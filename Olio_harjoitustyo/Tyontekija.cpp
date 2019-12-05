#include "pch.h"
#include "Tyontekija.h"

Tyontekija::~Tyontekija()
{
}

void Tyontekija::setTag(const string & aTag)
{
	tag = aTag;
}

string Tyontekija::getTag() const
{
	return tag;
}

void Tyontekija::setPay(int aPay)
{
	pay = aPay;
}

int Tyontekija::getPay()
{
	return pay;
}
