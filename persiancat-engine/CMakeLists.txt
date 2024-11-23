# Set the source files for the engine
set(ENGINE_SRC
    html-rendering.cpp
    renderer.cpp
    libxml2/libxml2/HTMLparser.c
    libxml2/libxml2/HTMLtree.c
    libxml2/libxml2/parser.c
    libxml2/libxml2/tree.c
    libxml2/libxml2/xmlmemory.c
)

# Create a static library for the engine
add_library(persiancat-engine STATIC ${ENGINE_SRC})

# Link the required libraries for the engine (e.g., libxml2)
target_link_libraries(persiancat-engine xml2)

