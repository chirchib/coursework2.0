#include "Account.h"
#include <iostream>
#include <iomanip>

void Account::display() const
{
	cout << endl << setw(10) << left << ID
		<< setw(20) << left << typeofEqiup
		<< setw(20) << left << Model
		<< setw(20) << left << serialNumber
		<< setw(20) << left << inventoryNumber;
}

int Account::get_ID()
{
	return ID;
}

string Account::get_typeofEqiup()
{
	return  typeofEqiup;
}

string Account::get_Model()
{
	return Model;
}

string Account::get_serialNumber()
{
	return serialNumber;
}

long Account::get_inventoryNumber()
{
	return inventoryNumber;
}

void Account::set_ID(int _ID)
{
	ID = _ID;
}

void Account::set_typeofEqiup(string _type)
{
	typeofEqiup = _type;
}

void Account::set_Model(string _Model)
{
	Model = _Model;
}

void Account::set_serialNumber(string _serNum)
{
	serialNumber = _serNum;
}

void Account::set_inventoryNumber(long _invNum)
{
	inventoryNumber = _invNum;
}