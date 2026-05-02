//Notacion Polaca con stl

#include<iostream>
#include<deque>
#include<queue>
#include<stack>
#include<sstream>
#include<string>
using namespace std;

class polaco {
public:
	polaco() {}
	~polaco(){}
	void elementos();
	void convierte();
	int prioridad(string y);
	double resultado();
	void imprimir();
private:
	deque<string>mideque;
	queue<string>cola;
	stack<string>pila;
};

void polaco::elementos(){
	string variable;
	string trozo;
	cout << "ingrese una exprecion matematica(con espacios): ";
	getline(cin, variable);
	stringstream ss(variable);
	while (ss >> trozo)
		cola.push(trozo);

}
void polaco::convierte() {
    while (!cola.empty()) {
        string aux = cola.front();
        cola.pop();

        if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
            while (!pila.empty() && prioridad(pila.top()) >= prioridad(aux)) {
                mideque.push_back(pila.top());
                pila.pop();
            }
            pila.push(aux);
        }
        else { 
            mideque.push_back(aux);
        }
    }
    
    while (!pila.empty()) {
        mideque.push_back(pila.top());
        pila.pop();
    }
}
int polaco::prioridad(string x) {
	if (x == "*" || x == "/") return 2;
	if (x == "+" || x == "-") return 1;
	return 0; 
}
double polaco::resultado() {
    stack<double> pilaCalculo;

    while (!mideque.empty()) {
        string aux = mideque.front();
        mideque.pop_front();

        if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
            
            double n2 = pilaCalculo.top(); pilaCalculo.pop();
            double n1 = pilaCalculo.top(); pilaCalculo.pop();

            if (aux == "+") pilaCalculo.push(n1 + n2);
            if (aux == "-") pilaCalculo.push(n1 - n2);
            if (aux == "*") pilaCalculo.push(n1 * n2);
            if (aux == "/") pilaCalculo.push(n1 / n2);
        }
        else {
            
            pilaCalculo.push(stod(aux));
        }
    }
    return pilaCalculo.top();
} 
void polaco::imprimir() {
    cout << "Resultado final: " << resultado() << endl;
}

int main() {
    polaco p;
    p.elementos(); 
    p.convierte(); 
    p.imprimir();  
    return 0;
}
