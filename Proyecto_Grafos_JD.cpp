// Proyecto_Grafos_JD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grafo.h"

const int ANCHO = 1300;
const int ALTO = 650;
const int NUM_NODOS = 50;
const float DIST_MAX = 150.0f;
const int MAX_CONEX = 6;
const sf::Color COLOR_FONDO = sf::Color(0, 0, 0);

int main() {
    sf::RenderWindow window(sf::VideoMode(ANCHO, ALTO), "Visualización de Grafos");
    Grafo* grafoActual = new Grafo(NUM_NODOS, DIST_MAX, MAX_CONEX, ANCHO, ALTO);
    Grafo* resaltado = nullptr;
    int nodoInicio = -1;
    int nodoDestino = -1;
    bool mostrarNoConexion = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Num0:
                    delete grafoActual;
                    delete resaltado;
                    grafoActual = new Grafo(NUM_NODOS, DIST_MAX, MAX_CONEX, ANCHO, ALTO);
                    resaltado = nullptr;
                    nodoInicio = -1;
                    nodoDestino = -1;
                    mostrarNoConexion = false;
                    break;
                case sf::Keyboard::Num1:
                    if (nodoInicio != -1) {
                        delete resaltado;
                        resaltado = grafoActual->DFS(nodoInicio);
                        mostrarNoConexion = false;
                    }
                    break;
                case sf::Keyboard::Num2:
                    if (nodoInicio != -1) {
                        delete resaltado;
                        resaltado = grafoActual->BFS(nodoInicio);
                        mostrarNoConexion = false;
                    }
                    break;
                case sf::Keyboard::Num3:
                    if (nodoInicio != -1) {
                        delete resaltado;
                        resaltado = grafoActual->Prim(nodoInicio);
                        mostrarNoConexion = false;
                    }
                    break;
                case sf::Keyboard::Num4:
                    delete resaltado;
                    resaltado = grafoActual->Kruskal();
                    mostrarNoConexion = false;
                    break;
                case sf::Keyboard::Num5:
                    if (nodoInicio != -1 && nodoDestino != -1) {
                        delete resaltado;
                        resaltado = grafoActual->Dijkstra(nodoInicio, nodoDestino);
                        if (resaltado == nullptr) {
                            mostrarNoConexion = true;
                        }
                        else {
                            mostrarNoConexion = false;
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                float mx = event.mouseButton.x;
                float my = event.mouseButton.y;
                int nodoClickeado = -1;
                float radioCuad = 40.0f * 40.0f;
                grafoActual->getNodos().go_to_start();
                for (int i = 0; i < grafoActual->getNumNodos(); ++i) {
                    Nodo n = grafoActual->getNodos().get_Element();
                    float d = Grafo::distanciaCuadrada(Nodo(0, mx, my), n);
                    if (d < radioCuad) {
                        radioCuad = d;
                        nodoClickeado = n.id;
                    }
                    grafoActual->getNodos().next();
                }
                if (nodoClickeado != -1) {
                    nodoInicio = nodoClickeado;
                    mostrarNoConexion = false;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
                float mx = event.mouseButton.x;
                float my = event.mouseButton.y;
                int nodoClickeado = -1;
                float radioCuad = 40.0f * 40.0f;
                grafoActual->getNodos().go_to_start();
                for (int i = 0; i < grafoActual->getNumNodos(); ++i) {
                    Nodo n = grafoActual->getNodos().get_Element();
                    float d = Grafo::distanciaCuadrada(Nodo(0, mx, my), n);
                    if (d < radioCuad) {
                        radioCuad = d;
                        nodoClickeado = n.id;
                    }
                    grafoActual->getNodos().next();
                }
                if (nodoClickeado != -1) {
                    nodoDestino = nodoClickeado;
                    mostrarNoConexion = false;
                }
            }
        }
        window.clear(COLOR_FONDO);
        if (grafoActual) {
            grafoActual->dibujar(window, resaltado, nodoInicio, nodoDestino);
        }
        sf::Font font;
        bool fontLoaded = false;
        if (font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
            fontLoaded = true;
        else if (font.loadFromFile("arial.ttf"))
            fontLoaded = true;
        if (fontLoaded) {
            sf::Text info;
            info.setFont(font);
            info.setCharacterSize(18);
            info.setFillColor(sf::Color::White);
            info.setPosition(10.0f, 10.0f);
            std::string mensaje = "Inicio: " + std::to_string(nodoInicio);
            if (nodoDestino != -1) {
                mensaje += "  Destino: " + std::to_string(nodoDestino);
            }
            info.setString(mensaje);
            window.draw(info);
            if (mostrarNoConexion) {
                sf::Text noPath;
                noPath.setFont(font);
                noPath.setString("No hay conexion entre los nodos");
                noPath.setCharacterSize(20);
                noPath.setFillColor(sf::Color::Red);
                noPath.setPosition(10.0f, 40.0f);
                window.draw(noPath);
            }
        }
        window.display();
    }
    delete grafoActual;
    delete resaltado;
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
