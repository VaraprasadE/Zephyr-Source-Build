# static library target named "circular_buffer"
add_library(
    circular_buffer
    STATIC
    src/circular_buffer.c
)

add_library(
    static_memory_pool
    STATIC
    src/static_memory_pool.c
)

target_include_directories(
    circular_buffer
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(
    static_memory_pool
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# External Info: You MUST add this line to inherit Zephyr's hardware compiler flags
target_link_libraries(circular_buffer PRIVATE zephyr_interface)
target_link_libraries(static_memory_pool PRIVATE zephyr_interface)