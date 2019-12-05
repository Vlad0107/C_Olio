#include "pch.h"
#include "Henkilo.h"
#include<iostream>


Henkilo::Henkilo(const string & aFName, const string & aLName, const string & aAdress, int aNumber)
	: fName(aFName), lName(aLName), adress(aAdress), number(aNumber)
{
}


Henkilo::~Henkilo()
{
}

string Henkilo::getFName() const
{
	return fName;
}

void Henkilo::setFname(const string & aFName)
{
	fName = aFName;
}

string Henkilo::getLName() const
{
	return lName;
}

void Henkilo::setLname(const string & aLName)
{
	lName = aLName;
}

string Henkilo::getAdress() const
{
	return adress;
}

void Henkilo::setAdress(const string & aAdress)
{
	adress = aAdress;
}

int Henkilo::getNumber()
{
	return number;
}

void Henkilo::setNumber(int aNumber)
{
	number = aNumber;
}

string Henkilo::getStringInput()
{
	string ret = "";
	cin.ignore();
	getline(cin, ret);
	cout << endl;
	return ret;
}

int Henkilo::getIntInput()
{
	int ret = 0;
	cin >> ret;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR. Syotteen on sisaltava numeroita ";
		cin >> ret;
	}
	cout << endl;
	return ret;
}

void Henkilo::printInfo() const
{
	cout << "Etunimi: " << fName << endl;
	cout << "Sukunimi: " << lName << endl;
	cout << "Osoite: " << adress << endl;
	cout << "Puh.: " << number << endl;
}
