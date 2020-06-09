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

	
	void connect()
	{
		/*
		auto ftp = Ftp("testftpserver.ucoz.net", "etestftpserver", "12341234");
		auto cd = ftp.cd("/Catalog");
		auto get = ftp.get("file.txt");

		if (get)
		{
			cout << "Файл загрузился с сервера" << endl;
		}
		else
		{
			cout << "Не удалось загрузить файл с сервера. Будет загружена локальная копия" << endl;
		}
		system("pause");
		*/
	}


	void save();

	void load();

	void print();

private:
	vector<Account> accounts;

};

