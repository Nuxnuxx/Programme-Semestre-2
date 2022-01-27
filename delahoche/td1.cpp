#include <cmath>
#include <math.h>
#include <string>
#include <iostream>

class point{
	private:
		 double x,y;
		 double rho,theta;
		 double carx,cary;
	public:
		 // Constructeur
		 point();
		 point(double);
		 point(double,double);

		 // Destructeur
		 ~point();

		 // Methode
		 void init(double,double);
		 void display();
		 void move(double,double);
		 void homothetie(double);

		 // Methode avancé
		 void polar();
		 void cartesian();
		 void rotate(double);
};


point::point(){
	std::cout << "Constructeur" << std::endl;
	x = 0;
	y = 0;
	polar();
	cartesian();
}

point::point(double p){
	std::cout << "Constructeur" << std::endl;
	x = y = p;
	polar();
	cartesian();
}

point::point(double px,double py){
	std::cout << "constructeur" << std::endl;
	x = px;
	y = py;
	polar();
	cartesian();
}

point::~point(){
	std::cout << "destructeur" << std::endl;
}

void point::init(double px,double py){
	x = px;
	y = py;
	polar();
	cartesian();
}


void point::move(double dx, double dy){
	x += dx;
	y += dy;
	polar();
	cartesian();
}

void point::homothetie(double nb){
	x = x * nb;
	y = y * nb;
	polar();
	cartesian();
}

void point::polar(){
	rho = sqrt(x*x + y*y);
	theta = atan2(x,y);
}


void point::cartesian(){
	carx = rho * cos(theta);
	cary = rho * sin(theta);
}

void point::rotate(double alpha){
	x = x * cos(alpha) + y * sin(alpha);
	y = y * cos(alpha) - x * sin(alpha);
	polar();
	cartesian();
}

void point::display(){
	std::cout << std::endl << "x = " << x;
	std::cout << " || y = " << y <<std::endl << std::endl;
	std::cout << "rho = " << rho;
	std::cout << " || theta = " << theta << std::endl << std::endl;
	std::cout << "carx = " << carx;
	std::cout << " || cary = " << cary << std::endl << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

int main()
{
	/* point a; */
	/* double x,y; */
	/* std::cin >> x >> y ; */
	/* a.init(x,y); */
	/* a.display(); */
	/* a.rotate(90); */
	/* a.display(); */

	/*  Plusieur syntaxe : */
	/*  point a(1,1); */
	/*  point a = point(1,1); */
	/* Quel changement */

	point b(10,10);
	b.display();
	b.rotate(90);
	b.display();
	return 0;
}
