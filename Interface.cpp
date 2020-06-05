#include "Interface.h"
#include "data.h"
#include "accounting.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void Interface()
{
	setlocale(LC_ALL, "Russian");
	main_menu();
	return;
}

void main_menu()
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
	bool tmp = false;
	while (!tmp)
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
			tmp++;
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
	return;
}

void menu1()
{
	system("cls");
	cout << "���������� ������ ������������: ";
	cout << "\n1) ��������"
		<< "\n2) �������"
		<< "\n0)���������"
		<< "\n��� �����: ";
	bool tmp = false;
	while (!tmp)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			menu1_1();
			break;
		}
		break;
		case '0':
			tmp++;
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
	main_menu();
}

void menu2()
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

void menu3()
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

void menu4()
{
	system("cls");
	cout << "1)�������\n0) ���������"
		<< "\n��� �����: ";
	bool tmp = false;
	while (!tmp)
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			auto data = Data();
			data.load();
			get_header();
			data.print();
		}
			cout << endl;
			break;
		case '0':
			tmp++;
			break;
		default:
			system("cls");
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
	main_menu();
	return;
}

void get_header()
{
	cout << endl << setw(20) << left << "Type of Eqiupment"
		<< setw(20) << left << "Model"
		<< setw(20) << left << "Serial Number"
		<< setw(20) << left << "Inventory Number" << endl;
	return;
}

void menu1_1()
{
	auto data = Data();
	data.load();

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
	data.add(account);
	data.save();
	menu1();
}

void menu1_2()
{

}