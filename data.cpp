#include "data.h"
#include "accounting.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

accounting Data::getVector(int _i)
{
	return vector_acc[_i];
}

int Data::getSize()
{
	return vector_acc.size();
}

void Data::add(accounting account)
{
	vector_acc.push_back(account);
}

void Data::edit(accounting account)
{
	for (auto it = vector_acc.begin(); it != vector_acc.end(); ++it)
	{
		if ((*it).get_ID() == account.get_ID())
		{
			*it = account;
		}
	}
}

void Data::remove(int _ID)
{
	for (auto it = vector_acc.begin(); it != vector_acc.end(); ++it)
	{
		if (_ID == (*it).get_ID())
		{
			vector_acc.erase(it);
		}
	}
}

bool Data::search(int _ID)
{
	for (auto it = vector_acc.begin(); it != vector_acc.end(); ++it)
	{
		if (_ID == (*it).get_ID())
		{
			return true;
		}
	}
	return false;
}

void Data::save()
{
	ofstream fp;//�������� ����� ������
	fp.open("file.txt", ios_base::trunc | ios::out);//�������� ����� � ������� ��� �����������
	for (auto it : vector_acc)//������� ������� �������
	{
		//������ � �����
		fp << it.get_ID() << " ";
		fp << it.get_typeofEqiup() << " ";
		fp << it.get_Model() << " ";
		fp << it.get_serialNumber() << " ";
		if ((*(vector_acc.end() - 1)).get_typeofEqiup() == it.get_typeofEqiup())fp << it.get_inventoryNumber(); //���� ��������� ������� - �� ������ ������� �� ����� ������
		else fp << it.get_inventoryNumber() << endl;
	}
	fp.close(); //������� ����
}

void Data::load()
{
	ifstream fp;//�������� ����� ������
	fp.open("file.txt");//�������� �����
	while (!fp.eof())//���� �� ����� �����
	{
		int id;
		string Eqiup, mod, serNum;
		long invNum;

		//������������� ���������� �� ��������� ������
		fp >> id;
		fp >> Eqiup;
		fp >> mod;
		fp >> serNum;
		fp >> invNum;
		//�������� ������� � ����
		vector_acc.push_back(accounting(id, Eqiup, mod, serNum, invNum));
	}
	fp.close();//������� ����
}

void Data::print()
{
	for (auto it : vector_acc)
	{
		it.display();
	}
}