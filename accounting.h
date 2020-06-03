#pragma once
#include <iostream>
using namespace std;
class accounting
{
public:
	accounting() : typeofEqiup(""),
		Model(""), serialNumber(""), inventoryNumber(0)
	{ }

	accounting(string Eqiup, string mod, string serNum, long invNum) :
		typeofEqiup(Eqiup), Model(mod), serialNumber(serNum), inventoryNumber(invNum)
	{ }

	void display() const;

	void set_typeofEqiup(string _type);
	
	void set_Model(string _Model);
	
	void set_serialNumber(string _serNum);

	void set_inventoryNumber(long _invNum);

	string get_typeofEqiup();

	string get_Model();

	string get_serialNumber();

	long get_inventoryNumber();

private:
	string typeofEqiup;
	string Model;
	string serialNumber;
	long inventoryNumber;
};

class displayAccount
{
public:
	void operator() (const accounting* ptrA) const;
};
