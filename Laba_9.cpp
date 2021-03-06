// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
using namespace std;
int Fibonnachi(int chislo);
int Fibonnachi_R(int chislo);
int vibor;
int chislo;
int a[100];
int peremennaay;
int main()
{
	setlocale(LC_ALL, "RUS");
	while (true) {
		cout << "Числа Фибоначчи\n Выберите: 1-использование обычных функций, 2-использование рекурсивных функций\n";
		cin >> vibor;
		switch (vibor) {
		case 1:
			cout << "Обычная функция\n Введите порядковый номер числа, до которого нужно выполнять функцию\n";
			cin >> chislo;
			if (chislo <= 0) cout << "Номер числа должен быть целым неотрицательным и не равным 0\n";
			else cout << "Число Фибоначчи равно " << Fibonnachi(chislo) << endl << "-------------------" << endl;
			break;
		case 2:
			cout << "Рекурсивная функция\n Введите порядковый номер числа, до которого нужно функцию\n";
			cin >> chislo;
			if (chislo <= 0) cout << "Номер числа должен быть целым неотрицательным и не равным 0\n";
			else cout << "Число Фибоначчи равно " << Fibonnachi_R(chislo) << endl << "-------------------" << endl;
			break;
		}
	}
	return 0;
}
int Fibonnachi(int chislo) {
	a[0] = 0;
	a[1] = 1;
	if (chislo > 2) {
		for (int b = 2; b <= chislo - 1; b++) a[b] = a[b - 1] + a[b - 2];
	}
	return a[chislo - 1];

}
int Fibonnachi_R(int chislo) {
	if (chislo == 1) return 0;
	if (chislo == 2) return 1;
	if (chislo > 2) return Fibonnachi_R(chislo - 1) + Fibonnachi_R(chislo - 2);
}