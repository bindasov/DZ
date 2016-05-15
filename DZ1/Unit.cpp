#include "Unit.h"
#include <iostream>


Unit::Unit(string un, int b)
{
	uname = un;
	bsal = b;
}


Unit::~Unit()
{
}

void Unit::ucalc() {
	int u = 0;
	for (int i = 0; i < vec.size(); i++) u = u + vec[i]->salary + vec[i]->rew + vec[i]->tripc*vec[i]->tripm;
	cout << "Money for the unit: " << u << endl;
}

void Unit::rewstat() {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i]->rew > 0) 
			cout << vec[i]->name << " has reward" << endl;
}

void Unit::mulstat() {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i]->mul > 1)
			cout << vec[i]->name << " has mul" << vec[i]->mul << endl;
}

