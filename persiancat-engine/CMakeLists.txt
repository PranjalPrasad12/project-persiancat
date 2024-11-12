# Project Persiancat- (C)Pranjal Prasad 2024.
# Project Persiancat is a 'free software' under the terms of both GPL 3.0 or later and LGPL 3.0, but this CMake is specifically licensed under LGPL 3.0 for more details read the information of the file 'COPYING' if you don't have a copy of the 'COPYING' file read it on https://github.com/PranjalPrasad12/project-persiancat/blob/master/COPYING
# project-persiancat/persiancat-engine/CMakeLists.txt

# Create a library for the engine
add_library(persiancat-engine STATIC
    html-rendering.cpp
)

# Specify include directories for engine headers
target_include_directories(persiancat-engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
