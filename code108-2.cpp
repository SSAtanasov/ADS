#include <iostream>
using namespace std;

// ��������� �� �������� ������
struct pq {
	int i;       // �������� �� ������� � ��������
	pq* next;    // �������� ��� ��������� �������
};

// ������� �� �������� �� ������� � ���� �� ��������
void pushq(pq*& top, pq*& bottom, int x) {
	pq* p = new(pq);   // ��������� �� ��� �������
	p->i = x;          // ��������� �� ����������
	p->next = NULL;    // ��������� �� ��������� ������� ��� NULL

	if (top == NULL)   // �������� ���� �������� � ������
		top = p;       // ��� � ������, ������ ������� ����� ������
	else
		bottom->next = p; // ��� �� � ������, ��������� ��� ������ �������� �������

	bottom = p;        // ������������ �� ������ ��� ����� �������
}

// ������� �� ��������� �� ������� �� �������� �� ��������
int popq(pq*& top, pq*& bottom) {
	if (top == NULL) {   // �������� ���� �������� � ������
		cout << "Queue is empty" << endl;
		return -1;       // ������� �� ��������, ���������, �� ���� ��������
	}

	int value = top->i;  // ��������� �� ���������� �� ������ �������
	pq* p = top;          // �������� �������� ��� �������� �������
	top = top->next;      // ������������ �� �������� ��� ��������� �������
	delete p;             // ��������� �� ������ ������� �������

	if (top == NULL)      // ��� ���� ����������� �������� � ������
		bottom = NULL;    // ��������� �� ������ ��� NULL

	return value;         // ������� �� ���������� �� �������� �������
}

int main() {
	int n, i, a;
	pq* top = NULL;      // ������ �� ��������
	pq* bottom = NULL;   // ���� �� ��������

	cout << "Enter the number of elements to add to the queue: ";
	cin >> n;

	// �������� �� �������� � ��������
	for (i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		pushq(top, bottom, a);
	}

	cout << "Queue elements after insertion:" << endl;

	// ��������� � ����������� �� �������� �� ��������
	for (i = 1; i <= n; i++) {
		int value = popq(top, bottom);
		if (value != -1)   // �������� ���� ��� �������� �������
			cout << value << endl;
	}

	return 0;
}
