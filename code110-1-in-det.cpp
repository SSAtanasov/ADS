#include <iostream>
using namespace std;

// ��������� �� ����� �� ������� �����
// ������� ������������� ���� (��������) � ��� ���������:
// ��� ���� � ����� ��������.
struct tnode {
	int i;           // �������� �� ������
	tnode* left;     // �������� ��� ���� ��������
	tnode* right;    // �������� ��� ����� ��������
};

// ��������� �� ������� ����� (��� - �����, ����, �����)
void printPREORDER(tnode* tree) {
	if (tree != NULL) {
		cout << tree->i << endl; // ����� �� ���������� �� ������� �����
		printPREORDER(tree->left);  // ���������� ��������� �� ������ ��������
		printPREORDER(tree->right); // ���������� ��������� �� ������� ��������
	}
}

// ��������� �� ������� ����� (��� - ����, �����, �����)
void printINORDER(tnode* tree) {
	if (tree != NULL) {
		printINORDER(tree->left);  // ���������� ��������� �� ������ ��������
		cout << tree->i << endl;  // ����� �� ���������� �� ������� �����
		printINORDER(tree->right); // ���������� ��������� �� ������� ��������
	}
}

// ��������� �� ������� ����� (��� - ����, �����, �����)
void printPOSTORDER(tnode* tree) {
	if (tree != NULL) {
		printPOSTORDER(tree->left);   // ���������� ��������� �� ������ ��������
		printPOSTORDER(tree->right);  // ���������� ��������� �� ������� ��������
		cout << tree->i << endl;      // ����� �� ���������� �� ������� �����
	}
}

// �������� �� ����� � ��������� �����
tnode* addnode(int x, tnode*& tree) {
	if (tree == NULL) { // ��� ������� � ������
		tree = new tnode; // ��������� �� ��� �����
		tree->i = x;      // �������� �� ���������� �� ������
		tree->left = NULL; // ����� �� ��� ���������
		tree->right = NULL; // ����� �� ����� ���������
	} else if (x < tree->i) { // ��� ���������� � ��-�����
		tree->left = addnode(x, tree->left); // �������� � ������ ��������
	} else { // ��� ���������� � ��-������ ��� �����
		tree->right = addnode(x, tree->right); // �������� � ������� ��������
	}
	return tree; // ������� �� �������� ��� ������
}

// �������� �� ���������� ������� � �������
tnode* findMin(tnode* tree) {
	while (tree->left != NULL) { // ��������� ������, ������ ��� ��� ���������
		tree = tree->left;
	}
	return tree; // ������� �� ���-����� �����
}

// ���������� �� ������� �� ��������� �����
void deleteKey(int x, tnode*& tree) {
	if (tree == NULL) { // ��� ������� � ������
		cout << "Element not found\n";
	} else if (x < tree->i) { // ��� ���������� � � ������ ��������
		deleteKey(x, tree->left);
	} else if (x > tree->i) { // ��� ���������� � � ������� ��������
		deleteKey(x, tree->right);
	} else {
		// ��������� �� ���������� � �������
		if (tree->left && tree->right) { // ��� ��� ��� ����������
			tnode* replace = findMin(tree->right); // �������� �� ���-����� � ������� ��������
			tree->i = replace->i; // ���������� �� �����������
			deleteKey(tree->i, tree->right); // ���������� �� ������
		} else {
			// ��� ��� ���� ��� ���� ����������
			tnode* temp = tree;
			tree = (tree->left != NULL) ? tree->left : tree->right; // ������������
			delete temp; // ��������� �� ������� �����
		}
	}
}

int main() {
	tnode* tree = NULL; // �������� ��� ������ �� �������
	int n, a;

	cout << "Enter number of elements: ";
	cin >> n;

	// �������� �� �������� � �������
	for (int i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		tree = addnode(a, tree); // �������� �� �������
	}

	cout << "\nIn-order traversal:\n";
	printINORDER(tree); // ��������� ���

	cout << "\nEnter element to delete: ";
	cin >> a;
	deleteKey(a, tree); // ��������� �� �������

	cout << "\nIn-order traversal after deletion:\n";
	printINORDER(tree); // ��������� ��� ���� �����������

	return 0;
}
