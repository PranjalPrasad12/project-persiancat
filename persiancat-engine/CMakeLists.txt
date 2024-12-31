cmake_minimum_required(VERSION 3.10)

# Define the engine library (if applicable)
add_library(persiancat-engine STATIC
    engine.cpp
    renderer.cpp
    html-rendering.cpp
)

target_include_directories(persiancat-engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

