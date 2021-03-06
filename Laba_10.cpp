// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
using namespace std;
class Predpriyatie {
public:
	char soname[20];
	char name[20];
	int n_otdela;
	char dolgnost[20];
	char data_nachala_raboti[10];
	int chislo;
	int mesyac;
	int god;
};
Predpriyatie rabotnik[50];

void input_by_file(int *pd);
void show(int *pcolvo);
void add(int *pcolvo);
int poisk(char str[], int *pcolvo);
void pryam_vibor(int *pcolvo);
int bin_poisk(int left, int right, int key_g, int key_m, int key_c);
void qs(int left, int right);

int main()
{
	int colvo;
	int vibor;
	int d = 0;
	setlocale(LC_ALL, "RUS");
	input_by_file(&d);
	system("cls");
	colvo = d;
	while (true) {
		system("cls");
		cout << "Выберите действие, которое хотите произвести:\n 1) Просмотр списка сотрудников \n 2) Добавление работников в файл \n 3) Поиск \n 4) Сортировка прямой выбор \n 5) Сортировка QuickSort \n 6) Двоичный поиск \n 7) Выход \n";
		cin >> vibor;
		switch (vibor) {
		case 1:
			show(&colvo);
			break;
		case 2:
			add(&colvo);
			break;
		case 3:
			cout << "Введите дату начала работы: ";
			char  str[10];
			cin >> str;
			{int index = poisk(str, &colvo);
			if (index != -1) cout << "В этот день на работу устраивался " << rabotnik[index].soname << " " << rabotnik[index].name << endl;
			else cout << "В этот день на работу никто не устраивался" << endl;
			break;
			}
		case 4:
			pryam_vibor(&colvo);
			break;
		case 5:
			qs(0, colvo - 1);
			break;
		case 6:
		{
			int p_chislo, p_mesyac, p_god;
			cout << "Введите день начала работы: ";
			cin >> p_chislo;
			cout << "Введите месяц начала работы: ";
			cin >> p_mesyac;
			cout << "Введите год начала работы: ";
			cin >> p_god;
			{int index = bin_poisk(0, colvo - 1, p_god, p_mesyac, p_chislo);
			if (index != -1) cout << "В этот день на работу устраивался " << rabotnik[index].soname << " " << rabotnik[index].name << endl;
			else cout << "В этот день на работу никто не устраивался" << endl;
			break;
			}
		}
		case 7:
			return 0;
			break;
		}
	}
	return 0;
}
void input_by_file(int *pd) {
	{ifstream F("OAuPvvod.txt");
	if (!F) cout << "Ошибка\n";
	while (!F.eof()) {
		F >> rabotnik[*pd].soname;
		F >> rabotnik[*pd].name;
		F >> rabotnik[*pd].n_otdela;
		F >> rabotnik[*pd].dolgnost;
		F >> rabotnik[*pd].data_nachala_raboti;
		rabotnik[*pd].chislo = ((int)rabotnik[*pd].data_nachala_raboti[0] - 48) * 10 + (int)rabotnik[*pd].data_nachala_raboti[1] - 48;
		rabotnik[*pd].mesyac = ((int)rabotnik[*pd].data_nachala_raboti[3] - 48) * 10 + (int)rabotnik[*pd].data_nachala_raboti[4] - 48;
		rabotnik[*pd].god = ((int)rabotnik[*pd].data_nachala_raboti[6] - 48) * 1000 + ((int)rabotnik[*pd].data_nachala_raboti[7] - 48) * 100 + ((int)rabotnik[*pd].data_nachala_raboti[8] - 48) * 10 + (int)rabotnik[*pd].data_nachala_raboti[9] - 48;
		if (F.eof()) break;
		else ++*(pd);
	}
	F.close(); }
}

void show(int *pcolvo) {
	{ofstream F("OAuPvvod.txt");
	if (!F) cout << "Ошибка\n";
	for (int k = 0; k < *pcolvo; k++) {
		F << rabotnik[k].soname << " " << rabotnik[k].name << " " << rabotnik[k].n_otdela << " " << rabotnik[k].dolgnost << " ";
		if ((rabotnik[k].chislo / 10) >= 1) F << rabotnik[k].chislo << '.';
		else F << '0' << rabotnik[k].chislo << '.';
		if ((rabotnik[k].mesyac / 10) >= 1) F << rabotnik[k].mesyac << '.';
		else F << '0' << rabotnik[k].mesyac << '.';
		F << rabotnik[k].god << endl;
		cout << rabotnik[k].soname << " " << rabotnik[k].name << " " << rabotnik[k].n_otdela << " " << rabotnik[k].dolgnost << " ";
		if ((rabotnik[k].chislo / 10) >= 1) cout << rabotnik[k].chislo << '.';
		else cout << '0' << rabotnik[k].chislo << '.';
		if ((rabotnik[k].mesyac / 10) >= 1) cout << rabotnik[k].mesyac << '.';
		else cout << '0' << rabotnik[k].mesyac << '.';
		cout << rabotnik[k].god << endl;
	}
	F.close();
	}
}

void add(int *pcolvo) {
	cin >> rabotnik[*pcolvo].soname >> rabotnik[*pcolvo].name >> rabotnik[*pcolvo].n_otdela >> rabotnik[*pcolvo].dolgnost >> rabotnik[*pcolvo].data_nachala_raboti;
	rabotnik[*pcolvo].chislo = ((int)rabotnik[*pcolvo].data_nachala_raboti[0] - 48) * 10 + (int)rabotnik[*pcolvo].data_nachala_raboti[1] - 48;
	rabotnik[*pcolvo].mesyac = ((int)rabotnik[*pcolvo].data_nachala_raboti[3] - 48) * 10 + (int)rabotnik[*pcolvo].data_nachala_raboti[4] - 48;
	rabotnik[*pcolvo].god = ((int)rabotnik[*pcolvo].data_nachala_raboti[6] - 48) * 1000 + ((int)rabotnik[*pcolvo].data_nachala_raboti[7] - 48) * 100 + ((int)rabotnik[*pcolvo].data_nachala_raboti[8] - 48) * 10 + (int)rabotnik[*pcolvo].data_nachala_raboti[9] - 48;
	*(pcolvo) += 1;
}

int poisk(char str[], int *pcolvo) {
	bool on_est = true;
	for (int i = 0; i < *pcolvo; i++) {
		for (int x = 0; x < 10; x++) {
			if (rabotnik[i].data_nachala_raboti[x] != str[x]) on_est = false;
		}
		if (on_est == true) {
			return i;
		}
		on_est = true;
	}
}

void pryam_vibor(int *pcolvo) {
	for (int y = 0; y < *pcolvo; y++) {
		int min;
		Predpriyatie vremennaya;
		min = y;
		for (int z = y + 1; z < *pcolvo; z++) {
			if (rabotnik[z].god < rabotnik[min].god) {
				min = z;
			}
			if (rabotnik[z].god == rabotnik[min].god)  if (rabotnik[z].mesyac < rabotnik[min].mesyac) {
				min = z;
			}
			if (rabotnik[z].god == rabotnik[min].god)  if (rabotnik[z].mesyac == rabotnik[min].mesyac) if (rabotnik[z].chislo < rabotnik[min].chislo) {
				min = z;
			}
		}
		vremennaya = rabotnik[min];
		rabotnik[min] = rabotnik[y];
		rabotnik[y] = vremennaya;
	}
}

void qs(int left, int right) {
	int i = left, j = right;
	Predpriyatie temp;
	int pivot_g = rabotnik[(left + right) / 2].god; //значения среднего элемента
	int pivot_m = rabotnik[(left + right) / 2].mesyac;
	int pivot_c = rabotnik[(left + right) / 2].chislo;
	//тело
	while (i < j) {
		while ((rabotnik[i].god < pivot_g) || ((rabotnik[i].god == pivot_g) & (rabotnik[i].mesyac < pivot_m)) || ((rabotnik[i].god == pivot_g) & (rabotnik[i].mesyac == pivot_m) & (rabotnik[i].chislo < pivot_c))) i++;
		while ((rabotnik[j].god > pivot_g) || ((rabotnik[j].god == pivot_g) & (rabotnik[j].mesyac > pivot_m)) || ((rabotnik[j].god == pivot_g) & (rabotnik[j].mesyac == pivot_m) & (rabotnik[j].chislo > pivot_c))) j--;
		if (i <= j) {
			temp = rabotnik[i];
			rabotnik[i] = rabotnik[j];
			rabotnik[j] = temp;
			i++;
			j--;
		}
	}
	//рекурсия
	if (left < j) qs(left, j);
	if (i < right) qs(i, right);
}

int bin_poisk(int left, int right, int key_g, int key_m, int key_c)
{
	int midd = 0;
	while (true)
	{
		midd = (left + right) / 2;
		if (key_g < rabotnik[midd].god) right = midd - 1;	  // если искомое меньше значения в ячейке, смещаем правую границу поиска
		if (key_g == rabotnik[midd].god) if (key_m < rabotnik[midd].mesyac) right = midd - 1;
		if (key_g == rabotnik[midd].god) if (key_m == rabotnik[midd].mesyac) if (key_c < rabotnik[midd].chislo) right = midd - 1;
		if (key_g > rabotnik[midd].god) left = midd + 1; // если искомое больше значения в ячейке, смещаем левую границу поиска
		if (key_g == rabotnik[midd].god) if (key_m > rabotnik[midd].mesyac) left = midd + 1;
		if (key_g == rabotnik[midd].god) if (key_m == rabotnik[midd].mesyac) if (key_c > rabotnik[midd].chislo) left = midd + 1;
		if (key_g == rabotnik[midd].god) if (key_m == rabotnik[midd].mesyac) if (key_c == rabotnik[midd].chislo) return midd;									// иначе (значения равны) функция возвращает индекс ячейки
		if (left > right)  return -1;						// если границы сомкнулись 
	}
}


