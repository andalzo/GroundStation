#pragma once
#include <QMainWindow>
#include "ComWindow.h"
#include "ManagementWindow.h"

namespace GS
{
    class MainWindow final : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        ComWindow* com_window;
        ManagementWindow* management_window{};
    };
}


