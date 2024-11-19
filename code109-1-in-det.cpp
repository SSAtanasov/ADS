#include <iostream>
using namespace std;

// Структура за двусвързан списък
// Включва ключова стойност и два указателя: към предходния и следващия елемент.
struct elem {
	int key;
	elem *pred; // Указател към предходния елемент
	elem *next; // Указател към следващия елемент
};

// 1. Добавяне на елемент в началото на списъка
void add1(elem* &start, int n) {
	elem* p = new elem;	// Създаване на нов елемент
	p->key = n;         // Задаване на ключовата стойност
	p->next = start;    // Насочване към текущото начало
	p->pred = NULL;     // Първият елемент няма предходен

	if (start != NULL) {
		start->pred = p; // Настройка на указателя pred за предходния елемент
	}
	start = p;          // Пренасочване на старт към новия елемент
}

// 2. Добавяне на елемент преди елемент с ключ k
void add2(elem* &start, int n, int k) {
	elem *q;
	elem *p = start;

	// Търсене на елемента с ключ k
	while (p != NULL && p->key != k) {
		p = p->next;
	}

	if (p != NULL) {	// Ако елементът е намерен
		q = new elem;	// Създаване на нов елемент
		q->key = p->key;
		q->next = p->next; // Насочване към следващия елемент
		q->pred = p;       // Настройка на предходния указател

		if (p->next != NULL) {
			p->next->pred = q; // Корекция на предходния указател на следващия елемент
		}

		p->next = q;
		p->key = n;	// Задаване на новата стойност на ключа
	}
}

// 3. Добавяне на елемент след елемент с ключ k
void add3(elem* &start, int n, int k) {
	elem *q;
	elem *p = start;

	// Търсене на елемента с ключ k
	while (p != NULL && p->key != k) {
		p = p->next;
	}

	if (p != NULL) {	// Ако елементът е намерен
		q = new elem;	// Създаване на нов елемент
		q->key = n;
		q->next = p->next; // Насочване към следващия елемент

		if (p->next != NULL) {
			p->next->pred = q; // Настройка на предходния указател
		}

		p->next = q;
		q->pred = p;         // Настройка на предходния указател на новия елемент
	}
}

// 4. Добавяне на последен елемент
void add4(elem* &start, int n) {
	elem *p = start, *q;
	q = new elem;	// Създаване на нов елемент
	q->key = n;
	q->next = NULL; // Последният елемент няма следващ

	if (start != NULL) { // Ако списъкът не е празен
		while (p->next != NULL) {
			p = p->next; // Обхождане до последния елемент
		}
		p->next = q;
		q->pred = p; // Настройка на предходния указател
	} else { // Ако списъкът е празен
		start = q;
		q->pred = NULL; // Първият елемент няма предходен
	}
}

// 5. Изтриване на първия елемент
void del1(elem* &start, int &n) {
	elem *p = start;
	n = start->key;       // Запазване на ключа за връщане
	start = start->next;  // Насочване към втория елемент

	if (start != NULL) {
		start->pred = NULL; // Премахване на връзката с предходния
	}
	delete p; // Изтриване на първия елемент
}

// 6. Изтриване на елемент със стойност n
void del2(elem* &start, int n) {
	elem *p = start;

	// Търсене на елемента с ключ n
	while (p != NULL && p->key != n) {
		p = p->next;
	}

	if (p != NULL) { // Ако елементът е намерен
		if (p->pred != NULL) {
			p->pred->next = p->next; // Пренасочване на предходния елемент
		}
		if (p->next != NULL) {
			p->next->pred = p->pred; // Пренасочване на следващия елемент
		}
		delete p; // Изтриване на елемента
	}
}

// 7. Изтриване на последен елемент
void del3(elem* &start, int &n) {
	elem *p = start;

	// Търсене на последния елемент
	while (p->next != NULL) {
		p = p->next;
	}
	n = p->key; // Запазване на стойността

	if (p->pred != NULL) {
		p->pred->next = NULL; // Пренасочване на връзките
	}
	delete p; // Изтриване на последния елемент
}

int main() {
	int i, n, a;
	elem* start = NULL;

	cout << "Enter the number of elements: ";
	cin >> n;

	// Добавяне на елементи в началото
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		add1(start, a); // Използване на функцията за добавяне в началото
	}

	cout << "Elements of the list:" << endl;
	elem *p = start;

	// Извеждане на елементите
	while (p != NULL) {
		cout << p->key << endl;
		p = p->next;
	}

	del1(start, a);
	cout << "Deleted first element: " << a << endl;

	cout << "Remaining elements of the list:" << endl;
	p = start;

	// Извеждане на оставащите елементи
	while (p != NULL) {
		cout << p->key << endl;
		p = p->next;
	}

	return 0;
}
