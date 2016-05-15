#include "Employee.h"
#include "Unit.h"
#include "VUnit.h"
#include <iostream>
using namespace std;

int main()
{
	VUnit vun;
	string command, str, str1, str2;
	int num;
	double db;
	bool exit = false;
	while (!exit)
	{
		cin >> command;
		if (command == "create")
		{
			cin >> str;
			cin >> num;
			vun.create(str, num);
		}
		if (command == "disband")
		{
			cin >> str;
			vun.disband(str);
		}
		if (command == "hire")
		{
			cin >> str;
			cin >> str1;
			vun.hire(str, str1);
		}
		if (command == "fire")
		{
			cin >> str;
			cin >> str1;
			vun.findanddo(str, str1, 0);
		}
		if (command == "promote")
		{
			cin >> str;
			cin >> str1;
			cin >> str2;
			vun.promosion(str1, str, str2);
		}
		if (command == "settrip")
		{
			cin >> str;
			cin >> str1;
			cin >> num;
			vun.empltrip(str, str1, num);
		}
		if (command == "setmult")
		{
			cin >> str;
			cin >> str1;
			cin >> db;
			vun.emplmult(str, str1, db);
		}
		if (command == "rewstats")
		{
			cin >> str;
			vun.rewstat(str);
		}
		if (command == "multstats")
		{
			cin >> str;
			vun.mulstat(str);
		}
		if (command == "calcsal")
		{
			cin >> str;
			cin >> str1;
			vun.findanddo(str, str1, 1);
		}
		if (command == "calcrew")
		{
			cin >> str;
			cin >> str1;
			vun.findanddo(str, str1, 2);
		}
		if (command == "calcunt")
		{
			cin >> str;
			vun.ucalc(str);
		}
		if (command == "showhistory")
		{
			cin >> str;
			cin >> str1;
			vun.findanddo(str, str1, 3);
		}
		if (command == "load")
		{
			ifstream file("1.txt");
			vun.readfrom(file);
			file.close();
		}
		if (command == "save")
		{
			ofstream file("1.txt");
			vun.writein(file);
			file.close();
		}
		if (command == "listunts") {
			vun.printu();
		}
		if (command == "listempls") {
			cin >> str;
			vun.printe(str);
		}
	}
	return 0;
}