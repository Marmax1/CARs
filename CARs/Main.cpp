#include <QApplication>
#include "MainWidget.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    srand(time(NULL));

    MainWidget widget;
    widget.showMaximized();

    return app.exec();
}