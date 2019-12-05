#include "pch.h"
#include "Koulu.h"


Koulu::Koulu()
{
}


Koulu::~Koulu()
{
}

string Koulu::getKNimi() const
{
	return kNimi;
}

void Koulu::setKNimi(const string & nimi)
{
	kNimi = nimi;
}

void Koulu::lisaaOhjelma(Koulutusohjelma* ohjelma) 
{
	ohjelmat.push_back(ohjelma);
}

bool Koulu::poistaOhjelma(const string& nimi)
{
	bool ret = false;
	
	ohjelmat.erase(
		remove_if(ohjelmat.begin(), ohjelmat.end(),[nimi,&ret](Koulutusohjelma* x)
	{ 
		if (x->getOhjelma() == nimi) {
			ret = true;
			return true;
		}
	}
		),
		ohjelmat.end()
	);
	return ret;
}

bool Koulu::poistaOpettaja(const string & ohjelma, const string & tunnus)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [ohjelma, &ret, tunnus](Koulutusohjelma* x)
	{
		if (ohjelma == x->getOhjelma())
		{
			ret = x->poistaOpettaja(tunnus);
		}
	});

	return ret;
}

bool Koulu::poistaOppilas(const string & ohjelma, const string & tunnus)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [ohjelma, &ret, tunnus](Koulutusohjelma* x)
	{
		if (ohjelma == x->getOhjelma())
		{
			ret = x->poistaOppilas(tunnus);
		}
	});

	return ret;
}

void Koulu::updateOpettaja(const string & ohjelma, const string& tunnus)
{
	for_each(ohjelmat.begin(), ohjelmat.end(), [ohjelma, tunnus](Koulutusohjelma* x)
	{
		if (ohjelma == x->getOhjelma())
		{
			 x->updateOpettaja(tunnus);
		}
	});

}

void Koulu::updateOppilas(const string & ohjelma, const string& tunnus)
{
	for_each(ohjelmat.begin(), ohjelmat.end(), [ohjelma, tunnus](Koulutusohjelma* x)
	{
		if (ohjelma == x->getOhjelma())
		{
			x->updateOppilas(tunnus);
		}
	});
}

void Koulu::tulostaOhjelmat()
{
	cout << "Ohjelmien nimet: " << endl;
	for_each(ohjelmat.begin(), ohjelmat.end(), [](Koulutusohjelma* x)
	{
		cout << x->getOhjelma() << endl;
		
	});
}

void Koulu::tulostaOhjelmienmaara()
{
	cout << "Ohjelmien maara: " << ohjelmat.size() << endl;
}

bool Koulu::lisaaOpettaja(const string& nimi)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [nimi,&ret](Koulutusohjelma* x)
	{
		if (nimi == x->getOhjelma())
		{
			cout << "FOUND!!!" << endl;
			cout << "Lisaataan opettaja! " << endl;
			Opettaja* y = new Opettaja{};
			cout << "Ala: " ;
			y->setAla(y->getStringInput());
			cout << "Tunnus: " ;
			y->setTag(y->getStringInput());
			cout << "Palkka: " ;
			y->setPay(y->getIntInput());
			cout << "Etunimi: ";
			y->setFname(y->getStringInput());
			cout << "Sukunimi: ";
			y->setLname(y->getStringInput());
			cout << "Osoite: " ;
			y->setAdress(y->getStringInput());
			cout << "Puh: "  ;
			y->setNumber(y->getIntInput());
			
			
			x->lisaaOpettaja(y);
			ret = true;
		}
	});
	return ret;
}

bool Koulu::lisaaOppilas(const string & nimi)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [nimi, &ret](Koulutusohjelma* x)
	{
		if (nimi == x->getOhjelma())
		{
			cout << "FOUND!!!" << endl;
			cout << "Lisaataan oppilas:! " << endl;
			Opiskelija* y = new Opiskelija{};
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
			
			x->lisaaOppilas(y);
			ret = true;
		}
	});
	return ret;
}

bool Koulu::listaaOpettajat(const string & nimi)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [nimi, &ret](Koulutusohjelma* x)
	{
		if (nimi == x->getOhjelma())
		{
			cout << "FOUND!!!" << endl;
			x->listaaOpettajat();
			ret = true;
		}
	});
	return ret;
}

bool Koulu::listaaOppilaat(const string & nimi)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [nimi, &ret](Koulutusohjelma* x)
	{
		if (nimi == x->getOhjelma())
		{
			cout << "FOUND!!!" << endl;
			x->listaaOppilaat();
			ret = true;
		}
	});
	return ret;
}

bool Koulu::updateOhjelma(const string & ohjelma)
{
	bool ret = false;
	for_each(ohjelmat.begin(), ohjelmat.end(), [ohjelma, &ret](Koulutusohjelma* x)
	{
		if (ohjelma == x->getOhjelma())
		{
			string input = "";
			cout << "FOUND!!!" << endl;
			cout << "Ohjelman uusi nimi:";
			cin.ignore();
			getline(cin, input);
			x->setOhjelma(input);
			ret = true;
		}
	});
	return ret;
}

bool Koulu::lueTiedostot()
{
	vector<string> result;
	string  line;
	ifstream str( "Opettajat.csv");
	getline(str, line);

	stringstream lineStream(line);
	string  cell;

	while (getline(lineStream, cell, ','))
	{
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return true;
}
