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
        int* grado = new int[numNodos];
        for (int i = 0; i < numNodos; ++i) {
            grado[i] = 0;
        }
        float distMaxCuad = distanciaMaxima * distanciaMaxima;
        for (int i = 0; i < numNodos; ++i) {
            nodos.go_to_pos(i);
            Nodo ni = nodos.get_Element();
            for (int j = i + 1; j < numNodos; ++j) {
                nodos.go_to_pos(j);
                Nodo nj = nodos.get_Element();
                if (grado[i] < maxConexionesPorNodo && grado[j] < maxConexionesPorNodo) {
                    float d = distanciaCuadrada(ni, nj);
                    if (d <= distMaxCuad) {
                        agregarArco(Arco(i, j, d));
                        grado[i]++;
                        grado[j]++;
                    }
                }
            }
        }
        delete[] grado;
    }

public:
    Grafo() {
        numNodos = 0;
        distanciaMaxima = 0.0f;
        maxConexionesPorNodo = 0;
        anchoVentana = 0.0f;
        altoVentana = 0.0f;
    }

    Grafo(int n, float distMax, int maxConex, float ancho, float alto) {
        numNodos = n;
        distanciaMaxima = distMax;
        maxConexionesPorNodo = maxConex;
        anchoVentana = ancho;
        altoVentana = alto;
        srand((unsigned)time(nullptr));
        for (int i = 0; i < n; ++i) {
            float x = rand() / float(RAND_MAX) * ancho;
            float y = rand() / float(RAND_MAX) * alto;
            agregarNodo(Nodo(i, x, y));
        }
        conectarNodosCercanos();
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

    static float distanciaCuadrada(const Nodo& a, const Nodo& b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    Grafo* DFS(int inicio) {
        Grafo* resultado = new Grafo();
        resultado->numNodos = numNodos;
        nodos.go_to_start();
        for (int i = 0; i < numNodos; ++i) {
            resultado->agregarNodo(nodos.get_Element());
            nodos.next();
        }
        bool* visitado = new bool[numNodos];
        for (int i = 0; i < numNodos; ++i) 
            visitado[i] = false;
        Linked_Stack<int> pila;
        pila.push(inicio);
        visitado[inicio] = true;
        while (!pila.is_empty()) {
            int actual = pila.pop();
            arcos.go_to_start();
            for (int i = 0; i < arcos.get_size(); ++i) {
                Arco a = arcos.get_Element();
                int vecino = -1;
                if (a.origen == actual) 
                    vecino = a.destino;
                else if (a.destino == actual) 
                    vecino = a.origen;
                if (vecino != -1 && !visitado[vecino]) {
                    visitado[vecino] = true;
                    resultado->agregarArco(a);
                    pila.push(vecino);
                }
                arcos.next();
            }
        }
        delete[] visitado;
        return resultado;
    }

    Grafo* BFS(int inicio) {
        Grafo* resultado = new Grafo();
        resultado->numNodos = numNodos;
        nodos.go_to_start();
        for (int i = 0; i < numNodos; ++i) {
            resultado->agregarNodo(nodos.get_Element());
            nodos.next();
        }
        bool* visitado = new bool[numNodos];
        for (int i = 0; i < numNodos; ++i)
            visitado[i] = false;
        Linked_Queue<int> cola;
        cola.enqueue(inicio);
        visitado[inicio] = true;
        while (!cola.is_empty()) {
            int actual = cola.dequeue();
            arcos.go_to_start();
            for (int i = 0; i < arcos.get_size(); ++i) {
                Arco a = arcos.get_Element();
                int vecino = -1;
                if (a.origen == actual) vecino = a.destino;
                else if (a.destino == actual) vecino = a.origen;
                if (vecino != -1 && !visitado[vecino]) {
                    visitado[vecino] = true;
                    resultado->agregarArco(a);
                    cola.enqueue(vecino);
                }
                arcos.next();
            }
        }
        delete[] visitado;
        return resultado;
    }

    Grafo* Prim(int inicio) {

    }

    Grafo* Kruskal() {

    }

    Grafo* Dijkstra(int inicio, int destino) {

    }

    void dibujar() {

    }
};

