#include "Path.h"

QPainterPath Path::turnToPoint(QPointF startPos, qreal startAngle, QPointF endPos, qreal endAngle) {
    QPainterPath path = QPainterPath(startPos);

    path.quadTo(getIntersection(startPos, startAngle, endPos, endAngle), endPos);

    return path;
}

QPointF Path::getIntersection(QPointF point1, qreal angleInPoint1, QPointF point2, qreal angleInPoint2) {
    // Convert the angles to radians
    angleInPoint1 = qDegreesToRadians(angleInPoint1);
    angleInPoint2 = qDegreesToRadians(angleInPoint2);

    // Calculate the slope and y-intercept of each line
    qreal m1 = qTan(angleInPoint1);
    qreal b1 = point1.y() - m1 * point1.x();
    qreal m2 = qTan(angleInPoint2);
    qreal b2 = point2.y() - m2 * point2.x();

    // Check if the lines are parallel
    if (qFuzzyCompare(m1, m2)) {
        // The lines are parallel
        return QPointF();
    }

    // Calculate the intersection point
    qreal x = (b2 - b1) / (m1 - m2);
    qreal y = m1 * x + b1;

    return QPointF(x, y);
}