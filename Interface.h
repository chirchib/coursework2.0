#pragma once

#include "data.h"

class Interface
{
public:
	Interface();

	void mainMenu();

	void menu1(); // ���������� ����� ����������

	void menu2(); // �������������� ����������

	void menu3(); // ����� ����������

	void menu4(); // ����� ������(����������� �� ...)

	void getHeader(); // ����� ��������� �������

	void menu11(); // ����������

	void menu12(); // ��������

	void menu31(); //������ ���������� ������������ �� ���� ������������

	void menu32(); //������ ���������� ������������ �� ������

	void menu33();//������ ���������� ������������ �� ��������� ������

	void menu34();//������ ���������� ������������ �� ������������ ������

	void menu35();//������ ���������� ������������ �� ���� �������(???)



	static void setCursorVisible(bool visible);



private:
	Data data;

};
