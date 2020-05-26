#include "data.h"
#include "accounting.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void data::AddVector()
{
	string Type, Mod, SNum;
	long INum;
	system("cls");
	cout << "\n¬ведите тип оборудовани€: ";
	cin >> Type;
	cout << "\n¬ведите модель";
	cin >> Mod;
	cout << "\n¬ведите серийный номер";
	cin >> SNum;
	cout << "\n¬ведите инвентарный номер";
	cin >> INum;
	data_vector(Type, Mod, SNum, INum);
	return;
}

void data::data_vector(string Eqiup, string mod, string serNum, long invNum)
{
	accounting* account = new accounting(Eqiup, mod, serNum, invNum);
	vector_acc.push_back(account);
	delete account;
}

void data::display_vector()
{
	for_each(vector_acc.begin(),
		vector_acc.end(), displayAccount());
	return;
}