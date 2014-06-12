#ifndef __MARS_SNAKE_H__
#define __MARS_SNAKE_H__

#include "SnakeBase.h"

class MarsSnake : public SnakeBase{
public:
	static MarsSnake* createMarsSnake(PlayScene* ps, Position headPos, int ori, float speed = 1);

	CREATE_FUNC(MarsSnake);

protected:
	int getNextDirection();
};

#endif