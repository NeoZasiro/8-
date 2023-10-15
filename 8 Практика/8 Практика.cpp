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

int GetRandomNumber(int min, int max)
{
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<int> distribution(min, max);

	int randomValue;

	randomValue = distribution(generator);

	return randomValue;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<OMS> myOMS;
	
	string firstName[9] = { "Александр" , "Леонид" , "Сергей", "Иван", "Фёдор", "Константин", "Даниил" , "Кирилл" , "Денис" };
	string lastName[9] = { "Кузнецов", "Иванов", "Проценко", "Соколов", "Коннов", "Проценко", "Штоколкин", "Моховиков", "Заостровцев" };
	string validaty[9] = { "01.01.2024", "02.05.2025", "06.07.2026", "03.03.2025", "04.05.2027", "12.12.2023", "07.07.2023", "05.05.2026", "01.09.2028" };

		myOMS.push_back(OMS(firstName[GetRandomNumber(0, 8)], lastName[GetRandomNumber(0, 8)], validaty[GetRandomNumber(0, 10)], "25.25.25"));
		myOMS[0].print();
	
}