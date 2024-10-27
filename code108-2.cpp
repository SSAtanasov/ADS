#include <iostream>
using namespace std;

// Структура за свързана опашка
struct pq {
	int i;       // Стойност на елемент в опашката
	pq* next;    // Указател към следващия елемент
};

// Функция за добавяне на елемент в края на опашката
void pushq(pq*& top, pq*& bottom, int x) {
	pq* p = new(pq);   // Създаване на нов елемент
	p->i = x;          // Записване на стойността
	p->next = NULL;    // Настройка на следващия елемент към NULL

	if (top == NULL)   // Проверка дали опашката е празна
		top = p;       // Ако е празна, новият елемент става начало
	else
		bottom->next = p; // Ако не е празна, свързване със стария последен елемент

	bottom = p;        // Пренасочване на дъното към новия елемент
}

// Функция за извличане на елемент от началото на опашката
int popq(pq*& top, pq*& bottom) {
	if (top == NULL) {   // Проверка дали опашката е празна
		cout << "Queue is empty" << endl;
		return -1;       // Връщане на стойност, показваща, че няма елементи
	}

	int value = top->i;  // Запазване на стойността на първия елемент
	pq* p = top;          // Временен указател към началния елемент
	top = top->next;      // Пренасочване на началото към следващия елемент
	delete p;             // Изтриване на стария начален елемент

	if (top == NULL)      // Ако след изтриването опашката е празна
		bottom = NULL;    // Настройка на дъното към NULL

	return value;         // Връщане на стойността на изтрития елемент
}

int main() {
	int n, i, a;
	pq* top = NULL;      // Начало на опашката
	pq* bottom = NULL;   // Край на опашката

	cout << "Enter the number of elements to add to the queue: ";
	cin >> n;

	// Добавяне на елементи в опашката
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		pushq(top, bottom, a);
	}

	cout << "Queue elements after insertion:" << endl;

	// Извличане и отпечатване на елементи от опашката
	for (i = 1; i <= n; i++) {
		int value = popq(top, bottom);
		if (value != -1)   // Проверка дали има извлечен елемент
			cout << value << endl;
	}

	return 0;
}
