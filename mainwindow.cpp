#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

MainWindow::MainWindow(const QUrl &url, bool debug, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),m_url(url), m_debug(debug)
{
    ui->setupUi(this);
    if (m_debug)
        qDebug() << "WebSocket server:" << url;
    connect(&m_webSocket, &QWebSocket::connected, this, &MainWindow::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &MainWindow::closed);
    m_webSocket.open(QUrl(url));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnected()
{
    if (m_debug)
        qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &MainWindow::onTextMessageReceived);
    m_webSocket.sendTextMessage(QStringLiteral("Hello! Send from Client!"));


    connect(&m_webSocket, &QWebSocket::binaryMessageReceived,
            this, &MainWindow::onBinaryMessageReceived);
//    m_webSocket.sendBinaryMessage(QByteArrayLiteral(2));
}

void MainWindow::onTextMessageReceived(QString message)
{
    if (m_debug)
        qDebug() << "Message received1:" << message;
    ui->label_1->setText(message);
//    qDebug() << "Message received2:" << message;
//    m_webSocket.open(QUrl(QStringLiteral("ws://192.168.50.127:1234")));
    m_webSocket.sendTextMessage(QStringLiteral("Hello! Send from Client!"));

//    m_webSocket.close();
}

void MainWindow::onBinaryMessageReceived(QByteArray message)
{
    if (m_debug)
        qDebug() << "Binary Message received1:" << message;
    ui->label_2->setText(message);
//    qDebug() << "Binary Message received2:" << message;
//    m_webSocket.open(QUrl(QStringLiteral("ws://192.168.50.127:1234")));
    m_webSocket.close();
}
