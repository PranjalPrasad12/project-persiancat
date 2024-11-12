# Project Persiancat- (C)Pranjal Prasad 2024.
# Project Persiancat is a 'free software' under the terms of both GPL 3.0 or later and LGPL 3.0, but this CMake is specifically licensed under GPL 3.0 for more details read the information of the file 'COPYING' if you don't have a copy of the 'COPYING' file read it on https://github.com/PranjalPrasad12/project-persiancat/blob/master/COPYING
# project-persiancat/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(persiancat)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include subdirectories for CLI and engine
add_subdirectory(persiancat-engine)
add_subdirectory(persiancat-browser-CLI)
