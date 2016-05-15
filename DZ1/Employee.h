#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const double r = 0.2, t = 0.3;

/**
class Employee
string name - имя сотрудника

string uname - название подразделения

int salary - зарплата сотрудника

int trips - состояние командировки

int tripc - количество командировок

double rew - премия

double tripm - командировочные

double mul - множитель ставки

vector<string> history - история изменения состояния сотрудника

Методы класса:

void calc();
@nРасчет зарплаты сотрудника

void reward();
@nПремирование сотрудника

void mult(double m);
@nУстановка множителя "m" для зарплаты сотрудника

void trip(int s);
@nУстановка состояния "s" командировки сотрудника

void hist();
@nОтображение истории изменения состояния сотрудника

void writein(ostream& ost);
@nЗапись в файл

void readfrom(istream& ist);
@nЧтение из файла
*/
class Employee
{
	string name, uname;
	int salary, trips, tripc;
	double rew, tripm, mul;
	vector<string> history;
public:
	Employee(string n, string u, int usal);
	~Employee();
	void calc();
	void reward();
	void mult(double m);
	void trip(int s);
	void hist();
	void readfrom(istream& ist);
	void writein(ostream& ost);
	friend class Unit;
	friend class VUnit;
};

