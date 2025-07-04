#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QWindow>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <stdio.h>
#include <stdlib.h>
#include "Panel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Panel panel;
    panel.refreshWindows();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("panel", &panel);
    engine.loadFromModule("ashire-panel", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
