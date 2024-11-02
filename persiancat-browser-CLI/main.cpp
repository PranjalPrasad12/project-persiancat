/* Persiancat - A simple privacy-focused browser
   Copyright (C) 2024-2025 Pranjal Prasad
   Language- C++
   File - main.cpp

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Be free to fork or experiment with this program. For the manual, open
    the 'Manual' folder with documentation in Markdown/HTML, OpenDocument Text,
    and a PDF. For any advice, bug, or question, pull an issue on the Git repository.

    -----------------------------------------------------
    PROJECT INFO:
    -----------------------------------------------------
    Project Name    : Persiancat
    Version         : Alpha 0.97
    Author          : Pranjal Prasad and community
    License         : GPL-3.0 (GNU General Public License v3.0 or later) for the browser and LGPL 3.0(GNU Lesser General Public License v3.0 or later)
    Repository      : https://github.com/your-repository-link (replace with real link)
    Documentation   : Markdown/HTML/OpenDocument/PDF (Located in the 'Manual' folder)
    Work Started on : 02 October 2024
    Description     : Persiancat is a lightweight, privacy-centric browser designed to prioritize user privacy and security by minimising tracking, implementing built-in ad-blocking, and ensuring a minimal resource footprint.
    Version Controling System: Git

    -----------------------------------------------------
    FEATURES:
    -----------------------------------------------------
    - Privacy-focused browsing experience.
    - Loads only neccesary CSS(like colours) and JavaScript
    - Lightweight design with minimal resource usage.
    - Built-in tracker prevention.
    - Customizable privacy settings and interface.
    - Support for multiple platforms (Linux, macOS, Windows).
    - Free and Open Source- you are free to use, modify, and redistribute.

    -----------------------------------------------------
    CONTRIBUTING:
    -----------------------------------------------------
    - Fork the repository, make changes, and submit a pull request.
    - Contributions are welcome in the form of bug reports, code improvements, new features, or documentation updates.
    - Follow the guidelines provided in the 'CONTRIBUTING.md' file.
    - Linux, macOS, BSD or Windows(with WSL/MingGW) is preferred
    - GCC is the preferred compiler
    - Being a programmer is not always required for contributing but basic knowledge is, you may help with documentation, designs and promoting the project.
    -----------------------------------------------------
    CONTACT & SUPPORT:
    -----------------------------------------------------
    Author Email   : pranjal@example.com (replace with real email)
    Issues Tracker : https://github.com/your-repository-link/issues (replace with real link)

    -----------------------------------------------------
    NOTE:
    -----------------------------------------------------
    This project is in active development. Contributions, feedback, and collaboration are highly appreciated. Please ensure that all changes comply with the project's licensing terms.
    */

#include <iostream>
#include "functions/html-rendering/html_rendering.h"

#include <iostream>
#include <string>
#include <fstream>
#include "functions/html-rendering/html_rendering.h"

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
    std::cout << "(C)Pranjal Prasad 2024\n\n";
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

    // Create an instance of the HTMLRenderer class and render the content
    HTMLRenderer renderer;
    renderer.renderHTML(htmlContent);

    std::cout << "\nRendering complete. Exiting the program. Thanks for using this browser to access the web :)\n";
    return 0;
}

