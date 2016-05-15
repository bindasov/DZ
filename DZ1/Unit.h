#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
using namespace std;
/**
class Unit
Класс - вектор сотрудников

uname - название подразделения

bsal - зарплата на подразделение

vector<Employee*> vec - вектор сотрудников

Методы класса:

void ucalc();
@nРасчет заработной платы на подразделение

void rewstat();
@nСтатистика по премируемым сотрудникам

void mulstat();
@nСтатистика по сотрудникам с определенным множителем ставки
*/
class Unit
{
	string uname;
	int bsal;
	vector<Employee*> vec;
public:
	Unit(string un, int b);
	~Unit();

	void ucalc();
	void rewstat();
	void mulstat();
	friend class VUnit;
};

