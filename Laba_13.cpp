// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

using namespace std;
typedef double(*type_f)(double);
double fun(double x);
double Automat(type_f, double a, double b, int n);
double Int1, Int2, x, eps = 0.000001, a = -2, b = 5, pogr;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	int  n = 2;
	cout << "-2/5 (x^3-5x^2)dx" << endl;
	Int1 = Automat(fun, a, b, n);
	cout << "Pri n = " << n << ". Integral raven " << Int1 << endl;
	_getch();
	return 0;
}

double fun(double x) {
	return pow(x, 3) - 5 * pow(x, 2);
}

double Automat(type_f f, double a, double b, int n) {
	double Fsr, Ftr, sum_yi = 0, sum_yiplus = 0;
	double h = (b - a) / n;
	x = a;
	for (int i = 1; i <= n; i++) {
		sum_yi += fun(x) + fun(x + h);
		sum_yiplus += fun(x + h / 2.);
		x += h;
	}
	Fsr = h * sum_yiplus;
	Ftr = h * sum_yi / 2.;
	if (fabs(Fsr - Ftr) >= eps) {
		n = 2 * n;
		return Automat(fun, a, b, n);
	}
	else return ((2 * Fsr + Ftr) / 3);
}