// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, k, u;
	double a, b, h, x, y, sum_S, Y, S;
	long double fct;
	void fun1(double a, double b, double h, int n);
	void fun2(double a);
	void fun3(double a, double b, double h, int n);
	fct = 1;
	sum_S = 0;
	for (x = a; x <= b; x += h) {

		cout << "viberite funkcii Y, S ili |Y-S|, nagav sootvetstvenno klavishi 1, 2, 3: ";
		cin >> u;
		switch (u) {
		case 1: cout << "Function S:";
			cin >> a >> b >> h >> n;
			fun1(a, b, h, n);
			break;
		case 2: cout << "Function Y:";
			cin >> a;
			fun2(a);
			break;
		case 3: cout << "Function Y-S:";
			cin >> a >> b >> h >> n;
			fun3(a, b, h, n);
			break;
		default: cout << "Mistake";  break;
		}
	}
	system("pause");
	return 0;
}

void fun1(double a, double b, double h, int n)
{
	Y = (exp(x) + exp(-x)) / 2;
	cout << "Y ravno:" << Y << "      ";
	for (k = 0; k <= n; k++) {
		for (y = 1; y <= 2 * k; y++) {
			fct = fct * y;
		}
		S = pow(x, 2 * k) / fct;
		fct = 1;
		sum_S += S;
	}
	cout << "sum_S ravno:" << sum_S << "      ";
	sum_S = 0;

}


void fun2(double a) {
	Y = (exp(x) + exp(-x)) / 2;
	cout << "Y ravno:" << Y << endl;

}

void fun3(double a, double b, double h, int n) {
	Y = (exp(x) + exp(-x)) / 2;
	cout << "Y ravno:" << Y << "      ";
	for (k = 0; k <= n; k++) {
		for (y = 1; y <= 2 * k; y++) {
			fct = fct * y;
		}
		S = pow(x, 2 * k) / fct;
		fct = 1;
		sum_S += S;
	}
	cout << "sum_S ravno:" << sum_S << "      ";
	cout << "|Y-sum_S| ravno:" << fabs(Y - sum_S) << endl;
	sum_S = 0;
}