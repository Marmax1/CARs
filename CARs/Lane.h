#ifndef LANE_H
#define LANE_H

#include <QGraphicsPathItem>

class Lane : public QGraphicsPathItem {
public:
    Lane(const QPainterPath& path, qreal laneWidth, QGraphicsItem* parent = nullptr);

    QPainterPath shape() const override;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

    void changeStartPos(QPointF pos);
    void changeEndPos(QPointF pos);
private:
    qreal laneWidth;
};

#endif // LANE_H