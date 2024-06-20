#include <QApplication>
#include "src/control/allControl/allcontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/image/statusImage/logo.ico"));
    AllControl* allControl = new AllControl();
    MainWindow *w = MainWindow::getInstance();
    w->show();
    return a.exec();
}
