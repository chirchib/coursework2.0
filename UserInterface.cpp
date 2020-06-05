#include "UserInterface.h"
#include "data.h"
#include "data.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

UserInterface::UserInterface()
{
	
}

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
		case '1':
		{

		}
		break;
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
	string _eqiup, _mod, _sernum;
	long _invnum;
	system("cls");
	cout << "���������� ����� ����������" << endl;
	cout << "������� ��� ������������: " << endl;
	cin >> _eqiup;
	cout << "������� ������: " << endl;
	cin >> _mod;
	cout << "������� �������� �����:" << endl; 
	cin >> _sernum;
	cout << "������� ����������� �����: " << endl;
	cin >> _invnum;

	auto account = accounting(_eqiup, _mod, _sernum, _invnum);
//	data.load();
	data.add(account);
	menu1();
}

void UserInterface::menu1_2()
{

}

UserInterface::~UserInterface()
{
//	data.save();
}