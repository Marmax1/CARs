#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QMouseEvent>
#include <QList>
#include "MapView.h"

MapView::MapView(QWidget* parent)
    : QGraphicsView(parent) {
    scene = new QGraphicsScene(0, 0, 1000, 600);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    scene->setBackgroundBrush(Qt::white);

    QGraphicsRectItem* item = new QGraphicsRectItem(0, 0, 100, 100);
    item->setBrush(QBrush(QColor(255, 0, 0)));
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();

    scene->addItem(item);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateScene()));
    timer->start(1);

    this->setGeometry(200, 100, 800, 500);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MapView::updateScene() {

    if (scene->items().count() < 200) {
        QGraphicsEllipseItem* ellips = new QGraphicsEllipseItem(0, 0, 20, 20);
        ellips->setBrush(QBrush(QColor(QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256)));
        ellips->setFlag(QGraphicsItem::ItemIsFocusable);
        ellips->setPos(QRandomGenerator::global()->bounded(0, (qint32)scene->sceneRect().width()), QRandomGenerator::global()->bounded(0, (qint32)scene->sceneRect().height()));
        scene->addItem(ellips);
    }

    for (auto& item : scene->items()) {
        if (!item->hasFocus()) {
            item->setPos(item->pos() + QPointF(QRandomGenerator::global()->bounded(-3, 4), QRandomGenerator::global()->bounded(-3, 4)));
            continue;
        }
        item->setPos(item->pos() + QPointF(0.1, 0));
    }
}

void MapView::drawForeground(QPainter* painter, const QRectF& rect) {
    QRectF sceneRect = this->sceneRect();
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
        sceneRect.width() - 4, sceneRect.height() - 4);
    QString message;
    message.setNum(this->scene->items().count());
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

    if (scene) {
        QList< QGraphicsItem* > items = scene->items(clickPos);
        if (!items.isEmpty()) {
            delete items[0];
        }
    }

    QGraphicsView::mouseDoubleClickEvent(event);
}