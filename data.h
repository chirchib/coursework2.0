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
			cout << "���� ���������� � �������" << endl;
		}
		else
		{
			cout << "�� ������� ��������� ���� � �������. ����� ��������� ��������� �����" << endl;
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

