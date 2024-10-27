#ifndef ROADSLOT_H
#define ROADSLOT_H

#include "Road.h"

class RoadSlot : public QGraphicsItem
{
public:
	RoadSlot(QPointF pos, qreal angle, QGraphicsItem* parent = nullptr);

	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) Q_DECL_OVERRIDE;

	Road* getRoad();
	void setRoad(Road* road, QPointF position);
	void connectToRoad(Road* road, int indexSide);
private:
	Road* road;
};

#endif
