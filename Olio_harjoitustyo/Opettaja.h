#pragma once
#include "Tyontekija.h"
#include<iostream>
class Opettaja : public Tyontekija
{
public:
	Opettaja() : opetusAla("") {};
	Opettaja(const string& aFName, const string& aLName) : Tyontekija(aFName, aLName) {};
	Opettaja(const string& aFName, const string& aLName, const string& aAdress, int aNumber, const string& aTag, int aPay, const string& ala)
		: Tyontekija(aFName, aLName, aAdress, aNumber, aTag, aPay), opetusAla(ala) {};
	~Opettaja();

	string getAla() const;
	void setAla(const string& ala);

	void tulostaTiedot();

private:
	string opetusAla;
};

