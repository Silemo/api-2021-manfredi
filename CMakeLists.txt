cmake_minimum_required(VERSION 3.16)

project(ProjectAPI C)

set(CMAKE_C_STANDARD 11)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -O2 -pipe -static -s -o")

add_executable(test_out capture.c capture_matrix.c dijkstra_matrix.c heap.c my_dijkstra.c tutorial.c tosubmit_clear.c)

add_executable(full_out graph_ranker.c graph_ranker.c tosubmit.c)