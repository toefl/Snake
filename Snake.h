#ifndef SNAKE_INCLUDED
#define SNAKE_INCLUDED
#include "Field.h"
#include "Fruct.h"
using namespace std;
class Snake
{
public:
	Snake(void);
	~Snake(void);
	void DrawSnake(double,double,double);
	void TickSnake(Field,Fruct [],int);
	int num,health,Score,dir;
	struct
	{
		int x,y;
	}s[150];
private:
	int scale;
};
#endif