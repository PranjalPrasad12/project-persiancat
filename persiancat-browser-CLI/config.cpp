#include <iostream>

void configureSettings(std::string& searchEngine) {
    std::cout << "Current Search Engine: " << searchEngine << "\n";
    std::cout << "Enter new search engine: ";
    std::cin >> searchEngine;
    std::cout << "Search engine updated to: " << searchEngine << "\n";
}
