// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int i = 0, j = 0, x = 0, colvo, element = 0, cifra = 0, vse = 0;

int main()
{
	setlocale(LC_ALL, "RUS");
	char massiv1[30];//kotori vvodim
	int massiv2[30];//pozicii probelov
	int massiv3[30];//tol'ko chetnie
	cout << "VVedite elementi massiva" << endl;
	cin >> massiv1;
	x = strlen(massiv1);
	massiv1[x] = ' ';
	massiv1[x + 1] = '\0';
	for (i = 0; i <= x; i++) {
		if (massiv1[i] == ' ') {
			massiv2[j] = i;
			j++;
		}
	}
	x = 0;
	colvo = j - 1;
	j = 0;
	cout << colvo << endl;
	if ((massiv1[massiv2[0] - 1] - 48) % 2 == 0) {
		for (i = 0; i < massiv2[0]; i++) {// ot 0 do pervogo probela
			cifra = (massiv1[i] - 48) * pow(10, massiv2[0] - 1 - i);
			element += cifra;
		}
		massiv3[x] = element;
		x++;
		cout << "1-i element = " << massiv3[0] << endl;
		element = 0;
	}
	for (j = 0; j < colvo; j++) {    //ot pervogo nomera probela do poslednego
		if ((massiv1[massiv2[j + 1] - 1] - 48) % 2 == 0) {
			for (i = massiv2[j] + 1; i < massiv2[j + 1]; i++) { //ot odnogo probela do next
				cifra = (massiv1[i] - 48) * pow(10, massiv2[j + 1] - i - 1);
				element += cifra;
			}
			massiv3[x] = element;
			x++;
			element = 0;
			cifra = 0;
		}
	}
	vse = x;
	cout << "Tol'ko chetnie:";
	for (x = 0; x < vse; x++) cout << massiv3[x] << " ";
	system("pause");
	return 0;
}