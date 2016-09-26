#include "Snake.h"
#include <glut.h>
Snake::Snake(void)
{
	s[0].x = 0;  //  s[0] -  ������ ��� �������� ��������� ������ ������
	s[0].y = 0;
	num = 3;    // ��������� ����� ������
	health = 3;
	scale = 25;  // �������������� �����������
	Score = 0;
	dir = 0; // �� ��������� �������� ������ �����
}
Snake::~Snake(void)
{
}
 void Snake::DrawSnake(double red, double green, double blue)  // ������� ��������� ������. ��������� � ���-�� ���������� ������ ����� ��� ���������, �� ������ ������������.
 {
  glColor3f(red,green,blue);
  for (int i=0;i<num;i++)
    {
		 //glColor3f(red,green,blue);
		 glRectf(s[i].x*scale, s[i].y*scale, (s[i].x+1)*scale, (s[i].y+1)*scale);
	 }
 }

 void Snake::TickSnake(Field lea,Fruct m[], int best)  //������� �������� ������
 {
	 for (int i=num;i>0;--i)  //������� ������ � ����������� dir ����������� ��������� � ������ ����������� �����
	{
		s[i].x = s[i-1].x;
		s[i].y = s[i-1].y;
	}

	if (dir==0) s[0].y+=1;  // ������������ �����
	if (dir==1) s[0].x-=1;  // ������������ �����
	if (dir==2) s[0].x+=1;  // ������������ ������
	if (dir==3) s[0].y-=1;  // ������������ ����

	for (int i=0;i<15;i++)
		if (  ( s[0].x==m[i].Get_fruct_x())  &&  ( s[0].y==m[i].Get_fruct_y())  ) //�������� �� ��, ��� ������ ����� �� ������.
		{
			num++;  // ����������� ����� ������
			Score++; //�  ������� ���������
			if ( Score > best )
				best = Score;
			m[i].Set_fruct();
		}

		if ( s[0].x > lea.Get_w()/lea.Get_Scale()-1 ) { dir=1; health--; num = 2;}// ���� ������� �� ���� �����, ������ ����������� �� ���������������, ������ 1 �����
		if ( s[0].x<0 )                               { dir=2; health--; num = 2;}
		if ( s[0].y > lea.Get_h()/lea.Get_Scale()-1 ) { dir=3; health--; num = 2;}
		if ( s[0].y<0 )                               { dir=0; health--; num = 2;}

		for (int i=1; i<num; i++)  //���� ������ "������" �� ����, �� ������� ���� �� ���� ����������.
			if ( s[0].x == s[i].x  &&  s[0].y == s[i].y)  num=i;
 }
