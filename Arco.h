#pragma once
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
};

