#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "filesystemmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    FileSystemModel fileSystemModel;

    fileSystemModel.setRootPath();

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();

    context->setContextProperty("fileSystemModel", &fileSystemModel);

    const QUrl url(QStringLiteral("/Users/kmr/QtAcademyCourse/Day6AppAlpha/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

