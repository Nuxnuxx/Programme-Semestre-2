#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>

class MyString {
	protected:
		char *tab;
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
		void supprime(const char);
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
		delete tab;
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
		temp[k] = tab[i];
		k++;
	}
	for (int j = 0; j < s2.n; j++) {
		temp[k] = s2.tab[j];
		k++;
	}
	return(MyString(temp));
}

void MyString::supprime(const char sup){
	char* res;
	int compt = 0;
	res = new char[n];
	for (int i = 0; i < n; i++) {
		res[i] = tab[i];
		if (tab[i] == sup)
			compt++;
	}
	delete tab;
	tab = new char[n = n - compt];
	int j = 0;
	for (int i = 0; i < n+compt; i++) {
		if (res[i] != sup) {
			tab[j] = res[i];
			j++;
		}
	}
}

class MyStringStat : public MyString {
	protected:
		int* tabStat;

	public:

		// CONSTRUCTEUR
		MyStringStat();
		MyStringStat(const char*);
		MyStringStat(const MyStringStat&);

		// OPERATOR
		MyStringStat& operator=(const MyStringStat&);

		// DESTRUCTEUR
		~MyStringStat();

		// METHODE
		void fcpte();
		void faff();
		void displayStat();
		MyStringStat concatenationStat(const MyStringStat&);
		char* Conversion();
		void supprimeStat(const char);
};

MyStringStat::MyStringStat() : MyString() {
	std::cout << "CONSTRUCTEUR MyStringStat" << std::endl;
	tabStat = new int[5];
}

MyStringStat::MyStringStat(const char* tabBase) : MyString(tabBase){
	std::cout << "CONSTRUCTEUR MyStringStat" << std::endl;
	tabStat = new int[5];
	fcpte();
}

MyStringStat::MyStringStat(const MyStringStat& s1) : MyString(s1){
	std::cout << "CONSTRUCTEUR MyStringStat" << std::endl;
	tabStat = new int[5];
	fcpte();
}

MyStringStat::~MyStringStat(){
	std::cout << "DESTRUCTEUR MyStringStat" << std::endl;
	delete[] tabStat;
}

void MyStringStat::supprimeStat(const char sup){
	MyString::supprime(sup);
	fcpte();
}

MyStringStat& MyStringStat::operator=(const MyStringStat& s1){
	if (this != &s1){
		this->MyString::operator=(s1);
		delete tabStat;
		tabStat = new int[5];
		fcpte();
	}
	return *this;
}

void MyStringStat::fcpte(){
	for (int i = 0; i < 5; i++) {
		tabStat[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (isalpha(tab[i]))
			tabStat[0]++;
		if (!isalpha(tab[i]) && !isspace(tab[i]))
			tabStat[1]++;
		if (isupper(tab[i]))
			tabStat[2]++;
		if (islower(tab[i]))
			tabStat[3]++;
		if (isspace(tab[i]))
			tabStat[4]++;
	}
}

void MyStringStat::faff(){
	std::cout << "\n" << std::endl;
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

char* MyStringStat::Conversion(){
	char* res = new char[n+1];

	for (int i = 0; i < n; i++) {
		res[i] = tab[i];
	}
	res[n] = '\0';
	return res;
}

MyStringStat MyStringStat::concatenationStat(const MyStringStat &s2){
	MyStringStat temp;

	temp.MyString::operator=(MyString::concatenation(s2)); // sus
	return temp;
}

class MyStringStatExt : public MyStringStat {
	protected:
		int tabStatExt[26];

	public:

		//CONSTRUCTEUR
		MyStringStatExt();
		MyStringStatExt(const char*);
		MyStringStatExt(const MyStringStatExt&);
		MyStringStatExt(const int,const char);

		//OPERATOR
		MyStringStatExt& operator=(const MyStringStatExt&);
		//DESTRUCTEUR
		~MyStringStatExt();

		//METHODE
		void fcpteExt();
		void displayStatExt();
		MyStringStatExt concatenationStatExt(const MyStringStatExt&);
		void supprimeStatExt(const char);
};

MyStringStatExt::MyStringStatExt() : MyStringStat(){
	std::cout << "CONSTRUCTEUR MyStringStatExt\n" << std::endl;
}

MyStringStatExt::MyStringStatExt(const char* tabpn) : MyStringStat(tabpn){
	std::cout << "CONSTRUCTEUR MyStringStatExt\n" << std::endl;
	fcpteExt();
}

MyStringStatExt::MyStringStatExt(const MyStringStatExt& s1) : MyStringStat(s1){
	std::cout << "CONSTRUCTEUR MyStringStatExt\n" << std::endl;
	fcpteExt();
}

MyStringStatExt::MyStringStatExt(const int pn,const char cara) {
	std::cout << "CONSTRUCTEUR MyStringStatExt\n" << std::endl;
	n = pn;
	tab = new char[n];
	for (int i = 0; i < n; i++) {
		tab[i] = cara;
	}
	fcpte();
	fcpteExt();
}

MyStringStatExt& MyStringStatExt::operator=(const MyStringStatExt &s1){
	if (this != &s1){
		this->MyStringStat::operator=(s1);
		fcpteExt();
	}
	return *this;
}

MyStringStatExt::~MyStringStatExt(){
	std::cout << "\nDESTRUCTEUR MyStringStatExt" << std::endl;
}

void MyStringStatExt::fcpteExt(){
	std::cout << "FCPTEEXT\n" << std::endl;

	for (int i = 0; i < 26; i++) {
		tabStatExt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if(isalpha(tab[i])){
			int val = (int)toupper(tab[i]);
			tabStatExt[val - 65]++;
		}
	}
}

void MyStringStatExt::displayStatExt(){
	display();
	displayStat();
	std::cout << "\n" << std::endl;
	for(int i = 0; i < 26; i++){
		if (tabStatExt[i] != 0)
			std::cout << "il y a " << tabStatExt[i] << " lettres : " << char(97 + i) << std::endl;
	}
}

MyStringStatExt MyStringStatExt::concatenationStatExt(const MyStringStatExt& s1){
	MyStringStatExt temp;

	temp.MyStringStat::operator=(MyStringStat::concatenationStat(s1)); // sus
	return temp;
}

void MyStringStatExt::supprimeStatExt(const char sup){
	MyStringStat::supprimeStat(sup);
	fcpteExt();
}

class MyStringExtExt : public MyStringStatExt {
	public:
		//CONSTRUCTEUR
		MyStringExtExt();
		MyStringExtExt(const char*);
		MyStringExtExt(const MyStringExtExt&);
		MyStringExtExt(const int,const char);

		//OPERATOR
		MyStringExtExt& operator=(const MyStringExtExt&);
		MyStringExtExt operator+(const MyStringExtExt&);
		MyStringExtExt operator-(const char);
		MyStringExtExt operator++();
		MyStringExtExt operator++(int);
		MyStringExtExt operator--();
		MyStringExtExt operator--(int);
		char& operator[](const int);
		char& operator[](const int) const;
		friend std::ostream& operator<<(std::ostream&, const MyStringExtExt&);
		MyStringExtExt operator+(const char);
		MyStringExtExt operator+(int);

		//DESTRUCTEUR
		~MyStringExtExt();
};

MyStringExtExt::MyStringExtExt(){
	std::cout << "CONSTRUCTEUR MyStringExtExt\n" << std::endl;
}

MyStringExtExt::MyStringExtExt(const char* tabpn) : MyStringStatExt(tabpn){
	std::cout << "CONSTRUCTEUR MyStringExtExt\n" << std::endl;
}

MyStringExtExt::MyStringExtExt(const MyStringExtExt& s1) : MyStringStatExt(s1){
	std::cout << "CONSTRUCTEUR MyStringExtExt\n" << std::endl;
}

MyStringExtExt::MyStringExtExt(const int pn,const char cara) : MyStringStatExt(pn,cara){
	std::cout << "CONSTRUCTEUR MyStringExtExt\n" << std::endl;
}

MyStringExtExt::~MyStringExtExt(){
	std::cout << "\nDESTRUCTEUR MyStringExtExt" << std::endl;
}

MyStringExtExt& MyStringExtExt::operator=(const MyStringExtExt &s1){
	if (this != &s1){
		this->MyStringStatExt::operator=(s1);
	}
	return *this;
}

MyStringExtExt MyStringExtExt::operator+(const MyStringExtExt& s1){
	MyStringExtExt temp;

	temp.MyStringStatExt::operator=(MyStringStatExt::concatenationStatExt(s1));
	return temp;
}

MyStringExtExt MyStringExtExt::operator-(const char sup){
	MyStringExtExt temp(*this);

	temp.supprimeStatExt(sup);
	return temp;
}

MyStringExtExt MyStringExtExt::operator++(){
	for (int i = 0; i < n; i++) {
		if(isalpha(tab[i])){
			tab[i] = (char)((int)tab[i] + 1);
		}
	}
	fcpteExt();
	return *this;
}

MyStringExtExt MyStringExtExt::operator++(int){
	MyStringExtExt temp(*this);

	for (int i = 0; i < n; i++) {
		if(isalpha(tab[i])){
			tab[i] = (char)((int)tab[i] + 1);
		}
	}
	fcpteExt();
	return temp;
}

MyStringExtExt MyStringExtExt::operator--(){
	for (int i = 0; i < n; i++) {
		if(isalpha(tab[i])){
			tab[i] = (char)((int)tab[i] - 1);
		}
	}
	fcpteExt();
	return *this;
}

MyStringExtExt MyStringExtExt::operator--(int){
	MyStringExtExt temp(*this);

	for (int i = 0; i < n; i++) {
		if(isalpha(tab[i])){
			tab[i] = (char)((int)tab[i] - 1);
		}
	}
	fcpteExt();
	return temp;
}

char& MyStringExtExt::operator[](const int index){
	if (index < 0 || index >= n) {
		throw std::out_of_range("index out of range");
	}
	return tab[index];
}

char& MyStringExtExt::operator[](const int index) const{
	if (index < 0 || index >= n) {
		throw std::out_of_range("index out of range");
	}
	return tab[index];
}

std::ostream &operator<<(std::ostream &os, const MyStringExtExt &s1){
	os << s1.tab << "\n";
	os << "Il y a " << s1.tabStat[0] << " lettres de l'alphabet\n";
	os << "Il y a " << s1.tabStat[1] << " autres caractères\n";
	os << "Il y a " << s1.tabStat[2] << " majuscules\n";
	os << "Il y a " << s1.tabStat[3] << " minuscules\n";
	os << "Il y a " << s1.tabStat[4] << " espaces\n";
	for (int i = 0; i < 26; i++) {
		if (s1.tabStatExt[i] != 0)
		os << "Il y a " << s1.tabStatExt[i] << " lettres " << (char)(i+65) << "\n";
	}
	return os;
}

MyStringExtExt MyStringExtExt::operator+(int nb){
	for (int i = 0; i < n; i++) {
		if(isalpha(tab[i])){
			tab[i] = (char)((int)tab[i] + nb);
		}
	}
	fcpteExt();
	return *this;
}

MyStringExtExt MyStringExtExt::operator+(const char cara){

	char* temp;
	temp = new char[n];
	for (int i = 0; i < n; i++) {
		temp[i] = tab[i];
	}
	delete tab;
	tab = new char[n=n*2];
	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			tab[i] = temp[i/2];
		}
		else {
			tab[i] = cara;
		}
	}
	fcpte();
	fcpteExt();
	return *this;
}

int main()
{
}
