// ============================================================
// BINARY SEARCH TREE - INTERACTIVE MENU VERSION
// ============================================================
// ВАЖНО: Този файл използва UTF-8 encoding за кирилица
// 
// За правилна работа на Windows:
// 1. Уверете се че файлът е запазен като UTF-8
// 2. В CMD преди стартиране напишете: chcp 65001
// 3. Или компилирайте с: g++ -fexec-charset=CP1251 binary_search_tree.cpp
//
// На Linux/Mac работи директно с UTF-8
// ============================================================

#include <iostream>
using namespace std;

struct tnode {
    int i;
    tnode* left;
    tnode* right;
};

// Обхождане на двоично дърво КЛД (Корен, Ляво, Дясно)
void printPREORDER(tnode* tree) {
    if (tree != NULL) {
        cout << tree->i << " ";
        printPREORDER(tree->left);
        printPREORDER(tree->right);
    }
}

// Обхождане на двоично дърво ЛКД (Ляво, Корен, Дясно)
void printINORDER(tnode* tree) {
    if (tree != NULL) {
        printINORDER(tree->left);
        cout << tree->i << " ";
        printINORDER(tree->right);
    }
}

// Обхождане на двоично дърво ЛДК (Ляво, Дясно, Корен)
void printPOSTORDER(tnode* tree) {
    if (tree != NULL) {
        printPOSTORDER(tree->left);
        printPOSTORDER(tree->right);
        cout << tree->i << " ";
    }
}

// Добавяне на възел в двоично дърво за претърсване
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

// Намиране на минималния елемент в дърво
tnode* findMin(tnode* tree) {
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

// Изключване на възел от двоично дърво
void deleteKey(int x, tnode* &tree) {
    if (tree == NULL) {
        cout << "Елементът не съществува в дървото!\n";
    } else {
        if (x < tree->i) {
            deleteKey(x, tree->left);
        } else if (x > tree->i) {
            deleteKey(x, tree->right);
        } else {
            // Елементът за изключване е намерен
            if (tree->left && tree->right) {
                // Върхът има два наследника
                // Намира се върхът за размяна
                tnode* replace = findMin(tree->right);
                tree->i = replace->i;
                deleteKey(tree->i, tree->right);
            } else {
                // Елементът има нула или едно поддървета
                tnode* temp = tree;
                if (tree->left) {
                    tree = tree->left;
                } else {
                    tree = tree->right;
                }
                delete(temp);
            }
        }
    }
}

// Търсене на елемент в дървото
bool Search(tnode* tree, int x) {
    if (tree == NULL) return false;
    if (tree->i == x) return true;
    if (x < tree->i) return Search(tree->left, x);
    else return Search(tree->right, x);
}

// Намиране на дълбочина на дърво
int MaxLen(tnode* tree) {
    if (tree == NULL) return -1;
    int l, r;
    l = MaxLen(tree->left);
    r = MaxLen(tree->right);
    if (l > r) return l + 1;
    else return r + 1;
}

// Преброяване общия брой върхове
int Count(tnode* tree) {
    if (tree == NULL) return 0;
    return Count(tree->left) + Count(tree->right) + 1;
}

// Освобождаване на паметта
void deleteTree(tnode* tree) {
    if (tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
}

int main() {
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
                if (Search(tree, a)) {
                    cout << "Елементът " << a << " е намерен в дървото.\n";
                } else {
                    cout << "Елементът " << a << " не е намерен в дървото.\n";
                }
                break;
                
            case 5:
                cout << "Въведете елемент за добавяне: ";
                cin >> a;
                tree = addnode(a, tree);
                cout << "Елементът е добавен успешно.\n";
                break;
                
            case 6:
                cout << "Въведете елемент за изтриване: ";
                cin >> a;
                deleteKey(a, tree);
                cout << "Дървото след изтриване (InOrder): ";
                printINORDER(tree);
                cout << endl;
                break;
                
            case 7:
                cout << "Брой възли в дървото: " << Count(tree) << endl;
                break;
                
            case 8:
                cout << "Дълбочина на дървото: " << MaxLen(tree) << endl;
                break;
                
            case 0:
                cout << "Изход от програмата...\n";
                break;
                
            default:
                cout << "Невалидна опция! Опитайте отново.\n";
        }
    } while(choice != 0);
    
    // Освобождаване на паметта
    deleteTree(tree);
    
    return 0;
}
