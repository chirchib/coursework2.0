#pragma once




#include <iostream>
#include <vector>

#include "account.h"

#pragma comment(lib, "ftp.lib")

#include "ftp.h"

using namespace std;

class Data
{
public:
	Data();

	void add(Account account);

	void save();

	void load();

	void print();

	void connectToServer();

	bool saveToServer();

	bool loadFromServer();


private:
	vector<Account> accounts;
	Ftp ftp;
};

