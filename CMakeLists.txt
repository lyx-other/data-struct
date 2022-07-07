cmake_minimum_required(VERSION 3.22)
project(data-struct)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_test0 00LinearList/00SequentialList.cpp)
add_executable(cpp_test1 00LinearList/01SinglyLinkedList.cpp)
add_executable(cpp_test2 00LinearList/02DoublyLinkedList.cpp)

add_executable(cpp_test4 01StaticAndQueue/00SeqStack/01main.cpp)

add_executable(cpp_test99 99Test/Test.cpp)