#pragma once

#include<string>
#include<iostream>
using namespace std;
class Henkilo
{
public:
	Henkilo() : fName(""), lName(""), adress(""), number(0) {};
	Henkilo(const string& aFName, const string& aLName) : fName(aFName), lName(aLName) {};
	Henkilo(const string& aFName, const string& aLName, const string& aAdress, int aNumber);
	~Henkilo();

	string getFName() const;
	void setFname(const string& aFName);

	string getLName() const;
	void setLname(const string& aLName);

	string getAdress() const;
	void setAdress(const string& aAdress);

	int getNumber();
	void setNumber(int aNumber);

	string getStringInput();
	int getIntInput();
	void printInfo() const;



private:
	string fName="", lName="", adress="";
	int number = 0;
};

