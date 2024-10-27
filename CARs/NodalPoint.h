#ifndef NODALPOINT_H
#define NODALPOINT_H

#include <QGraphicsItem>
#include "Road.h"

class NodalPoint : public QGraphicsItem
{
public:
	virtual void addRoad(Road* road) = 0;
	virtual Road* getRoad(int index) = 0;
};

#endif

