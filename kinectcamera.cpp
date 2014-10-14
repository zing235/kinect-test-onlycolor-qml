#include "kinectcamera.h"
#include <OpenNI.h>
#include <opencv2/opencv.hpp>
#include <QPainter>
#include <QImage>
#include <vector>
#include <stdio.h>
using namespace std;
using namespace cv;
openni::VideoFrameRef  mColorFrame;
openni::VideoStream mColorStream;
openni::Device mDevice;
QImage kinectframe;
static bool fig =0;//设置fig来判断设备是否打开
KinectCamera::KinectCamera(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void KinectCamera::startcamera(void)
{
    openni::OpenNI::initialize();//初始化
    mDevice.open( openni::ANY_DEVICE );//打开设备（已在全局变量中声明设备mDevice）
    mColorStream.create( mDevice, openni::SENSOR_COLOR );// 创建数据流
    mColorStream.start();//开启数据流
    fig=1;
}

void KinectCamera::closecamera(void)
{
    mColorStream.destroy();
    mDevice.close();
    openni:: OpenNI::shutdown();
}

void KinectCamera::updatecamera(void)
{
    update();
}

void KinectCamera::paint(QPainter *painter)
{

    if (!fig)//如果设备未打开，先执行startcamera
    {
        startcamera();
        mColorStream.readFrame( &mColorFrame );
        kinectframe= QImage((const unsigned char*)mColorFrame.getData(),mColorFrame.getWidth(), mColorFrame.getHeight(),QImage::Format_RGB888);
//        const QImage kinectframe((const unsigned char*)mColorFrame.getData(),mColorFrame.getWidth(), mColorFrame.getHeight(),QImage::Format_RGB888);
        painter->drawImage(boundingRect().adjusted(1, 1, -1, -1),kinectframe);
    }
    else//如果设备以打开，直接执行
    {
        mColorStream.readFrame( &mColorFrame );
        kinectframe= QImage((const unsigned char*)mColorFrame.getData(),mColorFrame.getWidth(), mColorFrame.getHeight(),QImage::Format_RGB888);
//        const QImage kinectframe((const unsigned char*)mColorFrame.getData(),mColorFrame.getWidth(), mColorFrame.getHeight(),QImage::Format_RGB888);
        painter->drawImage(boundingRect().adjusted(1, 1, -1, -1),kinectframe);
    }

}

