/*
  Persiancat Browser CLI- (C) 2024 Pranjal Prasad
  Project Persiancat's Browser CLI is a 'free' software and you are free to redistribute
  it under certain conditions of the GPL v3.

  I have suggested the use of GCC for compiling the browser with its engine
  v. 0.98 Alpha
  Date- Friday, 6 December 2024(A special day)
  
 */
#include <iostream>
#include "headers/menu.h"
#include "headers/config.h"
#include "headers/page.h"
#include "headers/search.h"
#include "../persiancat-engine/html-rendering.h"  // Include engine functionality, most important

// Utility to clear the screen (for better interface experience)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}


// Function to get build information
std::string getBuildInfo() {
    return "Persiancat v. Alpha 0.97.5\nBuilt on: " __DATE__ " " __TIME__ " UTC\nCompiler: " __VERSION__;
}

// Function to detect OS
std::string getOperatingSystem() {
    #if defined(_WIN32) || defined(_WIN64)
    return "Windows";
    #elif defined(__linux__)
    return "Linux";
    #elif defined(__APPLE__)
    return "macOS";
    #else
    return "Unknown OS";
    #endif
}

// Function to display the browser interface
void displayInterface(const std::string& searchEngine) {
    clearScreen();
// START
    std::cout << "File   Edit   View   Buffers/Tabs   Tools   Settings   Help\n";
    std::cout << "\nPersiancat is currently a browser\n";
    std::cout << getBuildInfo() << "\n";
    std::cout << "OS: " << getOperatingSystem() << "\n";  // Display OS info
    std::cout << "(C) Pranjal Prasad 2024\n";
    std::cout << "\nURL- ............................................................................................... (GO)\n";
    std::cout << "Search Query- ................................................................................... (GO)\n";
    std::cout << "Search Engine- " << searchEngine << " (Change Search Engine)\n";
// END
}

// Main program loop
int main() {
    std::string searchEngine = "DuckDuckGo"; // Default search engine
    std::string url, query;

    while (true) {
        displayInterface(searchEngine);

        std::cout << "\nOptions:\n1. Open Menu (Press M)\n2. Enter URL (Press U)\n3. Search (Press S)\n4. Exit (Press E). More Information(I). Copying(C)\n";
        char choice;
        std::cin >> choice;

        switch (choice) {
            case 'M': // Open Menu
                handleMenu();
                break;
            case 'U': // Enter URL
                std::cout << "Enter URL: ";
                std::cin >> url;
                openWebPage(url); // Call engine function to open the web page
                break;
            case 'S': // Search
                std::cout << "Enter search query: ";
                std::cin >> query;
                searchQuery(query, searchEngine);  // Assuming search functionality
                break;
            case 'E': // Exit
                std::cout << "Exiting Persiancat. Goodbye!\n";
                return 0;
            case 'I': // Some Information
                std::cout << "Project Persiancat, a suite of applications that is aimed to be minimal\n";
                std::cout << "Project Persiancat v. 0.98-alpha| Released on 6 December 2024\n";
                std::cout << "Project Persiancat is a free software, you are free to redistribute it under the certain conditions of the GNU GPL v3 and the GPL LGPL v3. For more details see the COPYING file or visit https://github.com/PranjalPrasad12/project-persiancat/blob/master/COPYING\n";
                std::cout << "(C) Pranjal Prasad 2024. Thanks for using Persiancat"
                return 0;
            case 'C': // Display licensing and copying related stuff

                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
