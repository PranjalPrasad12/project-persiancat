/* Persiancat - A simple privacy-focused browser
   Copyright (C) 2024-2025 Pranjal Prasad
   Language- C
   File - main.c

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

#include <stdio.h>
#include "functions/html-rendering/html-rendering.h"

// Display startup message
void displayStartupMessage() {
    printf("Persiancat - A simple privacy-oriented minimal browser\n\n");
    printf("This program is free software: you can redistribute it and/or modify\n");
    printf("it under the terms of the GNU General Public License as published by\n");
    printf("the Free Software Foundation, either version 3 of the License, or\n");
    printf("(at your option) any later version.\n\n");
    printf("This program is distributed in the hope that it will be useful,\n");
    printf("but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
    printf("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
    printf("GNU General Public License for more details.\n\n");
    printf("You should have received a copy of the GNU General Public License\n");
    printf("along with this program. If not, see <https://www.gnu.org/licenses/>.\n\n");
    printf("Usage: ./persiancat *<url> or */<file path>\n\n");
}

int main(int argc, char* argv[]) {
    displayStartupMessage();

    // Check if a URL or file path is provided
    if (argc < 2) {
        printf("No URL or file path provided.\n");
        printf("Usage: ./persiancat *<url> or */<file path>\n");
        return 1;
    }

    // Render HTML content based on provided URL or file path
    const char* htmlContent = argv[1];
    renderHTML(htmlContent);

    return 0;
}

