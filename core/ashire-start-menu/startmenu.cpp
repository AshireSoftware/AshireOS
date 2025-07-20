#include <iostream>
#include "startmenu.h"

StartMenu::StartMenu(QObject *parent)
    : QObject{parent}
{}

void StartMenu::test(void)
{
    std::cout << "Testing!" << std::endl;
}

void StartMenu::killStartMenu(void)
{
    std::system("killall \"ashire-start-menu\" &");
}

void StartMenu::runDefaultBrowser(void)
{
    std::system("xdg-open https://google.com &");
}

void StartMenu::runTerminal(void)
{
    std::system("alacritty &");
}

void StartMenu::openHomeFolder(void)
{
    std::system("xdg-open ~ &");
}

void StartMenu::openDocumentsFolder(void)
{
    std::system("xdg-open ~/Documents &");
}

void StartMenu::openPicturesFolder(void)
{
    std::system("xdg-open ~/Pictures &");
}

void StartMenu::openVideosFolder(void)
{
    std::system("xdg-open ~/Videos &");
}

void StartMenu::openMusicFolder(void)
{
    std::system("xdg-open ~/Music &");
}
