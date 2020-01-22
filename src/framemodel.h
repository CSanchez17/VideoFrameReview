#ifndef FRAMEMODEL_H
#define FRAMEMODEL_H

#include <QObject>
#include <QPixmap>

class FrameModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString _frameIndex READ getFrameIndex
               WRITE setFrameIndex NOTIFY changedFrameIndex)
    Q_PROPERTY(QString _framePosition READ getFramePosition
               WRITE setFramePosition NOTIFY changedFramePosition)
    Q_PROPERTY(QPixmap _framePixmamp READ getFramePixmap
               WRITE setFramePixmap NOTIFY changedFramePixmap)

public:
    //explicit: avoid implicite type conversion
    explicit FrameModel(QObject *parent = nullptr);
    explicit FrameModel(QString id, QString pos, QPixmap qpixmap);

    QString getFrameIndex() const;
    void setFrameIndex(const QString &value);

    QString getFramePosition() const;
    void setFramePosition(const QString &value);

    QPixmap getFramePixmap() const;
    void setFramePixmap(const QPixmap &framePixmap);


signals:

    void changedFrameIndex();
    void changedFramePosition();
    void changedFramePixmap();

private:
    QString m_frameIndex;
    QString m_framePosition;
    QPixmap m_framePixmap;
};

#endif // FRAMEMODEL_H
