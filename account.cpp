#include "account.h"
#include <iostream>
#include <iomanip>

void Account::display() const
{
	cout << endl << setw(20) << left << typeofEqiup
		<< setw(20) << left << model
		<< setw(20) << left << serialNumber
		<< setw(20) << left << inventoryNumber;
}

int Account::getId()
{
	return id;
}

string Account::getTypeofEqiup()
{
	return  typeofEqiup;
}

string Account::getModel()
{
	return model;
}

string Account::getSerialNumber()
{
	return serialNumber;
}

long Account::getInventoryNumber()
{
	return inventoryNumber;
}

void Account::setId(int id)
{
	this->id = id;
}

void Account::setTypeofEqiup(string _type)
{
	 typeofEqiup = _type;
}

void Account::setModel(string _Model)
{
	model = _Model;
}

void Account::setSerialNumber(string _serNum)
{
	serialNumber = _serNum;
}

void Account::setInventoryNumber(long _invNum)
{
	inventoryNumber = _invNum;
}

