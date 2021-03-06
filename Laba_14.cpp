// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
using namespace std;

struct Tree
{
	int key;
	char info[20];
	Tree *left, *right;
};

struct ball
{
	char info[20];
};

Tree* createTree(char inf[20], int k)
{
	int i = 0;
	Tree *p = new Tree;
	p->key = k;
	p->left = NULL;
	p->right = NULL;
	while (inf[i] != '\0')
	{
		p->info[i] = inf[i];
		i++;
	}
	p->info[i] = '\0';
	i = 0;
	return p;
}

void addList(Tree *root, char inf[20], int k)
{
	Tree *prev = NULL, *t;
	bool find = true;
	t = root;
	while (t && find) {
		prev = t;
		if (k == t->key) {
			find = false;
			cout << "Dublucate Key!" << endl;
		}
		else
			if (k < t->key) t = t->left;
			else t = t->right;
	}
	if (find) {
		t = createTree(inf, k);
		if (k < prev->key) prev->left = t;
		else prev->right = t;
	}

	return;
}

Tree* delKey(Tree *root, int k) {
	Tree *Del, *Prev_Del, *R, *Prev_R;
	Del = root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != k) {
		Prev_Del = Del;
		if (Del->key > k) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) {
		cout << "There is no such key" << endl;
		return root;
	}

	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {

			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}

			if (Prev_R == Del) R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == root) root = R;
	else
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R;
		else Prev_Del->right = R;
	delete Del;
	return root;
}


void View_Tree(Tree *p, int level) {
	if (p != NULL) {
		View_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++) cout << " ";
		cout << p->info << "_" << p->key << endl;
		View_Tree(p->left, level + 1);
	}
}


int Find_key(Tree *p, int k)
{
	Tree *prev = NULL, *t;
	bool find = true;
	t = p;
	while (t && find) {
		prev = t;
		if (k == t->key) {
			find = false;
			cout << t->info << endl;
			return 1;
		}
		if (k < t->key) t = t->left;
		if (k > t->key)	 t = t->right;
	}
	return 0;
}

void Task(Tree *p, int *a)
{
	if (p->left == NULL && p->right == NULL) return;
	if (p->left != NULL && p->right != NULL)++*a;
	if (p->left != NULL) Task(p->left, a);
	if (p->right != NULL) Task(p->right, a);
}

void Mass(Tree *p, int* a)
{
	a[a[0]] = p->key;
	a[0]++;
	if (p->left == NULL && p->right == NULL) return;
	if (p->left != NULL) Mass(p->left, a);
	if (p->right != NULL) Mass(p->right, a);
}

ball* Find(Tree *p, int k)
{
	Tree *prev = NULL, *t;
	bool find = true;
	int i;
	ball *inf = new ball;
	t = p;
	while (t && find) {
		prev = t;
		if (k == t->key) {
			i = 0;
			find = false;
			while (t->info[i] != '\0')
			{
				inf->info[i] = t->info[i];
				i++;
			}
			inf->info[i] = '\0';
			return inf;
		}
		else
			if (k < t->key) t = t->left;
			else t = t->right;
	}
}

void Balance(Tree **p, int n, int k, int *a, Tree *root)
{
	ball *x;
	int i = 0;
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		x = Find(root, a[m]);
		(*p)->key = a[m];
		while (x->info[i] != '\0')
		{
			(*p)->info[i] = x->info[i];
			i++;
		}
		(*p)->info[i] = '\0';
		Balance(&(*p)->left, n, m, a, root);
		Balance(&(*p)->right, m + 1, k, a, root);
	}
}


int main()
{
	int key, kod, i, j, min, n;
	char info[20];
	int a, b[100];
	Tree *root = NULL;
	while (true)
	{
		cout << "Type\n 1 to add information,\n 2 to balance tree,\n 3 to show tree information,\n 4 to del key information,\n 5 to show key informayion,\n 6 to task,\n 0 to exit" << endl;
		cin >> kod;
		switch (kod)
		{
		case 1:
			cout << "Type key and information" << endl;
			cin >> key >> info;
			if (root == NULL) root = createTree(info, key);
			else addList(root, info, key);
			break;

		case 2:if (root == NULL) break;
			b[0] = 1;
			Mass(root, b);
			n = b[0];
			for (i = 1; i < n; i++)
			{
				min = b[i] + 1;
				for (j = i; j < n; j++) if (b[j] < min) {
					min = b[j];
					b[j] = b[i];
					b[i] = min;
				}
			}
			Balance(&root, 1, n, b, root);
			break;

		case 3: cout << endl;
			View_Tree(root, 0); cout << endl;
			break;

		case 4: cout << "input key" << endl;
			cin >> key;
			root = delKey(root, key);
			break;

		case 5: cout << "input key" << endl;
			cin >> key;
			i = Find_key(root, key);
			if (i == 0) cout << "There is no element with such key" << endl;
			break;

		case 6:
			a = 0;
			Task(root, &a);
			if (a == 0) cout << "there is no such elements" << endl;
			else cout << "The number of ancestors with 2 daughters" << a << endl;
			a = 0;
			break;

		case 0:
			return 0;
			break;

		}
	}
}