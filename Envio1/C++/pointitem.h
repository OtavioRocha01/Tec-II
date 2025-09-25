#ifndef POINTITEM_H
#define POINTITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneHoverEvent>
#include <QBrush>
#include <QPen>

class PointItem : public QGraphicsEllipseItem {
public:
    qreal dx;
    qreal dy;
    PointItem(qreal x, qreal y, qreal w, qreal h, qreal dx, qreal dy);
    bool hitBorder(PointItem* p, const QRectF &sceneRect);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // POINTITEM_H
