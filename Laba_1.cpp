// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int a;
	double z, x, y, c, d, u;
	cout << "Vvedite peremennyu Z:";
	cin >> z;
	if (z < 1) x = pow(z, 2);
	else x = z - 1;
	cout << "Vvedite chislo ot 1 do 3:" << endl << "1)u=2*x " << endl << "2)u=x^2" << endl << "3)u=x/3" << endl;
	cin >> a;
	switch (a) {
	case 1: u = 2 * x; break;
	case 2: u = pow(x, 2); break;
	case 3: u = x / 3; break;
	default:cout << "Ashibka" << endl; return 1;
	}
	cout << "Znachenie peremennou D:";
	cin >> d;
	cout << "Znachenie peremennou C:";
	cin >> c;
	y = (d*u*exp(pow(sin(x), 3)) + c * log(x + 1)) / sqrt(x);
	cout << "Viragenie ravno:" << y;
	system("pause");
	return 0;
}