#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>
#include <QGroupBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include "MainWidget.h"
#include "MapView.h"
#include "StartWidget.h"
#include "QStackedWidget"

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent) {
   

    QHBoxLayout* layout = new QHBoxLayout(this);
    StartWidget* widget = new StartWidget(this);
    widget->setGeometry(this->geometry());
    layout->addWidget(widget);

    connect(widget, SIGNAL(changeToMap()), this, SLOT(changeToMap()));
}

void MainWidget::changeToMap() {
    MapView* widget = new MapView(this);
    widget->show();
    QLayoutItem* layoutWithReplacedWidget = this->layout()->replaceWidget(this->layout()->itemAt(0)->widget(), widget);
    delete layoutWithReplacedWidget->widget();
    delete layoutWithReplacedWidget;
}