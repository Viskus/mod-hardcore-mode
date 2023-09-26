cmake_minimum_required(VERSION 3.10)
project(HardcoreMode)

add_library(HardcoreMode MODULE
    src/HardcoreMode.cpp
)

target_include_directories(HardcoreMode PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(TARGETS HardcoreMode
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/modules
)
