#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnWebBrowser_clicked();

    void on_btnFileManager_clicked();

    void on_btnMediaPlayer_clicked();

    void on_btnImageViewer_clicked();

    void on_btnTextEditor_clicked();

    void on_btnCalculator_clicked();

    void on_btnShutDown_clicked();

    void on_btnOpenHomeFolder_clicked();

    void on_btnOpenDocumentsFolder_clicked();

    void on_btnOpenPicturesFolder_clicked();

    void on_btnOpenMusicFolder_clicked();

    void on_btnOpenSettings_clicked();

    void on_btnOpenDownloadsFolder_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
