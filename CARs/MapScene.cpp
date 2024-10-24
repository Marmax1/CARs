#include "MapScene.h"


MapScene::MapScene(QObject* parent)
	: QGraphicsScene(parent) {

}

MapScene::MapScene(qreal x, qreal y, qreal width, qreal height, QObject* parent)
	: QGraphicsScene(x, y, width, height, parent) {

    setBackgroundBrush(Qt::gray);

    Car* car = new Car(60, "car.png");
    car->setFocus();
    car->setPos(100, 100);
    QPainterPath* path = new QPainterPath(Path::turnToPoint(car->pos(), car->rotation(), QPointF(300, 300), car->rotation() + 90));
    QList<QPointF> points;
    for (double t = 0.0; t < 1.0;) {
        t += qMax(qAbs(0.5 - t) / 3, 0.01);
        points << path->pointAtPercent(t);
    }
    if (points.back() == QPointF(0, 0)) {
        points.removeLast();
    }
    points << QPointF(300, 350) << QPointF(320, 400);
    car->setPath(points);

    /*MyWidget* wid = new MyWidget(path);
    wid->show();*/

    addItem(car);

    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    timer->start(1 / 60);
}

bool MapScene::saveToFile() {
	return false;
}

void MapScene::onTimer() {
    //Controller.processCollisions();
    advance();
}
/*if (scene->items().count() < 200) {
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
    }*/