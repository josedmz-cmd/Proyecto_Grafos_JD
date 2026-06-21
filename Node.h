/*
José Daniel Mora Zúñiga

	CLASE NODE
	La clase Node representa un nodo de una lista enlazada simple.
	Almacena un elemento de tipo genérico E y un puntero al siguiente nodo.

	Funcionalidades:
	- Constructor con elemento y siguiente (opcional).
	- Constructor con solo siguiente (para nodo centinela).

	Miembros:
		element   -> El dato almacenado.
		next      -> Puntero al siguiente nodo.
*/
#pragma once

template <typename E>
class Node {
public:
	E element;
	Node<E>* next;

	Node(E element, Node<E>* next = nullptr) {
		this->element = element;
		this->next = next;
	}
	Node(Node<E>* next = nullptr) {
		this->next = next;
	}
};