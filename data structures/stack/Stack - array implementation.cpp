// Stos w tablicy
// Data: 13.08.2012
// (C)2020 mgr Jerzy Wa�aszek
//------------------------------

#include <iostream>

using namespace std;

const int MAXINT = -2147483647;

// Definicja typu obiektowego stack
//---------------------------------
class stack {
private:
    int n;      // rozmiar tablicy
    int sptr;   // wska�nik stosu
    int* S;    // tablica dynamiczna

public:
    stack(int x); // konstruktor
    ~stack();     // destruktor
    bool empty(void);
    int  top(void);
    void push(int v);
    void pop(void);
};

//---------------------
// Metody obiektu stack
//---------------------

// Konstruktor - tworzy tablic� dla stosu
//---------------------------------------
stack::stack(int x) {
    n = x;
    S = new int[x];
    sptr = 0;
}

// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
stack::~stack() {
    delete[] S;
}

// Sprawdza, czy stos jest pusty
//------------------------------
bool stack::empty(void) {
    return !sptr;
}

// Zwraca szczyt stosu.
// Warto�� specjalna to -MAXINT
//-----------------------------
int stack::top(void) {
    if (sptr) return S[sptr - 1];
    return -MAXINT;
}

// Zapisuje na stos
//-----------------
void stack::push(int v) {
    if (sptr < n) S[sptr++] = v;
}

// Usuwa ze stosu
//---------------
void stack::pop(void) {
    if (sptr) sptr--;
}

//---------------
// Program g��wny
//---------------

int main()
{
    stack S(10); // tworzymy stos na 10 element�w
    int i;

    for (i = 1; i <= 10; i++) {
        S.push(i);
    }

    while (!S.empty()) {
        cout << S.top() << endl;
        S.pop();
    }
}