#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h, m, r, s; //hora, minuto, segundos, resultado y residuo

    cin >> s;

    h = s / 3600;
    m = (s % 3600) / 60;
    r = s % 60;

    cout << h << " " << m << " " << r << "\n";

}

/*
Problema 1.2 — Segundos a reloj · nivel 1
Convierte una cantidad de segundos a horas, minutos y segundos.
Entrada: un entero s, con 0 ≤ s ≤ 10^9.
Salida: h m r, donde 0 ≤ m < 60 y 0 ≤ r < 60 (las horas h pueden pasar de 24).
Ejemplo: 3725 → 1 2 5.
Matemática: escribe s = 3600h + 60m + r y demuestra que h, m y r son únicos usando la división euclidiana dos veces.
*/

/*
Que debo de hacer?
Convertir una cantidad de segundos a horas, minutos y segundos.
*/