#pragma once
#include "Koulutusohjelma.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<sstream>

class Koulu
{
public:
	Koulu();
	Koulu(const string& aName) : kNimi(aName) {};
	~Koulu();

	string getKNimi() const;
	void setKNimi(const string& nimi);

	void lisaaOhjelma(Koulutusohjelma* ohjelma);
	bool poistaOhjelma(const string& nimi);

	bool poistaOpettaja(const string& ohjelma, const string& tunnus);
	bool poistaOppilas(const string& ohjelma, const string& tunnus);

	void updateOpettaja(const string& ohjelma, const string& tunnus);
	void updateOppilas(const string& ohjelma, const string& tunnus);

	void tulostaOhjelmat();
	void tulostaOhjelmienmaara();

	bool lisaaOpettaja(const string& nimi);
	bool lisaaOppilas(const string& nimi);

	bool listaaOpettajat(const string& nimi);
	bool listaaOppilaat(const string& nimi);

	bool updateOhjelma(const string& ohjelma);

	bool lueTiedostot();


private:
	string kNimi;
	vector<Koulutusohjelma*> ohjelmat;
};

