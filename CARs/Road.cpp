#include "Road.h"

Road::Road(qreal widthLane, int lanesTo1, int lanesTo2) {
    lanesTo = new QGraphicsItemGroup();
    lanesFrom = new QGraphicsItemGroup();

    qreal offset = widthLane / 2;

    firstSidePoint = QPointF(-250, 0);
    secondSidePoint = QPointF(250, 0);

    QPointF startPoint1 = QPointF(-250, 0) + QPointF(0, offset);
    QPointF endPoint1 = QPointF(250, 0) + QPointF(0, offset);
    QPointF startPoint2 = QPointF(250, 0) - QPointF(0, offset);
    QPointF endPoint2 = QPointF(-250, 0) - QPointF(0, offset);

    for (int i = 0; i < lanesTo1; i++) {
        QPainterPath path(startPoint1);
        path.lineTo(endPoint1);
        Lane* lane = new Lane(path, widthLane);
        lanesTo->addToGroup(lane);
        startPoint1.setY(startPoint1.y() + widthLane);
        endPoint1.setY(endPoint1.y() + widthLane);
    }

    for (int i = 0; i < lanesTo2; i++) {
        QPainterPath path;
        path.moveTo(startPoint2);
        path.lineTo(endPoint2);
        Lane* lane = new Lane(path, widthLane);
        lanesFrom->addToGroup(lane);
        startPoint2.setY(startPoint2.y() - widthLane);
        endPoint2.setY(endPoint2.y() - widthLane);
    }

    length = QLineF(firstSidePoint, secondSidePoint).length();
}

QRectF Road::boundingRect() const {
    QRectF rect1 = lanesTo->boundingRect();
    QRectF rect2 = lanesFrom->boundingRect();
    return rect1.united(rect2);
    return QRectF();
}

void Road::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::gray);

    painter->drawPath(lanesTo->shape());
    painter->drawPath(lanesFrom->shape());

    painter->setPen(Qt::white);
    painter->setBrush(Qt::NoBrush);

    QList<QGraphicsItem*> lanes1 = lanesTo->childItems();
    QList<QGraphicsItem*> lanes2 = lanesFrom->childItems();

    for (int i = 0; i < lanes1.size(); i++) {
        QLineF line1(lanes1[i]->boundingRect().left(), lanes1[i]->boundingRect().top(),
            lanes1[i]->boundingRect().right(), lanes1[i]->boundingRect().top());
        painter->drawLine(line1);
        /*painter->drawRect(lanes1[i]->boundingRect());
        painter->drawRect(lanes1[i + 1]->boundingRect());*/
    }
    painter->setPen(Qt::red);
    painter->setBrush(Qt::NoBrush);
    for (int i = 0; i < lanes2.size(); i++) {
        QLineF line2(lanes2[i]->boundingRect().left(), lanes2[i]->boundingRect().bottom(),
            lanes2[i]->boundingRect().right(), lanes2[i]->boundingRect().bottom());
        painter->drawLine(line2);
        /*painter->drawRect(lanes2[i]->boundingRect());
        painter->drawRect(lanes2[i + 1]->boundingRect());*/
    }
}

double Road::getLength() const {
	return length;
}

int Road::getCountLanes() const {
	return countLanes;
}

bool Road::fixSide(int side) {
    if (side == 0 && !firstSideFixed) {
        firstSideFixed = true;
        return true;
    }
    if (side == 1 && !secondSideFixed) {
        secondSideFixed = true;
        return true;
    }
    return false;
}

bool Road::fixSide(int side, QPointF pos, qreal angle) {
    switch (side) {
    case 0:
        if (!firstSideFixed) {
            firstSideFixed = true;
            QTransform transform(getTransformMoveInDirection(length / 2, angle));
            transform.translate(pos.x(), pos.y());
            transform.rotate(angle);
            setTransform(transform);
            return true;
        }
        else return false;
    case 1:
        if (!secondSideFixed) {
            secondSideFixed = true;
            return true;
        }
    default:
        return false;
    }
}

bool Road::isFirstSideFixed() {
    return firstSideFixed;
}

bool Road::isSecondSideFixed() {
    return secondSideFixed;
}

QPointF Road::getFirstSidePoint() {
    return mapToScene(firstSidePoint);
}

QPointF Road::getSecondSidePoint() {
    return mapToScene(secondSidePoint);
}

QTransform Road::getTransformMoveInDirection(qreal distance, qreal angle) {
    // Преобразуем угол из градусов в радианы
    qreal radians = angle * M_PI / 180.0;

    // Вычисляем смещение по осям x и y
    qreal deltaX = distance * std::cos(radians);
    qreal deltaY = distance * std::sin(radians);

    QTransform transform;
    transform.translate(deltaX, deltaY);
    return transform;
}