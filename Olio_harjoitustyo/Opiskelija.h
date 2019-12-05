#pragma once
#include "Henkilo.h"
#include<iostream>

class Opiskelija : public Henkilo
{
public:
	Opiskelija() : studNumber("") {};
	Opiskelija(const string& aFname, const string& aLName) : Henkilo(aFname, aLName) {};
	Opiskelija(const string& aFName, const string& aLName, const string& aAdress, int aNumber, const string& aStudNumber)
		: Henkilo (aFName,aLName, aAdress, aNumber), studNumber(aStudNumber){}
	~Opiskelija() {};

	void setStudNumber(const string& aNumber);
	string getStudNumber() const;
	void tulostaTiedot();
	

private:
	string studNumber;
};

