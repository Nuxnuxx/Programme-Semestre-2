#include <iomanip>
#include <iostream>
#define N 200

class vecteur1{
	private:
		int n;
		float tab[N];
	public:
		// CONSTRUCTEUR | DESTRUCTEUR
		vecteur1();
		vecteur1(int);
		vecteur1(int,float*);
		~vecteur1();

		// METHODE
		void display();
		void initialise();
		void initialise(int);
		void initialise(int,float*);
		void homothetie(int);
		float scalaireValeur(vecteur1);
		float scalaireAdresse(vecteur1*);
		float scalaireReference(vecteur1&);
		vecteur1 addition(vecteur1&);
};

vecteur1::vecteur1(){
	std::cout << "CONSTRUCTEUR" << std::endl;
	n = 0;
}

vecteur1::vecteur1(int pn){
	std::cout << "CONSTRUCTEUR" << std::endl;
	n = pn;
	for (int i = 0; i < n; i++)
		this->tab[i] = 0;
}

vecteur1::vecteur1(int pn,float *x){
	std::cout << "CONSTRUCTEUR" << std::endl;
	n = pn;
	for (int i = 0; i < n; i++)
		this->tab[i] = x[i];
}

vecteur1::~vecteur1(){
	std::cout << "DESTRUCTEUR" << std::endl;
}

void vecteur1::display(){
	for (int i = 0; i < n; i++)
		std::cout << std::setw(2) << tab[i] ;
	std::cout << std::endl;
}

void vecteur1::initialise(){
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> this->tab[i];
}

void vecteur1::initialise(int x){
	n = x;
	for (int i = 0; i < n; i++)
		this->tab[i] = 0;
}

void vecteur1::initialise(int x,float y[N]){
	n = x;
	for (int i = 0; i < n; i++)
		std::cin >> y[i];
}

void vecteur1::homothetie(int x){
	for (int i = 0; i < n; i++)
		this->tab[i] *= x;
}

float vecteur1::scalaireValeur(vecteur1 v2){
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


float vecteur1::scalaireAdresse(vecteur1* v2){
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

float vecteur1::scalaireReference(vecteur1& v2){
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

vecteur1 vecteur1::addition(vecteur1& v2){
	if (n == v2.n) {
		vecteur1 result;
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

int main()
{
	vecteur1 *test = new vecteur1(10);
	test->display();
	test->initialise();
	test->display();
	delete test;
}
