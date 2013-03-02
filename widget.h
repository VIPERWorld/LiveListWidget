#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include "livelistwidget.h"

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    LiveListWidget *listWidget;
private slots:
    void movedSignalCaught(int src,int dest,QListWidgetItem* item);
    void removedSignalCaught(int row, QListWidgetItem* item);
};

#endif // WIDGET_H
