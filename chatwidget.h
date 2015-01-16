#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

    QTcpSocket *sock;

public:
    explicit ChatWidget(QWidget *parent = 0);
    ~ChatWidget();

private:
    Ui::ChatWidget *ui;

private slots:
    void readData();
    void sendMessage();
};

#endif // CHATWIDGET_H
