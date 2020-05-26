#include "UserInterface.h"
#include "data.h"
#include <iostream>
#include <iomanip>
using namespace std;

void UserInterface::main_menu()
{
	system("cls");
	cout << "����� ����������!\n";
	cout << "\n�������� �����: "
		 << "\n1) �������� ����� ���������� ��� �������."
		 << "\n2) ������������� ������������ ����������."
		 << "\n3) ����� ����������."
		 << "\n4) ������� ������."
		 << "\n0) �����"
		 << "\n��� �����: ";
	while (true)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '1':
			menu1();
			break;
		case '2':
			menu2();
			break;
		case '3':
			menu3();
			break;
		case '4':
			menu4();
			break;
		case '0':
			return;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
}

void UserInterface::menu1()
{
	system("cls");
	cout << "���������� ������ ������������: ";
	cout << "\n1) ��������"
	 	 << "\n2) �������"
		 << "\n0)���������"
		 << "\n��� �����: ";
	while (true)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			main_menu();
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
}

void UserInterface::menu2()
{
	system("cls");
	cout << "�������������� ����������: ";
	cout << "\n0) ���������"
		 << "\n��� �����: ";
	while (true)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			main_menu();
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
}

void UserInterface::menu3()
{
	system("cls");
	cout << "����� ����������:"
		<< "\n1) ����� �� ���� ������������"
		<< "\n2) ����� �� ������"
		<< "\n3) ����� �� ��������� ������"
		<< "\n4) ����� �� ������������ ������"
		<< "\n5) ����� �� ���� �������"
		<< "\n0) ���������"
		<< "\n��� �����: ";
	while (true)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			main_menu();
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
}

void UserInterface::menu4()
{
	system("cls");
	cout << "\n0) ���������"
	     << "\n��� �����: ";
	while (true)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '0':
			main_menu();
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
}

void UserInterface::get_header()
{
	cout << endl << setw(20) << left << "Type of Eqiupment"
		<< setw(20) << left << "Model"
		<< setw(20) << left << "Serial Number"
		<< setw(20) << left << "Inventory Number" << endl
		<< setw(70) << setfill('-');
}

void UserInterface::menu1_1()
{
	addVect();
	menu1();
}

void UserInterface::menu1_2()
{

}