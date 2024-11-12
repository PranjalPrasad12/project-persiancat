#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>

class MenuSystem {
public:
    MenuSystem();
    void displayMenu();        // Display the main menu
    void handleMenuInput();     // Handle user inputs for the menu
    bool isMenuVisible() const; // Check if the menu is currently visible
    void toggleMenu();          // Toggle the visibility of the menu

private:
    bool menuVisible;           // Flag for menu visibility
    std::vector<std::string> menuOptions; // List of menu options
    void renderMenu();          // Render the menu on screen
    void processOption(int option); // Process chosen option
};

#endif // MENU_SYSTEM_H
