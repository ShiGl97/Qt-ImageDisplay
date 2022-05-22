#include "imagedisplay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageDisplay w;
    w.show();
    return a.exec();
}
