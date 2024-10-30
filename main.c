/* Persiancat - A simple privacy-focused browser
   Copyright (C) 2024-2025 Pranjal Prasad
   Language- C

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
#include <sys/stat.h>

// Structure to hold fetched data
struct MemoryStruct {
    char* memory;
    size_t size;
};

// Callback function to write data into a string (used for web content)
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    char* ptr = realloc(mem->memory, mem->size + totalSize + 1);
    if (ptr == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, totalSize);
    mem->size += totalSize;
    mem->memory[mem->size] = 0;  // Null-terminate the string

    return totalSize;
}

// Function for rendering HTML
void renderHTML(const char* content) {
    const char* pos = content;

    while (*pos != '\0') {
        if (strncmp(pos, "<title>", 7) == 0) {
            pos += 7;
            printf("\n\033[1;33m[Title: "); // Yellow for title
            while (*pos != '\0' && strncmp(pos, "</title>", 8) != 0) {
                putchar(*pos);
                pos++;
            }
            printf("]\033[0m\n");
            pos += 8;
        } else if (strncmp(pos, "<h1>", 4) == 0) {
            printf("\n\033[1;34m"); // Bold Blue for H1
            pos += 4;
        } else if (strncmp(pos, "<h2>", 4) == 0) {
            printf("\n\033[1;32m"); // Bold Green for H2
            pos += 4;
        } else if (strncmp(pos, "</h1>", 5) == 0 || strncmp(pos, "</h2>", 5) == 0) {
            printf("\033[0m\n"); // Reset color and add newline
            pos += 5;
        } else if (strncmp(pos, "<p>", 3) == 0) {
            printf("\n"); // New paragraph
            pos += 3;
        } else if (strncmp(pos, "</p>", 4) == 0) {
            printf("\n"); // End of paragraph
            pos += 4;
        } else if (strncmp(pos, "<ul>", 4) == 0) {
            printf("\n"); // Start a new line for list
            pos += 4;
        } else if (strncmp(pos, "<li>", 4) == 0) {
            printf("  • "); // Bullet for list item
            pos += 4;
        } else if (strncmp(pos, "</li>", 5) == 0) {
            printf("\n"); // End list item with newline
            pos += 5;
        } else if (strncmp(pos, "<a href=\"", 9) == 0) {
            pos += 9;
            const char* urlEnd = strchr(pos, '"');
            if (urlEnd) {
                printf("[Link: ");
                fwrite(pos, 1, urlEnd - pos, stdout);
                printf("] ");
                pos = urlEnd + 1;
            }
        } else if (strncmp(pos, "</a>", 4) == 0) {
            pos += 4;
        } else if (strncmp(pos, "<body>", 6) == 0) {
            printf("\n"); // Start of body
            pos += 6;
        } else if (strncmp(pos, "</body>", 7) == 0) {
            printf("\n"); // End of body
            pos += 7;
        } else {
            putchar(*pos);
            pos++;
        }
    }
    printf("\033[0m\n"); // Reset formatting at end
}

// Function to load file cont
ent into MemoryStruct
int loadLocalFile(const char* filePath, struct MemoryStruct* chunk) {
    FILE* file = fopen(filePath, "rb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    chunk->memory = malloc(fileSize + 1);
    if (!chunk->memory) {
        perror("Not enough memory");
        fclose(file);
        return 1;
    }

    fread(chunk->memory, 1, fileSize, file);
    chunk->memory[fileSize] = 0;  // Null-terminate the content
    chunk->size = fileSize;

    fclose(file);
    return 0;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL or file path>\n", argv[0]);
        return 1;
    }

    struct MemoryStruct chunk;
    chunk.memory = NULL;
    chunk.size = 0;

    struct stat pathStat;
    if (stat(argv[1], &pathStat) == 0 && S_ISREG(pathStat.st_mode)) {
        // Argument is a valid file path, load content from the file
        if (loadLocalFile(argv[1], &chunk) != 0) {
            return 1;
        }
    } else {
        // Argument is treated as a URL, fetch content using curl
        CURL* curl = curl_easy_init();
        if (!curl) {
            fprintf(stderr, "Failed to initialize CURL\n");
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            free(chunk.memory);
            return 1;
        }

        curl_easy_cleanup(curl);
    }

    printf("Fetched content:\n");
    renderHTML(chunk.memory);

    free(chunk.memory);
    return 0;
}
