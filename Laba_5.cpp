// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int razmer, i, j; // i, j - indeksi elementov
bool pravda_ili_log;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Vvedite kolvo stolbcov (strok) ";
	cin >> razmer;
	int** massiv = new int*[razmer];
	for (i = 0; i < razmer; i++) {
		massiv[i] = new int[razmer];
	}
	for (i = 0; i < razmer; i++) {
		for (j = 0; j < razmer; j++)
		{
			cout << "Vvedite element (" << i << "," << j << ") ";
			cin >> massiv[i][j];
			cout << endl;
		}
	}
	pravda_ili_log = true;
	for (i = 0; i < razmer; i++) {
		for (j = 0; j < razmer; j++) {
			if (massiv[i][j] != massiv[j][i]) pravda_ili_log = false;
		}
	}
	if (pravda_ili_log == true) cout << "Matrica simmetrichna" << endl;
	if (pravda_ili_log == false) cout << "Matrica ne simmetrichna" << endl;
	system("pause");
	return 0;
}