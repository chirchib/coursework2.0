#include "Interface.h"
#include "data.h"
#include "Account.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <conio.h>
using namespace std;

Interface::Interface()
{
	setlocale(LC_ALL, "rus");

	data = Data(); //Инициализация класса базы данных 

	data.load();//Загрузка данных из локального файла в вектор

	Interface::mainMenu();//Запуск меню
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
		menu1_1();
		break;
	case '2':
		menu1_2();
		break;
	case '0':
		mainMenu();
		break;
	default:
		menu1();
		break;
	}

}

void Interface::menu1_1()
{
	int _id;
	string _eqiup, _mod, _sernum;
	long _invnum;
	cout << "Добавление новой информации" << endl;
	do
	{
		cout << "Введите ID: " << endl;
		cin >> _id;
	} while (data.search(_id) == false);
	cout << "Введите тип оборудования: " << endl;
	cin >> _eqiup;
	cout << "Введите модель: " << endl;
	cin >> _mod;
	cout << "Введите серийный номер:" << endl;
	cin >> _sernum;
	cout << "Введите инвентарный номер: " << endl;
	cin >> _invnum;

	auto account = Account(_id, _eqiup, _mod, _sernum, _invnum);
	data.add(account);
	data.save();
	Interface::menu1();
}

void Interface::menu1_2()
{
	Interface::getHeader();
	data.print();

	int id;
	cout << "Введите ID элемента, который хотите удалить: " << endl;
	cin >> id;
	if (data.search(id) == true)
	{
		data.remove(id);
		data.save();
		cout << "Удаление выполнено успешно." << endl;
	}
	else
		cout << "Такого элемента нет:" << endl;
	Interface::menu1();
}


void Interface::menu2()
{
	cout << "Редактирование информации: ";
	cout << "\n1) Редакитровать\n0) Вернуться"
		<< "\nВаш выбор: ";
		char choice;
		choice = _getch();
		switch (choice)
		{
		case '1':
			Interface::menu2_1();
			break;
		case '0':
			Interface::mainMenu();
			break;
		default:
			Interface::menu2();
			break;
		}
}

void Interface::menu3()
{
	cout << "Поиск информации:"
		<< "\n1) Поиск по ID"
		<< "\n2) Поиск по типу оборудования"
		<< "\n3) Поиск по модели"
		<< "\n4) Поиск по серийному номеру"
		<< "\n5) Поиск по инвентарному номеру"
		<< "\n6) Поиск по всем пунктам"
		<< "\n0) Вернуться"
		<< "\nВаш выбор: ";


	int searchID;
	string searchTypeofEqiup, searchModel, searchSerialNumber;
	long searchInventoryNumber;
	vector<Account> searchVect;
	for (int i = 0; i < data.getSize(); i++)
	{
		searchVect.push_back(data.getVector(i));
	}
	bool found_one = false;
	char choice;
	choice = _getch();
	switch (choice)
	{
	case '1':
		cout << "\nВведите ID: " << endl;
		cin >> searchID;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchID == (*it).get_ID())
			{
				if (!found_one)
				{
					cout << "\nУдалось найти: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\nНе удалось ничего найти.";
		}
		Interface::menu3();
		break;
	case '2':
		cout << "\nВведите тип оборудования: " << endl;
		cin >> searchTypeofEqiup;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchTypeofEqiup == (*it).get_typeofEqiup())
			{
				if (!found_one)
				{
					cout << "\nУдалось найти: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\nНе удалось ничего найти.";
		}
		Interface::menu3();
		break;
	case '3':
		cout << "\nВведите модель оборудования: " << endl;
		cin >> searchModel;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchModel == (*it).get_Model())
			{
				if (!found_one)
				{
					cout << "\nУдалось найти: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\nНе удалось ничего найти.";
		}
		Interface::menu3();
		break;
	case '4':
		cout << "\nВведите серийный номер: " << endl;
		cin >> searchSerialNumber;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchSerialNumber == (*it).get_serialNumber())
			{
				if (!found_one)
				{
					cout << "\nУдалось найти: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\nНе удалось ничего найти.";
		}
		Interface::menu3();
		break;
	case '5':
		cout << "\nВведите инвентарный номер: " << endl;
		cin >> searchInventoryNumber;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchSerialNumber == (*it).get_serialNumber())
			{
				if (!found_one)
				{
					cout << "\nУдалось найти: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\nНе удалось ничего найти.";
		}
		Interface::menu3();
		break;
	case '6':
		cout << "\nВведите ID: " << endl;
		cin >> searchID;
		cout << "\nВведите тип оборудования: " << endl;
		cin >> searchTypeofEqiup;
		cout << "\nВведите модель оборудования: " << endl;
		cin >> searchModel;
		cout << "\nВведите серийный номер: " << endl;
		cin >> searchSerialNumber;
		cout << "\nВведите инвентарный номер: " << endl;
		cin >> searchInventoryNumber;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchID == (*it).get_ID()
				&& searchSerialNumber == (*it).get_serialNumber()
				&& searchModel == (*it).get_Model()
				&& searchSerialNumber == (*it).get_serialNumber()
				&& searchInventoryNumber == (*it).get_inventoryNumber())
			{
				if (!found_one)
				{
					cout << "\nУдалось найти: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\nНе удалось ничего найти.";
		}
		Interface::menu3();
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
	cout << "\n1) Прямой вывод информации"
		<< "\n2) Сортированный вывод по ID"
		<< "\n3) Сортированный вывод по типу оборудования"
		<< "\n0) Вернуться"
		<< "\nВаш выбор: ";

	vector<Account> sortVect;
	for (int i = 0; i < data.getSize(); i++)
	{
		sortVect.push_back(data.getVector(i));
	}
	int size = sortVect.size();
	auto it = sortVect.begin();
	
		char choice;
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			it = sortVect.begin();
			Interface::getHeader();
			while (it != sortVect.end())
			{
				(*it++).display();
			}
		}
			break;
		case '2':
		{
			for (auto i = 0; i < size - 1; i++)
			{
				int min = i;
				Account hel;
				for (int j = i + 1; j < size; j++)
				{
					if (sortVect[j].get_ID() < sortVect[min].get_ID())
						min = j;
				}
				hel = sortVect[i];
				sortVect[i] = sortVect[min];
				sortVect[min] = hel;
			}
			it = sortVect.begin();
			Interface::getHeader();
			while (it != sortVect.end())
			{
				(*it++).display();
			}
		}
			break;
		case '3':
			for (int i = 0; i < size - 1; i++)
			{
				int min = i;
				Account hel;
				for (int j = i + 1; j < size; j++)
				{
					if (sortVect[j].get_typeofEqiup() < sortVect[min].get_typeofEqiup())
						min = j;
				}
				hel = sortVect[i];
				sortVect[i] = sortVect[min];
				sortVect[min] = hel;
			}
			it = sortVect.begin();
			Interface::getHeader();
			while (it != sortVect.end())
			{
				(*it++).display();
			}
			break;
		case '0':
			Interface::mainMenu();
			break;
		default:
			Interface::menu4();
			break;
		}
}

void Interface::getHeader()
{
	cout << endl << setw(10) << left << "ID"
		<< setw(20) << left << "Type of Eqiupment"
		<< setw(20) << left << "Model"
		<< setw(20) << left << "Serial Number"
		<< setw(20) << left << "Inventory Number" << endl;
}



void Interface::menu2_1()
{
	system("cls");
	Data data = Data();
	data.load();
	getHeader();
	data.print();
	int id;
	cout << "\nВведите ID элемента, который хотите изменить: " << endl;
	cin >> id;
	if (data.search(id) == true)
	{
		string _TypeofEqiup, _Model, _SerialNumber;
		long _InventoryNumber;

		cout << "\nВведите тип оборудования: " << endl;
		cin >> _TypeofEqiup;
		cout << "\nВведите модель оборудования: " << endl;
		cin >> _Model;
		cout << "\nВведите серийный номер: " << endl;
		cin >> _SerialNumber;
		cout << "\nВведите инвентарный номер: " << endl;
		cin >> _InventoryNumber;

		auto account = Account(id, _TypeofEqiup, _Model, _SerialNumber, _InventoryNumber);
		data.edit(account);
		data.save();
		cout << "Редактирование выполненено успешно" << endl;
	}
	else
		cout << "Такого элемента нет." << endl;
	Interface::menu2();
}
