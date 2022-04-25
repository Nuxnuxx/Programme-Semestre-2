#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class point
{
	protected:
		double x, y;
		double rho, theta;
	public:
		// CONSTRUCTEUR
		point();
		point(int);
		point(int, int);
		point(const point&);
		// DESTRUCTEUR
		~point();
		// METHODES
		void rotation(int);
		void polaire();
		void cartesienne();
		void initialise(int, int);
		void display();
		void deplace(int dx, int dy);
		void homothetie(int k);
};

point::point()
{
	cout << "constructeur point" << endl;
	x = 0;
	y = 0;
	polaire();
}

point::point(int p)
{
	cout << "constructeur point" << endl;
	x = p;
	y = p;
	polaire();
}

point::point(int px, int py)
{
	cout << "constructeur point" << endl;
	x = px;
	y = py;
	polaire();
}

point::point(const point& p1)
{
	cout << "constructeur point" << endl;
	x = p1.x;
	y = p1.y;
	polaire();
}

point::~point()
{
	cout << "destructeur point" << endl;
}

void point::rotation(int alpha)
{
	double radian;
	radian = M_PI * alpha;
	radian = radian / 180;
	theta = theta + radian;
	cartesienne();
}

void point::cartesienne()
{
	x = rho * cos(theta);
	y = rho * sin(theta);
}

void point::polaire()
{
	rho = sqrt(x * x + y * y);
	theta = atan2(y, x);
}

void point::initialise(int px, int py)
{
	x = px;
	y = py;
	polaire();
}

void point::display()
{
	cout << "x : " << x ;
	cout << " y : " << y << endl;
	cout << "theta : " << theta ;
	cout << " rho : " << rho << endl;
}

void point::deplace(int dx, int dy)
{
	x = x + dx;
	y = y + dy;
	polaire();
}

void point::homothetie(int k)
{
	x = x * k;
	y = y * k;
	polaire();
}

class rectangle
{
	protected:
		point p1, p2;
	public:
		// CONSTRUCTEUR
		rectangle();
		rectangle(point,int,int);
		rectangle(point, point);
		rectangle(int, int, int, int);
		rectangle(const rectangle& r1);

		// DESTRUCTEUR
		~rectangle();

		// OPERATEURS
		rectangle& operator=(const rectangle& r1);

		// METHODES
		void display();
		void initialise(int, int, int, int);
		void initialise(point,int,int);
		void homothetie(int k);
		void deplace(const point&);
};

rectangle::rectangle() : p1(0, 0), p2(0, 0)
{
	cout << "constructeur rectangle" << endl;
}

rectangle::rectangle(point p,int h,int l) : p1(p), p2(p)
{
	cout << "constructeur rectangle" << endl;
	p2.deplace(l,h);
}

rectangle::rectangle(point p1, point p2) : p1(p1), p2(p2)
{
	cout << "constructeur rectangle" << endl;
}

rectangle::rectangle(int px1, int py1, int px2, int py2) : p1(px1, py1), p2(px2, py2)
{
	cout << "constructeur rectangle" << endl;
}

rectangle::rectangle(const rectangle& r1) : p1(r1.p1), p2(r1.p2)
{
	cout << "constructeur rectangle" << endl;
}

rectangle::~rectangle()
{
	cout << "destructeur rectangle" << endl;
}

rectangle& rectangle::operator=(const rectangle& r1)
{
	p1 = r1.p1;
	p2 = r1.p2;
	return *this;
}

void rectangle::display()
{
	p1.display();
	p2.display();
}

void rectangle::initialise(int px1, int py1, int px2, int py2)
{
	p1.initialise(px1, py1);
	p2.initialise(px2, py2);
}

void rectangle::initialise(point p, int h, int l)
{
	p1 = p2 = p;
	p2.deplace(l, h);
}

void rectangle::homothetie(int k)
{
	p1.homothetie(k);
	p2.homothetie(k);
}

void rectangle :: deplace(const point& a){
}

class bouton {
	private:
		rectangle r;
		string txt;
	public:

		// CONSTRUCTEUR
		bouton();
		bouton(point,int,int);
		bouton(point,point,const char*);
		bouton(int, int, int, int, const char*);
		bouton(const bouton&);

		// DESTRUCTEUR
		~bouton();

		// OPERATEURS
		bouton& operator=(const bouton&);

		// METHODES
		void display();
		void initialise(int, int, int, int, const char*);
		void initialise(point,int,int,const char*);
		void homothetie(int k);
		void deplace();
};

bouton::bouton() : r(0, 0, 0, 0), txt("")
{
	cout << "constructeur bouton" << endl;
}

bouton::bouton(point p,int h,int l) : r(p,h,l)
{
	cout << "constructeur bouton" << endl;
}

bouton::bouton(point p,point p2,const char* t) : r(p,p2)
{
	cout << "constructeur bouton" << endl;
	txt = t;
}

bouton::bouton(int px1, int py1, int px2, int py2, const char* t) : r(px1, py1, px2, py2)
{
	cout << "constructeur bouton" << endl;
	txt = t;
}

bouton::bouton(const bouton& b1) : r(b1.r), txt(b1.txt)
{
	cout << "constructeur bouton" << endl;
}

bouton::~bouton()
{
	cout << "destructeur bouton" << endl;
}

bouton& bouton::operator=(const bouton& b1)
{
	r = b1.r;
	txt = b1.txt;
	return *this;
}

void bouton::display()
{
	r.display();
	cout << "texte : " << txt << endl;
}

void bouton::initialise(int px1, int py1, int px2, int py2, const char* t)
{
	r.initialise(px1, py1, px2, py2);
	txt = t;
}

void bouton::initialise(point p, int h, int l, const char* t)
{
	r.initialise(p, h, l);
	txt = t;
}

void bouton::homothetie(int k)
{
	r.homothetie(k);
}

void bouton::deplace(){

}

int main()
{
	bouton r1(1,1,1,1,"test");
	r1.display();
}
