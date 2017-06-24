#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    clip = QApplication::clipboard();
    connect(clip,SIGNAL(dataChanged()),this,SLOT(slotget()));
}


void Widget::slotget()
{
    static QString clip_str;

    if(set_flag == false)
    {
        clip_str.append(clip->text()+"\n");
        set_flag = true;
        clip->setText(clip_str);
    }

    else
    {
        set_flag = false;
    }

}

void Widget::keyPressEvent(QKeyEvent *e)
{
    static bool enter_alt = false;

    if(e->key() == Qt::Key_Alt)
    {
        enter_alt = true;
        qDebug("Get Alt key ... ");
    }

    else
    {
        if(enter_alt)
        {
            // click ctl + someting ( ex.ctl+c )
            enter_alt = false;
            qDebug("Do function Processs ... ");
        }

        else
            qDebug("Nothing to Do");
    }
}

Widget::~Widget()
{
    delete ui;
}
