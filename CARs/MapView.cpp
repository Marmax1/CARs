#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QMouseEvent>
#include <QList>
#include <QOpenGLWidget>
#include <QPainter>
#include "MapView.h"
#include "MapScene.h"
#include "Car.h"
#include "Path.h"

/*
class MyWidget : public QWidget
{
public:
    MyWidget(QPainterPath* path) : QWidget() {
        pat = path;
    }

private:

    void paintEvent(QPaintEvent* event)
    {
        QPainter painter;
        painter.begin(this);
        painter.fillRect(0, 0, 100, 100, Qt::white);
        painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
            Qt::FlatCap, Qt::MiterJoin));
        painter.setBrush(QColor(122, 163, 39));
        painter.drawPath(*pat);
        painter.end();
    }

    QPainterPath* pat;
};*/

MapView::MapView(QWidget* parent) : QGraphicsView(parent) {
    MapScene* scene = new MapScene(0, 0, 1440, 800);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setViewport(new QOpenGLWidget());
    setGeometry(0, 0, 1440, 800);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setTransformationAnchor(QGraphicsView::NoAnchor);
}

void MapView::drawForeground(QPainter* painter, const QRectF& rect) {
    QGraphicsScene* scene = this->scene();
    QRectF sceneRect = rect;
    QRectF textRect(rect.left() + 4, rect.top() + 4,
        rect.width() - 4, rect.height() - 4);
    QString message;
    message.setNum(scene->items().count());
    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}

void MapView::mouseDoubleClickEvent(QMouseEvent* event) {
    QPointF clickPos = mapToScene(event->pos());

    qDebug() << "Double-clicked at:" << clickPos;

    if (this->scene()) {
        QList< QGraphicsItem* > items = this->scene()->items(clickPos);
        if (!items.isEmpty()) {
            delete items[0];
        }
    }

    QGraphicsView::mouseDoubleClickEvent(event);
}

void MapView::wheelEvent(QWheelEvent* event)
{
    // your functionality, for example:
    // if ctrl pressed, use original functionality
    if (event->modifiers() & Qt::ControlModifier)
    {
        QGraphicsView::wheelEvent(event);
    }
    // otherwise, do yours
    else
    {
        if (event->angleDelta().y() > 0)
        {
            scale(1.1, 1.1);
        }
        else
        {
            scale(0.9, 0.9);
        }
    }
}

void MapView::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        // Store original position.
        m_originX = event->pos().x();
        m_originY = event->pos().y();
    }
}

void MapView::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::RightButton)
    {
        QPointF oldP = mapToScene(m_originX, m_originY);
        QPointF newP = mapToScene(event->pos());
        QPointF translation = newP - oldP;

        translate(translation.x(), translation.y());

        m_originX = event->pos().x();
        m_originY = event->pos().y();
    }
}