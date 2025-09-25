#include "myscene.h"
#include "globals.h"
#include "qgraphicssceneevent.h"
#include <QDateTime>

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos();
    qint64 t = QDateTime::currentMSecsSinceEpoch() - g_startTime;
    *g_logStream << t << ",move," << pos.x() << "," << pos.y() << ",nenhum,\n";

    QGraphicsScene::mouseMoveEvent(event);
}
