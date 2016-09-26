#include "fruct.h"
#include <stdlib.h>
#include <time.h>
#include <glut.h>
using namespace std;
Fruct::Fruct(void)
{
	srand(time(0));
	Scale = 25;
}
Fruct::~Fruct(void)
{
}
void Fruct::Set_fruct() // случайным образом получаем фрукт на поле
{
	x=rand() % 20;
    y=rand() % 20;
}
int Fruct::Get_fruct_x()
{
	return x;
}
int Fruct::Get_fruct_y()
{
	return y;
}
void Fruct::Draw_Fruct() // прорисовка фркута
{
	glColor3f(0.0,1.0,1.0);
    glRectf(x*Scale,y*Scale,(x+1)*Scale,(y+1)*Scale);
}

