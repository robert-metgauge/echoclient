#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QUrl &url, bool debug = false, QWidget *parent = 0);
    ~MainWindow();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onConnected();
    void onTextMessageReceived(QString message);
    void onBinaryMessageReceived(QByteArray message);

private:
    Ui::MainWindow *ui;

    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
};

#endif // MAINWINDOW_H
