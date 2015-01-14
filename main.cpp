#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *mainWindow = new MainWindow;
    mainWindow->setMinimumSize(640, 480);

    mainWindow->show();

    return app.exec();
}
