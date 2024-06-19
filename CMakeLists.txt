# Build Structure of this project 
cmake_minimum_required(VERSION 3.10)

# find_package(Catch2 3 REQUIRED)
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wunused-variable -Wuninitialized -Wsign-compare -Wfloat-equal -Wformat=2 -Wmissing-include-dirs -Wredundant-decls -Wreturn-type -Wswitch -Wswitch-enum -Wunused-parameter -Wunused-function -Wmissing-noreturn -Wnull-dereference -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wdouble-promotion -Wformat-overflow=2 -Wformat-truncation=2 -Wstack-protector -Wstrict-overflow=5 -Wvla -Wvolatile-register-var")

add_library(test_util SHARED test_util.cc)
add_library(sort SHARED ./sort/insertion_sort.cc ./sort/merge_sort.cc)
target_link_libraries(sort test_util)

add_executable(a.out main.cc)
target_link_libraries(a.out test_util sort)
target_link_directories(a.out PUBLIC . ./sort/)

add_executable(test test/test.cc)
target_link_libraries(test test_util sort Catch2::Catch2WithMain)
