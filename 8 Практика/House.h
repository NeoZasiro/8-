#pragma once
#include <iostream>
#include "Polis.h"

using namespace std;
using namespace Polis;
namespace Model
{
	class House : public Polis
	{
	private:
		struct HouseInfo
		{
			string adress;
			int square;
			int cost;
			int summa;
		} InfoHouse;
	public:
		House(string firstName, string lastName, string validity, string adress, int square, int cost, int summa)
			: Polis(firstName, lastName, validity), InfoHouse{ adress, square , cost, summa }
		{
		}
		~House()
		{
			cout << "������ ������� House ��� ������� ������: " << InfoPolis.polisNumber << " ���� �������!" << endl;
		}
		void print()
		{
			cout << "\n����� ������ ����������� ������: " << InfoPolis.polisNumber << endl;
			cout << "���: " << InfoPolis.firstName << endl;
			cout << "�������: " << InfoPolis.lastName << endl;
			cout << "����� ������: " << InfoHouse.adress << endl;
			cout << "������� ������: " << InfoHouse.square << endl;
			cout << "����� �����������: " << InfoHouse.summa << endl;
			cout << "��������� �����������: " << InfoHouse.cost << endl;
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
	};
}
