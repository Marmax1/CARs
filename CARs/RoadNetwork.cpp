#include "RoadNetwork.h"

void RoadNetwork::addNodalPoint(NodalPoint* intersection) {
    network[intersection];
}

void RoadNetwork::addRoad(NodalPoint* start, NodalPoint* end, Road* road) {
    network[start][end] = road;
    start->addRoad(road);
    end->addRoad(road);
}

QList<QGraphicsItem*> RoadNetwork::getItems() {
    QList<QGraphicsItem*> items = QList<QGraphicsItem*>();
    for (auto& pair : network) {
        NodalPoint* nodeFrom = pair.first;
        items.push_back(nodeFrom);
        for (auto& pairTo : network[nodeFrom]) {
            items.push_back(pairTo.first);
            items.push_back(pairTo.second);
        }
    }
    return items;
}

