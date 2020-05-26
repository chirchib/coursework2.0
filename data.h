#pragma once
#include "accounting.h"
#include <iostream>
#include <vector>
class data
{
public:
	void data_vector(string Eqiup, string mod, string serNum, long invNum);

	void AddVector();

	void display_vector();
private:
	vector<accounting*> vector_acc;
};

