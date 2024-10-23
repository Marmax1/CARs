#include "MapScene.h"


MapScene::MapScene(QObject* parent)
	: QGraphicsScene(parent) {

}

MapScene::MapScene(qreal x, qreal y, qreal width, qreal height, QObject* parent)
	: QGraphicsScene(x, y, width, height, parent) {
}

bool MapScene::saveToFile() {
	return false;
}