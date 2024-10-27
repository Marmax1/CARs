#include "RoadSlot.h"

RoadSlot::RoadSlot(QPointF pos, qreal angle, QGraphicsItem* parent) {
	setPos(pos);
	setRotation(-angle);
	setParentItem(parent);
}

QRectF RoadSlot::boundingRect() const {
	return QRectF();
}

void RoadSlot::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
	painter->setBrush(Qt::yellow);
	painter->drawEllipse(QPointF(0, 0), 10, 10);
}

Road* RoadSlot::getRoad() {
	return road;
}

void RoadSlot::setRoad(Road* road, QPointF position) { /// fix
	this->road = road;
	if (!road->fixSide(0, position, rotation())) {
		road->fixSide(1, position, rotation()); // need to connect, not add
	}
}

void RoadSlot::connectToRoad(Road* road, int indexSide) {
	this->road = road;
	road->fixSide(indexSide);
}