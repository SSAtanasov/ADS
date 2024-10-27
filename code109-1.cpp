#include <iostream>
using namespace std;

// Примерно описание на структурата на двусвързан списък
struct elem {
	int key;
	elem *pred;
	elem *next;
};

// 1. Включване на елемент в началото на двусвързан списък
void add1(elem* &start, int n) {
	elem* p = new elem;	// създаване на новия елемент
	p->key = n;
	p->next = start;
	p->pred = NULL;	// насочване на указателите

	if (start != NULL) {
		start->pred = p;
	}
	start = p;
}

// 2. Включване на междинен елемент със стойност n в списъка преди друг елемент с ключова стойност k
void add2(elem* &start, int n, int k) {
	elem *q;
	elem *p = start;

	// търсене на елемента с ключ k
	while (p != NULL && p->key != k) {
		p = p->next;
	}

	if (p != NULL) {	// проверка дали елементът е намерен
		q = new elem;	// създаване на нов елемент
		q->key = p->key;
		q->next = p->next;
		q->pred = p;

		if (p->next != NULL) {
			p->next->pred = q;
		}

		p->next = q;
		p->key = n;	// обновяване на ключа на p
	}
}

// 3. Включване на междинен елемент със стойност n в списъка след друг елемент с ключова стойност k
void add3(elem* &start, int n, int k) {
	elem *q;
	elem *p = start;

	// търсене на елемента с ключ k
	while (p != NULL && p->key != k) {
		p = p->next;
	}

	if (p != NULL) {	// проверка дали елементът е намерен
		q = new elem;	// създаване на нов елемент
		q->key = n;
		q->next = p->next;

		if (p->next != NULL) {
			p->next->pred = q;
		}

		p->next = q;
		q->pred = p;
	}
}

// 4. Включване на последен елемент със стойност n в двусвързан списък
void add4(elem* &start, int n) {
	elem *p = start, *q;
	q = new elem;	// създаване на нов елемент
	q->key = n;
	q->next = NULL;

	// проверка дали списъкът е непразен
	if (start != NULL) {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = q;
		q->pred = p;
	} else {
		start = q;
		q->pred = NULL;
	}
}

// 5. Изключване на първия елемент от двусвързан списък
// стойността на изтрития елемент е достъпна в main()
void del1(elem* &start, int &n) {
	elem *p = start;
	n = start->key;
	start = start->next;	// пренасочване на връзките

	if (start != NULL) {
		start->pred = NULL;
	}
	delete p;	// изключване на елемента
}

// 6. Изключване на междинен елемент със стойност n от двусвързан списък
void del2(elem* &start, int n) {
	elem *p = start;

	// търсене на елемента с ключ n
	while (p != NULL && p->key != n) {
		p = p->next;
	}

	if (p != NULL) {	// проверка дали елементът е намерен
		if (p->pred != NULL) {
			p->pred->next = p->next;
		}
		if (p->next != NULL) {
			p->next->pred = p->pred;
		}
		delete p;	// изтриване на елемента
	}
}

// 7. Изключване на последен елемент от двусвързан списък
void del3(elem* &start, int &n) {
	elem *p = start;

	// търсене на последния елемент
	while (p->next != NULL) {
		p = p->next;
	}
	n = p->key;

	if (p->pred != NULL) {
		p->pred->next = NULL;
	}
	delete p;	// изтриване на елемента
}

int main() {
	int i, n, a;
	elem* start = NULL;

	cout << "Enter the number of elements: ";
	cin >> n;

	// Въвеждане на елементи и добавяне в началото на списъка
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		add1(start, a);
	}

	cout << "Elements of the list:" << endl;
	elem *p = start;

	// Обхождане на списъка и извеждане на елементите му
	while (p != NULL) {
		cout << p->key << endl;
		p = p->next;
	}

	del1(start, a);
	cout << "Deleted first element: " << a << endl;

	cout << "Remaining elements of the list:" << endl;
	p = start;

	// Обхождане на списъка и извеждане на оставащите елементи
	while (p != NULL) {
		cout << p->key << endl;
		p = p->next;
	}

	return 0;
}
