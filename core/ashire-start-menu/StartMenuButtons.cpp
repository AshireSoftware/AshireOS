#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_btnWebBrowser_clicked()
{
    system("firefox &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnFileManager_clicked()
{
    system("dolphin &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnMediaPlayer_clicked()
{
    system("ashire-media-player &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnImageViewer_clicked()
{
    system("ashire-image-viewer &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnTextEditor_clicked()
{
    system("ashire-text-editor &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnCalculator_clicked()
{
    system("ashire-calculator &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnShutDown_clicked()
{
    system("shutdown now");
    system("killall ashire-start-menu");
}


void MainWindow::on_btnOpenHomeFolder_clicked()
{
    system("dolphin ~/ &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnOpenDocumentsFolder_clicked()
{
    system("dolphin ~/Documents &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnOpenPicturesFolder_clicked()
{
    system("dolphin ~/Pictures &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnOpenMusicFolder_clicked()
{
    system("dolphin ~/Music &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnOpenDownloadsFolder_clicked()
{
    system("dolphin ~/Downloads &");
    system("killall ashire-start-menu");
}

void MainWindow::on_btnOpenSettings_clicked()
{
    system("ashire-settings &");
    system("killall ashire-start-menu");
}
