#include "GenPoint.h"

GenPoint::GenPoint(QPointF pos, qreal angle, QGraphicsItem* parent) {
	setPos(pos);
	setParentItem(parent);
	roadSlot = new RoadSlot(QPointF(0,0), angle, this);
}

QRectF GenPoint::boundingRect() const {
	return QRectF();
}

void GenPoint::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
	return;
}

void GenPoint::setRoad(Road* road) {
	roadSlot->setRoad(road, mapToScene(roadSlot->pos()));
}

void GenPoint::addRoad(Road* road) {
	setRoad(road);
}

Road* GenPoint::getRoad(int index) {
	return roadSlot->getRoad();
}

void GenPoint::connectToRoad(Road* road) {
	if (road->isFirstSideFixed()) {
		if (road->isSecondSideFixed()) {
			return; // can't connect
		}
		else {
			roadSlot->connectToRoad(road, 1);
			setPos(road->getSecondSidePoint());
		}
	}
	else {
		roadSlot->connectToRoad(road, 0);
		setPos(road->getFirstSidePoint());
	}
}