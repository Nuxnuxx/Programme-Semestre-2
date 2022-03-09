#include <cstdlib>
#include <iomanip>
#include <iostream>

class vecteur2{
	private:
		int n;
		float *tab;
		static int ctr;
	public:

		// CONSTRUCTEUR
		vecteur2();
		vecteur2(int);
		vecteur2(int,float*);
		vecteur2(const vecteur2&);

		// DESTRUCTEUR
		~vecteur2();

		// METHODE
		void display();
		void initialise();
		void initialise(int);
		void initialise(int,float*);
		void homothetie(int);
		float scalaireValeur(vecteur2);
		float scalaireAdresse(vecteur2*);
		float scalaireReference(vecteur2&);
		vecteur2 addition(vecteur2&);
		static void compt();
};

int vecteur2::ctr = 0;

void vecteur2::compt(){
	std::cout << "appel compte" << ctr << " objets" << std::endl;
}

vecteur2::vecteur2(){
	std::cout << "CONSTRUCTEUR" << std::endl;
	ctr++;
	n = 0;
	tab = new float[n];
	for (int i = 0; i < n; i++)
		this->tab[i] = 0;
	std::cout << "il y a :" << ctr << " objets" << std::endl;
}

vecteur2::vecteur2(int pn){
	std::cout << "CONSTRUCTEUR" << std::endl;
	ctr++;
	n = pn;
	tab = new float[n];
	for (int i = 0; i < n; i++)
		this->tab[i] = 0;
	std::cout << "il y a :" << ctr << " objets" << std::endl;
}

vecteur2::vecteur2(int pn,float *tab){
	std::cout << "CONSTRUCTEUR" << std::endl;
	ctr++;
	n = pn;
	tab = new float[n];
	for (int i = 0; i < n; i++)
		this->tab[i] = tab[i];
	std::cout << "il y a :" << ctr << " objets" << std::endl;
}

vecteur2::vecteur2(const vecteur2& v1){
	if (this != v1) {
		delete tab;
		tab = new float[n = v1.n];
	}
}

vecteur2::~vecteur2(){
	ctr--;
	std::cout << "CONSTRUCTEUR" << std::endl;
	delete tab;
}

void vecteur2::display(){
	for (int i = 0; i < n; i++)
		std::cout << std::setw(2) << tab[i] ;
	std::cout << std::endl;
}

void vecteur2::initialise(){
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> this->tab[i];
}

void vecteur2::initialise(int x){
	n = x;
	for (int i = 0; i < n; i++)
		this->tab[i] = 0;
}

void vecteur2::initialise(int x,float *y){
	n = x;
	for (int i = 0; i < n; i++)
		std::cin >> y[i];
}

void vecteur2::homothetie(int x){
	for (int i = 0; i < n; i++)
		this->tab[i] *= x;
}

float vecteur2::scalaireValeur(vecteur2 v2){
	float sum = 0;
	if (n == v2.n) {
		for (int i = 0; i < n; i++)
		{
			sum += this->tab[i] * v2.tab[i];
		}
		std::cout << sum << std::endl;
		return sum;
	}
	else {
	std::cout << "SCALAIRE IMPOSSIBLE" << std::endl;
	return sum;
	}
}


float vecteur2::scalaireAdresse(vecteur2* v2){
	float sum = 0;
	if (n == v2->n) {
		for (int i = 0; i < n; i++)
		{
			sum += this->tab[i] * v2->tab[i];
		}
		std::cout << sum << std::endl;
		return sum;
	}
	else {
	std::cout << "SCALAIRE IMPOSSIBLE" << std::endl;
	return 0;
	}
}

float vecteur2::scalaireReference(vecteur2& v2){
	float sum = 0;
	if (n == v2.n) {
		for (int i = 0; i < n; i++)
		{
			sum += this->tab[i] * v2.tab[i];
		}
		std::cout << sum << std::endl;
		return sum;
	}
	else {
	std::cout << "SCALAIRE IMPOSSIBLE" << std::endl;
	return 0;
	}
}

vecteur2 vecteur2::addition(vecteur2& v2){
	if (n == v2.n) {
		vecteur2 result;
		for (int i = 0; i < n; i++)
		{
			result.tab[i] = this->tab[i] + v2.tab[i];
		}
		return result;
	}
	else {
	std::cout << "ADDITION IMPOSSIBLE" << std::endl;
	return 0;
	}
}

int main(){
	vecteur2 v1;
	v1.display();
	v1.homothetie(2);
	v1.display();
}
