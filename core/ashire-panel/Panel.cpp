#include <QRegularExpression>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <cstdio>
#include <string>
#include "Panel.h"

Panel::Panel(QObject *parent) : QObject(parent), m_prevFocusedId("")
{
}

QVariantList Panel::windows() const
{
    return m_windows;
}

bool Panel::isProgramRunning(const std::string& programName) {
    std::string command = "pidof " + programName + " > /dev/null";
    int result = system(command.c_str());   // return exit status
    return (result == 0);
}

void Panel::refreshWindows()
{
    // List of program titles to ignore
    static const QStringList ignoreList = {
        "Ashire Window Decorations",
        "Ashire Start Menu",
        "Ashire Panel",
        "plasmashell",
        "@!0,0;BDHF",
        "Desktop @"
    };

    m_windows.clear();

    QProcess process;
    process.start("wmctrl", QStringList() << "-l");
    if (!process.waitForFinished(2000)) {
        qWarning() << "Failed to run wmctrl";
        emit windowsChanged();
        return;
    }

    QString output = process.readAllStandardOutput();
    QStringList lines = output.split('\n', Qt::SkipEmptyParts);
    for (const QString &line : lines) {
        auto parts = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        if (parts.size() >= 4) {
            QString idHex = parts[0];
            QString title = parts.mid(3).join(' ');

            // Check if the window title matches any from the ignore list
            bool shouldIgnore = false;
            for (const QString &ignoreTitle : ignoreList) {
                if (title.contains(ignoreTitle, Qt::CaseInsensitive)) {
                    shouldIgnore = true;
                    break;
                }
            }

            if (shouldIgnore)
                continue; // Skip this window

            QVariantMap window;
            window["id"] = idHex;
            window["title"] = title;
            m_windows.append(window);
        }
    }
    emit windowsChanged();
}

QString Panel::getFocusedWindow()
{
    QProcess process;
    process.start("xdotool", {"getwindowfocus"});
    if (!process.waitForFinished(2000))
        return "";

    QString output = process.readAllStandardOutput().trimmed();
    bool ok;
    int decimalId = output.toInt(&ok);
    if (!ok)
        return "";

    return QString("0x%1").arg(decimalId, 8, 16, QLatin1Char('0'));
}

void Panel::minimizeWindow(const QString &winId)
{
    QProcess::execute("xdotool", {"windowminimize", winId});
}

void Panel::focusWindow(const QString &winId)
{
    QProcess::execute("wmctrl", {"-ia", winId});
}

QString Panel::getPrevFocusedId() const
{
    return m_prevFocusedId;
}

void Panel::setPrevFocusedId(const QString &id)
{
    m_prevFocusedId = id;
}

void Panel::openStartMenu()
{
    std::string program = "ashire-start-menu";

    // Start an instance of the start menu if none exist
    if (!isProgramRunning(program)) {
        system("ashire-start-menu &");
        std::cout << "Started the start menu process" << std::endl;
        system("sleep 0.4 && wmctrl -a \"Ashire Panel\"");   // Moves focus from Start Menu to Panel
    }

    // kill start menu instances if at least one exists
    else {
        system("killall ashire-start-menu");
        std::cout << "Killed the start menu process" << std::endl;
    }
}
