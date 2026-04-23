/* creacion de una queque (cola) circular */

#include <iostream>
using namespace std;

struct Pilar {
	int* arr;
	int* tail;
	int* heap;
	int numero;

	Pilar(int r);
	~Pilar();
	bool lleno();
	bool vacio();
	bool push(int y);//llenar
	bool pop();//sacar
	void print();
};
Pilar::Pilar(int r) {//constructor
	numero = r;
	arr = new int [r];
	heap=nullptr;
	tail=nullptr;
}
Pilar::~Pilar() {
	delete[]arr;
}
bool Pilar::lleno() {
	if (vacio()) {
		return false;
	}
	if ((tail == arr + numero - 1 && heap == arr) || (tail + 1 == heap)) { // aca da la vuelta el tail a la cola
		return true;
	}return false;
}
bool Pilar::vacio() {
	return heap == nullptr;
}
bool Pilar::push(int y) {
	if (lleno()) return false;

	if (vacio()) {
		heap = tail = arr;
	}
	else if (tail == arr + numero - 1) {
		tail = arr;
	}
	else {
		tail++;
	}

	*tail = y;
	return true;
}
bool Pilar::pop() {
	if (vacio()) return false;

	if (heap == tail) {
		heap = tail = nullptr;
	}
	else if (heap == arr + numero - 1) {
		heap = arr;
	}
	else {
		heap++;
	}
	return true;
}
void Pilar::print() {
	if (vacio()) {
		cout << "cola vacia ;V" << endl;
		return;
	}
	int* temp = heap;
	while (true) {
		cout << *temp << " -> ";
		if (temp == tail) break;
		if (temp == arr + numero - 1)
			temp = arr;  // vuelta circular
		else
			temp++;
	}

	cout << endl;
}

int main() {
	Pilar p(5);
	p.push(1);
	p.push(2);
	p.push(5);
	p.push(4);
	p.push(8);
	p.print();
	p.pop();
	p.print();
	p.push(50);
	p.print();
}
