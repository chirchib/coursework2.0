#pragma once
#include <iostream>
using namespace std;
class Account
{
public:
	Account() : id(0), typeofEqiup(""),
		model(""), serialNumber(""), inventoryNumber(0)
	{ }

	Account(int id, string eqiup, string mod, string serNum, long invNum) :
		id(id), typeofEqiup(eqiup), model(mod), serialNumber(serNum), inventoryNumber(invNum)
	{ }

	void display() const;


	void setId(int id);

	void setTypeofEqiup(string _type);
	
	void setModel(string _Model);
	
	void setSerialNumber(string _serNum);

	void setInventoryNumber(long _invNum);


	int getId();

	string getTypeofEqiup();

	string getModel();

	string getSerialNumber();

	long getInventoryNumber();

	void operator ()()
	{
		display();
	}


private:
	int id;
	string typeofEqiup;
	string model;
	string serialNumber;
	long inventoryNumber;
};
