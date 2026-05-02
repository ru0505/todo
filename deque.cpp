//deque

#include <iostream>
using namespace std;

class Deque {
private:
    int** ini=nullptr;
    int** fin=nullptr;
    int** mapa=nullptr;
    int* inicio=nullptr;
    int* final=nullptr;
    int num = 3;
    int cant = 9;
    int cantidad = 0;
public:
    Deque() {
        mapa = new int* [cant];
        ini = mapa + cant/2;
        fin = ini;
    }
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    int& operator[](int i);
    void print();
};
//agregar
void Deque::push_front(int x) {
    if (!inicio) { //vacio
        ini =fin= mapa + cant / 2;
        *ini = new int[num];
        inicio =final= *ini + num/2;
        *inicio = x;
    }
    else if(inicio==*ini){//si choca con el inicio, los dos tipos
        if (ini==mapa) {
            cout << "limite";
            return;
        }
        --ini;
        *ini = new int [num];
        inicio = *ini + num-1;
        *inicio = x;
    }
    else {
        --inicio;
        *inicio = x;
    }cantidad++;

}
void Deque::push_back(int x){
    if (!inicio) {
        fin =ini = mapa + cant / 2;
        *fin = new int[num];
        final =inicio= *fin + num / 2;
        *final = x;
    }
    else if (final == *fin + num - 1) {
        if (fin == mapa + cant - 1) {
            cout << "limite";
            return;
        }
        ++fin;
        *fin = new int[num];
        final = *fin;
        *final = x;
    }
    else {
        final++;
        *final = x;
    }cantidad++;

}
//eliminar
void Deque::pop_front() {
    if (!inicio) { cout << "esta vacio ;v "; }
    else if (inicio == final) {
        delete[] * ini;
        inicio = nullptr;
        final = nullptr;
		*ini = nullptr;
        
    }
    else if (inicio == *ini + num - 1) {
        delete[] * ini;
        ++ini;
        inicio = *ini;
    }
    else {
        ++inicio;
    }cantidad--;
}
void Deque::pop_back() {
    if (!final) { cout << "esta vacio ;v "; }
    else if (inicio == final) {
        delete[] * fin;
        inicio = nullptr;
        final = nullptr;
		*fin = nullptr;
        
    }
    else if (final == *fin) {
        delete[] * fin;
        --fin;
        final = *fin +num-1;
    }
    else {
        --final;
    }cantidad--;
}
//operator
int& Deque::operator[](int i) {
    if (!inicio) {
        cout << "esta vacio ;v ";
        return *inicio;
    }int desnivel = inicio - *ini;
    int nivel = desnivel + i;
    return *(*(ini + (nivel / num)) + nivel % num);
}
//imprimir
void Deque::print() {
    if (!inicio) {
        cout << "esta vacio >;";
    }
    for (int i = 0;i < cantidad;i++) {
        cout << (*this)[i] << " ";
    }cout << endl;
}

int main()
{
    Deque d;
    d.push_front(1);
	d.push_front(2);
    d.push_front(3);
    d.push_front(5);
    d.push_back(8);
    d.push_back(5);
    d.print();
    d.pop_back();
	d.pop_front();
    d.operator[](3) = 10;
    d.print();
    

    
}
