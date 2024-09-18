#include <iostream>
#include "application.h"
#include "massiv.h"

using namespace std;

int application::choice()
{
	int n = 0;
	bool h = true;
	int ap;
	cout << "Введите размер массива:\t";
	cin >> n;
	massiv mass;
	mass.changeSize(n);
	while (h)
	{
		system("cls");
		ap = menu();
		switch (ap)
		{
		case 1:
			mass.completion(n);
			mass.print();
			break;
		case 2:
			mass.sko();
			break;
		case 3:
			mass.sort();
			mass.print();
			break;
		case 4:
			cout << "Введите новое количество элемментов в массиве: \t";
			int num;
			cin >> num;
			n = num;
			mass.changeSize(num);
			mass.print();
			break;
		case 5:
			mass.print();
			cout << "\nВведите индекс числа которое хотите заменить: \t";
			int numb;
			cin >> numb;
			if (numb > n - 1)
			{
				cout << "Вы превысили число элементов в массиве!\n";
				break;
			}
			int ind;
			cout << "\nВведите новое число: \t";
			cin >> ind;
			mass.elements[numb] = ind;
			mass.print();
			break;
		case 6:
			mass.print();
			break;
		case 7:
			h = false;
			return 0;
		default:
			cout << "Вы выбрали вариант которого нету";
		}
		cout << '\n';
		system("pause");
	}
	return ap;
}

int application::menu()
{
	int enter;
	setlocale(LC_ALL, "RU");
	cout << "Выберите действие" << '\n';
	cout << "1) Ввод с консоли значений" << '\n';
	cout << "2) Расчет среднего и среднеквадратичного отклонения (СКО) и вывод результатов расчета" << '\n';
	cout << "3) Сортировка элементов массива по возрастанию или убыванию" << '\n';
	cout << "4) Изменение размерности массива" << '\n';
	cout << "5) Изменение значения выбранного элемента массива по индексу" << '\n';
	cout << "6) Вывод элементов массива" << '\n';
	cout << "7) Выход" << '\n';
	cout << "Введите номер команды \nПосле каждого действия вывод массива происходит через отдельный пункт\n";
	cin >> enter;
	return enter;
}