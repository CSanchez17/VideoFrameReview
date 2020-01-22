#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <QObject>
#include <QVector>
#include <QStringList>

#include "threadgetframes.h"
#include "framemodel.h"

using namespace std;
using namespace cv;

class ModelManager : public QObject
{
    Q_OBJECT
public:
    explicit ModelManager(QObject *parent = nullptr);

    static QVector<QPixmap> m_frameGalerie;
    static QList<QObject *> m_frameModel;

    Q_INVOKABLE void populateList();

signals:
    void newFrameAdded(QString frameIndex);

public slots:
    void addFrameToModel(FrameModel* obj, QPixmap qpixmap);

private:
    ThreadGetFrames *m_tGetFrames;

};

#endif // MODELMANAGER_H
