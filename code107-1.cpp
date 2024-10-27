#include <iostream>
using namespace std;

// ���������� �� ��������� �� ������� �� �������
struct plist {
	int i;          // �������� �� ��������
	plist* next;    // �������� ��� ��������� �������
};

// ����������� �� ��������� �� ������� � �������� �� ������
void insertBegin(plist*& l, int x) {
	plist* p = new plist;
	p->i = x;
	p->next = l;
	l = p;
}

// ��������� �� ������� ���� ����� ������� (l) � ������
void insertAfter(plist*& l, int x) {
	if (l == NULL) {
		insertBegin(l, x); // ��� �������� � ������, �������� �������� � ��������
	} else {
		plist* p = new plist;
		p->i = x;
		p->next = l->next;
		l->next = p;
	}
}

// ��������� �� ������� ����� ����� ������� (l) � ������
void insertBefore(plist*& l, int x) {
	if (l == NULL) {
		insertBegin(l, x); // ��� �������� � ������, �������� �������� � ��������
	} else {
		plist* p = new plist;
		p->i = l->i;
		p->next = l->next;
		l->i = x;
		l->next = p;
	}
}

// ����������� �� ��������� �� ������� � ������ �������� �� ������
void deletel(plist*& l, int x) {
	plist* p = l;
	plist* q;

	// �������� ���� ������� ������� � ���� �� ���������
	if (l != NULL && l->i == x) {
		l = l->next;
		delete p;
	} else {
		// ������� �� �������� �� ���������
		while (p->next != NULL && p->next->i != x) {
			p = p->next;
		}
		// ��� ��������� � �������, ��� �� �������
		if (p->next != NULL) {
			q = p->next;
			p->next = p->next->next;
			delete q;
		}
	}
}

// ����������� �� ������� �� ������� � ������ (����� �������� ��� �������� � ��������� ��������)
plist* search(plist* l, int x) {
	while (l != NULL) {
		if (l->i == x) {
			return l; // ����� �������� ��� ��������� �������
		}
		l = l->next;
	}
	return NULL; // ����� NULL, ��� ��������� �� � �������
}

// ����������� �� ��������� � ����������� �� ���������� �� ������
void printl(plist* l) {
	while (l != NULL) {
		cout << l->i << endl;
		l = l->next;
	}
}

// ������ �������
int main() {
	int n, i, a;
	plist* list = NULL;

	cout << "Enter the number of elements: "; // ���������� �� ��������� �� ���� ��������
	cin >> n;

	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": "; // ���������� �� ��������� �� �������
		cin >> a;
		insertBegin(list, a); // �������� �� ������� � �������� �� �������
	}

	cout << "Enter the value to search: "; // ���������� �� ������� �� ��������
	cin >> a;
	if (search(list, a) != NULL)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cout << "List elements:" << endl;
	printl(list); // ����������� �� ���������� �� �������

	return 0;
}
