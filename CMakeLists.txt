cmake_minimum_required(VERSION 3.20)

project(Matrix_Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(matrix src/matrix.cpp)
target_include_directories(matrix PUBLIC include)

add_executable(matrix_calculator src/main.cpp)
target_link_libraries(matrix_calculator matrix)

enable_testing()
add_subdirectory(tests)