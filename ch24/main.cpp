#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

void squareroot()
{	
	int a;
	cin >> a;
	if(a>0)
		cout << "sqrt of " << a << " : " << sqrt(a) << endl;
	else
		cout << "no square root";
}

int main()
{
	/*
	char ch1;
	cout << sizeof(ch1) << endl;

	short sh1;
	cout << sizeof(sh1) << endl;

	int i1;
	cout << sizeof(i1) << endl;

	long l1;
	cout << sizeof(l1) << endl;

	float f1;
	cout << sizeof(f1) << endl;

	double d1;
	cout << sizeof(d1) << endl;

	int* i2;
	cout << sizeof(i2) << endl;

	double* d2;
	cout << sizeof(d2) << endl;

	Matrix<int, 1> a(10);
	cout << sizeof(a) << endl;

	Matrix<int, 1> b(100);
	cout << sizeof(b) << endl;

	Matrix<double, 1> c(10);
	cout << sizeof(c) << endl;

	Matrix<int,2> d(10,10);
	cout << sizeof(d) << endl;

	Matrix<int,3> e(10,10,10);
	cout << sizeof(e) << endl;

	cout << a.size() << endl;
	cout << b.size() << endl;
	cout << c.size() << endl;
	cout << e.size() << endl;

	int x;
	cout << "enter the number of numbers you want the sqrt of:";
	cin >> x;
	for(int i=1;i<=x;i++)
		squareroot();


	Matrix<double> matrix1(10);
	cout << "Enter 10 floating-point values: " << endl;

	for(int i=0;i<10;i++)
		cin >> matrix1[i];
	cout << matrix1 << endl;
	

	cout << "Multiplication table: enter an n and an m below:" << endl;
	int n;int m;
	cin >> n; cin >> m;
	Matrix<int, 2> table(n,m);

	for(int i=0; i< table.dim1();i++)
	{
		for(int j=0; j<table.dim2();j++)
		{
			table(i,j) = (i+1)*(j+1);
			cout << setw(5) << table(i,j) << " ";
		}
		cout << endl;
	}

	cout << "Enter 10 complex numbers: " << endl;
	Matrix<complex<double>> matrix2(10);
	for(int i=0;i<10;i++)
		cin >> matrix2[i];

	complex<double> sum;
	for (int i = 0; i < 10; i++)
        sum += matrix2[i];
    cout << "Sum of numbers in matrix: " << sum << endl;

    */

    cout << "Enter 6 ints:" << endl;
    Matrix<int,2> matrix3(2,3);
    for(int i=0; i < matrix3.dim1(); i++)
		for(int j=0; j < matrix3.dim2(); j++)
		{
			cin >> matrix3(i,j);
		}

	for(int i=0; i < matrix3.dim1(); i++)
	{
		for(int j=0; j < matrix3.dim2(); j++)
		{
			cout << setw(3) << matrix3(i,j) << " ";
		}
		cout << endl;
	}


	return 0;
}