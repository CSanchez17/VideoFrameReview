#include "framemodel.h"

FrameModel::FrameModel(QObject *parent) : QObject(parent)
{

}

FrameModel::FrameModel(QString id, QString pos, QPixmap qpixmap)
{
    m_frameIndex = id;
    m_framePosition = pos;
    m_framePixmap = qpixmap;
}

QString FrameModel::getFrameIndex() const
{
    return m_frameIndex;
}

void FrameModel::setFrameIndex(const QString &value)
{
    m_frameIndex = value;
}

QString FrameModel::getFramePosition() const
{
    return m_framePosition;
}

void FrameModel::setFramePosition(const QString &value)
{
    m_framePosition = value;
}


QPixmap FrameModel::getFramePixmap() const
{
    return m_framePixmap;
}

void FrameModel::setFramePixmap(const QPixmap &framePixmap)
{
    m_framePixmap = framePixmap;
}
