#pragma once

#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>

namespace GS
{
    class ComWindow final : public QWidget
    {
        Q_OBJECT

    public:
        explicit ComWindow(QWidget* parent = nullptr);

    private:
        QHBoxLayout* main_h_layout;
        QVBoxLayout* v1_layout;
        QVBoxLayout* v2_layout;
        QHBoxLayout* h1_layout;

        QMediaPlayer* media_player;
        QVideoWidget* video_widget;

        QPlainTextEdit* console;

        QLabel* altitude_label;
        QLabel* longtitude_label;
        QLabel* latitude_label;
        QLabel* speed_label;
        QLabel* yaw_label;
        QLabel* roll_label;
        QLabel* pitch_label;
        QLabel* battery_percent;

        QPushButton* start_server_button;
        QPushButton* open_mw_button;
        QPushButton* settings_button;
    };

} // GS

