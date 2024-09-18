#include <iostream>
#include "application.h"
#include "massiv.h"

using namespace std;

int application::choice()
{
	int n = 0;
	bool h = true;
	int ap;
	cout << "������� ������ �������:\t";
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
			cout << "������� ����� ���������� ���������� � �������: \t";
			int num;
			cin >> num;
			n = num;
			mass.changeSize(num);
			mass.print();
			break;
		case 5:
			mass.print();
			cout << "\n������� ������ ����� ������� ������ ��������: \t";
			int numb;
			cin >> numb;
			if (numb > n - 1)
			{
				cout << "�� ��������� ����� ��������� � �������!\n";
				break;
			}
			int ind;
			cout << "\n������� ����� �����: \t";
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
			cout << "�� ������� ������� �������� ����";
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
	cout << "�������� ��������" << '\n';
	cout << "1) ���� � ������� ��������" << '\n';
	cout << "2) ������ �������� � ������������������� ���������� (���) � ����� ����������� �������" << '\n';
	cout << "3) ���������� ��������� ������� �� ����������� ��� ��������" << '\n';
	cout << "4) ��������� ����������� �������" << '\n';
	cout << "5) ��������� �������� ���������� �������� ������� �� �������" << '\n';
	cout << "6) ����� ��������� �������" << '\n';
	cout << "7) �����" << '\n';
	cout << "������� ����� ������� \n����� ������� �������� ����� ������� ���������� ����� ��������� �����\n";
	cin >> enter;
	return enter;
}