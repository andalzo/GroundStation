#include "Gui/ComWindow.h"
namespace GS
{

    ComWindow::ComWindow(QWidget* parent) : QWidget(parent)
    {
        //Creating layouts
        main_h_layout = new QHBoxLayout(this);
        v1_layout = new QVBoxLayout();
        v2_layout = new QVBoxLayout();
        h1_layout = new QHBoxLayout();

        //Creating widgets
        media_player = new QMediaPlayer(this);
        media_player->setSource(QUrl::fromLocalFile(QString("/home/andalzo/FESA/GroundStation/data/testvideo.mp4")));

        video_widget = new QVideoWidget(this);
        video_widget->setFixedSize(QSize(1200,800));
        media_player->setVideoOutput(video_widget);
        media_player->play();

        console = new QPlainTextEdit(this);
        console->setPlaceholderText("...");
        console->setFixedSize(QSize(1200, 200));

        longtitude_label = new QLabel("Longtitude: ", this);
        latitude_label = new QLabel("Latitude: ", this);
        altitude_label = new QLabel("Altitude: ", this);
        speed_label = new QLabel("Velocity: ", this);
        yaw_label = new QLabel("Yaw Angle: ", this);
        roll_label = new QLabel("Roll Angle: ", this);
        pitch_label = new QLabel("Pitch Angle: ", this);
        battery_percent = new QLabel("Battery Percent: ", this);

        start_server_button  = new QPushButton("Start Server", this);
        open_mw_button = new QPushButton("Open Management Window", this);
        settings_button = new QPushButton("Settings", this);

        //Adding widgets

        v1_layout->addWidget(video_widget);
        v1_layout->addWidget(console);
        v1_layout->addLayout(h1_layout);

        v2_layout->addWidget(longtitude_label);
        v2_layout->addWidget(latitude_label);
        v2_layout->addWidget(altitude_label);
        v2_layout->addWidget(speed_label);
        v2_layout->addWidget(yaw_label);
        v2_layout->addWidget(roll_label);
        v2_layout->addWidget(pitch_label);
        v2_layout->addWidget(battery_percent);

        v2_layout->addWidget(start_server_button);
        v2_layout->addWidget(console);
        v2_layout->addWidget(settings_button);

        main_h_layout->addLayout(v1_layout);
        main_h_layout->addLayout(v2_layout);
    }
} // GS