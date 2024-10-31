#include "html-rendering.h"
#include <string>
#include <iostream>
#include <cstring>

class HTMLRenderer {
public:
    void renderHTML(const std::string& content) {
        const char* pos = content.c_str();
        while (*pos != '\0') {
            if (matchTag(pos, "<title>")) {
                renderTitle(pos);
            } else if (matchTag(pos, "<h1>")) {
                renderHeader(pos, 1);
            } else if (matchTag(pos, "<h2>")) {
                renderHeader(pos, 2);
            } else if (matchTag(pos, "<h3>")) {
                renderHeader(pos, 3);
            } else if (matchTag(pos, "<p>")) {
                renderParagraph(pos);
            } else if (matchTag(pos, "<ul>")) {
                renderList(pos);
            } else if (matchTag(pos, "<a href=\"")) {
                renderLink(pos);
            } else if (matchTag(pos, "<img src=\"")) {
                renderImage(pos);
            } else if (matchTag(pos, "<table>")) {
                renderTable(pos);
            } else {
                std::cout << *pos;
                pos++;
            }
        }
        resetFormatting();
    }

private:
    bool matchTag(const char*& pos, const char* tag) {
        if (strncmp(pos, tag, strlen(tag)) == 0) {
            pos += strlen(tag);
            return true;
        }
        return false;
    }

    void renderTitle(const char*& pos) {
        std::cout << "\n\033[1;33m[Title: "; // Yellow for title
        while (*pos != '\0' && !matchTag(pos, "</title>")) {
            std::cout << *pos++;
        }
        std::cout << "]\033[0m\n";
    }

    void renderHeader(const char*& pos, int level) {
        switch (level) {
            case 1: std::cout << "\n\033[1;34m"; break; // Bold Blue for H1
            case 2: std::cout << "\n\033[1;32m"; break; // Bold Green for H2
            case 3: std::cout << "\n\033[1;36m"; break; // Cyan for H3
            default: std::cout << "\n"; break;
        }
        while (*pos != '\0' && !matchTag(pos, ("</h" + std::to_string(level) + ">").c_str())) {
            std::cout << *pos++;
        }
        resetFormatting();
        std::cout << "\n";
    }

    void renderParagraph(const char*& pos) {
        std::cout << "\n";
        while (*pos != '\0' && !matchTag(pos, "</p>")) {
            std::cout << *pos++;
        }
        std::cout << "\n";
    }

    void renderList(const char*& pos) {
        std::cout << "\n";
        while (*pos != '\0' && !matchTag(pos, "</ul>")) {
            if (matchTag(pos, "<li>")) {
                std::cout << "  • ";
                while (*pos != '\0' && !matchTag(pos, "</li>")) {
                    std::cout << *pos++;
                }
                std::cout << "\n";
            }
        }
    }

    void renderLink(const char*& pos) {
        std::cout << "\033[1;34m[Link: ";
        const char* urlEnd = strchr(pos, '"');
        if (urlEnd) {
            std::cout.write(pos, urlEnd - pos);
            pos = urlEnd + 1;
            std::cout << "] ";
        }
        resetFormatting();
    }

    void renderImage(const char*& pos) {
        std::cout << "\033[1;35m[Image: ";
        const char* srcEnd = strchr(pos, '"');
        if (srcEnd) {
            std::cout.write(pos, srcEnd - pos);
            pos = srcEnd + 1;
            std::cout << "]\033[0m ";
        }
    }

    void renderTable(const char*& pos) {
        std::cout << "\n[Table]\n";
        while (*pos != '\0' && !matchTag(pos, "</table>")) {
            if (matchTag(pos, "<tr>")) {
                std::cout << "\n| ";
                while (*pos != '\0' && !matchTag(pos, "</tr>")) {
                    if (matchTag(pos, "<td>")) {
                        while (*pos != '\0' && !matchTag(pos, "</td>")) {
                            std::cout << *pos++;
                        }
                        std::cout << " | ";
                    }
                }
            }
        }
        std::cout << "\n";
    }

    void resetFormatting() {
        std::cout << "\033[0m";
    }
};

// C-compatible function to call the C++ HTMLRenderer class
void renderHTML(const char* content) {
    HTMLRenderer renderer;
    renderer.renderHTML(content);
}
