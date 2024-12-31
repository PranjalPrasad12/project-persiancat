#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QWebEngineView>
#include <QToolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTabWidget *tabWidget;
    QLineEdit *addressBar;
    QWebEngineView *webView;
    QToolBar *toolBar;
};

#endif // MAINWINDOW_H
