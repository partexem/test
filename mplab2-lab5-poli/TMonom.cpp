#include "TMonom.h"

TMonom::TMonom(int x, int y, int z, int c)
{

    Coefficient = c;
    ConvolutionalDegree = Make—onvolutionalDegree(x, y, z);

}

int TMonom::Make—onvolutionalDegree(int x, int y, int z)
{

    return x * 100 + y * 10 + z;

}

int TMonom::GetCoefficient()
{

    return Coefficient;

}

void TMonom::SetCoefficient(int _Coefficient)
{

    Coefficient = _Coefficient;

}

TMonom& TMonom::operator=(TMonom Monom)
{

    if (this == &Monom)
    {

        return *this;

    }

    Coefficient = Monom.Coefficient;
    ConvolutionalDegree = Monom.ConvolutionalDegree;
    return *this;

}

int TMonom::GetConvolutionalDegree()
{

    return ConvolutionalDegree;

}

int TMonom::getVariableDegree(variableDegree variable)
{

    int result = 0;
    switch (variable)
    {

    case variableDegree::x:
        result = ConvolutionalDegree / 100;
        break;
    case variableDegree::y:
        result = ConvolutionalDegree % 100 / 10;
        break;
    case variableDegree::z:
        result = ConvolutionalDegree % 10;
        break;
    default:
        result = -1;

    }

    return result;

}
