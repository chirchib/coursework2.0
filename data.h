#pragma once
#include "accounting.h"
#include <iostream>
#include <vector>
using namespace std;

class Data
{
public:

	accounting getVector(int _i);

	int getSize();

	void add(accounting account);

	void edit(accounting account);

	void remove(int _ID);

	bool search(int _ID);

	void save();

	void load();

	void print();

private:
	vector<accounting> vector_acc;
};

