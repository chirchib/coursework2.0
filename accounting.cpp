#include "accounting.h"
#include <iostream>
#include <iomanip>

void accounting::display() const
{
	cout << endl << setw(20) << left << typeofEqiup
		<< setw(20) << left << Model
		<< setw(20) << left << serialNumber
		<< setw(20) << left << inventoryNumber;
}

string accounting::get_typeofEqiup()
{
	return  typeofEqiup;
}

string accounting::get_Model()
{
	return Model;
}

string accounting::get_serialNumber()
{
	return serialNumber;
}

long accounting::get_inventoryNumber()
{
	return inventoryNumber;
}

void accounting::set_typeofEqiup(string _type)
{
	 typeofEqiup = _type;
}

void accounting::set_Model(string _Model)
{
	Model = _Model;
}

void accounting::set_serialNumber(string _serNum)
{
	serialNumber = _serNum;
}

void accounting::set_inventoryNumber(long _invNum)
{
	inventoryNumber = _invNum;
}

void displayAccount::operator() (const accounting* ptrA) const
{
	ptrA->display();
}