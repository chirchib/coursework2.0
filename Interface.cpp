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
	ios::sync_with_stdio(true);//Синхронизация iostream и стандартного потока(ускоряет cout)

	data = Data();//Инициализация объекта 


	data.load();//Загрузка

	Interface::mainMenu();
}

void Interface::mainMenu()
{

	system("cls");
	cout << "Добро пожаловать!\n";
	cout << "\nВыберите пункт: "
		<< "\n1) Добавить новую информацию или удалить."
		<< "\n2) Редактировать существующую информацию."
		<< "\n3) Поиск информации."
		<< "\n4) Вывести данные."
		<< "\n0) Выйти\n";

	char choice;
	choice = _getch();//Замена cin на _getch() 
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
	cout << "Добавление нового оборудования: ";
	cout << "\n1) Добавить"
		<< "\n2) Удалить"
		<< "\n0)Вернуться\n";
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
	cout << "Редактирование информации: ";
	cout << "\n0) Вернуться\n";

	char choice;
	choice = _getch();
	switch (choice)
	{
	case '0':
		Interface::mainMenu();
		break;
	default:
		system("cls");
		cout << "\nТакого варианта не существует, попробуйте еще раз";
		break;
	}

}

void Interface::menu3()
{
	system("cls");
	cout << "Поиск информации:"
		<< "\n1) Поиск по типу оборудования"
		<< "\n2) Поиск по модели"
		<< "\n3) Поиск по серийному номеру"
		<< "\n4) Поиск по инвентарному номеру"
		<< "\n5) Поиск по всем пунктам"
		<< "\n0) Вернуться\n";

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
	//cout << "\n----Список данных----\n";
	setCursorVisible(false);
	getHeader();
	this->data.print();
	_getch();
	setCursorVisible(true);
	Interface::mainMenu();
}

void Interface::getHeader()
{
	cout << endl << setw(20) << left << "Тип"
		<< setw(20) << left << "Модель"
		<< setw(20) << left << "Серийный№"
		<< setw(20) << left << "Инвентарный№" << endl
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
	cout << "Добавление новой информации" << endl;

	//Добавил ввод ID
	cout << "Введите ID: " << endl;
	cin >> id;
	cout << "Введите тип оборудования: " << endl;
	cin >> typeofEqiup;
	cout << "Введите модель: " << endl;
	cin >> model;
	cout << "Введите серийный номер:" << endl;
	cin >> serialNumber;
	cout << "Введите инвентарный номер: " << endl;
	cin >> inventoryNumber;
	//Обновлённый конструктор аккаунта(???)
	auto account = Account(id,typeofEqiup,model,serialNumber,inventoryNumber);
	data.add(account);
	Interface::menu1();
}


void Interface::menu12()
{
	system("cls");
	cout << "\n----Удалить оборудование----\n";
	//TODO Удаление оборудования
	_getch();
	Interface::menu1();
}

void Interface::menu31()
{
	system("cls");
	cout << "\n----Поиск по типу оборудования----\n";
	//TODO Поиск оборудования
	_getch();
	Interface::menu1();
}

void Interface::menu32()
{
	system("cls");
	cout << "\n----Поиск по модели----\n";
	//TODO Поиск по модели
	_getch();
	Interface::menu1();
}

void Interface::menu33()
{
	system("cls");
	cout << "\n----Поиск по серийному номеру----\n";
	//TODO Поиск по серийному номеру
	_getch();
	Interface::menu1();
}

void Interface::menu34()
{
	system("cls");
	cout << "\n----Поиск по инвентарному номеру----\n";
	//TODO Поиск по инвентарному номеру
	_getch();
	Interface::menu1();
}

void Interface::menu35()
{
	system("cls");
	cout << "\n----Поиск по всем пунктам----\n";
	//TODO Поиск по всем пунктам
	_getch();
	Interface::menu1();
}



///<summary>
/// Устанавливает отображение курсора посредством WinAPI (Windows.h)
///</summary>
///<param name = "visible"> Видимость курсора </param>
void Interface::setCursorVisible(bool visible)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

