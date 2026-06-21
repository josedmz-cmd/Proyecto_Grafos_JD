/*
José Daniel Mora Zúñiga

	CLASE DLINKEDLIST
	La clase DLinkedList implementa una lista doblemente enlazada con cursor,
	heredando de la interfaz List<E>.
	Utiliza nodos DNode con centinelas head y tail.

	Funcionalidades:
	- Inserción en posición actual (insert) y al final (append).
	- Eliminación en posición actual (remove).
	- Acceso y modificación del elemento actual (get_Element, set_element).
	- Movimiento del cursor (go_to_start, go_to_end, go_to_pos, next, previous).
	- Consultas (at_start, at_end, get_pos, get_size).
	- Limpieza (clear) y visualización (print).

	Estructura interna:
		head y tail son nodos centinela.
		current apunta al nodo anterior al elemento actual (para facilitar inserción/eliminación).

	Métodos principales:
		insert(E)        -> Inserta antes de la posición actual.
		append(E)        -> Agrega al final.
		remove()         -> Elimina el elemento actual.
		get_Element()    -> Retorna el elemento actual.
		set_element(E)   -> Modifica el elemento actual.
		go_to_start()    -> Mueve cursor al inicio.
		go_to_end()      -> Mueve cursor al final.
		go_to_pos(int)   -> Mueve cursor a posición dada.
		next()/previous()-> Avanza/retrocede el cursor.
		clear()          -> Elimina todos los elementos.
		get_size()       -> Retorna cantidad de elementos.
		print()          -> Imprime la lista (marca el elemento actual con *).
*/
#pragma once

#include <stdexcept>
#include "List.h"
#include <iostream>
#include "DNode.h"
//Sigue apuntando al anterior
using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class DLinkedList : public List<E> {
private:
	DNode<E>* head;
	DNode<E>* tail;
	DNode<E>* current;
	int size;

public:
	DLinkedList() {
		head = current = new DNode<E>(nullptr, nullptr);
		head->next = tail = new DNode<E>(nullptr, head);
		size = 0;
	}

	~DLinkedList() {
		clear();
		delete head;
		delete tail;
	}

	void insert(E element) {
		current->next = current->next->previous
			= new DNode<E>(element, current->next, current);
		size++;
	}

	void append(E element) {
		tail->previous = tail->previous->next
			= new DNode<E>(element, tail, tail->previous);
		size++;
	}

	void set_element(E element) {
		if (size == 0)
			throw runtime_error("List is empty");
		if (current->next == tail)
			throw runtime_error("No current element");
		current->next->element = element;
	}

	E get_Element() {
		if (size == 0)
			throw runtime_error("List is empty");
		if (current->next == tail)
			throw runtime_error("No current element");
		return current->next->element;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (current->next == tail)
			throw runtime_error("No current element.");
		E result = current->next->element;
		current->next = current->next->next;
		delete current->next->previous;
		current->next->previous = current;
		size--;
		return result;
	}

	void clear() {
		current = head->next;
		while (head->next != tail) {
			head->next = current->next;
			delete current;
			current = head->next;
		}
		current = head;
		size = 0;
	}

	void go_to_start() {
		current = head;
	}

	void go_to_end() {
		current = tail->previous;
	}

	void go_to_pos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds");
		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
	}

	void next() {
		if (current->next != tail)
			current = current->next;
	}

	void previous() {
		if (current != head)
			current = current->previous;
	}

	bool at_start() {
		return current == head;
	}

	bool at_end() {
		return current->next == tail;
	}

	int get_pos() {
		DNode <E>* temp = head;
		int pos = 0;
		while (temp != current) {
			temp = temp->next;
			pos++;
		}
		return pos;
	}

	int get_size() {
		return size;
	}

	void print() {
		DNode <E>* temp = head->next;
		cout << "[";
		for (int i = size - 1; i >= 0; i--) {
			cout << temp->element;
			if (temp == current->next)
				cout << "*";
			if (i != 0)
				cout << ", ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};

