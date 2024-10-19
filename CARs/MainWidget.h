#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MainWidget : public QWidget {
    Q_OBJECT
    
public:
    MainWidget(QWidget* parent = nullptr);

private:
    QWidget* centralWidget;
    QTimer* timer;
};

#endif