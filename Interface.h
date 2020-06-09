#pragma once

#include "data.h"

class Interface
{
public:
	Interface();

	void mainMenu();

	void menu1(); // Добавление новой информации

	void menu2(); // Редактирование информации

	void menu3(); // Поиск информации

	void menu4(); // Вывод данных(сортировать по ...)

	void getHeader(); // Вывод заголовка таблицы

	void menu11(); // Добавление

	void menu12(); // Удаление

	void menu31(); //Список найденного оборудования по типу оборудования

	void menu32(); //Список найденного оборудования по модели

	void menu33();//Список найденного оборудования по сирийному номеру

	void menu34();//Список найденного оборудования по инвентарному номеру

	void menu35();//Список найденного оборудования по всем пунктам(???)



	static void setCursorVisible(bool visible);



private:
	Data data;

};
