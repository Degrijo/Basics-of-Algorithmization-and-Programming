// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int a, i, m, naim, Sum = 0, razmer, k;
	cout << "Vvedite razmer massiva" << endl;
	cin >> razmer;
	int *massiv = new int[razmer];
	cout << "Vvedite cifry 1 ili 2, kotoraya opredelyaet kak zadaetca masiv, polzovatelem ili randomno(v predelah ot 1 do 15):" << endl;
	cin >> a;
	switch (a) {
	case 1:
		cout << "Vvedite elementi massiva" << endl;
		for (i = 0; i < razmer; i++) {
			cin >> massiv[i];
		}
		break;
	case 2: for (i = 0; i < razmer; i++) {
		massiv[i] = 1 + rand() % 15;
	}
			break;
	default:
		cout << "Oshibka, vi vveli neverni simvol";
		break;
	}
	naim = massiv[i];
	cout << "Elementi massiva - ";
	for (i = 0; i < razmer; i++) {  // poisk naimenshego chisla
		cout << massiv[i] << "   ";
		if (massiv[i] <= naim) {
			naim = massiv[i];
			k = i;
		}
	}
	cout << endl;
	for (m = k + 1; m < razmer; m++) { // summa elementov posle naim
		Sum += fabs(massiv[m]);
	}
	cout << "Summa elementov massiva posle naimenshego=" << Sum;
	system("pause");
	return 0;
}