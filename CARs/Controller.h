#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MapScene.h"
#include "RoadNetwork.h"

class Controller
{
public:
	Controller(MapScene* scene, RoadNetwork* city);

private:
	MapScene* scene;
	RoadNetwork* city;
};

#endif
