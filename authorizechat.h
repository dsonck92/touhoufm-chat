#ifndef AUTHORIZECHAT_H
#define AUTHORIZECHAT_H

#include <QDialog>
#include <QUrl>

namespace Ui {
class AuthorizeChat;
}

class AuthorizeChat : public QDialog
{
    Q_OBJECT

    QString key;

public:
    explicit AuthorizeChat(QWidget *parent = 0);
    ~AuthorizeChat();

    QString authKey(){return key;}

private:
    Ui::AuthorizeChat *ui;

private slots:
    void trackUrl(QUrl url);
    void loadFinished();
};

#endif // AUTHORIZECHAT_H
