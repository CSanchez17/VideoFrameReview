#include "modelmanager.h"

#include <QDebug>
#include <QDir>


ModelManager::ModelManager(QObject *parent):
    QObject(parent)
{
    populateList();
}

void ModelManager::populateList()
{
    m_tGetFrames = new ThreadGetFrames(this);

    connect(m_tGetFrames, &ThreadGetFrames::newFrame,
         [&](QString frameIndex, FrameModel* obj, QPixmap qpixmap){

         //qDebug() << "New frameIndex: " << frameIndex;
         this->m_frameModel.append(obj);
         this->m_frameGalerie.append(qpixmap);

         emit newFrameAdded(frameIndex);
    });

    std::string path("C:\\Users\\Home\\Videos\\Sony.mp4");
    m_tGetFrames->getFramesOfVideo(path);
}

void ModelManager::addFrameToModel(FrameModel *obj, QPixmap qpixmap)
{

}

QVector<QPixmap> ModelManager::m_frameGalerie;
QList<QObject *> ModelManager::m_frameModel;
