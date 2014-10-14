#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QtQml>
#include "kinectcamera.h"
#include <QtQuick/QQuickView>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<KinectCamera>("KinectCamera",1,0,"KinectCamera");
    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/kinecttest/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
