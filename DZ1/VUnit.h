#pragma once
#include <string>
#include "Unit.h"
using namespace std;
/**
class VUnit

vector<Unit*> v - вектор подразделений

Методы класса:

void create(string un, int b);
@nСоздание подразделения с именем "um" и базовой ставкой b

void disband(string un);
@nРасформирование подразделения "un"

void hire(string un, string en);
@nНайм сотрудника с именем "en" в подразделение "un"

void findanddo(string un, string en, int com);
@nФункция поиска сотрудника с именем "en" в подразделении "un" и выполнение действия, зависящего
от цифровой команды
@n 0 - уволить сотрудника
@n 1 - расчитать зарплату
@n 2 - выписать премию
@n 3 - показать историю изменения состояния сотрудника

void promosion(string un, string en, string unm);
@nПереход сотрудника с именем "en" из подразделения "un" в подразделение "unm"

void emplmult(string un, string en, double m);
@nУстановка множителя ставки "m" для сотрудника с именем "en" в подразделении "un"

void empltrip(string un, string en, int s);
@nУчет состояния командировок сотрудника "en" из подразделения "un"
@n 0 - не был
@n 1 - был отправлен
@n2 - вернулся
@n 3 - была оплачена

void ucalc(string un);
@nРасчет заработной платы на подразделение "un"

void rewstat(string un);
@nСтатистика по премируемым сотрудникам подразделения "un"

void mulstat(string un);
@nСтатистика по сотрудникам с определенным множителем ставки подразделения "un"

void printu();
@nПечать названий всех подразделений

void printe(string un);
@nПечать имен всех сотрудником подразделения "un"

void writein(ostream& ost);
@nЗапись в файл

void readfrom(istream& ist);
@nЧтение из файла
*/
class VUnit
{
	vector<Unit*> v;
public:
	VUnit();
	~VUnit();

	void create(string un, int b);
	void disband(string un);
	void hire(string un, string en);
	void findanddo(string un, string en, int com);
	void promosion(string un, string en, string unm);
	void emplmult(string un, string en, double m);
	void empltrip(string un, string en, int s);
	void ucalc(string un);
	void rewstat(string un);
	void mulstat(string un);
	void printu();
	void printe(string un);
	void writein(ostream& ost);
	void readfrom(istream& ist);
};

