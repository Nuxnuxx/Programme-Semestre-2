#include <cctype>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include <iostream>

class MyString {
	private:
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
	std::cout << "CONSTRUCTEUR" << std::endl;
	n = 0;
	tab = NULL;
}

MyString::MyString(const char* tabpn){
	std::cout << "CONSTRUCTEUR" << std::endl;
	n = strlen(tabpn);
	tab = new char[n];
	for (int i = 0; i < n; i++)
		tab[i] = tabpn[i];
}

MyString::MyString(const MyString& s2){
	std::cout << "CONSTRUCTEUR" << std::endl;
	n = s2.n;
	tab = new char[n];
	for (int i = 0; i < n; i++)
		tab[i] = s2.tab[i];
}

MyString::~MyString(){
	std::cout << "DESTRUCTEUR" << std::endl;
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

/* CONCATENATION DANS LE DIS OBJET S1 */
/* void MyString::concatenation(const MyString& s2){ */
/* 	n = n + s2.n; */
/* 	char* temp = tab; */
/* 	delete[] tab; */
/* 	tab = new char[n]; */
/* 	strcat(temp,s2.tab); */
/* 	tab = temp; */
/* } */

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

int main()
{
	MyString s1("ABC");
	MyString s2("DEF");
	s1.display();
	s2.display();
	MyString s3;
	s3 = s2.concatenation(s1);
	s3.display();
}
