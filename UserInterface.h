#pragma once
#include "data.h"
using namespace std;
class UserInterface
{
public:
	
	UserInterface();

	void main_menu();

	~UserInterface();

private:

	Data data = Data();

	void menu1(); // ���������� ����� ����������

	void menu2(); // �������������� ����������

	void menu3(); // ����� ����������

	void menu4(); // ����� ������(����������� �� ...)

	void get_header(); // ����� ��������� �������

	void menu1_1(); // ����������

	void menu1_2(); // ��������
};