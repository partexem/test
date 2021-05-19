#pragma once
#include "TDatLink.h"


class List
{

	TDatLink* First;//первое звено 
	int ListLen;//кол-во звеньев в списке 

public:

	int GetListLen();
	List();//конструктор по умолчанию
	TDatLink* Search(int ConvolutionalDegree, bool& Found);//Поиск 
	void AddToTheList(TMonom Add); //добавление звена 
	TMonom DeleteToTheList(int index);
	bool TestForEmptiness();
	friend List operator+(const List& Listv1, const List& Listv2);//перегрузка оператор сложения 
	void print();
	List& operator=(List& list);
	void SumToCurrentPolynomial(List& list);

};
