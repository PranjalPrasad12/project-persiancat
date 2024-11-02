#include "HTMLRenderer.h"

extern "C" void renderHTML(const char* content) {
    HTMLRenderer renderer;
    renderer.renderHTML(content);
}
