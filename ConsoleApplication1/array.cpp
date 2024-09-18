#include <iostream>
#include "massiv.h"
#include "Tcomplex.h"
#include "number.h"
using namespace std;

void massiv::completion(int m)
{
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < m; i++)
	{
		cin >> elements[i];
	}
}

void massiv::print()
{
	cout << "массив { ";
	for (int i = 0; i < elements.size(); i++)
	{
		cout << elements[i] << " ";
	}
	cout << "}";
}

void massiv::sort()
{
	int size = elements.size();
	int a;
	cout << "Введите \"0\" для обычной сортировки, \"1\" для обратной : \t";
	cin >> a;
	for (int i = 0; i < size / 2; i++)
	{
		for (int c = i; c < size - i - 1; c++)
		{
			if (elements[c] > elements[c + 1])
			{
				swap(elements[c], elements[c + 1]);
			}
		}
		for (int c = size - 2 - i; c >= i; c--)
		{
			if (elements[c] > elements[c + 1])
			{
				swap(elements[c], elements[c + 1]);
			}
		}

	}
	if (a == 1)
	{
		reverse(elements.begin(), elements.end());
	}
}

void massiv::changeSize(int num)
{
	elements.resize(num);
}

void massiv::sko()
{
	int size = elements.size();
	number summ = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		summ = summ + elements[i];
	}
	number firstStep = 1.0 / size;
	number secondStep = firstStep * summ;
	cout << "Результат среднего значения отклонения:\n" << secondStep;
	int sizeN = size - 1;
	number thirdtStep = 1.0 / sizeN;
	number free = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		number space = elements[i] - secondStep;
		number space2 = space * space;
		free = free + space2;
	}

	number forthStep = thirdtStep * free;
	//number fifthStep = sqrt(forthStep);
	cout << "\nРезультат среднеквадратичного значения отклонения:\n" << forthStep;
}
