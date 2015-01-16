#include "chatwidget.h"
#include "ui_chatwidget.h"

#include <QInputDialog>
#include <QMessageBox>
#include "authorizechat.h"

ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);

    AuthorizeChat *ac = new AuthorizeChat(this);

    ac->exec();

    QString authkey = ac->authKey();

    while(authkey.isEmpty())
    {
        bool ok;
        authkey = QInputDialog::getText(this,"Authorization token","Please get your authorization token from <a href=\"http://touhou.fm/authtoken.php\">here</a>",QLineEdit::Normal,QString(),&ok);

        if(!ok)
        {
            ui->lblInfo->setText(QString("Warning, signin failed! Please restart the program."));
            close();
            return;
        }
    }

    ui->lblInfo->setText(QString("Signed in with %1").arg(authkey));

    sock = new QTcpSocket(this);

    sock->connectToHost("touhou.fm",9009);

    if(!sock->waitForConnected())
    {
        QMessageBox::critical(this,"Connection failed","The connection to the TouHou.FM server failed");
    }

    connect(sock,SIGNAL(readyRead()),SLOT(readData()));
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

void ChatWidget::readData()
{
    QString message = sock->readAll();

    ui->listMessages->addItem(message);
}

void ChatWidget::sendMessage()
{
    QString message = ui->editChat->text();
    ui->editChat->clear();

    sock->write(message.toUtf8());
}
