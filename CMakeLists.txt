cmake_minimum_required(VERSION 3.5)
project(lab_3)

add_executable(leak examples/memory_leak.cpp)
add_executable(unique examples/unique_ptr.cpp)
add_executable(shared examples/shared_ptr.cpp)
add_executable(weak examples/weak_ptr.cpp)
add_executable(file_unique examples/unique_file.cpp)
