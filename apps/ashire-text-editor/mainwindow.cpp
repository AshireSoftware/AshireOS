#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->TextArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->TextArea->setText("");  // Delete text
    filePath = "";  // Set file path to none
}

void MainWindow::on_actionOpen_triggered()
{
    file = QFileDialog::getOpenFileName(this, "Open a file");

    if (!file.isEmpty())
    {
        QFile filePath(file);
        if (filePath.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&filePath);
            QString text = in.readAll();
            ui->TextArea->setPlainText(text);
            filePath.close();
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    // Check if a file is already opened.
    // Open a save file window dialog if no file is opened.
    if (file.isEmpty()) {
        MainWindow::on_actionSave_as_triggered();
    }

    QFile file(filePath);
    // Save the text to a file if a file is already opened.
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
        out << ui->TextArea->toPlainText();
        file.flush();
        file.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString saveFilePath = QFileDialog::getSaveFileName(this, "Save file");
    filePath = saveFilePath;
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open file.");
        return;
    }
    QTextStream out(&file);
    QString text = ui->TextArea->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionIncrease_Font_Size_triggered()
{
    // Increase font size
    QFont font = ui->TextArea->font();
    int currentSize = font.pointSize();
    font.setPointSize(currentSize + 2);
    ui->TextArea->setFont(font);
}

void MainWindow::on_actionDecrease_Font_Size_triggered()
{
    // Decrease font size
    QFont font = ui->TextArea->font();
    int currentSize = font.pointSize();
    font.setPointSize(currentSize - 2);
    ui->TextArea->setFont(font);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->TextArea->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->TextArea->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->TextArea->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->TextArea->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->TextArea->redo();
}

