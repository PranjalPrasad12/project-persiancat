#include <iostream>

void searchQuery(const std::string& query, const std::string& searchEngine) {
    if (query.empty()) {
        std::cout << "No query provided. Returning to main menu.\n";
        return;
    }
    std::cout << "Searching for: " << query << " using " << searchEngine << "\n";
    // Simulate search operation here
    std::cout << "Search results displayed.\n";
}
