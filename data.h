#pragma once




#include <iostream>
#include <vector>

#include "account.h"

#ifdef _WIN32
#pragma comment(lib, "ftp32.lib")
#endif

#ifdef _WIN64
#pragma comment(lib, "ftp64.lib")
#endif



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

	//void sortID(Account account);

	bool saveToServer();

	bool loadFromServer();


private:
	vector<Account> accounts;
	Ftp ftp;
};

