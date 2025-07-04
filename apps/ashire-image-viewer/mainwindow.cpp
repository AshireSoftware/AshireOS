#include <QFileDialog>
#include <QFile>
#include <QStandardPaths>
#include <QString>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ImageArea->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    // Search for a file inside the user's home directory
    QString homeDirectory = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);     // Set home directory

    auto fileName = QFileDialog::getOpenFileName(this, "Open a file", homeDirectory, "Image Files (*.png *.jpg *.jpeg *.bmp *.gif);;All Files (*)");
    auto pixmap = QPixmap(fileName);    // Open image
    ui->ImageArea->setPixmap(pixmap);   // Set image to label
}

