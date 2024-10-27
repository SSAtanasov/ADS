#include <iostream>
using namespace std;

// Структура за свързан списък
struct pstack {
	int i;          // Стойност на елемент в списъка
	pstack* next;   // Указател към следващия елемент
};

// Функция за добавяне на елемент в началото на списъка
void insert(pstack*& l, int x) {
	pstack* p = new(pstack);  // Създаване на нов елемент
	p->i = x;                 // Записване на стойността
	p->next = l;              // Свързване с предишния начален елемент
	l = p;                    // Пренасочване на началото на списъка
}

// Функция за премахване на елемент от началото на списъка
void pop(pstack*& l) {
	// Проверка дали списъкът е празен
	if (l == NULL) {
		cout << "Stack is empty" << endl;
	} else {
		pstack* p = l;   // Временен указател към началния елемент
		l = l->next;     // Преместване на началото към следващия елемент
		delete(p);       // Изтриване на стария начален елемент
	}
}

// Функция за отпечатване на всички елементи в списъка
void printl(pstack* l) {
	while (l != NULL) {
		cout << l->i << endl;  // Печат на стойността на текущия елемент
		l = l->next;           // Преминаване към следващия елемент
	}
}

int main() {
	int n, i, a;
	pstack* list = NULL;  // Инициализиране на списъка като празен

	cout << "Enter number of elements to add: ";
	cin >> n;

	// Четене на елементи и добавяне в началото на списъка
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		insert(list, a);
	}

	// Печат на списъка след въвеждане на елементите
	cout << "List after insertion:" << endl;
	printl(list);

	// Премахване на първия елемент и печат на списъка
	cout << "List after popping one element:" << endl;
	pop(list);
	printl(list);

	return 0;
}
