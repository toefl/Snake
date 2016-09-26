#ifndef FRUCT_INCLUDED
#define FRUCT_INCLUDED

using namespace std;
class Fruct
{
public:
	Fruct(void);
	~Fruct(void);
	void Draw_Fruct(); //рисовать фрукт
	void Set_fruct(); //ф-ия генерирует случайное значение координат фрукта
	int Get_fruct_x();  //получить координату х
	int Get_fruct_y();//получить координату у
private:
	int x,y,Scale;  // переменные для координат фрукта, Scale - масштаб.
};
#endif