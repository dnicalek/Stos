#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

struct element
{
    int number;
    element* next;
};

void push(element* &stack, int value)
{
    element* el = new element;
    el->number=value;
    el->next=stack;
    stack=el;

}

void push_from1_to10(element* &stack, int value)
{
    value = (rand() % 10 ) + 1;

    element* el=new element;
    el->number=value;
    el->next=stack;
    stack=el;
    cout<<"Dodano element o wartosci: "<<value<<endl;
}

void pop(element* &stack)
{
    if(stack==nullptr)
    {
        cout<<"Stos jest pusty"<<endl;
    }
    else
    {
        element* temp=stack;
        stack=stack->next;
        delete temp;
    }
}

bool is_Empty(element(* stack))
{
    if(stack==nullptr)
    {
        cout<<"Stos jest pusty. "<<endl;
        return true;
    }
    else
    {
        cout<<"Stos nie jest pusty. "<<endl;
        return false;
    }
}

void top(element* stack)
{
    cout<<"Element na wierzchu to: "<<stack->number<<endl;
}

void delete_stack(element* &stack)
{
    if(stack==nullptr)
    {
        cout<<"Stos pusty."<<endl;
    }
    else
    {
        while(stack!=nullptr)
        {
            pop(stack);
        }
    }

}

void reverse() //wynik.txt zapisuje się w buildzie qt creatora, trzeba wejsc do folderu
{
    cout<<"Odwracanie tekstu piosenki"<<endl;
    element* piosenka = nullptr;
    char value;
    ifstream file;
    file.open("znaki1.txt");
    while(file.get(value))
    {
        push(piosenka,value);
    }
    file.close();

    ofstream wyn;
    wyn.open("wynik.txt");

    while(piosenka != nullptr)
    {
        wyn.put(piosenka->number);
        pop(piosenka);
    }
    wyn.close();
}

int main()
{
    srand(time(NULL));
    element* stack=nullptr;
    int wybor, value;

    cout<<"MENU PROGRAMU"<<endl;
    cout<<"1) Sprawdzenie czy stos jest pusty "<<endl;
    cout<<"2) Dodanie elementu na stos "<<endl;
    cout<<"3) Usuniecie elementu ze stosu "<<endl;
    cout<<"4) Pobranie elementu ze stosu "<<endl;
    cout<<"5) Usuniecie wszystkich elementow ze stosu "<<endl;
    cout<<"6) Odwrocenie kolejnosci "<<endl;
    cout<<"7) Wyjscie z programu "<<endl;
    cout<<""<<endl;
    while(true)
    {

        cout<<"Wybierz numer zadania: ";
        cin>>wybor;


        switch(wybor)
        {
        case 1:
            is_Empty(stack);
            break;
        case 2:
            push_from1_to10(stack,value);
            break;
        case 3:
            pop(stack);
            break;
        case 4:
            top(stack);
            break;
        case 5:
            delete_stack(stack);
            break;
        case 6:
            reverse(); //wynik.txt zapisuje się w buildzie qt creatora, trzeba wejsc do folderu
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"Nie ma takiej opcji."<<endl;

        }



    }

    return 0;
}
