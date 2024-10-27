#ifndef ROAD_H
#define ROAD_H

#include <QString>
#include <QPainter>
#include "Lane.h"
#include <QTransform>

class Road : public QGraphicsItem {
public:
	Road(qreal widthLane, int lanesTo1, int lanesTo2);

	QRectF boundingRect() const Q_DECL_OVERRIDE;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) Q_DECL_OVERRIDE;

	qreal getLength() const;
	int getCountLanes() const;


	bool fixSide(int index);
	bool fixSide(int index, QPointF pos, qreal angle);
	bool isFirstSideFixed();
	bool isSecondSideFixed();
	QPointF getFirstSidePoint();
	QPointF getSecondSidePoint();

private:
	qreal length;
	int widthLane;
	int countLanes;
	QGraphicsItemGroup* lanesTo;
	QGraphicsItemGroup* lanesFrom;
	QPointF firstSidePoint;
	bool firstSideFixed;
	QPointF secondSidePoint;
	bool secondSideFixed;

	static QTransform getTransformMoveInDirection(qreal distance, qreal angle);
};

#endif // ROAD_H
