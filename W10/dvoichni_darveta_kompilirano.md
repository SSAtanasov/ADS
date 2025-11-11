# Двоични дървета - Пълна информация и код

## 1. Определения

### Дърво (Tree)
Динамична информационна структура, състояща се от елементи (върхове) и връзки между тях (дъги), в която:
- Всички върхове без 1 имат по 1 предшественик
- 1 връх (корен) няма предшественици
- Единствен път до корена
- **Ниво на върха** - брой на върховете в пътя до корена
- **Корен** - ниво 0
- **Листа** - върхове без наследници
- **Поддърво** - върхът и всичките му наследници, техните наследници и т.н.
- Рекурсивна същност на дърветата като структури от данни

### Двоично дърво (Binary Tree)
- Брой на наследниците на върховете: 0, 1 или 2
- Ляв и десен наследник

### Рекурсивно определение на двоично дърво
Крайно множество от елементи (възли), което е или **празно**, или се състои от **корен** (възел), свързан с две непресичащи се двоични дървета (поддървета) - **ляво** и **дясно** поддърво.

## 2. Аритметични изрази и двоични дървета
- Листата са имена на променливи и константи
- Другите възли са аритметични операции
- Пример: `(a+b/c)*(d-e*f)`

## 3. Обхождане на двоично дърво
Линейно нареждане на възлите на дървото:

1. **preorder (клд – корен, ляво, дясно)** - `*+a/bc-d*ef`
2. **inorder (лкд – ляво, корен, дясно)** - `a+b/c*d-e*f`
3. **postorder (лдк – ляво, дясно, корен)** - `abc/+def*-*`

## Пример на двоично дърво

![Пример на двоично дърво](binary_tree_example.png)

*Пример: Двоично дърво с корен 2 и наследници. InOrder обхождане дава: 2, 7, 2, 6, 5, 11, 5, 9, 4*

### Примерни резултати от обхождане:
За дърво с върхове: 2 (корен), 7, 5, 2, 6, 9, 5, 11, 4

- **КДЛ**: 2;5;9;4;7;6;11;5;2
- **ДКЛ**: 9;4;5;2;11;6;5;7;2
- **ДЛК**: 4;9;5;11;5;6;2;7;2
- **КЛД**: 2;7;2;6;5;11;5;9;4
- **ЛКД**: 2;7;5;6;11;2;5;4;9
- **ЛДК**: 2;5;11;6;7;4;9;5;2

## 4. Двоично дърво за претърсване (Binary Search Tree)

### Определение
Двоичното дърво за претърсване е структура от данни, която служи за съхраняване и намиране на данни по ключ, за който съществува наредба.

**Данните са разпределени в дървото по следния начин:**
- За всеки връх, всички данни в **лявото му поддърво** имат **по-малък ключ**
- Всички данни в **дясното поддърво** имат **по-голям ключ**

**Примери:**
10,  5, 15,  3, 8, 12, 20
 5,  3,  7,  2, 4,  6,  9
 7, 15, 10, 20, 8, 12, 17, 25, 15

### Ефикасност на двоичните дървета за търсене
- **Средна сложност** на операциите добавяне и търсене: **O(log N)**, където N е броят на елементите
- При добавяне на подредени елементи дървото може да се изроди до свързан списък → сложност **O(N)**
- Съществуват алгоритми (балансирани дървета), които поддържат структурата балансирана и запазват добрите сложности

### Изключване на връх по даден ключ

Тази операция е малко по-сложна. След намиране на върха с ключ k, са възможни 3 ситуации:

1. **Ако върхът е листо** - освобождава се заетата памет и се променя указателят на върха, сочещ към него (присвоява му се стойност NULL)

2. **Ако върхът има само ляво или само дясно поддърво** - се замества с корена на това поддърво

3. **Най-сложният случай** - когато върхът за изтриване p има едновременно ляво и дясно поддърво:
   - Намира се върхът с **най-малък ключ в дясното поддърво** (най-левият в дясното поддърво)
   - Този връх се разменя с p
   - След размяната p ще има най-много едно поддърво и се изключва по някое от горните две правила
   - (Алтернатива: намиране на елемента с най-голям ключ в лявото поддърво)

## 5. Програмен код

### Основна структура

```cpp
#include <iostream>
using namespace std;

struct tnode {
    int i;
    tnode* left;
    tnode* right;
};
```

### Функции за обхождане

#### 1. PreOrder (КЛД - Корен, Ляво, Дясно)
```cpp
void printPREORDER(tnode* tree) {
    if (tree != NULL) {
        cout << tree->i << endl;
        printPREORDER(tree->left);
        printPREORDER(tree->right);
    }
}
```

#### 2. InOrder (ЛКД - Ляво, Корен, Дясно)
```cpp
void printINORDER(tnode* tree) {
    if (tree != NULL) {
        printINORDER(tree->left);
        cout << tree->i << endl;
        printINORDER(tree->right);
    }
}
```

#### 3. PostOrder (ЛДК - Ляво, Дясно, Корен)
```cpp
void printPOSTORDER(tnode* tree) {
    if (tree != NULL) {
        printPOSTORDER(tree->left);
        printPOSTORDER(tree->right);
        cout << tree->i << endl;
    }
}
```

### Функции за работа с дървото

#### 4. Добавяне на възел
```cpp
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
```

#### 5. Намиране на минимален елемент
```cpp
tnode* findMin(tnode* tree) {
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}
```

#### 6. Изключване от двоично дърво
```cpp
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
                deleteKey(tree->i, tree->right); /* върхът се изключва */
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
```

### Допълнителни функции

#### 7. Търсене на елемент
```cpp
bool Search(tnode* tree, int x) {
    if (tree == NULL) return false;
    if (tree->i == x) return true;
    if (x < tree->i) return Search(tree->left, x);
    else return Search(tree->right, x);
}
```

#### 8. Намиране на дълбочина на дърво
```cpp
int MaxLen(tnode* tree) {
    if (tree == NULL) return -1;
    int l, r;
    l = MaxLen(tree->left);
    r = MaxLen(tree->right);
    if (l > r) return l + 1;
    else return r + 1;
}
```

#### 9. Преброяване на общия брой върхове
```cpp
int Count(tnode* tree) {
    if (tree == NULL) return 0;
    return Count(tree->left) + Count(tree->right) + 1;
}
```

### Пълна програма

```cpp
#include <iostream>
using namespace std;

struct tnode {
    int i;
    tnode* left;
    tnode* right;
};

void printPREORDER(tnode* tree) {
    if (tree != NULL) {
        cout << tree->i << endl;
        printPREORDER(tree->left);
        printPREORDER(tree->right);
    }
}

void printINORDER(tnode* tree) {
    if (tree != NULL) {
        printINORDER(tree->left);
        cout << tree->i << endl;
        printINORDER(tree->right);
    }
}

void printPOSTORDER(tnode* tree) {
    if (tree != NULL) {
        printPOSTORDER(tree->left);
        printPOSTORDER(tree->right);
        cout << tree->i << endl;
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
        cout << "Nyama element\n";
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

bool Search(tnode* tree, int x) {
    if (tree == NULL) return false;
    if (tree->i == x) return true;
    if (x < tree->i) return Search(tree->left, x);
    else return Search(tree->right, x);
}

int MaxLen(tnode* tree) {
    if (tree == NULL) return -1;
    int l, r;
    l = MaxLen(tree->left);
    r = MaxLen(tree->right);
    if (l > r) return l + 1;
    else return r + 1;
}

int Count(tnode* tree) {
    if (tree == NULL) return 0;
    return Count(tree->left) + Count(tree->right) + 1;
}

int main() {
    tnode* tree = NULL;
    int i, n, a;
    
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a;
        tree = addnode(a, tree);
    }
    
    cout << endl;
    printINORDER(tree);
    cout << endl;
    
    cin >> a;
    deleteKey(a, tree);
    
    cout << endl;
    printINORDER(tree);
    
    // Допълнително можете да използвате:
    // cout << endl << Count(tree) << endl;
    // cout << endl << MaxLen(tree) << endl;
    
    return 0;
}
```

## 6. Примери за използване

### Вход:
```
7
15 10 20 8 12 17 25
15
```

### Изход:
```
8 10 12 15 17 20 25
(след изтриване на 15)
8 10 12 17 20 25
```

## Забележки:
- InOrder обхождането на двоично дърво за претърсване дава **сортиран изход**
- Всички операции са **рекурсивни** по природа
- Дълбочината се измерва от -1 (празно дърво) до 0 (само корен) и нагоре
- При изтриване на възел с две деца, алгоритъмът използва най-малкия елемент от дясното поддърво като заместител
