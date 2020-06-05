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
			cout << "\nТакого варианта не существует, попробуйте еще раз";
			break;
		}
	}
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
			menu1_1();
			break;
		case '2':
			menu1_2();
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
	bool tmp = false;
	while (!tmp)
	{
		string searchTypeofEqiup, searchModel, searchSerialNumber;
		long searchInventoryNumber;
		auto data = Data();
		data.load();
		vector<accounting> searchVect;
		for (int i = 0; i < data.getSize(); i++)
		{
			searchVect.push_back(data.getVector(i));
		}
		bool tmp = false;
		while (!tmp)
		{
			bool found_one = false;
			char choice;
			cin >> choice;
			switch (choice)
			{
			case '1':
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
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\nНе удалось ничего найти.";
				}
				break;
			case '2':
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
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\nНе удалось ничего найти.";
				}
				break;
			case '3':
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
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\nНе удалось ничего найти.";
				}
				break;
			case '4':
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
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\nНе удалось ничего найти.";
				}

				break;
			case '5':
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
					if (searchSerialNumber == (*it).get_serialNumber()
						&& searchModel == (*it).get_Model()
						&& searchSerialNumber == (*it).get_serialNumber()
						&& searchInventoryNumber == (*it).get_inventoryNumber())
					{
						if (!found_one)
						{
							cout << "\nУдалось найти: ";
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\nНе удалось ничего найти.";
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
	}
	main_menu();
	return;
}

void menu4()
{
	system("cls");
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
	Data data = Data();


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
	menu1();
}

void menu1_2()
{

}