#include "Gui/MainWindow.h"
#include <QFile>

namespace GS
{
    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
    {
        showMaximized();
        com_window = new ComWindow(this);
        setWindowTitle(QString("FESA Management System"));
        setCentralWidget(com_window);
        //const QString styleSheet_file = "ElegantDark.qss";
        //QFile file(styleSheet_file);
        //if (file.open(QFile::ReadOnly))
        {
            //QString styleSheet = QLatin1String(file.readAll());
            //setStyleSheet(styleSheet);
        }
    }
} // GS