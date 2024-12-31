/*
 * (C) Pranjal Prasad 2024-2025
 * The Persiancat Engine is licensed under the terms of MPL-2.0
 */
#include <stdio.h>

extern void render_html(const char* input);

int main() {
    const char* html_data = "<html><body><h1>Hello, World!</h1></body></html>";
    render_html(html_data);  // Calling the Rust function
    return 0;
}
