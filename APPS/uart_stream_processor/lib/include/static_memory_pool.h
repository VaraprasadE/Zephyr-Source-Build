#ifndef STATIC_MEMORY_POOL_H
#define STATIC_MEMORY_POOL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifndef STATIC_MEMORY_POOL_CAPACITY
#define STATIC_MEMORY_POOL_CAPACITY 8U
#endif

#ifndef STATIC_MEMORY_POOL_DATA_SIZE
#define STATIC_MEMORY_POOL_DATA_SIZE 16U
#endif

typedef struct static_pool_node static_pool_node;

/**
 * @brief Fixed-size packet node stored inside the static pool.
 *
 * Each node can be linked into a singly linked list or passed by pointer
 * through a queue between Zephyr threads.
 */
struct static_pool_node
{
    uint8_t data[STATIC_MEMORY_POOL_DATA_SIZE];
    size_t length;
    bool in_use;
    static_pool_node *next;
};

/**
 * @brief Pool container that owns all statically allocated nodes.
 */
typedef struct static_memory_pool
{
    static_pool_node nodes[STATIC_MEMORY_POOL_CAPACITY];
    static_pool_node *free_list;
    size_t available;
} static_memory_pool;

/**
 * @brief Initialize a static memory pool.
 *
 * @param pool Pointer to the pool instance.
 */
void static_memory_pool_init(static_memory_pool *pool);

/**
 * @brief Acquire one free node from the pool.
 *
 * @param pool Pointer to the pool instance.
 *
 * @return Pointer to a free node, or NULL if the pool is exhausted.
 */
static_pool_node *static_memory_pool_acquire(static_memory_pool *pool);

/**
 * @brief Return a node back to the pool.
 *
 * The node must have been acquired from the same pool.
 *
 * @param pool Pointer to the pool instance.
 * @param node Pointer to the node to release.
 *
 * @retval true The node was returned successfully.
 * @retval false The input was invalid or the node was already free.
 */
bool static_memory_pool_release(static_memory_pool *pool, static_pool_node *node);

/**
 * @brief Append a node to the tail of a singly linked list.
 *
 * @param head Pointer to the list head.
 * @param node Node to append.
 *
 * @retval true The node was appended.
 * @retval false The input was invalid.
 */
bool static_memory_pool_add_node(static_pool_node **head, static_pool_node *node);

/**
 * @brief Insert a node into a singly linked list.
 *
 * If @p position is NULL, the node is inserted at the head. Otherwise the node
 * is inserted immediately after @p position.
 *
 * @param head Pointer to the list head.
 * @param position Existing node after which to insert, or NULL for head insert.
 * @param node Node to insert.
 *
 * @retval true The node was inserted.
 * @retval false The input was invalid.
 */
bool static_memory_pool_insert_node(static_pool_node **head,
                                    static_pool_node *position,
                                    static_pool_node *node);

/**
 * @brief Remove a node from a singly linked list without returning it to pool.
 *
 * @param head Pointer to the list head.
 * @param node Node to remove.
 *
 * @retval true The node was removed from the list.
 * @retval false The node was not found or the input was invalid.
 */
bool static_memory_pool_remove_node(static_pool_node **head, static_pool_node *node);

/**
 * @brief Remove a node from a list and return it to the pool.
 *
 * @param pool Pointer to the pool instance.
 * @param head Pointer to the list head.
 * @param node Node to delete.
 *
 * @retval true The node was deleted and released.
 * @retval false The node was not found or the input was invalid.
 */
bool static_memory_pool_delete_node(static_memory_pool *pool,
                                    static_pool_node **head,
                                    static_pool_node *node);

/**
 * @brief Pop the head node from a linked list.
 *
 * @param head Pointer to the list head.
 *
 * @return The removed head node, or NULL if the list is empty.
 */
static_pool_node *static_memory_pool_pop_node(static_pool_node **head);

/**
 * @brief Get the number of currently free nodes.
 *
 * @param pool Pointer to the pool instance.
 *
 * @return Number of nodes available for allocation.
 */
size_t static_memory_pool_available(const static_memory_pool *pool);

#endif /* STATIC_MEMORY_POOL_H */