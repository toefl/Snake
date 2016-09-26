#ifndef Field_INCLUDED
#define Field_INCLUDED

using namespace std;
// Данный класс устанавливает ширину,высоту создаваемого окна, а так же масштабирующий коэффициент, а затем рисует поле для змейки
class Field
{
public:
	Field(void);
	~Field(void);
	void DrawField(); // прорисовка поля
	void Set_w(int,int);//установка ширины окна
	void Set_h(int,int);//установка высоты окна
	void Set_scale();//установка масштаба
	int Get_w();//получить ширину окна
	int Get_h();//получить высоту окна
	int Get_Scale();// получить масштаб
private:
	int w,h,Scale;// ширина, высота, масштаб.
};

#endif