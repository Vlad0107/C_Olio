
#include "pch.h"
#include "Koulu.h"

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include <limits>

using namespace std;

void printMenu() {
	cout << "1)	Lisaa koulutusohjelma" << endl;
	cout << "2)	Tulosta koulutusohjelmien nimet" << endl;
	cout << "3)	Tulosta koulutusohjelmien maara" << endl;
	cout << "4)	Lisaa koulutusohjelmaan opettaja" << endl;
	cout << "5)	Tulosta koulutusohjelman opettajat" << endl;
	cout << "6)	Lisaa koulutusohjelmaan opiskelija" << endl;
	cout << "7)	Tulosta koulutusohjelman opiskelijat" << endl;
	cout << "8)	Poista koulutusohjelma" << endl;
	cout << "9)	Poista opettaja" << endl;
	cout << "10) Poista opiskelija" << endl;
	cout << "11) Paivita koulutusohjelman nimi" << endl;
	cout << "12) Paivita opettajan tiedot" << endl;
	cout << "13) Paivita opiskelijan tiedot" << endl;
	cout << "14) Lue tiedot" << endl;
	cout << "15) Tallenna tiedot" << endl;
	cout << "0)	Lopeta" << endl;
}

int getChoice() {
	int ret = 0;
	cout << "Valintasi: ";
	cin >> ret;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR  Valitse numero(0-15): ";
		cin >> ret;
	}
	return ret;
}

void addOhjelma(Koulu* k) {
	string ohjelma;
	cout << "Kolutusohjelman nimi: ";
	cin.ignore();
	getline(cin, ohjelma);
	Koulutusohjelma* x = new Koulutusohjelma{ ohjelma };
	k->lisaaOhjelma(x);
}

string getString() {
	string ret = "";
	cin.ignore();
	getline(cin, ret);
	return ret;
}

int main() {

	Koulu* k = new Koulu();
	int choice = 1;
	string input = "";
	string input2 = "";

	while (choice != 0) {
		printMenu();
		choice = getChoice();
		switch (choice) {
		case 1:
			addOhjelma(k);
			break;
		case 2:
			k->tulostaOhjelmat();
			break;
		case 3:
			k->tulostaOhjelmienmaara();
			break;
		case 4:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			if (!k->lisaaOpettaja(input)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 5:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			if (!k->listaaOpettajat(input)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 6:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			if (!k->lisaaOppilas(input)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 7:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			if (!k->listaaOppilaat(input)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 8:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			if (!k->poistaOhjelma(input)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 9:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			cout << "Opettajan tunnus:";
			input2 = getString();
			if (!k->poistaOpettaja(input,input2)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 10:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			cout << "Opiskelijan tunnus:";
			input2 = getString();
			if (!k->poistaOppilas(input, input2)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 11:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			if (!k->updateOhjelma(input)) {
				cout << "NOT FOUND!!" << endl;
			}
			break;
		case 12:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			cout << "Opettajan tunnus:";
			input2 = getString();
			k->updateOpettaja(input, input2);
			break;
		case 13:
			cout << "Koulutusohjelman nimi:";
			input = getString();
			cout << "Oppilaan tunnus:";
			input2 = getString();
			k->updateOppilas(input, input2);
			break;
		/*case 14:
			k->lueTiedostot();
			break;
		case 15:
			break;
		}*/
		if (choice != 0) {
			system("pause");
			system("cls");
		}
	}	
		return EXIT_SUCCESS;
}

