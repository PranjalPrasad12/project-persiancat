#include <iostream>
#include <string>
#include <fstream>
#include "/persiancat-engine/html-rendering.h"  // Corrected path for html-rendering.h

// Function to load HTML content from a file
std::string loadHTMLFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file.\n";
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

int main() {
    // First message
    std::cout << "Persiancat - A simple privacy-oriented minimal browser\n\n";
    std::cout << "(C) Pranjal Prasad 2024\n\n";
    std::cout << "This program is free software: you can redistribute it and/or modify\n";
    std::cout << "it under the terms of the GNU General Public License as published by\n";
    std::cout << "the Free Software Foundation, either version 3 of the License, or\n";
    std::cout << "(at your option) any later version.\n\n";
    std::cout << "This program is distributed in the hope that it will be useful,\n";
    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\n";
    std::cout << "GNU General Public License for more details.\n\n";
    std::cout << "You should have received a copy of the GNU General Public License\n";
    std::cout << "along with this program. If not, see <https://www.gnu.org/licenses/>.\n\n";

    std::cout << "Usage: You can either enter HTML content directly or specify a file path.\n";
    std::cout << "----------------------------------------------------------------------------\n";

    // Prompt user for input
    std::cout << "Please choose an option:\n";
    std::cout << "1. Enter HTML content directly\n";
    std::cout << "2. Provide a file path to load HTML content\n";
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();  // Clear newline character from input buffer

    std::string htmlContent;

    if (choice == 1) {
        // Direct HTML input
        std::cout << "Enter HTML content (end with Ctrl+D on a new line):\n";
        std::cin.ignore(); // clear buffer for multiline input
        std::getline(std::cin, htmlContent, '\0');  // Capture multi-line input until EOF
    } else if (choice == 2) {
        // File path input
        std::cout << "Enter file path: ";
        std::string filePath;
        std::cin >> filePath;
        htmlContent = loadHTMLFromFile(filePath);

        if (htmlContent.empty()) {
            std::cerr << "Failed to load content from the file. Exiting.\n";
            return 1;
        }
    } else {
        std::cerr << "Invalid choice. Exiting.\n";
        return 1;
    }

    // Now let's use more features from the engine.

    // Initialize an instance of HTMLRenderer
    HTMLRenderer renderer;

    // 1. Parse and Render HTML content (Enhanced with additional features)
    std::cout << "Parsing and rendering HTML content...\n";
    if (!renderer.isValidHTML(htmlContent)) {
        std::cerr << "Error: Invalid HTML content.\n";
        return 1;
    }

    // 2. Render the HTML content
    renderer.renderHTML(htmlContent);

    // 3. If the engine supports CSS, render styles (assuming CSS parsing feature exists)
    std::cout << "Rendering CSS...\n";
    renderer.renderCSS(htmlContent);  // Assuming there's a method for rendering CSS styles

    // 4. Add JavaScript support (if engine supports JS rendering or simulation)
    std::cout << "Executing JavaScript...\n";
    renderer.executeJavaScript(htmlContent);  // Assuming there's a JS execution method

    // Final message
    std::cout << "\nRendering complete. Exiting the program. Thanks for using this browser to access the web :)\n";
    return 0;
}
