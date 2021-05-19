#include "TDatLink.h"

TDatLink* TDatLink::GetpNext()
{

	return pNext;

}

void TDatLink::SetpNext(TDatLink* _pNext)
{

	pNext = _pNext;

}

TMonom TDatLink::GetMonom()
{

	return Monom;

}

void TDatLink::SetMonom(TMonom _Monom)
{

	Monom = _Monom;

}

TDatLink::TDatLink(TMonom _Monom, TDatLink* _pNext)
{

	Monom = _Monom;
	pNext = _pNext;

}
