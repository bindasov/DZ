#include "VUnit.h"
#include <iostream>


VUnit::VUnit()
{
}


VUnit::~VUnit()
{ // в v указатели на Unit. Утечка.
}

void VUnit::create(string un, int b) {
	v.push_back(new Unit(un, b));
};

void VUnit::disband(string un) {
	bool b = false;
	for (int i = 0; i < v.size(); i++)
		if (v[i]->uname == un) {
			b = true;
			v.erase(v.begin() + i);
		}
	if (!b) cout << "No such unit" << endl; // exception!
};

void VUnit::hire(string un, string en) {
	bool b = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->uname == un) {
			v[i]->vec.push_back(new Employee(en, un, v[i]->bsal));
			b = true;
		}
	}
	if (!b) cout << "No such unit" << endl;
}

void VUnit::findanddo(string un, string en, int com) {
	bool b = false, c = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->uname == un) {
			b = true;
			for (int j = 0; j < v[i]->vec.size(); j++)
				if (v[i]->vec[j]->name == en) {
					c = true;
					switch (com) {
					case 0: v[i]->vec.erase(v[i]->vec.begin() + j); break;
					case 1: v[i]->vec[j]->calc(); break;
					case 2: v[i]->vec[j]->reward(); break;
					case 3: v[i]->vec[j]->hist();
					}
				}
		}
	}
	if (!b) cout << "No such unit" << endl;
	if (!c) cout << "No such employee" << endl;
}

void VUnit::promosion(string un, string en, string unm) {
	bool b = false, c = false, d = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->uname == un) { // видел у Тарасова в лабе, не вникал, можно упростить.
			b = true;
			for (int j = 0; j < v[i]->vec.size(); j++)
				if (v[i]->vec[j]->name == en) {
					c = true;
					for (int k = 0; k < v.size(); k++) {
						if (v[k]->uname == unm) {
							d = true;
							v[k]->vec.push_back(new Employee(en, unm, v[k]->bsal));
							v[k]->vec[j]->history.push_back("The employee was promoted");
						}
					}
					v[i]->vec.erase(v[i]->vec.begin() + j);
				}
		}
	}
	if (!b || !d) cout << "No such unit" << endl;
	else if (!c) cout << "No such employee" << endl;
	
}

void VUnit::emplmult(string un, string en, double m) {
	bool b = false, c = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->uname == un) {
			b = true;
			for (int j = 0; j < v[i]->vec.size(); j++)
				if (v[i]->vec[j]->name == en) {
					c = true;
					v[i]->vec[j]->mult(m);
				}
		}
	}
	if (!b) cout << "No such unit" << endl;
	else if (!c) cout << "No such employee" << endl;
}

void VUnit::empltrip(string un, string en, int s) {
	bool b = false, c = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->uname == un) {
			b = true;
			for (int j = 0; j < v[i]->vec.size(); j++)
				if (v[i]->vec[j]->name == en) {
					c = true;
					v[i]->vec[j]->trip(s);
				}
		}
	}
	if (!b) cout << "No such unit" << endl;
	else if (!c) cout << "No such employee" << endl;
}

void VUnit::ucalc(string un) {
	for (int i = 0; i < v.size(); i++)
		if (v[i]->uname == un) v[i]->ucalc();
}

void VUnit::rewstat(string un) {
	for (int i = 0; i < v.size(); i++)
		if (v[i]->uname == un) v[i]->rewstat();
}

void VUnit::mulstat(string un) {
	for (int i = 0; i < v.size(); i++)
		if (v[i]->uname == un) v[i]->mulstat();
}

void VUnit::printu() {
	for (int i = 0; i < v.size(); i++)
		cout << v[i]->uname << endl;
}
void VUnit::printe(string un) {
	for (int i=0; i<v.size(); i++)
		if (v[i]->uname == un) {
			cout << "Unit: " << v[i]->uname << endl;
			for (int j = 0; j < v[i]->vec.size(); j++)
				cout << v[i]->vec[j]->name << endl;
		}
}

void VUnit::writein(ostream& ost) {
	ost << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		ost << v[i]->uname << " " << v[i]->bsal << " " << v[i]->vec.size() << endl;
		for (int j = 0; j < v[i]->vec.size(); j++) v[i]->vec[j]->writein(ost);
	}
}

void VUnit::readfrom(istream& ist) {
	string str;
	int size, size1, sal;
	ist >> size;
	for (int i = 0; i < size; i++) {
		ist >> str >> sal >> size1;
		v.push_back(new Unit(str, sal));
		for (int j = 0; j < size1; j++) {
			v[i]->vec.push_back(new Employee(" ", " ", v[i]->bsal));
			v[i]->vec[j]->readfrom(ist);
		}
	}
}
