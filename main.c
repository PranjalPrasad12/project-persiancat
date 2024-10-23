/* Persiancat - A simple privacy-focused browser
   Copyright (C) 2024-2025 Pranjal Prasad

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

    Be free to fork or experiment with this program. For the manual, visit
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
    Description     : Persiancat is a lightweight, privacy-centric browser designed to prioritize user privacy and security by minimizing tracking, implementing built-in ad-blocking, and ensuring a minimal resource footprint.

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
    - Linux, macOS, BSD or Windows(with WSL) is preferred
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
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold fetched data
struct MemoryStruct {
    char* memory;
    size_t size;
};

// Callback function to write data into a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    // Reallocate memory to store additional data
    char* ptr = realloc(mem->memory, mem->size + totalSize + 1);
    if (ptr == NULL) {
        // Out of memory
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    // Copy fetched content into memory
    memcpy(&(mem->memory[mem->size]), contents, totalSize);
    mem->size += totalSize;
    mem->memory[mem->size] = 0;  // Null-terminate the string

    return totalSize;
}

// Function to render basic HTML (only colors in this case)
void renderHTML(const char* content) {
    const char* pos = content;

    while (*pos != '\0') {
        // Check for colored <span> tags and switch text color accordingly
        if (strncmp(pos, "<span style=\"color:red\">", 24) == 0) {
            printf("\033[31m");  // Start red text
            pos += 24;  // Skip the tag
        } else if (strncmp(pos, "<span style=\"color:green\">", 26) == 0) {
            printf("\033[32m");  // Start green text
            pos += 26;  // Skip the tag
        } else if (strncmp(pos, "</span>", 7) == 0) {
            printf("\033[0m");  // Reset color
            pos += 7;  // Skip the closing tag
        } else {
            putchar(*pos);  // Print the character
            pos++;
        }
    }

    printf("\033[0m");  // Reset color after done
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL* curl;
    CURLcode res;

    // Structure to hold the fetched content
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // Allocate 1 byte to start
    chunk.size = 0;            // No data initially

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);  // Set the URL to fetch
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Set callback for writing data
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);  // Pass the memory struct to the callback

        // Perform the request, `res` will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if (res == CURLE_OK) {
            printf("Fetched content:\n");
            renderHTML(chunk.memory);  // Call the HTML rendering function
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);  // Free allocated memory
    }

    return 0;
}

