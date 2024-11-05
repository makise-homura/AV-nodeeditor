#pragma once

#include <utility>

#include <QtCore/QUuid>
#include <QtWidgets/QGraphicsObject>

#include "ConnectionState.hpp"
#include "Definitions.hpp"
#include "qobjectdefs.h"

class QGraphicsSceneMouseEvent;

namespace QtNodes {

class AbstractGraphModel;
class BasicGraphicsScene;

/// Graphic Object for connection. Adds itself to scene
class ConnectionGraphicsObject : public QGraphicsObject
{
    Q_OBJECT
public:
    // Needed for qgraphicsitem_cast
    enum { Type = UserType + 2 };

    int type() const override { return Type; }

public:
    ConnectionGraphicsObject(BasicGraphicsScene &scene, ConnectionId const connectionId);

    ~ConnectionGraphicsObject() = default;

public:
    AbstractGraphModel &graphModel() const;

    BasicGraphicsScene *nodeScene() const;

    ConnectionId const &connectionId() const;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    QPointF const &endPoint(PortType portType) const;

    QPointF out() const { return _out; }

    QPointF in() const { return _in; }

    std::pair<QPointF, QPointF> pointsC1C2() const;

    void setEndPoint(PortType portType, QPointF const &point);

    /// Updates the position of both ends
    void move();

    ConnectionState const &connectionState() const;

    ConnectionState &connectionState();

    // Метод для установки цвета соединения
        void setConnectionColor(const QColor& color) { connectionColor = color; }
        QColor getConnectionColor() const { return connectionColor; }

Q_SIGNALS:
    void doubleClicked(); // Сигнал двойного клика

    void positionChanged();

protected:
    void paint(QPainter *painter,
               QStyleOptionGraphicsItem const *option,
               QWidget *widget = 0) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    // Переопределение метода для двойного клика
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override {
        Q_EMIT doubleClicked(); // Генерируем сигнал
        QGraphicsObject::mouseDoubleClickEvent(event); // Вызываем базовую реализацию
    }

private:
    void initializePosition();

    void addGraphicsEffect();

    std::pair<QPointF, QPointF> pointsC1C2Horizontal() const;

    std::pair<QPointF, QPointF> pointsC1C2Vertical() const;

private:
    ConnectionId _connectionId;

    AbstractGraphModel &_graphModel;

    ConnectionState _connectionState;

    mutable QPointF _out;
    mutable QPointF _in;

    QColor connectionColor;
};

} // namespace QtNodes
