#pragma once

#include <iostream>
/*
José Daniel Mora Zúñiga

	CLASE NODO (PARA GRAFO)
	La clase Nodo representa un vértice del grafo. Almacena su identificador
	y coordenadas en el plano (x, y). Proporciona operadores de comparación
	por ID y sobrecarga de operator<< para impresión.

	Miembros:
		id  -> Identificador numérico.
		x, y -> Posición en pantalla.

	Métodos:
		Constructores.
		Operadores: <, >, ==, !=.
		friend operator<<.
*/
class Nodo {
public:
	int id;
	float x;
	float y;

	Nodo() {
		id = -1;
		x = 0.0f;
		y = 0.0f;
	}

	Nodo(int id, float x, float y) {
		this->id = id;
		this->x = x;
		this->y = y;
	}

	bool operator<(const Nodo& other) const {
		return id < other.id;
	}

	bool operator>(const Nodo& other) const {
		return id > other.id;
	}

	bool operator==(const Nodo& other) const {
		return id == other.id;
	}

	bool operator!=(const Nodo& other) const {
		return id != other.id;
	}

	friend std::ostream& operator<<(std::ostream& os, const Nodo& n) {
		os << "Nodo(" << n.id << ", " << n.x << ", " << n.y << ")";
		return os;
	}
};

