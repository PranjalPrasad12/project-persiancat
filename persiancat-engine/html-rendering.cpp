#include "HTMLRenderer.h"
#include <iostream>
#include <cstring>
#include <libxml2/HTMLparser.h>

void HTMLRenderer::renderHTML(const std::string& content) {
    htmlDocPtr doc = htmlReadMemory(content.c_str(), content.size(), nullptr, nullptr, HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc == nullptr) {
        std::cerr << "Failed to parse HTML document." << std::endl;
        return;
    }

    renderNode(doc->children);

    xmlFreeDoc(doc);
    xmlCleanupParser();
}

void HTMLRenderer::renderNode(xmlNode* node) {
    for (xmlNode* curr = node; curr != nullptr; curr = curr->next) {
        switch (curr->type) {
            case XML_ELEMENT_NODE:
                renderElement(curr);
                break;
            case XML_TEXT_NODE:
                if (curr->content) {
                    std::cout << curr->content; // Render text content
                }
                break;
            default:
                break;
        }
        renderNode(curr->children); // Recursive call for child nodes
    }
}

void HTMLRenderer::renderElement(xmlNode* element) {
    const char* name = (const char*)element->name;
    if (strcmp(name, "title") == 0) {
        renderTitle(element);
    } else if (strcmp(name, "h1") == 0) {
        renderHeader(1, element);
    } else if (strcmp(name, "h2") == 0) {
        renderHeader(2, element);
    } else if (strcmp(name, "h3") == 0) {
        renderHeader(3, element);
    } else if (strcmp(name, "h4") == 0) {
        renderHeader(4, element);
    } else if (strcmp(name, "p") == 0) {
        renderParagraph(element);
    } else if (strcmp(name, "ul") == 0) {
        renderList(element);
    } else if (strcmp(name, "ol") == 0) {
        renderOrderedList(element);
    } else if (strcmp(name, "li") == 0) {
        renderListItem(element);
    } else if (strcmp(name, "a") == 0) {
        renderLink(element);
    } else if (strcmp(name, "img") == 0) {
        renderImage(element);
    } else if (strcmp(name, "table") == 0) {
        renderTable(element);
    } else if (strcmp(name, "div") == 0) {
        renderDiv(element);
    } else if (strcmp(name, "span") == 0) {
        renderSpan(element);
    }
}

void HTMLRenderer::renderTitle(xmlNode* element) {
    std::cout << "\n\033[1;33m[Title: ";
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_TEXT_NODE) {
            std::cout << child->content;
        }
        child = child->next;
    }
    std::cout << "]\033[0m\n";
}

void HTMLRenderer::renderHeader(int level, xmlNode* element) {
    switch (level) {
        case 1: std::cout << "\n\033[1;34m"; break; // Bold Blue for H1
        case 2: std::cout << "\n\033[1;32m"; break; // Bold Green for H2
        case 3: std::cout << "\n\033[1;36m"; break; // Cyan for H3
        case 4: std::cout << "\n\033[1;35m"; break; // Magenta for H4
        default: std::cout << "\n"; break;
    }
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_TEXT_NODE) {
            std::cout << child->content;
        }
        child = child->next;
    }
    resetFormatting();
    std::cout << "\n";
}

void HTMLRenderer::renderParagraph(xmlNode* element) {
    std::cout << "\n";
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_TEXT_NODE) {
            std::cout << child->content;
        }
        child = child->next;
    }
    std::cout << "\n";
}

void HTMLRenderer::renderList(xmlNode* element) {
    std::cout << "\n";
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_ELEMENT_NODE && strcmp((const char*)child->name, "li") == 0) {
            std::cout << "  • ";
            renderListItem(child);
        }
        child = child->next;
    }
}

void HTMLRenderer::renderOrderedList(xmlNode* element) {
    std::cout << "\n";
    xmlNode* child = element->children;
    int index = 1;
    while (child) {
        if (child->type == XML_ELEMENT_NODE && strcmp((const char*)child->name, "li") == 0) {
            std::cout << index++ << ". ";
            renderListItem(child);
        }
        child = child->next;
    }
}

void HTMLRenderer::renderListItem(xmlNode* element) {
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_TEXT_NODE) {
            std::cout << child->content;
        }
        child = child->next;
    }
    std::cout << "\n";
}

void HTMLRenderer::renderLink(xmlNode* element) {
    const char* href = (const char*)xmlGetProp(element, (const xmlChar*)"href");
    std::cout << "\033[1;34m[Link: " << (href ? href : "N/A") << "] ";
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_TEXT_NODE) {
            std::cout << child->content;
        }
        child = child->next;
    }
    resetFormatting();
}

void HTMLRenderer::renderImage(xmlNode* element) {
    const char* src = (const char*)xmlGetProp(element, (const xmlChar*)"src");
    std::cout << "\033[1;35m[Image: " << (src ? src : "N/A") << "]\033[0m ";
}

void HTMLRenderer::renderTable(xmlNode* element) {
    std::cout << "\n[Table]\n";
    xmlNode* row = element->children;
    while (row) {
        if (row->type == XML_ELEMENT_NODE && strcmp((const char*)row->name, "tr") == 0) {
            std::cout << "\n| ";
            xmlNode* cell = row->children;
            while (cell) {
                if (cell->type == XML_ELEMENT_NODE && strcmp((const char*)cell->name, "td") == 0) {
                    xmlNode* cellChild = cell->children;
                    while (cellChild) {
                        if (cellChild->type == XML_TEXT_NODE) {
                            std::cout << cellChild->content;
                        }
                        cellChild = cellChild->next;
                    }
                    std::cout << " | ";
                }
                cell = cell->next;
            }
        }
        row = row->next;
    }
    std::cout << "\n";
}

void HTMLRenderer::renderDiv(xmlNode* element) {
    std::cout << "[Div Start] ";
    renderNode(element->children);
    std::cout << "[Div End]\n";
}

void HTMLRenderer::renderSpan(xmlNode* element) {
    std::cout << "[Span] ";
    xmlNode* child = element->children;
    while (child) {
        if (child->type == XML_TEXT_NODE) {
            std::cout << child->content;
        }
        child = child->next;
    }
    std::cout << "[/Span]\n";
}

void HTMLRenderer::resetFormatting() {
    std::cout << "\033[0m";
}
