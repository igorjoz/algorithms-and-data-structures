// Usuwanie duplikat�w z listy jednokierunkowej
// Data: 20.02.2012
// (C)2020 mgr Jerzy Wa�aszek
//---------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ element�w listy
//--------------------
struct slistEl
{
    slistEl* next;
    char data;
};

// Definicja typu obiektowego slist
//---------------------------------

class slist
{
public:
    slistEl* head;

    slist();  // konstruktor
    ~slist(); // destruktor
    unsigned size();
    void printl();
    void push_front(char v);
    void pop_front();
    void unique();
};

// Konstruktor listy
//------------------
slist::slist()
{
    head = NULL;
}

// Destruktor listy
//-----------------
slist::~slist()
{
    while (head) pop_front();
}

// Funkcja oblicza liczb� element�w listy
//---------------------------------------
unsigned slist::size()
{
    unsigned c = 0;
    slistEl* p = head;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

// Procedura wy�wietla zawarto�� element�w listy
//----------------------------------------------
void slist::printl()
{
    unsigned i;
    slistEl* p = head;

    cout << size() << ": ";
    for (i = 1; p; p = p->next) cout << p->data;
    cout << endl;
}

// Procedura do��czania na pocz�tek listy
//---------------------------------------
void slist::push_front(char v)
{
    slistEl* p;

    p = new slistEl;
    p->next = head;
    p->data = v;
    head = p;
}

// Procedura usuwa pierwszy element
//---------------------------------
void slist::pop_front()
{
    slistEl* p = head; // zapami�tujemy pocz�tek

    if (p)
    {
        head = p->next;   // nowy pocz�tek
        delete p;         // usu� element z pami�ci
    }
}

void slist::unique() {
    slistEl* p, * pc, * r;
    pc = head;

    while (pc) {
        p = pc;
        while (p->next) {
            if (p->next->data == pc->data) {
                r = p->next;
                p->next = r->next;
                delete r;
            }
            else {
                p = p->next;
            }
        }   
        pc = pc->next;
    }
}

int main()
{
    slist L;
    int i;

    srand(time(NULL));

    for (i = 0; i < 40; i++) L.push_front(65 + rand() % 26);
    L.printl();
    L.unique();
    L.printl();

    return 0;
}