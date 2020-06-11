#pragma once
#include "Account.h"
#include <iostream>
#include <vector>
using namespace std;

class Data
{
public:

	Account getVector(int _i);

	int getSize();

	void add(Account account);

	void edit(Account account);

	void remove(int _ID);

	bool search(int _ID);

	void save();

	void load();

	void print();

private:
	vector<Account> vector_acc;
};

