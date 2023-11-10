#include "menu.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>


#include <QKeyEvent>

menu::menu(QWidget *parent):QWidget(parent) {

     setPixmap(QPixmap(":/menu/img/Menu/StartButton.png").scaled(200,200,Qt::KeepAspectRatio));
     start = false;
     qDebug()<<"Start Button ok";
}

void menu::mousePressEvent(QGraphicsSceneMouseEvent *event){
    start=true;
}
