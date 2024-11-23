#include <iostream>

void openWebPage(const std::string& url) {
    if (url.empty()) {
        std::cout << "No URL provided. Returning to main menu.\n";
        return;
    }
    std::cout << "Opening: " << url << "\n";
    // Simulate web page loading here
    std::cout << "Web page loaded successfully.\n";
}
