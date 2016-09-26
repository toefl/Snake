#include "Fruct.h"
#include "Field.h"
#include "Snake.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <glut.h>
#include <fstream>
using namespace std;

int speed=0,best;
double red = 0.0, green = 0.0, blue = 0.0;
Field lea; // поле
Fruct m[15]; // яблоко на поле
Snake Z; 
ifstream in("BEST.txt");
void drawText(const char *text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0,400,0,500,-100,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x,y);
	for(int i=0; i<length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,(int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);

}
void display() 
{
	char score[3],bestScore[3],Health[2];
	itoa(Z.Score,score,10);
	in >> best;
	int j=0;
	itoa(best,bestScore,10);
	glClear(GL_COLOR_BUFFER_BIT);
	if ( Z.health == 0 )
	{
		glClear(GL_COLOR_BUFFER_BIT);
		cout << "G A M E  O V E R !" << endl;
		_sleep(1000);
		exit(0);
	}
	lea.DrawField();
	Z.DrawSnake(red,green,blue);
	for (int i=0; i<15; i++)
	{
		m[i].Draw_Fruct();
	}
	glColor3f( 1.0, 0.0, 0.0 );
	drawText("You score: ",12,300,6);
	drawText(score,3,380,6);
	if ( best <  Z.Score )
	{
		in.close();
		in.open("BEST.txt", ios::out);
		ofstream out("BEST.txt");
		out << Z.Score;
		best = Z.Score;
		itoa(best,bestScore,10);
	}
	drawText("Best result: ",13,10,6);
	drawText(bestScore,3,90,6);
	drawText("Health:",7,163,6);
	itoa(Z.health,Health,6);
	drawText(Health,7,210,6);
	glFlush();
	glutSwapBuffers();
}
void KeyboardEvent(int key, int a, int b)
{   
	switch(key)
	{
	case 101 : 	Z.dir=0; break; // up
	case 102 :  Z.dir=2; break;
	case 100 :  Z.dir=1; break;
	case 103 :  Z.dir=3; break;
	case GLUT_KEY_F1 :   speed=speed+5; break;
	case GLUT_KEY_F2 :   speed=speed-5; break;
	case GLUT_KEY_F3 :  {
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
						}
	case GLUT_KEY_F4 : {
		red = 0.0;
		green = 1.0;
		blue = 0.0;
		break;
					   }
	case GLUT_KEY_F5 : {
		red = 0.0;
		green = 0.0;
		blue = 1.0;
		break;
					   }
	}
}
void timer(int =0)
{
	display();
	Z.TickSnake(lea,m,best);
	glutTimerFunc(80-speed,timer,0);
}
int main(int argc, char **argv)
{
	in >> best;
	lea.Set_scale();
	lea.Set_h(20,lea.Get_Scale());
	lea.Set_w(20,lea.Get_Scale());
	
	for ( int i=0; i<15; i++ )
	{
		m[i].Set_fruct();
	}
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize (lea.Get_w(), lea.Get_h() );
	glutCreateWindow ("Snake. Bikmukhametov Aidar."); 
	glClearColor(0.0,0.6,0.3,0.1);  //цвет фона
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,lea.Get_w(),0,lea.Get_h());
	glutDisplayFunc (display);
	glutSpecialFunc(KeyboardEvent);
	glutTimerFunc(50,timer,0); 
	glutMainLoop();
}
