#include "Car.h"

Car::Car(qreal maxSpeed, const QString fileName) : QGraphicsPixmapItem(QPixmap(fileName)), maxSpeed(maxSpeed/ 60) {
	speed = 0.1;
	rotationSpeed = 1;
	acseleration = 0.05;
	currentDestinationPointIndex = 0;
	path = QList<QPointF>();

	setFlag(ItemIsFocusable);
	setScale(0.1);
}

void Car::setPath(const QList<QPointF>& path) {
	this->path = path;
	currentDestinationPointIndex = 0;
}

qreal Car::getSpeed() {
	return speed;
}

qreal Car::getMaxSpeed() {
	return maxSpeed;
}

void Car::advance(int phase) {
	if (phase) {
		if (currentDestinationPointIndex < path.size()) {
			QPointF destination = path.at(currentDestinationPointIndex);
			QLineF lineToDestination(pos(), destination);

			if (lineToDestination.length() < speed) {
				currentDestinationPointIndex++;
				if (currentDestinationPointIndex == path.size()) {
					return;
				}
				destination = path.at(currentDestinationPointIndex);
				lineToDestination = QLineF(pos(), destination);
			}

			double theta = lineToDestination.angle();
			setRotation(-theta);

			acselerate();
			double dy = speed * qSin(qDegreesToRadians(theta));
			double dx = speed * qCos(qDegreesToRadians(theta));
			setPos(x() + dx, y() - dy);
		}
		else {
			//this->deleteLater();
			acseleration = 0;
			speed = 0;
			rotationSpeed = 0;
		}
	}
}

void Car::acselerate() {
	speed += acseleration;
	if (speed > maxSpeed) {
		speed = maxSpeed;
	}
	else if (speed < 0) {
		speed = 0;
	}
}