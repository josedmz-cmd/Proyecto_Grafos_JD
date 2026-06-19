#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "Stack.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Linked_Stack : public Stack<E> {
private:
	Node<E>* top;
	int size;

public:
	Linked_Stack() {
		size = 0;
		top = nullptr;
	}
	~Linked_Stack() { //Destructor es lo mismo que el clear en este caso
		clear();
	}
	void push(E element) { //el next apunta al top anterior y luego top apunta al nodo nuevo
		top = new Node<E>(element, top);
		size++;
	}
	E pop() { //Al retornar el elemento encontrado en el top, hay que respaldarlo. Luego se elimina el nodo
		if (size == 0)
			throw runtime_error("Stack is empty.");
		E result = top->element; //(*top).element
		Node <E>* temp = top->next; //También puede ser temp = top,
		delete top; //después top = top->next
		top = temp; //y luego delete temp
		size--;
		return result; //temp va a dejar de ser utilizada porque es variable local
	}
	// const E& top_value()
	E top_value() { //Para obtimizar, en ves de retornar el elemento, se retorna la referencia al elemento usando E& en vez de E. Pero puede hacer cambios.
		if (size == 0)     //Entonces se le agrega const antes de E&
			throw runtime_error("Stack is empty.");
		return top->element; 
	}
	void clear() {
		Node <E>* temp = nullptr;
		for (int i = 0; i < size; i++) {
			temp = top; //También puede ser temp = top->next,
			top = top->next; //después delete top
			delete temp; //y luego top = temp
		}
		size = 0;
		//while (size > 0) {
			//temp = top;
			//top = top->next;
			//delete temp;
			//size--;
		//}
		//while (top != nullptr) {
			//temp = top;
			//top = top->next;
			//delete temp;
		//}
		//size = 0;
		//Este último es el que hace menos operaciones
	}
	bool is_empty() {
		return size == 0;
	}
	int get_size() {
		return size;
	}
	void print() {
		Node <E>* temp = top;
		cout << "[";
		for (int i = size - 1; i >= 0; i--) { //alt: while (temp != nullptr)
			cout << temp->element;
			if (i != 0) //alt: if (temp->next != nullptr)
				cout << ", ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};

