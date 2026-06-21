/*
José Daniel Mora Zúñiga

    CLASE FINDUNION (UNION-FIND)
    La clase FindUnion implementa la estructura de conjuntos disjuntos
    con compresión de camino y unión por rango. Se utiliza en el algoritmo
    de Kruskal para detectar ciclos.

    Funcionalidades:
    - find(int): Encuentra la raíz del conjunto al que pertenece el elemento,
                 aplicando compresión de camino.
    - unir(int, int): Une dos conjuntos si son diferentes, usando rango.

    Miembros:
        padre[] -> Arreglo de padres.
        rango[] -> Arreglo de rangos (altura aproximada).
        n       -> Número de elementos.
*/
#pragma once

class FindUnion {
private:
    int* padre;
    int* rango;
    int n;

public:
    FindUnion(int n) {
        this->n = n;
        padre = new int[n];
        rango = new int[n];
        for (int i = 0; i < n; ++i) {
            padre[i] = i;
            rango[i] = 0;
        }
    }

    ~FindUnion() {
        delete[] padre;
        delete[] rango;
    }

    int find(int x) {
        if (padre[x] != x) {
            padre[x] = find(padre[x]);
        }
        return padre[x];
    }

    void unir(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) 
            return;
        if (rango[rx] < rango[ry]) {
            padre[rx] = ry;
        }
        else if (rango[rx] > rango[ry]) {
            padre[ry] = rx;
        }
        else {
            padre[ry] = rx;
            rango[rx]++;
        }
    }
};

