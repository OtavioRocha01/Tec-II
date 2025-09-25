#ifndef MYSCENE_H
#define MYSCENE_H

#include "qgraphicsscene.h"


class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    using QGraphicsScene::QGraphicsScene;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYSCENE_H
