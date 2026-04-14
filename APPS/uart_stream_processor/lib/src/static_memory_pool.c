#include "static_memory_pool.h"

static bool static_memory_pool_owns_node(const static_memory_pool *pool,
                                         const static_pool_node *node)
{
    return (pool != NULL) &&
           (node >= &pool->nodes[0]) &&
           (node <= &pool->nodes[STATIC_MEMORY_POOL_CAPACITY - 1U]);
}

void static_memory_pool_init(static_memory_pool *pool)
{
    if (pool == NULL) {
        return;
    }

    pool->free_list = NULL;
    pool->available = STATIC_MEMORY_POOL_CAPACITY;

    for (size_t index = 0; index < STATIC_MEMORY_POOL_CAPACITY; index++) {
        pool->nodes[index].length = 0U;
        pool->nodes[index].in_use = false;
        pool->nodes[index].next = pool->free_list;
        pool->free_list = &pool->nodes[index];
    }
}

static_pool_node *static_memory_pool_acquire(static_memory_pool *pool)
{
    static_pool_node *node;

    if ((pool == NULL) || (pool->free_list == NULL)) {
        return NULL;
    }

    node = pool->free_list;
    pool->free_list = node->next;
    node->next = NULL;
    node->length = 0U;
    node->in_use = true;
    pool->available--;

    return node;
}

bool static_memory_pool_release(static_memory_pool *pool, static_pool_node *node)
{
    if (!static_memory_pool_owns_node(pool, node) || !node->in_use) {
        return false;
    }

    node->length = 0U;
    node->in_use = false;
    node->next = pool->free_list;
    pool->free_list = node;
    pool->available++;

    return true;
}

bool static_memory_pool_add_node(static_pool_node **head, static_pool_node *node)
{
    static_pool_node *tail;

    if ((head == NULL) || (node == NULL) || !node->in_use) {
        return false;
    }

    node->next = NULL;

    if (*head == NULL) {
        *head = node;
        return true;
    }

    tail = *head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = node;
    return true;
}

bool static_memory_pool_insert_node(static_pool_node **head,
                                    static_pool_node *position,
                                    static_pool_node *node)
{
    if ((head == NULL) || (node == NULL) || !node->in_use) {
        return false;
    }

    if (position == NULL) {
        node->next = *head;
        *head = node;
        return true;
    }

    node->next = position->next;
    position->next = node;
    return true;
}

bool static_memory_pool_remove_node(static_pool_node **head, static_pool_node *node)
{
    static_pool_node *current;

    if ((head == NULL) || (*head == NULL) || (node == NULL)) {
        return false;
    }

    if (*head == node) {
        *head = node->next;
        node->next = NULL;
        return true;
    }

    current = *head;

    while ((current->next != NULL) && (current->next != node)) {
        current = current->next;
    }

    if (current->next != node) {
        return false;
    }

    current->next = node->next;
    node->next = NULL;
    return true;
}

bool static_memory_pool_delete_node(static_memory_pool *pool,
                                    static_pool_node **head,
                                    static_pool_node *node)
{
    if (!static_memory_pool_remove_node(head, node)) {
        return false;
    }

    return static_memory_pool_release(pool, node);
}

static_pool_node *static_memory_pool_pop_node(static_pool_node **head)
{
    static_pool_node *node;

    if ((head == NULL) || (*head == NULL)) {
        return NULL;
    }

    node = *head;
    *head = node->next;
    node->next = NULL;

    return node;
}

size_t static_memory_pool_available(const static_memory_pool *pool)
{
    if (pool == NULL) {
        return 0U;
    }

    return pool->available;
}