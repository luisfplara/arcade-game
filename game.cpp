#include <QGraphicsTextItem>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>

#include "game.h"
#include "enemy.h"
#include "menu.h"

Game::Game(QWidget *parent)
{
 scene = new QGraphicsScene();
 scene->setSceneRect(0,0,800,600);
 scene->setBackgroundBrush(QBrush(QImage(":/images/img/Background/starBackground.png")));

 QFont f("Arial", 20,20,false);
 QGraphicsTextItem *text = scene->addText("Luis Fernando Pinto",f);
 text->setPos(0, 550);

 setScene(scene);
 setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 setFixedSize(800,600);

 m = new menu();
 m->setPos(300,400);
 //while(!m->start){}
 scene->addItem(m);


 player = new Player();
 player->setPos(350,500);
 player->setFlag(QGraphicsItem::ItemIsFocusable);
 player->setFocus();
 scene->addItem(player);

 QTimer * timer = new QTimer();
 QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
 timer->start(2000);

 score = new Score();
 scene->addItem(score);
 health = new Health();
 health->setPos(health->x(), health->y()+25);


  QMediaPlayer * music = new QMediaPlayer(this);
  music->setMedia(QUrl("qrc:/sounds/sounds/Hall of the Mountain King.mp3"));
  music->play();

  show();

}
