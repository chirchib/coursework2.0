#pragma once




#include <iostream>
#include <vector>

#include "account.h"



using namespace std;

class Data
{
public:
	Data();

	void add(Account account);

	void save();

	void load();

	void print();

private:
	vector<Account> accounts;

};

