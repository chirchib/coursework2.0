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

	data = Data(); //������������� ������ ���� ������ 

	data.load();//�������� ������ �� ���������� ����� � ������

	Interface::mainMenu();//������ ����
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
	cout << "���������� ����� ����������" << endl;
	do
	{
		cout << "������� ID: " << endl;
		cin >> _id;
	} while (data.search(_id) == false);
	cout << "������� ��� ������������: " << endl;
	cin >> _eqiup;
	cout << "������� ������: " << endl;
	cin >> _mod;
	cout << "������� �������� �����:" << endl;
	cin >> _sernum;
	cout << "������� ����������� �����: " << endl;
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
	cout << "������� ID ��������, ������� ������ �������: " << endl;
	cin >> id;
	if (data.search(id) == true)
	{
		data.remove(id);
		data.save();
		cout << "�������� ��������� �������." << endl;
	}
	else
		cout << "������ �������� ���:" << endl;
	Interface::menu1();
}


void Interface::menu2()
{
	cout << "�������������� ����������: ";
	cout << "\n1) �������������\n0) ���������"
		<< "\n��� �����: ";
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
	cout << "����� ����������:"
		<< "\n1) ����� �� ID"
		<< "\n2) ����� �� ���� ������������"
		<< "\n3) ����� �� ������"
		<< "\n4) ����� �� ��������� ������"
		<< "\n5) ����� �� ������������ ������"
		<< "\n6) ����� �� ���� �������"
		<< "\n0) ���������"
		<< "\n��� �����: ";


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
		cout << "\n������� ID: " << endl;
		cin >> searchID;
		found_one = false;
		for (auto it = searchVect.begin(); it != searchVect.end(); ++it)
		{
			if (searchID == (*it).get_ID())
			{
				if (!found_one)
				{
					cout << "\n������� �����: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\n�� ������� ������ �����.";
		}
		Interface::menu3();
		break;
	case '2':
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
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\n�� ������� ������ �����.";
		}
		Interface::menu3();
		break;
	case '3':
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
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\n�� ������� ������ �����.";
		}
		Interface::menu3();
		break;
	case '4':
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
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\n�� ������� ������ �����.";
		}
		Interface::menu3();
		break;
	case '5':
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
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\n�� ������� ������ �����.";
		}
		Interface::menu3();
		break;
	case '6':
		cout << "\n������� ID: " << endl;
		cin >> searchID;
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
			if (searchID == (*it).get_ID()
				&& searchSerialNumber == (*it).get_serialNumber()
				&& searchModel == (*it).get_Model()
				&& searchSerialNumber == (*it).get_serialNumber()
				&& searchInventoryNumber == (*it).get_inventoryNumber())
			{
				if (!found_one)
				{
					cout << "\n������� �����: ";
					Interface::getHeader();
					found_one = true;
				}
				(*it).display();
			}
		}
		if (!found_one)
		{
			cout << "\n�� ������� ������ �����.";
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
	cout << "\n1) ������ ����� ����������"
		<< "\n2) ������������� ����� �� ID"
		<< "\n3) ������������� ����� �� ���� ������������"
		<< "\n0) ���������"
		<< "\n��� �����: ";

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
	cout << "\n������� ID ��������, ������� ������ ��������: " << endl;
	cin >> id;
	if (data.search(id) == true)
	{
		string _TypeofEqiup, _Model, _SerialNumber;
		long _InventoryNumber;

		cout << "\n������� ��� ������������: " << endl;
		cin >> _TypeofEqiup;
		cout << "\n������� ������ ������������: " << endl;
		cin >> _Model;
		cout << "\n������� �������� �����: " << endl;
		cin >> _SerialNumber;
		cout << "\n������� ����������� �����: " << endl;
		cin >> _InventoryNumber;

		auto account = Account(id, _TypeofEqiup, _Model, _SerialNumber, _InventoryNumber);
		data.edit(account);
		data.save();
		cout << "�������������� ����������� �������" << endl;
	}
	else
		cout << "������ �������� ���." << endl;
	Interface::menu2();
}
