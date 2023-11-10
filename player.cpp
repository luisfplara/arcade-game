#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>


#include "player.h"
#include "bullet.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/img/player.png"));
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/Laser.mp3"));


}
void Player::keyPressEvent(QKeyEvent *event)
{
 // mensagem informando que ocorreu uso do teclado
 //qDebug()<<"Key press detected";
 if(event->key() == Qt::Key_Left)
 {
 // limite para não sair da tela
 if(pos().x() > 0)
 setPos(x()-10,y());
 }
 else if(event->key() == Qt::Key_Right)
 {
 // limite para não sair da tela
 if(pos().x() + 100 < 800 )
 setPos(x()+10,y());
 }
 else if(event->key() == Qt::Key_Up)
 {
 setPos(x(),y()-10);
 }
 else if(event->key() == Qt::Key_Down)
 {
 setPos(x(),y()+10);
 }
 // criar tiro (bullet)
  else if(event->key() == Qt::Key_Space)
  {
  // teste via Debug
  // qDebug()<<"Bullet created";
  Bullet * bullet = new Bullet();
  bullet->setPos(x(),y());
  scene()->addItem(bullet);
  // adicionar barulho de tiro
   // analizando o estado de reprodução de Player
   if(bulletsound->state() == QMediaPlayer::PlayingState)
   {
   // caso o som ainda esta tocando resetar o Player para posição

   bulletsound->setPosition(0);
   }
   else if(bulletsound->state() == QMediaPlayer::StoppedState)
   {
   bulletsound->play();
   }
  }
 }
void Player::spawn()
{
 // cria inimigo
 Enemy * enemy = new Enemy();
 scene()->addItem(enemy);
}

