#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare functions from Rust library (FFI)
extern int render_html(const char *html);
extern void free_html_string(char *html);

void loadHTMLDocument(const char *filePath, char **htmlContent, int *contentSize) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        printf("Error: Unable to open HTML file %s\n", filePath);
        return;
    }

    fseek(file, 0, SEEK_END);
    *contentSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *htmlContent = (char *)malloc(*contentSize + 1);
    fread(*htmlContent, 1, *contentSize, file);
    (*htmlContent)[*contentSize] = '\0';

    fclose(file);
    printf("Loaded HTML content from %s, size: %d bytes\n", filePath, *contentSize);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path-to-html-file>\n", argv[0]);
        return 1;
    }

    const char *htmlFilePath = argv[1];
    char *htmlContent = NULL;
    int contentSize = 0;

    // Load HTML content
    loadHTMLDocument(htmlFilePath, &htmlContent, &contentSize);

    // Render HTML using Servo (via Rust)
    if (render_html(htmlContent) == 0) {
        printf("Rendering complete\n");
    } else {
        printf("Error: Failed to render HTML\n");
    }

    // Free the HTML string
    free_html_string(htmlContent);

    return 0;
}
