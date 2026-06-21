/*
José Daniel Mora Zúñiga

    CLASE QUEUE (INTERFAZ)
    La clase Queue es una interfaz abstracta que define el contrato que deben
    cumplir todas las implementaciones de colas (FIFO).

    Funcionalidades:
    - Operaciones básicas: enqueue, dequeue, front_value.
    - Consultas: is_empty, get_size.
    - Limpieza: clear.
    - Visualización: print.

    Métodos principales:
        enqueue(E element)   -> Agrega un elemento al final.
        dequeue()            -> Elimina y retorna el elemento del frente.
        front_value()        -> Retorna el elemento del frente sin eliminarlo.
        clear()              -> Elimina todos los elementos.
        is_empty()           -> Retorna true si la cola está vacía.
        get_size()           -> Retorna la cantidad de elementos.
        print()              -> Imprime el contenido de la cola.
*/
#pragma once

template <typename E>
class Queue {
public:
	Queue() {}
	Queue(const Queue<E>&) = delete;
	void operator=(const Queue<E>&) = delete;
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual E front_value() = 0;
	virtual void clear() = 0;
	virtual bool is_empty() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};

