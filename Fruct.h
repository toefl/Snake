#ifndef FRUCT_INCLUDED
#define FRUCT_INCLUDED

using namespace std;
class Fruct
{
public:
	Fruct(void);
	~Fruct(void);
	void Draw_Fruct(); //�������� �����
	void Set_fruct(); //�-�� ���������� ��������� �������� ��������� ������
	int Get_fruct_x();  //�������� ���������� �
	int Get_fruct_y();//�������� ���������� �
private:
	int x,y,Scale;  // ���������� ��� ��������� ������, Scale - �������.
};
#endif