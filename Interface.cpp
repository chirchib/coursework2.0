#include "Interface.h"
#include "data.h"
#include "account.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <conio.h>

#include <Windows.h>

using namespace std;

Interface::Interface()
{
	setlocale(LC_ALL, "Russian");
	ios::sync_with_stdio(true);//������������� iostream � ������������ ������(�������� cout)

	data = Data();//������������� ������� 


	data.load();//��������

	Interface::mainMenu();
}

void Interface::mainMenu()
{

	system("cls");
	cout << "����� ����������!\n";
	cout << "\n�������� �����: "
		<< "\n1) �������� ����� ���������� ��� �������."
		<< "\n2) ������������� ������������ ����������."
		<< "\n3) ����� ����������."
		<< "\n4) ������� ������."
		<< "\n0) �����\n";

	char choice;
	choice = _getch();//������ cin �� _getch() 
	switch (choice)
	{
	case '1':
		Interface::menu1();
		break;
	case '2':
		Interface::menu2();
		break;
	case '3':
		Interface::menu3();
		break;
	case '4':
		Interface::menu4();
		break;
	case '0':

		data.save();
		exit(EXIT_SUCCESS);
		break;
	default:
		Interface::mainMenu();
		break;
	}
		
}

void Interface::menu1()
{
	system("cls");
	cout << "���������� ������ ������������: ";
	cout << "\n1) ��������"
		<< "\n2) �������"
		<< "\n0)���������\n";
	char choice;
	choice = _getch();
	switch (choice)
	{
	case '1':
		menu11();
		break;
	case '2':
		menu12();
		break;
	case '0':
		mainMenu();
		break;
	default:
		menu1();
		break;
	}

}

void Interface::menu2()
{
	system("cls");
	cout << "�������������� ����������: ";
	cout << "\n0) ���������\n";

	char choice;
	choice = _getch();
	switch (choice)
	{
	case '0':
		Interface::mainMenu();
		break;
	default:
		system("cls");
		cout << "\n������ �������� �� ����������, ���������� ��� ���";
		break;
	}

}

void Interface::menu3()
{
	system("cls");
	cout << "����� ����������:"
		<< "\n1) ����� �� ���� ������������"
		<< "\n2) ����� �� ������"
		<< "\n3) ����� �� ��������� ������"
		<< "\n4) ����� �� ������������ ������"
		<< "\n5) ����� �� ���� �������"
		<< "\n0) ���������\n";

	char choice;
	choice = _getch();
	switch (choice)
	{
	case '1':
		Interface::menu31();
		break;
	case '2':
		Interface::menu32();
		break;
	case '3':
		Interface::menu33();
		break;
	case '4':
		Interface::menu34();
		break;
	case '5':
		Interface::menu35();
		break;
	case '0':
		Interface::mainMenu();
		break;
	default:
		Interface::menu3();
		break;
	}

}

void Interface::menu4()
{
	system("cls");
	//cout << "\n----������ ������----\n";
	setCursorVisible(false);
	getHeader();
	this->data.print();
	_getch();
	setCursorVisible(true);
	Interface::mainMenu();
}

void Interface::getHeader()
{
	cout << endl << setw(20) << left << "���"
		<< setw(20) << left << "������"
		<< setw(20) << left << "��������"
		<< setw(20) << left << "�����������" << endl
		<< setw(70) << setfill('-');
}

void Interface::menu11()
{
	int id;
	string typeofEqiup;
	string model;
	string serialNumber;
	long inventoryNumber;
	system("cls");
	cout << "���������� ����� ����������" << endl;

	//������� ���� ID
	cout << "������� ID: " << endl;
	cin >> id;
	cout << "������� ��� ������������: " << endl;
	cin >> typeofEqiup;
	cout << "������� ������: " << endl;
	cin >> model;
	cout << "������� �������� �����:" << endl;
	cin >> serialNumber;
	cout << "������� ����������� �����: " << endl;
	cin >> inventoryNumber;
	//���������� ����������� ��������(???)
	auto account = Account(id,typeofEqiup,model,serialNumber,inventoryNumber);
	data.add(account);
	Interface::menu1();
}


void Interface::menu12()
{
	system("cls");
	cout << "\n----������� ������������----\n";
	//TODO �������� ������������
	_getch();
	Interface::menu1();
}

void Interface::menu31()
{
	system("cls");
	cout << "\n----����� �� ���� ������������----\n";
	//TODO ����� ������������
	_getch();
	Interface::menu1();
}

void Interface::menu32()
{
	system("cls");
	cout << "\n----����� �� ������----\n";
	//TODO ����� �� ������
	_getch();
	Interface::menu1();
}

void Interface::menu33()
{
	system("cls");
	cout << "\n----����� �� ��������� ������----\n";
	//TODO ����� �� ��������� ������
	_getch();
	Interface::menu1();
}

void Interface::menu34()
{
	system("cls");
	cout << "\n----����� �� ������������ ������----\n";
	//TODO ����� �� ������������ ������
	_getch();
	Interface::menu1();
}

void Interface::menu35()
{
	system("cls");
	cout << "\n----����� �� ���� �������----\n";
	//TODO ����� �� ���� �������
	_getch();
	Interface::menu1();
}



///<summary>
/// ������������� ����������� ������� ����������� WinAPI (Windows.h)
///</summary>
///<param name = "visible"> ��������� ������� </param>
void Interface::setCursorVisible(bool visible)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

