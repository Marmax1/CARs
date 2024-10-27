#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MapView : public QGraphicsView {
    Q_OBJECT
    
public:
    MapView(QWidget* parent = nullptr);

protected:
    void drawForeground(QPainter* painter, const QRectF& rect) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

    qreal m_originX;
    qreal m_originY;
};

#endif