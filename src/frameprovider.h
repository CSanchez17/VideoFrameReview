#ifndef FRAMEPROVIDER_H
#define FRAMEPROVIDER_H


#include <QQuickImageProvider>

#include <iostream>
#include <QObject>

#include "modelmanager.h"


using namespace std;
using namespace cv;

class FrameProvider : public QQuickImageProvider
{

public:
    FrameProvider();
    QPixmap requestPixmap(const QString &id, QSize *size,
                          const QSize &requestedSize) ; //override

    ModelManager m_modelManager;
private:


};

#endif // FRAMEPROVIDER_H
