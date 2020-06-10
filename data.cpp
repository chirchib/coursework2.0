#include "data.h"
#include "account.h"
#include <iostream>


#include <vector>
#include <algorithm>
#include <fstream>




using namespace std;


Data::Data()
{
}

void Data::add(Account account)
{
	accounts.push_back(account);
}

void Data::save()
{
	ofstream fp;//�������� ����� ������
	fp.open("file.txt", ios_base::trunc | ios::out);//�������� ����� � ������� ��� �����������
	for (auto it : accounts)//������� ������� �������
	{
		int id;
		string typeofEqiup;
		string model;
		string serialNumber;
		long inventoryNumber;
		//������ � �����
		fp << it.getId() << " ";
		fp << it.getTypeofEqiup() << " ";
		fp << it.getModel() << " ";
		fp << it.getSerialNumber() << " ";
		if ((*(accounts.end() - 1)).getId() == it.getId())fp << it.getInventoryNumber(); //���� ��������� ������� - �� ������ ������� �� ����� ������
		else fp << it.getInventoryNumber() << endl;
	}
	fp.close(); //������� ����
}

void Data::load()
{
	ifstream fp;//�������� ����� ������
	fp.open("file.txt");//�������� �����

	if (!fp.is_open())
	{
		cout << "������ ��� �������� �����. ��������� ������� ����� file.txt � ����� � ����������" << endl;
		system("pause");
		exit(1);
	}

	while (!fp.eof())//���� �� ����� �����
	{
		int id;
		string typeofEqiup;
		string model;
		string serialNumber;
		long inventoryNumber;
		

		//������������� ���������� �� ��������� ������
		fp >> id;
		fp >> typeofEqiup;
		fp >> model;
		fp >> serialNumber;
		fp >> inventoryNumber;
		//�������� ������� � ����
		accounts.push_back(Account(id, typeofEqiup, model, serialNumber, inventoryNumber));
	}
	fp.close();//������� ����
}

void Data::print()
{
	for (auto it : accounts)
	{
		it.display();
	}
}

void Data::connectToServer()
{
	setlocale(LC_ALL, "rus");
	ftp = Ftp();

	if (!ftp.connectToHost("testftpserver.ucoz.net", "etestftpserver", "12341234"))//���� ����������� �� �������
	{
		cout << "������ �������� ���� ������" << endl;
		exit(GetLastError());//����� � ������� ��� ������
	}
}
//������������� ���������� ����� � ��������
bool Data::saveToServer()
{
	bool cond1 = ftp.cd("/Catalog");
	bool cond2 = ftp.put("file.txt");
	return cond1 && cond2;
}

bool Data::loadFromServer()
{
	bool cond1 = ftp.cd("/Catalog");
	bool cond2 = ftp.get("file.txt");
	return cond1 && cond2;
}
