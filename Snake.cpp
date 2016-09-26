#include "Snake.h"
#include <glut.h>
Snake::Snake(void)
{
	s[0].x = 0;  //  s[0] -  ячейка для хранения координат головы змейки
	s[0].y = 0;
	num = 3;    // начальная длина змейки
	health = 3;
	scale = 25;  // масштабирующий коэффициент
	Score = 0;
	dir = 0; // по умолчанию движение змейки вверх
}
Snake::~Snake(void)
{
}
 void Snake::DrawSnake(double red, double green, double blue)  // функция отрисовки змейки. Принимает в кач-ве параметров нужные цвета для рисования, по выбору пользователя.
 {
  glColor3f(red,green,blue);
  for (int i=0;i<num;i++)
    {
		 //glColor3f(red,green,blue);
		 glRectf(s[i].x*scale, s[i].y*scale, (s[i].x+1)*scale, (s[i].y+1)*scale);
	 }
 }

 void Snake::TickSnake(Field lea,Fruct m[], int best)  //функция движения змейки
 {
	 for (int i=num;i>0;--i)  //Сдвинув голову в направлении dir передвигаем остальное в ячейку предыдущего звена
	{
		s[i].x = s[i-1].x;
		s[i].y = s[i-1].y;
	}

	if (dir==0) s[0].y+=1;  // передвижение вверх
	if (dir==1) s[0].x-=1;  // передвижение влево
	if (dir==2) s[0].x+=1;  // передвижение вправо
	if (dir==3) s[0].y-=1;  // передвижение вниз

	for (int i=0;i<15;i++)
		if (  ( s[0].x==m[i].Get_fruct_x())  &&  ( s[0].y==m[i].Get_fruct_y())  ) //проверка на то, что голова дошла до фрукта.
		{
			num++;  // увеличиваем длину змейки
			Score++; //и  текущий результат
			if ( Score > best )
				best = Score;
			m[i].Set_fruct();
		}

		if ( s[0].x > lea.Get_w()/lea.Get_Scale()-1 ) { dir=1; health--; num = 2;}// если доходим до края карты, меняем направление на противоположное, тратим 1 жизнь
		if ( s[0].x<0 )                               { dir=2; health--; num = 2;}
		if ( s[0].y > lea.Get_h()/lea.Get_Scale()-1 ) { dir=3; health--; num = 2;}
		if ( s[0].y<0 )                               { dir=0; health--; num = 2;}

		for (int i=1; i<num; i++)  //если голова "прошла" по телу, то съедаем себя по этой координате.
			if ( s[0].x == s[i].x  &&  s[0].y == s[i].y)  num=i;
 }
