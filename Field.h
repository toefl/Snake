#ifndef Field_INCLUDED
#define Field_INCLUDED

using namespace std;
// ������ ����� ������������� ������,������ ������������ ����, � ��� �� �������������� �����������, � ����� ������ ���� ��� ������
class Field
{
public:
	Field(void);
	~Field(void);
	void DrawField(); // ���������� ����
	void Set_w(int,int);//��������� ������ ����
	void Set_h(int,int);//��������� ������ ����
	void Set_scale();//��������� ��������
	int Get_w();//�������� ������ ����
	int Get_h();//�������� ������ ����
	int Get_Scale();// �������� �������
private:
	int w,h,Scale;// ������, ������, �������.
};

#endif