#include <iostream>

using namespace std;

struct Elem {
    int key;
    Elem* next;
} *start;

static void init() {
    start = nullptr;
}

static Elem* swapNodes(Elem* p, Elem* q) {
    Elem* temp = q->next;
    q->next = p;
    p->next = temp;
    return q;
}

static int sortList(Elem** start, int listSize) {
    Elem** s;
    int i, j, swapped = 0;

    for (i = 0; i <= listSize; i++) {
        s = start;

        for (j = 0; j < listSize - i - 1; j++) {
            Elem* p = *s;
            Elem* q = p->next;

            if (p->key < q->key) {
                *s = swapNodes(p, q);
                swapped = 1;
            }

            s = &(*s)->next;
        }

        if (swapped == 0) {
            break;
        }
    }
    return 0;
}

static void addAtBeginning(int n) {
    Elem* newElem = new Elem;
    newElem->key = n;
    newElem->next = start;
    start = newElem;
}

static void addAtEnd(int n) {
    Elem* p = start;
    Elem* newElem = new Elem;
    newElem->key = n;
    newElem->next = nullptr;

    if (start) {
        while (p->next) {
            p = p->next;
        }
        p->next = newElem;
    }
    else {
        start = newElem;
    }
}

static void outputList(Elem* node) {
    while (node != nullptr) {
        cout << node->key << "  |  ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    init();
    int n, elementsCount, i = 0;

    cout << " > Enter key value for the start element: ";
    cin >> n;
    addAtBeginning(n);
    i++;

    cout << " > Enter how many elements to add after the start: ";
    cin >> elementsCount;

    for (int j = 0; j < elementsCount; j++) {
        cout << " > Enter key value for element " << i << ": ";
        cin >> n;
        addAtEnd(n);
        i++;
    }

    cout << " > List before sort: ";
    outputList(start);

    sortList(&start, i);

    cout << " > List after sort: ";
    outputList(start);

    return 0;
}
