// ============================================================
// BINARY SEARCH TREE - INTERACTIVE MENU VERSION (CP1251 FIX)
// ============================================================

#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;

struct tnode {
    int i;
    tnode* left;
    tnode* right;
};

void printPREORDER(tnode* tree) {
    if (tree != NULL) {
        cout << tree->i << " ";
        printPREORDER(tree->left);
        printPREORDER(tree->right);
    }
}

void printINORDER(tnode* tree) {
    if (tree != NULL) {
        printINORDER(tree->left);
        cout << tree->i << " ";
        printINORDER(tree->right);
    }
}

void printPOSTORDER(tnode* tree) {
    if (tree != NULL) {
        printPOSTORDER(tree->left);
        printPOSTORDER(tree->right);
        cout << tree->i << " ";
    }
}

tnode* addnode(int x, tnode* &tree) {
    if (tree == NULL) {
        tree = new tnode;
        tree->i = x;
        tree->left = NULL;
        tree->right = NULL;
    } else if (x < tree->i) {
        tree->left = addnode(x, tree->left);
    } else {
        tree->right = addnode(x, tree->right);
    }
    return tree;
}

tnode* findMin(tnode* tree) {
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

void deleteKey(int x, tnode* &tree) {
    if (tree == NULL) {
        cout << "Елементът не съществува в дървото!\n";
    } else {
        if (x < tree->i) {
            deleteKey(x, tree->left);
        } else if (x > tree->i) {
            deleteKey(x, tree->right);
        } else {
            if (tree->left && tree->right) {
                tnode* replace = findMin(tree->right);
                tree->i = replace->i;
                deleteKey(tree->i, tree->right);
            } else {
                tnode* temp = tree;
                if (tree->left) tree = tree->left;
                else tree = tree->right;
                delete temp;
            }
        }
    }
}

bool Search(tnode* tree, int x) {
    if (tree == NULL) return false;
    if (tree->i == x) return true;
    if (x < tree->i) return Search(tree->left, x);
    else return Search(tree->right, x);
}

int MaxLen(tnode* tree) {
    if (tree == NULL) return -1;
    int l = MaxLen(tree->left);
    int r = MaxLen(tree->right);
    return (l > r ? l : r) + 1;
}

int Count(tnode* tree) {
    if (tree == NULL) return 0;
    return Count(tree->left) + Count(tree->right) + 1;
}

void deleteTree(tnode* tree) {
    if (tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
}

int main() {
    // --- Най-стабилната конфигурация за кирилица ---
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Bulgarian");

    tnode* tree = NULL;
    int n, a, choice;

    cout << "=== Двоично дърво за претърсване ===\n\n";
    cout << "Въведете брой елементи: ";
    cin >> n;

    cout << "Въведете елементите:\n";
    for (int i = 1; i <= n; i++) {
        cin >> a;
        tree = addnode(a, tree);
    }

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. InOrder обхождане (ЛКД)\n";
        cout << "2. PreOrder обхождане (КЛД)\n";
        cout << "3. PostOrder обхождане (ЛДК)\n";
        cout << "4. Търсене на елемент\n";
        cout << "5. Добавяне на елемент\n";
        cout << "6. Изтриване на елемент\n";
        cout << "7. Брой възли в дървото\n";
        cout << "8. Дълбочина на дървото\n";
        cout << "0. Изход\n";
        cout << "Изберете опция: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "InOrder: ";
                printINORDER(tree);
                cout << endl;
                break;

            case 2:
                cout << "PreOrder: ";
                printPREORDER(tree);
                cout << endl;
                break;

            case 3:
                cout << "PostOrder: ";
                printPOSTORDER(tree);
                cout << endl;
                break;

            case 4:
                cout << "Въведете елемент за търсене: ";
                cin >> a;
                if (Search(tree, a))
                    cout << "Елементът " << a << " е намерен.\n";
                else
                    cout << "Елементът " << a << " не е намерен.\n";
                break;

            case 5:
                cout << "Въведете елемент за добавяне: ";
                cin >> a;
                addnode(a, tree);
                cout << "Добавен.\n";
                break;

            case 6:
                cout << "Въведете елемент за изтриване: ";
                cin >> a;
                deleteKey(a, tree);
                cout << "След изтриване (InOrder): ";
                printINORDER(tree);
                cout << endl;
                break;

            case 7:
                cout << "Брой възли: " << Count(tree) << endl;
                break;

            case 8:
                cout << "Дълбочина: " << MaxLen(tree) << endl;
                break;

            case 0:
                cout << "Изход...\n";
                break;

            default:
                cout << "Невалидна опция!\n";
        }
    } while(choice != 0);

    deleteTree(tree);
    return 0;
}
