#include "frameprovider.h"

#include <QPixmap>
#include <QDebug>


FrameProvider::FrameProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap FrameProvider::requestPixmap(const QString &id, QSize *size,
                                       const QSize &requestedSize)
{
    //qDebug() <<"MyImageProvider: m_modelManager.m_frameGalerie.size: "<<m_modelManager.m_frameGalerie.size();
    QStringList ids = id.split("/");
    int index = ids[0].toInt();

    if (m_modelManager.m_frameGalerie.size() > 0 && index >= 0){
        return m_modelManager.m_frameGalerie[index];
    }

    return QPixmap();   //return a null pixmap
}
