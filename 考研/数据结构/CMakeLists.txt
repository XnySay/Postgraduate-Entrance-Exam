# -*- coding: utf-8 -*-
cmake_minimum_required(VERSION 3.20)
project(数据结构)
# Set C++ standard and flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置图代码的源文件路径和输出路径
set(GRAPH_SOURCE_DIR${PROJECT_SOURCE_DIR}/代码题/图/code)
file(GLOB GRAPH_CPP_SOURCES${GRAPH_SOURCE_DIR}/*.cpp)
set(GRAPH_EXECUTABLE_OUTPUT_PATH${GRAPH_SOURCE_DIR}/bin)

# 设置树和二叉树代码的源文件路径和输出路径
set(TREE_SOURCE_DIR${PROJECT_SOURCE_DIR}/代码题/树和二叉树/code)
file(GLOB TREE_CPP_SOURCES${TREE_SOURCE_DIR}/*.cpp)
set(TREE_EXECUTABLE_OUTPUT_PATH${TREE_SOURCE_DIR}/bin)

# 输出路径
set(EXECUTABLE_OUTPUT_PATH${GRAPH_EXECUTABLE_OUTPUT_PATH})

# 添加图代码的可执行文件
foreach(GRAPH_CPP_FILE${GRAPH_CPP_SOURCES})
    get_filename_component(file_name${GRAPH_CPP_FILE} NAME_WE)
    add_executable(${file_name}${GRAPH_CPP_FILE})
endforeach()

# 输出路径
set(EXECUTABLE_OUTPUT_PATH${TREE_EXECUTABLE_OUTPUT_PATH})

# 添加树和二叉树代码的可执行文件
foreach(TREE_CPP_FILE${TREE_CPP_SOURCES})
    get_filename_component(file_name${TREE_CPP_FILE} NAME_WE)
    add_executable(${file_name}${TREE_CPP_FILE})
endforeach()
