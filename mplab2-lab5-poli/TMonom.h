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

	TMonom(int x = 0, int y = 0, int z = -1, int c = 0);//�����������
	int Make�onvolutionalDegree(int x, int y, int z);//������� ���������� �������
	int GetCoefficient();//�������� ���������� ������ 
	void SetCoefficient(int _Coefficient);//���������� ���������� ������ 
	TMonom& operator=(TMonom Monom);//���������� ���������
	int GetConvolutionalDegree();
	int getVariableDegree(variableDegree variable);

};
