#pragma once
#include "accounting.h"
#include <iostream>
#include <vector>
using namespace std;

class Data
{
public:
	Data();

	void add(accounting account);

	void save();

	void load();

	void print();

private:
	vector<accounting> vector_acc;
};

