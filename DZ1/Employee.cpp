#include "Employee.h"
#include <iostream>

Employee::Employee(string n, string u, int usal)
{
	name = n;
	uname = u;
	salary = usal;
	rew = 0;
	tripm = 0;
	trips = 0;
	tripc = 0;
	mul = 1;
}

Employee::~Employee()
{
	history.clear(); // оно же разрушится. зачем?
}

void Employee::calc() {
	cout << "Employee: " << name << endl;
	cout << "Salary: " << mul*salary << endl;
	cout << "Reward: " << rew << endl;
	cout << "Trip money: " << tripc*tripm << " for " << tripc << " trips" << endl;
	cout << "Total: " << mul*salary + rew + tripc*tripm << endl;
}

void Employee::reward() {
	rew = r*salary;
	cout << name << " was rewarded" << endl;
	history.push_back(" was rewarded");
}

void Employee::mult(double m) {
	if (m > 1) {
		mul = m;
		cout << name << " got a new mult" << endl;
		history.push_back(" got a new mult");
	}
	else cout << "You can't set less than 1 mult"; // студент обычно знает, что еще как может)
};

void Employee::trip(int s) {
	trips = s;
	if (s == 1) {
		cout << name << " was sent" << endl;
		history.push_back(" was sent to a trip");
	}
	if (s == 2) {
		cout << name << " came back." << endl;
		history.push_back(" came back");
		tripc++;
	}
	if (s == 3) {
		tripm += t*salary;
		cout << name << " got money for his trip" << endl;
		history.push_back(" got money for his trip");
	};
};

void Employee::hist() {
	for (int i = 0; i < history.size(); i++) {
		cout << name << history[i] << endl;
	}
};

void Employee::readfrom(istream& ist) {
	ist >> name >> uname >> salary >> rew >> tripm >> trips >> tripc >> mul;

}

void Employee::writein(ostream& ost) {
	ost << name << " " << uname << " " << salary << " " << rew << " " << tripm << " " << trips << " " << tripc << " " << mul << endl;
};