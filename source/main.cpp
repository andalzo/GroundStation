#include <QApplication>
#include "Gui/MainWindow.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GS::MainWindow window;
    window.show();
    return QApplication::exec();
}
