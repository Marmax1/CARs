#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>

class Car : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
    Car(qreal maxSpeed, const QString fileName);
	void setPath(const QList<QPointF>& path);

public:
	qreal getSpeed();
	qreal getMaxSpeed();
	void advancePosition();
	void calculateAcseleration();

public slots:
	void advance(int phase) Q_DECL_OVERRIDE;

private:
	void acselerate();

	qreal speed;
	qreal rotationSpeed;
	qreal acseleration;
	qreal maxSpeed;

	QList<QPointF> path;
	int currentDestinationPointIndex;
};

#endif

