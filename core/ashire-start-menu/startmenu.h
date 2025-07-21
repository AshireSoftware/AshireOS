#ifndef STARTMENU_H
#define STARTMENU_H

#include <QObject>

class StartMenu : public QObject
{
    Q_OBJECT
public:
    explicit StartMenu(QObject *parent = nullptr);

public slots:
    void test();
    void killStartMenu();
    void shutdownComputer();
    void runDefaultBrowser();
    void runTerminal();
    void openHomeFolder();
    void openDocumentsFolder();
    void openPicturesFolder();
    void openVideosFolder();
    void openMusicFolder();
signals:
};

#endif // STARTMENU_H
