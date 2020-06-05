#pragma once
#include "data.h"
using namespace std;
class UserInterface
{
public:
	
	UserInterface();

	void main_menu();

	~UserInterface();

private:

	Data data = Data();

	void menu1(); // Добавление новой информации

	void menu2(); // Редактирование информации

	void menu3(); // Поиск информации

	void menu4(); // Вывод данных(сортировать по ...)

	void get_header(); // Вывод заголовка таблицы

	void menu1_1(); // Добавление

	void menu1_2(); // Удаление
};