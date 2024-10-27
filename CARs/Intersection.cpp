#include "Intersection.h"

Intersection::Intersection(int countOfRoads, QGraphicsItem* parent) {
	setParentItem(parent);
	roadSlots = QList<RoadSlot*>(countOfRoads);
}

Intersection::Intersection(int countOfRoads, QList<QPointF> slotPoints, QList<qreal> angles, QGraphicsItem* parent) {
	setParentItem(parent);
	roadSlots = QList<RoadSlot*>();
	for (int i = 0; i < countOfRoads; i++) {
		roadSlots.push_back(new RoadSlot(slotPoints[i], angles[i], this));
	}
}

QRectF Intersection::boundingRect() const {
	return QRectF(QPointF(-50, -50), QPointF(50, 50));
}

void Intersection::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
	painter->setPen(Qt::darkBlue);
	painter->setBrush(Qt::darkBlue);
	painter->drawRect(boundingRect());
}

void Intersection::addRoad(Road* road) {
	for (auto& item : roadSlots) {
		if (item->getRoad() == nullptr) {
			auto check = pos();
			auto check2 = item->pos();
			QPointF check3 = mapToScene(item->pos());
			item->setRoad(road, mapToScene(item->pos()));
			return;
		}
	}
}

Road* Intersection::getRoad(int index) {
	if (index < 0 && index >= roadSlots.size()) {
		return nullptr;
	}

	return roadSlots[index]->getRoad();
}

Intersection* Intersection::getSimlpeIntersection4() {
	QList<QPointF> slotPoints;
	QList<qreal> angles;
	slotPoints.push_back(QPointF(0, -50));
	angles.push_back(90);
	slotPoints.push_back(QPointF(50, 0));
	angles.push_back(0);
	slotPoints.push_back(QPointF(0, 50));
	angles.push_back(-90);
	slotPoints.push_back(QPointF(-50, 0));
	angles.push_back(-180);
	return new Intersection(4, slotPoints, angles);
}