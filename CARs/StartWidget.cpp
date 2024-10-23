#include "StartWidget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QScreen>
#include <QSpacerItem>


StartWidget::StartWidget(QWidget* parent)
    : QWidget(parent)
{
    // Create a widget for the button
    QWidget* buttonWidget = new QWidget(this);
    QVBoxLayout* buttonLayout = new QVBoxLayout(buttonWidget);
    buttonLayout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    // Create buttons for buttonWidget
    QPushButton* startButton = new QPushButton("Start", buttonWidget);
    QPushButton* settingsButton = new QPushButton("Settings", buttonWidget);
    QPushButton* aboutQtButton = new QPushButton("About app", buttonWidget);
    QPushButton* exitButton = new QPushButton("Exit", buttonWidget);
    // Setup the size
    QSize buttonSize = QGuiApplication::primaryScreen()->availableSize() / 8;
    startButton->setFixedSize(buttonSize);
    settingsButton->setFixedSize(buttonSize);
    aboutQtButton->setFixedSize(buttonSize);
    exitButton->setFixedSize(buttonSize);

    //Add them to the layout
    buttonLayout->setSpacing(25);
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(settingsButton);
    buttonLayout->addWidget(aboutQtButton);
    buttonLayout->addWidget(exitButton);

    // Create widget for every button
    QWidget* settingsWidget = new QWidget(this);
    QLabel* settingsLabel = new QLabel("Settings", settingsWidget);
    settingsLabel->setAlignment(Qt::AlignCenter);
    QPushButton* settingsCloseButton = new QPushButton("Close", settingsWidget);

    QWidget* aboutQtWidget = new QWidget(this);
    QLabel* aboutQtLabel = new QLabel("About Qt", aboutQtWidget);
    aboutQtLabel->setAlignment(Qt::AlignCenter);
    QPushButton* aboutQtCloseButton = new QPushButton("Close", aboutQtWidget);

    // Create stackedWidget
    QStackedWidget* stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(buttonWidget);
    stackedWidget->addWidget(settingsWidget);
    stackedWidget->addWidget(aboutQtWidget);

    //Define layout of current widget
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(stackedWidget);

    connect(startButton, &QPushButton::clicked, this, [=]() {
        emit changeToMap();
        });

    connect(settingsButton, &QPushButton::clicked, this, [=]() {
        stackedWidget->setCurrentWidget(settingsWidget);
        });

    connect(aboutQtButton, &QPushButton::clicked, this, [=]() {
        stackedWidget->setCurrentWidget(aboutQtWidget);
        });

    connect(exitButton, &QPushButton::pressed, this, &QWidget::close);

    // Connect the signal of pressing the "Close" button to the slots
    connect(settingsCloseButton, &QPushButton::pressed, this, [=]() {
        stackedWidget->setCurrentWidget(buttonWidget);
        });

    connect(aboutQtCloseButton, &QPushButton::clicked, this, [=]() {
        stackedWidget->setCurrentWidget(buttonWidget);
        });
}