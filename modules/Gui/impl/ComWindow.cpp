#include "Gui/ComWindow.h"

namespace GS
{

    ComWindow::ComWindow(QWidget* parent) : QWidget(parent)
    {
        main_h_layout = new QHBoxLayout(this);

        media_player = new QMediaPlayer(this);
        media_player->setSource(QUrl("gst-pipeline: rtpsrc uri=rtp://192.168.1.41:5000?encoding-name=H264 ! rtph264depay ! "
                          "avdec_h264 max-threads=8 ! xvimagesink name=qtvideosink sync=false"));

        video_widget = new QVideoWidget(this);
        media_player->setVideoOutput(video_widget);




        console = new QTextEdit(this);
        console->setPlaceholderText("Waiting Commands...");
        console->setFixedSize(QSize(1200, 250));

        v1_layout = new QVBoxLayout();
        v1_layout->addWidget(video_widget);
        v1_layout->addWidget(console);

        h1_layout = new QHBoxLayout();
        h1_layout->addWidget(command_line);
        h1_layout->addWidget(enter_command_button);

        v1_layout->addLayout(h1_layout);
        main_h_layout->addLayout(v1_layout);

        v2_layout = new QVBoxLayout();
        Altitude_label = new QLabel("Altitude:", this);
        Longitude_label = new QLabel("Longitude:", this);
        Velocity_label = new QLabel("Velocity:", this);
        Angle_label = new QLabel("Yaw Angle:", this);
        Pitch_label = new QLabel("Pitch Angle:", this);

        v2_layout->addWidget(Altitude_label);
        v2_layout->addWidget(Longitude_label);
        v2_layout->addWidget(Velocity_label);
        v2_layout->addWidget(Angle_label);
        v2_layout->addWidget(Pitch_label);

        arm_command_button = new QPushButton("Enter Arm Mode", this);
        land_command_button = new QPushButton("Enter Landing Sequence", this);
        fly_command_button = new QPushButton("Enter Flight Sequence", this);

        v2_layout->addWidget(arm_command_button);
        v2_layout->addWidget(land_command_button);
        v2_layout->addWidget(fly_command_button);

        main_h_layout->addLayout(v2_layout);
    }
} // GS