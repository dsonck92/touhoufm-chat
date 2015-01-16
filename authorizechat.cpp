#include "authorizechat.h"
#include "ui_authorizechat.h"

#include <QWebFrame>
#include <QMessageBox>

AuthorizeChat::AuthorizeChat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizeChat)
{
    ui->setupUi(this);
}

AuthorizeChat::~AuthorizeChat()
{
    delete ui;
}

void AuthorizeChat::trackUrl(QUrl url)
{
}

void AuthorizeChat::loadFinished()
{
    QUrl url = ui->webView->url();
    if(url.path().contains("authtoken.php"))
    {
        key = ui->webView->page()->currentFrame()->toPlainText();

        if(!key.isEmpty())
        {
            close();
        }
    }

    url = ui->webView->url();

   // QMessageBox::information(this,"URL",url.toString());

    if(url.path().contains("wp-login"))
        return;
    if(url.path().contains("authtoken"))
        return;

    ui->webView->stop();

    ui->webView->load(QUrl("http://touhou.fm/authtoken.php"));

}
