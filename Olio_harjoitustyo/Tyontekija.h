#pragma once
#include "Henkilo.h"
class Tyontekija : public Henkilo
{
public:
	Tyontekija() : tag(""), pay(0) {};
	Tyontekija(const string& aFName, const string& aLName) : Henkilo(aFName, aLName) {};
	Tyontekija(const string& aFName, const string& aLName, const string& aAdress, int aNumber, const string& aTag, int aPay)
		:Henkilo(aFName, aLName, aAdress, aNumber), tag(aTag), pay(aPay) {};
	~Tyontekija();

	void setTag(const string& aTag);
	string getTag() const;

	void setPay(int aPay);
	int getPay();

private:
	string tag;
	int pay;
};

