#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();  // Display the main window

    return app.exec();  // Start the Qt event loop
}
