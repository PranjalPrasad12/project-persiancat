#ifndef HTMLRENDERING_H
#define HTMLRENDERING_H

#include <string>
#include <libxml2/HTMLparser.h>

class HTMLRenderer {
public:
    void renderHTML(const std::string& content);

private:
    void renderNode(xmlNode* node);
    void renderElement(xmlNode* element);
    void renderTitle(xmlNode* element);
    void renderHeader(int level, xmlNode* element);
    void renderParagraph(xmlNode* element);
    void renderList(xmlNode* element);
    void renderLink(xmlNode* element);
    void renderImage(xmlNode* element);
    void renderTable(xmlNode* element);
    void resetFormatting();
};

#endif // HTMLRENDERING.H
