#include "Field.h"
#include <glut.h>
using namespace std;
void Field::Set_scale()
{
	Scale = 25; //масштабирующий коэффициент
}
void Field::Set_w(int N,int Scale)
{
	w = N*Scale; // устанавливаю ширину окна
}
void Field::Set_h(int M,int Scale)
{
	h = M*Scale;// устанавливаю высоту окна
}
int Field::Get_h()
{
	return h;
}
int Field::Get_w()
{
	return w;
}
int Field::Get_Scale()
{
	return Scale;
}
Field::Field(void)
{
}
Field::~Field(void)
{
}
void Field::DrawField() //прорисовка поля
{
	glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
	for (int i=0; i<w; i+=Scale)
      {
		  glVertex2f(i,0); glVertex2f(i,h);
	  }
    for (int j=0; j<h; j+=Scale)
      {
		  glVertex2f(0,j); glVertex2f(w,j);
	  }
    glEnd();
	glFlush();
}
