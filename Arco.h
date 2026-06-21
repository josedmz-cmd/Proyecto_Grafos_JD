/*
José Daniel Mora Zúñiga

	CLASE ARCO (PARA GRAFO)
	La clase Arco representa una arista del grafo. Almacena origen, destino
	y peso (distancia). Proporciona operadores de comparación por peso
	y sobrecarga de operator<< para impresión.

	Miembros:
		origen, destino -> Índices de los nodos conectados.
		peso           -> Valor numérico (distancia al cuadrado en este proyecto).

	Métodos:
		Constructores.
		Operadores: <, >, ==.
		friend operator<<.
*/
#pragma once

#include <iostream>

class Arco {
public: 
	int origen;
	int destino;
	float peso;

	Arco() {
		origen = -1;
		destino = 1;
		peso = 0.0f;
	}

	Arco(int orig, int dest, float p) {
		origen = orig;
		destino = dest;
		peso = p;
	}

	bool operator<(const Arco& other) const {
		return peso < other.peso;
	}

	bool operator>(const Arco& other) const {
		return peso > other.peso;
	}

	bool operator==(const Arco& other) const {
		return (peso == other.peso && origen == other.origen && destino == other.destino);
	}

	friend std::ostream& operator<<(std::ostream& os, const Arco& a) {
		os << "Arco(" << a.origen << " -> " << a.destino << ", peso: " << a.peso << ")";
		return os;
	}
};

