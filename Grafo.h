/*
José Daniel Mora Zúñiga

    CLASE GRAFO
    La clase Grafo representa un grafo no dirigido etiquetado con nodos
    en posiciones (x,y) y arcos con peso (distancia al cuadrado).
    Incluye generación aleatoria y algoritmos: DFS, BFS, Prim, Kruskal, Dijkstra.

    Funcionalidades:
    - Generación de nodos aleatorios y conexiones según distancia y grado máximo.
    - Algoritmos de árbol de expansión y ruta más corta.
    - Dibujo con SFML (nodos, arcos, resaltados, indicadores de selección).

    Miembros principales:
        nodos, arcos (listas).
        numNodos, distanciaMaxima, maxConexionesPorNodo.
        anchoVentana, altoVentana.

    Métodos:
        getNodos(), getArcos(), getNumNodos().
        agregarNodo(), agregarArco().
        distanciaCuadrada().
        DFS(), BFS(), Prim(), Kruskal(), Dijkstra().
        dibujar().
*/
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
                if (a.origen == actual) 
                    vecino = a.destino;
                else if (a.destino == actual) 
                    vecino = a.origen;
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
        Grafo* resultado = new Grafo();
        resultado->numNodos = numNodos;
        nodos.go_to_start();
        for (int i = 0; i < numNodos; ++i) {
            resultado->agregarNodo(nodos.get_Element());
            nodos.next();
        }
        float* dist = new float[numNodos];
        int* padre = new int[numNodos];
        bool* enArbol = new bool[numNodos];
        for (int i = 0; i < numNodos; ++i) {
            dist[i] = 1e9;
            padre[i] = -1;
            enArbol[i] = false;
        }
        dist[inicio] = 0.0f;
        Heap_Priority_Queue<Pair<int, float>> pq;
        pq.insert(Pair<int, float>(inicio, 0.0f), 0);
        while (!pq.is_empty()) {
            Pair<int, float> p = pq.removeMin();
            int u = p.key;
            if (enArbol[u]) 
                continue;
            enArbol[u] = true;
            if (padre[u] != -1) {
                resultado->agregarArco(Arco(padre[u], u, dist[u]));
            }
            arcos.go_to_start();
            for (int i = 0; i < arcos.get_size(); ++i) {
                Arco a = arcos.get_Element();
                int v = -1;
                if (a.origen == u) 
                    v = a.destino;
                else if (a.destino == u) 
                    v = a.origen;
                if (v != -1 && !enArbol[v] && a.peso < dist[v]) {
                    dist[v] = a.peso;
                    padre[v] = u;
                    pq.insert(Pair<int, float>(v, a.peso), (int)a.peso);
                }
                arcos.next();
            }
        }
        delete[] dist;
        delete[] padre;
        delete[] enArbol;
        return resultado;
    }

    Grafo* Kruskal() {
        Grafo* resultado = new Grafo();
        resultado->numNodos = numNodos;
        nodos.go_to_start();
        for (int i = 0; i < numNodos; ++i) {
            resultado->agregarNodo(nodos.get_Element());
            nodos.next();
        }
        FindUnion fu(numNodos);
        Heap_Priority_Queue<Arco> pq;
        arcos.go_to_start();
        for (int i = 0; i < arcos.get_size(); ++i) {
            Arco a = arcos.get_Element();
            pq.insert(a, (int)a.peso);
            arcos.next();
        }
        int arcosAgregados = 0;
        while (!pq.is_empty() && arcosAgregados < numNodos - 1) {
            Arco a = pq.removeMin();
            if (fu.find(a.origen) != fu.find(a.destino)) {
                fu.unir(a.origen, a.destino);
                resultado->agregarArco(a);
                arcosAgregados++;
            }
        }
        return resultado;
    }

    Grafo* Dijkstra(int inicio, int destino) {
        if (inicio < 0 || inicio >= numNodos || destino < 0 || destino >= numNodos)
            return nullptr;
        float* dist = new float[numNodos];
        int* prev = new int[numNodos];
        bool* definitivo = new bool[numNodos];
        for (int i = 0; i < numNodos; ++i) {
            dist[i] = 1e9;
            prev[i] = -1;
            definitivo[i] = false;
        }
        dist[inicio] = 0.0f;
        Heap_Priority_Queue<Pair<int, float>> pq;
        pq.insert(Pair<int, float>(inicio, 0.0f), 0);
        while (!pq.is_empty()) {
            Pair<int, float> p = pq.removeMin();
            int u = p.key;
            if (definitivo[u]) 
                continue;
            definitivo[u] = true;
            if (u == destino) 
                break;
            arcos.go_to_start();
            for (int i = 0; i < arcos.get_size(); ++i) {
                Arco a = arcos.get_Element();
                int v = -1;
                if (a.origen == u) 
                    v = a.destino;
                else if (a.destino == u)
                    v = a.origen;
                if (v != -1 && !definitivo[v] && dist[u] + a.peso < dist[v]) {
                    dist[v] = dist[u] + a.peso;
                    prev[v] = u;
                    pq.insert(Pair<int, float>(v, dist[v]), (int)dist[v]);
                }
                arcos.next();
            }
        }
        if (dist[destino] == 1e9) {
            delete[] dist;
            delete[] prev;
            delete[] definitivo;
            return nullptr;
        }
        Grafo* resultado = new Grafo();
        resultado->numNodos = numNodos;
        nodos.go_to_start();
        for (int i = 0; i < numNodos; ++i) {
            resultado->agregarNodo(nodos.get_Element());
            nodos.next();
        }
        int actual = destino;
        while (actual != inicio) {
            int ant = prev[actual];
            arcos.go_to_start();
            bool encontrado = false;
            for (int i = 0; i < arcos.get_size(); ++i) {
                Arco a = arcos.get_Element();
                if ((a.origen == ant && a.destino == actual) || (a.origen == actual && a.destino == ant)) {
                    resultado->agregarArco(a);
                    encontrado = true;
                    break;
                }
                arcos.next();
            }
            if (!encontrado) 
                break;
            actual = ant;
        }
        delete[] dist;
        delete[] prev;
        delete[] definitivo;
        return resultado;
    }

    void dibujar(sf::RenderWindow& window, Grafo* resaltado = nullptr, int nodoInicio = -1, int nodoDestino = -1) {
        const sf::Color COLOR_FONDO = sf::Color(0, 0, 0);
        const sf::Color COLOR_ARCO_NORMAL = sf::Color(255, 255, 255);
        const sf::Color COLOR_ARCO_RESALTADO = sf::Color::Red;
        const sf::Color COLOR_NODO_RELLENO = sf::Color(120, 81, 169);  // I like purple  https://html-color.codes/purple
        const sf::Color COLOR_NODO_BORDE = sf::Color::White;
        const float RADIO_NODO = 12.5f;
        const float GROSOR_BORDE = 2.0f;
        const int TAMANO_TEXTO = 13;
        const sf::Color COLOR_TEXTO = sf::Color::Black;
        const float RADIO_INDICADOR = 19.0f;
        const sf::Color COLOR_INDICADOR_INICIO = sf::Color::Green;
        const sf::Color COLOR_INDICADOR_DESTINO = sf::Color::Red;
        sf::VertexArray lineas(sf::PrimitiveType::Lines);
        arcos.go_to_start();
        for (int i = 0; i < arcos.get_size(); ++i) {
            Arco a = arcos.get_Element();
            Nodo nOrigen; 
            Nodo nDestino;
            nodos.go_to_pos(a.origen);
            nOrigen = nodos.get_Element();
            nodos.go_to_pos(a.destino);
            nDestino = nodos.get_Element();
            lineas.append(sf::Vertex(sf::Vector2f(nOrigen.x, nOrigen.y), COLOR_ARCO_NORMAL));
            lineas.append(sf::Vertex(sf::Vector2f(nDestino.x, nDestino.y), COLOR_ARCO_NORMAL));
            arcos.next();
        }
        window.draw(lineas);
        if (resaltado) {
            sf::VertexArray lineasResaltadas(sf::PrimitiveType::Lines);
            resaltado->arcos.go_to_start();
            for (int i = 0; i < resaltado->arcos.get_size(); ++i) {
                Arco a = resaltado->arcos.get_Element();
                Nodo nOrigen;
                Nodo nDestino;
                nodos.go_to_pos(a.origen);
                nOrigen = nodos.get_Element();
                nodos.go_to_pos(a.destino);
                nDestino = nodos.get_Element();
                lineasResaltadas.append(sf::Vertex(sf::Vector2f(nOrigen.x, nOrigen.y), COLOR_ARCO_RESALTADO));
                lineasResaltadas.append(sf::Vertex(sf::Vector2f(nDestino.x, nDestino.y), COLOR_ARCO_RESALTADO));
                resaltado->arcos.next();
            }
            window.draw(lineasResaltadas);
        }
        sf::Font font;
        bool fontLoaded = false;
        if (font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
            fontLoaded = true;
        else if (font.loadFromFile("arial.ttf"))
            fontLoaded = true;
        nodos.go_to_start();
        for (int i = 0; i < numNodos; ++i) {
            Nodo n = nodos.get_Element();
            sf::CircleShape circle(RADIO_NODO);
            circle.setPosition(sf::Vector2f(n.x - RADIO_NODO, n.y - RADIO_NODO));
            circle.setFillColor(COLOR_NODO_RELLENO);
            circle.setOutlineColor(COLOR_NODO_BORDE);
            circle.setOutlineThickness(GROSOR_BORDE);
            window.draw(circle);
            if (fontLoaded) {
                sf::Text text;
                text.setFont(font);
                text.setString(std::to_string(n.id));
                text.setCharacterSize(TAMANO_TEXTO);
                text.setFillColor(COLOR_TEXTO);
                text.setPosition(sf::Vector2f(n.x - 10.0f, n.y - 10.0f));
                window.draw(text);
            }
            nodos.next();
        }
        if (nodoInicio != -1) {
            Nodo n;
            nodos.go_to_pos(nodoInicio);
            n = nodos.get_Element();
            sf::CircleShape indicador(RADIO_INDICADOR);
            indicador.setPosition(sf::Vector2f(n.x - RADIO_INDICADOR, n.y - RADIO_INDICADOR));
            indicador.setFillColor(sf::Color::Transparent);
            indicador.setOutlineColor(COLOR_INDICADOR_INICIO);
            indicador.setOutlineThickness(3.0f);
            window.draw(indicador);
        }
        if (nodoDestino != -1) {
            Nodo n;
            nodos.go_to_pos(nodoDestino);
            n = nodos.get_Element();
            sf::CircleShape indicador(RADIO_INDICADOR);
            indicador.setPosition(sf::Vector2f(n.x - RADIO_INDICADOR, n.y - RADIO_INDICADOR));
            indicador.setFillColor(sf::Color::Transparent);
            indicador.setOutlineColor(COLOR_INDICADOR_DESTINO);
            indicador.setOutlineThickness(3.0f);
            window.draw(indicador);
        }
    }
};