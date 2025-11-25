# Операции: Двоично дърво vs BST

## ТАБЛИЦА НА ОПЕРАЦИИТЕ

| Операция | Вид | Причина |
|----------|-----|---------|
| **Структура tnode** | ДВОИЧНО | Просто два указателя (left, right), без ограничения |
| **printPREORDER** | ДВОИЧНО | Работи на всяко дърво, няма сравнения |
| **printINORDER** | ДВОИЧНО | Работи на всяко дърво, няма сравнения |
| **printPOSTORDER** | ДВОИЧНО | Работи на всяко дърво, няма сравнения |
| **MaxLen** | ДВОИЧНО | Просто мерки дълбочина, няма сравнения по ключ |
| **Count** | ДВОИЧНО | Просто брой възлови, няма сравнения |
| **addnode** | BST | Сравнява x < tree->i, разчита на BST структура |
| **findMin** | BST | Пътува всегда наляво, разчита че най-малкия е там |
| **deleteKey** | BST | Сравнява за намиране, разчита на BST правила |
| **Search** | BST | Сравнява за претърсване, разчита на BST структура |

---

## ОПЕРАЦИИ ЗА ДВОИЧНО ДЪРВО (работят на ВСЯКО двоично дърво)

### 1. **Структура на възел**
```cpp
struct tnode {
    int i;
    tnode* left;
    tnode* right;
};
```
✅ **Двоично дърво** - просто два указателя

---

### 2. **Обхождане: PreOrder, InOrder, PostOrder**
```cpp
void printINORDER(tnode* tree) {
    if (tree != NULL) {
        printINORDER(tree->left);      // идеят вляво
        cout << tree->i << endl;        // отпечатай възел
        printINORDER(tree->right);     // идеят вдясно
    }
}
```
✅ **Двоично дърво** - работят на всяко дърво без зависимост от стойностите!
- Няма `if (x < tree->i)` сравнения
- Просто линейно нареждане

---

### 3. **Намиране на дълбочина**
```cpp
int MaxLen(tnode* tree) {
    if (tree == NULL) return -1;
    int l = MaxLen(tree->left);
    int r = MaxLen(tree->right);
    if (l > r) return l + 1;
    else return r + 1;
}
```
✅ **Двоично дърво** - просто рекурсия, няма сравнения по ключ!

---

### 4. **Броене на върховете**
```cpp
int Count(tnode* tree) {
    if (tree == NULL) return 0;
    return Count(tree->left) + Count(tree->right) + 1;
}
```
✅ **Двоично дърво** - просто счетоводство, няма зависимост от стойностите!

---

## ОПЕРАЦИИ ЗА BST (разчитат на BST структура)

### 5. **Добавяне на възел**
```cpp
tnode* addnode(int x, tnode* &tree) {
    if (tree == NULL) {
        tree = new tnode;
        tree->i = x;
        tree->left = NULL;
        tree->right = NULL;
    } else if (x < tree->i) {              // КЛЮЧОВО СРАВНЕНИЕ!
        tree->left = addnode(x, tree->left);
    } else {
        tree->right = addnode(x, tree->right);
    }
    return tree;
}
```
❌ **Само за BST** - зависи от сравнението `x < tree->i`
- Разчита че всичко по-малко е вляво

---

### 6. **Намиране на минимален елемент**
```cpp
tnode* findMin(tnode* tree) {
    while (tree->left != NULL) {           // ПРЕДПОЛОЖЕНИЕ НА BST!
        tree = tree->left;
    }
    return tree;
}
```
❌ **Само за BST** - предполага че най-малкия е винаги най-вляво!
- На обичайно дърво това не е вярно

---

### 7. **Търсене на елемент**
```cpp
bool Search(tnode* tree, int x) {
    if (tree == NULL) return false;
    if (tree->i == x) return true;
    if (x < tree->i) return Search(tree->left, x);    // СРАВНЕНИЕ!
    else return Search(tree->right, x);
}
```
❌ **Само за BST** - използва сравненията за ефикасно търсене
- На обичайно дърво би требвало да проверишъ всички възлови!

---

### 8. **Изтриване на елемент**
```cpp
void deleteKey(int x, tnode* &tree) {
    if (tree == NULL) {
        cout << "Nyama element\n";
    } else {
        if (x < tree->i) {                 // СРАВНЕНИЯ ЗА НАВИГАЦИЯ!
            deleteKey(x, tree->left);
        } else if (x > tree->i) {
            deleteKey(x, tree->right);
        } else {
            // намерен е елементът
            if (tree->left && tree->right) {
                tnode* replace = findMin(tree->right);  // ОЩЕ ЗАВИСИМОСТ ОТ BST!
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
```
❌ **Само за BST** - множество зависимости:
- Сравнения за намиране на елемента
- Използва `findMin` която е за BST
- Разчита на структурата

---

## РЕЗЮМЕ

| Категория | Операции |
|-----------|----------|
| **ДВОИЧНО ДЪРВО** | Структура, PreOrder, InOrder, PostOrder, MaxLen, Count |
| **BST** | addnode, findMin, Search, deleteKey |

**Ключова разлика:**
- **Двоично дърво операции**: Работят с ВСЯКО дърво, няма зависимост от стойностите
- **BST операции**: Разчитат че стойностите са организирани по BST правилата
