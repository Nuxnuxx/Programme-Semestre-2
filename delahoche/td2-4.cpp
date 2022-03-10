#include <cctype>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include <iostream>

class MyString {
	protected:
		char* tab;
		int n;
	public:
		//CONSTRUCTEUR
		MyString();
		MyString(const char*);
		MyString(const MyString&);

		//OPERATOR
		MyString& operator=(const MyString&);
		MyString& operator=(const char*);

		// DESTRUCTEUR
		~MyString();

		//METHODE
		void display();
		void maj();
		void min();
		MyString concatenation(const MyString&);

};

MyString::MyString(){
	std::cout << "CONSTRUCTEUR MyString" << std::endl;
	n = 0;
	tab = NULL;
}

MyString::MyString(const char* tabpn){
	std::cout << "CONSTRUCTEUR MyString" << std::endl;
	n = strlen(tabpn);
	tab = new char[n];
	for (int i = 0; i < n; i++)
		tab[i] = tabpn[i];
}

MyString::MyString(const MyString& s2){
	std::cout << "CONSTRUCTEUR MyString" << std::endl;
	n = s2.n;
	tab = new char[n];
	for (int i = 0; i < n; i++)
		tab[i] = s2.tab[i];
}

MyString::~MyString(){
	std::cout << "DESTRUCTEUR MyString" << std::endl;
	delete[] tab;
}

MyString& MyString::operator=(const MyString& s2) {
	if (this != &s2) {
		delete[] tab;
		tab = new char[n = s2.n];
		for (int i = 0; i < n; i++)
			tab[i] = s2.tab[i];
	}
	return *this;
}

MyString& MyString::operator=(const char* tabpn){
	tab = new char[strlen(tabpn)];
	for (int i = 0; i < n; i++)
		tab[i] = tabpn[i];
	return *this;
}

void MyString::display(){
	for (int i = 0; i < n; i++)
		std::cout << tab[i] ;
	std::cout << std::endl;
}

void MyString::maj(){
	for (int i = 0; i < n; i++)
		tab[i] = toupper(tab[i]);
}

void MyString::min(){
	for (int i = 0; i < n; i++)
		tab[i] = tolower(tab[i]);
}

MyString MyString::concatenation(const MyString& s2){
	char* temp = new char[n + s2.n];
	int k = 0;
	for (int i = 0; i < n; i++) {
		temp[i] = tab[i];
		k++;
	}
	for (int i = 0; i < s2.n; i++) {
		temp[k] = s2.tab[i];
		k++;
	}
	return (MyString(temp));
}

class MyStringStat : public MyString {
	private:
		int* tabStat;
	public:
		// CONSTRUCTEUR
		MyStringStat();
		MyStringStat(const char*);
		MyStringStat(const MyStringStat&);

		// OPERATOR
		/* MyStringStat& operator=(const MyStringStat&); */

		// DESTRUCTEUR
		~MyStringStat();

		// METHODE
		void fcpte();
		void faff();
		void displayStat();
};

MyStringStat::MyStringStat() : MyString() {
	std::cout << "CONSTRUCTEUR MyStringStat" << std::endl;
	tabStat = new int[5];
	for (int i = 0; i < 5; i++)
		tabStat[i] = 0;
	fcpte();
}

MyStringStat::MyStringStat(const char* tabBase) : MyString(tabBase){
	std::cout << "CONSTRUCTEUR MyStringStat" << std::endl;
	tabStat = new int[5];
	for (int i = 0; i < 5; i++)
		tabStat[i] = 0;
	fcpte();
}

MyStringStat::MyStringStat(const MyStringStat& s1) : MyString(s1){
	std::cout << "CONSTRUCTEUR MyStringStat" << std::endl;
	tabStat = new int[5];
	tabStat = s1.tabStat;
	fcpte();
}

MyStringStat::~MyStringStat(){
	std::cout << "DESTRUCTEUR MyStringStat" << std::endl;
	delete[] tabStat;
}

/* MyStringStat& MyStringStat::operator=(const MyStringStat& s1){ */
/* 	if (this != &s1){ */
/* 		delete[] tabStat; */
/* 		tabStat = s1.tabStat; */
/* 	} */
/* 	return *this; */
/* } */

void MyStringStat::fcpte(){
	for (int i = 0; i < n; i++) {
		if (isalpha(tab[i]))
			tabStat[0]++;
		if (isalpha(tab[i]) == 0)
			tabStat[1]++;
		if (isupper(tab[i]))
			tabStat[2]++;
		if (islower(tab[i]))
			tabStat[3]++;
		if (tab[i] == 32)
			tabStat[4]++;
	}
}

void MyStringStat::faff(){
	std::cout << "Il y a " << tabStat[0] << " lettres de l'alphabet" << std::endl;
	std::cout << "Il y a " << tabStat[1] << " autres caractères" << std::endl;
	std::cout << "Il y a " << tabStat[2] << " majuscules" << std::endl;
	std::cout << "Il y a " << tabStat[3] << " minuscules" << std::endl;
	std::cout << "Il y a " << tabStat[4] << " espaces" << std::endl;
}

void MyStringStat::displayStat(){
	display();
	faff();
}

int main()
{
}
