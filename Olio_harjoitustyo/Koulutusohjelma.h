#pragma once
#include "Opiskelija.h"
#include "Opettaja.h"
#include<vector>
#include<algorithm>
#include<iostream>
class Koulutusohjelma: public Opettaja, public Opiskelija
{
public:
	Koulutusohjelma();
	Koulutusohjelma(const string& ohjelma);
	~Koulutusohjelma();

	void setOhjelma(const string& ohje);
	string getOhjelma() const;

	void lisaaOpettaja(Opettaja* opettaja);
	void listaaOpettajat();
	bool poistaOpettaja(const string& tunnus);
	void updateOpettaja(const string tunnus);

	void lisaaOppilas(Opiskelija* opiskelija);
	void listaaOppilaat();
	bool poistaOppilas(const string& tunnus);
	void updateOppilas(const string tunnus);


private:
	string ohjelma;
	vector<Opettaja*> opettajat;
	vector<Opiskelija*> oppilaat;
};

