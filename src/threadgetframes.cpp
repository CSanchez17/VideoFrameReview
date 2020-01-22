#include "threadgetframes.h"

#include <chrono>
#include <QPixmap>
#include <QDebug>

using namespace cv;
using namespace std;

ThreadGetFrames::ThreadGetFrames(QObject *parent) : QThread(parent)
{
}

int ThreadGetFrames::getFramesOfVideo(std::string &path)
{
    this->m_videoPath = QString::fromStdString(path);
    this->m_capture = VideoCapture(path);

    // Check if camera opened successfully
    if(!this->m_capture.isOpened()){
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    // tun thread
    this->start(QThread::HighestPriority);

    return 0;
}

void ThreadGetFrames::run()
{

    chrono::steady_clock sc;
    auto start = sc.now();

    int i = 0;
    auto counter = i;
    while(1){

        Mat srcFrame, resFrame;
        // Capture frame-by-frame
        this->m_capture >> srcFrame;

        // If the frame is empty, break immediately
        if (srcFrame.empty())
            break;

        if (i % m_frameStep == 0){
            cv::Size videoSize = cv::Size ((int) 140, (int) 100);
            cv::resize(srcFrame,resFrame, videoSize);

            QImage qimage;
            qImageFromCvImage(resFrame, qimage);
            QPixmap qpixmap = QPixmap::fromImage(qimage, Qt::ColorOnly);

            QString pos(QString::number(m_capture.get(CAP_PROP_POS_MSEC)));

            FrameModel* frameObject = new FrameModel(QString::number(counter), pos, qpixmap);

            emit newFrame(QString::number(counter),
                          frameObject,
                          qpixmap);

            counter++;
                // Test: save images as file
                //    QDir dir;
                //    QString name(dir.absolutePath() +"/images/Image_" + QString::number(i) + ".jpg");
                //    imwrite( name.toStdString().c_str(), resFrame );   //to cv string
        }
        i++;
    }

    auto end = sc.now();
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "time: "<<time_span.count() <<" seconds"<<std::endl;
    qDebug() << "Number of frames: " << m_capture.get(CAP_PROP_FRAME_COUNT);

    //qDebug() << "last position = duration? [ms]: " << m_capture.get(CAP_PROP_POS_MSEC);
    double fps = m_capture.get(CAP_PROP_FPS);
    qDebug() << "fps: " << fps;


    m_capture.release();
}

void ThreadGetFrames::qImageFromCvImage(const cv::Mat& cvImage, QImage& qImage){

    qImage = QImage(cvImage.cols,cvImage.rows,QImage::Format_RGB888);       //Format_RGB888 compatibel with CV_8UC3
    for( int r = 0; r < cvImage.rows; ++r)
    {
        for ( int c = 0; c < cvImage.cols; ++c)
        {
            //get cv pixelvalues
            Vec3b pixelColor = cvImage.at<cv::Vec3b>(r,c);

            // opencv has BGR, but qimage uses RGB
            QRgb value = qRgb(pixelColor[2], pixelColor[1], pixelColor[0]); /// RGBA Werte sollen hier angepasst werden
            qImage.setPixel(c, r, value);
        }
    }
}


