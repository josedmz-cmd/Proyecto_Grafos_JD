/*
José Daniel Mora Zúñiga

	CLASE DNODE
	La clase DNode representa un nodo de una lista doblemente enlazada.
	Almacena un elemento de tipo genérico E y punteros al siguiente y anterior nodo.

	Funcionalidades:
	- Constructor con elemento, siguiente y anterior.
	- Constructor con solo siguiente y anterior (para centinelas).

	Miembros:
		element   -> El dato almacenado.
		next      -> Puntero al siguiente nodo.
		previous  -> Puntero al nodo anterior.
*/
#pragma once

template <typename E>
class DNode {
public:
	E element;
	DNode<E>* next;
	DNode<E>* previous;

	DNode(E element, DNode<E>* next, DNode<E>* previous) {
		this->element = element;
		this->next = next;
		this->previous = previous;
	}

	DNode(DNode<E>* next, DNode<E>* previous) {
		this->next = next;
		this->previous = previous;
	}
};

