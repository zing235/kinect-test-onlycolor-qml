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
openni::VideoFrameRef  mDepthFrame;
openni::VideoStream mDepthStream;
openni::Device mDevice;
QImage KinectDepthImage;
QImage KinectColorImage;
static bool fig =0;//设置fig来判断设备是否打开
KinectCamera::KinectCamera(QQuickItem *parent)
    : QQuickPaintedItem(parent),m_streamsource("color")
{
}

void KinectCamera::startcamera(void)
{
    openni::OpenNI::initialize();//初始化
    mDevice.open( openni::ANY_DEVICE );//打开设备（已在全局变量中声明设备mDevice）
    mColorStream.create( mDevice, openni::SENSOR_COLOR );// 创建数据流
    mColorStream.start();//开启数据流
    mDepthStream.create( mDevice, openni::SENSOR_DEPTH );// 创建数据流
    mDepthStream.start();//开启数据流
    fig=1;
}

void KinectCamera::closecamera(void)
{
    mColorStream.destroy();
    mDepthStream.destroy();
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
          if(m_streamsource=="depth")
           {
              int iMaxDepth = mDepthStream.getMaxPixelValue();
              mDepthStream.readFrame( &mDepthFrame );
              const cv::Mat mImageDepth(
                          mDepthFrame.getHeight(), mDepthFrame.getWidth(),
                          CV_16UC1, (void*)mDepthFrame.getData() );
              cv::Mat mScaledDepth;
              mImageDepth.convertTo( mScaledDepth, CV_8U, 255.0 / iMaxDepth );
              QVector<QRgb>  colorTable;
              for(int k=0;k<256;++k)
              {
                  colorTable.push_back( qRgb(k,k,k) );
              }
              KinectDepthImage= QImage((const unsigned char*)mScaledDepth.data,mDepthFrame.getWidth(), mDepthFrame.getHeight(),QImage::Format_Indexed8);
              KinectDepthImage.setColorTable(colorTable);
              painter->drawImage(boundingRect().adjusted(1, 1, -1, -1),KinectDepthImage);
          }
          else
          {
              mColorStream.readFrame( &mColorFrame );
              KinectColorImage= QImage((const unsigned char*)mColorFrame.getData(),mColorFrame.getWidth(), mColorFrame.getHeight(),QImage::Format_RGB888);
              painter->drawImage(boundingRect().adjusted(1, 1, -1, -1),KinectColorImage);
          }
    }
    else//如果设备以打开，直接执行
    {
        if(m_streamsource=="depth")
        {
            int iMaxDepth = mDepthStream.getMaxPixelValue();
            mDepthStream.readFrame( &mDepthFrame );
            const cv::Mat mImageDepth(
                        mDepthFrame.getHeight(), mDepthFrame.getWidth(),
                        CV_16UC1, (void*)mDepthFrame.getData() );
            cv::Mat mScaledDepth;
            mImageDepth.convertTo( mScaledDepth, CV_8U, 255.0 / iMaxDepth );
            QVector<QRgb>  colorTable;
            for(int k=0;k<256;++k)
            {
                colorTable.push_back( qRgb(k,k,k) );
            }
            KinectDepthImage= QImage((const unsigned char*)mScaledDepth.data,mDepthFrame.getWidth(), mDepthFrame.getHeight(),QImage::Format_Indexed8);
            KinectDepthImage.setColorTable(colorTable);
            painter->drawImage(boundingRect().adjusted(1, 1, -1, -1),KinectDepthImage);
        }
        else
        {
            mColorStream.readFrame( &mColorFrame );
            KinectColorImage= QImage((const unsigned char*)mColorFrame.getData(),mColorFrame.getWidth(), mColorFrame.getHeight(),QImage::Format_RGB888);
            painter->drawImage(boundingRect().adjusted(1, 1, -1, -1),KinectColorImage);
        }

    }
}

QString KinectCamera::getstreamsource(void) const
{
    return m_streamsource;
}
void KinectCamera::setstreamsource(const QString streamsource)
{
   m_streamsource=streamsource;
   emit streamsourceChanged();
}

