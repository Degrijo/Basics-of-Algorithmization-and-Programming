// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
using namespace std;
struct Student {
	char soname[50];
	int year;
	int nubergroup;
	int otmetki[4];
	double srball;
};
int main(int argc, char* argv[])
{
	Student  stud[50];
	int d = 0;// number of student
	int colvo;// colvo studentov
	int a;// switch for menu
	int c;// switch for creation
	int sumotmetok = 0;
	int b;

	string line;//dlya perehoda na novuu stroky
	bool otmetka;
	while (true) {
		cout << "Viberite operaciu, vvedya sootvetstvyuchuu cifru:\n 1)------------Creation------------\n2)------------Checking------------\n3)------------Correction------------\n4)------------Solution------------ \n";
		cin >> a;
		switch (a) {
		case 1:
			cout << "------------Creation------------" << endl << "Choose: 1)input by Keyboard or 2)input from File\n";
			cin >> c;
			switch (c) {
			case 1:
				cin >> stud[d].soname >> stud[d].year >> stud[d].nubergroup;
				for (b = 0; b < 4; b++) cin >> stud[d].otmetki[b];
				for (b = 0; b < 4; b++) sumotmetok += stud[d].otmetki[b];
				stud[d].srball = sumotmetok / 4.;// vvesti otmetki i poschitat' ih sum
				d++;
				break;
			case 2:
			{fstream F("OAuPvvod.txt", ios::in);
			if (!F) return 1;
			while (!F.eof()) {
				F >> stud[d].soname;
				F >> stud[d].year;
				F >> stud[d].nubergroup;
				for (b = 0; b < 4; b++) F >> stud[d].otmetki[b];
				for (b = 0; b < 4; b++) {
					sumotmetok += stud[d].otmetki[b];
					stud[d].srball = sumotmetok / 4.;
				}
				sumotmetok = 0;
				d++;
			}
			F.close();
			break;
			}
			}
			colvo = d;
			break;
		case 2:
			cout << "------------Checking------------\n";
			{fstream F("OAuPvivod.txt", ios::out);
			if (!F) return 1;
			for (d = 0; d < colvo; d++) {
				cout << stud[d].soname << " " << stud[d].year << " " << stud[d].nubergroup << " ";
				F << stud[d].soname << " " << stud[d].year << " " << stud[d].nubergroup << " ";
				for (b = 0; b < 4; b++) {
					cout << stud[d].otmetki[b] << " ";
					F << stud[d].otmetki[b] << " ";
				}
				cout << stud[d].srball << " ";
				cout << endl;
				F << stud[d].srball << "\n";
			}
			F.close();
			break;
			}
		case 3:
			cout << "------------Correction------------\n";
			cout << "Let's correct inf in input file\n";
			d = 0;
			{ifstream F("OAuPvvod.txt");
			if (!F) return 1;
			while (!F.eof()) {

				F >> stud[d].soname;
				F >> stud[d].year;
				F >> stud[d].nubergroup;
				for (b = 0; b < 4; b++) F >> stud[d].otmetki[b];
				for (b = 0; b < 4; b++) {
					sumotmetok += stud[d].otmetki[b];
					stud[d].srball = sumotmetok / 4.;
				}
				sumotmetok = 0;
				d++;
			}
			F.close();
			colvo = d;
			}
			{ofstream F("OAuPvivod.txt");
			if (!F) return 1;
			for (d = 0; d < colvo; d++) {
				cout << stud[d].soname << " " << stud[d].year << " " << stud[d].nubergroup << " ";
				F << stud[d].soname << " " << stud[d].year << " " << stud[d].nubergroup << " ";
				for (b = 0; b < 4; b++) {
					cout << stud[d].otmetki[b] << " ";
					F << stud[d].otmetki[b] << " ";
				}
				cout << stud[d].srball << " ";
				cout << endl;
				F << stud[d].srball << "\n";
			}
			F.close();
			break;
			}

		case 4:
			cout << "------------Solution------------\n" << "Vivesti studentov, imeushih neudvl otmetki \n";
			for (d = 0; d < colvo; d++) {
				otmetka = true;
				for (b = 0; b < 4; b++)
				{
					if (stud[d].otmetki[b] < 4) otmetka = false;
				}
				if (otmetka == false) cout << stud[d].soname << " ";
				cout << endl;
			}
			break;
		}
	}
	return 0;
}