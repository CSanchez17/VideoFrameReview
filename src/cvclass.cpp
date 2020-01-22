#include "cvclass.h"
#include <QDebug>
#include <QDir>
#include <QStringList>
#include <QVector>

#include "opencv2/opencv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

CvClass::CvClass(QObject *parent):
    QObject(parent)
{

    qDebug() << "OpenCV version : " << CV_VERSION;
    qDebug() << "Major version : " << CV_MAJOR_VERSION;
    qDebug() << "Minor version : " << CV_MINOR_VERSION;
    qDebug() << "Subminor version : " << CV_SUBMINOR_VERSION;

    m_cv1 = QString::fromStdString(CV_VERSION);
    m_cv2 = QString::number(CV_MAJOR_VERSION);
    m_cv3 = QString::number(CV_MINOR_VERSION);
    m_cv4 = QString::number(CV_SUBMINOR_VERSION);

}


QString CvClass::getcv1() const
{
    return m_cv1;
}

void CvClass::setCv1(const QString &cv1)
{
    m_cv1 = cv1;
}

QString CvClass::getcv2() const
{
    return m_cv2;
}

void CvClass::setCv2(const QString &cv2)
{
    m_cv2 = cv2;
}

QString CvClass::getcv3() const
{
    return m_cv3;
}

void CvClass::setCv3(const QString &cv3)
{
    m_cv3 = cv3;
}

QString CvClass::getcv4() const
{
    return m_cv4;
}

void CvClass::setCv4(const QString &cv4)
{
    m_cv4 = cv4;
}
