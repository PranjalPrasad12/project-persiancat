# Project Persiancat- (C)Pranjal Prasad 2024.
# Project Persiancat is a 'free software' under the terms of both GPL 3.0 or later and LGPL 3.0, but this CMake is specifically licensed under GPL 3.0 for more details read the information of the file 'COPYING' if you don't have a copy of the 'COPYING' file read it on https://github.com/PranjalPrasad12/project-persiancat/blob/master/COPYING
# project-persiancat/persiancat-browser-CLI/CMakeLists.txt

# Create an executable for the CLI browser
add_executable(persiancat-browser-CLI)
    main.cpp
    menu.cpp
)

# Link the engine library to the CLI executable
target_link_libraries(persiancat-browser-CLI PRIVATE PersianCatEngine)

# Specify include directories for both CLI and engine headers
target_include_directories(persiancat-browser-CLI PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/persiancat-engine
)
