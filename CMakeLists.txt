cmake_minimum_required(VERSION 3.10)
project(HardcoreMode)

set(MODULE_NAME HardcoreMode)

# Define the source files for the module
set(SOURCE_FILES
    src/HardcoreMode.cpp
    src/HardcoreMode.h
)

# Create the module shared library
add_library(${MODULE_NAME} MODULE ${SOURCE_FILES})

# Include AzerothCore's CMake scripts and target properties
include_directories(${CMAKE_SOURCE_DIR}/dep/acore/src/server/shared)
include_directories(${CMAKE_SOURCE_DIR}/dep/acore/src/server/shared/revision_db)
include_directories(${CMAKE_SOURCE_DIR}/dep/acore/src/server/game)
include_directories(${CMAKE_SOURCE_DIR}/src/tools/dbc)

# Set module dependencies if any
set(MODULE_DEPENDENCIES
    AzerothCore::World
    AzerothCore::Game
    AzerothCore::ScriptPCH
)

# Link the module with its dependencies
target_link_libraries(${MODULE_NAME} PRIVATE ${MODULE_DEPENDENCIES})

# Specify module installation directory
install(TARGETS ${MODULE_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/modules
)
