#include <iostream>
#include <string>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "../include/middlemen.hpp"

int main(int argc, char *argv[]){

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QScopedPointer<Middlemen> middlemen(new Middlemen);
    QQmlApplicationEngine engine;

    app.setOrganizationName("European University of Lefke");
    app.setOrganizationDomain("http://www.eul.edu.tr/en/");
    app.setApplicationName("ImSteg");

    const QUrl url(QStringLiteral("qrc:/pages/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &obj_url){
        if(!obj && url == obj_url)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    engine.rootContext()->setContextProperty("middlemen", middlemen.data());

    return app.exec();
}