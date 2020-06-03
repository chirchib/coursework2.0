#pragma once
#include "accounting.h"
#include <iostream>
#include <vector>
class data
{
public:
//	void data_vector(string Eqiup, string mod, string serNum, long invNum);

	void add(accounting account);

	void save();

	void load();

	void print();

private:
	vector<accounting> vector_acc;
};

