#ifndef CVCLASS_H
#define CVCLASS_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "opencv2/opencv.hpp"
#include <iostream>
#include <QVector>
#include <QPixmap>
#include <QQmlContext>


#include "threadgetframes.h"
#include "framemodel.h"

using namespace std;
using namespace cv;

class CvClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString _cv1 READ getcv1 WRITE setCv1 CONSTANT)
    Q_PROPERTY(QString _cv2 READ getcv2 WRITE setCv2 CONSTANT)
    Q_PROPERTY(QString _cv3 READ getcv3 WRITE setCv3 CONSTANT)
    Q_PROPERTY(QString _cv4 READ getcv4 WRITE setCv4 CONSTANT)

    /*
     * If the property values can change, then QML needs a NOTIFY signal
     * so it can know when they have changed and update property bindings.
     * If they can't change, add CONSTANT to your property declaration, for example: oben!
    */

public:
    explicit CvClass(QObject *parent = nullptr);

    QString getcv1() const;
    void setCv1(const QString &cv1);

    QString getcv2() const;
    void setCv2(const QString &cv2);

    QString getcv3() const;
    void setCv3(const QString &cv3);

    QString getcv4() const;
    void setCv4(const QString &cv4);


signals:
    void newFrameAdded(FrameModel* obj, QPixmap qpixmap);

private:


    QString m_cv1;
    QString m_cv2;
    QString m_cv3;
    QString m_cv4;
};

#endif // CVCLASS_H
