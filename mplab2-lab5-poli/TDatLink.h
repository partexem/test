#pragma once
#include "TMonom.h"


class TDatLink
{
	TMonom Monom;
	TDatLink* pNext;

public:

	TDatLink* GetpNext();//�������� ��������� �� ��������� �����
	void SetpNext(TDatLink* _pNext);//���������� ��������� �� ��������� �����
	TMonom GetMonom();//�������� ����� 
	void SetMonom(TMonom _Monom);//���������� ����� 
	TDatLink(TMonom _Monom = TMonom(), TDatLink* _pNext = nullptr);//�����������

};
