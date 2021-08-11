cmake_minimum_required(VERSION 3.16)
project(ProjectAPI C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjectAPI capture.c capture_matrix.c dijkstra_matrix.c heap.c)