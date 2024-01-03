#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FileSystemModel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<FileSystemModel>("FileSystemModel", 1, 0, "FileSystemModel");

    QQmlApplicationEngine engine;
    engine.load((QUrl("qrc:/Day6AppAlpha/Main.qml")));

    return app.exec();
}
