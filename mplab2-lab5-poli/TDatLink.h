#pragma once
#include "TMonom.h"


class TDatLink
{
	TMonom Monom;
	TDatLink* pNext;

public:

	TDatLink* GetpNext();//получить указатель на следуюзее звено
	void SetpNext(TDatLink* _pNext);//установить указатель на следуюзее звено
	TMonom GetMonom();//получить моном 
	void SetMonom(TMonom _Monom);//установить моном 
	TDatLink(TMonom _Monom = TMonom(), TDatLink* _pNext = nullptr);//конструктор

};
