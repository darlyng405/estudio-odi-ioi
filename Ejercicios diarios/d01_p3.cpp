/*
Problema 1.3 — ¿Qué día será? · nivel 2
Hoy es el día d de la semana (0 = domingo, 1 = lunes, …, 6 = sábado). ¿Qué día de la semana será dentro de k días? 
Si k es negativo, se refiere al pasado.
Entrada: d k, con 0 ≤ d ≤ 6 y |k| ≤ 10^18.
Salida: un entero de 0 a 6.
Ejemplo: 0 -1 → 6; 3 10 → 6.
Matemática: demuestra que ((x % 7) + 7) % 7 está siempre en [0, 6] y es congruente con x módulo 7, incluso cuando x < 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string dias [7] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
    //decidi usar un array ya que definir cada dia variable por variable me parecia poco practico.
    long long d , k; // d = dia actual, k = cantidad de dias a sumar o restar
    cin >> d >> k;

    long long re = ((d + k) % 7 + 7) % 7;
    //re es de nuevo el resultado, siempre lo pondre asi.

    cout << dias[re] <<"\n";
    return 0;
    //vi que era una buena practica siempre poner el return al final en cpp

}