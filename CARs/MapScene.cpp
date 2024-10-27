#include "MapScene.h"
#include <iostream>

MapScene::MapScene(QObject* parent)
	: QGraphicsScene(parent) {

}

MapScene::MapScene(qreal x, qreal y, qreal width, qreal height, QObject* parent)
	: QGraphicsScene(x, y, width, height, parent) {

    setBackgroundBrush(Qt::darkGreen);

    Road* road1 = new Road(20, 2, 2);
    //road1->setScale(5);
    /*Road* road2 = new Road(20, 2, 2);
    road2->setScale(5);
    Road* road3 = new Road(20, 2, 2);
    road3->setScale(5);
    Road* road4 = new Road(20, 2, 2);
    road4->setScale(5);*/

    Intersection* intersection = Intersection::getSimlpeIntersection4();
    
    intersection->setPos(width / 2, height / 2);

    intersection->addRoad(road1);
    //intersection->addRoad(road2);
    //intersection->addRoad(road3);
    //intersection->addRoad(road4);

    /*QPointF ps = intersection->pos();

    GenPoint* gn1 = new GenPoint(QPointF(width / 2, -50), -90);
    GenPoint* gn2 = new GenPoint(QPointF(height / 2, width + 50), 180);
    GenPoint* gn3 = new GenPoint(QPointF(width / 2, height + 50), 90);
    GenPoint* gn4 = new GenPoint(QPointF(height / 2, -50), 0);

    gn1->addRoad(road1);
    gn2->addRoad(road2);
    gn3->addRoad(road3);
    gn4->addRoad(road4);*/

    GenPoint* gn1 = new GenPoint(QPointF(width / 2, -50), 90);

    gn1->connectToRoad(road1);

    addItem(gn1);

    addItem(road1);
    //addItem(road2);
    //addItem(road3);
    //addItem(road4);
    addItem(intersection);
    /*
    addItem(gn1);
    addItem(gn2);
    addItem(gn3);
    addItem(gn4);*/
    addEllipse(sceneRect());

    /*MyWidget* wid = new MyWidget(path);
    wid->show();*/

    //adding car
    Car* car1 = new Car(60, "Asset 1.png");
    car1->setFocus();
    car1->setPos(100, 100);
    QPainterPath* path = new QPainterPath(Path::turnToPoint(car1->pos(), car1->rotation(), QPointF(300, 300), car1->rotation() + 90));
    QList<QPointF> points;
    for (double t = 0.0; t < 1.0;) {
        t += qMax(qAbs(0.5 - t) / 3, 0.01);
        points << path->pointAtPercent(t);
    }
    if (points.back() == QPointF(0, 0)) {
        points.removeLast();
    }
    points << QPointF(300, 350) << QPointF(320, 400);
    car1->setPath(points);

    addItem(car1);

    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(1 / 60);
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