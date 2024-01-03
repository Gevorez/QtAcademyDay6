#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FileSystemModel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<FileSystemModel>("FileSystemModel", 1, 0, "FileSystemModel");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("/Users/kmr/QtAcademyCourse/Day6AppAlpha/Main.qml"));
    engine.load(url);

    return app.exec();
}
