/*
José Daniel Mora Zúñiga

	CLASE LINKED_QUEUE
	La clase Linked_Queue implementa una cola (FIFO) utilizando una lista enlazada simple
	con nodos centinela. Hereda de la interfaz Queue<E>.

	Funcionalidades:
	- enqueue(E): Agrega un elemento al final.
	- dequeue(): Elimina y retorna el elemento del frente.
	- front_value(): Retorna el elemento del frente sin eliminarlo.
	- clear(): Elimina todos los elementos.
	- is_empty(): Verifica si la cola está vacía.
	- get_size(): Retorna la cantidad de elementos.
	- print(): Muestra el contenido de la cola.

	Estructura interna:
		front -> Nodo centinela (anterior al primer elemento).
		back  -> Puntero al último nodo.
		size  -> Número de elementos.
*/
#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "Queue.h"
//front->next->element

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Linked_Queue : public Queue<E> {
private:
	Node<E>* front;
	Node<E>* back;
	int size;

public:
	Linked_Queue() {
		front = back = new Node<E>();
		size = 0;
	}
	~Linked_Queue() {
		clear();
		delete front;
	}
	void enqueue(E element) {
		back = back->next = new Node<E>(element);
		size++;
	}
	E dequeue() {
		if (size == 0)
			throw runtime_error("Queue is empty.");
		E result = front->next->element;
		Node <E>* temp = front->next;
		front->next = temp->next;
		delete temp;
		if (size == 1)
			back = front;
		size--;
		return result;
	}
	E front_value() {
		if (size == 0)
			throw runtime_error("Queue is empty.");
		return front->element;
	}
	void clear() {
		for (int i = 0; i < size; i++) {
			Node <E>* temp = front->next;
			front->next = temp->next;
			delete temp;
		} //alt:
		//while (front->next != nullptr) {
			//Node <E>* temp = front->next;
			//front->next = temp->next;
			//delete temp;
		//}
		back = front;
		size = 0;
	}
	bool is_empty() {
		return size == 0;
	}
	int get_size() {
		return size;
	}
	void print() {
		Node <E>* temp = front->next;
		cout << "[";
		for (int i = size - 1; i >= 0; i--) { //alt: while (temp != nullptr)
			cout << temp->element;
			if (i != 0) //alt: if (temp->next != nullptr)
				cout << ", ";
			temp = temp->next;
		}
		//while (temp!= nullptr) {
			//cout << temp->element;
			//if (temp->next != nullptr)
				//cout <<", ";
			//temp = temp->next;
		//}
		cout << "]" << endl;                       
	}
};

