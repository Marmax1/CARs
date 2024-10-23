#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
class StartWidget : public QWidget
{
	Q_OBJECT

public:
	StartWidget(QWidget* parent = nullptr);

signals:
	void changeToMap();
};

#endif

