#pragma once
#include <iostream>
using namespace std;
class accounting
{
public:
	accounting() : ID(0), typeofEqiup(""),
		Model(""), serialNumber(""), inventoryNumber(0)
	{ }

	accounting(int Id, string Eqiup, string mod, string serNum, long invNum) : 
		ID(Id), typeofEqiup(Eqiup), Model(mod), serialNumber(serNum), inventoryNumber(invNum)
	{ }

	void display() const;

	void set_ID(int _Id);
	
	void set_typeofEqiup(string _type);
	
	void set_Model(string _Model);
	
	void set_serialNumber(string _serNum);

	void set_inventoryNumber(long _invNum);

	int get_ID();

	string get_typeofEqiup();

	string get_Model();

	string get_serialNumber();

	long get_inventoryNumber();

private:
	int ID;
	string typeofEqiup;
	string Model;
	string serialNumber;
	long inventoryNumber;
};
