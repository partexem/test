#pragma once

enum class variableDegree
{
	x,
	y,
	z
};

class TMonom
{
	int ConvolutionalDegree;
	int Coefficient;

public:

	TMonom(int x = 0, int y = 0, int z = -1, int c = 0);//конструктор
	int MakeСonvolutionalDegree(int x, int y, int z);//функция сверточной степени
	int GetCoefficient();//получить коэфициент монома 
	void SetCoefficient(int _Coefficient);//установить коэфициент монома 
	TMonom& operator=(TMonom Monom);//перегрузка оператора
	int GetConvolutionalDegree();
	int getVariableDegree(variableDegree variable);

};
