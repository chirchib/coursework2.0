#include <iostream>
#include <vector>
#include "accounting.h"
using namespace std;

void data_vector(string Eqiup, string mod, string serNum, long invNum)
{
	vector<accounting*> vector_acc;
	accounting* account = new accounting(Eqiup, mod, serNum, invNum);
	
	vector_acc.push_back(account);
	delete account; 
}

void AddVector()
{
	string Type, Mod, SNum;
	long INum;
	system("cls");
	cout << "\n������� ��� ������������: ";
	cin >> Type;
	cout << "\n������� ������";
	cin >> Mod;
	cout << "\n������� �������� �����";
	cin >> SNum;
	cout << "\n������� ����������� �����";
	cin >> INum;
	data_vector(Type, Mod, SNum, INum);
	return;
}