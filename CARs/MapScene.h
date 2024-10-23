#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>

class MapScene : public QGraphicsScene {
    Q_OBJECT
        
public:
    MapScene(QObject* parent = nullptr);
    MapScene(qreal x, qreal y, qreal width, qreal height, QObject* parent = nullptr);

    bool saveToFile();
};

#endif