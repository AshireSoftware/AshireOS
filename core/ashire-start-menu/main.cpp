
#include <QApplication>
#include <QMouseEvent>
#include <QEvent>
#include <QScreen>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    // Move window to bottom left
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = screenGeometry.x();
    int y = screenGeometry.y() + screenGeometry.height() - window.height() - 50;
    window.move(x, y);

    window.setWindowFlags(
        Qt::FramelessWindowHint |
        Qt::Tool |
        Qt::WindowStaysOnBottomHint |
        Qt::BypassWindowManagerHint
        );
    window.setFocusPolicy(Qt::NoFocus);

    window.show();
    return app.exec();
}
