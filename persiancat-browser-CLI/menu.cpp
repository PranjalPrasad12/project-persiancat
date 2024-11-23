#include <iostream>

void handleMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. File\n2. Edit\n3. Help\n";
    char menuChoice;
    std::cin >> menuChoice;

    switch (menuChoice) {
        case '1': // File
            std::cout << "File Menu:\n1. New Tab\n2. Open\n3. Open Local Page\n4. Use Network Shares (Planned)\n";
            break;
        case '2': // Edit
            std::cout << "Edit Menu:\n1. Undo\n2. Redo\n3. Cut\n4. Copy\n5. Paste\n";
            break;
        case '3': // Help
            std::cout << "Help Menu:\n1. Tutorial\n2. FAQ\n3. Repository\n4. Credits\n5. About\n";
            break;
        default:
            std::cout << "Invalid menu choice.\n";
    }
}
