#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWebEngineView>
#include <QMenuBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create Tab Widget (for browser tabs)
    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);

    // Create a new tab and WebView (for the content)
    QWidget *tab1 = new QWidget();
    tabWidget->addTab(tab1, "Tab 1");

    // Create the address bar
    addressBar = new QLineEdit(this);
    addressBar->setPlaceholderText("Enter URL...");

    // Create the navigation buttons
    QPushButton *backButton = new QPushButton("Back");
    QPushButton *forwardButton = new QPushButton("Forward");
    QPushButton *refreshButton = new QPushButton("Refresh");
    QPushButton *homeButton = new QPushButton("Home");

    // Create layout for the navigation bar (top part)
    QHBoxLayout *navLayout = new QHBoxLayout();
    navLayout->addWidget(backButton);
    navLayout->addWidget(forwardButton);
    navLayout->addWidget(refreshButton);
    navLayout->addWidget(homeButton);
    navLayout->addWidget(addressBar);

    // Add the navigation layout to the main window
    QWidget *navWidget = new QWidget();
    navWidget->setLayout(navLayout);
    setMenuWidget(navWidget);

    // WebView to display web pages
    webView = new QWebEngineView(this);
    webView->setUrl(QUrl("https://www.google.com"));
    tab1->setLayout(new QVBoxLayout());
    tab1->layout()->addWidget(webView);

    // Menu Bar (for File, Edit menus)
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("New Tab");
    fileMenu->addAction("Exit");

    QMenu *editMenu = menuBar()->addMenu("Edit");
    editMenu->addAction("Preferences");

    // ToolBar (for bookmarks, etc.)
    toolBar = addToolBar("Bookmarks");
    toolBar->addAction("Bookmark This Page");
}

MainWindow::~MainWindow()
{
    // Destructor if you need to clean up resources
}
