/*
José Daniel Mora Zúñiga

    CLASE PRIORITY_QUEUE (INTERFAZ)
    La clase Priority_Queue define el contrato para colas de prioridad.
    Los elementos se insertan con una prioridad (int) y se extraen en orden
    de menor prioridad (número más bajo = mayor prioridad).

    Funcionalidades:
    - insert(E, int): Agrega un elemento con su prioridad.
    - min(): Retorna el elemento de menor prioridad sin eliminarlo.
    - removeMin(): Elimina y retorna el elemento de menor prioridad.
    - clear(): Elimina todos los elementos.
    - getSize(): Retorna la cantidad de elementos.
    - is_empty(): Verifica si la cola está vacía.
    - print(): Muestra el contenido de la cola.
*/
#pragma once
template <typename E>
class Priority_Queue {
public:
    Priority_Queue() {}
    Priority_Queue(const Priority_Queue<E>& other) = delete;
    void operator=(const Priority_Queue<E>&) = delete;
    virtual ~Priority_Queue() {}
    virtual void insert(E element, int priority) = 0;
    virtual E min() = 0;
    virtual E removeMin() = 0;
    virtual void clear() = 0;
    virtual int getSize() = 0;
    virtual bool is_empty() = 0;
    virtual void print() = 0;
};
