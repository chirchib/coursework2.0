#include "data.h"
#include "account.h"
#include <iostream>


#include <vector>
#include <algorithm>
#include <fstream>




using namespace std;


Data::Data()
{
}

void Data::add(Account account)
{
	accounts.push_back(account);
}

void Data::save()
{
	ofstream fp;//Файловый поток записи
	fp.open("file.txt", ios_base::trunc | ios::out);//Открытие файла и очистка его содержимого
	for (auto it : accounts)//Перебор вектора клентов
	{
		int id;
		string typeofEqiup;
		string model;
		string serialNumber;
		long inventoryNumber;
		//Запись в поток
		fp << it.getId() << " ";
		fp << it.getTypeofEqiup() << " ";
		fp << it.getModel() << " ";
		fp << it.getSerialNumber() << " ";
		if ((*(accounts.end() - 1)).getId() == it.getId())fp << it.getInventoryNumber(); //Если последний элемент - не делать переход на новую строку
		else fp << it.getInventoryNumber() << endl;
	}
	fp.close(); //Закрыть файл
}

void Data::load()
{
	ifstream fp;//Файловый поток чтения
	fp.open("file.txt");//Открытие файла

	if (!fp.is_open())
	{
		cout << "Ошибка при открытии файла. Проверьте наличие файла file.txt в папке с программой" << endl;
		system("pause");
		exit(1);
	}

	while (!fp.eof())//Пока не конец файла
	{
		int id;
		string typeofEqiup;
		string model;
		string serialNumber;
		long inventoryNumber;
		

		//Инициализация переменных из файлового потока
		fp >> id;
		fp >> typeofEqiup;
		fp >> model;
		fp >> serialNumber;
		fp >> inventoryNumber;
		//Добавить клиента в базу
		accounts.push_back(Account(id, typeofEqiup, model, serialNumber, inventoryNumber));
	}
	fp.close();//Закрыть файл
}

void Data::print()
{
	for (auto it : accounts)
	{
		it.display();
	}
}

void Data::connectToServer()
{
	setlocale(LC_ALL, "rus");
	ftp = Ftp();

	if (!ftp.connectToHost("testftpserver.ucoz.net", "etestftpserver", "12341234"))//Если подключение не удалось
	{
		cout << "Ошибка загрузки базы данных" << endl;
		exit(GetLastError());//Выйти и вернуть код ошибки
	}
}
//Синхронизация локального файла с сервером
bool Data::saveToServer()
{
	bool cond1 = ftp.cd("/Catalog");
	bool cond2 = ftp.put("file.txt");
	return cond1 && cond2;
}

bool Data::loadFromServer()
{
	bool cond1 = ftp.cd("/Catalog");
	bool cond2 = ftp.get("file.txt");
	return cond1 && cond2;
}
