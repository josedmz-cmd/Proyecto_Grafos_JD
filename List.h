/*
José Daniel Mora Zúñiga

    CLASE LIST (INTERFAZ)
    La clase List es una interfaz abstracta que define el contrato que deben
    cumplir todas las implementaciones de listas lineales con cursor.

    Funcionalidades:
    - Inserción de elementos (insert, append).
    - Eliminación de elementos (remove).
    - Acceso y modificación del elemento actual (get_Element, set_element).
    - Movimiento del cursor (go_to_start, go_to_end, go_to_pos, next, previous).
    - Consultas de posición y estado (at_start, at_end, get_pos).
    - Consultas de tamaño y vacío (get_size, clear).
    - Visualización del contenido (print).

    Métodos principales:
        insert(E element)    -> Inserta un elemento en la posición actual del cursor.
        append(E element)    -> Agrega un elemento al final de la lista.
        set_element(E)       -> Modifica el elemento en la posición actual.
        get_Element()        -> Retorna el elemento en la posición actual.
        remove()             -> Elimina y retorna el elemento en la posición actual.
        clear()              -> Elimina todos los elementos de la lista.
        go_to_start()        -> Mueve el cursor al inicio de la lista.
        go_to_end()          -> Mueve el cursor al final de la lista.
        go_to_pos(int pos)   -> Mueve el cursor a la posición especificada.
        next()               -> Avanza el cursor una posición.
        previous()           -> Retrocede el cursor una posición.
        at_start()           -> Retorna true si el cursor está al inicio.
        at_end()             -> Retorna true si el cursor está al final.
        get_pos()            -> Retorna la posición actual del cursor.
        get_size()           -> Retorna la cantidad de elementos en la lista.
        print()              -> Imprime el contenido de la lista.
*/
#pragma once
template <typename E>
class List {
public:
	List() {}
	List(const List<E>& other) = delete;
	void operator=(const List<E>& other) = delete;
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual void set_element(E element) = 0;
	virtual E get_Element() = 0;
	virtual E remove() = 0;
	virtual void clear() = 0;
	virtual void go_to_start() = 0;
	virtual void go_to_end() = 0;
	virtual void go_to_pos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool at_start() = 0;
	virtual bool at_end() = 0;
	virtual int get_pos() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};