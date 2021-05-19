#pragma once
#include "TDatLink.h"


class List
{

	TDatLink* First;//������ ����� 
	int ListLen;//���-�� ������� � ������ 

public:

	int GetListLen();
	List();//����������� �� ���������
	TDatLink* Search(int ConvolutionalDegree, bool& Found);//����� 
	void AddToTheList(TMonom Add); //���������� ����� 
	TMonom DeleteToTheList(int index);
	bool TestForEmptiness();
	friend List operator+(const List& Listv1, const List& Listv2);//���������� �������� �������� 
	void print();
	List& operator=(List& list);
	void SumToCurrentPolynomial(List& list);

};
