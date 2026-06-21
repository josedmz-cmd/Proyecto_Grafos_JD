/*
José Daniel Mora Zúñiga

	CLASE PAIR
	La clase Pair es una estructura genérica que almacena un par de valores
	de dos tipos diferentes (K y V). Se utiliza para relaciones clave-valor.

	Funcionalidades:
	- Constructores: por defecto, con clave, o con clave y valor.
	- Operadores de comparación (==, !=, <, <=, >, >=) que comparan SOLO la clave.
	- Sobrecarga de operator<< para imprimir en formato (clave, valor).

	Miembros:
		key   -> Clave de tipo K.
		value -> Valor de tipo V.
*/
#pragma once

#include <iostream>

using std::ostream;

template <typename K, typename V>
class Pair {
public:
	K key;
	V value;

	Pair() {}

	Pair(K key) {
		this->key = key;
	}

	Pair(K key, V value) {
		this->key = key;
		this->value = value;
	}

	bool operator==(const Pair<K, V>& other) {
		return key == other.key;
	}

	bool operator!=(const Pair<K, V>& other) {
		return key != other.key;
	}

	bool operator<(const Pair<K, V>& other) {
		return key < other.key;
	}

	bool operator<=(const Pair<K, V>& other) {
		return key <= other.key;
	}

	bool operator>(const Pair<K, V>& other) {
		return key > other.key;
	}

	bool operator>=(const Pair<K, V>& other) {
		return key >= other.key;
	}

	friend ostream& operator<<(ostream& os, const Pair<K, V>& p) {
		os << "(" << p.key << ", " << p.value << ")";
		return os;
	}
};
