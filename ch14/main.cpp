#include "std_lib_facilities.h"

class B1{
public:
	virtual void vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
	virtual void pvf() =0;
};

class D1:public B1{
public:
	void vf() override { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }		//4.feladat: nem irja felul a B1-ben az f()-et.
};

class D2: public D1{
public:
	void pvf() override { cout << "D2::pvf()\n"; }
};

class B2{
public:
	virtual void pvf() =0;
};

class D21: public B2{
public:
	string word = "cucc";
	void pvf() override { cout << word << '\n'; }
};

class D22: public B2{
public:
	int number = 2;
	void pvf() override { cout << number << '\n'; }
};

void f (B2& b)
{
	b.pvf();
}

int main()
{
	/*
	//1.feladat
	B1 b1;
	b1.vf();
	b1.f();

	//2.feladat
	D1 d1;
	d1.vf();
	d1.f(); //kiirja b1.f()et

	//3.feladat
	B1& reference = d1;
	reference.vf();	
	reference.f();
	*/


	//4.feladat

	/*
	//1.feladat
	B1 b1;
	b1.vf();					//B-ket irja csak ki
	b1.f();

	//2.feladat
	D1 d1;
	d1.vf();                     //D-ket irja csak ki
	d1.f(); //kiirja b1.f()et

	//3.feladat
	B1& reference = d1;
	reference.vf();				//vf()nel D1, f()nel B1
	reference.f();

	*/

	//5.feladat
	//cannot compile; the virtual functions are pure within

	//6.feladat
	/*
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	*/

	//7.feladat
	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	return 0;
}