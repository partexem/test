#include "List.h"
#include <iostream>

int List::GetListLen()
{

	return ListLen;

}

List::List()
{

	ListLen = 0;
	First = new TDatLink();//фиктивное звено 
	First->SetpNext(First);

}

TDatLink* List::Search(int ConvolutionalDegree, bool& Found)
{

	Found = false;
	TDatLink* Previous = First;
	TDatLink* Current = Previous->GetpNext();

	while (Current != First)
	{

		if (Current->GetMonom().GetConvolutionalDegree() > ConvolutionalDegree)
		{

			Previous = Current;
			Current = Current->GetpNext();

		}
		else if (Current->GetMonom().GetConvolutionalDegree() < ConvolutionalDegree)
		{

			break;

		}
		else if (Current->GetMonom().GetConvolutionalDegree() == ConvolutionalDegree)
		{

			Found = true;
			break;

		}

	}

	return Previous;
}

void List::AddToTheList(TMonom AddMonom)
{

	bool Add;
	TDatLink* Previous = Search(AddMonom.GetConvolutionalDegree(), Add);

	if (Add == true)
	{

		TMonom Result = Previous->GetpNext()->GetMonom();
		if (Result.GetCoefficient() + AddMonom.GetCoefficient() != 0)
		{

			Result.SetCoefficient(Result.GetCoefficient() + AddMonom.GetCoefficient());
			Previous->GetpNext()->SetMonom(Result);

		}
		else
		{

			TDatLink* Removable = Previous->GetpNext();
			Previous->SetpNext(Removable->GetpNext());
			delete Removable;
			ListLen -= 1;

		}
	}
	else
	{

		TDatLink* NewLink = new TDatLink(AddMonom);
		NewLink->SetpNext(Previous->GetpNext());
		Previous->SetpNext(NewLink);
		ListLen += 1;

	}

}

TMonom List::DeleteToTheList(int index)
{

	TMonom Res;
	TDatLink* Previos = First;
	TDatLink* Removable = First;

	for (int i = 0; i <= index; i++)
	{

		Previos = Removable;
		Removable = Removable->GetpNext();

	}

	Previos->SetpNext(Removable->GetpNext());
	Res = Removable->GetMonom();
	delete Removable;
	ListLen -= 1;
	return Res;

}

bool List::TestForEmptiness()
{

	if (ListLen == 0)
	{

		return true;

	}
	else
		return false;

}

List operator+(const List& Listv1, const List& Listv2)
{

	List ResList;
	TDatLink* LinkListv1 = Listv1.First->GetpNext();
	TDatLink* LinkListv2 = Listv2.First->GetpNext();
	TDatLink* LinkResList = ResList.First;

	while (Listv1.First != LinkListv1 || Listv2.First != LinkListv2)
	{

		if (LinkListv1->GetMonom().GetConvolutionalDegree() > LinkListv2->GetMonom().GetConvolutionalDegree())
		{

			LinkResList->SetpNext(new TDatLink(LinkListv1->GetMonom()));
			ResList.ListLen += 1;

			LinkListv1 = LinkListv1->GetpNext();
			LinkResList = LinkResList->GetpNext();
			LinkResList->SetpNext(ResList.First);

		}
		else if (LinkListv1->GetMonom().GetConvolutionalDegree() < LinkListv2->GetMonom().GetConvolutionalDegree())
		{

			LinkResList->SetpNext(new TDatLink(LinkListv2->GetMonom()));
			ResList.ListLen += 1;

			LinkListv2 = LinkListv2->GetpNext();
			LinkResList = LinkResList->GetpNext();
			LinkResList->SetpNext(ResList.First);

		}
		else
		{

			if (LinkListv1->GetMonom().GetCoefficient() + LinkListv2->GetMonom().GetCoefficient() != 0)
			{

				TMonom resMonom = LinkListv1->GetMonom();
				resMonom.SetCoefficient(LinkListv1->GetMonom().GetCoefficient() + LinkListv2->GetMonom().GetCoefficient());
				LinkResList->SetpNext(new TDatLink(resMonom));
				ResList.ListLen += 1;

				LinkListv1 = LinkListv1->GetpNext();
				LinkListv2 = LinkListv2->GetpNext();
				LinkResList = LinkResList->GetpNext();
				LinkResList->SetpNext(ResList.First);

			}
			else
			{

				LinkListv1 = LinkListv1->GetpNext();
				LinkListv2 = LinkListv2->GetpNext();

			}
		}
	}

	return ResList;

}

void List::print()
{
	using namespace std;

	TDatLink* per = First->GetpNext();
	if (!GetListLen())
	{
		cout << "0";
		return;
	}
	while (per != First)
	{
		if (per->GetMonom().GetCoefficient() < 0)
		{

			cout << "  " << per->GetMonom().GetCoefficient() << "*" << "x^" << per->GetMonom().getVariableDegree(variableDegree::x) << " y^" << per->GetMonom().getVariableDegree(variableDegree::y) << " z^" << per->GetMonom().getVariableDegree(variableDegree::z);

		}
		else
		{
			if (per == First->GetpNext())
			{

				cout << per->GetMonom().GetCoefficient() << "*" << "x^" << per->GetMonom().getVariableDegree(variableDegree::x) << " y^" << per->GetMonom().getVariableDegree(variableDegree::y) << " z^" << per->GetMonom().getVariableDegree(variableDegree::z);

			}
			else
			{

				cout << " + " << per->GetMonom().GetCoefficient() << "*" << "x^" << per->GetMonom().getVariableDegree(variableDegree::x) << " y^" << per->GetMonom().getVariableDegree(variableDegree::y) << " z^" << per->GetMonom().getVariableDegree(variableDegree::z);

			}
		}

		per = per->GetpNext();

	}

}

List& List::operator=(List& list)
{


	if (this == &list) {
		return *this;
	}

	TDatLink* per = list.First->GetpNext();
	while (per != list.First)
	{

		this->AddToTheList(per->GetMonom());
		per = per->GetpNext();

	}

	this->ListLen = list.ListLen;

	return *this;
}

void List::SumToCurrentPolynomial(List& list)
{

	TDatLink* LinkPrev1 = this->First;
	TDatLink* LinkPrev2 = list.First;
	TDatLink* LinkCur1 = this->First->GetpNext();
	TDatLink* LinkCur2 = list.First->GetpNext();


	while (LinkCur2 != list.First)
	{

		if (LinkCur1->GetMonom().GetConvolutionalDegree() > LinkCur2->GetMonom().GetConvolutionalDegree())
		{

			LinkPrev1 = LinkCur1;
			LinkCur1 = LinkCur1->GetpNext();

		}
		else if (LinkCur1->GetMonom().GetConvolutionalDegree() < LinkCur2->GetMonom().GetConvolutionalDegree())
		{

			LinkPrev1->SetpNext(LinkCur2);
			LinkPrev2->SetpNext(LinkCur2->GetpNext());
			LinkCur2->SetpNext(LinkCur1);
			LinkPrev1 = LinkCur2;
			LinkCur2 = LinkPrev2->GetpNext();
			this->ListLen += 1;
			list.ListLen -= 1;

		}
		else
		{

			if (LinkCur1->GetMonom().GetCoefficient() + LinkCur2->GetMonom().GetCoefficient() != 0)
			{

				TMonom res = LinkCur1->GetMonom();

				res.SetCoefficient(LinkCur1->GetMonom().GetCoefficient() + LinkCur2->GetMonom().GetCoefficient());

			}
			else
			{

				LinkPrev1->SetpNext(LinkCur1->GetpNext());
				this->ListLen -= 1;
				delete LinkCur1;

			}

			LinkPrev1 = LinkPrev1;
			LinkCur1 = LinkPrev1->GetpNext();
			LinkPrev2 = LinkCur2;
			LinkCur2 = LinkCur2->GetpNext();
		}
	}


}