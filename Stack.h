/*
José Daniel Mora Zúñiga

    CLASE STACK (INTERFAZ)
    La clase Stack es una interfaz abstracta que define el contrato que deben
    cumplir todas las implementaciones de pilas (LIFO).

    Funcionalidades:
    - Operaciones básicas de pila: push, pop, top_value.
    - Consultas: is_empty, get_size.
    - Limpieza: clear.
    - Visualización: print.

    Métodos principales:
        push(E element)   -> Agrega un elemento al tope.
        pop()             -> Elimina y retorna el elemento del tope.
        top_value()       -> Retorna el elemento del tope sin eliminarlo.
        clear()           -> Elimina todos los elementos.
        is_empty()        -> Retorna true si la pila está vacía.
        get_size()        -> Retorna la cantidad de elementos.
        print()           -> Imprime el contenido de la pila.
*/
#pragma once //Solo pase una vez

template <typename E>
class Stack {
public:
	Stack() {};
	Stack(const Stack<E>& other) = delete; //se puede quitar el other
	void operator=(const Stack<E>&) = delete;
	virtual ~Stack() {} //destructor, para que todas las clases puedan sobreescrirlo
	virtual void push(E element) = 0; //No tiene implementación
	virtual E pop() = 0; //virtual: el método se puede volver a definir en una subclase
	virtual E top_value() = 0;
	virtual void clear() = 0;
	virtual bool is_empty() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};