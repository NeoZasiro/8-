#pragma once
#include <iostream>
#include "Polis.h"
using namespace std;

namespace Model
{
	class OMS : private Polis
	{
	private:
		struct InfoOms
		{
			string birthDate;
		}Oms;
	public:
		OMS(string firstName, string lastName, string validity, string birthDate)
			: Polis(firstName, lastName, validity), Oms{birthDate}
		{
		}
		~OMS()
		{
			cout << "������ ������ ������ OMS ��� ������� ������ " << InfoPolis.polisNumber << " ���� �������!" << endl;
		}
		void print()
		{
			cout << "\n����� ������ ���: " << InfoPolis.polisNumber << endl;
			cout << "���: " << InfoPolis.firstName << endl;
			cout << "�������: " << InfoPolis.lastName << endl;
			cout << "���� ��������: " << Oms.birthDate << endl;
			cout << "���� �������� ������: " << InfoPolis.validity << endl;
		}
		int GetPolisNumber()
		{
			return InfoPolis.polisNumber;
		}
		string GetLastName()
		{
			return InfoPolis.lastName;
		}
		bool operator==(string SearchLastName);
	};

	bool OMS::operator==(string SearchLastName)
	{
		return InfoPolis.lastName == SearchLastName;
	}
}
