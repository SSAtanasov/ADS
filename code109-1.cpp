#include <iostream>
using namespace std;

// �������� �������� �� ����������� �� ���������� ������
struct elem {
	int key;
	elem *pred;
	elem *next;
};

// 1. ��������� �� ������� � �������� �� ���������� ������
void add1(elem* &start, int n) {
	elem* p = new elem;	// ��������� �� ����� �������
	p->key = n;
	p->next = start;
	p->pred = NULL;	// ��������� �� �����������

	if (start != NULL) {
		start->pred = p;
	}
	start = p;
}

// 2. ��������� �� �������� ������� ��� �������� n � ������� ����� ���� ������� � ������� �������� k
void add2(elem* &start, int n, int k) {
	elem *q;
	elem *p = start;

	// ������� �� �������� � ���� k
	while (p != NULL && p->key != k) {
		p = p->next;
	}

	if (p != NULL) {	// �������� ���� ��������� � �������
		q = new elem;	// ��������� �� ��� �������
		q->key = p->key;
		q->next = p->next;
		q->pred = p;

		if (p->next != NULL) {
			p->next->pred = q;
		}

		p->next = q;
		p->key = n;	// ���������� �� ����� �� p
	}
}

// 3. ��������� �� �������� ������� ��� �������� n � ������� ���� ���� ������� � ������� �������� k
void add3(elem* &start, int n, int k) {
	elem *q;
	elem *p = start;

	// ������� �� �������� � ���� k
	while (p != NULL && p->key != k) {
		p = p->next;
	}

	if (p != NULL) {	// �������� ���� ��������� � �������
		q = new elem;	// ��������� �� ��� �������
		q->key = n;
		q->next = p->next;

		if (p->next != NULL) {
			p->next->pred = q;
		}

		p->next = q;
		q->pred = p;
	}
}

// 4. ��������� �� �������� ������� ��� �������� n � ���������� ������
void add4(elem* &start, int n) {
	elem *p = start, *q;
	q = new elem;	// ��������� �� ��� �������
	q->key = n;
	q->next = NULL;

	// �������� ���� �������� � ��������
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

// 5. ���������� �� ������ ������� �� ���������� ������
// ���������� �� �������� ������� � �������� � main()
void del1(elem* &start, int &n) {
	elem *p = start;
	n = start->key;
	start = start->next;	// ������������ �� ��������

	if (start != NULL) {
		start->pred = NULL;
	}
	delete p;	// ���������� �� ��������
}

// 6. ���������� �� �������� ������� ��� �������� n �� ���������� ������
void del2(elem* &start, int n) {
	elem *p = start;

	// ������� �� �������� � ���� n
	while (p != NULL && p->key != n) {
		p = p->next;
	}

	if (p != NULL) {	// �������� ���� ��������� � �������
		if (p->pred != NULL) {
			p->pred->next = p->next;
		}
		if (p->next != NULL) {
			p->next->pred = p->pred;
		}
		delete p;	// ��������� �� ��������
	}
}

// 7. ���������� �� �������� ������� �� ���������� ������
void del3(elem* &start, int &n) {
	elem *p = start;

	// ������� �� ��������� �������
	while (p->next != NULL) {
		p = p->next;
	}
	n = p->key;

	if (p->pred != NULL) {
		p->pred->next = NULL;
	}
	delete p;	// ��������� �� ��������
}

int main() {
	int i, n, a;
	elem* start = NULL;

	cout << "Enter the number of elements: ";
	cin >> n;

	// ��������� �� �������� � �������� � �������� �� �������
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		add1(start, a);
	}

	cout << "Elements of the list:" << endl;
	elem *p = start;

	// ��������� �� ������� � ��������� �� ���������� ��
	while (p != NULL) {
		cout << p->key << endl;
		p = p->next;
	}

	del1(start, a);
	cout << "Deleted first element: " << a << endl;

	cout << "Remaining elements of the list:" << endl;
	p = start;

	// ��������� �� ������� � ��������� �� ���������� ��������
	while (p != NULL) {
		cout << p->key << endl;
		p = p->next;
	}

	return 0;
}
