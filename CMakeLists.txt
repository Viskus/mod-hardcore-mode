cmake_minimum_required(VERSION 3.10)
project(mod-hardcore-mode)

# Define the name of your module
set(MODULE_NAME HardcoreMode)

# List your module's source files
set(SOURCE_FILES
    src/HardcoreMode.cpp
    src/HardcoreMode.h
)

# Include directories for AzerothCore headers and your module's source directory
include_directories(
    ${CMAKE_SOURCE_DIR}/dep/acore/src/server/game
    ${CMAKE_SOURCE_DIR}/modules/mod-hardcore-mode/src
)

# Create the module shared library
add_library(${MODULE_NAME} MODULE ${SOURCE_FILES})

# Link your module with AzerothCore libraries (static linking)
target_link_libraries(${MODULE_NAME}
    PRIVATE
    libworld
    libgame
    libscript
)

# Set the installation directory for your module
install(TARGETS ${MODULE_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/modules
)
