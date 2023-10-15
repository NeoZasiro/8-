#pragma once
#pragma once
#include <iostream>
using namespace std;

class Polis
{
protected:
	static inline int id;
	struct polisInfo
	{
		int polisNumber;
		string firstName;
		string lastName;
		string validity;
	} InfoPolis;
public:
	Polis(string firstName, string lastName, string validity)
		: InfoPolis{ id++, firstName, lastName, validity }
	{
		cout << "����� ��� �������: " << id - 1 << " ��� ������." << endl;
	}

	~Polis()
	{
		cout << "������ ������ ��� �������: " << InfoPolis.polisNumber << " ���� �������!" << endl;
	}
	bool operator==(string SearchLastName);
	virtual void print()
	{
		cout << "\n����� ������ ����������� ������: " << InfoPolis.polisNumber << endl;
		cout << "���: " << InfoPolis.firstName << endl;
		cout << "�������: " << InfoPolis.lastName << endl;
		cout << "���� �������� ������: " << InfoPolis.validity << endl;
	}
};

bool Polis::operator==(string SearchLastName)
{
	return InfoPolis.lastName == SearchLastName;
}
