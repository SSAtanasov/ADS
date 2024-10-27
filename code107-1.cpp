#include <iostream>
using namespace std;

// Дефиниране на структура на елемент от списъка
struct plist {
	int i;          // Стойност на елемента
	plist* next;    // Указател към следващия елемент
};

// Подпрограма за включване на елемент в началото на списък
void insertBegin(plist*& l, int x) {
	plist* p = new plist;
	p->i = x;
	p->next = l;
	l = p;
}

// Включване на елемент след даден елемент (l) в списък
void insertAfter(plist*& l, int x) {
	if (l == NULL) {
		insertBegin(l, x); // Ако списъкът е празен, вмъкваме елемента в началото
	} else {
		plist* p = new plist;
		p->i = x;
		p->next = l->next;
		l->next = p;
	}
}

// Включване на елемент преди даден елемент (l) в списък
void insertBefore(plist*& l, int x) {
	if (l == NULL) {
		insertBegin(l, x); // Ако списъкът е празен, вмъкваме елемента в началото
	} else {
		plist* p = new plist;
		p->i = l->i;
		p->next = l->next;
		l->i = x;
		l->next = p;
	}
}

// Подпрограма за изтриване на елемент с дадена стойност от списък
void deletel(plist*& l, int x) {
	plist* p = l;
	plist* q;

	// Проверка дали първият елемент е този за изтриване
	if (l != NULL && l->i == x) {
		l = l->next;
		delete p;
	} else {
		// Търсене на елемента за изтриване
		while (p->next != NULL && p->next->i != x) {
			p = p->next;
		}
		// Ако елементът е намерен, той се изтрива
		if (p->next != NULL) {
			q = p->next;
			p->next = p->next->next;
			delete q;
		}
	}
}

// Подпрограма за търсене на елемент в списък (връща указател към елемента с търсената стойност)
plist* search(plist* l, int x) {
	while (l != NULL) {
		if (l->i == x) {
			return l; // Връща указател към намерения елемент
		}
		l = l->next;
	}
	return NULL; // Връща NULL, ако елементът не е намерен
}

// Подпрограма за обхождане и отпечатване на елементите на списък
void printl(plist* l) {
	while (l != NULL) {
		cout << l->i << endl;
		l = l->next;
	}
}

// Главна функция
int main() {
	int n, i, a;
	plist* list = NULL;

	cout << "Enter the number of elements: "; // Подканване за въвеждане на брой елементи
	cin >> n;

	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": "; // Подканване за въвеждане на елемент
		cin >> a;
		insertBegin(list, a); // Вмъкване на елемент в началото на списъка
	}

	cout << "Enter the value to search: "; // Подканване за търсене на стойност
	cin >> a;
	if (search(list, a) != NULL)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << "List elements:" << endl;
	printl(list); // Отпечатване на елементите на списъка

	return 0;
}
