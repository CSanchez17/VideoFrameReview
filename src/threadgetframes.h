#ifndef THREADGETFRAMES_H
#define THREADGETFRAMES_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QStringList>

#include "opencv2/opencv.hpp"
#include <iostream>

#include "framemodel.h"

class ThreadGetFrames : public QThread
{
    Q_OBJECT
public:
    explicit ThreadGetFrames(QObject *parent = nullptr);

    void qImageFromCvImage(const cv::Mat& cvImage, QImage& qImage);
    int getFramesOfVideo(std::string &path);

signals:
    void newFrame(QString indexOfFrame,
                  FrameModel* frameObject,
                  QPixmap qpixmap);

protected:
    void run();

private:
    QString m_videoPath;
    cv::VideoCapture m_capture;
    int m_frameStep = 50;
};

#endif // THREADGETFRAMES_H
