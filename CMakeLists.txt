# This Cmake is not working properly right now for compiling I would recommend using GCC through its CLI
# Use this:q:

# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(PersianCat VERSION 0.1)

# Define the source directories for each part of the project
set(PERSIANCAT_ENGINE_SRC_DIR persiancat-engine)
set(PERSIANCAT_CLI_SRC_DIR persiancat-browser-CLI)

# Specify the include directories for the project
include_directories(
    ${PERSIANCAT_ENGINE_SRC_DIR}/libxml2/include
    ${PERSIANCAT_CLI_SRC_DIR}/headers
)

# Add subdirectories for the engine and the CLI
add_subdirectory(${PERSIANCAT_ENGINE_SRC_DIR})
add_subdirectory(${PERSIANCAT_CLI_SRC_DIR})
