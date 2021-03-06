// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
using namespace std;

struct Stak
{
	int x; //информационный элемент
	Stak *Next, *Head; //Голова стека и указатель на следующий элемент
};

/*ФУНКЦИЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА В СТЕК (в список LIFO)*/
void Add(int x, Stak *&MyStak) //Принимаем элемент стека и указатель на стек, при этом говорим, что принимаемый указатель будет сам по себе указателем
{
	Stak *temp = new Stak; //Выделяем память для нового элемента
	temp->x = x; //Записываем в поле x принимаемый в функцию элемент x
	temp->Next = MyStak->Head; //Указываем, что следующий элемент это предыдущий
	MyStak->Head = temp; //Сдвигаем голову на позицию вперед
}

/*ФУНКЦИЯ ОТОБРАЖЕНИЯ СТЕКА*/
void Show(Stak *MyStak) //Нужен только сам стек
{
	Stak *temp = MyStak->Head; //Объявляем указатель и Указываем ему, что его позиция в голове стека
							   //с помощью цикла проходим по всему стеку
	while (temp != NULL) //выходим при встрече с пустым полем
	{
		cout << temp->x << " "; //Выводим на экран элемент стека
		temp = temp->Next; //Переходим к следующему элементу
	}
}

/*ФУНКЦИЯ УДАЛЕНИЯ СТЕКА ИЗ ПАМЯТИ*/
void ClearStak(Stak *MyStak)
{
	while (MyStak->Head != NULL) //Пока по адресу не пусто
	{
		Stak *temp = MyStak->Head->Next; //Временная переменная для хранения адреса следующего элемента
		delete MyStak->Head; //Освобождаем адрес обозначающий начало
		MyStak->Head = temp; //Меняем адрес на следующий
	}
}

//ФУНКЦИЯ СОРТИРОВКИ ЧЕРЕЗ ПЕРЕСТАНОВКУ АДРЕСОВ
void Sort_p(Stak *MyStak) {
	Stak *t = NULL, *t1, *r;
	Stak **p = &MyStak->Head;
	if ((*p)->Next->Next == NULL) return;
	do {
		for (t1 = *p; t1->Next->Next != t; t1 = t1->Next)
			if (t1->Next->x > t1->Next->Next->x) {
				r = t1->Next->Next;
				t1->Next->Next = r->Next;
				r->Next = t1->Next;
				t1->Next = r;
			}
		t = t1->Next;
	} while ((*p)->Next->Next != t);
}

//ФУНКЦИЯ СОРТИРОВКИ ЧЕРЕЗ ПЕРЕСТАНОВКУ ЗНАЧЕНИЙ
void Sort_x(Stak *MyStak) {
	Stak *t = NULL, *t1;
	Stak *p = MyStak->Head;
	int r;
	do {
		for (t1 = p; t1->Next != t; t1 = t1->Next)
			if (t1->x > t1->Next->x) {
				r = t1->x;
				t1->x = t1->Next->x;
				t1->Next->x = r;
			}
		t = t1;
	} while (p->Next != t);
}

//В созданном списке определить количество элементов, имеющих значения, меньше среднего значения от всех элементов, и удалить эти элементы
void Individual(Stak *MyStak) {
	Stak *temp = MyStak->Head;
	int sum = 0, i = 0, k = 0;
	while (temp != NULL)
	{
		sum += temp->x;
		i++;
		temp = temp->Next;
	}
	Add(0, MyStak);
	temp = MyStak->Head;
	while (temp->Next != NULL)
	{
		if (temp->Next->x < sum / i) {
			Stak *temp2 = temp->Next->Next;
			delete temp->Next;
			temp->Next = temp2;
			k++;
		}
		else temp = temp->Next;
	}
	{Stak *a = MyStak->Head->Next;
	delete MyStak->Head;
	MyStak->Head = a; }
	cout << "Количество элементов, имеющих значение меньше среднего - " << k << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Stak *MyStak = new Stak; //Выделяем память для стека
	MyStak->Head = NULL; //Во избежание ошибок инициализируем первый элемент
	while (true) {
		cout << "Введите действие, которое хотите выполнить: \n 1 - Добавить элемент в стек \n 2 - Вывести стек на экран \n 3 - Очистить стек \n 4 - Сортировка перестановкой адресов \n 5 - Сортировка перестановкой значений \n 6 - Индивидуальное задание \n 7 - Выход \n";
		int vibor;
		cin >> vibor;
		switch (vibor) {
		case 1:
		{
			int i;
			cout << "Введите значение элемента: ";
			cin >> i;
			Add(i, MyStak);
		}
		break;
		case 2:
			Show(MyStak);
			cout << endl;
			break;
		case 3:
			ClearStak(MyStak);
			break;
		case 4:
			Sort_p(MyStak);
			break;
		case 5:
			Sort_x(MyStak);
			break;
		case 6:
			Individual(MyStak);
			break;
		case 7:
			return 0;
			break;
		}
	}
	delete MyStak->Head;
	delete MyStak;
	return 0;
}
/*Написать программу по созданию, добавлению, просмотру и решению поставленной задачи
 для однонаправленного линейного списка типа СТЕК.
Реализовать сортировку стека двумя рассмотренными выше методами.
В созданном списке определить количество элементов, имеющих значения,
меньше среднего значения от всех элементов, и удалить эти элементы*/
