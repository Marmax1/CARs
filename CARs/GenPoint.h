#ifndef GENPOINT_H
#define GENPOINT_H

#include "NodalPoint.h"
#include "RoadSlot.h"

class GenPoint : public NodalPoint
{
public:
	GenPoint(QPointF pos, qreal angle, QGraphicsItem* parent = nullptr);

	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) Q_DECL_OVERRIDE;

	void addRoad(Road* road) override;
	Road* getRoad(int index) override;
	void setRoad(Road* road);
	void connectToRoad(Road* road);

private:
	RoadSlot* roadSlot;
};

#endif // GENPOINT_H