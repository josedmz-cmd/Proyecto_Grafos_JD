#pragma once

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
};

