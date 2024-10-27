#include "Lane.h"

Lane::Lane(const QPainterPath& path, qreal laneWidth, QGraphicsItem* parent){
	setParentItem(parent);
	setPath(path);
    this->laneWidth = laneWidth;
}

QPainterPath Lane::shape() const {
    QPainterPathStroker stroker;
    stroker.setWidth(laneWidth / 2);
    stroker.setCapStyle(Qt::FlatCap);
    return stroker.createStroke(path());
}

QRectF Lane::boundingRect() const {
    QRectF rect = path().boundingRect();
    rect.adjust(-laneWidth / 2, -laneWidth / 2, laneWidth / 2, laneWidth / 2);
    return rect;
}

void Lane::paint(QPainter* painter, QStyleOptionGraphicsItem* option, QWidget* widget) {
    return;
}

void Lane::changeStartPos(QPointF pos) {
    QPainterPath* newPath = new QPainterPath(pos);
    newPath->lineTo(mapToScene(path().currentPosition()));
    setPath(*newPath);
}


void Lane::changeEndPos(QPointF pos) {
    QPainterPath* newPath = new QPainterPath(QPointF(0, 0));
    newPath->lineTo(pos);
    setPath(*newPath);
}