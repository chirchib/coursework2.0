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