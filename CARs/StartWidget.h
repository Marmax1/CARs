#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <qwidget.h>
class StartWidget : public QWidget
{
	Q_OBJECT

public:
	StartWidget(QWidget* parent = nullptr);

private:
	QLayout* defaultLayout;
	QLayout* settingsLayout;
};

#endif

