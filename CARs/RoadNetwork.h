#ifndef ROADNETWORK_H
#define ROADNETWORK_H
#include "MapScene.h"
#include "NodalPoint.h"

class RoadNetwork {
public:

    void addNodalPoint(NodalPoint* nodalPoint);
    void addRoad(NodalPoint* start, NodalPoint* end, Road* road);

    QList<NodalPoint> findShortestWay();
    QList<QGraphicsItem*> getItems();

private:
    std::map<NodalPoint*, std::map<NodalPoint*, Road*>> network;
};

#endif