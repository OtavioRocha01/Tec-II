#ifndef LINEITEM_H
#define LINEITEM_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneHoverEvent>
#include <QPen>

class LineItem : public QGraphicsLineItem {
public:
    qreal dx;
    qreal dy;

    explicit LineItem(const QLineF &line, qreal dx, qreal dy);
    bool hitBorder(LineItem* l, const QRectF &sceneRect);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // LINEITEM_H
