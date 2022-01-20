cmake_minimum_required (VERSION 3.16)
project(behavior_tree_tutorial)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(BehaviorTreeV3)

include_directories(
    include
    config
    )

add_executable (bt_tutorial src/bt_tutorial.cpp)

target_link_libraries (bt_tutorial PUBLIC 
    BT::behaviortree_cpp_v3
    )
