#include "pch.h"
#include "Opiskelija.h"


void Opiskelija::setStudNumber(const string&  aNumber)
{
	studNumber = aNumber;
}

string Opiskelija::getStudNumber() const
{
	return studNumber;
}

void Opiskelija::tulostaTiedot()
{
	cout << "Opiskelija numero: " << getStudNumber() << endl;
	cout << "Etunimi: " << getFName() << endl;
	cout << "Sukunimi: " << getLName() << endl;
	cout << "Osoite: " << getAdress() << endl;
	cout << "Puh: " << getNumber() << endl;
}
