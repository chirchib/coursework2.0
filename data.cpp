#include "data.h"
#include "accounting.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void Data::add(accounting account)
{
	vector_acc.push_back(account);
}

void Data::save()
{
	ofstream fp;//�������� ����� ������
	fp.open("file.txt", ios_base::trunc | ios::out);//�������� ����� � ������� ��� �����������
	for (auto it : vector_acc)//������� ������� �������
	{
		//������ � �����
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
		string Eqiup, mod, serNum;
		long invNum;

		//������������� ���������� �� ��������� ������
		fp >> Eqiup;
		fp >> mod;
		fp >> serNum;
		fp >> invNum;
		//�������� ������� � ����
		vector_acc.push_back(accounting(Eqiup, mod, serNum, invNum));
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