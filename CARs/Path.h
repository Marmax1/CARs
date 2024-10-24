#ifndef PATH_H
#define PATH_H

#include <QtMath>
#include <QPainterPath>

class Path
{
public:
	static QPainterPath turnToPoint(QPointF startPos, qreal startAngle, QPointF endPos, qreal endAngle);

private:
	static QPointF getIntersection(QPointF startPos, qreal startAngle, QPointF endPos, qreal endAngle);
};

#endif

