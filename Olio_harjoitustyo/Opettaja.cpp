#include "pch.h"
#include "Opettaja.h"

Opettaja::~Opettaja()
{
}

string Opettaja::getAla() const
{
	return "Ala: " + opetusAla;
}

void Opettaja::setAla(const string & ala)
{
	opetusAla = ala;
}

void Opettaja::tulostaTiedot() 
{
	cout << "Ala: " << opetusAla << endl;			//string
	cout << "Tunnus: " << getTag() << endl;			//string
	cout << "Palkka: " << getPay() << endl;			//int
	cout << "Etunimi: " << getFName() << endl;		//string
	cout << "Sukunimi: " << getLName() << endl;		//string
	cout << "Osoite: " << getAdress() << endl;		//string
	cout << "Puh: " << getNumber() << endl;			//int
}
