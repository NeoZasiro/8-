#include <iostream>
#include <Windows.h>
#include <random>
#include "OMS.h"
#include "House.h"
#include <iomanip>

using namespace std;
using namespace Model;
using namespace Polis;

vector<OMS*> myOMS;
vector<OMS*> OMSRefresh;

int GetRandomNumber(int min, int max)
{
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<int> distribution(min, max);

	int randomValue;

	randomValue = distribution(generator);

	return randomValue;
}

string ReturnString(string text)
{
	cout << text;
	cin >> text;
	return text;
}

int CountLastName(string searchLastName, int numPolis)
{
	int count{};
	for (int k = 0; k < numPolis; k++)
	{
		if (myOMS[k]->GetLastName() == searchLastName)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = 0;

	string firstName[9] = { "Александр" , "Леонид" , "Сергей", "Иван", "Фёдор", "Константин", "Даниил" , "Кирилл" , "Денис" };
	string lastName[9] = { "Кузнецов", "Иванов", "Проценко", "Соколов", "Коннов", "Проценко", "Штоколкин", "Моховиков", "Заостровцев" };
	string validaty[9] = { "01.01.2024", "02.05.2025", "06.07.2026", "03.03.2025", "04.05.2027", "12.12.2023", "07.07.2023", "05.05.2026", "01.09.2028" };
	string birthDate[9] = { "24.01.1995", "25.05.1997", "14.06.2004", "30.07.2005", "11.11.1999", "24.03.2006", "19.03.2000", "20.08.2002", "20.09.2007" };
	for (int i = 0; i < 1000; i++)
	{
		OMS* omsArray = new OMS(firstName[GetRandomNumber(0, 8)], lastName[GetRandomNumber(0, 8)], validaty[GetRandomNumber(0, 8)], birthDate[GetRandomNumber(0, 8)]);
		myOMS.push_back(omsArray);
	}

	for (int i = 999; i > -1; i--)
	{
		OMSRefresh.push_back(myOMS[i]);
	}

	for (int i = 0; i < 500; i++)
	{
		OMS* omsArray = new OMS(firstName[GetRandomNumber(0, 8)], lastName[GetRandomNumber(0, 8)], validaty[GetRandomNumber(0, 8)], "25.25.25");
		int position = i + 500;
		auto iter1 = myOMS.cbegin() + 500;
		myOMS.insert(iter1 + i, omsArray);
	}
	string searchLastName = "";

	while (searchLastName != "q" && searchLastName != "Q")
	{
		searchLastName = ReturnString("Введите фамилию для поиска: ");
		if (searchLastName != "q" && searchLastName != "Q")
		{
			cout << "Количество полюсов на заданную фамилию: " << CountLastName(searchLastName, size(myOMS)) << endl;
		}
	}
	for (int i = 0; i < 1500; i++)
	{
		cout << "\n" << setfill('-') << setw(60) << " " << endl;
		delete myOMS[i];
	}
	myOMS.clear();
	cout << "Size myOMS = " << size(myOMS) << endl;
	OMSRefresh.clear();
}