cmake_minimum_required(VERSION 3.10)
project(HardcoreMode)

add_library(HardcoreMode SHARED
    HardcoreMode.cpp
)

target_include_directories(HardcoreMode PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
