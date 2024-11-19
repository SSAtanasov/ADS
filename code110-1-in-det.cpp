#include <iostream>
using namespace std;

// Структура за възел на двоично дърво
// Включва информационна част (стойност) и два указателя:
// към ляво и дясно поддърво.
struct tnode {
	int i;           // Стойност на възела
	tnode* left;     // Указател към ляво поддърво
	tnode* right;    // Указател към дясно поддърво
};

// Обхождане на двоично дърво (КЛД - корен, ляво, дясно)
void printPREORDER(tnode* tree) {
	if (tree != NULL) {
		cout << tree->i << endl; // Печат на стойността на текущия възел
		printPREORDER(tree->left);  // Рекурсивно обхождане на лявото поддърво
		printPREORDER(tree->right); // Рекурсивно обхождане на дясното поддърво
	}
}

// Обхождане на двоично дърво (ЛКД - ляво, корен, дясно)
void printINORDER(tnode* tree) {
	if (tree != NULL) {
		printINORDER(tree->left);  // Рекурсивно обхождане на лявото поддърво
		cout << tree->i << endl;  // Печат на стойността на текущия възел
		printINORDER(tree->right); // Рекурсивно обхождане на дясното поддърво
	}
}

// Обхождане на двоично дърво (ЛДК - ляво, дясно, корен)
void printPOSTORDER(tnode* tree) {
	if (tree != NULL) {
		printPOSTORDER(tree->left);   // Рекурсивно обхождане на лявото поддърво
		printPOSTORDER(tree->right);  // Рекурсивно обхождане на дясното поддърво
		cout << tree->i << endl;      // Печат на стойността на текущия възел
	}
}

// Добавяне на възел в двоичното дърво
tnode* addnode(int x, tnode*& tree) {
	if (tree == NULL) { // Ако дървото е празно
		tree = new tnode; // Създаване на нов възел
		tree->i = x;      // Задаване на стойността на възела
		tree->left = NULL; // Липса на ляв наследник
		tree->right = NULL; // Липса на десен наследник
	} else if (x < tree->i) { // Ако стойността е по-малка
		tree->left = addnode(x, tree->left); // Добавяне в лявото поддърво
	} else { // Ако стойността е по-голяма или равна
		tree->right = addnode(x, tree->right); // Добавяне в дясното поддърво
	}
	return tree; // Връщане на указател към корена
}

// Намиране на минималния елемент в дървото
tnode* findMin(tnode* tree) {
	while (tree->left != NULL) { // Обхождане наляво, докато има ляв наследник
		tree = tree->left;
	}
	return tree; // Връщане на най-левия възел
}

// Изключване на елемент от двоичното дърво
void deleteKey(int x, tnode*& tree) {
	if (tree == NULL) { // Ако дървото е празно
		cout << "Element not found\n";
	} else if (x < tree->i) { // Ако стойността е в лявото поддърво
		deleteKey(x, tree->left);
	} else if (x > tree->i) { // Ако стойността е в дясното поддърво
		deleteKey(x, tree->right);
	} else {
		// Елементът за изключване е намерен
		if (tree->left && tree->right) { // Ако има два наследника
			tnode* replace = findMin(tree->right); // Намиране на най-левия в дясното поддърво
			tree->i = replace->i; // Заместване на стойностите
			deleteKey(tree->i, tree->right); // Изключване на възела
		} else {
			// Ако има едно или нула наследника
			tnode* temp = tree;
			tree = (tree->left != NULL) ? tree->left : tree->right; // Пренасочване
			delete temp; // Изтриване на текущия възел
		}
	}
}

int main() {
	tnode* tree = NULL; // Указател към корена на дървото
	int n, a;

	cout << "Enter number of elements: ";
	cin >> n;

	// Добавяне на елементи в дървото
	for (int i = 1; i <= n; i++) {
		cout << "Enter element " << i << ": ";
		cin >> a;
		tree = addnode(a, tree); // Добавяне на елемент
	}

	cout << "\nIn-order traversal:\n";
	printINORDER(tree); // Обхождане ЛКД

	cout << "\nEnter element to delete: ";
	cin >> a;
	deleteKey(a, tree); // Изтриване на елемент

	cout << "\nIn-order traversal after deletion:\n";
	printINORDER(tree); // Обхождане ЛКД след изтриването

	return 0;
}
