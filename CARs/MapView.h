#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MapView : public QGraphicsView {
    Q_OBJECT
    
public:
    MapView(QWidget* parent = nullptr);

private slots:
    void updateScene();

protected:
    void drawForeground(QPainter* painter, const QRectF& rect) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
private:
    QGraphicsScene* scene;
    QTimer* timer;
};

#endif