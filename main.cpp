#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QFile"
#include "QDir"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    // engine.loadFromModule("TestBed", "Main");
    qDebug() << "Resources in root:" << QDir(":/").entryList(QDir::AllEntries);
    qDebug() << "Checking resource:" << QFile::exists("qrc:/SampleTest.qml");
    // QPdfWriter writer(url.toLocalFile());

    QUrl url(QStringLiteral("qrc:/SampleTest.qml"));
    engine.load(url);

    // engine.load("./Main.qml");

    return app.exec();
}
