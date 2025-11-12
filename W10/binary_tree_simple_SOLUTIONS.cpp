#include <iostream>
using namespace std;

struct tnode {
    int i;
    tnode* left;
    tnode* right;
};

// Обхождане на двоично дърво клд (корен, ляво, дясно)
void printPREORDER(tnode* tree) {
    if (tree != NULL) {
        cout << tree->i << endl;
        printPREORDER(tree->left);
        printPREORDER(tree->right);
    }
}

// Обхождане на двоично дърво лкд (ляво, корен, дясно)
void printINORDER(tnode* tree) {
    if (tree != NULL) {
        printINORDER(tree->left);
        cout << tree->i << endl;
        printINORDER(tree->right);
    }
}

// Обхождане на двоично дърво лдк (ляво, дясно, корен)
void printPOSTORDER(tnode* tree) {
    if (tree != NULL) {
        printPOSTORDER(tree->left);
        printPOSTORDER(tree->right);
        cout << tree->i << endl;
    }
}

// Добавяне на възел
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

// Изключване от двоично дърво
void deleteKey(int x, tnode* &tree) {
    if (tree == NULL) {
        cout << "Nyama element\n";
    } else {
        if (x < tree->i) {
            deleteKey(x, tree->left);
        } else if (x > tree->i) {
            deleteKey(x, tree->right);
        } else {
            /* елементът за изключване е намерен */
            if (tree->left && tree->right) {
                /* върхът има два наследника */
                /* намира се върхът за размяна */
                tnode* replace = findMin(tree->right);
                tree->i = replace->i;
                deleteKey(tree->i, tree->right);
            } else {
                /* елементът има нула или едно поддървета */
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

// Търсене на елемент
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
    int i, n, a;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    for (i = 1; i <= n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> a;
        tree = addnode(a, tree);
    }
    
    cout << "\nIn-order traversal:\n";
    printPREORDER(tree);  // TASK 4: Replaced with printPREORDER
    
    cout << "\nEnter element to delete: ";
    cin >> a;
    deleteKey(a, tree);
    
    cout << "\nIn-order traversal after deletion:\n";
    printINORDER(tree);
    
    
    // ============================================================
    // SOLUTIONS TO EXERCISES
    // ============================================================
    
    // TASK 1: Add a call to Search()
    if (Search(tree, 15)) {
        cout << "Found 15" << endl;
    } else {
        cout << "15 not found" << endl;
    }
    
    
    // TASK 2: Add a call to Count()
    cout << "Count: " << Count(tree) << endl;
    
    
    // TASK 3: Add a call to MaxLen()
    cout << "Depth: " << MaxLen(tree) << endl;
    
    
    // TASK 4: Replace the traversal function
    // (Should replace line 135: printINORDER -> printPREORDER)
    // If done correctly, line 135 will have printPREORDER(tree);
    
    
    // TASK 5: Use printPOSTORDER
    cout << "\nPost-order traversal:" << endl;
    printPOSTORDER(tree);
    
    
    // TASK 6: Free the memory
    deleteTree(tree);
    
    return 0;
}
