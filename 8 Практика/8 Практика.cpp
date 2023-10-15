#include <iostream>
#include <Windows.h>
#include <random>
#include "OMS.h"
#include "House.h"
#include <iomanip>

using namespace std;
using namespace Model;

//Вариант А.
//Задание 1. Для структуры классов, спроектированной на Практических занятиях №5 и №6,
//сначала создать вектор из 1000 объектов какого - либо из производных классов.
//Затем создать второй вектор, в который занести элементы первого вектора в обратном порядке.
//Рассчитать Вычисляемый показатель.
//Задание 2. Добавить в середину вектора 500 элементов и рассчитать Вычисляемый показатель.
//Очистить вектор и убедиться, что он пуст.
//Задание 3. Разработать меню для демонстрации работы программы.

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

	for (int i = 0; i < 1000; i++)
	{
		OMS* omsArray = new OMS(firstName[GetRandomNumber(0, 8)], lastName[GetRandomNumber(0, 8)], validaty[GetRandomNumber(0, 8)], "25.25.25");
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

		/*for (int i = 0; i < 5; i++)
		{
			cout << "myOMS: " << myOMS[i]->GetPolisNumber() << endl;
			cout << "OMSRefresh: " << OMSRefresh[i]->GetPolisNumber() << endl;
		}*/
		searchLastName = ReturnString("Введите фамилию для поиска: ");
		if (searchLastName == "q" || searchLastName == "Q")
		{
			cout << "Количество полюсов на заданную фамилию: " << CountLastName(searchLastName, size(myOMS)) << endl;
		}
	}

}