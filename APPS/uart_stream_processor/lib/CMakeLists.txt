# static library target named "circular_buffer"
add_library(
    circular_buffer
    STATIC
    src/circular_buffer.c
)

target_include_directories(
    circular_buffer
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)