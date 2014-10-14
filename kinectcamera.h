#ifndef KINECTCAMERA_H
#define KINECTCAMERA_H
#include <QPainter>
#include <QtQuick/QQuickPaintedItem>

class KinectCamera : public QQuickPaintedItem
{
    Q_OBJECT

public:
    KinectCamera(QQuickItem *parent = 0);
    Q_INVOKABLE void startcamera();
    Q_INVOKABLE void updatecamera();
    Q_INVOKABLE void closecamera();

    void paint(QPainter *painter);



};
#endif // KINECTCAMERA_H
