# This Cmake is licensed under the conditions of the GPL v.3
# (C) Pranjal Prasad 2024
# This file is currently not working properly

# Set the source files for the browser CLI
set(CLI_SRC
    main.cpp
    config.cpp
    menu.cpp
    page.cpp
    search.cpp
)

# Create an executable for the browser CLI
add_executable(persiancat-cli ${CLI_SRC})

# Link the engine library to the CLI executable
target_link_libraries(persiancat-cli persiancat-engine)

