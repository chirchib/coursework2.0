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
			cout << "\n������ �������� �� ����������, ���������� ��� ���";
			break;
		}
	}
	main_menu();
	return;
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
				cout << "\n������� ��� ������������: " << endl;
				cin >> searchTypeofEqiup;
				found_one = false;
				for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
				{
					if (searchTypeofEqiup == (*it).get_typeofEqiup())
					{
						if (!found_one)
						{
							cout << "\n������� �����: ";
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\n�� ������� ������ �����.";
				}
				break;
			case '2':
				cout << "\n������� ������ ������������: " << endl;
				cin >> searchModel;
				found_one = false;
				for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
				{
					if (searchModel == (*it).get_Model())
					{
						if (!found_one)
						{
							cout << "\n������� �����: ";
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\n�� ������� ������ �����.";
				}
				break;
			case '3':
				cout << "\n������� �������� �����: " << endl;
				cin >> searchSerialNumber;
				found_one = false;
				for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
				{
					if (searchSerialNumber == (*it).get_serialNumber())
					{
						if (!found_one)
						{
							cout << "\n������� �����: ";
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\n�� ������� ������ �����.";
				}
				break;
			case '4':
				cout << "\n������� ����������� �����: " << endl;
				cin >> searchInventoryNumber;
				found_one = false;
				for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
				{
					if (searchSerialNumber == (*it).get_serialNumber())
					{
						if (!found_one)
						{
							cout << "\n������� �����: ";
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\n�� ������� ������ �����.";
				}

				break;
			case '5':
				cout << "\n������� ��� ������������: " << endl;
				cin >> searchTypeofEqiup;
				cout << "\n������� ������ ������������: " << endl;
				cin >> searchModel;
				cout << "\n������� �������� �����: " << endl;
				cin >> searchSerialNumber;
				cout << "\n������� ����������� �����: " << endl;
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
							cout << "\n������� �����: ";
							get_header();
							found_one = true;
						}
						(*it).display();
					}
				}
				if (!found_one)
				{
					cout << "\n�� ������� ������ �����.";
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
	}
	main_menu();
	return;
}

void menu4()
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
	menu1();
}

void menu1_2()
{

}