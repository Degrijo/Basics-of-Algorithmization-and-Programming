// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
void fun1(double x);
void fun2(double x, int k, int n);
void fun3(double x, int k, int n);
double funcziyaS(double x, int k, int n) {
	return  S = pow(x, 2 * k) / fct;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, k, u;
	double a, b, h, x, y, sum_S, Y, S;
	long double fct;
	cout << "Vvedite a, b, h" << endl;
	cin >> a >> b >> h;
	cout << "viberite funkcii Y, S ili |Y-S|, nagav sootvetstvenno klavishi 1, 2, 3" << endl;
	cin >> u;
	switch (u) {
	case 1: cout << "Function Y:" << endl;// переменные x
		for (x = a; x <= b; x += h)
		{
			fun1(x);
		}
		break;
	case 2: cout << "Function S:" << endl;// переменные x, k, n
		cout << "Vvedite n" << endl;
		sum_S = 0;
		cin >> n;
		for (x = a; x <= b; x += h)
		{
			for (k = 0; k <= n; k++) {
				fct = 1;
				for (y = 1; y <= 2 * k; y++) {
					fct = fct * y;
				}
				sum_S += funcziyaS(x, k, n);
				fct = 1;
			}
			cout << "S ravno:" << sum_S << endl;
			sum_S = 0; ;
		}
		break;
	case 3: cout << "Function Y-S:" << endl;// переменные x, k, n 
		cout << "Vvedite n" << endl;
		cin >> n;
		for (x = a; x <= b; x += h)
		{
			fun3(x, k, n);
		}
		break;
	default: cout << "Mistake";  break;
	}
	system("pause");
	return 0;
}

void fun1(double x) //функция Y
{
	cout << "Pri x= " << x << "  ";
	Y = (exp(x) + exp(-x)) / 2;
	cout << "Y ravno:" << Y << endl;

}

void fun2(double x, int k, int n) { //функция S
	cout << "Pri x= " << x << "  ";
	for (k = 0; k <= n; k++) {
		fct = 1;
		for (y = 1; y <= 2 * k; y++) {
			fct = fct * y;
		}
		S = pow(x, 2 * k) / fct;
		fct = 1;
		sum_S += S;
	}
	cout << "S ravno:" << sum_S << endl;
	sum_S = 0;

}

void fun3(double x, int k, int n) { //функция Y-S
	cout << "Pri x= " << x << "  ";
	Y = (exp(x) + exp(-x)) / 2;
	sum_S = 0;
	for (k = 0; k <= n; k++) {
		fct = 1;
		for (y = 1; y <= 2 * k; y++) {
			fct = fct * y;
		}
		S = pow(x, 2 * k) / fct;
		fct = 1;
		sum_S += S;

	}
	cout << "|Y-sum_S| ravno:" << fabs(Y - sum_S) << endl;
	sum_S = 0;
}