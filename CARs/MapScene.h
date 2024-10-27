#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "Car.h"
#include "Path.h"
#include "Road.h"
#include "Intersection.h"
#include "GenPoint.h"

class MapScene : public QGraphicsScene {
    Q_OBJECT
        
public:
    MapScene(QObject* parent = nullptr);
    MapScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);

    bool saveToFile();

private slots:
    void onTimer();
};

#endif