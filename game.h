#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "player.h"
#include "score.h"
#include "health.h"
#include "enemy.h"
#include "menu.h"
class Game: public QGraphicsView
{
public:
 Game(QWidget * parent=0);
 QGraphicsScene * scene;
 Player * player;
 Score * score;
 Health *health;
 menu *m;
 void start();

};
#endif // GAME_H
