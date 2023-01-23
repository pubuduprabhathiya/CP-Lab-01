cmake_minimum_required(VERSION 3.22)
project(CP VERSION 0.0.1 DESCRIPTION "Lab-01")

file(GLOB SOURCES all.c linked_list.c operation.c mutex.c rwlock.c serial_program.c graph.c)

add_executable(main  ${SOURCES})
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
target_link_libraries(main PRIVATE Python3::Python m pthread)

