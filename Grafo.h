#pragma once

#include "DLinkedList.h"
#include "Nodo.h"
#include "Arco.h"
#include "Linked_Stack.h"
#include "Linked_Queue.h"
#include "Heap_Priority_Queue.h"
#include "Min_Heap.h"
#include "FindUnion.h"
#include "Pair.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Grafo {
private:
    DLinkedList<Nodo> nodos;
    DLinkedList<Arco> arcos;
    int numNodos;
    float distanciaMaxima;
    int maxConexionesPorNodo;
    float anchoVentana, altoVentana;

    void conectarNodosCercanos() {

    }

public:
    Grafo() {

    }

    Grafo(int n, float distMax, int maxConex, float ancho, float alto) {

    }

    ~Grafo() {}

    DLinkedList<Nodo>& getNodos() {
        return nodos;
    }
    DLinkedList<Arco>& getArcos() {
        return arcos;
    }
    int getNumNodos() const {
        return numNodos;
    }

    void agregarNodo(const Nodo& n) {
        nodos.append(n);
    }

    void agregarArco(const Arco& a) {
        arcos.append(a);
    }

    static float distancia(const Nodo& a, const Nodo& b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    Grafo* DFS(int inicio) const {

    }

    Grafo* BFS(int inicio) const {

    }

    Grafo* Prim(int inicio) const {

    }

    Grafo* Kruskal() const {

    }

    Grafo* Dijkstra(int inicio, int destino) const {

    }

    void dibujar() {

    }
};

