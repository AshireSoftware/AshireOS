#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimediaWidgets>
#include <QtMultimedia>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QProgressBar>
#include <QSlider>
#include <QString>
#include <QStandardPaths>
#include <QPushButton>
#include <QSpacerItem>
#include <QLayout>

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
    void on_actionOpen_triggered();
    void on_actionPlaybackToggle_triggered();
    void on_actionAudioToggle_triggered();
    void on_actionToggle_Fullscreen_triggered();
    void on_actionIncrease_Volume_triggered();
    void on_actionDecrease_Volume_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* MediaPlayer;
    QVideoWidget* VideoWidget;
    QAudioOutput* AudioOutput;
    QSlider* VideoProgressSlider;
    QSlider* VolumeSlider;
    QPushButton* btnTogglePlayback;
    QPushButton* btnToggleAudio;
    QPushButton* btnToggleFullscreen;
    QSpacerItem* Spacer;
    quint64 VideoDuration;
    int videoVolume;
    bool isVideoPaused = false;
    bool isVideoMuted = false;
    bool isVideoFullscreen = false;
};
#endif // MAINWINDOW_H
