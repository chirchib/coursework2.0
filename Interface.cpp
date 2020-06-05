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
	cout << "Добро пожаловать!\n";
	cout << "\nВыберите пункт: "
		<< "\n1) Добавить новую информацию или удалить."
		<< "\n2) Редактировать существующую информацию."
		<< "\n3) Поиск информации."
		<< "\n4) Вывести данные."
		<< "\n0) Выйти"
		<< "\nВаш выбор: ";
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
			cout << "\nТакого варианта не существует, попробуйте еще раз";
			break;
		}
	}
	return;
}

void menu1()
{
	system("cls");
	cout << "Добавление нового оборудования: ";
	cout << "\n1) Добавить"
		<< "\n2) Удалить"
		<< "\n0)Вернуться"
		<< "\nВаш выбор: ";
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
			cout << "\nТакого варианта не существует, попробуйте еще раз";
			break;
		}
	}
	main_menu();
}

void menu2()
{
	system("cls");
	cout << "Редактирование информации: ";
	cout << "\n0) Вернуться"
		<< "\nВаш выбор: ";
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
			cout << "\nТакого варианта не существует, попробуйте еще раз";
			break;
		}
	}
}

void menu3()
{
	system("cls");
	cout << "Поиск информации:"
		<< "\n1) Поиск по типу оборудования"
		<< "\n2) Поиск по модели"
		<< "\n3) Поиск по серийному номеру"
		<< "\n4) Поиск по инвентарному номеру"
		<< "\n5) Поиск по всем пунктам"
		<< "\n0) Вернуться"
		<< "\nВаш выбор: ";
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
			cout << "\nТакого варианта не существует, попробуйте еще раз";
			break;
		}
	}
}

void menu4()
{
	system("cls");
	cout << "1)Вывести\n0) Вернуться"
		<< "\nВаш выбор: ";
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
			cout << "\nТакого варианта не существует, попробуйте еще раз";
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
	cout << "Добавление новой информации" << endl;
	cout << "Введите тип оборудования: " << endl;
	cin >> _eqiup;
	cout << "Введите модель: " << endl;
	cin >> _mod;
	cout << "Введите серийный номер:" << endl;
	cin >> _sernum;
	cout << "Введите инвентарный номер: " << endl;
	cin >> _invnum;

	auto account = accounting(_eqiup, _mod, _sernum, _invnum);
	data.add(account);
	data.save();
	menu1();
}

void menu1_2()
{

}