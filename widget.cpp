#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    listWidget = new LiveListWidget(this);
    layout->addWidget(listWidget);

    for(quint8 i=0; i<3; i++)
    {
        QListWidgetItem *item = new QListWidgetItem(QString("item %1").arg(i));
        listWidget->addItem(item);
    }

    connect(listWidget,SIGNAL(itemMoved(int,int,QListWidgetItem*)),this,SLOT(movedSignalCaught(int, int, QListWidgetItem*)));
    connect(listWidget,SIGNAL(itemRemoved(int,QListWidgetItem*)),this,SLOT(removedSignalCaught(int,QListWidgetItem*)));
}

Widget::~Widget()
{
    
}

void Widget::movedSignalCaught(int src,int dest,QListWidgetItem* item)
{
    qDebug() << item->text() << " was moved from row " << src << " to row " << dest;
}

void Widget::removedSignalCaught(int row, QListWidgetItem *item)
{
    qDebug() << item->text() << " was removed from row " << row;
}
