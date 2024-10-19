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

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent) {
   
    MapView* centralWid = new MapView(this);
    centralWidget = centralWid;
    centralWidget->setGeometry(QGuiApplication::primaryScreen()->geometry());

    QGroupBox* groupBox = new QGroupBox(tr("Group Box with Layout"), this);

    QRadioButton* radio1 = new QRadioButton(tr("&Radio button 1"));
    QRadioButton* radio2 = new QRadioButton(tr("R&adio button 2"));
    QRadioButton* radio3 = new QRadioButton(tr("Ra&dio button 3"));

    radio1->setChecked(true);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);

    groupBox->setGeometry(20, 20, 100, 100);
}