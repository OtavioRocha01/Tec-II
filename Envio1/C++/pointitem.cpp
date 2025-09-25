#include "pointitem.h"
#include "globals.h"

#include <QDateTime>

PointItem::PointItem(qreal x, qreal y, qreal w, qreal h, qreal dx, qreal dy)
    : QGraphicsEllipseItem(x, y, w, h)
{
    if ( dx == 0 && dy == 0 ) {
        this->dx = (rand()%3) - 1;
        this->dy = (rand()%3) - 1;
    } else {
        this->dx = dx;
        this->dy = dy;
    }
    setBrush(Qt::red);
    setPen(QPen(Qt::black));
    setAcceptHoverEvents(true);
}

void PointItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    setBrush(Qt::green);
    QGraphicsEllipseItem::hoverEnterEvent(event);
}

void PointItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    setBrush(Qt::red);
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

bool PointItem::hitBorder(PointItem* p, const QRectF &sceneRect){
    QRectF r = p->rect();
    QPointF pos = p->pos();
    if (pos.x() <= sceneRect.left() || pos.x() + r.width() >= sceneRect.right())
        return true;
    if (pos.y() <= sceneRect.top() || pos.y() + r.height() >= sceneRect.bottom())
        return true;
    return false;
}

void PointItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF pos = event->scenePos();
    qint64 t = QDateTime::currentMSecsSinceEpoch() - g_startTime;
    *g_logStream << t << ",click," << pos.x() << "," << pos.y() << ",ponto,ID=" << this << "\n";

    setBrush(Qt::green); // efeito visual
    QGraphicsEllipseItem::mousePressEvent(event);
}
