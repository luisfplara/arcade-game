#ifndef MENU_H
#define MENU_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QWidget>



#include <QObject>
class menu :  public QWidget,public QGraphicsPixmapItem{

public:
 menu(QWidget *parent = 0);
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  bool start;


};

#endif // MENU_H
