#include <iostream>
#include "List.h"


using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");

	int x, y, z, c = 0;
	List list1;

	while (true)
	{

		cout << "������� ����������� ������ : ";
		cin >> c;
		if (c == 0)
		{

			break;

		}

		do
		{

			cout << "������� ������� x : ";
			cin >> x;

		} 		while (x < 0 || x > 9);

		do
		{
			cout << "������� ������� y : ";
			cin >> y;

		} 		while (y < 0 || y > 9);

		do {
			cout << "������� ������� z : ";
			cin >> z;
		} while (z < 0 || z > 9);
		cout << endl;

		TMonom Monom(x, y, z, c);
		list1.AddToTheList(Monom);

	}

	cout << endl;
	cout << "������� 1: ";
	list1.print();
	cout << endl;

	List list2;

	while (true)
	{

		cout << "������� ����������� ������ : ";
		cin >> c;
		if (c == 0)
		{

			break;

		}
		do {
			cout << "������� ������� x : ";
			cin >> x;
		} while (x < 0 || x > 9);

		do {
			cout << "������� ������� y : ";
			cin >> y;
		} while (y < 0 || y > 9);

		do {
			cout << "������� ������� z : ";
			cin >> z;
		} while (z < 0 || z > 9);

		cout << endl;

		TMonom Monom(x, y, z, c);
		list2.AddToTheList(Monom);
	}

	cout << endl;
	cout << "������� 2: ";
	list2.print();
	cout << endl;
	cout << endl;


	List list3 = list1 + list2;
	cout << "����� ��������� � ����� �������: ";
	list3.print();
	cout << endl;
	cout << endl;
	list1.SumToCurrentPolynomial(list2);

	cout << "����� ��������� � ������ �������: ";
	list1.print();
	cout << endl;
	cout << "������� ������� ��������: ";
	list2.print();
	cout << endl;

	return 0;
}