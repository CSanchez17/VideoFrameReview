#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include <QDebug>

#include <QObject>

#include "cvclass.h"
#include "modelmanager.h"
#include "frameprovider.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);    
    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();

    FrameProvider myimageProvider;

    context->setContextProperty("modelManager",
                                &myimageProvider.m_modelManager);


    context->setContextProperty("myModel",
        QVariant::fromValue(myimageProvider.m_modelManager.m_frameModel));

    engine.addImageProvider(QLatin1String("MyImageProvider"), &myimageProvider);

    engine.addImportPath("qrc:/");
    engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

    return app.exec();
}
