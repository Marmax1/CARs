#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "NodalPoint.h"
#include "Road.h"
#include "RoadSlot.h"

class Intersection : public NodalPoint
{
public:
	Intersection(int countOfRoads, QGraphicsItem* parent = nullptr);
	Intersection(int countOfRoads, QList<QPointF> slotPoints, QList<qreal> angles, QGraphicsItem* parent = nullptr);
	

	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) Q_DECL_OVERRIDE;

	void addRoad(Road* road) override;
	Road* getRoad(int index) override;

	static Intersection* getSimlpeIntersection4();

private:
	QList<RoadSlot*> roadSlots;
};

#endif

