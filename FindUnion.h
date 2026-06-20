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

