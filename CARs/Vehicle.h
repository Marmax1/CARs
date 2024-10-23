#pragma once
#include <qgraphicsitem.h>

class Vehicle : QGraphicsItem
{

public:
	qreal getSpeed();
	qreal getMaxSpeed();

private:

	qreal speed;
	qreal maxSpeed;

};

