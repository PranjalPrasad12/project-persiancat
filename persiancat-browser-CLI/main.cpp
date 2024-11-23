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
    std::cout << "START\n";
    std::cout << "File   Edit   View   Buffers/Tabs   Tools   Settings   Help\n";
    std::cout << "\nPersiancat is currently a browser\n";
    std::cout << getBuildInfo() << "\n";
    std::cout << "OS: " << getOperatingSystem() << "\n";  // Display OS info
    std::cout << "(C) Pranjal Prasad 2024\n";
    std::cout << "\nURL- ............................................................................................... (GO)\n";
    std::cout << "Search Query- ................................................................................... (GO)\n";
    std::cout << "Search Engine- " << searchEngine << " (Change Search Engine)\n";
    std::cout << "END\n";
}

// Main program loop
int main() {
    std::string searchEngine = "DuckDuckGo"; // Default search engine
    std::string url, query;

    while (true) {
        displayInterface(searchEngine);

        std::cout << "\nOptions:\n1. Open Menu (Press M)\n2. Enter URL (Press U)\n3. Search (Press S)\n4. Exit (Press E)\n";
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
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
