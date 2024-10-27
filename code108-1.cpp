#include <iostream>
using namespace std;

// ��������� �� ������� ������
struct pstack {
	int i;          // �������� �� ������� � �������
	pstack* next;   // �������� ��� ��������� �������
};

// ������� �� �������� �� ������� � �������� �� �������
void insert(pstack*& l, int x) {
	pstack* p = new(pstack);  // ��������� �� ��� �������
	p->i = x;                 // ��������� �� ����������
	p->next = l;              // ��������� � ��������� ������� �������
	l = p;                    // ������������ �� �������� �� �������
}

// ������� �� ���������� �� ������� �� �������� �� �������
void pop(pstack*& l) {
	// �������� ���� �������� � ������
	if (l == NULL) {
		cout << "Stack is empty" << endl;
	} else {
		pstack* p = l;   // �������� �������� ��� �������� �������
		l = l->next;     // ����������� �� �������� ��� ��������� �������
		delete(p);       // ��������� �� ������ ������� �������
	}
}

// ������� �� ����������� �� ������ �������� � �������
void printl(pstack* l) {
	while (l != NULL) {
		cout << l->i << endl;  // ����� �� ���������� �� ������� �������
		l = l->next;           // ����������� ��� ��������� �������
	}
}

int main() {
	int n, i, a;
	pstack* list = NULL;  // �������������� �� ������� ���� ������

	cout << "Enter number of elements to add: ";
	cin >> n;

	// ������ �� �������� � �������� � �������� �� �������
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		insert(list, a);
	}

	// ����� �� ������� ���� ��������� �� ����������
	cout << "List after insertion:" << endl;
	printl(list);

	// ���������� �� ������ ������� � ����� �� �������
	cout << "List after popping one element:" << endl;
	pop(list);
	printl(list);

	return 0;
}
