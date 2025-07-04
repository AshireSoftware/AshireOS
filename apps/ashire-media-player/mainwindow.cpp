#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Sets up the media player, video widget and audio output.
    MediaPlayer = new QMediaPlayer(this);
    VideoWidget = new QVideoWidget(this);
    AudioOutput = new QAudioOutput(this);
    MediaPlayer->setVideoOutput(VideoWidget);
    MediaPlayer->setAudioOutput(AudioOutput);

    // Creates the progress bar and connects it with with the media plyer.
    VideoProgressSlider = new QSlider(Qt::Horizontal);
    connect(MediaPlayer, &QMediaPlayer::durationChanged, VideoProgressSlider, &QSlider::setMaximum);
    connect(MediaPlayer, &QMediaPlayer::positionChanged, VideoProgressSlider, &QSlider::setValue);
    connect(VideoProgressSlider, &QSlider::sliderMoved, MediaPlayer, &QMediaPlayer::setPosition);

    // Creates the play/pause button.
    btnTogglePlayback = new QPushButton(this);
    btnTogglePlayback->setIcon(QIcon::fromTheme("media-playback-pause"));
    connect(btnTogglePlayback,&QPushButton::clicked,this, &MainWindow::on_actionPlaybackToggle_triggered);

    // Creates the mute/unmute button.
    btnToggleAudio = new QPushButton(this);
    btnToggleAudio->setIcon(QIcon::fromTheme("audio-volume-high"));
    connect(btnToggleAudio,&QPushButton::clicked,this, &MainWindow::on_actionAudioToggle_triggered);

    // Creates the fullscreen button.
    btnToggleFullscreen = new QPushButton(this);
    btnToggleFullscreen->setIcon(QIcon::fromTheme("view-fullscreen"));
    connect(btnToggleFullscreen,&QPushButton::clicked,this, &MainWindow::on_actionToggle_Fullscreen_triggered);

    // Creates the volume slider and connects it to audio.
    VolumeSlider = new QSlider(Qt::Horizontal);
    VolumeSlider->setFixedWidth(69);
    VolumeSlider->setValue(100);
    connect(VolumeSlider, &QSlider::valueChanged, this, [=](int value){
        qreal volume = value / 100.0;
        AudioOutput->setVolume(volume);
    });

    // Sets the video layout and container.
    QHBoxLayout *videoLayout = new QHBoxLayout();
    videoLayout->setContentsMargins(0, 0, 0, 0);
    videoLayout->setSpacing(0);
    videoLayout->addWidget(VideoWidget);
    QWidget *videoContainer = new QWidget(this);
    videoContainer->setLayout(videoLayout);

    // Adds a spacer between the video and playback controls layouts.
    QSpacerItem *Spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    videoLayout->addItem(Spacer);

    // Sets the layout and container for controls.
    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(VideoProgressSlider);
    controlsLayout->addWidget(VolumeSlider);
    controlsLayout->addWidget(btnToggleFullscreen);
    controlsLayout->addWidget(btnTogglePlayback);
    controlsLayout->addWidget(btnToggleAudio);
    QWidget *controlsContainer = new QWidget(this);
    controlsContainer->setLayout(controlsLayout);

    // Sets the layout combining both layouts and containers.
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(videoContainer);
    mainLayout->addWidget(controlsContainer);

    // Sets layout on the central widget.
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    // Searches for a file inside the user's home directory.
    QString homeDirectory = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", homeDirectory,
        "Video Files (*.mp4 *.mp3 *.webm *.wav *.avi *.mpg);;All Files (*)");
    MediaPlayer->setSource(QUrl::fromLocalFile(fileName));
    MediaPlayer->play();
}

void MainWindow::on_actionPlaybackToggle_triggered()
{
    // Checks if the video is already paused.
    if(isVideoPaused == true)
    {
        // Unpauses video.
        isVideoPaused = false;
        btnTogglePlayback->setIcon(QIcon::fromTheme("media-playback-pause"));
        MediaPlayer->play();
    }
    else {
        // Pauses video.
        isVideoPaused = true;
        btnTogglePlayback->setIcon(QIcon::fromTheme("media-playback-start"));
        MediaPlayer->pause();
    }
}

void MainWindow::on_actionAudioToggle_triggered()
{
    // Checks if the video is already muted.
    if(isVideoMuted == true)
    {
        // Unmutes video
        isVideoMuted = false;
        AudioOutput->setVolume(100);
        btnToggleAudio->setIcon(QIcon::fromTheme("audio-volume-high"));
    }
    else {
        // Mutes video
        isVideoMuted = true;
        AudioOutput->setVolume(0);
        btnToggleAudio->setIcon(QIcon::fromTheme("audio-volume-muted"));
    }
}

void MainWindow::on_actionToggle_Fullscreen_triggered()
{
    // Checks if the video is already fullscreen.
    if(isVideoFullscreen == true)
    {
        // Unfullscreens video.
        isVideoFullscreen = false;
        btnToggleFullscreen->setIcon(QIcon::fromTheme("view-restore"));
        this->showNormal();
    }
    else {
        // Fullscreens video.
        isVideoFullscreen = true;
        btnToggleFullscreen->setIcon(QIcon::fromTheme("view-fullscreen"));
        this->showFullScreen();
    }
}

void MainWindow::on_actionIncrease_Volume_triggered()
{
    // Increases the volume.
}

void MainWindow::on_actionDecrease_Volume_triggered()
{
    // Decreases the volume.
}
