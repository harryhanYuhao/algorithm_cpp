# Build Structure of this project 
cmake_minimum_required(VERSION 3.10)

project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wunused-variable -Wuninitialized -Wsign-compare -Wfloat-equal -Wformat=2 -Wmissing-include-dirs -Wredundant-decls -Wreturn-type -Wswitch -Wswitch-enum -Wunused-parameter -Wunused-function -Wmissing-noreturn -Wnull-dereference -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wdouble-promotion -Wformat-overflow=2 -Wformat-truncation=2 -Wstack-protector -Wstrict-overflow=5 -Wvla -Wvolatile-register-var")

add_library(util SHARED util.cc)
add_library(sort SHARED ./sort/insertion_sort.cc ./sort/merge_sort.cc)
target_link_libraries(sort util)

add_executable(a.out main.cc)
target_link_libraries(a.out util sort)
target_link_directories(a.out PUBLIC . ./sort/)
