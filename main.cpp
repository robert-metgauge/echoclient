#include "mainwindow.h"
#include <QApplication>
#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    QCommandLineParser parser;
//    parser.setApplicationDescription("QtWebSockets example: echoclient");
//    parser.addHelpOption();

//    QCommandLineOption dbgOption(QStringList() << "d" << "debug",
//            QCoreApplication::translate("main", "Debug output [default: off]."));
//    parser.addOption(dbgOption);
//    parser.process(a);
//    bool debug = parser.isSet(dbgOption);
    bool debug = true;

//    MainWindow client(QUrl(QStringLiteral("ws://localhost:1234")), debug);
    MainWindow client(QUrl(QStringLiteral("ws://192.168.50.127:1234")), debug);
    client.show();

//    QObject::connect(&client, &MainWindow::closed, &a, &QCoreApplication::quit);

    return a.exec();
}
