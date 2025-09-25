#include "lineitem.h"
#include "globals.h"

#include <QDateTime>

LineItem::LineItem(const QLineF &line, qreal dx, qreal dy)
    : QGraphicsLineItem(line)
{
    if ( dx == 0 && dy == 0 ) {
        this->dx = (rand()%3) - 1;
        this->dy = (rand()%3) - 1;
    } else {
        this->dx = dx;
        this->dy = dy;
    }
    setPen(QPen(Qt::blue, 4));
    setAcceptHoverEvents(true);
}

void LineItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    setPen(QPen(Qt::green, 6));
    QGraphicsLineItem::hoverEnterEvent(event);
}

void LineItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    setPen(QPen(Qt::blue, 4));
    QGraphicsLineItem::hoverLeaveEvent(event);
}

bool LineItem::hitBorder(LineItem* l, const QRectF &sceneRect) {
    QLineF line = l->line();
    if (!sceneRect.contains(line.p1()) || !sceneRect.contains(line.p2()))
        return true;
    return false;
}

void LineItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF pos = event->scenePos();
    qint64 t = QDateTime::currentMSecsSinceEpoch() - g_startTime;
    *g_logStream << t << ",click,"
                 << pos.x() << "," << pos.y()
                 << ",linha,P1=("
                 << line().p1().x() << "." << line().p1().y() << ") "
                 << "P2=("
                 << line().p2().x() << "." << line().p2().y() << ")"
                 << "\n";

    setPen(QPen(Qt::red,2));
    QGraphicsLineItem::mousePressEvent(event);
}
