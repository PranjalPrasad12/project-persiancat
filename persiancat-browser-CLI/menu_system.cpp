#include "menu_system.h"

MenuSystem::MenuSystem() : menuVisible(false) {
    // Define menu options
    menuOptions = {
        "1. Load HTML File",
        "2. Enter HTML Content",
        "3. View License",
        "4. Exit"
    };
}

// Display the main menu (toggle on/off)
void MenuSystem::displayMenu() {
    menuVisible = !menuVisible;
    if (menuVisible) renderMenu();
}

// Render the menu with options
void MenuSystem::renderMenu() {
    std::cout << "\n===== PersianCat Browser Menu =====\n";
    for (const auto& option : menuOptions) {
        std::cout << option << "\n";
    }
    std::cout << "Press the corresponding number to select an option.\n";
    std::cout << "Press Ctrl+M to close this menu.\n";
}

// Check if the menu is visible
bool MenuSystem::isMenuVisible() const {
    return menuVisible;
}

// Toggle the visibility of the menu
void MenuSystem::toggleMenu() {
    menuVisible = !menuVisible;
}

// Handle user input for menu selection
void MenuSystem::handleMenuInput() {
    int choice;
    std::cin >> choice;

    // Process selected menu option
    processOption(choice);
}

// Process a selected menu option
void MenuSystem::processOption(int option) {
    switch (option) {
        case 1:
            std::cout << "Option 1: Load HTML File selected.\n";
            // Logic to load HTML file
            break;
        case 2:
            std::cout << "Option 2: Enter HTML Content selected.\n";
            // Logic to enter HTML content
            break;
        case 3:
            std::cout << "Option 3: View License selected.\n";
            // Display license information
            break;
        case 4:
            std::cout << "Exiting PersianCat Browser.\n";
            exit(0);
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
    }
}
