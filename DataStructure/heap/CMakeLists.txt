cmake_minimum_required(VERSION 2.8)

project("LinkedListTest")

set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")
#set(CMAKE_CXX_FLAGS "-std=c++17 ")


#add_executable(hello helloWorld.cpp)

add_executable(heap binaryHeapVector.cpp)
#add_executable(LinkedListTest linkedListTest.cpp)
#add_executable(LinkedListTest dobleLinkedListcpp)