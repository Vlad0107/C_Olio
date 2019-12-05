#include "pch.h"
#include "Koulutusohjelma.h"



Koulutusohjelma::Koulutusohjelma(const string & aOhjelma)
	: ohjelma(aOhjelma)
{
}

Koulutusohjelma::Koulutusohjelma()
{
}

Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::setOhjelma(const string & ohje)
{
	ohjelma = ohje;
}

string Koulutusohjelma::getOhjelma() const
{
	return ohjelma;
}

void Koulutusohjelma::lisaaOpettaja(Opettaja * opettaja)
{
	opettajat.push_back(opettaja);
}

void Koulutusohjelma::listaaOpettajat()
{
	for_each(opettajat.begin(), opettajat.end(), [](Opettaja* x)
	{
		x->tulostaTiedot();
	});
}

void Koulutusohjelma::lisaaOppilas(Opiskelija * opiskelija)
{
	oppilaat.push_back(opiskelija);
}

void Koulutusohjelma::listaaOppilaat()
{
	for_each(oppilaat.begin(), oppilaat.end(), [](Opiskelija* x)
	{
		x->tulostaTiedot();
	});
}

bool Koulutusohjelma::poistaOpettaja(const string & tunnus)
{
	bool ret = false;

	opettajat.erase(
		remove_if(opettajat.begin(), opettajat.end(), [tunnus, &ret](Opettaja* x)
	{
		if (x->getTag() == tunnus) {
			ret = true;
			return true;
		}
	}
		),
		opettajat.end()
		);
	return ret;
}

void Koulutusohjelma::updateOpettaja(const string tunnus)
{
	for_each(opettajat.begin(), opettajat.end(), [tunnus](Opettaja* y)
	{
		if (tunnus == y->getTag())
		{
			cout << "FOUND!!!" << endl;
			cout << "Paivitetaan opettaja! " << endl;
			cout << "Ala: ";
			y->setAla(y->getStringInput());
			cout << "Tunnus: ";
			y->setTag(y->getStringInput());
			cout << "Palkka: ";
			y->setPay(y->getIntInput());
			cout << "Etunimi: ";
			y->setFname(y->getStringInput());
			cout << "Sukunimi: ";
			y->setLname(y->getStringInput());
			cout << "Osoite: ";
			y->setAdress(y->getStringInput());
			cout << "Puh: ";
			y->setNumber(y->getIntInput());
		}
	});
}

bool Koulutusohjelma::poistaOppilas(const string & tunnus)
{
	bool ret = false;

	oppilaat.erase(
		remove_if(oppilaat.begin(), oppilaat.end(), [tunnus, &ret](Opiskelija* x)
	{
		if (x->getStudNumber() == tunnus) {
			ret = true;
			return true;
		}
	}
		),
		oppilaat.end()
		);
	return ret;
}

void Koulutusohjelma::updateOppilas(const string tunnus)
{
	for_each(oppilaat.begin(), oppilaat.end(), [tunnus](Opiskelija* y)
	{
		if (tunnus == y->getStudNumber())
		{
			cout << "FOUND!!!" << endl;
			cout << "Paivitetaan oppilas! " << endl;
			cout << "Opiskelijanumero:";
			y->setStudNumber(y->getStringInput());
			cout << "Etunimi: ";
			y->setFname(y->getStringInput());
			cout << "Sukunimi: ";
			y->setLname(y->getStringInput());
			cout << "Osoite:";
			y->setAdress(y->getStringInput());
			cout << "Puh.:";
			y->setNumber(y->getIntInput());
		}
	});
}
