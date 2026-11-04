# Plan de preparación IOI: 93 días de C++ y matemáticas

**Del domingo 1 de noviembre de 2026 al lunes 1 de febrero de 2027**

3 problemas diarios · 1 proyecto diario para calificar · 93 días · 279 problemas

---

## 1. Cómo funciona este plan

Cada día sigue la misma estructura:

1. **Teoría desde cero.** Solo lo necesario para resolver el día: ideas, fórmulas y, cuando aparece una herramienta nueva, un fragmento de código.
2. **Tres problemas** de dificultad creciente. El primero calienta, el segundo exige la idea central del día y el tercero obliga a combinar ideas o a demostrar algo. Cada problema trae una línea de **Matemática**: lo que debes razonar, deducir o demostrar antes de programar.
3. **Proyecto del día.** Un programa más completo que integra lo aprendido. Es lo que me entregas para calificar.

El plan sube de forma gradual. La semana 1 parte de cero absoluto (compilar, leer números, ciclos). Las semanas 11 a 13 llegan a técnicas de nivel IOI: descomposición pesada y por centroides, DP con optimizaciones, geometría, juegos, problemas interactivos y problemas con subtareas.

Los **sábados** son de **repaso**: tres problemas que mezclan lo de la semana. Los días **92 y 93** son **simulacros de IOI**: tres problemas por día con subtareas, que es el formato de cada jornada de la competencia real (la IOI tiene dos jornadas con tres problemas cada una).

**Tiempo estimado.** Las primeras semanas, entre 1 y 2 horas por día; hacia el final, entre 3 y 5. Si un día se te va el doble, no pasa nada: lo importante es entregar y entender tus errores.

**Protocolo cuando te atascas** (en este orden):

1. Reescribe el enunciado con tus palabras y resuelve a mano el ejemplo.
2. Escribe una solución lenta pero correcta (fuerza bruta). Te servirá para comparar después.
3. Calcula, a partir de los límites, qué complejidad necesitas (tabla de la sección 4).
4. Relee la teoría del día y la línea de Matemática.
5. Solo entonces pregúntame, contándome qué intentaste.

---

## 2. Preparar el entorno (antes del Día 1)

Necesitas un compilador de C++ y un editor de texto (VS Code sirve perfecto).

| Sistema | Instalación |
|---|---|
| Linux (Ubuntu/Debian) | `sudo apt install g++` |
| Windows | Instala WSL (Ubuntu) y luego `sudo apt install g++`; o instala MSYS2 y el paquete `mingw-w64-ucrt-x86_64-gcc` |
| macOS | `brew install gcc` (el `g++` que trae el sistema es en realidad Clang y no incluye `bits/stdc++.h`; usa `g++-NN` con la versión que instale Homebrew) |

Comprueba que funciona con `g++ --version`. Comandos que usarás todo el plan:

```bash
# Desarrollo: avisos + detección de errores de memoria y desbordamientos
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -fsanitize=address,undefined -g -o main main.cpp

# Como en un concurso
g++ -std=c++17 -O2 -o main main.cpp

# Ejecutar leyendo la entrada desde un archivo
./main < entrada.txt
```

Los sanitizers (`-fsanitize`) no existen en MinGW de Windows; en WSL sí. Si no los tienes, quita esa opción.

---

## 3. Plantilla base

Todo programa del plan parte de esta plantilla:

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // tu código aquí
    return 0;
}
```

- `#include <bits/stdc++.h>` trae toda la biblioteca estándar (es una extensión de GCC).
- `ios::sync_with_stdio(false); cin.tie(nullptr);` acelera mucho `cin`/`cout`. Con estas líneas no mezcles `scanf/printf` con `cin/cout`.
- Imprime saltos de línea con `"\n"`, no con `endl` (`endl` vacía el búfer cada vez y es lento).
- `using ll = long long;` crea un nombre corto para el tipo que más usarás.

---

## 4. Convenciones de los enunciados

- Cada problema indica **Entrada**, **Salida**, **Límites** y un **Ejemplo**. En los ejemplos, el símbolo `/` separa líneas distintas.
- Salvo que se diga otra cosa: tiempo 1 s, memoria 256 MB, índices desde 1 y todos los valores caben en `long long`.
- Las fórmulas van en texto plano para que se vean igual en cualquier visor: `a^b` potencia, `n!` factorial, `C(n,k)` combinaciones, `floor(x)` y `ceil(x)` parte entera inferior y superior, `a mod m` resto, `|x|` valor absoluto, `Σ` suma.
- Si hay varias respuestas válidas, el enunciado fija un criterio de desempate para que la respuesta sea única.
- Los ejemplos son pequeños a propósito. Los límites son los reales: tu solución debe cumplirlos.

**Qué complejidad necesitas.** Regla práctica: C++ hace del orden de `10^8` operaciones simples por segundo.

| Tamaño máximo de `n` | Complejidad que suele alcanzar |
|---|---|
| hasta 10 | `O(n!)` |
| hasta 20 | `O(2^n · n)` |
| hasta 500 | `O(n^3)` |
| hasta 5 000 | `O(n^2)` |
| hasta 200 000 | `O(n log n)` |
| hasta 10 000 000 | `O(n)` |
| hasta 10^18 | `O(log n)` o `O(1)` |

**Escala de nivel (1 a 10).**

| Nivel | Significado | Temas típicos |
|---|---|---|
| 1–2 | Fundamentos | entrada/salida, ciclos, aritmética entera |
| 3–4 | Técnicas básicas | ordenar, búsqueda binaria, prefijos, simulación, números primos |
| 5–6 | Estándar de concurso | DP clásica, grafos básicos, BIT, DSU |
| 7–8 | Avanzado | árboles de segmentos, LCA, DP con optimizaciones, flujos |
| 9–10 | Nivel IOI exigente | combinar 2 o 3 técnicas, subtareas, demostraciones finas |

El nivel **sube a lo largo del plan**, pero cada tema nuevo arranca con problemas más sencillos que el cierre del tema anterior. Nivel promedio por semana (semanas 1 a 14): 2,0 → 2,8 → 3,5 → 3,8 → 4,4 → 4,1 → 5,0 → 5,8 → 5,6 → 6,6 → 7,3 → 6,2 → 7,9 → 8,2.

---

## 5. Entrega y calificación

**Qué me envías cada día** (pégalo en el chat o adjunta los archivos, y escribe "Entrega Día N"):

- `dNN.cpp`: el código del proyecto del día (`NN` es el número de día con dos dígitos; por ejemplo `d07.cpp`). Si quieres que revise también los problemas, mándalos en archivos aparte: `dNN_p1.cpp`, `dNN_p2.cpp`, `dNN_p3.cpp`.
- `dNN_notas.md`: máximo una página con (a) la idea y la complejidad de cada solución, (b) la demostración o el razonamiento matemático que se pide, (c) tus casos de prueba con la salida esperada y (d) cuánto tiempo te tomó y qué te costó.

**Rúbrica (100 puntos).**

| Criterio | Puntos | Qué evalúo |
|---|---|---|
| Corrección | 40 | Casos de ejemplo, casos borde (mínimos, máximos, vacíos, repetidos) y casos aleatorios |
| Eficiencia | 20 | Que la complejidad cumpla los límites del enunciado |
| Matemática | 15 | Que el razonamiento o la demostración sea completo y correcto |
| Pruebas | 15 | Casos propios que realmente intenten romper tu solución (desde el Día 7, comparación contra fuerza bruta cuando aplique) |
| Calidad del código | 10 | Nombres claros, funciones cortas, nada de código muerto |

Un día queda **aprobado con 70 puntos o más**. Con menos, corriges y reenvías antes de avanzar. Con 85 o más, el tema está dominado.

**Regla de recuperación.** Si pierdes un día, lo haces al siguiente sin saltarte contenido. No acumules más de 2 días pendientes.

---

## 6. Mapa del plan

| Semana | Fechas | Días | Enfoque |
|---|---|---|---|
| 1 | 1–7 nov | 1–7 | Fundamentos de C++ y aritmética entera |
| 2 | 8–14 nov | 8–14 | Complejidad, STL, cuadrículas, aritmética modular y primos |
| 3 | 15–21 nov | 15–21 | Técnicas sobre arreglos: prefijos, diferencias, búsqueda binaria y dos punteros |
| 4 | 22–28 nov | 22–28 | Pilas, colas, backtracking, bits y combinatoria |
| 5 | 29 nov–5 dic | 29–35 | Algoritmos voraces y programación dinámica |
| 6 | 6–12 dic | 36–42 | Grafos: recorridos, componentes, DSU y árboles de expansión mínima |
| 7 | 13–19 dic | 43–49 | Caminos mínimos y árboles |
| 8 | 20–26 dic | 50–56 | Estructuras de datos para consultas de rango |
| 9 | 27 dic–2 ene | 57–63 | Cadenas, teoría de números avanzada y probabilidad |
| 10 | 3–9 ene | 64–70 | Programación dinámica avanzada |
| 11 | 10–16 ene | 71–77 | Grafos avanzados |
| 12 | 17–23 ene | 78–84 | Geometría, juegos y técnicas de competencia |
| 13 | 24–30 ene | 85–91 | Integración: técnicas de nivel IOI |
| 14 | 31 ene–1 feb | 92–93 | Simulacros finales de la IOI |

---

## 7. Índice de días

La columna "Niveles" muestra el nivel de los problemas 1, 2 y 3 de cada día.

| Día | Fecha | Tema | Niveles |
|---|---|---|---|
| 1 | dom 1 nov | Tu primer programa en C++ | 1·1·2 |
| 2 | lun 2 nov | Ciclos y acumuladores | 1·2·2 |
| 3 | mar 3 nov | Arreglos y vectores | 1·2·3 |
| 4 | mié 4 nov | Funciones y recursión | 1·2·3 |
| 5 | jue 5 nov | Cadenas de texto | 1·2·3 |
| 6 | vie 6 nov | Divisibilidad y máximo común divisor | 1·2·3 |
| 7 | sáb 7 nov | Repaso de la semana 1 y primer test de estrés | 2·3·4 |
| 8 | dom 8 nov | Complejidad y estimación de costos | 2·3·3 |
| 9 | lun 9 nov | Ordenar con la STL | 1·2·3 |
| 10 | mar 10 nov | Conjuntos y diccionarios | 1·3·4 |
| 11 | mié 11 nov | Cuadrículas y matrices | 2·2·3 |
| 12 | jue 12 nov | Aritmética modular y exponenciación rápida | 2·3·4 |
| 13 | vie 13 nov | Números primos: división de prueba y criba | 2·3·4 |
| 14 | sáb 14 nov | Repaso de la semana 2 y pruebas de estrés | 3·4·4 |
| 15 | dom 15 nov | Sumas prefijas | 2·3·4 |
| 16 | lun 16 nov | Sumas prefijas en 2D | 3·3·5 |
| 17 | mar 17 nov | Arreglos de diferencias | 2·3·4 |
| 18 | mié 18 nov | Búsqueda binaria | 2·3·4 |
| 19 | jue 19 nov | Búsqueda binaria sobre la respuesta | 3·4·5 |
| 20 | vie 20 nov | Dos punteros y ventana deslizante | 3·4·4 |
| 21 | sáb 21 nov | Repaso de la semana 3 y pruebas de estrés | 3·4·5 |
| 22 | dom 22 nov | Pilas, colas y pila monótona | 2·4·5 |
| 23 | lun 23 nov | Colas de prioridad y deque | 3·4·5 |
| 24 | mar 24 nov | Recursión y backtracking | 3·4·5 |
| 25 | mié 25 nov | Bits y máscaras | 2·3·4 |
| 26 | jue 26 nov | Combinatoria y coeficientes binomiales | 3·4·5 |
| 27 | vie 27 nov | Euclides extendido, inversos modulares y teorema chino del resto | 3·4·5 |
| 28 | sáb 28 nov | Repaso de la semana 4 y pruebas de estrés | 3·4·5 |
| 29 | dom 29 nov | Algoritmos voraces I: intervalos | 3·4·5 |
| 30 | lun 30 nov | Algoritmos voraces II: ordenar con el comparador correcto | 4·4·5 |
| 31 | mar 1 dic | Programación dinámica I: estados y recurrencias | 3·4·5 |
| 32 | mié 2 dic | Programación dinámica II: mochila | 4·4·5 |
| 33 | jue 3 dic | Programación dinámica III: secuencias | 4·5·6 |
| 34 | vie 4 dic | Programación dinámica IV: cuadrículas | 3·4·6 |
| 35 | sáb 5 dic | Simulacro 1 estilo IOI | 4·5·6 |
| 36 | dom 6 dic | Grafos: representación, DFS y componentes conexas | 2·3·4 |
| 37 | lun 7 dic | BFS: caminos más cortos sin pesos | 3·4·6 |
| 38 | mar 8 dic | BFS avanzado: grafos bipartitos, 0-1 BFS y estados | 3·4·5 |
| 39 | mié 9 dic | Orden topológico y DP en grafos acíclicos dirigidos | 4·4·5 |
| 40 | jue 10 dic | Conjuntos disjuntos (DSU) | 3·4·6 |
| 41 | vie 11 dic | Árbol de expansión mínima | 4·5·6 |
| 42 | sáb 12 dic | Repaso de la semana 6 y pruebas de estrés | 3·4·5 |
| 43 | dom 13 dic | Dijkstra | 4·5·6 |
| 44 | lun 14 dic | Bellman–Ford y Floyd–Warshall | 4·5·5 |
| 45 | mar 15 dic | Árboles: profundidad, diámetro y contribución de aristas | 3·4·5 |
| 46 | mié 16 dic | DP en árboles y reenraizado | 5·5·6 |
| 47 | jue 17 dic | Recorrido de Euler: consultas sobre subárboles | 4·5·6 |
| 48 | vie 18 dic | Ancestro común más bajo (LCA) con saltos binarios | 5·5·6 |
| 49 | sáb 19 dic | Repaso de la semana 7: mini-simulacro de grafos y árboles | 5·6·7 |
| 50 | dom 20 dic | Árbol de Fenwick (BIT) | 4·5·6 |
| 51 | lun 21 dic | Árbol de segmentos | 5·6·7 |
| 52 | mar 22 dic | Propagación perezosa (lazy) | 6·7·7 |
| 53 | mié 23 dic | Tabla dispersa (sparse table) y consultas de mínimo | 4·5·6 |
| 54 | jue 24 dic | Compresión de coordenadas y barrido (sweep line) | 4·6·6 |
| 55 | vie 25 dic | Descomposición en bloques y algoritmo de Mo | 5·7·7 |
| 56 | sáb 26 dic | Repaso de la semana 8 y pruebas de estrés | 5·6·7 |
| 57 | dom 27 dic | Hashing de cadenas | 5·5·6 |
| 58 | lun 28 dic | KMP y función Z | 4·5·6 |
| 59 | mar 29 dic | Trie y XOR máximo | 5·6·6 |
| 60 | mié 30 dic | Función φ de Euler y exponentes enormes | 5·5·6 |
| 61 | jue 31 dic | Inclusión–exclusión | 5·6·7 |
| 62 | vie 1 ene | Probabilidad y esperanza | 5·6·6 |
| 63 | sáb 2 ene | Simulacro 2 estilo IOI | 6·6·7 |
| 64 | dom 3 ene | DP con máscaras de bits | 6·6·7 |
| 65 | lun 4 ene | DP de dígitos | 6·6·7 |
| 66 | mar 5 ene | DP con transiciones optimizadas | 6·7·7 |
| 67 | mié 6 ene | DP de intervalos | 6·6·7 |
| 68 | jue 7 ene | Optimización convexa: rectas (CHT) y divide y vencerás | 7·8·8 |
| 69 | vie 8 ene | Exponenciación de matrices y recurrencias lineales | 6·7·7 |
| 70 | sáb 9 ene | Repaso de la semana 10 y pruebas de estrés de DP | 6·6·7 |
| 71 | dom 10 ene | Componentes fuertemente conexas (SCC) | 6·7·7 |
| 72 | lun 11 ene | Puentes y puntos de articulación | 6·6·7 |
| 73 | mar 12 ene | 2-SAT | 7·7·8 |
| 74 | mié 13 ene | Flujo máximo y emparejamientos | 7·7·8 |
| 75 | jue 14 ene | Descomposición pesada-ligera (HLD) | 8·8·8 |
| 76 | vie 15 ene | Descomposición por centroides | 6·8·9 |
| 77 | sáb 16 ene | Repaso de la semana 11 y pruebas de estrés de grafos | 7·8·8 |
| 78 | dom 17 ene | Geometría computacional con enteros | 4·5·6 |
| 79 | lun 18 ene | Envolvente convexa | 6·7·7 |
| 80 | mar 19 ene | Teoría de juegos | 5·6·7 |
| 81 | mié 20 ene | Meet in the middle y bitsets | 6·6·7 |
| 82 | jue 21 ene | Problemas con grader e interactivos | 5·6·7 |
| 83 | vie 22 ene | Problemas constructivos e invariantes | 6·7·7 |
| 84 | sáb 23 ene | Repaso de la semana 12 y mini-simulacro 3 | 6·7·8 |
| 85 | dom 24 ene | Árbol de segmentos persistente | 8·8·8 |
| 86 | lun 25 ene | Fusión pequeño a grande (*small-to-large*) | 7·8·8 |
| 87 | mar 26 ene | Arreglo de sufijos | 8·8·8 |
| 88 | mié 27 ene | Búsqueda binaria avanzada: sobre la respuesta y paralela | 7·8·8 |
| 89 | jue 28 ene | DP con estructuras de datos | 7·7·8 |
| 90 | vie 29 ene | Conjunto integrador difícil | 7·8·9 |
| 91 | sáb 30 ene | Repaso de la semana 13 y biblioteca personal | 8·8·9 |
| 92 | dom 31 ene | Simulacro IOI, Jornada 1 | 7·8·9 |
| 93 | lun 1 feb | Simulacro IOI, Jornada 2 y cierre del plan | 7·8·10 |

---

## Semana 1 · 1–7 nov · Fundamentos de C++ y aritmética entera

**Objetivo:** compilar y ejecutar programas, leer y escribir datos, usar ciclos, arreglos, funciones y cadenas, y dominar el algoritmo de Euclides.

### Día 1 · domingo 1 de noviembre · Tu primer programa en C++

**Teoría desde cero.** Un programa en C++ es un archivo de texto (`.cpp`). El **compilador** (`g++`) lo traduce a un ejecutable que la computadora corre. El ciclo de trabajo siempre es: escribir, compilar, ejecutar y comprobar la salida.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;            // lee dos enteros separados por espacio o salto de línea
    cout << a + b << "\n";    // imprime la suma y un salto de línea
    return 0;
}
```

- **Tipos:** `int` guarda enteros de unos ±2,1·10^9 (exactamente de −2 147 483 648 a 2 147 483 647); `long long`, de unos ±9,2·10^18; `double` guarda decimales; `char` un carácter; `string` texto; `bool` verdadero o falso. Si un resultado no cabe en el tipo, el programa responde mal **sin avisar** (desbordamiento). En concursos usa `long long` salvo que estés seguro.
- **Operadores:** `+ - * /` y `%` (resto). Con enteros, `/` descarta la parte decimal y redondea hacia cero: `7 / 2` da `3` y `-7 / 2` da `-3`. Además, `-7 % 2` da `-1` en C++.
- **Decisiones:** `if (cond) { ... } else if (cond2) { ... } else { ... }`. Comparaciones: `== != < <= > >=`. Lógica: `&&` (y), `||` (o), `!` (no).
- **Compilar y ejecutar:** `g++ -std=c++17 -O2 -o d01 d01.cpp` y luego `./d01`.

**Matemática del día: división euclidiana.** Para enteros `a` y `b > 0` existen únicos `q` y `r` con `a = b·q + r` y `0 ≤ r < b`. En C++ el resto puede salir negativo si `a` es negativo; la forma segura de obtener el resto no negativo es `((a % b) + b) % b`.

**Problema 1.1 — Suma grande** · nivel 1

Lee dos enteros `a` y `b` e imprime su suma.

- **Entrada:** una línea con `a b`, con `|a|, |b| ≤ 10^18`.
- **Salida:** `a + b`.
- **Ejemplo:** `2000000000 2000000000` → `4000000000`.
- **Matemática:** calcula `2^31 − 1` y explica por qué, con `int`, el ejemplo daría una respuesta incorrecta.

**Problema 1.2 — Segundos a reloj** · nivel 1

Convierte una cantidad de segundos a horas, minutos y segundos.

- **Entrada:** un entero `s`, con `0 ≤ s ≤ 10^9`.
- **Salida:** `h m r`, donde `0 ≤ m < 60` y `0 ≤ r < 60` (las horas `h` pueden pasar de 24).
- **Ejemplo:** `3725` → `1 2 5`.
- **Matemática:** escribe `s = 3600h + 60m + r` y demuestra que `h`, `m` y `r` son únicos usando la división euclidiana dos veces.

**Problema 1.3 — ¿Qué día será?** · nivel 2

Hoy es el día `d` de la semana (0 = domingo, 1 = lunes, …, 6 = sábado). ¿Qué día de la semana será dentro de `k` días? Si `k` es negativo, se refiere al pasado.

- **Entrada:** `d k`, con `0 ≤ d ≤ 6` y `|k| ≤ 10^18`.
- **Salida:** un entero de 0 a 6.
- **Ejemplo:** `0 -1` → `6`; `3 10` → `6`.
- **Matemática:** demuestra que `((x % 7) + 7) % 7` está siempre en `[0, 6]` y es congruente con `x` módulo 7, incluso cuando `x < 0`.

**Proyecto del día — Calculadora de consola**

Programa que lee líneas `a op b` hasta el fin de la entrada, con `op` en `+ - * / %`, y escribe el resultado de cada línea. Para `/` y `%` usa la división euclidiana con resto no negativo: `a = b·q + r` con `0 ≤ r < |b|`; `/` imprime `q` y `%` imprime `r`. Si `b = 0` en `/` o `%`, imprime `ERROR`. Usa `long long`.

- **Ejemplos:** `7 / 2` → `3`; `-7 / 2` → `-4`; `-7 % 2` → `1`; `5 % 0` → `ERROR`.
- **Qué reviso:** negativos, cero, formato exacto de salida y el razonamiento del resto en las notas.
- **Entrega:** `d01.cpp` y `d01_notas.md`.

### Día 2 · lunes 2 de noviembre · Ciclos y acumuladores

**Teoría desde cero.** Un **ciclo** repite instrucciones. `for (int i = 1; i <= n; i++) { ... }` ejecuta el bloque con `i = 1, 2, …, n`. `while (cond) { ... }` repite mientras `cond` sea verdadera. `break` sale del ciclo y `continue` salta a la siguiente vuelta.

Dos patrones que usarás siempre:

- **Contador:** `cnt++` cada vez que se cumple algo.
- **Acumulador:** `sum += x` para sumar, `mx = max(mx, x)` para quedarte con el máximo.

```cpp
long long sum = 0;
int n; cin >> n;
for (int i = 1; i <= n; i++) sum += i;   // suma 1 + 2 + ... + n

long long x;
while (cin >> x) { /* ... */ }           // lee hasta que ya no queden datos
```

**Costo.** Un ciclo de `n` vueltas hace del orden de `n` operaciones: con `n = 10^6` es instantáneo; con `n = 10^10`, imposible. Aprende a contar vueltas desde ya.

**Matemática del día: suma de Gauss.** `1 + 2 + … + n = n(n+1)/2`. Prueba: escribe la suma al derecho y al revés; cada columna suma `n+1` y hay `n` columnas, así que `2S = n(n+1)`. Consecuencia: la suma de los primeros `k` pares es `k(k+1)`.

**Problema 2.1 — Múltiplos de 3 o 5** · nivel 1

Suma los enteros entre 1 y `n` que son múltiplos de 3 o de 5.

- **Entrada:** `n`, con `1 ≤ n ≤ 10^6`.
- **Salida:** la suma.
- **Ejemplo:** `10` → `33` (3 + 5 + 6 + 9 + 10).
- **Matemática:** la suma de los múltiplos de `k` hasta `n` es `k·m(m+1)/2` con `m = floor(n/k)`. Usa inclusión–exclusión (resta los múltiplos de 15) para obtener una fórmula directa y comprueba que coincide con tu ciclo.

**Problema 2.2 — Dígitos al revés** · nivel 2

Cuenta los dígitos de un número y escribe el número con los dígitos invertidos (sin ceros a la izquierda).

- **Entrada:** `n`, con `0 ≤ n ≤ 10^9`.
- **Salida:** `cantidad_de_dígitos número_invertido`.
- **Ejemplo:** `1200` → `4 21`; `0` → `1 0`.
- **Matemática:** si `n = Σ d_i·10^i`, explica por qué `n % 10` extrae el último dígito y `n / 10` lo elimina. Para `n ≥ 1`, la cantidad de dígitos es `floor(log10(n)) + 1`.

**Problema 2.3 — Collatz** · nivel 2

Dado `n`, repite: si es par, divídelo entre 2; si es impar, reemplázalo por `3n + 1`, hasta llegar a 1. Cuenta los pasos y el valor máximo alcanzado (incluyendo el inicial).

- **Entrada:** `n`, con `1 ≤ n ≤ 10^6`.
- **Salida:** `pasos máximo`.
- **Ejemplo:** `6` → `8 16` (6, 3, 10, 5, 16, 8, 4, 2, 1); `1` → `0 1`.
- **Matemática:** demuestra que si `n` es impar entonces `3n + 1` es par. Con `n = 113383` el máximo es 2 482 111 348: compáralo con `2^31 − 1` y explica por qué aquí `int` falla.

**Proyecto del día — Estadísticas de una secuencia**

Programa que lee enteros hasta el fin de la entrada (sin que se diga cuántos son) y escribe seis líneas:

```
cantidad 4
suma 19
minimo -2
maximo 10
promedio 4.75
pares 3
```

(el ejemplo corresponde a la entrada `4 -2 7 10`). El promedio va con exactamente 2 decimales (`cout << fixed << setprecision(2) << x;`). Si no hay ningún número, imprime solo `VACIO`.

- **Qué reviso:** que no uses arreglos (basta un ciclo con acumuladores), el promedio con `double`, los pares negativos (`-2` es par) y el caso vacío.
- **Notas:** explica por qué `sum / n` con enteros truncaría y cuánto puede crecer `sum` con `10^6` números de `10^9`.
- **Entrega:** `d02.cpp` y `d02_notas.md`.

### Día 3 · martes 3 de noviembre · Arreglos y vectores

**Teoría desde cero.** Un **arreglo** guarda muchos valores del mismo tipo, numerados desde 0. `vector<int> a(n)` crea `n` elementos con índices `0..n-1`.

```cpp
int n; cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

int cnt[1001];            // arreglo global: todo empieza en 0
cnt[x]++;                 // cuenta cuántas veces aparece el valor x
```

- Acceder fuera de rango (`a[n]`, `a[-1]`) es un error grave que no siempre avisa: compila con `-fsanitize=address,undefined` para detectarlo.
- **Contar frecuencias:** si los valores son pequeños (≤ 10^6), un arreglo `cnt[valor]` resuelve "¿cuántas veces aparece cada valor?" en una sola pasada.
- Para recorrer: `for (int i = 0; i < n; i++)` o `for (int x : a)`.

**Matemática del día.** *Principio del palomar:* si metes `n + 1` objetos en `n` cajas, alguna caja tiene al menos 2. En general, con `N` objetos en `k` cajas, alguna tiene al menos `ceil(N/k)`. Y *posiciones en círculo:* un elemento que avanza `k` lugares en un arreglo circular de tamaño `n` queda en `(i + k) mod n`.

**Problema 3.1 — Máximo y su posición** · nivel 1

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 10^5` y `|a_i| ≤ 10^9`.
- **Salida:** el valor máximo y la posición (desde 1) de su primera aparición.
- **Ejemplo:** `5 / 3 9 2 9 1` → `9 2`.
- **Matemática:** demuestra que el máximo de `n` números se obtiene con `n − 1` comparaciones y que no se puede con menos (cada número, salvo el máximo, debe "perder" al menos una comparación).

**Problema 3.2 — Moda** · nivel 2

Encuentra el valor que más se repite.

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 10^5` y `1 ≤ a_i ≤ 1000`.
- **Salida:** el valor más frecuente; si hay empate, el menor.
- **Ejemplo:** `5 / 3 1 3 1 2` → `1`.
- **Matemática:** con valores entre 1 y 1000, ¿cuál es el mínimo `n` que garantiza que algún valor aparece al menos 3 veces? Justifícalo con el principio del palomar.

**Problema 3.3 — Rotar el arreglo** · nivel 3

Rota un arreglo `k` posiciones a la derecha (cada rotación mueve el último elemento al principio).

- **Entrada:** `n k` y luego `n` enteros, con `1 ≤ n ≤ 10^5` y `0 ≤ k ≤ 10^18`.
- **Salida:** el arreglo rotado, en una línea.
- **Ejemplo:** `5 7 / 1 2 3 4 5` → `4 5 1 2 3`.
- **Matemática:** demuestra que rotar `n` veces deja el arreglo igual, así que solo importa `k mod n`, y que el elemento de la posición `i` (desde 0) termina en `(i + k) mod n`.

**Proyecto del día — Reporte de notas**

Lee `n` y luego `n` calificaciones enteras de 0 a 100. Escribe los conteos por rango, en este orden y formato:

```
00-09: 1
10-19: 0
...
80-89: 0
90-100: 2
aprobados: 3/4
promedio: 68.75
maxima: 100 (1)
```

(el ejemplo corresponde a las notas `95 100 73 7`; los rangos `20-29` a `70-79` se escriben igual que los mostrados). `aprobados` cuenta notas `≥ 60`; `maxima` es la nota máxima y, entre paréntesis, cuántos estudiantes la obtuvieron. Como extra, dibuja un histograma con `*`.

- **Qué reviso:** el último rango (90–100 incluye al 100), un arreglo de frecuencias en lugar de muchos `if`, e índices sin salirse de rango.
- **Entrega:** `d03.cpp` y `d03_notas.md`.

### Día 4 · miércoles 4 de noviembre · Funciones y recursión

**Teoría desde cero.** Una **función** agrupa código reutilizable: recibe parámetros y puede devolver un valor.

```cpp
long long fact(int n) {
    if (n == 0) return 1;        // caso base: detiene la recursión
    return n * fact(n - 1);      // caso recursivo: el mismo problema, más pequeño
}

void intercambia(int &a, int &b) {   // & = por referencia: modifica los originales
    int t = a; a = b; b = t;
}
```

- Por defecto los parámetros se **copian**; con `&` trabajas sobre el original (útil para modificar o para no copiar vectores grandes: `const vector<int> &v`).
- Una función **recursiva** se llama a sí misma. Siempre necesita un **caso base** y cada llamada debe acercarse a él; si no, el programa se queda sin pila y se cae.
- Cada llamada ocupa memoria de pila: una recursión de 10^5 niveles puede ser peligrosa; la de 20 niveles, no.

**Matemática del día: inducción.** Para probar que algo vale para todo `n ≥ 0`: (1) pruebas el caso base `n = 0`; (2) suponiendo que vale para `n − 1`, pruebas que vale para `n`. Recursión e inducción son gemelas: demostrar que `fact(n)` es correcto es exactamente una inducción.

**Problema 4.1 — Factorial** · nivel 1

- **Entrada:** `n`, con `0 ≤ n ≤ 20`.
- **Salida:** `n!`.
- **Ejemplo:** `5` → `120`.
- **Matemática:** `20! = 2 432 902 008 176 640 000`. Comprueba que `21!` ya supera `2^63 − 1` y explica por qué el límite del problema es 20.

**Problema 4.2 — Torres de Hanoi** · nivel 2

Hay `n` discos en la torre `A`; hay que pasarlos a la torre `C` usando `B`, moviendo un disco a la vez y sin poner uno grande sobre uno pequeño. Escribe la solución mínima, que es única, usando recursión: mover `n−1` discos de `A` a `B`, mover el disco más grande de `A` a `C` y mover `n−1` discos de `B` a `C`.

- **Entrada:** `n`, con `1 ≤ n ≤ 10`.
- **Salida:** primero la cantidad de movimientos y luego un movimiento por línea, `origen destino`.
- **Ejemplo:** `2` → `3 / A B / A C / B C`.
- **Matemática:** si `T(n)` es el número de movimientos, `T(n) = 2T(n−1) + 1` y `T(1) = 1`. Demuestra por inducción que `T(n) = 2^n − 1`.

**Problema 4.3 — Fibonacci módulo** · nivel 3

Con `F(0) = 0`, `F(1) = 1` y `F(n) = F(n−1) + F(n−2)`, calcula `F(n)` módulo `1 000 000 007`.

- **Entrada:** `n`, con `0 ≤ n ≤ 10^6`.
- **Salida:** `F(n) mod 1 000 000 007`.
- **Ejemplo:** `10` → `55`; `50` → `586268941`.
- **Matemática:** demuestra que `(x + y) mod m = ((x mod m) + (y mod m)) mod m`. Explica por qué reducir en cada paso es obligatorio: `F(10^6)` tiene más de 200 000 dígitos.

**Proyecto del día — Intérprete matemático**

Programa que lee comandos hasta el fin de la entrada y responde cada uno con una línea. Cada comando va en una función propia.

- `fact n` (0 ≤ n ≤ 20): `n!`.
- `fib n` (0 ≤ n ≤ 90): `F(n)` exacto.
- `hanoi n` (1 ≤ n ≤ 62): movimientos mínimos.
- `llamadas n` (0 ≤ n ≤ 35): cuántas llamadas se hacen en total al ejecutar una función recursiva `f(n)`, donde `f(0)` y `f(1)` no llaman a nadie y `f(n)` llama a `f(n−1)` y a `f(n−2)` (cuenta la llamada inicial y todas las anidadas; por ejemplo, `llamadas 2` = 3). Impleméntalo de verdad con recursión y también con una fórmula.
- Si el argumento está fuera de rango, imprime `FUERA DE RANGO`.

- **Notas:** demuestra por inducción que `llamadas(n) = 2·F(n+1) − 1`.
- **Entrega:** `d04.cpp` y `d04_notas.md`.

### Día 5 · jueves 5 de noviembre · Cadenas de texto

**Teoría desde cero.** Una `string` guarda texto. Cada carácter es en realidad un número (código ASCII): `'a' = 97`, `'A' = 65`, `'0' = 48`.

```cpp
string s;
cin >> s;                         // lee una palabra (hasta el espacio)
cin >> ws;                        // descarta saltos de línea pendientes
getline(cin, s);                  // lee una línea completa, con espacios
int len = s.size();               // longitud
char c = s[0];                    // primer carácter (índices desde 0)
int pos = c - 'a';                // 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
reverse(s.begin(), s.end());      // invierte la cadena
string t = s.substr(2, 3);        // 3 caracteres desde el índice 2
```

- Después de `cin >> x` queda un salto de línea sin leer. Si luego usas `getline`, primero escribe `cin >> ws;` o leerás una línea vacía.
- Funciones útiles: `isalpha(c)`, `isdigit(c)`, `isupper(c)`, `tolower(c)`, `toupper(c)`.
- Se comparan con `==`, `<` y `>` (orden alfabético).

**Matemática del día.** *Aritmética en el alfabeto:* con letras numeradas de 0 a 25, correr una letra `k` lugares es `(p + k) mod 26`; la regla del resto no negativo del Día 1 aplica igual. *Conteo de centros:* una cadena de longitud `n` tiene `2n − 1` centros posibles de palíndromo (`n` de longitud impar y `n − 1` de longitud par).

**Problema 5.1 — Palíndromo** · nivel 1

- **Entrada:** una cadena `s` de letras minúsculas, con `1 ≤ |s| ≤ 10^5`.
- **Salida:** `SI` si se lee igual al derecho y al revés; si no, `NO`.
- **Ejemplo:** `reconocer` → `SI`; `hola` → `NO`.
- **Matemática:** demuestra que `s` es palíndromo si y solo si `s[i] = s[n−1−i]` para todo `i < floor(n/2)`.

**Problema 5.2 — Cifrado César** · nivel 2

Desplaza cada letra `k` posiciones en el alfabeto (cíclico), manteniendo mayúsculas y minúsculas. Los demás caracteres no cambian.

- **Entrada:** primera línea `k` (`|k| ≤ 10^18`); segunda línea, un texto de hasta `10^5` caracteres (puede tener espacios).
- **Salida:** el texto cifrado.
- **Ejemplo:** `3 / Hola, Mundo!` → `Krod, Pxqgr!`; `-3 / Krod` → `Hola`.
- **Matemática:** justifica que solo importa `k mod 26` y que cifrar con `k` y luego con `−k` devuelve el texto original.

**Problema 5.3 — Subcadenas palíndromas** · nivel 3

Cuenta las parejas `(i, j)` con `i ≤ j` tales que `s[i..j]` es palíndromo (cuenta cada posición por separado, aunque el texto se repita).

- **Entrada:** una cadena `s` de minúsculas, con `1 ≤ |s| ≤ 2000`.
- **Salida:** la cantidad.
- **Ejemplo:** `aaa` → `6`; `abba` → `6`.
- **Matemática:** expande desde cada uno de los `2n − 1` centros mientras los extremos coincidan. Demuestra que el peor caso es `O(n^2)` y que para `aaaa…a` la respuesta es `n(n+1)/2`.

**Proyecto del día — Analizador de texto**

Lee un texto de varias líneas hasta el fin de la entrada y escribe seis líneas con estas claves: `lineas`, `palabras` (secuencias de caracteres sin espacio), `caracteres` (todos, sin contar saltos de línea), `vocales` (`aeiou`, sin distinguir mayúsculas), `letra_mas_frecuente` (sin distinguir mayúsculas; en empate, la primera alfabéticamente; `-` si no hay letras) y `palindromo` (`SI` o `NO`, ignorando mayúsculas y todo lo que no sea letra; el texto vacío cuenta como `SI`).

```
lineas: 1
palabras: 4
caracteres: 18
vocales: 8
letra_mas_frecuente: a
palindromo: SI
```

(el ejemplo corresponde a la entrada `Anita lava la tina`).

- **Qué reviso:** manejo de líneas vacías, descomposición en funciones (una por métrica) y las notas con el razonamiento del palíndromo.
- **Entrega:** `d05.cpp` y `d05_notas.md`.

### Día 6 · viernes 6 de noviembre · Divisibilidad y máximo común divisor

**Teoría desde cero.** Decimos que `a` **divide** a `b` (`a | b`) si `b = a·k` para algún entero `k`. El **máximo común divisor** `gcd(a, b)` es el mayor entero que divide a ambos; el **mínimo común múltiplo** `lcm(a, b)` es el menor positivo que es múltiplo de ambos.

**Algoritmo de Euclides:** `gcd(a, 0) = a` y `gcd(a, b) = gcd(b, a mod b)`.

```cpp
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;     // divide primero para evitar desbordamiento
}
```

(C++17 ya trae `std::gcd` y `std::lcm` en `<numeric>`, pero conviene que sepas escribirlos).

**Matemática del día.**

- *Por qué funciona Euclides:* si `a = q·b + r`, todo divisor común de `a` y `b` divide a `r = a − q·b`, y todo divisor común de `b` y `r` divide a `a`. Los dos conjuntos de divisores comunes coinciden, así que el `gcd` no cambia.
- *Cuánto tarda:* el resto se reduce a menos de la mitad cada dos pasos, así que son `O(log b)` pasos.
- *Identidad de Bézout:* existen enteros `x, y` con `a·x + b·y = gcd(a, b)`, y todos los valores `a·x + b·y` son múltiplos de `gcd(a, b)`.
- `gcd(a, b) · lcm(a, b) = a · b`.

**Problema 6.1 — MCD y MCM** · nivel 1

- **Entrada:** `a b`, con `1 ≤ a, b ≤ 10^9`.
- **Salida:** `gcd lcm`.
- **Ejemplo:** `12 18` → `6 36`.
- **Matemática:** demuestra `gcd(a, b) · lcm(a, b) = a · b` mirando los exponentes de cada primo (mínimo para el gcd, máximo para el lcm).

**Problema 6.2 — Suma de fracciones** · nivel 2

Suma dos fracciones y escribe el resultado irreducible, con denominador positivo.

- **Entrada:** `p1 q1 p2 q2`, con `|p| ≤ 10^9` y `1 ≤ q ≤ 10^9`.
- **Salida:** `p/q`; si el resultado es 0, escribe `0/1`.
- **Ejemplo:** `1 2 1 3` → `5/6`; `1 2 -1 2` → `0/1`; `3 4 1 4` → `1/1`.
- **Matemática:** demuestra que todo racional tiene una única forma irreducible con denominador positivo, y que `p/q` con `gcd(|p|, q) = 1` es esa forma.

**Problema 6.3 — Jarras** · nivel 3

Tienes dos jarras de capacidades `a` y `b` litros y agua ilimitada. Puedes llenar una jarra, vaciarla, o verter una en otra hasta vaciar la primera o llenar la segunda. Para cada consulta `c`, responde si puede quedar exactamente `c` litros en alguna de las jarras.

- **Entrada:** `a b`; luego `T`; luego `T` líneas con un entero `c`. Límites: `1 ≤ a, b ≤ 10^9`, `1 ≤ T ≤ 10^5`, `0 ≤ c ≤ 2·10^9`.
- **Salida:** `SI` o `NO` por consulta.
- **Ejemplo:** `3 5 / 3 / 4 / 1 / 6` → `SI / SI / NO`.
- **Matemática:** demuestra que es posible si y solo si `c ≤ max(a, b)` y `gcd(a, b)` divide a `c`. Necesidad: las cantidades en las jarras son siempre múltiplos de `gcd(a, b)` (invariante). Suficiencia: usa Bézout.

**Proyecto del día — Calculadora de fracciones**

Lee comandos hasta el fin de la entrada: `add p1 q1 p2 q2`, `sub ...`, `mul ...`, `div ...`. Escribe cada resultado como `p/q` irreducible con `q > 0` (el cero es `0/1`). Si `div` divide entre una fracción con numerador 0, imprime `ERROR`. Valores de entrada: `|p| ≤ 10^9`, `1 ≤ q ≤ 10^9`.

- **Ejemplos:** `add 1 2 1 3` → `5/6`; `div 1 2 -3 4` → `-2/3`.
- **Qué reviso:** una función `normaliza(p, q)` reutilizada en las cuatro operaciones, signos correctos y que ninguna operación desborde `long long`.
- **Entrega:** `d06.cpp` y `d06_notas.md`.

### Día 7 · sábado 7 de noviembre · Repaso de la semana 1 y primer test de estrés

**Teoría: probar contra fuerza bruta.** Un programa que pasa los ejemplos puede estar mal. La defensa más poderosa en concursos es el **test de estrés**: escribes (1) una solución lenta pero obviamente correcta (*fuerza bruta*), (2) la solución rápida, y (3) un generador de entradas aleatorias pequeñas. Comparas ambas respuestas miles de veces; la primera diferencia es un contraejemplo que puedes depurar.

```cpp
mt19937_64 rng(12345);                                  // semilla fija: resultados repetibles
auto aleatorio = [&](long long lo, long long hi) {      // entero uniforme en [lo, hi]
    return uniform_int_distribution<long long>(lo, hi)(rng);
};
```

**Problema 7.1 — Raíz digital** · nivel 2

Suma los dígitos de `n`; si el resultado tiene más de un dígito, repite hasta quedar con uno.

- **Entrada:** `n`, con `1 ≤ n ≤ 10^18`.
- **Salida:** el dígito final.
- **Ejemplo:** `987654321` → `9` (suma 45, luego 9).
- **Matemática:** como `10 ≡ 1 (mod 9)`, demuestra que `n` y la suma de sus dígitos tienen el mismo resto módulo 9, y deduce la fórmula `1 + (n − 1) mod 9` para `n ≥ 1`.

**Problema 7.2 — Pares coprimos** · nivel 3

Cuenta las parejas `(i, j)` con `1 ≤ i < j ≤ n` y `gcd(i, j) = 1`.

- **Entrada:** `n`, con `1 ≤ n ≤ 2000`.
- **Salida:** la cantidad.
- **Ejemplo:** `5` → `9`.
- **Matemática:** hay `n(n−1)/2` parejas en total. Estima cuántas operaciones hace tu programa para `n = 2000` (parejas por pasos de Euclides) y decide si cabe en 1 segundo.

**Problema 7.3 — Josephus** · nivel 4

`n` personas numeradas de 1 a `n` forman un círculo. Se cuenta desde la persona 1 y cada `k`-ésima persona sale del círculo; el conteo continúa desde la siguiente. ¿Quién sobrevive?

- **Entrada:** `n k`, con `1 ≤ n ≤ 10^6` y `1 ≤ k ≤ 10^9`.
- **Salida:** el número del sobreviviente.
- **Ejemplo:** `7 3` → `4` (salen 3, 6, 2, 7, 5, 1).
- **Matemática:** sea `J(n)` el sobreviviente con personas numeradas desde 0. Demuestra `J(1) = 0` y `J(n) = (J(n−1) + k) mod n`: tras eliminar a la persona `(k−1) mod n`, el círculo restante es un círculo de `n−1` personas con las etiquetas "desplazadas" `k` lugares. Implementa en `O(n)`.

**Proyecto del día — Test de estrés**

Un único programa con tres partes:

1. `josephus_simulacion(n, k)` (simulación con un `vector` y `erase`) y `josephus_formula(n, k)` (la recurrencia).
2. Un `main` que compara ambas para todo `1 ≤ n ≤ 200` y `1 ≤ k ≤ 20`, e imprime `OK` o la primera discrepancia en formato `n k simulacion formula`.
3. Lo mismo para la raíz digital: fórmula contra suma repetida de dígitos, con `10^4` valores aleatorios en `[1, 10^18]` generados con `mt19937_64`.

- **Qué reviso:** que la simulación sea genuinamente independiente de la fórmula, la semilla fija y el mensaje de discrepancia.
- **Notas:** una tabla con los primeros 10 valores de `J` para `k = 2` y qué patrón ves.
- **Entrega:** `d07.cpp` y `d07_notas.md`.

---

## Semana 2 · 8–14 nov · Complejidad, STL, cuadrículas, aritmética modular y primos

**Objetivo:** estimar el costo de un programa antes de escribirlo, usar `sort`, `set` y `map`, trabajar con matrices, dominar la aritmética modular y manejar números primos.

### Día 8 · domingo 8 de noviembre · Complejidad y estimación de costos

**Teoría desde cero.** La **complejidad** cuenta cuántas operaciones hace un programa en función del tamaño de la entrada `n`, ignorando constantes y términos pequeños. Se escribe con `O(...)`.

- Un ciclo de `n` vueltas es `O(n)`. Dos ciclos anidados de `n` vueltas son `O(n^2)`. Un ciclo que divide `n` entre 2 en cada vuelta es `O(log n)`.
- Ciclos "triangulares" también son cuadráticos:

```cpp
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)     // (n-1) + (n-2) + ... + 1 = n(n-1)/2 vueltas
        revisa(i, j);
```

- Para saber si tu idea cabe en el tiempo, usa la tabla de la sección 4: con `n = 2·10^5`, `O(n^2)` (4·10^10 operaciones) es imposible y `O(n log n)` (unos 3,5·10^6) es trivial.
- **Medir tiempo real:** `auto t0 = chrono::steady_clock::now();` antes y después; resta y convierte con `chrono::duration_cast<chrono::milliseconds>(t1 - t0).count()`.

**Un algoritmo para mejorar una idea cuadrática: Kadane.** Para la mayor suma de un subarreglo contiguo, en vez de probar todos los pares `(i, j)`, guarda la mejor suma de un subarreglo que *termina* en la posición actual:

```cpp
long long best = a[0], cur = a[0];
for (int i = 1; i < n; i++) {
    cur = max(a[i], cur + a[i]);   // o empiezo de nuevo en a[i], o extiendo el anterior
    best = max(best, cur);
}
```

**Matemática del día.** Sumas que aparecen al contar operaciones: `1 + 2 + … + n = n(n+1)/2`; `log2(n)` es cuántas veces puedes dividir `n` entre 2 hasta llegar a 1; `n + n/2 + n/4 + … < 2n`.

**Problema 8.1 — Pares con suma K** · nivel 2

Cuenta las parejas de posiciones `i < j` tales que `a_i + a_j = K`.

- **Entrada:** `n K` y luego `n` enteros. Límites: `2 ≤ n ≤ 3000`, `|a_i|, |K| ≤ 10^9`.
- **Salida:** la cantidad de parejas.
- **Ejemplo:** `5 6 / 1 5 3 3 2` → `2`.
- **Matemática:** hay `n(n−1)/2` parejas. Para `n = 3000`, ¿cuántas comparaciones son? Calcula también cuántas haría una solución de tres ciclos anidados y por qué no serviría.

**Problema 8.2 — Subarreglo de suma máxima** · nivel 3

Encuentra la mayor suma entre los subarreglos contiguos **no vacíos**.

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 10^6` y `|a_i| ≤ 10^9`.
- **Salida:** la suma máxima.
- **Ejemplo:** `9 / -2 1 -3 4 -1 2 1 -5 4` → `6` (el subarreglo `4 -1 2 1`).
- **Matemática:** demuestra Kadane: sea `b_i` la mejor suma de un subarreglo que termina en `i`. Todo subarreglo que termina en `i` es `[a_i]` o un subarreglo que termina en `i−1` extendido con `a_i`; por tanto `b_i = max(a_i, b_{i−1} + a_i)`, y la respuesta es `max b_i`. ¿Por qué cabe en `long long`?

**Problema 8.3 — Ternas pitagóricas** · nivel 3

Cuenta las ternas `(a, b, c)` con `1 ≤ a < b < c ≤ n` y `a² + b² = c²`.

- **Entrada:** `n`, con `1 ≤ n ≤ 2000`.
- **Salida:** la cantidad.
- **Ejemplo:** `20` → `6` (3-4-5, 6-8-10, 9-12-15, 12-16-20, 5-12-13, 8-15-17).
- **Matemática:** para `n = 2000` recorrer los pares `(a, b)` es `O(n^2)`. Verifica que `c = round(sqrt(a² + b²))` con `c·c == a² + b²` es exacto en `double` para estos tamaños. Bonus: Euclides genera todas las ternas primitivas con `(m² − k², 2mk, m² + k²)` para `m > k`, coprimos y de distinta paridad.

**Proyecto del día — Cronómetro de complejidad**

Programa que mide y tabula el tiempo real de tres algoritmos con tamaños crecientes (cada tamaño es el doble del anterior, al menos cuatro tamaños por algoritmo):

1. `O(n)`: sumar un arreglo aleatorio.
2. `O(n log n)`: ordenar un arreglo aleatorio con `sort`.
3. `O(n^2)`: contar parejas con suma `K` con dos ciclos (la idea del Problema 8.1).

Escoge tamaños que tarden entre 10 ms y 2 s. Imprime una tabla `algoritmo n milisegundos razon`, donde `razon` es el tiempo dividido entre el tiempo del tamaño anterior.

- **Qué reviso:** que el compilador no elimine tu ciclo (usa el resultado, por ejemplo imprimiéndolo), que uses `steady_clock` y que generes los datos con `mt19937_64` fuera de la medición.
- **Notas:** explica qué razón esperabas al duplicar `n` en cada algoritmo (≈2, ≈2 y ≈4) y si los datos lo confirman.
- **Entrega:** `d08.cpp` y `d08_notas.md`.

### Día 9 · lunes 9 de noviembre · Ordenar con la STL

**Teoría desde cero.** `sort(v.begin(), v.end())` ordena de menor a mayor en `O(n log n)`.

```cpp
sort(v.begin(), v.end());                       // ascendente
sort(v.begin(), v.end(), greater<int>());       // descendente

vector<pair<int, string>> r;                    // (nota, nombre)
sort(r.begin(), r.end(), [](const auto &x, const auto &y) {
    if (x.first != y.first) return x.first > y.first;   // nota mayor primero
    return x.second < y.second;                          // empate: nombre alfabético
});
```

- `pair<A, B>` guarda dos valores (`.first`, `.second`) y ya se compara en orden lexicográfico: primero por `first`, luego por `second`.
- Un **comparador** debe devolver `true` solo si `x` va **estrictamente antes** que `y`. Nunca uses `<=`: rompe el orden y puede colgar el programa.
- `stable_sort` conserva el orden original de los empatados.

**Matemática del día.**

- *Cota inferior:* hay `n!` ordenaciones posibles y cada comparación descarta como máximo la mitad; hacen falta al menos `log2(n!) ≈ n·log2(n) − 1,44·n` comparaciones. Ningún ordenamiento por comparaciones es mejor que `O(n log n)`.
- *Ordenar convierte problemas globales en locales:* tras ordenar, la mínima diferencia entre dos elementos aparece entre vecinos. Prueba: si `x < z < y` entonces `y − x > z − x`, así que un par no vecino nunca es mínimo estricto.

**Problema 9.1 — Ordenar** · nivel 1

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 10^5` y `|a_i| ≤ 10^9`.
- **Salida:** dos líneas: el arreglo ascendente y el arreglo descendente.
- **Ejemplo:** `4 / 3 1 4 1` → `1 1 3 4 / 4 3 1 1`.
- **Matemática:** explica cuántas comparaciones necesitas al menos para ordenar `n = 5` elementos (usa `log2(5!)`).

**Problema 9.2 — Ranking de estudiantes** · nivel 2

- **Entrada:** `n` y luego `n` líneas `nombre nota`, con `1 ≤ n ≤ 10^5`, nombres de letras minúsculas (hasta 20) y `0 ≤ nota ≤ 100`.
- **Salida:** los estudiantes por nota descendente; en empate, por nombre ascendente. Una línea `nombre nota` por estudiante.
- **Ejemplo:** `3 / ana 90 / beto 95 / carla 90` → `beto 95 / ana 90 / carla 90`.
- **Matemática:** demuestra que tu comparador es un orden estricto válido: irreflexivo (`comp(x, x)` es falso) y transitivo.

**Problema 9.3 — Menor diferencia** · nivel 3

Entre todas las parejas `i < j`, halla la menor `|a_i − a_j|` y cuántas parejas la alcanzan.

- **Entrada:** `n` y luego `n` enteros, con `2 ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** `diferencia_mínima cantidad_de_parejas`.
- **Ejemplo:** `5 / 8 1 4 9 5` → `1 2`; `4 / 7 7 7 1` → `0 3`.
- **Matemática:** si la mínima es `> 0`, todos los valores son distintos y toda pareja mínima es de vecinos (en el arreglo ordenado). Si la mínima es `0`, un valor repetido `c` veces aporta `C(c, 2)` parejas. Justifica cada caso.

**Proyecto del día — Tabla de posiciones**

Lee `n` equipos (`1 ≤ n ≤ 20`, nombres sin espacios) y luego `m` partidos (`0 ≤ m ≤ 200`), cada uno como `equipoA golesA equipoB golesB`. Victoria = 3 puntos, empate = 1, derrota = 0. Ordena por: puntos (desc), diferencia de goles (desc), goles a favor (desc), nombre (asc). Imprime una línea por equipo con `posicion nombre PJ G E P GF GC DG Pts`.

- **Qué reviso:** una `struct` con los datos del equipo, un comparador con los cuatro criterios, y que la búsqueda de equipos por nombre funcione (con `n ≤ 20` basta búsqueda lineal).
- **Notas:** demuestra que tu comparador es transitivo con los cuatro criterios.
- **Entrega:** `d09.cpp` y `d09_notas.md`.

### Día 10 · martes 10 de noviembre · Conjuntos y diccionarios

**Teoría desde cero.** Un `set<T>` guarda elementos **únicos y ordenados**; un `map<K, V>` asocia a cada clave un valor, también ordenado por clave. Insertar, borrar y buscar cuestan `O(log n)`.

```cpp
set<int> s;
s.insert(5); s.erase(5);
if (s.count(7)) { /* 7 está */ }
auto it = s.lower_bound(3);                 // primer elemento >= 3
if (it != s.end()) cout << *it << "\n";

map<string, int> freq;
freq[palabra]++;                            // crea la clave con 0 si no existía
for (auto &[clave, cnt] : freq)             // recorre en orden de clave
    cout << clave << " " << cnt << "\n";
```

- `multiset` permite repetidos. `unordered_set` y `unordered_map` suelen ser más rápidos, pero no tienen orden y en el peor caso pueden degradarse: por ahora usa las versiones ordenadas.
- **Clave canónica:** si dos objetos "equivalentes" siempre producen la misma clave (por ejemplo, las letras de una palabra ordenadas), un `map` de clave a cantidad agrupa los equivalentes.

**Matemática del día.** *Unión de dos conjuntos:* `|A ∪ B| = |A| + |B| − |A ∩ B|`. *Relaciones de equivalencia:* agrupar por clave canónica funciona porque "tener la misma clave" es reflexiva, simétrica y transitiva. *Complemento:* `a_i + a_j = K` equivale a `a_j = K − a_i`: convierte una búsqueda de parejas en consultas a un diccionario.

**Problema 10.1 — Valores distintos** · nivel 1

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** cuántos valores distintos hay.
- **Ejemplo:** `6 / 5 3 5 1 3 3` → `3`.
- **Matemática:** si todos los valores están en `[1, 100]` y `n = 101`, ¿qué garantiza el principio del palomar sobre la cantidad de distintos?

**Problema 10.2 — Grupos de anagramas** · nivel 3

Dos palabras son anagramas si usan exactamente las mismas letras con las mismas repeticiones.

- **Entrada:** `n` y luego `n` palabras de minúsculas, con `1 ≤ n ≤ 10^5` y longitud total `≤ 10^6`.
- **Salida:** `cantidad_de_grupos tamaño_del_grupo_más_grande`.
- **Ejemplo:** `5 / listen silent enlist google gogole` → `2 3`.
- **Matemática:** demuestra que dos palabras son anagramas si y solo si sus versiones ordenadas son iguales. ¿Por qué la ordenada es una clave canónica?

**Problema 10.3 — Dos sumas** · nivel 4

Encuentra la pareja de posiciones `i < j` con `a_i + a_j = K` que tenga el `j` más pequeño; si hay empate, el `i` más pequeño.

- **Entrada:** `n K` y luego `n` enteros, con `2 ≤ n ≤ 2·10^5`, `|a_i|, |K| ≤ 10^9`.
- **Salida:** `i j` (desde 1) o `-1` si no existe.
- **Ejemplo:** `5 9 / 2 7 11 15 1` → `1 2`; `4 6 / 3 3 1 5` → `1 2`; `3 100 / 1 2 3` → `-1`.
- **Matemática:** recorre `j` de izquierda a derecha guardando, para cada valor, su primera posición. Demuestra que la primera `j` con complemento ya visto es el menor `j` posible y que la posición guardada da el menor `i`.

**Proyecto del día — Inventario de tienda**

Lee comandos hasta el fin de la entrada y usa un `map<string, long long>`:

- `alta nombre cantidad`: suma `cantidad` al producto. Imprime `OK`.
- `venta nombre cantidad`: si hay suficiente, resta e imprime `OK`; si no, imprime `FALTA` y no cambia nada.
- `consulta nombre`: imprime la cantidad (0 si no existe).
- `listar`: imprime `nombre cantidad` de cada producto con cantidad positiva, en orden alfabético, y termina con la línea `fin`.
- `top k`: imprime los `k` productos con más cantidad (empate: orden alfabético), uno por línea.

- **Qué reviso:** que no crees claves vacías al consultar (`m[x]` crea la clave; usa `find`), el orden en `listar` y la ordenación de `top`.
- **Entrega:** `d10.cpp` y `d10_notas.md`.

### Día 11 · miércoles 11 de noviembre · Cuadrículas y matrices

**Teoría desde cero.** Una cuadrícula se guarda como `vector<vector<int>>` (o `vector<string>` si son caracteres). El elemento de la fila `i` y columna `j` es `g[i][j]`.

```cpp
int n, m; cin >> n >> m;
vector<vector<int>> g(n, vector<int>(m));
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> g[i][j];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};     // arriba, derecha, abajo, izquierda
for (int d = 0; d < 4; d++) {
    int x = i + dx[d], y = j + dy[d];
    if (x < 0 || x >= n || y < 0 || y >= m) continue; // fuera de la cuadrícula
    // usa g[x][y]
}
```

- Ocho vecinos: usa `dx = {-1,-1,-1,0,0,1,1,1}` y `dy = {-1,0,1,-1,1,-1,0,1}`.
- **Siempre** comprueba los límites antes de acceder.
- Para leer filas de caracteres: `vector<string> g(n); for (auto &f : g) cin >> f;`.

**Matemática del día.** En una matriz `n × n`: los elementos de la diagonal principal cumplen `i = j`; los de la antidiagonal, `i + j = n − 1`. Una **rotación de 90° a la derecha** lleva `(i, j)` a `(j, n − 1 − i)`. La **distancia de Manhattan** entre dos celdas es `|x1 − x2| + |y1 − y2|`.

**Problema 11.1 — Diagonales y filas** · nivel 2

- **Entrada:** `n` y luego una matriz `n × n` de enteros, con `1 ≤ n ≤ 500` y `|a| ≤ 10^6`.
- **Salida:** `suma_diagonal suma_antidiagonal fila_de_mayor_suma` (fila desde 1; en empate, la primera).
- **Ejemplo:** `3 / 1 2 3 / 4 5 6 / 7 8 9` → `15 15 3`.
- **Matemática:** demuestra que `(i, j)` está en la antidiagonal si y solo si `i + j = n − 1`, y que en una matriz impar ambas diagonales comparten exactamente una celda.

**Problema 11.2 — Rotar 90°** · nivel 2

Rota una matriz `n × m` 90° en sentido horario.

- **Entrada:** `n m` y luego la matriz, con `1 ≤ n, m ≤ 500`.
- **Salida:** la matriz resultante, de `m` filas y `n` columnas.
- **Ejemplo:** `2 3 / 1 2 3 / 4 5 6` → `4 1 / 5 2 / 6 3`.
- **Matemática:** deduce la regla `nueva[j][n−1−i] = vieja[i][j]` y comprueba que aplicarla 4 veces devuelve la matriz original.

**Problema 11.3 — Juego de la vida** · nivel 3

En una cuadrícula con celdas vivas `#` y muertas `.`, calcula una generación: una celda viva con 2 o 3 vecinas vivas sobrevive; una celda muerta con exactamente 3 vecinas vivas nace; el resto queda muerto. Los bordes no se enlazan (fuera de la cuadrícula todo está muerto).

- **Entrada:** `n m` y luego `n` filas de `m` caracteres, con `1 ≤ n, m ≤ 500`.
- **Salida:** la cuadrícula siguiente.
- **Ejemplo:** `5 5 / ..... / ..#.. / ..#.. / ..#.. / .....` → `..... / ..... / .###. / ..... / .....`.
- **Matemática:** cada celda tiene como máximo 8 vecinas. Calcula el costo total `O(8·n·m)` y explica por qué necesitas una cuadrícula nueva para el resultado (no actualizar sobre la misma).

**Proyecto del día — Buscaminas**

Lee `n m` y una cuadrícula de `*` (mina) y `.` (vacío). Imprime la cuadrícula donde cada `.` se reemplaza por la cantidad de minas en sus 8 vecinas (los `*` se mantienen). Después imprime una línea `minas: X` con el total de minas.

```
*211
12*1
0111
minas: 2
```

(el ejemplo corresponde a la entrada `3 4 / *... / ..*. / ....`).

- **Qué reviso:** arreglos `dx` y `dy`, comprobación de límites y funciones separadas para leer, calcular e imprimir.
- **Entrega:** `d11.cpp` y `d11_notas.md`.

### Día 12 · jueves 12 de noviembre · Aritmética modular y exponenciación rápida

**Teoría desde cero.** Decimos `a ≡ b (mod m)` si `a` y `b` dejan el mismo resto al dividir entre `m`. Las respuestas de muchos problemas piden "módulo `10^9 + 7`" para que los números no crezcan sin control.

- Suma, resta y producto se pueden reducir **en cualquier paso**: `(a + b) mod m = ((a mod m) + (b mod m)) mod m`, y lo mismo con `·` y `−`.
- **La división no** se puede reducir así (se verá en el Día 26).
- Para restar: `((a − b) % m + m) % m`.
- Con `m ≤ 10^9 + 7`, el producto de dos valores ya reducidos es `< 1,0·10^18` y cabe en `long long`.

**Exponenciación rápida.** Calcular `a^b` multiplicando `b` veces es imposible si `b = 10^18`. La idea: `a^b = a^(b/2) · a^(b/2)` (y un factor extra `a` si `b` es impar).

```cpp
long long potencia(long long a, long long b, long long m) {
    long long r = 1 % m;
    a %= m;
    while (b > 0) {
        if (b & 1) r = r * a % m;     // si el bit actual de b es 1, multiplica
        a = a * a % m;                // eleva al cuadrado
        b >>= 1;                      // pasa al siguiente bit
    }
    return r;
}
```

**Matemática del día.** Si `b = Σ b_i·2^i` (escritura en binario), entonces `a^b = Π (a^(2^i))^(b_i)`. Invariante del ciclo: `r · a^b` siempre vale lo mismo que al inicio; al terminar `b = 0` y `r` es la respuesta. Son `O(log b)` multiplicaciones: unas 60 para `b = 10^18`.

**Problema 12.1 — Potencia modular** · nivel 2

- **Entrada:** `a b m`, con `0 ≤ a ≤ 10^9`, `0 ≤ b ≤ 10^18` y `1 ≤ m ≤ 10^9`.
- **Salida:** `a^b mod m`.
- **Ejemplo:** `2 10 1000` → `24`; `5 0 1` → `0`.
- **Matemática:** demuestra el invariante del ciclo y explica por qué `5 0 1` da `0` y no `1` (por eso se inicia `r = 1 % m`).

**Problema 12.2 — Últimos k dígitos** · nivel 3

Halla los últimos `k` dígitos de `n^n`, escritos con exactamente `k` cifras (con ceros a la izquierda si hace falta).

- **Entrada:** `n k`, con `1 ≤ n ≤ 10^9` y `1 ≤ k ≤ 9`.
- **Salida:** los `k` dígitos.
- **Ejemplo:** `7 4` → `3543` (7^7 = 823543); `10 3` → `000`.
- **Matemática:** demuestra que `x mod 10^k` son exactamente los últimos `k` dígitos de `x`. Para rellenar con ceros usa `setw(k)` y `setfill('0')`.

**Problema 12.3 — Producto modular enorme** · nivel 4

Calcula `a·b mod m` cuando `m` llega a `10^18`, donde `a·b` no cabe en `long long`.

- **Entrada:** `a b m`, con `0 ≤ a, b < m ≤ 10^18`.
- **Salida:** `a·b mod m`.
- **Ejemplo:** `999999999999999999 999999999999999999 1000000000000000000` → `1`.
- **Matemática:** escribe `b` en binario y suma `a·2^i mod m` para cada bit encendido: nunca hay valores `≥ 2m ≤ 2·10^18`, que sí caben en `long long`. Demuestra la corrección y explica el ejemplo: `(−1)^2 ≡ 1 (mod 10^18)`. (Alternativa: `__int128`.)

**Proyecto del día — Intercambio de claves Diffie–Hellman de juguete**

Dos personas acuerdan una clave secreta en público: eligen un primo `p` y una base `g`, cada una guarda un secreto (`a` y `b`), publican `A = g^a mod p` y `B = g^b mod p`, y calculan `K1 = B^a mod p` y `K2 = A^b mod p`.

- **Entrada:** `p g a b`, con `2 ≤ p ≤ 10^18` primo, `1 ≤ g < p` y `1 ≤ a, b ≤ 10^18`.
- **Salida:** `A B K1 K2`.
- **Ejemplo:** `23 5 4 3` → `4 10 18 18`.
- **Qué reviso:** potencia modular con producto seguro (Problema 12.3 o `__int128`), y que `K1 = K2`.
- **Notas:** demuestra que `K1 = K2 = g^(ab) mod p`.
- **Entrega:** `d12.cpp` y `d12_notas.md`.

### Día 13 · viernes 13 de noviembre · Números primos: división de prueba y criba

**Teoría desde cero.** Un entero `n ≥ 2` es **primo** si solo es divisible entre 1 y entre sí mismo.

**Teorema fundamental de la aritmética:** todo entero `n ≥ 2` se escribe de forma **única** como producto de primos: `n = p1^e1 · p2^e2 · … · pk^ek`.

**Comprobar un primo en `O(√n)`.** Si `n = a·b` con `1 < a ≤ b`, entonces `a ≤ √n`; basta probar divisores hasta `√n`.

```cpp
bool esPrimo(long long n) {
    if (n < 2) return false;
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0) return false;
    return true;
}
```

**Criba de Eratóstenes.** Para obtener todos los primos hasta `N`: tacha los múltiplos de cada primo, empezando en su cuadrado.

```cpp
vector<bool> compuesto(N + 1);
for (int i = 2; (long long)i * i <= N; i++)
    if (!compuesto[i])
        for (int j = i * i; j <= N; j += i) compuesto[j] = true;
```

Para factorizar rápido muchos números, guarda el **menor factor primo** `spf[j]` de cada `j` en la misma criba y divide repetidamente por `spf[n]`.

**Matemática del día.** Hay infinitos primos (Euclides: si fueran finitos, `p1·p2·…·pk + 1` tendría un factor primo fuera de la lista). La criba cuesta `N·(1/2 + 1/3 + 1/5 + …) ≈ N·ln ln N`. Hay unos `N / ln N` primos hasta `N`: por ejemplo, 664 579 hasta `10^7`.

**Problema 13.1 — ¿Es primo?** · nivel 2

- **Entrada:** `T` y luego `T` enteros `n`, con `1 ≤ T ≤ 50` y `1 ≤ n ≤ 10^12`.
- **Salida:** `SI` o `NO` por cada `n`.
- **Ejemplo:** `4 / 1 / 2 / 91 / 1000000007` → `NO / SI / NO / SI`.
- **Matemática:** demuestra que basta probar hasta `√n`. Calcula el costo máximo del programa (`T · 10^6` divisiones) y concluye si cabe en 1 s.

**Problema 13.2 — Contar primos** · nivel 3

- **Entrada:** `n`, con `1 ≤ n ≤ 10^7`.
- **Salida:** cuántos primos hay entre 1 y `n`.
- **Ejemplo:** `10` → `4`; `100` → `25`.
- **Matemática:** demuestra que empezar a tachar en `i²` es suficiente (los múltiplos `k·i` con `k < i` ya los tachó un primo menor) y justifica que hace falta probar `i` solo hasta `√N`.

**Problema 13.3 — Cantidad de divisores** · nivel 4

- **Entrada:** `q` y luego `q` enteros `n`, con `1 ≤ q ≤ 10^5` y `1 ≤ n ≤ 10^6`.
- **Salida:** la cantidad de divisores de cada `n`, separados por espacios.
- **Ejemplo:** `4 / 1 12 36 97` → `1 6 9 2`.
- **Matemática:** si `n = Π p_i^(e_i)`, demuestra que la cantidad de divisores es `Π (e_i + 1)` (cada divisor elige su exponente de `p_i` entre `0` y `e_i` de forma independiente). Explica por qué la criba con `spf` factoriza cada número en `O(log n)`.

**Proyecto del día — Analizador numérico**

Para cada consulta `n` (`1 ≤ n ≤ 10^12`), imprime una línea con: si es primo o compuesto, su factorización, la cantidad de divisores `tau`, la suma de divisores `sigma` y su clasificación (`perfecto` si `sigma − n = n`, `abundante` si `sigma − n > n`, `deficiente` si es menor). Usa una criba hasta `10^6` y divide solo entre primos.

```
28: compuesto | 2^2 * 7 | tau=6 | sigma=56 | perfecto
13: primo | 13 | tau=2 | sigma=14 | deficiente
1: ni primo ni compuesto | 1 | tau=1 | sigma=1 | deficiente
```

La entrada es `q` y luego `q` valores (`1 ≤ q ≤ 100`).

- **Qué reviso:** el resto grande que queda como primo después de dividir (si `n` tiene un factor primo mayor que `10^6`), el formato exacto y el uso de `sigma = Π (p^(e+1) − 1)/(p − 1)`.
- **Notas:** demuestra la fórmula de `sigma` y explica por qué tras dividir entre todos los primos `≤ 10^6` lo que queda es 1 o un primo.
- **Entrega:** `d13.cpp` y `d13_notas.md`.

### Día 14 · sábado 14 de noviembre · Repaso de la semana 2 y pruebas de estrés

**Teoría: razonar con aritmética de potencias de primos.** Para el último dígito distinto de cero de `n!` necesitas la **fórmula de Legendre**: el exponente del primo `p` en `n!` es `e_p(n!) = floor(n/p) + floor(n/p²) + floor(n/p³) + …`. Un cero final aparece por cada par de factores `2·5`; como hay más 2 que 5, el exponente de los ceros es `e_5`.

**Problema 14.1 — Goldbach** · nivel 3

Todo par `n ≥ 4` hasta donde se ha comprobado es suma de dos primos. Para cada `n`, halla el primo `p` más pequeño tal que `n − p` también es primo.

- **Entrada:** `T` y luego `T` enteros pares `n`, con `1 ≤ T ≤ 10^4` y `4 ≤ n ≤ 10^6`.
- **Salida:** `p n−p` por cada consulta.
- **Ejemplo:** `3 / 4 / 10 / 28` → `2 2 / 3 7 / 5 23`.
- **Matemática:** si `p > n/2`, entonces `n − p < n/2` es un primo menor que también forma pareja; por eso el menor `p` cumple `p ≤ n/2`. Usa una criba hasta `10^6`.

**Problema 14.2 — Ordenar por divisores** · nivel 4

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 10^5` y `1 ≤ a_i ≤ 10^6`.
- **Salida:** los números ordenados por cantidad de divisores descendente; en empate, por valor ascendente.
- **Ejemplo:** `5 / 12 7 36 1 6` → `36 12 6 7 1`.
- **Matemática:** prepara una tabla de cantidad de divisores para todo `1..10^6` con una criba de múltiplos (`para cada d, suma 1 a sus múltiplos`) y calcula su costo: `Σ N/d ≈ N·ln N`.

**Problema 14.3 — Último dígito no nulo de n!** · nivel 4

- **Entrada:** `n`, con `1 ≤ n ≤ 10^6`.
- **Salida:** el último dígito distinto de cero de `n!`.
- **Ejemplo:** `5` → `2` (120); `10` → `8` (3 628 800); `20` → `4`.
- **Matemática:** calcula `e_2` y `e_5` con Legendre; quita de cada factor `i` todos los 2 y 5, multiplica lo que queda módulo 10, y finalmente multiplica por `2^(e_2 − e_5)` módulo 10. Demuestra por qué `e_2 ≥ e_5` y por qué el resultado nunca termina en 0.

**Proyecto del día — Pruebas de estrés de la semana**

Un único programa que ejecuta tres comparaciones y escribe `OK` o el primer contraejemplo de cada una:

1. Último dígito no nulo: tu método rápido contra fuerza bruta con `__int128` para `n = 1..30` (`30! < 1,7·10^38`).
2. Goldbach: tu método con criba contra `esPrimo` (división de prueba) para todos los pares `4 ≤ n ≤ 2000`.
3. Ordenar por divisores: tu comparador contra un ordenamiento por selección `O(n^2)` en 2000 arreglos aleatorios de tamaño hasta 20 con valores hasta 500.

- **Qué reviso:** que la fuerza bruta no comparta código con la solución rápida, la semilla fija y el formato del contraejemplo.
- **Entrega:** `d14.cpp` y `d14_notas.md`.

---

## Semana 3 · 15–21 nov · Técnicas sobre arreglos: prefijos, diferencias, búsqueda binaria y dos punteros

**Objetivo:** resolver consultas de rango en `O(1)`, aplicar actualizaciones masivas, buscar en `O(log n)` y recorrer arreglos con ventanas en `O(n)`.

### Día 15 · domingo 15 de noviembre · Sumas prefijas

**Teoría desde cero.** Si te piden muchas veces la suma de un tramo `a[l..r]`, sumar cada vez cuesta `O(n)` por consulta. La idea: **precalcular una vez** las sumas acumuladas `p[i] = a[1] + … + a[i]` (con `p[0] = 0`). Después, cada consulta es una resta.

```cpp
vector<long long> a(n + 1), p(n + 1, 0);
for (int i = 1; i <= n; i++) { cin >> a[i]; p[i] = p[i - 1] + a[i]; }

// suma de a[l..r] en O(1):
long long s = p[r] - p[l - 1];
```

Usa índices desde 1 y `p[0] = 0`: así `l = 1` no necesita un caso especial. La técnica sirve para cualquier cosa "acumulable": también para contar, por ejemplo, cuántos elementos de un tramo cumplen una condición (suma prefija de un arreglo de unos y ceros).

**Matemática del día.**

- *Telescopía:* `p[r] − p[l−1] = (a_1 + … + a_r) − (a_1 + … + a_{l−1}) = a_l + … + a_r`.
- Un arreglo de `n` elementos tiene `n(n+1)/2` subarreglos contiguos.
- El subarreglo `a[i+1..j]` suma `K` si y solo si `p_j − p_i = K`. Esto convierte "contar subarreglos" en "contar parejas de prefijos con una diferencia dada", que se resuelve con un diccionario.

**Problema 15.1 — Consultas de suma** · nivel 2

- **Entrada:** `n q`; luego `n` enteros; luego `q` líneas `l r`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i| ≤ 10^9`, `1 ≤ l ≤ r ≤ n`.
- **Salida:** la suma de `a[l..r]` para cada consulta.
- **Ejemplo:** `5 2 / 1 2 3 4 5 / 1 3 / 2 5` → `6 / 14`.
- **Matemática:** demuestra la fórmula con telescopía y compara el costo: la solución ingenua hace hasta `q·n = 4·10^10` operaciones; la de prefijos, `n + q`.

**Problema 15.2 — Punto de equilibrio** · nivel 3

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** el menor índice `i` (desde 1) tal que `a_1 + … + a_{i−1} = a_{i+1} + … + a_n` (una suma vacía vale 0), o `-1` si no existe.
- **Ejemplo:** `6 / 1 7 3 6 5 6` → `4`; `3 / 1 2 3` → `-1`.
- **Matemática:** si `S` es la suma total y `L` la suma de la izquierda de `i`, la condición equivale a `2L + a_i = S`. Úsala para resolverlo en una sola pasada.

**Problema 15.3 — Subarreglos con suma K** · nivel 4

- **Entrada:** `n K` y luego `n` enteros, con `1 ≤ n ≤ 2·10^5`, `|a_i| ≤ 10^9` y `|K| ≤ 10^15`.
- **Salida:** cuántos subarreglos contiguos suman exactamente `K`.
- **Ejemplo:** `5 3 / 1 2 1 2 1` → `4`; `4 0 / 1 -1 1 -1` → `4`.
- **Matemática:** para cada `j`, cuenta cuántos prefijos anteriores valen `p_j − K` (con un `map<long long, int>`). Explica por qué hay que empezar con `p_0 = 0` ya contado una vez, por qué los negativos no rompen el método y por qué la respuesta puede llegar a `n(n+1)/2 ≈ 2·10^10` (necesitas `long long`).

**Proyecto del día — Panel de ventas**

Lee `n` ventas diarias y luego `q` comandos (`1 ≤ n, q ≤ 2·10^5`, `|v| ≤ 10^9`), cada uno respondido en `O(1)` tras un único preprocesamiento:

- `suma l r`: la suma de las ventas de los días `l..r`.
- `prom l r`: el promedio, con 2 decimales.
- `mejor k`: la ventana de `k` días consecutivos con mayor suma; imprime `inicio suma` (en empate, el inicio menor).
- `positivos l r`: cuántos días del tramo tuvieron ventas `> 0`.

Ejemplo: `5 4 / 3 -1 4 1 5 / suma 2 4 / prom 1 5 / mejor 2 / positivos 1 5` → `4 / 2.40 / 4 6 / 4`.

- **Qué reviso:** un solo cálculo de prefijos (también para `positivos`), `long long`, `fixed << setprecision(2)` y el desempate de `mejor`.
- **Entrega:** `d15.cpp` y `d15_notas.md`.

### Día 16 · lunes 16 de noviembre · Sumas prefijas en 2D

**Teoría desde cero.** La misma idea en una cuadrícula: `P[i][j]` es la suma de todas las celdas del rectángulo que va desde `(1,1)` hasta `(i,j)`.

```cpp
vector<vector<long long>> P(n + 1, vector<long long>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        P[i][j] = a[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];

// suma del rectángulo (x1,y1)-(x2,y2), con índices desde 1:
long long s = P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1];
```

**Matemática del día: inclusión–exclusión.** Si sumas `P[i-1][j]` y `P[i][j-1]`, la región `(1,1)–(i-1,j-1)` se cuenta dos veces; por eso se resta una vez. Para un rectángulo: toma el grande `(1,1)–(x2,y2)`, quita la franja de arriba y la franja de la izquierda, y devuelve la esquina que quitaste dos veces. Otra idea clave: **fijar dos filas y comprimir las columnas** convierte un problema 2D en uno 1D (por ejemplo, para aplicar Kadane del Día 8).

**Problema 16.1 — Consultas de rectángulos** · nivel 3

- **Entrada:** `n m q`; la matriz `n × m`; luego `q` líneas `x1 y1 x2 y2`. Límites: `1 ≤ n, m ≤ 1000`, `1 ≤ q ≤ 10^5`, `|a| ≤ 10^6`.
- **Salida:** la suma de cada rectángulo.
- **Ejemplo:** `3 3 2 / 1 2 3 / 4 5 6 / 7 8 9 / 1 1 2 2 / 2 2 3 3` → `12 / 28`.
- **Matemática:** deduce la fórmula del rectángulo con inclusión–exclusión y acota el valor máximo de una suma (`10^6 · 10^6 = 10^12`) para justificar `long long`.

**Problema 16.2 — Cuadrado de suma máxima** · nivel 3

- **Entrada:** `n m k` y la matriz. Límites: `1 ≤ n, m ≤ 1000`, `1 ≤ k ≤ min(n, m)`, `|a| ≤ 10^6`.
- **Salida:** `suma fila columna`, con la esquina superior izquierda del cuadrado `k × k` de mayor suma (en empate, menor fila y luego menor columna).
- **Ejemplo:** `3 3 2 / 1 2 3 / 4 5 6 / 7 8 9` → `28 2 2`.
- **Matemática:** hay `(n−k+1)(m−k+1)` cuadrados. Compara el costo de sumar cada uno celda por celda (`n·m·k²` en el peor caso) con el de prefijos 2D.

**Problema 16.3 — Submatriz de suma máxima** · nivel 5

- **Entrada:** `n m` y la matriz. Límites: `1 ≤ n, m ≤ 100`, `|a| ≤ 10^4`.
- **Salida:** la mayor suma de una submatriz rectangular no vacía.
- **Ejemplo:** `3 4 / 1 2 -1 -4 / -8 -3 4 2 / 3 8 10 -8` → `21` (la fila 3, columnas 1 a 3).
- **Matemática:** fija el par de filas `(r1, r2)` y define `c_j = Σ a[r][j]` para `r` entre `r1` y `r2`; la mejor submatriz con esas filas es el subarreglo máximo de `c` (Kadane). Hay `n(n+1)/2` pares de filas: demuestra que el costo es `O(n²·m)` y calcula cuántas operaciones son para `n = m = 100`.

**Proyecto del día — Editor de imágenes en grises**

Lee una imagen `n × m` de píxeles con valores 0 a 255 (`1 ≤ n, m ≤ 500`) y comandos hasta el fin de la entrada (máximo 100):

- `suma x1 y1 x2 y2`: suma de los píxeles del rectángulo.
- `prom x1 y1 x2 y2`: promedio con 2 decimales.
- `blur r` (`0 ≤ r ≤ 50`): imprime la imagen en la que cada píxel se reemplaza por el promedio **entero** (división entera) de los píxeles de su ventana `|x' − x| ≤ r`, `|y' − y| ≤ r`, recortada en los bordes.

Ejemplo: imagen `2 2 / 0 4 / 8 12` con `blur 1` → `6 6 / 6 6`.

- **Qué reviso:** prefijos 2D calculados una sola vez, recorte de ventanas con `min`/`max` y que `blur` cueste `O(n·m)`.
- **Entrega:** `d16.cpp` y `d16_notas.md`.

### Día 17 · martes 17 de noviembre · Arreglos de diferencias

**Teoría desde cero.** El problema inverso de los prefijos: tienes que sumar un valor `v` a **todo un tramo** `a[l..r]`, muchas veces, y leer el arreglo solo al final. Sumar elemento por elemento cuesta `O(n)` por actualización. Con un **arreglo de diferencias** `d` cada actualización es `O(1)`:

```cpp
vector<long long> d(n + 2, 0);
d[l] += v;                         // desde l, todo sube v
d[r + 1] -= v;                     // después de r, se cancela

// al final, reconstruye con suma prefija
long long cur = 0;
for (int i = 1; i <= n; i++) { cur += d[i]; a[i] += cur; }
```

En 2D, una actualización de rectángulo toca **cuatro esquinas**:

```cpp
d[x1][y1]         += v;
d[x1][y2 + 1]     -= v;
d[x2 + 1][y1]     -= v;
d[x2 + 1][y2 + 1] += v;           // luego, suma prefija 2D de d
```

**Matemática del día.** Si `d_i = a_i − a_{i−1}`, entonces `d_1 + … + d_i = a_i` (telescopía): *diferencias* y *prefijos* son operaciones inversas, como derivada e integral. Sumar `v` a `a[l..r]` solo cambia `d_l` (aumenta `v`) y `d_{r+1}` (disminuye `v`): fuera de ese tramo las diferencias entre vecinos no cambian.

**Problema 17.1 — Actualizaciones de rango** · nivel 2

- **Entrada:** `n q`; luego `n` enteros iniciales; luego `q` líneas `l r v`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v| ≤ 10^9`.
- **Salida:** el arreglo final, en una línea.
- **Ejemplo:** `5 2 / 0 0 0 0 0 / 1 3 2 / 2 5 3` → `2 5 5 3 3`.
- **Matemática:** demuestra que solo `d_l` y `d_{r+1}` cambian. Acota el mayor valor final posible (`10^9 + 2·10^5 · 10^9 ≈ 2·10^14`) para justificar `long long`.

**Problema 17.2 — Puntos muy cubiertos** · nivel 3

- **Entrada:** `n M K`; luego `n` líneas `l r`. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ M ≤ 10^6`, `1 ≤ l ≤ r ≤ M`, `1 ≤ K ≤ n`.
- **Salida:** cuántos puntos enteros de `1..M` están cubiertos por al menos `K` segmentos.
- **Ejemplo:** `3 10 2 / 1 5 / 3 8 / 4 10` → `6`.
- **Matemática:** la cobertura del punto `x` es `Σ [l_i ≤ x ≤ r_i]`. Cada segmento aporta `+1` en `l` y `−1` en `r+1` a la diferencia; demuestra que la suma prefija de esa diferencia es exactamente la cobertura.

**Problema 17.3 — Tablero con rectángulos** · nivel 4

- **Entrada:** `n m q`; luego `q` líneas `x1 y1 x2 y2 v`. El tablero empieza en ceros. Límites: `1 ≤ n, m ≤ 1000`, `1 ≤ q ≤ 10^5`, `|v| ≤ 10^4`.
- **Salida:** el tablero final, una fila por línea.
- **Ejemplo:** `3 3 2 / 1 1 2 2 1 / 2 2 3 3 2` → `1 1 0 / 1 3 2 / 0 2 2`.
- **Matemática:** demuestra con inclusión–exclusión que, tras la suma prefija 2D, cada celda dentro del rectángulo recibe `+v` exactamente una vez y cada celda fuera recibe `0`.

**Proyecto del día — Reservas de salas**

Un edificio tiene reservas de salas durante un día (`1440` minutos). Cada reserva ocupa `[s, e)`: incluye el minuto `s` y no incluye el `e`.

- **Entrada:** `n q`; luego `n` líneas `s e` (`0 ≤ s < e ≤ 1440`, `1 ≤ n ≤ 10^5`); luego `q` líneas con un minuto `t` (`0 ≤ t < 1440`, `1 ≤ q ≤ 10^5`).
- **Salida:** primera línea, el máximo de reservas simultáneas (las salas necesarias); segunda línea, cuántos minutos del día alcanzan ese máximo; luego, para cada consulta, cuántas reservas están activas en el minuto `t`.
- **Ejemplo:** `3 2 / 0 60 / 30 90 / 60 120 / 45 / 60` → `2 / 60 / 2 / 2`.
- **Qué reviso:** intervalos semiabiertos, costo `O(n + 1440 + q)` y arreglo con tamaño suficiente (`1442`).
- **Notas:** explica por qué "salas necesarias" es el máximo de la cobertura y por qué se usa `[s, e)`.
- **Entrega:** `d17.cpp` y `d17_notas.md`.

### Día 18 · miércoles 18 de noviembre · Búsqueda binaria

**Teoría desde cero.** Si un arreglo está **ordenado**, puedes buscar un valor descartando la mitad de las posibilidades en cada paso: `O(log n)` en vez de `O(n)`. Para `n = 2·10^5` son unos 18 pasos.

La forma más segura de escribirla es con un **invariante** y un intervalo `[lo, hi]`:

```cpp
// primera posición pos en [0, n] con a[pos] >= x   (n si no existe)
int lo = 0, hi = n;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;     // evita desbordar con lo + hi
    if (a[mid] >= x) hi = mid;        // la respuesta está en [lo, mid]
    else lo = mid + 1;                // la respuesta está en [mid + 1, hi]
}
// al salir, lo == hi es la respuesta
```

La STL ya lo trae: `lower_bound(a.begin(), a.end(), x) - a.begin()` es la primera posición con `a[pos] ≥ x`, y `upper_bound(...)` es la primera con `a[pos] > x`. La cantidad de veces que aparece `x` es la diferencia entre ambas.

**Matemática del día.**

- *Invariante:* durante todo el ciclo, todos los elementos con índice `< lo` son `< x` y todos los de índice `≥ hi` son `≥ x`. Al terminar `lo = hi`, así que `lo` es exactamente la primera posición con `a ≥ x`.
- *Terminación:* en cada vuelta `hi − lo` se reduce a la mitad, como máximo, así que hay a lo más `ceil(log2(n + 1))` vueltas.
- Los errores típicos son de "uno de más o de menos" (`mid`, `mid + 1`, `hi = n` o `n − 1`): fíjate siempre qué significa cada extremo.

**Problema 18.1 — Buscar en un arreglo ordenado** · nivel 2

- **Entrada:** `n q`; luego `n` enteros ordenados de forma no decreciente; luego `q` valores `x`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |x| ≤ 10^9`.
- **Salida:** para cada `x`, la posición (desde 1) de su primera aparición o `-1`.
- **Ejemplo:** `5 3 / 1 3 3 7 9 / 3 4 9` → `2 / -1 / 5`.
- **Matemática:** demuestra el invariante y calcula el máximo de iteraciones para `n = 2·10^5`.

**Problema 18.2 — Rangos de posición** · nivel 3

- **Entrada:** igual que el 18.1.
- **Salida:** para cada `x`, dos números: cuántos elementos son `< x` y cuántos son `≤ x`.
- **Ejemplo:** `5 4 / 1 3 3 7 9 / 3 8 0 10` → `1 3 / 4 4 / 0 0 / 5 5`.
- **Matemática:** el primer valor es `lower_bound` y el segundo, `upper_bound`; las ocurrencias de `x` son su diferencia. Demuestra que siempre `0 ≤ menores ≤ no_mayores ≤ n`.

**Problema 18.3 — Raíz entera** · nivel 4

- **Entrada:** `T` y luego `T` enteros `n`, con `1 ≤ T ≤ 10^5` y `0 ≤ n ≤ 10^18`.
- **Salida:** `floor(sqrt(n))` para cada `n`.
- **Ejemplo:** `3 / 16 17 1000000000000000000` → `4 / 4 / 1000000000`.
- **Matemática:** `x² ≤ n` es verdadero para `x = 0..r` y falso después, así que la raíz entera es el mayor `x` verdadero. Con límite superior `2·10^9` evitas desbordar (`(2·10^9)² = 4·10^18`). Explica por qué `sqrt()` con `double` puede fallar para `n` cercano a `10^18` (un `double` tiene unos 15–16 dígitos exactos).

**Proyecto del día — Autocompletado simple**

Programa que sugiere palabras a partir de un prefijo.

- **Entrada:** `n q`; luego `n` palabras distintas de minúsculas (longitud `≤ 20`); luego `q` prefijos. Límites: `1 ≤ n, q ≤ 10^5`.
- **Salida:** por cada prefijo, una línea con la cantidad de palabras que lo tienen y, en la misma línea, las primeras 3 en orden alfabético.
- **Ejemplo:** `5 3 / casa casco cosa perro pera / ca / p / z` → `2 casa casco / 2 pera perro / 0`.
- **Pista:** las palabras con prefijo `p` son exactamente las que están en el rango `[p, p + char(127))` del diccionario ordenado; dos `lower_bound` te dan su cantidad.
- **Qué reviso:** ordenar una sola vez, ninguna búsqueda lineal por consulta y el caso de cero resultados.
- **Entrega:** `d18.cpp` y `d18_notas.md`.

### Día 19 · jueves 19 de noviembre · Búsqueda binaria sobre la respuesta

**Teoría desde cero.** A veces no buscas en un arreglo, sino que buscas **el valor de la respuesta**. Si puedes escribir un predicado `good(x)` ("¿funciona con `x`?") que es *falso, falso, …, falso, verdadero, …, verdadero* (**monótono**), la búsqueda binaria encuentra el primer `x` verdadero con `O(log(rango) · costo de good)`.

```cpp
// menor x en [lo, hi] con good(x) verdadero (se asume good(hi) verdadero)
long long lo = 0, hi = 2000000000LL;
while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (good(mid)) hi = mid; else lo = mid + 1;
}

// mayor x en [lo, hi] con good(x) verdadero (se asume good(lo) verdadero)
while (lo < hi) {
    long long mid = lo + (hi - lo + 1) / 2;   // redondea hacia arriba para no ciclar
    if (good(mid)) lo = mid; else hi = mid - 1;
}
```

Receta: (1) escribe el predicado, (2) demuestra que es monótono, (3) elige cotas que contengan la respuesta, (4) decide si buscas el primer verdadero o el último.

**Matemática del día.** La monotonía se demuestra con un argumento de "si funciona con `x`, funciona con algo más fácil": por ejemplo, si con piezas de largo `ℓ` consigues `k` piezas, con piezas de largo `ℓ − 1` consigues al menos `k`. La complejidad total es `O(log(hi − lo) · costo(good))`.

**Problema 19.1 — Cortar cuerdas** · nivel 3

Tienes `n` cuerdas y quieres `k` pedazos del mismo largo entero `ℓ ≥ 1` (de la cuerda `i` salen `floor(L_i / ℓ)` pedazos). Halla el mayor `ℓ`; si ni con `ℓ = 1` alcanza, la respuesta es `0`.

- **Entrada:** `n k` y luego `n` largos. Límites: `1 ≤ n ≤ 10^5`, `1 ≤ k ≤ 10^9`, `1 ≤ L_i ≤ 10^9`.
- **Salida:** el mayor `ℓ`.
- **Ejemplo:** `3 5 / 8 7 9` → `4`.
- **Matemática:** `good(ℓ) = (Σ floor(L_i/ℓ) ≥ k)`. Demuestra que es monótono (`floor(L/(ℓ−1)) ≥ floor(L/ℓ)`) y acota la suma (`≤ 10^5 · 10^9 = 10^14`).

**Problema 19.2 — Colocar antenas** · nivel 4

- **Entrada:** `n k` y luego `n` posiciones distintas. Límites: `2 ≤ k ≤ n ≤ 10^5`, `1 ≤ x_i ≤ 10^9`.
- **Salida:** la mayor distancia mínima posible entre dos antenas al colocar `k` de ellas en posiciones de la lista.
- **Ejemplo:** `5 3 / 1 2 8 4 9` → `3`.
- **Matemática:** para una distancia `d`, el voraz "ordena y coloca la siguiente antena en la primera posición a distancia `≥ d` de la última" coloca el máximo posible de antenas; demuéstralo con un argumento de intercambio. Entonces `good(d) = (antenas colocables ≥ k)` es monótono.

**Problema 19.3 — Dividir el arreglo** · nivel 5

Divide el arreglo en exactamente `k` partes contiguas no vacías de modo que la mayor suma de una parte sea lo más pequeña posible.

- **Entrada:** `n k` y luego `n` enteros positivos. Límites: `1 ≤ k ≤ n ≤ 10^5`, `1 ≤ a_i ≤ 10^9`.
- **Salida:** esa menor suma máxima.
- **Ejemplo:** `5 2 / 7 2 5 10 8` → `18` (partes `7 2 5` y `10 8`).
- **Matemática:** `max(a_i) ≤ respuesta ≤ Σ a_i`. Para un `S` dado, el voraz "cierra la parte cuando el siguiente elemento ya no cabe" usa el mínimo número de partes; demuéstralo. Como `k ≤ n`, si el voraz usa `c ≤ k` partes se pueden partir más sin aumentar el máximo, así que `good(S) = (partes ≤ k)`. Costo `O(n · log(Σ a_i))`.

**Proyecto del día — Biblioteca de búsqueda binaria**

Escribe dos plantillas de función sobre `long long` y úsalas para resolver los tres problemas de hoy:

- `primero_verdadero(lo, hi, pred)`: menor `x` en `[lo, hi]` con `pred(x)` verdadero, o `hi + 1` si no hay.
- `ultimo_verdadero(lo, hi, pred)`: mayor `x` en `[lo, hi]` con `pred(x)` verdadero, o `lo − 1` si no hay.

El `main` lee primero un número `1`, `2` o `3` (el problema de hoy que debe resolver) y después la entrada de ese problema. Ejemplo: `1 / 3 5 / 8 7 9` → `4`.

- **Qué reviso:** al menos 10 `assert` de bordes (todo falso, todo verdadero, un solo elemento, rango de un punto, extremos `0` y `10^18`), cálculo de `mid` sin desbordar y comentarios que declaren las precondiciones (monotonía).
- **Entrega:** `d19.cpp` y `d19_notas.md`.

### Día 20 · viernes 20 de noviembre · Dos punteros y ventana deslizante

**Teoría desde cero.** **Dos punteros** son dos índices que recorren el arreglo, siempre en la misma dirección, de modo que cada uno se mueve a lo sumo `n` veces: el total es `O(n)` aunque haya un `while` dentro de un `for` (*análisis amortizado*).

- **Arreglo ordenado:** un puntero al inicio y otro al final; según la suma, avanzas uno u otro.
- **Ventana deslizante:** una ventana `[l, r]` que crece por la derecha y se achica por la izquierda mientras cumple una condición.

```cpp
// longitud mínima de un subarreglo con suma >= S (todos los a[i] son positivos)
int l = 0, best = INT_MAX;
long long sum = 0;
for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum - a[l] >= S) sum -= a[l++];   // achica mientras siga cumpliendo
    if (sum >= S) best = min(best, r - l + 1);
}
```

**Matemática del día.** *Corrección de la pareja con suma objetivo:* en un arreglo ordenado con `l` a la izquierda y `r` a la derecha, si `a_l + a_r < K` entonces `a_l` no puede formar pareja con ningún elemento a la izquierda de `r` (todos son `≤ a_r`), así que se descarta `l`; si `> K`, se descarta `r`. Nunca se pierde un par válido. *Amortización:* `l` y `r` solo avanzan, así que hay a lo más `2n` movimientos.

**Problema 20.1 — Pareja con suma objetivo** · nivel 3

- **Entrada:** `n K` y luego `n` enteros **ordenados** de menor a mayor (puede haber repetidos). Límites: `2 ≤ n ≤ 2·10^5`, `|a_i|, |K| ≤ 10^9`.
- **Salida:** los valores `x y` con `x ≤ y` y `x + y = K` tomados de dos posiciones distintas, con el `x` más pequeño posible; o `-1` si no existe.
- **Ejemplo:** `5 9 / 1 3 4 5 7` → `4 5`; `4 6 / 1 3 3 5` → `1 5`.
- **Matemática:** demuestra que ningún par válido se descarta y que el primer par encontrado tiene el `x` mínimo.

**Problema 20.2 — Subarreglo más corto** · nivel 4

- **Entrada:** `n S` y luego `n` enteros positivos. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ a_i ≤ 10^9`, `1 ≤ S ≤ 10^15`.
- **Salida:** la menor longitud de un subarreglo contiguo con suma `≥ S`, o `0` si no existe.
- **Ejemplo:** `6 15 / 5 1 3 5 10 7` → `2` (5 + 10).
- **Matemática:** como todos son positivos, agrandar la ventana siempre aumenta la suma y achicarla siempre la disminuye; por eso `l` y `r` nunca retroceden. Demuestra el costo amortizado y explica por qué la técnica falla si hay números negativos (usa prefijos en ese caso).

**Problema 20.3 — Subcadena con pocos distintos** · nivel 4

- **Entrada:** `k` en la primera línea y una cadena `s` de minúsculas en la segunda. Límites: `1 ≤ k ≤ 26`, `1 ≤ |s| ≤ 2·10^5`.
- **Salida:** la mayor longitud de una subcadena contigua con a lo más `k` letras distintas.
- **Ejemplo:** `2 / eceba` → `3`; `1 / aaabb` → `3`.
- **Matemática:** si una ventana es válida, toda subventana también lo es (monotonía). Mantén `cnt[26]` y la cantidad de letras distintas en la ventana; demuestra que el costo total es `O(n)`.

**Proyecto del día — Analizador de registros**

Un servidor guarda eventos `E` (error) y `O` (correcto).

- **Entrada:** `n K`; luego `n` líneas `t tipo`, con `t` estrictamente creciente. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ K ≤ n`, `1 ≤ t ≤ 10^9`.
- **Salida:** dos números: (1) `longitud`: la mayor cantidad de eventos consecutivos de la lista con a lo más `K` errores; (2) `racha`: la menor diferencia `t_final − t_inicial` entre bloques consecutivos de `K` errores (usando las marcas de tiempo de esos errores), o `-1` si hay menos de `K` errores.
- **Ejemplo:** `6 2 / 1 O / 2 E / 4 E / 7 O / 8 E / 9 E` → `4 1`.
- **Qué reviso:** ventanas deslizantes `O(n)`, sin bucles anidados innecesarios y el caso con menos de `K` errores.
- **Notas:** demuestra por qué, para la racha mínima, basta mirar `K` errores consecutivos de la lista de errores.
- **Entrega:** `d20.cpp` y `d20_notas.md`.

### Día 21 · sábado 21 de noviembre · Repaso de la semana 3 y pruebas de estrés

**Teoría: ¿qué técnica uso?** Antes de programar, clasifica el problema:

- Muchas consultas de suma en un tramo y el arreglo no cambia: **prefijos** (1D o 2D).
- Muchas actualizaciones de tramos y se lee al final: **arreglo de diferencias**.
- Arreglo ordenado y buscas un valor o una cota: **búsqueda binaria**.
- "El mayor/menor valor tal que se pueda…" con un chequeo monótono: **búsqueda binaria sobre la respuesta**.
- Tramos contiguos con números positivos o con una condición que se rompe al agrandar: **ventana deslizante**.
- Parejas con suma dada en un arreglo ordenado: **dos punteros**; en uno sin ordenar: **diccionario** o ordenar primero.

**Problema 21.1 — Longitud mínima L** · nivel 3

- **Entrada:** `n L` y luego `n` enteros. Límites: `1 ≤ L ≤ n ≤ 2·10^5`, `|a_i| ≤ 10^9`.
- **Salida:** la mayor suma de un subarreglo contiguo de longitud al menos `L`.
- **Ejemplo:** `5 2 / 1 -5 3 -1 4` → `6` (3 − 1 + 4).
- **Matemática:** la suma de `a[i+1..j]` es `p_j − p_i`; para cada `j ≥ L` quieres el `i ≤ j − L` con `p_i` mínimo. Demuestra que ese mínimo se puede mantener con una variable porque el conjunto de candidatos solo crece.

**Problema 21.2 — Parejas en un intervalo** · nivel 4

- **Entrada:** `n L R` y luego `n` enteros. Límites: `2 ≤ n ≤ 2·10^5`, `|a_i| ≤ 10^9`, `−2·10^9 ≤ L ≤ R ≤ 2·10^9`.
- **Salida:** cuántas parejas `i < j` cumplen `L ≤ a_i + a_j ≤ R`.
- **Ejemplo:** `4 3 5 / 1 2 3 4` → `4`.
- **Matemática:** sea `F(X)` la cantidad de parejas con suma `≤ X`; la respuesta es `F(R) − F(L − 1)`. Calcula `F` con dos punteros sobre el arreglo ordenado y justifica por qué ordenar no cambia la cantidad de parejas `{i, j}`.

**Problema 21.3 — Tripletas de suma cero** · nivel 5

- **Entrada:** `n` y luego `n` enteros. Límites: `3 ≤ n ≤ 3000`, `|a_i| ≤ 10^6`.
- **Salida:** cuántas tripletas de **valores** `(x ≤ y ≤ z)` con `x + y + z = 0` se pueden formar con tres posiciones distintas. Dos tripletas son iguales si tienen los mismos valores.
- **Ejemplo:** `6 / -1 0 1 2 -1 -4` → `2`; `4 / 0 0 0 0` → `1`.
- **Matemática:** ordena, fija `x = a_i` (saltando valores repetidos de `x`) y busca `y + z = −x` con dos punteros en `i+1..n−1`, saltando `y` y `z` repetidos tras cada hallazgo. Justifica el costo `O(n²)` y que así no cuentas tripletas duplicadas.

**Proyecto del día — Pruebas de estrés de la semana**

Un único programa con dos comparaciones, cada una con 5000 pruebas aleatorias y semilla fija:

1. Tripletas de suma cero: fuerza bruta `O(n³)` (todas las tripletas de posiciones, guardando las tripletas de valores ordenadas en un `set`) contra tu solución de dos punteros, con `n ≤ 12` y valores en `[−5, 5]`.
2. Parejas en un intervalo: fuerza bruta `O(n²)` contra la solución ordenada con dos punteros, con `n ≤ 15`, valores en `[−10, 10]` y `L ≤ R` aleatorios en `[−20, 20]`.

Escribe `OK` por comparación, o el primer contraejemplo (arreglo, `L`, `R` y las dos respuestas).

- **Qué reviso:** que la fuerza bruta sea independiente, la semilla fija y el formato del contraejemplo.
- **Notas:** una tabla de una línea por técnica de la semana: cuándo se usa y qué complejidad tiene.
- **Entrega:** `d21.cpp` y `d21_notas.md`.

---

## Semana 4 · 22–28 nov · Pilas, colas, backtracking, bits y combinatoria

**Objetivo:** dominar las estructuras lineales de la STL, explorar todas las posibilidades con recursión, manejar conjuntos como números binarios y contar con aritmética modular.

### Día 22 · domingo 22 de noviembre · Pilas, colas y pila monótona

**Teoría desde cero.** Una **pila** (`stack`) funciona "último en entrar, primero en salir" (LIFO): como una pila de platos. Una **cola** (`queue`) es "primero en entrar, primero en salir" (FIFO): como la fila de un banco. Todas sus operaciones cuestan `O(1)`.

```cpp
stack<int> st;
st.push(5);                 // apila
int arriba = st.top();      // mira el de arriba
st.pop();                   // desapila
bool vacia = st.empty();    // siempre revisa antes de top() o pop()

queue<int> q;
q.push(3); int frente = q.front(); q.pop();
```

**Uso clásico: paréntesis.** Cada vez que aparece un cierre, debe coincidir con el último apertura que sigue abierta:

```cpp
stack<char> st;
for (char c : s) {
    if (c == '(' || c == '[' || c == '{') st.push(c);
    else {
        if (st.empty()) { /* sobra un cierre: NO */ }
        char t = st.top(); st.pop();
        /* comprueba que t y c sean del mismo tipo */
    }
}
```

**Pila monótona: siguiente mayor.** Para cada elemento, el primer elemento mayor a su derecha. Guarda en la pila los índices cuyo "siguiente mayor" aún no se encontró; sus valores quedan en orden decreciente.

```cpp
vector<int> res(n, -1);
stack<int> st;                           // índices con valores decrecientes
for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
        res[st.top()] = a[i];            // a[i] es el siguiente mayor de ese elemento
        st.pop();
    }
    st.push(i);
}
```

**Matemática del día.** *Amortización:* cada índice se apila una vez y se desapila a lo sumo una vez, así que el `while` interno suma `O(n)` en total aunque parezca anidado. *Paréntesis de un solo tipo:* una secuencia es válida si y solo si el "saldo" (abiertos menos cerrados) nunca baja de 0 y termina en 0. Con varios tipos, un contador no basta: `([)]` tiene el saldo correcto y sin embargo es inválida.

**Problema 22.1 — Paréntesis balanceados** · nivel 2

- **Entrada:** una cadena de los caracteres `()[]{}`, con `1 ≤ |s| ≤ 10^5`.
- **Salida:** `SI` si está bien balanceada; si no, `NO`.
- **Ejemplo:** `([]{})` → `SI`; `([)]` → `NO`.
- **Matemática:** demuestra el criterio del saldo para un solo tipo de paréntesis y construye un contraejemplo que muestre por qué un contador no alcanza con tres tipos.

**Problema 22.2 — Siguiente elemento mayor** · nivel 4

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 2·10^5` y `1 ≤ a_i ≤ 10^9`.
- **Salida:** para cada `i`, el valor del primer elemento a su derecha que sea estrictamente mayor que `a_i`, o `-1`.
- **Ejemplo:** `5 / 2 1 5 3 4` → `5 5 -1 4 -1`.
- **Matemática:** demuestra que los valores de la pila siempre quedan en orden no creciente y que el costo total es `O(n)`.

**Problema 22.3 — Evaluar una expresión** · nivel 5

- **Entrada:** una línea con una expresión de enteros no negativos, con `+`, `-`, `*`, paréntesis y espacios (sin signo unario). Longitud `≤ 10^5`; todo valor intermedio cabe en `long long`.
- **Salida:** el valor de la expresión.
- **Ejemplo:** `2 + 3 * (4 - 1)` → `11`; `(1+2)*(3+4)-5` → `16`.
- **Matemática:** la gramática `expr = término (('+'|'-') término)*`, `término = factor ('*' factor)*`, `factor = número | '(' expr ')'` codifica la precedencia. Explica por qué `*` se evalúa antes que `+` y por qué `a - b - c` se evalúa de izquierda a derecha. Puedes implementarla con recursión (una función por regla) o con dos pilas.

**Proyecto del día — Calculadora con memoria**

Intérprete que lee líneas hasta el fin de la entrada:

- `let x = expr`: guarda el valor de `expr` en la variable `x` (nombres de letras minúsculas). No imprime nada.
- `print expr`: imprime el valor de `expr`.

Las expresiones usan números, variables, `+ - * /` y paréntesis. La división trunca hacia cero; dividir entre cero o usar una variable no definida imprime `ERROR`.

```
let a = 5
let b = a * 3 + 1
print b - 2
print (a + b) / 4
print a / 0
```

La salida de ese ejemplo es `14 / 5 / ERROR`.

- **Qué reviso:** el evaluador del Problema 22.3 reutilizado, el manejo de errores sin que el programa se caiga y una estructura clara (analizador léxico, evaluador, ciclo principal).
- **Entrega:** `d22.cpp` y `d22_notas.md`.

### Día 23 · lunes 23 de noviembre · Colas de prioridad y deque

**Teoría desde cero.** Una **cola de prioridad** (`priority_queue`) siempre te da el elemento más grande (o el más pequeño) en `O(1)`, y agregar o quitar cuesta `O(log n)`.

```cpp
priority_queue<int> mx;                                  // el máximo arriba
priority_queue<int, vector<int>, greater<int>> mn;       // el mínimo arriba
mn.push(5); mn.push(2);
int m = mn.top();        // 2
mn.pop();
```

Un **deque** (`deque`) es una cola con dos extremos: puedes agregar y quitar por el frente y por el final en `O(1)`.

**Deque monótono: máximo de una ventana deslizante.** Guarda índices cuyos valores van en orden decreciente; el frente es siempre el máximo de la ventana actual.

```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();   // los menores ya no servirán
    dq.push_back(i);
    if (dq.front() <= i - k) dq.pop_front();                      // salió de la ventana
    if (i >= k - 1) cout << a[dq.front()] << " ";
}
```

**Matemática del día.** *Heap de tamaño `k`:* para tener siempre el `k`-ésimo mayor de un flujo, guarda en un min-heap los `k` mayores vistos; su tope es el `k`-ésimo mayor. *Voraz y argumento de intercambio:* para unir cuerdas con costo igual a la suma de sus largos, conviene unir siempre las dos más cortas; el costo total es `Σ L_i · profundidad_i` en el árbol de uniones y las hojas más profundas deben ser las más cortas (si no, intercambiarlas reduce el costo).

**Problema 23.1 — K-ésimo mayor en línea** · nivel 3

- **Entrada:** `n k` y luego `n` enteros, con `1 ≤ k ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** después de leer cada elemento, el `k`-ésimo mayor de los leídos hasta ahora, o `-1` si aún hay menos de `k` elementos (una línea con `n` valores).
- **Ejemplo:** `6 3 / 4 9 1 7 3 8` → `-1 -1 1 4 4 7`.
- **Matemática:** demuestra el invariante: el min-heap contiene siempre los `k` mayores del prefijo. Costo `O(n log k)`.

**Problema 23.2 — Máximo en ventanas** · nivel 4

- **Entrada:** `n k` y luego `n` enteros, con `1 ≤ k ≤ n ≤ 10^6` y `|a_i| ≤ 10^9`.
- **Salida:** el máximo de cada ventana de `k` elementos consecutivos (`n − k + 1` valores).
- **Ejemplo:** `8 3 / 2 7 1 4 4 9 3 5` → `7 7 4 9 9 9`.
- **Matemática:** demuestra que los valores del deque son decrecientes, que el frente es el máximo y que cada índice entra y sale una sola vez (costo `O(n)`).

**Problema 23.3 — Unir cuerdas** · nivel 5

Unir dos cuerdas de largos `x` e `y` cuesta `x + y`. Une todas las cuerdas en una sola con el menor costo total.

- **Entrada:** `n` y luego `n` largos, con `1 ≤ n ≤ 10^5` y `1 ≤ L_i ≤ 10^9`.
- **Salida:** el costo mínimo.
- **Ejemplo:** `4 / 4 3 2 6` → `29` (2+3=5, luego 4+5=9, luego 9+6=15; 5 + 9 + 15 = 29).
- **Matemática:** demuestra que existe una solución óptima donde las dos cuerdas más cortas se unen primero (intercambio) y acota la respuesta para justificar `long long`.

**Proyecto del día — Planificador de tareas**

Un procesador ejecuta tareas **sin interrupciones**. Cuando queda libre, elige entre las tareas ya llegadas la de menor duración (empate: menor hora de llegada; luego, menor `id`). Si no hay tareas llegadas, espera a la siguiente.

- **Entrada:** `n` y luego `n` líneas `id llegada duracion`, con `1 ≤ n ≤ 10^5` y tiempos hasta `10^9`.
- **Salida:** primera línea, los `id` en el orden de ejecución; segunda línea, el tiempo de espera promedio (inicio − llegada) con 2 decimales.
- **Ejemplo:** `4 / 1 0 7 / 2 2 4 / 3 4 1 / 4 5 4` → `1 3 2 4 / 4.00`.
- **Qué reviso:** ordenar por llegada, un `priority_queue` con comparador `(duración, llegada, id)`, saltos de tiempo y `long long`.
- **Notas:** explica por qué esta política minimiza el tiempo de espera promedio entre las que no interrumpen (argumento de intercambio).
- **Entrega:** `d23.cpp` y `d23_notas.md`.

### Día 24 · martes 24 de noviembre · Recursión y backtracking

**Teoría desde cero.** El **backtracking** (vuelta atrás) construye una solución paso a paso: *elige* una opción, *explora* recursivamente, y *deshace* la elección para probar la siguiente. Así recorres todas las posibilidades.

```cpp
vector<int> actual;
void subconjuntos(int i, int n) {
    if (i == n) { /* aquí 'actual' es un subconjunto completo */ return; }
    subconjuntos(i + 1, n);              // opción 1: no tomo i
    actual.push_back(i);                 // opción 2: tomo i
    subconjuntos(i + 1, n);
    actual.pop_back();                   // deshago la elección
}
```

- **Poda:** si en algún punto ya es imposible llegar a una solución (la suma ya se pasó, una reina ya está atacada), corta esa rama sin explorarla.
- **Costo:** subconjuntos `2^n`, permutaciones `n!`; por eso sirve solo con `n` pequeño (hasta unos 20 y 10 respectivamente).

**Matemática del día.** El árbol de recursión de los subconjuntos tiene `2^(n+1) − 1` nodos. Hay `C(n, k)` subconjuntos de tamaño `k`. En el problema de las `n` reinas hay que fijar una reina por fila; dos reinas comparten diagonal si `fila − columna` o `fila + columna` coinciden. Conteos conocidos de soluciones para `n = 1, 2, …, 8`: `1, 0, 0, 2, 10, 4, 40, 92`.

**Problema 24.1 — Combinaciones** · nivel 3

- **Entrada:** `n k`, con `1 ≤ k ≤ n ≤ 15`.
- **Salida:** todos los subconjuntos de tamaño `k` de `{1, …, n}`, uno por línea, con sus elementos en orden creciente y las líneas en orden lexicográfico.
- **Ejemplo:** `4 2` → `1 2 / 1 3 / 1 4 / 2 3 / 2 4 / 3 4`.
- **Matemática:** deduce que hay `C(n, k)` líneas y calcula el máximo (`C(15, 7) = 6435`). Justifica por qué decidir "tomo o no tomo" en orden produce el orden lexicográfico (o cómo lograrlo).

**Problema 24.2 — Subconjuntos con suma exacta** · nivel 4

- **Entrada:** `n S` y luego `n` enteros positivos, con `1 ≤ n ≤ 20`, `1 ≤ a_i ≤ 10^9` y `1 ≤ S ≤ 10^10`.
- **Salida:** cuántos subconjuntos de **posiciones** suman exactamente `S`.
- **Ejemplo:** `5 10 / 2 3 5 7 8` → `3` (`{2,8}`, `{3,7}`, `{2,3,5}`).
- **Matemática:** hay `2^n` subconjuntos; para `n = 20` son unos `10^6`. Con los valores ordenados de mayor a menor y la suma restante de los elementos que faltan, ¿cuándo puedes podar una rama con seguridad?

**Problema 24.3 — N reinas** · nivel 5

- **Entrada:** `n`, con `1 ≤ n ≤ 13`.
- **Salida:** cuántas formas hay de colocar `n` reinas en un tablero `n × n` sin que se ataquen.
- **Ejemplo:** `6` → `4`; `8` → `92`.
- **Matemática:** demuestra que dos celdas están en la misma diagonal descendente si y solo si `f1 − c1 = f2 − c2` (y en la ascendente si `f1 + c1 = f2 + c2`). Verifica que tu programa reproduce `1, 0, 0, 2, 10, 4, 40, 92` para `n = 1..8`. Marca columnas y diagonales ocupadas con arreglos de booleanos o con máscaras de bits.

**Proyecto del día — Resolutor de Sudoku**

- **Entrada:** 9 líneas de 9 caracteres (`0` = casilla vacía, `1`–`9` = dado). El puzzle tiene a lo más una solución.
- **Salida:** las 9 líneas del tablero resuelto, o `SIN SOLUCION`.
- **Qué reviso:** backtracking con control de filas, columnas y cajas (idealmente con máscaras de bits), y poda: elegir la casilla vacía con menos candidatos reduce muchísimo el árbol.
- **Notas:** prueba con al menos tres puzzles (uno fácil, uno difícil con pocas pistas y uno sin solución) y registra cuántas llamadas recursivas hizo cada uno.
- **Entrega:** `d24.cpp` y `d24_notas.md`.

### Día 25 · miércoles 25 de noviembre · Bits y máscaras

**Teoría desde cero.** Los números se guardan en **binario**. `13 = 1101` porque `8 + 4 + 1`. Los operadores bit a bit actúan sobre cada posición:

| Operación | Significado | Ejemplo |
|---|---|---|
| `a & b` | 1 si ambos son 1 | `1100 & 1010 = 1000` |
| `a \| b` | 1 si alguno es 1 | `1100 \| 1010 = 1110` |
| `a ^ b` | 1 si son distintos (XOR) | `1100 ^ 1010 = 0110` |
| `a << k` | multiplica por `2^k` | `3 << 2 = 12` |
| `a >> k` | divide entre `2^k` (entero) | `13 >> 1 = 6` |

```cpp
(m >> i) & 1                // ¿el bit i está encendido?
m | (1 << i)                // enciende el bit i
m & ~(1 << i)               // apaga el bit i
m ^ (1 << i)                // invierte el bit i
x & (x - 1)                 // apaga el bit encendido más bajo
x & -x                      // aísla el bit encendido más bajo
__builtin_popcount(x)       // cuenta bits encendidos (popcountll para long long)
1LL << i                    // para i >= 31 usa siempre 1LL, o desbordarás
```

**Conjuntos como máscaras.** Un subconjunto de `{0, …, n−1}` se guarda como un entero: el bit `i` indica si `i` pertenece. Todos los subconjuntos se recorren con `for (int m = 0; m < (1 << n); m++)`.

**Matemática del día.**

- *Propiedades del XOR:* `a ^ a = 0`, `a ^ 0 = a`, es conmutativo y asociativo. XOR es la suma módulo 2 de cada bit, sin acarreo.
- *Subconjuntos:* hay `2^n` (cada elemento está o no está). Recorrer los subconjuntos de cada subconjunto cuesta `3^n` en total (cada elemento: fuera del grande, dentro del grande pero fuera del chico, o en ambos).
- *Código Gray:* `g(i) = i ^ (i >> 1)` recorre todos los números con un solo bit distinto entre vecinos.

**Problema 25.1 — Datos de un número en binario** · nivel 2

- **Entrada:** `n`, con `1 ≤ n ≤ 10^18`.
- **Salida:** `bits_encendidos es_potencia_de_2 largo_en_binario`, donde `es_potencia_de_2` es `SI` o `NO`.
- **Ejemplo:** `40` → `2 NO 6` (101000); `64` → `1 SI 7`.
- **Matemática:** demuestra que `x & (x − 1)` apaga el bit encendido más bajo y deduce que `x` es potencia de 2 si y solo si `x > 0` y `x & (x − 1) = 0`.

**Problema 25.2 — El único sin pareja** · nivel 3

- **Entrada:** `n` y luego `n` enteros, con `n` impar, `1 ≤ n ≤ 10^6` y `1 ≤ a_i ≤ 10^9`. Todos los valores aparecen exactamente dos veces, salvo uno que aparece una vez.
- **Salida:** ese valor.
- **Ejemplo:** `7 / 4 1 2 1 2 9 4` → `9`.
- **Matemática:** demuestra con las propiedades del XOR que el XOR de todo el arreglo es el valor único. *Bonus (no se entrega):* si hubiera dos valores únicos `x` e `y`, el bit más bajo de `x ^ y` los separa en dos grupos; ¿cómo lo usarías?

**Problema 25.3 — Subconjuntos con suma divisible** · nivel 4

- **Entrada:** `n m` y luego `n` enteros, con `1 ≤ n ≤ 20`, `1 ≤ m ≤ 10^9` y `1 ≤ a_i ≤ 10^9`.
- **Salida:** cuántos subconjuntos **no vacíos** de posiciones tienen una suma divisible entre `m`.
- **Ejemplo:** `4 3 / 1 2 3 4` → `5` (`{3}`, `{1,2}`, `{2,4}`, `{1,2,3}`, `{2,3,4}`).
- **Matemática:** demuestra que la correspondencia máscara → subconjunto es una biyección entre `0..2^n − 1` y los subconjuntos, y calcula el costo `2^n · n` para `n = 20`.

**Proyecto del día — Conjuntos con máscaras**

Implementa una `struct Conjunto` sobre `unsigned long long` que represente un subconjunto de `{0, …, 63}`, con: `agregar`, `quitar`, `contiene`, `tamano`, `unir`, `intersectar`, `restar`, `complemento` y `elementos` (en orden creciente, recorriendo bits con `x & -x`). Luego un intérprete con ocho conjuntos `A` a `H` (inicialmente vacíos) y estos comandos hasta el fin de la entrada:

- `add X i`, `del X i`: agrega o quita `i` del conjunto `X`.
- `union Z X Y`, `inter Z X Y`, `diff Z X Y`: guarda en `Z` el resultado.
- `comp Z X`: guarda en `Z` el complemento de `X` dentro de `{0..63}`.
- `show X`: imprime `tamaño: elementos` (para el vacío, `0:`).

Ejemplo: `add A 1 / add A 5 / add B 5 / add B 9 / union C A B / show C / inter D A B / show D` → `3: 1 5 9 / 1: 5`.

- **Qué reviso:** `1ULL << i` (no `1 << i`), `__builtin_popcountll`, ninguna operación con ciclos de 64 vueltas donde baste una operación de máscara.
- **Entrega:** `d25.cpp` y `d25_notas.md`.

### Día 26 · jueves 26 de noviembre · Combinatoria y coeficientes binomiales

**Teoría desde cero.**

- **Principio del producto:** si haces una cosa de `a` maneras y otra de `b`, ambas se hacen de `a·b` maneras.
- **Permutaciones:** ordenar `n` objetos distintos: `n!`. Ordenar `k` de `n`: `P(n, k) = n!/(n−k)!`.
- **Combinaciones:** elegir `k` de `n` sin importar el orden: `C(n, k) = n! / (k!·(n−k)!)`.
- **Identidad de Pascal:** `C(n, k) = C(n−1, k−1) + C(n−1, k)` (el objeto `n` está en el grupo o no).
- **Estrellas y barras:** las soluciones enteras no negativas de `x_1 + … + x_k = n` son `C(n + k − 1, k − 1)` (ordena `n` estrellas y `k − 1` barras).

**Cómo calcular `C(n, k)` módulo `p = 10^9 + 7`.**

1. Con la identidad de Pascal construyes una tabla en `O(n²)`: sirve hasta `n ≈ 2000`.
2. Para `n` grande, precalculas factoriales y dividir se convierte en multiplicar por un **inverso modular**. Si `p` es primo y `p` no divide a `a`, el **pequeño teorema de Fermat** dice `a^(p−1) ≡ 1 (mod p)`, así que `a^(p−2)` es el inverso de `a`.

```cpp
const long long MOD = 1'000'000'007;
vector<long long> fact(N + 1), inv_fact(N + 1);
fact[0] = 1;
for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
inv_fact[N] = potencia(fact[N], MOD - 2, MOD);          // potencia() del Día 12
for (int i = N; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;

auto C = [&](int n, int k) -> long long {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
};
```

**Matemática del día.** *Por qué funciona Fermat:* los números `a·1, a·2, …, a·(p−1)` son una reordenación de `1, 2, …, p−1` módulo `p`, así que `a^(p−1)·(p−1)! ≡ (p−1)! (mod p)`; como `(p−1)!` es coprimo con `p`, se cancela y queda `a^(p−1) ≡ 1`. *Por qué sirve `inv_fact[i−1] = inv_fact[i]·i`:* porque `1/(i−1)! = i/i!`.

**Problema 26.1 — Triángulo de Pascal** · nivel 3

- **Entrada:** `T` y luego `T` líneas `n k`, con `1 ≤ T ≤ 10^5` y `0 ≤ n, k ≤ 2000`.
- **Salida:** `C(n, k) mod 10^9 + 7` para cada línea (`0` si `k > n`).
- **Ejemplo:** `3 / 5 2 / 10 5 / 6 7` → `10 / 252 / 0`.
- **Matemática:** demuestra la identidad de Pascal con el argumento combinatorio (el objeto `n` está o no en el grupo) y comprueba que `Σ C(n, k) = 2^n`.

**Problema 26.2 — Binomiales rápidos** · nivel 4

- **Entrada:** `T` y luego `T` líneas `n k`, con `1 ≤ T ≤ 2·10^5` y `0 ≤ n, k ≤ 10^6`.
- **Salida:** `C(n, k) mod 10^9 + 7`.
- **Ejemplo:** `3 / 10 3 / 20 10 / 1000000 0` → `120 / 184756 / 1`.
- **Matemática:** demuestra que `a^(p−2)` es el inverso de `a` módulo `p`, y que el cálculo de `inv_fact` hacia atrás es correcto. Explica por qué el truco falla si el módulo no es primo.

**Problema 26.3 — Estrellas y barras con mínimos** · nivel 5

- **Entrada:** `n k` y luego `k` enteros `a_i`, con `0 ≤ n ≤ 10^6`, `1 ≤ k ≤ 10^6` y `0 ≤ a_i ≤ 10^6`.
- **Salida:** cuántas soluciones enteras tiene `x_1 + … + x_k = n` con `x_i ≥ a_i`, módulo `10^9 + 7`.
- **Ejemplo:** `5 3 / 0 0 0` → `21`; `5 3 / 1 1 1` → `6`.
- **Matemática:** con `y_i = x_i − a_i ≥ 0` la ecuación queda `Σ y_i = n − Σ a_i`; si esto es negativo no hay soluciones; si no, son `C(n − Σ a_i + k − 1, k − 1)`. Acota el índice superior (`≤ 2·10^6`) para dimensionar los factoriales y cuida que `Σ a_i` puede llegar a `10^12`.

**Proyecto del día — Calculadora combinatoria**

Programa que precalcula factoriales e inversos hasta `2·10^6` y responde comandos hasta el fin de la entrada (módulo `10^9 + 7`):

- `perm n k`: `P(n, k)`.
- `comb n k`: `C(n, k)`.
- `multiset n k`: formas de elegir `k` objetos de `n` tipos con repetición, `C(n + k − 1, k)`.
- `verificar`: compara, para todo `n ≤ 1000` y `k ≤ n`, `C(n, k)` por factoriales contra una tabla de Pascal, e imprime `OK` o la primera discrepancia.

Ejemplo: `comb 5 2` → `10`; `perm 5 2` → `20`; `multiset 3 2` → `6`; `verificar` → `OK`.

- **Qué reviso:** casos `k > n`, `k = 0`, `n = 0`, y que `verificar` use una implementación genuinamente distinta (Pascal).
- **Entrega:** `d26.cpp` y `d26_notas.md`.

### Día 27 · viernes 27 de noviembre · Euclides extendido, inversos modulares y teorema chino del resto

**Teoría desde cero.**

**Euclides extendido.** Además del `gcd(a, b)`, devuelve enteros `x, y` con `a·x + b·y = gcd(a, b)`.

```cpp
long long egcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
```

- **Inverso modular (módulo cualquiera):** `a` tiene inverso módulo `m` si y solo si `gcd(a, m) = 1`. Llama a `egcd(a, m, x, y)` y el inverso es `((x % m) + m) % m`.
- **Ecuación diofántica `a·x + b·y = c`:** tiene solución entera si y solo si `gcd(a, b)` divide a `c`. Si `(x0, y0)` es una, todas son `(x0 + t·b/g, y0 − t·a/g)` con `t` entero.
- **Teorema chino del resto (TCR):** el sistema `x ≡ a1 (mod m1)`, `x ≡ a2 (mod m2)` con `m1` y `m2` coprimos tiene una única solución módulo `m1·m2`.

**Matemática del día.**

- *Cómo se obtiene la recurrencia de `egcd`:* si `b·x1 + (a mod b)·y1 = g` y `a mod b = a − (a/b)·b`, entonces `a·y1 + b·(x1 − (a/b)·y1) = g`; por eso `x = y1` e `y = x1 − (a/b)·y1`.
- *TCR constructivo:* escribe `x = a1 + m1·t`. Necesitas `m1·t ≡ a2 − a1 (mod m2)`. Si `g = gcd(m1, m2)`, hay solución si y solo si `g` divide a `a2 − a1`; entonces `t ≡ ((a2 − a1)/g) · inv(m1/g mod m2/g) (mod m2/g)` y la solución es única módulo `lcm(m1, m2)`.

**Problema 27.1 — Euclides extendido** · nivel 3

- **Entrada:** `a b`, con `1 ≤ a, b ≤ 10^9`.
- **Salida:** `g x y`, donde `g = gcd(a, b)`, `a·x + b·y = g` y `x` es el menor entero no negativo para el que existe esa `y`.
- **Ejemplo:** `12 18` → `6 2 -1`; `3 5` → `1 2 -1`.
- **Matemática:** demuestra que todas las soluciones son `(x0 + t·b/g, y0 − t·a/g)` y que exactamente una tiene `x` en `[0, b/g)`.

**Problema 27.2 — Inverso modular** · nivel 4

- **Entrada:** `T` y luego `T` líneas `a m`, con `1 ≤ T ≤ 10^5`, `0 ≤ a ≤ 10^9` y `1 ≤ m ≤ 10^9`.
- **Salida:** el `x` en `[0, m − 1]` con `a·x ≡ 1 (mod m)`, o `-1` si no existe. Para `m = 1` la respuesta es `0`.
- **Ejemplo:** `3 / 3 7 / 4 8 / 10 17` → `5 / -1 / 12`.
- **Matemática:** demuestra que existe inverso si y solo si `gcd(a, m) = 1` (⇒ por Bézout; ⇐ si `a·x ≡ 1` entonces `a·x − m·k = 1`, y todo divisor común de `a` y `m` divide a 1).

**Problema 27.3 — Dos congruencias** · nivel 5

- **Entrada:** `a1 m1 a2 m2`, con `1 ≤ m1, m2 ≤ 10^9` y `0 ≤ a_i < m_i`.
- **Salida:** el menor `x ≥ 0` con `x ≡ a1 (mod m1)` y `x ≡ a2 (mod m2)`, o `-1` si no existe.
- **Ejemplo:** `2 3 3 5` → `8`; `1 4 3 6` → `9`; `0 4 1 6` → `-1`.
- **Matemática:** sigue la construcción de arriba incluyendo el caso en que `m1` y `m2` no son coprimos. Explica por qué `lcm(m1, m2) ≤ 10^18` y por qué cada producto intermedio cabe en `long long`.

**Proyecto del día — RSA de juguete**

El sistema RSA cifra con una clave pública `(n, e)` y descifra con una clave privada `d`. Para primos `p ≠ q`: `n = p·q`, `φ = (p − 1)(q − 1)` y `d` es el inverso de `e` módulo `φ`. Cifrar es `c = m^e mod n` y descifrar es `m = c^d mod n`.

- **Entrada:** `p q e`; luego `k`; luego `k` mensajes `m`. Límites: `p, q` primos distintos `≤ 10^9`, `e` coprimo con `φ`, `1 ≤ k ≤ 1000`, `0 ≤ m < n`.
- **Salida:** primera línea `n d`; luego, por cada mensaje, `c m'` (el cifrado y el descifrado, que debe ser igual a `m`).
- **Ejemplo:** `61 53 17 / 1 / 65` → `3233 2753 / 2790 65`.
- **Qué reviso:** inverso con `egcd`, producto modular seguro con `__int128` (porque `n` llega a `10^18`) y que `m' = m` siempre.
- **Notas:** esboza por qué descifrar funciona (`e·d ≡ 1 mod φ`; usa Fermat en `p` y en `q` y luego combina con el TCR). Es un juguete: el RSA real usa números de cientos de dígitos y relleno criptográfico; nunca lo uses para proteger datos reales.
- **Entrega:** `d27.cpp` y `d27_notas.md`.

### Día 28 · sábado 28 de noviembre · Repaso de la semana 4 y pruebas de estrés

**Teoría: el principio de reflexión (números de Catalan).** Una secuencia de `n` pares de paréntesis bien formada es un camino con pasos `+1` (abrir) y `−1` (cerrar) que va de `(0, 0)` a `(2n, 0)` sin bajar nunca de 0. Hay `C(2n, n)` caminos con `n` pasos de cada tipo. Un camino **malo** toca la altura `−1`; si reflejas su tramo hasta ese primer contacto, obtienes un camino que termina en altura `−2`, es decir, con `n − 1` subidas y `n + 1` bajadas, y la correspondencia es biyectiva. Por tanto los caminos buenos son `C(2n, n) − C(2n, n + 1)`: los **números de Catalan** `1, 1, 2, 5, 14, 42, …`.

**Problema 28.1 — Mayor XOR de una pareja** · nivel 3

- **Entrada:** `n` y luego `n` enteros, con `2 ≤ n ≤ 3000` y `0 ≤ a_i < 2^30`.
- **Salida:** el mayor `a_i ^ a_j` con `i < j`.
- **Ejemplo:** `4 / 1 2 4 8` → `12`.
- **Matemática:** demuestra que `a ^ b ≤ a + b` usando `a + b = (a ^ b) + 2·(a & b)`. Calcula el costo `n²/2` y verifica que cabe.

**Problema 28.2 — Dos grupos iguales** · nivel 4

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 20` y `1 ≤ a_i ≤ 10^9`.
- **Salida:** `SI` si los números se pueden repartir en dos grupos con la misma suma; si no, `NO`.
- **Ejemplo:** `5 / 3 1 4 2 2` → `SI`; `3 / 1 2 4` → `NO`.
- **Matemática:** una condición necesaria es que la suma total sea par; luego el problema es hallar un subconjunto de suma `total/2`. Calcula el costo de enumerar máscaras (`2^20 · 20`).

**Problema 28.3 — Paréntesis válidos** · nivel 5

- **Entrada:** `n`, con `0 ≤ n ≤ 10^6`.
- **Salida:** cuántas secuencias válidas de `n` pares de paréntesis hay, módulo `10^9 + 7` (para `n = 0` hay una, la vacía).
- **Ejemplo:** `3` → `5`; `4` → `14`; `1` → `1`.
- **Matemática:** demuestra con el principio de reflexión que la respuesta es `C(2n, n) − C(2n, n + 1)` (así evitas dividir entre `n + 1`). Dimensiona los factoriales hasta `2·10^6`.

**Proyecto del día — Pruebas de estrés combinatorias**

Un único programa con tres comparaciones; escribe `OK` o el primer contraejemplo de cada una:

1. Catalan: la fórmula `C(2n, n) − C(2n, n + 1)` contra (a) generar todas las secuencias válidas por backtracking para `n = 0..10` y (b) la recurrencia `C(n+1) = Σ C(i)·C(n−i)`.
2. Binomiales: `C(n, k)` con factoriales e inversos contra una tabla de Pascal, para todo `n ≤ 500`.
3. Dos grupos iguales: enumeración de máscaras contra una búsqueda con backtracking y poda, en 3000 pruebas aleatorias con `n ≤ 12` y valores en `[1, 20]`.

- **Qué reviso:** que cada fuerza bruta sea independiente, semilla fija y mensajes claros.
- **Entrega:** `d28.cpp` y `d28_notas.md`.

---

## Semana 5 · 29 nov–5 dic · Algoritmos voraces y programación dinámica

**Objetivo:** decidir cuándo basta una elección "golosa" (y demostrarlo), y plantear programación dinámica: estados, recurrencias, casos base y reconstrucción de la solución. Cierra con el primer simulacro estilo IOI.

### Día 29 · domingo 29 de noviembre · Algoritmos voraces I: intervalos

**Teoría desde cero.** Un algoritmo **voraz** (*greedy*) construye la solución tomando en cada paso la mejor opción local, sin volver atrás. Es muy rápido, pero solo funciona cuando se puede **demostrar** que esa elección nunca empeora el resultado. Sin demostración, un voraz es solo una corazonada.

**Selección de actividades.** Dadas `n` actividades `[s_i, e_i)` (incluyen `s_i`, excluyen `e_i`), ¿cuál es el mayor número que no se solapan? Voraz: ordénalas por **hora de fin** y toma cada una cuyo inicio sea `≥` al fin de la última tomada.

```cpp
sort(v.begin(), v.end(), [](const auto &x, const auto &y) {
    if (x.second != y.second) return x.second < y.second;      // por fin
    return x.first < y.first;
});
long long ultimo = LLONG_MIN; int cnt = 0;
for (auto [s, e] : v)
    if (s >= ultimo) { cnt++; ultimo = e; }
```

**Máximo de intervalos simultáneos (barrido).** Crea eventos `(tiempo, +1)` al inicio y `(tiempo, −1)` al final; ordénalos (a igual tiempo, `−1` va antes que `+1`, porque `[s, e)` no incluye `e`) y lleva un contador.

```cpp
vector<pair<long long, int>> ev;
for (auto [s, e] : v) { ev.push_back({s, +1}); ev.push_back({e, -1}); }
sort(ev.begin(), ev.end());
int cur = 0, mx = 0;
for (auto [t, d] : ev) { cur += d; mx = max(mx, cur); }
```

**Trabajos con plazo (tiempo unitario).** Cada trabajo dura 1 unidad y tiene un plazo `d` y una ganancia `g`. Ordena por plazo; recorre guardando las ganancias en un min-heap; si el heap tiene más trabajos que el plazo actual, descarta la menor ganancia.

```cpp
priority_queue<long long, vector<long long>, greater<long long>> pq;
for (auto [d, g] : jobs) {                       // jobs ordenados por plazo
    pq.push(g);
    if ((long long)pq.size() > d) pq.pop();      // sobran trabajos: se va el menos rentable
}
```

**Matemática del día: argumento de intercambio.** Para la selección de actividades: sea `G` la actividad que termina primero. Toma cualquier solución óptima y cámbiale su primera actividad por `G`: como `G` termina antes o a la misma hora, sigue sin solaparse con las demás, y el tamaño no cambia. Entonces existe un óptimo que contiene a `G`; se repite con lo que queda (inducción). Para los plazos: un conjunto de trabajos es factible si y solo si, ordenados por plazo, el `i`-ésimo tiene plazo `≥ i`.

**Problema 29.1 — Máximo de actividades** · nivel 3

- **Entrada:** `n` y luego `n` líneas `s e`, con `1 ≤ n ≤ 2·10^5` y `0 ≤ s < e ≤ 10^9`. Dos actividades son compatibles si `e1 ≤ s2` o `e2 ≤ s1`.
- **Salida:** el máximo número de actividades mutuamente compatibles.
- **Ejemplo:** `5 / 1 3 / 2 5 / 3 6 / 5 8 / 6 9` → `3`.
- **Matemática:** demuestra el argumento de intercambio y explica por qué ordenar por *inicio* o por *duración* no funciona (busca un contraejemplo para cada uno).

**Problema 29.2 — Salas necesarias** · nivel 4

- **Entrada:** `n` y luego `n` reuniones `s e` (intervalos `[s, e)`), con `1 ≤ n ≤ 2·10^5` y `0 ≤ s < e ≤ 10^9`.
- **Salida:** el mínimo número de salas para realizarlas todas.
- **Ejemplo:** `4 / 0 30 / 5 10 / 15 20 / 10 15` → `2`.
- **Matemática:** demuestra que la respuesta es el máximo de reuniones simultáneas: hacen falta al menos ese número (en ese instante) y el voraz por inicio lo logra.

**Problema 29.3 — Trabajos con plazo y ganancia** · nivel 5

- **Entrada:** `n` y luego `n` líneas `d g`, con `1 ≤ n ≤ 2·10^5`, `1 ≤ d ≤ 10^9` y `1 ≤ g ≤ 10^9`. Cada trabajo dura 1 unidad de tiempo; el tiempo `t = 1, 2, 3, …` admite un trabajo y el trabajo `i` debe hacerse en un tiempo `t ≤ d_i`.
- **Salida:** la máxima ganancia total.
- **Ejemplo:** `5 / 2 100 / 1 19 / 2 27 / 1 25 / 3 15` → `142`.
- **Matemática:** demuestra la condición de factibilidad (ordenados por plazo, el `i`-ésimo tiene plazo `≥ i`) y por qué descartar la menor ganancia cuando el heap se pasa conserva siempre el mejor conjunto factible. Acota la respuesta (`≤ 2·10^14`).

**Proyecto del día — Agenda óptima**

Un teatro recibe `n` solicitudes `id inicio fin` (intervalos `[inicio, fin)`). El programa calcula tres cosas:

1. El mayor conjunto de solicitudes compatibles. Ordena por `(fin, id)`; toma una solicitud si `inicio ≥ fin` de la última tomada.
2. El mínimo de salas necesarias para atender **todas**.
3. Una asignación de sala para cada solicitud. Ordena por `(inicio, id)`; libera las salas cuyo fin sea `≤ inicio`; usa la sala libre de **menor número**, o abre una nueva.

- **Entrada:** `n` y `n` líneas `id inicio fin` (`1 ≤ n ≤ 2·10^5`, `id` de 1 a `n`).
- **Salida:** línea 1: `K` y los `K` id elegidos en el orden de selección; línea 2: el número de salas; línea 3: la sala de la solicitud `1, 2, …, n`.
- **Ejemplo:** `4 / 1 0 30 / 2 5 10 / 3 15 20 / 4 10 15` → `3 2 4 3 / 2 / 1 2 2 2`.
- **Qué reviso:** los desempates exactos, dos heaps (salas ocupadas por fin y salas libres por número) y costo `O(n log n)`.
- **Entrega:** `d29.cpp` y `d29_notas.md`.

### Día 30 · lunes 30 de noviembre · Algoritmos voraces II: ordenar con el comparador correcto

**Teoría desde cero.** Muchos problemas voraces se reducen a **ordenar con un comparador inteligente**. El método para encontrarlo es el **intercambio de vecinos**: toma una solución cualquiera, mira dos elementos consecutivos `i, j`, calcula cuánto cambia el resultado si los intercambias y deduce una regla "`i` va antes que `j` cuando…". Si en una solución desordenada siempre existe un par de vecinos en el orden incorrecto (como en un ordenamiento burbuja), arreglarlo no empeora el resultado y por tanto el orden por esa regla es óptimo.

```cpp
// formar el número más grande pegando cadenas
sort(v.begin(), v.end(), [](const string &a, const string &b) {
    return a + b > b + a;
});
```

El comparador debe ser un orden estricto válido (irreflexivo y transitivo). Si lo escribes con divisiones, usa multiplicación cruzada para no perder precisión: `t_i / w_i < t_j / w_j` equivale a `t_i · w_j < t_j · w_i`.

**Voraz con un heap: paradas de combustible.** Mientras avanzas, guarda en un max-heap el combustible de todas las estaciones que ya pasaste. Cuando no alcanzas la siguiente meta, "te detienes retroactivamente" en la estación con más combustible.

**Matemática del día.**

- *Concatenación:* para `a` y `b` con longitudes `la` y `lb`, `a+b > b+a` equivale a `a·10^lb + b > b·10^la + a`, es decir, `a·(10^lb − 1) > b·(10^la − 1)`, o `a/(10^la − 1) > b/(10^lb − 1)`. Es una comparación entre números reales `f(x) = x/(10^len(x) − 1)`, así que es transitiva.
- *Regla de Smith:* para minimizar `Σ w_i·C_i` (tiempos de finalización `C_i`), si `i` va justo antes que `j`, el costo de ese par es `w_i·t_i + w_j·(t_i + t_j)`; invertido, `w_j·t_j + w_i·(t_i + t_j)`. La diferencia es `w_j·t_i − w_i·t_j`: conviene `i` primero si `t_i/w_i < t_j/w_j`.

**Problema 30.1 — Mayor número concatenando** · nivel 4

- **Entrada:** `n` y luego `n` enteros no negativos (de hasta 18 dígitos), con `1 ≤ n ≤ 10^5` y longitud total `≤ 10^6`.
- **Salida:** el mayor número que se forma pegándolos en algún orden (sin ceros a la izquierda; si todos son cero, `0`).
- **Ejemplo:** `4 / 12 121 9 98` → `99812121`.
- **Matemática:** demuestra que el comparador `a+b > b+a` es transitivo con la fórmula de arriba.

**Problema 30.2 — Espera ponderada mínima** · nivel 4

`n` trabajos se ejecutan uno tras otro. El trabajo `i` dura `t_i` y tiene peso `w_i`. Si termina en el instante `C_i`, el costo total es `Σ w_i·C_i`. Elige el orden que lo minimiza.

- **Entrada:** `n` y luego `n` líneas `t w`, con `1 ≤ n ≤ 10^5` y `1 ≤ t, w ≤ 10^4`.
- **Salida:** el costo mínimo.
- **Ejemplo:** `3 / 3 1 / 1 1 / 2 2` → `13`.
- **Matemática:** demuestra la regla de Smith con el intercambio de vecinos y acota la respuesta para confirmar que cabe en `long long`.

**Problema 30.3 — Paradas de combustible** · nivel 5

Un auto está en el kilómetro 0 con `F` unidades de combustible (consume 1 por kilómetro) y debe llegar al kilómetro `D`. Hay `n` estaciones: en la posición `p_i` se carga `f_i` unidades (se recarga todo al detenerse).

- **Entrada:** `D F n` y luego `n` líneas `p f`. Límites: `1 ≤ D, F ≤ 10^9`, `1 ≤ n ≤ 2·10^5`, `1 ≤ p_i < D`, `1 ≤ f_i ≤ 10^9`.
- **Salida:** el mínimo de paradas para llegar a `D`, o `-1` si es imposible.
- **Ejemplo:** `25 5 4 / 3 10 / 5 2 / 10 8 / 15 4` → `3`.
- **Matemática:** si ya agotaste el combustible, debiste haberte detenido antes en alguna estación que pasaste; elegir la de mayor combustible nunca es peor (intercambio). Costo `O(n log n)`.

**Proyecto del día — Comparador de políticas de turnos**

Un taller recibe `n` trabajos `id t w d` (duración, peso, fecha límite). Se ejecutan uno tras otro desde el instante 0 en el orden de cada política:

- `SPT`: duración menor primero (desempate: `id`).
- `SMITH`: `t/w` menor primero, con multiplicación cruzada (desempate: `id`).
- `EDD`: fecha límite menor primero (desempate: `id`).

Para cada política imprime `NOMBRE suma_C suma_wC max_retraso`, donde `C_i` es el instante de finalización y el retraso de un trabajo es `C_i − d_i` (puede ser negativo; `max_retraso` es el máximo).

- **Entrada:** `n` y `n` líneas `id t w d`, con `1 ≤ n ≤ 10^5`, `1 ≤ t, w ≤ 10^4` y `1 ≤ d ≤ 10^9`.
- **Ejemplo:** `3 / 1 1 2 10 / 2 5 4 3 / 3 2 1 1` → `SPT 12 37 5 / SMITH 15 34 7 / EDD 17 46 4`.
- **Qué reviso:** comparadores válidos (sin divisiones ni `<=`), `long long` y salida exacta.
- **Notas:** con ese ejemplo, indica qué política gana en cada métrica y explica por qué no hay una política ganadora en todas.
- **Entrega:** `d30.cpp` y `d30_notas.md`.

### Día 31 · martes 1 de diciembre · Programación dinámica I: estados y recurrencias

**Teoría desde cero.** La **programación dinámica** (DP) resuelve un problema grande a partir de problemas más pequeños **que se repiten**, guardando sus respuestas para no recalcularlas. Se plantea con cuatro preguntas:

1. **Estado:** ¿qué significa `dp[i]`? (Escríbelo en una frase: "`dp[i]` es el número de formas de…").
2. **Recurrencia:** ¿cómo se obtiene `dp[i]` de estados más pequeños?
3. **Caso base:** ¿cuánto vale el estado más pequeño?
4. **Orden y respuesta:** ¿en qué orden se calculan y cuál estado es la respuesta?

```cpp
// formas de subir n escalones dando pasos de 1, 2 o 3
vector<long long> dp(n + 1, 0);
dp[0] = 1;                                 // caso base: una forma de estar en el suelo
for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (i >= 2) dp[i] += dp[i - 2];
    if (i >= 3) dp[i] += dp[i - 3];
    dp[i] %= MOD;
}
```

La versión **de abajo hacia arriba** (el código anterior) llena una tabla en orden. La versión **con memoización** escribe la recurrencia como función recursiva y guarda resultados (`memo[i] = ...`). Ambas hacen el mismo trabajo.

**Cambio de monedas.** Mínimo de monedas para formar `S`: `dp[x] = 1 + min(dp[x − c])` sobre las monedas `c ≤ x`, con `dp[0] = 0` y un valor "infinito" para lo imposible.

**Contar combinaciones o permutaciones:** el orden de los ciclos lo decide todo. Con las monedas en el ciclo **de afuera** y los montos en el de adentro, cada multiconjunto de monedas se cuenta una sola vez (combinaciones); con los montos afuera y las monedas adentro, cada **secuencia** se cuenta (permutaciones).

**Matemática del día.** *Corrección por inducción:* si `dp[j]` es correcto para todo `j < i`, y la recurrencia cubre todas las opciones del último paso (cada una distinta de las otras), entonces `dp[i]` es correcto. *Costo:* número de estados × costo de cada transición. *Contar con y sin orden:* para `S = 4` con monedas `{1, 2, 3}`, las combinaciones son 4 (`1+1+1+1`, `1+1+2`, `2+2`, `1+3`) y las secuencias son 7.

**Problema 31.1 — Escaleras** · nivel 3

- **Entrada:** `n`, con `1 ≤ n ≤ 10^6`.
- **Salida:** de cuántas formas se sube una escalera de `n` escalones dando pasos de 1, 2 o 3, módulo `10^9 + 7`.
- **Ejemplo:** `4` → `7`; `1` → `1`; `3` → `4`.
- **Matemática:** demuestra la recurrencia `f(n) = f(n−1) + f(n−2) + f(n−3)` clasificando las formas por su último paso, y fija los casos base `f(0) = 1`, `f(1) = 1`, `f(2) = 2`.

**Problema 31.2 — Cambio mínimo** · nivel 4

- **Entrada:** `n S` y luego `n` valores de monedas distintos, con `1 ≤ n ≤ 100`, `1 ≤ S ≤ 10^5` y `1 ≤ c ≤ 10^5`. Cada moneda se puede usar cuantas veces se quiera.
- **Salida:** la menor cantidad de monedas que suma `S`, o `-1`.
- **Ejemplo:** `3 11 / 1 2 5` → `3`; `2 7 / 2 4` → `-1`.
- **Matemática:** calcula el costo `S · n` y explica por qué el voraz "toma la moneda más grande posible" puede fallar (con monedas `{1, 3, 4}` y `S = 6`).

**Problema 31.3 — Formas de dar cambio** · nivel 5

- **Entrada:** `n S` y luego `n` valores de monedas, con `1 ≤ n ≤ 100`, `1 ≤ S ≤ 10^5`.
- **Salida:** de cuántas maneras se forma `S` **sin importar el orden** de las monedas, módulo `10^9 + 7`.
- **Ejemplo:** `3 4 / 1 2 3` → `4`.
- **Matemática:** explica por qué, con monedas afuera y montos adentro, cada combinación se cuenta una sola vez, y por qué el orden inverso daría 7 en el ejemplo.

**Proyecto del día — Máquina de cambio**

Calcula, para varios montos, el cambio con menos monedas y muestra qué monedas se usan.

- **Entrada:** `n q`; luego `n` valores de monedas; luego `q` montos. Límites: `1 ≤ n ≤ 100`, `1 ≤ q ≤ 100`, montos `≤ 10^5`.
- **Salida:** por cada monto, `k: c1 c2 …` con la cantidad `k` y las monedas en orden decreciente, o `IMPOSIBLE`.
- **Reconstrucción:** desde el monto `x`, toma la moneda **mayor** `c ≤ x` con `dp[x − c] = dp[x] − 1`, y repite con `x − c`.
- **Ejemplo:** `3 2 / 1 3 4 / 6 7` → `2: 3 3 / 2: 4 3`.
- **Qué reviso:** manejo del infinito sin desbordar, reconstrucción correcta y una sola tabla `dp` para todos los montos.
- **Notas:** muestra un sistema de monedas en el que el voraz falla y explica por qué la DP sí funciona.
- **Entrega:** `d31.cpp` y `d31_notas.md`.

### Día 32 · miércoles 2 de diciembre · Programación dinámica II: mochila

**Teoría desde cero.** El problema de la **mochila 0/1**: tienes `n` objetos con peso `w_i` y valor `v_i`, y una capacidad `W`; cada objeto se toma una vez o no se toma. ¿Cuál es el mayor valor?

- **Estado:** `dp[w]` = mayor valor con capacidad `w` usando los objetos vistos hasta ahora.
- **Recurrencia:** al agregar el objeto `i`, `dp[w] = max(dp[w], dp[w − w_i] + v_i)`.

```cpp
vector<long long> dp(W + 1, 0);
for (int i = 0; i < n; i++)
    for (int w = W; w >= wt[i]; w--)               // DESCENDENTE: cada objeto se usa una vez
        dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
```

Si el ciclo de `w` fuese ascendente, `dp[w − w_i]` ya incluiría al objeto `i` y lo podrías usar varias veces: eso es la **mochila ilimitada**.

**Suma de subconjuntos.** Si lo que importa es "¿se puede formar la suma `s`?", `dp` es booleano: `dp[s] |= dp[s − a_i]`. Con `bitset`, la actualización completa es `dp |= dp << a_i`.

**Matemática del día.**

- *Estado completo:* `dp[i][w]` es el mejor valor con los primeros `i` objetos y capacidad `w`; depende solo de `dp[i−1][·]`. Iterar `w` de mayor a menor en un solo arreglo garantiza que `dp[w − w_i]` aún es del paso `i − 1`.
- *Costo:* `O(n · W)`. Es **pseudopolinomial**: crece con el valor de `W`, no con su tamaño en bits; con `W = 10^9` es inviable.
- *Partición binaria para objetos repetidos:* si de un objeto hay `c` copias, divídelas en lotes de tamaños `1, 2, 4, …, 2^(k−1)` y un resto `r = c − (2^k − 1)`, con `k` el mayor entero tal que `2^k − 1 ≤ c`. Con esos lotes se puede formar cualquier cantidad de `0` a `c`, y nada más.

**Problema 32.1 — Mochila 0/1** · nivel 4

- **Entrada:** `n W` y luego `n` líneas `w v`, con `1 ≤ n ≤ 100`, `1 ≤ W ≤ 10^4`, `1 ≤ w ≤ 10^4` y `1 ≤ v ≤ 10^6`.
- **Salida:** el mayor valor total sin pasar la capacidad.
- **Ejemplo:** `4 7 / 1 1 / 3 4 / 4 5 / 5 7` → `9` (objetos de peso 3 y 4).
- **Matemática:** explica por qué el recorrido descendente evita usar un objeto dos veces y acota el valor máximo.

**Problema 32.2 — Dos grupos con diferencia mínima** · nivel 4

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 100` y `1 ≤ a_i ≤ 100`.
- **Salida:** la menor diferencia posible `|S1 − S2|` al repartir todos los números en dos grupos.
- **Ejemplo:** `4 / 1 2 3 9` → `3`.
- **Matemática:** si el total es `T` y un grupo suma `s`, la diferencia es `|T − 2s|`; basta hallar el mayor `s ≤ T/2` alcanzable (suma de subconjuntos). Justifica por qué `T ≤ 10^4` hace que el costo sea pequeño.

**Problema 32.3 — Mochila con cantidades** · nivel 5

- **Entrada:** `n W` y luego `n` líneas `w v c` (peso, valor y copias disponibles), con `1 ≤ n ≤ 100`, `1 ≤ W ≤ 10^4`, `1 ≤ w ≤ 10^4`, `1 ≤ v ≤ 10^6` y `1 ≤ c ≤ 10^4`.
- **Salida:** el mayor valor total.
- **Ejemplo:** `2 10 / 3 5 2 / 4 7 3` → `17` (dos de peso 3 y uno de peso 4).
- **Matemática:** demuestra la partición binaria (los lotes `1, 2, 4, …, r` generan exactamente `0..c`) y calcula el costo `O(W · Σ log c_i)`.

**Proyecto del día — Optimizador de presupuesto**

Un comprador elige entre `n` artículos con un presupuesto `B` para maximizar el valor.

- **Entrada:** `n B` y `n` líneas `nombre costo valor`, con `1 ≤ n ≤ 100`, `1 ≤ B ≤ 10^4`, costos `≥ 1`.
- **Salida:** línea 1: `valor_total costo_total`; línea 2: los nombres elegidos en el orden de la entrada (o `-` si ninguno); línea 3: `voraz diferencia`, donde `voraz` es el valor que obtiene el criterio "mayor valor/costo primero, mientras quepa" (desempate: orden de entrada) y `diferencia` es `óptimo − voraz`.
- **Reconstrucción:** con la tabla `dp[i][w]` completa, desde `i = n` hacia atrás: si `dp[i][w] ≠ dp[i−1][w]`, el objeto `i` se toma y `w` baja su costo.
- **Ejemplo:** `3 50 / a 10 60 / b 20 100 / c 30 120` → `220 50 / b c / 160 60`.
- **Qué reviso:** reconstrucción correcta (no basta el arreglo de una dimensión) y la comparación con el voraz.
- **Entrega:** `d32.cpp` y `d32_notas.md`.

### Día 33 · jueves 3 de diciembre · Programación dinámica III: secuencias

**Teoría desde cero.** Muchos problemas de DP trabajan con **secuencias**: el estado dice "qué pasó con los primeros `i` elementos".

**Subsecuencia creciente más larga (LIS).** En `O(n²)`: `dp[i]` = longitud de la mejor subsecuencia estrictamente creciente que termina en `a[i]`; `dp[i] = 1 + max dp[j]` sobre `j < i` con `a[j] < a[i]`.

En `O(n log n)`, el arreglo `tails`, donde `tails[k]` es la **menor cola posible** de una subsecuencia creciente de largo `k + 1`:

```cpp
vector<int> tails;
for (int x : a) {
    auto it = lower_bound(tails.begin(), tails.end(), x);   // estrictamente creciente
    if (it == tails.end()) tails.push_back(x); else *it = x;
}
// tails.size() es la longitud de la LIS. Para no decreciente, usa upper_bound.
```

**Subsecuencia común más larga (LCS).** `dp[i][j]` es la LCS de los primeros `i` caracteres de `s` y los primeros `j` de `t`:

```cpp
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + 1
                                       : max(dp[i-1][j], dp[i][j-1]);
```

**Distancia de edición (Levenshtein).** Mínimo de inserciones, borrados y sustituciones para convertir `s` en `t`: `dp[i][j] = min(dp[i−1][j] + 1, dp[i][j−1] + 1, dp[i−1][j−1] + (s[i-1] != t[j-1]))`, con `dp[i][0] = i` y `dp[0][j] = j`.

**Matemática del día.**

- *LCS:* mira el último carácter de cada cadena. Si coinciden, siempre se pueden emparejar en alguna LCS (si la LCS no los usa, agregarlos la mejoraría); si no, al menos uno de los dos no está en la LCS y se descarta.
- *LIS con `tails`:* `tails` siempre queda estrictamente creciente. Un valor `x` mejora la mejor cola de la longitud `p + 1` (la primera cola `≥ x`), y si `x` es mayor que todas, extiende la LIS. `tails` **no** es una LIS, solo su longitud es correcta.
- *Reconstruir:* retrocede por la tabla viendo de qué casilla vino cada valor.

**Problema 33.1 — LIS cuadrática** · nivel 4

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 5000` y `|a_i| ≤ 10^9`.
- **Salida:** la longitud de la subsecuencia estrictamente creciente más larga.
- **Ejemplo:** `7 / 3 1 4 1 5 9 2` → `4`.
- **Matemática:** demuestra la recurrencia `dp[i] = 1 + max{dp[j] : j < i, a_j < a_i}` (o 1 si no existe ese `j`) clasificando las subsecuencias por su penúltimo elemento.

**Problema 33.2 — LCS con reconstrucción** · nivel 5

- **Entrada:** dos líneas con cadenas de minúsculas `s` y `t`, con `1 ≤ |s|, |t| ≤ 2000`.
- **Salida:** la longitud de su LCS y, en la línea siguiente, una LCS. Para que sea única, reconstruye desde `(n, m)`: si los caracteres coinciden, tómalo y baja a `(i−1, j−1)`; si no, ve a `(i−1, j)` cuando `dp[i−1][j] ≥ dp[i][j−1]` y a `(i, j−1)` en caso contrario.
- **Ejemplo:** `aggtab / gxtxayb` → `4 / gtab`.
- **Matemática:** demuestra la recurrencia de la LCS por casos sobre el último carácter. ¿Cuánta memoria usa tu tabla (`2001 × 2001` enteros)?

**Problema 33.3 — LIS rápida** · nivel 6

- **Entrada:** `n` y luego `n` enteros, con `1 ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** dos números: la longitud de la subsecuencia estrictamente creciente más larga y la de la **no decreciente** más larga.
- **Ejemplo:** `6 / 2 2 3 1 3 4` → `3 5`.
- **Matemática:** demuestra el invariante de `tails` (estrictamente creciente en todo momento y `tails[k]` mínima) y explica por qué usar `lower_bound` o `upper_bound` cambia entre estricta y no decreciente.

**Proyecto del día — Corrector ortográfico**

Sugiere correcciones para palabras mal escritas usando la distancia de edición.

- **Entrada:** `n q`; luego `n` palabras del diccionario; luego `q` palabras a corregir. Límites: `1 ≤ n ≤ 5000`, `1 ≤ q ≤ 100`, palabras de minúsculas de a lo más 15 letras.
- **Salida:** por cada palabra, hasta 3 sugerencias del diccionario con distancia `≤ 2`, ordenadas por `(distancia, palabra)` y escritas `palabra:distancia`, separadas por espacios; si no hay ninguna, escribe `?`.
- **Ejemplo:** diccionario `casa cosa caso mesa peso` y consulta `cesa` → `casa:1 cosa:1 mesa:1`.
- **Qué reviso:** distancia de edición correcta, costo total acotado (`q · n · 15²`), desempates y salida exacta.
- **Notas:** muestra la tabla `dp` para convertir `cesa` en `casa` y explica por qué la distancia es simétrica.
- **Entrega:** `d33.cpp` y `d33_notas.md`.

### Día 34 · viernes 4 de diciembre · Programación dinámica IV: cuadrículas

**Teoría desde cero.** En una cuadrícula donde solo te mueves **hacia la derecha o hacia abajo**, cada celda se alcanza desde la de arriba o desde la de la izquierda. El estado es la propia celda:

```cpp
dp[0][0] = a[0][0];
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) continue;
        long long mejor = LLONG_MAX;
        if (i > 0) mejor = min(mejor, dp[i - 1][j]);
        if (j > 0) mejor = min(mejor, dp[i][j - 1]);
        dp[i][j] = a[i][j] + mejor;
    }
```

- **Contar caminos:** `dp[i][j] = dp[i-1][j] + dp[i][j-1]`, y una celda con obstáculo vale 0.
- **Reconstruir el camino:** guarda de dónde viene cada valor o retrocede comparando.
- **Estados extra:** si dos personas caminan a la vez, el estado necesita la posición de ambas.

**Matemática del día.** Sin obstáculos, el número de caminos de `(1,1)` a `(n,m)` es `C(n + m − 2, n − 1)`: de los `n + m − 2` pasos, elige cuáles son hacia abajo. Para `3 × 3`, `C(4, 2) = 6`. Dos caminantes que avanzan a la vez están siempre en la misma antidiagonal `fila + columna = t`, así que el estado es `(t, fila_1, fila_2)`, con `columna_k = t − fila_k`, y las monedas de una celda se cuentan una vez cuando `fila_1 = fila_2`.

**Problema 34.1 — Camino de costo mínimo** · nivel 3

- **Entrada:** `n m` y luego una matriz de costos `n × m`, con `1 ≤ n, m ≤ 1000` y `0 ≤ a ≤ 10^6`.
- **Salida:** el costo mínimo de ir de `(1,1)` a `(n,m)` sumando el costo de cada celda visitada.
- **Ejemplo:** `3 3 / 2 1 4 / 3 7 1 / 5 2 3` → `11`.
- **Matemática:** demuestra la recurrencia por inducción y acota la respuesta (`≤ 2000 · 10^6`) para decidir el tipo de dato.

**Problema 34.2 — Caminos con obstáculos** · nivel 4

- **Entrada:** `n m` y luego `n` filas de `m` caracteres: `.` libre, `#` obstáculo. Límites: `1 ≤ n, m ≤ 1000`.
- **Salida:** cuántos caminos (solo derecha o abajo) hay de `(1,1)` a `(n,m)` sin pisar obstáculos, módulo `10^9 + 7` (0 si el inicio o el final son obstáculos).
- **Ejemplo:** `3 3 / ... / .#. / ...` → `2`.
- **Matemática:** comprueba la fórmula `C(n + m − 2, n − 1)` contra tu DP en un tablero sin obstáculos de `3 × 3` (6) y de `4 × 5`.

**Problema 34.3 — Dos recolectores** · nivel 6

Dos recolectores salen de `(1,1)` y llegan a `(n,m)` moviéndose solo hacia la derecha o abajo. Cada celda tiene monedas; si ambos pasan por una celda, sus monedas se cuentan **una sola vez**. Maximiza el total.

- **Entrada:** `n m` y la matriz de monedas, con `1 ≤ n, m ≤ 100` y `0 ≤ a ≤ 100`.
- **Salida:** el máximo total de monedas.
- **Ejemplo:** `3 3 / 0 3 1 / 2 0 4 / 5 1 0` → `16`.
- **Matemática:** justifica el estado `(t, fila_1, fila_2)` y cuenta estados y transiciones (`(n + m) · n² · 4`). Explica por qué hacer que un recolector tome el mejor camino y luego el otro el mejor del resto **no** es correcto en general.

**Proyecto del día — Mapa de caminos**

- **Entrada:** `n m` y una matriz `n × m` con enteros: `-1` es un muro y `≥ 0` es el costo de pisar esa celda (incluida la inicial). Límites: `1 ≤ n, m ≤ 1000`.
- **Salida:** línea 1: `costo_minimo cantidad_de_caminos_minimos` (la cantidad módulo `10^9 + 7`); línea 2: un camino mínimo como cadena de `D` y `R`, prefiriendo `D` cuando ambos llevan a un camino mínimo. Si no hay camino, escribe `SIN CAMINO`.
- **Ejemplo:** `3 3 / 1 3 1 / 1 5 1 / 4 2 1` → `7 1 / RRDD`.
- **Qué reviso:** DP hacia adelante o hacia atrás (para el desempate de la reconstrucción te conviene calcular desde el final), contar caminos mínimos con módulo y los muros.
- **Notas:** verifica tu conteo de caminos en tableros sin muros hasta `30 × 30` con la fórmula `C(n + m − 2, n − 1)` calculada exactamente (cabe en `long long`).
- **Entrega:** `d34.cpp` y `d34_notas.md`.

### Día 35 · sábado 5 de diciembre · Simulacro 1 estilo IOI

**Teoría: cómo se puntúa y cómo se compite.** En la IOI cada problema se divide en **subtareas**: bloques de casos de prueba con límites cada vez más amplios y un puntaje propio. Una subtarea solo cuenta si **todos** sus casos salen bien y a tiempo; el puntaje de un problema es la suma de sus subtareas resueltas (hasta 100). Por eso, una solución parcial correcta vale más que una completa con un error.

Estrategia para hoy (tiempo sugerido: 3 horas; en la IOI real cada jornada dura 5 horas):

1. Lee los tres problemas completos (10 a 15 minutos) y ordénalos de más fácil a más difícil *para ti*.
2. En cada problema, escribe primero la solución de fuerza bruta para la primera subtarea: asegura puntos y servirá para comparar.
3. Mejora subtarea por subtarea. Antes de entregar cada versión, compárala con la fuerza bruta en casos pequeños aleatorios.
4. Reserva 20 minutos finales para revisar desbordamientos, casos borde y formato de salida.

**Problema 35.1 — Aspersores** · nivel 4

En una línea hay `n` plantas en las posiciones enteras `x_i` (pueden repetirse). Un aspersor en la posición `p` (cualquier entero) riega las plantas en `[p, p + L]`, extremos incluidos. ¿Cuántos aspersores hacen falta como mínimo?

- **Entrada:** `n L` y luego `n` posiciones. Límites: `1 ≤ n ≤ 2·10^5`, `0 ≤ L ≤ 10^9`, `0 ≤ x_i ≤ 10^9`.
- **Salida:** el mínimo de aspersores.
- **Subtareas:** (20 puntos) `n ≤ 15`; (30 puntos) `n ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `6 4 / 1 2 3 8 9 20` → `3`.
- **Matemática:** demuestra que existe un óptimo donde cada aspersor se coloca justo en la planta más a la izquierda que aún no está regada.

**Problema 35.2 — Pasos rotos** · nivel 5

Una escalera tiene peldaños numerados de `1` a `n`; empiezas en el `0` y en cada movimiento subes entre `1` y `K` peldaños. `m` peldaños están rotos y no puedes pisarlos. ¿De cuántas formas llegas al peldaño `n`?

- **Entrada:** `n K m` y, si `m > 0`, una segunda línea con los `m` peldaños rotos (distintos, entre 1 y `n`). Límites: `1 ≤ K ≤ n ≤ 10^6`, `0 ≤ m ≤ n`.
- **Salida:** la cantidad de formas, módulo `10^9 + 7` (0 si el peldaño `n` está roto).
- **Subtareas:** (15 puntos) `n ≤ 20`; (35 puntos) `n ≤ 5000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 2 1 / 3` → `2`.
- **Matemática:** plantea `dp[i] = Σ_{k=1..K} dp[i−k]` (y `0` si `i` está roto); expresa esa suma como una diferencia de sumas prefijas para pasar de `O(nK)` a `O(n)`.

**Problema 35.3 — Ventanas parejas** · nivel 6

Cuenta los subarreglos contiguos no vacíos en los que la diferencia entre el máximo y el mínimo es a lo más `K`.

- **Entrada:** `n K` y luego `n` enteros. Límites: `1 ≤ n ≤ 2·10^5`, `0 ≤ K ≤ 10^9`, `|a_i| ≤ 10^9`.
- **Salida:** la cantidad (cabe en `long long`).
- **Subtareas:** (20 puntos) `n ≤ 100`; (30 puntos) `n ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 2 / 1 3 2 5 4` → `9`.
- **Matemática:** demuestra que si `[l, r]` es válido, toda subventana también, y que para cada `r` el menor `l` válido no decrece al aumentar `r`. Usa dos deques monótonos (máximo y mínimo) y cuenta `r − l + 1` subarreglos por cada `r`.

**Proyecto del día — Informe de simulacro**

El proyecto es el simulacro mismo y su análisis.

1. Resuelve los tres problemas con el tiempo sugerido y anota cuánto te tomó cada uno.
2. Entrega, para cada problema, la **mejor solución completa** que logres (después del simulacro puedes terminarlas: eso se llama *upsolving*; indica en las notas qué lograste dentro del tiempo y qué después).
3. Para cada problema, un test de estrés dentro del mismo archivo: tu solución final contra la fuerza bruta de la primera subtarea, con 3000 casos aleatorios pequeños.
4. En las notas, una tabla con: subtareas que habrías resuelto dentro del tiempo, puntaje estimado por problema, causa de cada subtarea perdida y una acción concreta para mejorar.

- **Qué califico:** que cada solución completa pase los límites de la última subtarea, que los tests de estrés sean independientes y la calidad del análisis.
- **Entrega:** `d35_p1.cpp`, `d35_p2.cpp`, `d35_p3.cpp` y `d35_notas.md`.

---

## Semana 6 · 6–12 dic · Grafos: recorridos, componentes, DSU y árboles de expansión mínima

**Objetivo:** modelar problemas como grafos, recorrerlos con DFS y BFS, ordenar dependencias, mantener conjuntos que se fusionan (DSU) y construir árboles de expansión mínima.

### Día 36 · domingo 6 de diciembre · Grafos: representación, DFS y componentes conexas

**Teoría desde cero.** Un **grafo** es un conjunto de **vértices** (o nodos) y un conjunto de **aristas** que unen pares de vértices. Sirve para modelar redes: ciudades y carreteras, personas y amistades, tareas y dependencias.

- **No dirigido:** la arista `u–v` se recorre en ambos sentidos. **Dirigido:** la arista `u→v` solo de `u` a `v`.
- **Grado** de un vértice: cuántas aristas lo tocan.
- **Camino:** sucesión de vértices consecutivos unidos por aristas. **Ciclo:** camino que vuelve a su inicio sin repetir aristas.
- **Conexo:** existe un camino entre cualquier par de vértices. Una **componente conexa** es un trozo conexo maximal.
- **Árbol:** grafo conexo y sin ciclos (tiene `n − 1` aristas). **Bosque:** grafo sin ciclos.

**Representación: lista de adyacencia.** Para cada vértice, la lista de sus vecinos. Ocupa `O(n + m)` y es la forma estándar:

```cpp
int n, m; cin >> n >> m;
vector<vector<int>> g(n + 1);
for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);                  // quita esta línea si el grafo es dirigido
}
```

(Una matriz de adyacencia `n × n` solo sirve para `n` de unos pocos miles.)

**Recorrido en profundidad (DFS).** Desde un vértice, avanza por un vecino no visitado hasta no poder más y retrocede. Cada vértice y cada arista se miran una cantidad constante de veces: `O(n + m)`.

```cpp
vector<bool> vis(n + 1, false);
function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    for (int v : g[u]) if (!vis[v]) dfs(v);
};
int componentes = 0;
for (int s = 1; s <= n; s++)
    if (!vis[s]) { componentes++; dfs(s); }
```

**Cuidado con la profundidad.** En un grafo en forma de camino con `2·10^5` vértices, la recursión baja `2·10^5` niveles y puede agotar la pila. Alternativa iterativa con una pila explícita (sirve para marcar componentes):

```cpp
vector<int> pila = {s};
vis[s] = true;
while (!pila.empty()) {
    int u = pila.back(); pila.pop_back();
    for (int v : g[u]) if (!vis[v]) { vis[v] = true; pila.push_back(v); }
}
```

**Matemática del día.**

- *Lema del apretón de manos:* `Σ grado(v) = 2m`, porque cada arista aporta 1 al grado de cada uno de sus dos extremos. Por tanto, la cantidad de vértices de grado impar es siempre par.
- *Componentes y aristas:* cada arista que se agrega reduce el número de componentes en a lo sumo 1, así que un grafo con `n` vértices y `m` aristas tiene al menos `n − m` componentes. Un bosque con `c` componentes tiene exactamente `n − c` aristas.
- *Número ciclomático:* `m − n + c` es la cantidad mínima de aristas que hay que eliminar para que el grafo no tenga ciclos.

**Problema 36.1 — Grados** · nivel 2

- **Entrada:** `n m` y luego `m` líneas `u v` (grafo simple: sin lazos ni aristas repetidas). Límites: `1 ≤ n ≤ 2·10^5`, `0 ≤ m ≤ 2·10^5`.
- **Salida:** línea 1: los grados de los vértices `1..n`; línea 2: cuántos vértices tienen grado impar.
- **Ejemplo:** `4 4 / 1 2 / 2 3 / 3 1 / 3 4` → `2 2 3 1 / 2`.
- **Matemática:** demuestra el lema del apretón de manos y deduce que la cantidad de vértices de grado impar es par.

**Problema 36.2 — Componentes conexas** · nivel 3

- **Entrada:** igual que el 36.1.
- **Salida:** `cantidad_de_componentes tamaño_de_la_mayor`.
- **Ejemplo:** `8 4 / 1 2 / 2 3 / 4 5 / 6 7` → `4 3`.
- **Matemática:** demuestra que el número de componentes es al menos `n − m` y que la igualdad ocurre si y solo si el grafo no tiene ciclos.

**Problema 36.3 — Aristas sobrantes** · nivel 4

- **Entrada:** igual que el 36.1.
- **Salida:** dos líneas. La primera, `k`: el mínimo de aristas que hay que eliminar para que el grafo no tenga ciclos. La segunda: `ARBOL` si el grafo es conexo y `k = 0`; `BOSQUE` si `k = 0` pero no es conexo; `CON CICLOS` si `k > 0`.
- **Ejemplo:** `5 5 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5` → `1 / CON CICLOS`; `4 3 / 1 2 / 2 3 / 3 4` → `0 / ARBOL`; `5 3 / 1 2 / 2 3 / 4 5` → `0 / BOSQUE`.
- **Matemática:** demuestra que `k = m − n + c`. Cota inferior: un bosque con `c'` componentes tiene `n − c'` aristas y eliminar aristas nunca reduce las componentes (`c' ≥ c`), así que quedan a lo sumo `n − c` aristas. Alcanzable: elimina solo aristas que están en algún ciclo (no desconectan).

**Proyecto del día — Analizador de redes sociales**

- **Entrada:** `n m` y `m` amistades `u v` (grafo simple). Límites: `1 ≤ n, m ≤ 2·10^5`.
- **Salida (cinco líneas):** `componentes: C`; `tamanos: s1 s2 …` (de mayor a menor); `mayor_grado: v d` (el vértice de mayor grado, con el menor número en empates, y su grado); `aislados: A` (vértices sin amigos); `ciclo: v1 v2 … vk` con cualquier ciclo válido (cada vértice adyacente al siguiente y el último al primero, `k ≥ 3`, sin repetir vértices) o `ciclo: ninguno`.
- **Ejemplo:** `8 6 / 1 2 / 2 3 / 3 1 / 4 5 / 6 7 / 7 8` → `componentes: 3 / tamanos: 3 3 2 / mayor_grado: 1 2 / aislados: 0 / ciclo: 1 2 3`.
- **Pista del ciclo:** en el árbol de un recorrido (DFS o BFS), toda arista que no es del árbol cierra un ciclo con el camino del árbol entre sus extremos; sube por los padres desde ambos extremos hasta el ancestro común.
- **Qué reviso:** recorrido sin desbordar la pila, costo `O(n + m)`, el ciclo (lo verifico contra tus aristas) y el formato exacto.
- **Entrega:** `d36.cpp` y `d36_notas.md`.

### Día 37 · lunes 7 de diciembre · BFS: caminos más cortos sin pesos

**Teoría desde cero.** El **recorrido en anchura (BFS)** visita los vértices por "capas": primero la fuente, luego sus vecinos, luego los vecinos de esos, y así sucesivamente. Usa una **cola**. Como cada arista cuesta 1, la primera vez que llegas a un vértice es con el camino **más corto**.

```cpp
vector<int> dist(n + 1, -1), padre(n + 1, 0);
queue<int> q;
dist[s] = 0; q.push(s);
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        padre[v] = u;                    // sirve para reconstruir el camino
        q.push(v);
    }
}
```

- **Cuadrículas:** cada celda libre es un vértice y los vecinos son las 4 (u 8) celdas contiguas; usa los arreglos `dx`, `dy` del Día 11.
- **BFS multifuente:** mete en la cola, desde el inicio, **todas** las fuentes con distancia 0. Calcula la distancia a la fuente más cercana de cada vértice en una sola pasada.
- **Reconstruir un camino:** parte del destino y sigue `padre` hasta la fuente; luego invierte.

**Matemática del día.** *Corrección de BFS:* por inducción sobre `d`, la cola siempre contiene vértices con distancia `d` seguidos de vértices con distancia `d + 1`, en ese orden; así se visitan en orden no decreciente de distancia y la primera vez que se alcanza un vértice es con su distancia mínima. *Costo:* `O(n + m)`; en una cuadrícula, `O(n·m)`.

**Problema 37.1 — Distancias desde un vértice** · nivel 3

- **Entrada:** `n m` y `m` aristas no dirigidas `u v`, con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `n` enteros: la distancia mínima (en aristas) desde el vértice 1 a cada vértice, o `-1` si no se puede llegar.
- **Ejemplo:** `5 4 / 1 2 / 2 3 / 1 4 / 4 3` → `0 1 2 1 -1`.
- **Matemática:** demuestra el invariante de la cola (capas `d` y `d + 1`) y deduce que BFS entrega distancias mínimas.

**Problema 37.2 — Distancia al cero más cercano** · nivel 4

- **Entrada:** `n m` y una matriz de 0 y 1 con al menos un 0, con `1 ≤ n, m ≤ 1000`.
- **Salida:** una matriz con, para cada celda, la menor cantidad de movimientos (arriba, abajo, izquierda, derecha) hasta una celda con 0.
- **Ejemplo:** `3 3 / 0 0 0 / 0 1 0 / 1 1 1` → `0 0 0 / 0 1 0 / 1 2 1`.
- **Matemática:** explica por qué iniciar con todos los ceros en la cola equivale a una BFS desde un vértice virtual unido a todos los ceros, y por qué una BFS desde cada celda costaría `O((n·m)²)`.

**Problema 37.3 — Escape del fuego** · nivel 6

En una cuadrícula hay muros `#`, celdas libres `.`, una persona `S` y cero o más focos de fuego `F`. Cada minuto, el fuego se extiende a las 4 celdas contiguas que no sean muro. Sea `f(c)` el minuto en que el fuego llega a la celda `c` (0 para los focos, infinito si nunca llega). La persona empieza en `S` en el minuto 0 y cada minuto se mueve a una celda contigua que no sea muro; estar en la celda `c` en el minuto `t` exige `t < f(c)`. Escapa al llegar a una celda del borde de la cuadrícula (si `S` ya está en el borde, escapa en el minuto 0).

- **Entrada:** `n m` y `n` filas con `.`, `#`, `S` y `F`, con `1 ≤ n, m ≤ 1000` y exactamente una `S`.
- **Salida:** el menor minuto en que puede escapar, o `IMPOSIBLE`.
- **Ejemplo:** `5 6 / .#..## / .F#.## / ...... / ##S.#. / .####.` → `4`; `4 5 / ####. / #S.F. / #...# / #####` → `IMPOSIBLE`.
- **Matemática:** calcula `f` con una BFS multifuente y luego una BFS de la persona que solo entra a `c` si `t < f(c)`. Justifica por qué esperar nunca ayuda (el fuego solo se extiende) y por qué bastan dos BFS: `O(n·m)`. En el primer ejemplo, ¿por qué el camino de 3 movimientos hacia la izquierda no sirve?

**Proyecto del día — Resolutor de laberintos**

- **Entrada:** `n m` y `n` filas con `.`, `#`, `S` y `E` (una de cada una de las dos últimas), con `1 ≤ n, m ≤ 1000`.
- **Salida:** si hay camino, la longitud mínima `L` en la primera línea y después el laberinto con el camino dibujado con `*` (sin tapar `S` ni `E`). Si hay varios caminos mínimos, dibuja el **lexicográficamente menor** como cadena de movimientos, con el orden `D < L < R < U` (abajo, izquierda, derecha, arriba). Si no hay camino, `SIN CAMINO`.
- **Ejemplo:** `3 4 / S..# / .#.. / ...E` → `5 / S..# / *#.. / ***E`.
- **Qué reviso:** BFS que explora las direcciones en el orden `D, L, R, U`, reconstrucción con padres y formato exacto.
- **Notas:** demuestra que ese orden de exploración entrega el camino lexicográficamente menor (por inducción sobre capas: las celdas de una capa salen de la cola en el orden de su camino mínimo menor).
- **Entrega:** `d37.cpp` y `d37_notas.md`.

### Día 38 · martes 8 de diciembre · BFS avanzado: grafos bipartitos, 0-1 BFS y estados

**Teoría desde cero.**

**BFS sobre un grafo implícito.** No siempre te dan el grafo: a veces los vértices son *situaciones* y las aristas *movimientos permitidos*. Los saltos de un caballo de ajedrez, los estados de un candado o de un rompecabezas se resuelven igual que un laberinto: BFS sobre estados. Lo importante es poder (1) codificar un estado y (2) generar sus vecinos.

**Grafo bipartito.** Un grafo es bipartito si sus vértices se pueden pintar con **dos colores** de modo que cada arista una colores distintos. Con BFS: pinta la fuente con 1; a cada vecino sin pintar dale el color contrario; si algún vecino ya tiene tu mismo color, no es bipartito.

**0-1 BFS.** Si las aristas cuestan 0 o 1, un BFS normal falla. Usa un `deque`: las aristas de costo 0 insertan por el **frente** y las de costo 1 por el **final**.

```cpp
deque<int> dq;
dist[s] = 0; dq.push_front(s);
while (!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    for (auto [v, w] : g[u])                   // w es 0 o 1
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            if (w == 0) dq.push_front(v); else dq.push_back(v);
        }
}
```

**Matemática del día.**

- *Bipartito si y solo si no hay ciclos impares.* (⇒) En un ciclo los colores se alternan, así que el ciclo tiene longitud par. (⇐) Pinta cada vértice según la paridad de su distancia BFS a la raíz de su componente; si una arista uniera dos vértices del mismo color, los dos caminos del árbol hasta su ancestro común más esa arista formarían un ciclo de longitud impar.
- *Paridad en el caballo:* cada salto cambia el color de la casilla (`fila + columna` cambia de paridad), así que ir de una casilla a otra del mismo color exige una cantidad **par** de saltos.
- *Invariante del 0-1 BFS:* el deque siempre tiene vértices con distancia `d` al frente seguidos de vértices con distancia `d + 1`.

**Problema 38.1 — Caballo** · nivel 3

- **Entrada:** una línea `n r1 c1 r2 c2`: un tablero `n × n` y dos casillas, con `1 ≤ n ≤ 1000`.
- **Salida:** la mínima cantidad de saltos de caballo entre ambas casillas, o `-1`.
- **Ejemplo:** `8 1 1 8 8` → `6`; `3 1 1 2 2` → `-1`.
- **Matemática:** usa el argumento de paridad para explicar por qué el primer ejemplo da un número par, y justifica por qué en un tablero `3 × 3` la casilla central es inalcanzable (y no se puede salir de ella).

**Problema 38.2 — ¿Es bipartito?** · nivel 4

- **Entrada:** `n m` y `m` aristas no dirigidas, con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `NO`; o `SI` y, en la línea siguiente, `n` valores `1` o `2` (los colores). Para que sea único, recorre las componentes empezando por su vértice menor, que recibe el color 1.
- **Ejemplo:** `4 4 / 1 2 / 2 3 / 3 4 / 4 1` → `SI / 1 2 1 2`; `3 3 / 1 2 / 2 3 / 3 1` → `NO`.
- **Matemática:** demuestra la caracterización por ciclos impares.

**Problema 38.3 — Romper muros** · nivel 5

- **Entrada:** `n m` y una cuadrícula de `.` y `#` donde `(1,1)` y `(n,m)` son `.`, con `1 ≤ n, m ≤ 1000`.
- **Salida:** la mínima cantidad de celdas `#` por las que hay que pasar (romperlas) para ir de `(1,1)` a `(n,m)` moviéndote en las 4 direcciones.
- **Ejemplo:** `3 3 / .#. / ### / .#.` → `2`.
- **Matemática:** entrar a `.` cuesta 0 y entrar a `#` cuesta 1. Demuestra el invariante del deque y por qué cada celda se saca a lo sumo una vez con su distancia final.

**Proyecto del día — Asignador de equipos**

Un organizador quiere repartir `n` personas en dos equipos, sin que dos personas en conflicto queden en el mismo.

- **Entrada:** `n m` y `m` conflictos `u v`, con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** si es posible, dos líneas `equipo 1: …` y `equipo 2: …` con los números de las personas en orden creciente (usa la coloración del Problema 38.2; si un equipo queda vacío, la línea termina en `:`). Si no, `IMPOSIBLE` y una línea `ciclo: v1 v2 … vk` con un **ciclo de longitud impar** (cada vértice adyacente al siguiente y el último al primero).
- **Ejemplo:** `5 4 / 1 2 / 2 3 / 3 4 / 4 5` → `equipo 1: 1 3 5 / equipo 2: 2 4`; `3 3 / 1 2 / 2 3 / 3 1` → `IMPOSIBLE / ciclo: 1 2 3`.
- **Qué reviso:** coloración con BFS, certificado del ciclo (cuando una arista `u–v` une dos vértices del mismo color, sube por los padres de ambos hasta el ancestro común) y formato.
- **Notas:** demuestra que ese ciclo tiene longitud impar: `dist(u) ≡ dist(v) (mod 2)`, así que `dist(u) + dist(v) − 2·dist(lca) + 1` es impar.
- **Entrega:** `d38.cpp` y `d38_notas.md`.

### Día 39 · miércoles 9 de diciembre · Orden topológico y DP en grafos acíclicos dirigidos

**Teoría desde cero.** Un **DAG** es un grafo dirigido sin ciclos. Modela dependencias: "el curso `a` es prerrequisito de `b`", "la tarea `u` debe terminar antes que `v`". Un **orden topológico** coloca todos los vértices en fila de modo que toda arista `u→v` tenga `u` antes que `v`.

**Algoritmo de Kahn.** Cuenta el **grado de entrada** de cada vértice (cuántas aristas llegan). Los de grado 0 no dependen de nadie: sácalos, quita sus aristas salientes (baja el grado de sus vecinos) y repite.

```cpp
vector<int> gin(n + 1, 0), orden;
for (int u = 1; u <= n; u++) for (int v : g[u]) gin[v]++;
queue<int> q;
for (int i = 1; i <= n; i++) if (gin[i] == 0) q.push(i);
while (!q.empty()) {
    int u = q.front(); q.pop();
    orden.push_back(u);
    for (int v : g[u]) if (--gin[v] == 0) q.push(v);
}
// si orden.size() < n, el grafo tiene al menos un ciclo
```

Para el orden lexicográficamente menor, cambia la cola por un `priority_queue` de mínimo.

**DP en un DAG.** Recorre los vértices en orden topológico: cuando llegas a `v`, todos sus predecesores ya tienen su valor final. Ejemplos: `largo[v] = 1 + max largo[u]` (camino más largo) y `formas[v] = Σ formas[u]` (cantidad de caminos).

**Matemática del día.** *Un DAG siempre tiene un vértice de grado de entrada 0:* si todos tuvieran una arista entrante, podrías caminar hacia atrás indefinidamente y, como hay finitos vértices, repetirías uno, formando un ciclo. Quitar ese vértice deja otro DAG; por inducción existe un orden topológico. Y viceversa: si hay un ciclo, ninguno de sus vértices llega a grado 0. *Corrección de la DP:* por el orden, el valor de `v` solo usa valores ya calculados.

**Problema 39.1 — Semestres mínimos** · nivel 4

- **Entrada:** `n m` y `m` líneas `a b` ("el curso `a` es prerrequisito de `b`"), con `1 ≤ n, m ≤ 2·10^5`. En cada semestre puedes llevar todos los cursos cuyos prerrequisitos ya aprobaste en semestres anteriores.
- **Salida:** la mínima cantidad de semestres para aprobar todos, o `-1` si es imposible.
- **Ejemplo:** `5 4 / 1 2 / 1 3 / 2 4 / 3 4` → `3`.
- **Matemática:** demuestra que el semestre de `v` es `1 + max(semestre de sus prerrequisitos)` y que la respuesta es la cantidad de vértices del camino más largo.

**Problema 39.2 — Orden topológico menor** · nivel 4

- **Entrada:** igual que el 39.1.
- **Salida:** el orden topológico lexicográficamente menor (como sucesión de vértices), o `IMPOSIBLE`.
- **Ejemplo:** `5 4 / 3 1 / 3 2 / 1 4 / 5 4` → `3 1 2 5 4`.
- **Matemática:** demuestra que elegir siempre el menor vértice disponible (grado de entrada 0) produce el menor orden posible, y que si al terminar quedan vértices sin sacar, hay un ciclo.

**Problema 39.3 — Caminos en un DAG** · nivel 5

- **Entrada:** `n m` y `m` aristas dirigidas `u v`. El grafo es acíclico. Límites: `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `caminos largo`: la cantidad de caminos distintos de 1 a `n` (módulo `10^9 + 7`) y la mayor cantidad de aristas de un camino de 1 a `n`; si no hay camino, `0 -1`.
- **Ejemplo:** `4 5 / 1 2 / 1 3 / 2 3 / 2 4 / 3 4` → `3 3`.
- **Matemática:** `formas[1] = 1`, `formas[v] = Σ formas[u]` sobre las aristas `u→v`. Para `largo`, usa solo vértices alcanzables desde 1. Explica por qué el orden topológico garantiza que los predecesores están listos.

**Proyecto del día — Planificador de cursos**

- **Entrada:** `n m` y `m` aristas `a b` (prerrequisitos), con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** si hay un ciclo, `CICLO: v1 v2 … vk` con un ciclo válido (cada `v_i → v_{i+1}` es una arista y `v_k → v_1` también). Si no, `semestres: S` y luego `S` líneas `k: ids` con los cursos del semestre `k` en orden creciente (cada curso en el primer semestre posible).
- **Ejemplo:** `5 4 / 1 2 / 1 3 / 2 4 / 3 4` → `semestres: 3 / 1: 1 5 / 2: 2 3 / 3: 4`.
- **Qué reviso:** Kahn por capas, detección del ciclo y su extracción: entre los vértices sin procesar, cada uno tiene un predecesor sin procesar; camina hacia atrás hasta repetir un vértice y luego invierte el orden.
- **Notas:** demuestra que ese recorrido hacia atrás siempre termina en un ciclo.
- **Entrega:** `d39.cpp` y `d39_notas.md`.

### Día 40 · jueves 10 de diciembre · Conjuntos disjuntos (DSU)

**Teoría desde cero.** Una estructura de **conjuntos disjuntos** (DSU, *union-find*) mantiene una partición de `1..n` en grupos y responde dos operaciones casi en `O(1)`:

- `find(x)`: ¿cuál es el representante (raíz) del grupo de `x`?
- `unite(a, b)`: fusiona los grupos de `a` y `b`.

Cada grupo es un árbol; `p[x]` es el padre de `x` y la raíz cumple `p[x] = x`. Dos mejoras clave: **compresión de caminos** (en `find`, cuelga cada vértice visitado directamente de la raíz) y **unión por tamaño** (cuelga el árbol pequeño del grande).

```cpp
struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;           // ya estaban juntos
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};
```

**DSU con paridad.** Para relaciones "mismo grupo / grupos distintos" entre dos clases, guarda en `d[x]` la paridad de `x` respecto a su padre (0 = igual, 1 = distinto):

```cpp
pair<int,int> find(int x) {                 // (raíz, paridad de x respecto a la raíz)
    if (p[x] == x) return {x, 0};
    auto [r, dr] = find(p[x]);
    p[x] = r; d[x] ^= dr;
    return {r, d[x]};
}
// al fusionar a y b con relación r: si las raíces ya son iguales, la relación es
// consistente si y solo si pa ^ pb == r; si no, p[ra] = rb y d[ra] = pa ^ pb ^ r
```

**Matemática del día.** *Altura con unión por tamaño:* cada vez que la profundidad de un vértice aumenta, su árbol se cuelga de otro de tamaño mayor o igual, así que el tamaño de su grupo al menos se duplica; como el tamaño no pasa de `n`, la profundidad es a lo sumo `log2(n)`. Con compresión de caminos además, el costo amortizado por operación es `O(α(n))` (inversa de Ackermann, menor que 5 para cualquier `n` real).

**Problema 40.1 — Conectividad dinámica** · nivel 3

- **Entrada:** `n q` y `q` líneas `t u v`: si `t = 1`, une `u` y `v`; si `t = 2`, pregunta si están conectados. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** `SI` o `NO` por cada pregunta.
- **Ejemplo:** `5 6 / 1 1 2 / 2 1 2 / 2 1 3 / 1 2 3 / 2 1 3 / 2 4 5` → `SI / NO / SI / NO`.
- **Matemática:** demuestra que "estar conectados" es una relación de equivalencia y que la raíz es un representante canónico.

**Problema 40.2 — Componentes tras cada arista** · nivel 4

- **Entrada:** `n m` y `m` aristas que se agregan en orden. Límites: `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `m` líneas; tras agregar cada arista, `cantidad_de_componentes tamaño_de_la_mayor`.
- **Ejemplo:** `5 4 / 1 2 / 2 3 / 1 3 / 4 5` → `4 2 / 3 3 / 3 3 / 2 3`.
- **Matemática:** una arista reduce el número de componentes en 1 si y solo si une dos componentes distintas. Demuestra que la mayor componente solo puede cambiar al fusionar.

**Problema 40.3 — Amigos y enemigos** · nivel 6

Hay `n` personas y dos grupos posibles. Llegan afirmaciones `S a b` ("`a` y `b` están en el mismo grupo") y `D a b` ("están en grupos distintos"). Cada afirmación se acepta si es compatible con **todas las aceptadas antes**; si no, se rechaza (y se ignora a partir de ahí).

- **Entrada:** `n q` y `q` líneas `t a b` con `t` en `S`/`D` y `a ≠ b`. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** `OK` o `CONTRADICCION` por cada afirmación.
- **Ejemplo:** `4 5 / D 1 2 / D 2 3 / S 1 3 / D 1 3 / S 1 4` → `OK / OK / OK / CONTRADICCION / OK`.
- **Matemática:** con paridades respecto a la raíz, la relación entre dos elementos del mismo conjunto queda determinada; una afirmación nueva con relación `r` es contradictoria si y solo si `pa ^ pb ≠ r`. Deduce el valor de `d[ra]` al fusionar.

**Proyecto del día — Red de computadoras**

Una oficina instala cables entre `n` computadoras, uno por uno.

- **Entrada:** `n m` y `m` cables `u v` en el orden en que se instalan. Límites: `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** tres líneas: (1) el número del cable tras el cual toda la red queda conectada (o `-1` si nunca); (2) cuántos cables fueron **redundantes** (unían computadoras que ya estaban conectadas); (3) los tamaños finales de los grupos, de mayor a menor.
- **Ejemplo:** `5 6 / 1 2 / 2 3 / 1 3 / 3 4 / 4 5 / 1 5` → `5 / 2 / 5`.
- **Qué reviso:** DSU con compresión y unión por tamaño, y que todo cueste `O(m · α(n))`.
- **Notas:** demuestra que los cables no redundantes forman un bosque y que su cantidad es `n − (componentes finales)`.
- **Entrega:** `d40.cpp` y `d40_notas.md`.

### Día 41 · viernes 11 de diciembre · Árbol de expansión mínima

**Teoría desde cero.** Un **árbol de expansión** de un grafo conexo es un subconjunto de `n − 1` aristas que conecta todos los vértices sin formar ciclos. En un grafo con pesos, el **árbol de expansión mínima** (MST) es el de menor peso total.

**Algoritmo de Kruskal.** Ordena las aristas de menor a mayor peso y agrega cada una si une dos componentes distintas (usa un DSU).

```cpp
sort(aristas.begin(), aristas.end());              // (peso, u, v)
long long total = 0; int usadas = 0;
for (auto [w, u, v] : aristas)
    if (dsu.unite(u, v)) { total += w; usadas++; }
// si usadas < n - 1, el grafo no es conexo
```

Costo `O(m log m)`. (El algoritmo de Prim con un `priority_queue` es la alternativa; produce el mismo peso.)

**Matemática del día.**

- *Propiedad del corte:* si divides los vértices en dos grupos no vacíos, la arista más liviana que cruza el corte pertenece a algún MST. Prueba: si un MST `T` no la contiene, agrégala a `T`; aparece un ciclo que cruza el corte por otra arista `f` con peso `≥`; cambiar `f` por la arista liviana no aumenta el peso.
- *Corrección de Kruskal:* cuando elige una arista que une las componentes `A` y `B`, esa es la más liviana entre las que quedan que salen de `A`, así que por la propiedad del corte es segura.
- *Propiedad del ciclo:* en cualquier ciclo, una arista estrictamente más pesada que todas las demás del ciclo no está en ningún MST.
- *Camino de cuello de botella:* para dos vértices `u, v`, un camino que minimiza la arista **máxima** puede tomarse dentro del MST.

**Problema 41.1 — Árbol de expansión mínima** · nivel 4

- **Entrada:** `n m` y `m` aristas `u v w`, con `1 ≤ n, m ≤ 2·10^5` y `1 ≤ w ≤ 10^9`.
- **Salida:** el peso del MST, o `IMPOSIBLE` si el grafo no es conexo.
- **Ejemplo:** `4 5 / 1 2 1 / 2 3 2 / 3 4 3 / 4 1 4 / 1 3 5` → `6`.
- **Matemática:** demuestra la corrección de Kruskal con la propiedad del corte y acota la respuesta (`≤ (n − 1)·10^9`).

**Problema 41.2 — Camino de cuello de botella** · nivel 5

- **Entrada:** `n m q`; `m` aristas `u v w`; luego `q` consultas `u v`. Límites: `1 ≤ n ≤ 2000`, `1 ≤ m ≤ 2·10^4`, `1 ≤ q ≤ 10^4`, `1 ≤ w ≤ 10^9`.
- **Salida:** para cada consulta, el menor valor posible de la arista **más pesada** de un camino entre `u` y `v` (0 si `u = v`, `-1` si no están conectados).
- **Ejemplo:** `4 5 3 / 1 2 1 / 2 3 2 / 3 4 3 / 4 1 4 / 1 3 5 / 1 4 / 2 4 / 1 1` → `3 / 3 / 0`.
- **Matemática:** demuestra que basta mirar el camino único del MST: si un camino óptimo usara una arista `e` fuera del MST, `e` sería la más pesada del ciclo que forma con el camino del MST y se podría reemplazar sin empeorar el máximo.

**Problema 41.3 — Pozos y caminos** · nivel 6

Un pueblo tiene `n` ciudades. Construir un pozo en la ciudad `i` cuesta `c_i`; construir un camino entre dos ciudades cuesta lo que indique la lista. Cada ciudad debe tener un pozo o estar unida por caminos con una ciudad que lo tenga. Minimiza el costo total.

- **Entrada:** `n m`; `c_1 … c_n`; luego `m` líneas `u v w`. Límites: `1 ≤ n, m ≤ 2·10^5`, todos los costos entre 1 y `10^9`.
- **Salida:** el costo mínimo.
- **Ejemplo:** `3 2 / 4 5 6 / 1 2 1 / 2 3 2` → `7` (un pozo en la ciudad 1 y dos caminos).
- **Matemática:** agrega un vértice `0` con una arista `0–i` de costo `c_i` para cada ciudad. Demuestra que las configuraciones válidas de costo mínimo son exactamente los árboles de expansión del grafo ampliado (cada componente de caminos tiene exactamente un pozo en una solución óptima), y por tanto la respuesta es el peso de un MST.

**Proyecto del día — Segundo mejor árbol**

Un ingeniero quiere conocer el MST y el "plan B": el árbol de expansión más barato que **no** sea el hallado.

- **Entrada:** `n m` y `m` aristas `u v w`, con `2 ≤ n ≤ 200`, `n − 1 ≤ m ≤ 2000`, `1 ≤ w ≤ 10^6`. El grafo es conexo.
- **Salida:** `mst segundo`: el peso del MST de Kruskal y el menor peso entre los árboles de expansión **distintos** del hallado (`-1` si no existe otro). Si hay empates y existe otro MST del mismo peso, `segundo = mst`.
- **Ejemplo:** `4 5 / 1 2 1 / 2 3 2 / 3 4 3 / 4 1 4 / 1 3 5` → `6 7`.
- **Idea:** todo árbol distinto del hallado `T` omite alguna arista de `T`; por tanto el segundo mejor es el mínimo, sobre las aristas `e` de `T`, del MST del grafo sin `e`.
- **Qué reviso:** el uso de la idea anterior (`n − 1` reconstrucciones de `O(m α(n))`), y una **prueba de estrés** contra una fuerza bruta que enumere todos los árboles de expansión para `n ≤ 6` y `m ≤ 9`.
- **Notas:** demuestra el argumento "todo árbol distinto omite una arista de `T`".
- **Entrega:** `d41.cpp` y `d41_notas.md`.

### Día 42 · sábado 12 de diciembre · Repaso de la semana 6 y pruebas de estrés

**Teoría: ¿qué herramienta de grafos uso?**

- **Componentes, ciclos, marcar zonas:** DFS o BFS.
- **Distancia mínima con aristas sin peso (o con peso 0/1):** BFS (0-1 BFS).
- **Dos colores / emparejar bandos:** BFS con coloración.
- **Dependencias, orden de ejecución, caminos en un DAG:** orden topológico.
- **Fusionar grupos y preguntar si están juntos:** DSU.
- **Conectar todo al menor costo:** Kruskal o Prim.

**Problema 42.1 — Islas** · nivel 3

- **Entrada:** `n m` y una cuadrícula de `#` (tierra) y `.` (agua), con `1 ≤ n, m ≤ 1000`. Dos celdas de tierra son de la misma isla si están conectadas por movimientos en las 4 direcciones.
- **Salida:** `cantidad_de_islas area_de_la_mayor`.
- **Ejemplo:** `4 5 / ##..# / #...# / ..#.. / #..##` → `5 3`.
- **Matemática:** cada isla es una componente conexa del grafo de celdas de tierra; justifica que cada celda se visita una sola vez y el costo es `O(n·m)`.

**Problema 42.2 — Líderes de grupo** · nivel 4

- **Entrada:** `n m` y `m` amistades `u v`, con `1 ≤ n, m ≤ 2·10^5`. Cada grupo de amigos (componente conexa) debe elegir un líder.
- **Salida:** de cuántas maneras se pueden elegir los líderes, módulo `10^9 + 7`.
- **Ejemplo:** `6 3 / 1 2 / 2 3 / 4 5` → `6`.
- **Matemática:** por el principio del producto, la respuesta es el producto de los tamaños de las componentes. Acota el crecimiento (el máximo para `n` personas es del orden de `3^(n/3)`) para justificar el módulo.

**Problema 42.3 — Separación máxima en k grupos** · nivel 5

Divide los vértices en exactamente `k` grupos no vacíos. La **separación** de una división es el menor peso entre las aristas que unen grupos distintos. Halla la mayor separación posible.

- **Entrada:** `n m k`; luego `m` aristas `u v w`. El grafo es conexo. Límites: `2 ≤ k ≤ n ≤ 2·10^5`, `1 ≤ m ≤ 2·10^5`, `1 ≤ w ≤ 10^9`.
- **Salida:** la mayor separación.
- **Ejemplo:** `5 6 2 / 1 2 1 / 2 3 2 / 3 4 10 / 4 5 1 / 1 5 12 / 2 4 9` → `9`.
- **Matemática:** ejecuta Kruskal hasta que queden `k` componentes; la respuesta es el peso de la primera arista posterior que une componentes distintas. Demuestra que ninguna otra división en `k` grupos tiene mayor separación: si una división `P` es distinta de la de Kruskal, alguna componente de Kruskal tiene dos vértices en grupos distintos de `P`; el camino de Kruskal entre ellos usa solo aristas de peso `≤` la respuesta y alguna de ellas cruza grupos de `P`.

**Proyecto del día — Pruebas de estrés de la semana**

Un único programa con cuatro comparaciones aleatorias (semilla fija, 2000 pruebas cada una); escribe `OK` por comparación o el primer contraejemplo:

1. Componentes: DSU contra DFS en grafos aleatorios con `n ≤ 12`.
2. MST: tu Kruskal contra una fuerza bruta que enumere todos los subconjuntos de `n − 1` aristas y se quede con el mejor que sea árbol (`n ≤ 6`, `m ≤ 10`).
3. Orden topológico menor: tu algoritmo contra la enumeración de todas las permutaciones válidas en DAGs aleatorios con `n ≤ 7` (genera el DAG con aristas que solo van hacia adelante en una permutación aleatoria).
4. Bipartito: tu BFS contra la prueba de todos los `2^n` coloreos para `n ≤ 10`.

- **Qué reviso:** que cada fuerza bruta sea realmente independiente, la generación correcta de entradas (grafos conexos para la 2, DAGs para la 3) y mensajes claros.
- **Notas:** una tabla con una fila por algoritmo de la semana, su complejidad y el caso borde que más te costó.
- **Entrega:** `d42.cpp` y `d42_notas.md`.

---

## Semana 7 · 13–19 dic · Caminos mínimos y árboles

**Objetivo:** calcular distancias en grafos con pesos (Dijkstra, Bellman–Ford, Floyd–Warshall), dominar los árboles (profundidades, diámetro, DP, recorrido de Euler) y responder consultas de ancestros comunes.

### Día 43 · domingo 13 de diciembre · Dijkstra

**Teoría desde cero.** En un grafo con **pesos** en las aristas, el camino más corto es el de menor suma de pesos, no el de menos aristas. Si todos los pesos son **no negativos**, el **algoritmo de Dijkstra** lo calcula en `O((n + m) log n)`. Mantiene una distancia tentativa `dist[v]` y siempre cierra el vértice abierto de menor distancia, que sale de un `priority_queue`.

```cpp
const long long INF = 4e18;
vector<long long> dist(n + 1, INF);
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
dist[s] = 0; pq.push({0, s});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;                 // entrada vieja del heap: se ignora
    for (auto [v, w] : g[u])                   // g[u] guarda pares (vecino, peso)
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});             // (y padre[v] = u para reconstruir la ruta)
        }
}
```

Con pesos hasta `10^9` y `10^5` aristas en un camino, las distancias llegan a `10^14`: usa siempre `long long`.

**Matemática del día.** *Por qué funciona:* cuando `u` sale del heap con la menor distancia tentativa `d`, esa distancia es **final**. Cualquier otro camino hacia `u` sale del conjunto de vértices ya cerrados por un vértice aún abierto, cuya distancia tentativa es `≥ d`; como los pesos no son negativos, seguir el camino no puede disminuir el total. *Con pesos negativos falla:* con aristas `1→2` (peso 2), `1→3` (peso 3) y `3→2` (peso −2), Dijkstra cierra el 2 con distancia 2, pero el camino `1→3→2` cuesta 1.

**Problema 43.1 — Distancia mínima** · nivel 4

- **Entrada:** `n m` y `m` aristas no dirigidas `u v w`, con `1 ≤ n, m ≤ 2·10^5` y `1 ≤ w ≤ 10^9`.
- **Salida:** la distancia mínima de 1 a `n`, o `-1`.
- **Ejemplo:** `5 6 / 1 2 4 / 1 3 1 / 3 2 2 / 2 4 5 / 3 4 8 / 4 5 3` → `11`.
- **Matemática:** demuestra el invariante de Dijkstra (la distancia del vértice que sale del heap es final) y acota la respuesta máxima para justificar `long long`.

**Problema 43.2 — Cupón de descuento** · nivel 5

Puedes usar **un cupón** que reduce el peso de **una** arista del camino a `floor(w/2)`.

- **Entrada:** `n m` y `m` aristas **dirigidas** `u v w`, con `1 ≤ n, m ≤ 10^5` y `1 ≤ w ≤ 10^9`.
- **Salida:** el costo mínimo de ir de 1 a `n` usando a lo sumo un cupón, o `-1` si no hay ruta.
- **Ejemplo:** `4 4 / 1 2 3 / 2 4 8 / 1 3 10 / 3 4 2` → `7`.
- **Matemática:** amplía el estado a `(vértice, cupón_usado)` (el grafo tiene `2n` vértices). Explica por qué las aristas del grafo ampliado siguen teniendo pesos no negativos y cuenta el nuevo costo.

**Problema 43.3 — Caminos mínimos: cantidad y largos** · nivel 6

- **Entrada:** `n m` y `m` aristas **dirigidas** `u v w`, con `1 ≤ n, m ≤ 10^5` y `1 ≤ w ≤ 10^9`.
- **Salida:** `distancia cantidad mínimo máximo`: la distancia mínima de 1 a `n`, cuántos caminos mínimos hay (módulo `10^9 + 7`), y el menor y el mayor número de aristas entre ellos. Si no hay camino, escribe `-1`.
- **Ejemplo:** `4 5 / 1 2 1 / 1 3 1 / 2 4 1 / 3 4 1 / 1 4 2` → `2 3 1 2`.
- **Matemática:** una arista `u→v` es **ajustada** si `dist[u] + w = dist[v]`. Con pesos positivos, las aristas ajustadas forman un DAG ordenado por `dist`; haz DP sobre él: `cantidad[v] = Σ cantidad[u]`, `mínimo[v] = 1 + min mínimo[u]`, `máximo[v] = 1 + max máximo[u]`. Explica por qué con pesos 0 esto fallaría.

**Proyecto del día — Navegador GPS**

- **Entrada:** `n m`; `m` calles `u v w` (no dirigidas); luego `q` y `q` comandos: `ruta u v` o `cerrar i` (cierra la calle número `i`, contada desde 1, para siempre). Límites: `n ≤ 1000`, `m ≤ 5000`, `q ≤ 200`, `w ≤ 10^6`.
- **Salida:** por cada `ruta`, `distancia: v1 v2 … vk` con una ruta mínima cualquiera (la verifico contra las calles) o `SIN RUTA`. Los `cerrar` no escriben nada.
- **Ejemplo:** `5 6 / 1 2 4 / 1 3 1 / 3 2 2 / 2 4 5 / 3 4 8 / 4 5 3 / 3 / ruta 1 5 / cerrar 4 / ruta 1 5` → `11: 1 3 2 4 5 / 12: 1 3 4 5`.
- **Qué reviso:** Dijkstra con reconstrucción de ruta por `padre`, `long long`, comandos de cierre aplicados en orden y el caso `u = v`.
- **Entrega:** `d43.cpp` y `d43_notas.md`.

### Día 44 · lunes 14 de diciembre · Bellman–Ford y Floyd–Warshall

**Teoría desde cero.**

**Bellman–Ford** soporta pesos **negativos**: relaja *todas* las aristas una y otra vez. Tras `i` pasadas, `dist` es correcto para los caminos de **a lo sumo `i` aristas**. Un camino mínimo sin ciclos tiene a lo más `n − 1` aristas; si en la pasada `n` todavía mejora algo, existe un **ciclo negativo**.

```cpp
vector<long long> d(n + 1, 0);              // todo en 0: detecta ciclos negativos en cualquier parte
bool ciclo = false;
for (int it = 1; it <= n; it++) {
    bool cambio = false;
    for (auto [u, v, w] : aristas)
        if (d[u] + w < d[v]) { d[v] = d[u] + w; cambio = true; }
    if (!cambio) break;
    if (it == n) ciclo = true;
}
```

**Floyd–Warshall** calcula la distancia entre **todas las parejas** en `O(n^3)` (sirve para `n` hasta unos 400). El orden de los ciclos importa: `k` va **afuera**.

```cpp
for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
```

Si al terminar algún `d[i][i] < 0`, hay un ciclo negativo.

**Matemática del día.** *Bellman–Ford:* por inducción sobre `i`, tras la pasada `i` el valor `d[v]` es a lo sumo el mejor camino de `≤ i` aristas hasta `v`. *Floyd–Warshall:* tras procesar `k`, `d[i][j]` es la mejor distancia usando como vértices intermedios solo `{1, …, k}`: o el camino no usa `k`, o pasa por `k` una vez y se parte en `i → k` y `k → j`.

**Problema 44.1 — Todas las parejas** · nivel 4

- **Entrada:** `n m q`; `m` aristas dirigidas `u v w`; `q` consultas `u v`. Límites: `1 ≤ n ≤ 400`, `1 ≤ m ≤ 10^5`, `1 ≤ q ≤ 10^5`, `0 ≤ w ≤ 10^9`. Puede haber aristas repetidas (conserva la menor).
- **Salida:** la distancia mínima de `u` a `v` o `-1`.
- **Ejemplo:** `3 3 2 / 1 2 4 / 2 3 5 / 1 3 10 / 1 3 / 3 1` → `9 / -1`.
- **Matemática:** demuestra el invariante de Floyd–Warshall y acota la distancia máxima (`399 · 10^9`).

**Problema 44.2 — ¿Hay un ciclo negativo?** · nivel 5

- **Entrada:** `n m` y `m` aristas dirigidas `u v w`, con `1 ≤ n ≤ 2500`, `1 ≤ m ≤ 5000` y `|w| ≤ 10^9`.
- **Salida:** `SI` si en **algún** lugar del grafo existe un ciclo de peso total negativo; si no, `NO`.
- **Ejemplo:** `4 4 / 1 2 1 / 2 3 -1 / 3 4 -1 / 4 2 -1` → `SI`; `3 3 / 1 2 5 / 2 3 -2 / 1 3 4` → `NO`.
- **Matemática:** explica por qué inicializar todas las distancias en 0 equivale a añadir un vértice fuente con aristas de peso 0 hacia todos, y por qué entonces bastan `n` pasadas.

**Problema 44.3 — A lo más K aristas** · nivel 5

- **Entrada:** `n m K` y `m` aristas dirigidas `u v w`, con `2 ≤ n ≤ 500`, `1 ≤ m ≤ 5000`, `1 ≤ K ≤ 500` y `|w| ≤ 10^6`. No hay ciclos negativos alcanzables desde 1.
- **Salida:** el menor costo de un camino de 1 a `n` con **a lo más** `K` aristas, o `-1`.
- **Ejemplo:** `4 4 2 / 1 2 1 / 2 3 1 / 3 4 1 / 1 4 5` → `5`; con `K = 3` → `3`.
- **Matemática:** haz `K` rondas de Bellman–Ford usando una **copia** de `d` de la ronda anterior (si relajas sobre el mismo arreglo, podrías usar más de una arista por ronda). Explica por qué.

**Proyecto del día — Tabla de rutas**

- **Entrada:** `n m`; `m` vuelos dirigidos `u v w`; luego `q` consultas `u v`. Límites: `1 ≤ n ≤ 300`, `0 ≤ w ≤ 10^6`.
- **Salida:** la matriz `n × n` de costos mínimos (`-1` si no hay ruta, 0 en la diagonal); `centro: c`, la ciudad con menor suma de distancias a las demás entre las que **alcanzan a todas** (menor número en empates; `NINGUNO` si no hay); `diametro: D`, la mayor distancia finita entre dos ciudades; y por cada consulta `distancia: v1 … vk` (ruta mínima cualquiera) o `SIN RUTA`.
- **Ejemplo:** `3 4 / 1 2 1 / 2 1 1 / 2 3 2 / 3 2 2 / 1 / 1 3` → `0 1 3 / 1 0 2 / 3 2 0 / centro: 2 / diametro: 3 / 3: 1 2 3`.
- **Qué reviso:** Floyd–Warshall con `INF` sin desbordar, la matriz `sig[i][j]` para reconstruir rutas y el formato.
- **Entrega:** `d44.cpp` y `d44_notas.md`.

### Día 45 · martes 15 de diciembre · Árboles: profundidad, diámetro y contribución de aristas

**Teoría desde cero.** Un **árbol** con `n` vértices tiene `n − 1` aristas y exactamente **un camino** entre cada par de vértices. Si eliges una **raíz**, cada vértice (salvo la raíz) tiene un **padre**; sus vecinos restantes son sus **hijos**. Conceptos: **profundidad** (distancia a la raíz), **subárbol** de `v` (`v` y todos sus descendientes) y **hoja** (vértice sin hijos).

Con `n` grande conviene recorrer el árbol sin recursión:

```cpp
vector<int> padre(n + 1, 0), prof(n + 1, 0), orden;
vector<int> pila = {1};
while (!pila.empty()) {
    int u = pila.back(); pila.pop_back();
    orden.push_back(u);                           // los padres aparecen antes que los hijos
    for (int v : g[u]) if (v != padre[u]) {
        padre[v] = u; prof[v] = prof[u] + 1; pila.push_back(v);
    }
}
vector<int> tam(n + 1, 1);                        // tamaño de subárbol: recorre 'orden' al revés
for (int i = n - 1; i > 0; i--) tam[padre[orden[i]]] += tam[orden[i]];
```

**Diámetro** (camino más largo): haz un recorrido desde cualquier vértice, toma el más lejano `a`, haz otro recorrido desde `a` y el más lejano `b`; la distancia `a–b` es el diámetro.

**Matemática del día.**

- *Contribución de cada arista:* al quitar la arista `(padre, hijo)` el árbol se parte en `tam[hijo]` y `n − tam[hijo]` vértices. Esa arista aparece en exactamente `tam[hijo]·(n − tam[hijo])` caminos entre pares. Por eso `Σ_{u<v} dist(u, v) = Σ_aristas w · tam · (n − tam)`.
- *Diámetro:* el vértice más lejano de cualquier vértice es un extremo de algún diámetro (si el camino hacia él no usara el diámetro, podrías cambiarlo por uno más largo sin reducir su longitud, contradiciendo que es el más lejano).

**Problema 45.1 — Profundidades y tamaños** · nivel 3

- **Entrada:** `n` y `n − 1` aristas, con `1 ≤ n ≤ 2·10^5`. La raíz es 1.
- **Salida:** dos líneas: la profundidad de cada vértice (la raíz tiene 0) y el tamaño del subárbol de cada vértice.
- **Ejemplo:** `5 / 1 2 / 1 3 / 3 4 / 3 5` → `0 1 1 2 2 / 5 1 3 1 1`.
- **Matemática:** demuestra que `tam[v] = 1 + Σ tam[hijos]` y que recorrer `orden` al revés calcula todos los tamaños sin recursión.

**Problema 45.2 — Diámetro** · nivel 4

- **Entrada:** `n` y `n − 1` aristas `u v w`, con `1 ≤ n ≤ 2·10^5` y `1 ≤ w ≤ 10^9`.
- **Salida:** la longitud (suma de pesos) del camino más largo.
- **Ejemplo:** `5 / 1 2 3 / 1 3 4 / 3 4 5 / 3 5 2` → `12`.
- **Matemática:** justifica el algoritmo de los dos recorridos (con pesos positivos) y acota el resultado (`≤ 2·10^14`).

**Problema 45.3 — Suma de todas las distancias** · nivel 5

- **Entrada:** igual que el 45.2.
- **Salida:** `Σ_{u<v} dist(u, v)` módulo `10^9 + 7`.
- **Ejemplo:** el mismo árbol → `64`.
- **Matemática:** aplica la fórmula de contribución por arista y comprueba el ejemplo a mano (`3·1·4 + 4·2·3 + 5·1·4 + 2·1·4`). Cuida el producto `w · tam · (n − tam)` módulo.

**Proyecto del día — Analizador de organigramas**

- **Entrada:** `n q`, `n − 1` aristas (raíz 1) y `q` comandos: `prof v`, `tam v`, `altura` (mayor profundidad), `hojas` (cantidad de vértices sin hijos) y `camino u v` (los vértices del camino de `u` a `v`, en orden). Límites: `n ≤ 10^5`, `q ≤ 10^4`.
- **Ejemplo:** `5 5 / 1 2 / 1 3 / 3 4 / 3 5 / prof 4 / tam 3 / altura / hojas / camino 2 5` → `2 / 3 / 2 / 3 / 2 1 3 5`.
- **Qué reviso:** recorrido iterativo, `camino` subiendo por los padres hasta el ancestro común (usa profundidades) y los tamaños de subárbol.
- **Entrega:** `d45.cpp` y `d45_notas.md`.

### Día 46 · miércoles 16 de diciembre · DP en árboles y reenraizado

**Teoría desde cero.** En un árbol enraizado, el estado natural de la DP es un **vértice**: `dp[v]` resume lo que pasa en el subárbol de `v`, y se calcula a partir de los hijos. Se evalúa en el orden inverso al recorrido (hijos antes que padres).

**Conjunto independiente de peso máximo** (ningún par de elegidos es adyacente):

- `a[v]` = mejor suma en el subárbol de `v` **sin** elegir `v` = `Σ max(a[c], b[c])` sobre los hijos `c`.
- `b[v]` = mejor suma **eligiendo** `v` = `peso[v] + Σ a[c]`.
- Respuesta: `max(a[raíz], b[raíz])`.

**Reenraizado (*rerooting*).** Para calcular una cantidad "desde cada vértice como raíz" sin repetir `n` veces un recorrido: calcula primero la respuesta para la raíz 1 y luego "mueve" la raíz a cada hijo con una fórmula. Ejemplo: suma de distancias desde `v` a todos los demás.

- `bajo[v] = Σ_{hijos c} (bajo[c] + tam[c])` (suma de distancias a su propio subárbol).
- `total[1] = bajo[1]` y, al pasar de un padre `p` a su hijo `c`, `total[c] = total[p] − tam[c] + (n − tam[c])`: los `tam[c]` vértices del subárbol de `c` quedan una arista más cerca y los otros `n − tam[c]`, una más lejos.

**Matemática del día.** *Cubrimiento mínimo:* el complemento de un conjunto independiente es un cubrimiento (ninguna arista tiene sus dos extremos dentro del independiente, así que cada arista tiene al menos un extremo fuera) y viceversa; por eso el cubrimiento mínimo vale `n` menos el tamaño del mayor conjunto independiente. *Corrección de la DP:* cada decisión sobre un hijo solo depende de si el padre fue elegido, y los subárboles de los hijos son independientes entre sí.

**Problema 46.1 — Conjunto independiente de peso máximo** · nivel 5

- **Entrada:** `n`; `n` pesos; `n − 1` aristas. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ peso ≤ 10^9`.
- **Salida:** la máxima suma de pesos de un conjunto sin dos vértices adyacentes.
- **Ejemplo:** `5 / 3 2 5 4 1 / 1 2 / 1 3 / 3 4 / 3 5` → `8` (vértices 1, 4 y 5).
- **Matemática:** demuestra las dos recurrencias y que el orden inverso del recorrido tiene listos a los hijos.

**Problema 46.2 — Cubrimiento mínimo de aristas** · nivel 5

- **Entrada:** `n` y `n − 1` aristas, con `1 ≤ n ≤ 2·10^5`.
- **Salida:** la menor cantidad de vértices que tocan **todas** las aristas.
- **Ejemplo:** `5 / 1 2 / 1 3 / 3 4 / 3 5` → `2` (vértices 1 y 3).
- **Matemática:** demuestra que un conjunto es un cubrimiento si y solo si su complemento es independiente, y deduce la respuesta como `n − (máximo conjunto independiente con pesos 1)`.

**Problema 46.3 — Suma de distancias desde cada vértice** · nivel 6

- **Entrada:** `n` y `n − 1` aristas, con `1 ≤ n ≤ 2·10^5`.
- **Salida:** `n` valores: para cada `v`, la suma de las distancias (en aristas) de `v` a todos los demás vértices.
- **Ejemplo:** `4 / 1 2 / 2 3 / 3 4` → `6 4 4 6`.
- **Matemática:** demuestra `total[c] = total[p] − tam[c] + (n − tam[c])` contando qué vértices se acercan y cuáles se alejan.

**Proyecto del día — Guardias de seguridad**

Un edificio tiene pasillos en forma de árbol. Un guardia en un cruce vigila ese cruce y los adyacentes. Calcula el mínimo de guardias para vigilar todos los cruces y una colocación válida.

- **Entrada:** `n` y `n − 1` aristas, con `1 ≤ n ≤ 2·10^5`.
- **Salida:** `g` y, en la línea siguiente, los `g` cruces elegidos en orden creciente (cualquier colocación válida de tamaño mínimo; la verifico).
- **Ejemplo:** `5 / 1 2 / 1 3 / 3 4 / 3 5` → `2 / 1 3`.
- **Estados sugeridos:** `A[v]`: mínimo con guardia en `v`; `B[v]`: sin guardia en `v`, pero vigilado por algún hijo; `C[v]`: sin guardia y sin vigilar por hijos (lo vigilará su padre). Recurrencias: `A = 1 + Σ min(A_c, B_c, C_c)`; `C = Σ B_c`; `B = Σ min(A_c, B_c)` más, si ningún hijo eligió `A`, el menor sobrecosto `A_c − min(A_c, B_c)`. Respuesta: `min(A[raíz], B[raíz])`.
- **Qué reviso:** reconstrucción de la colocación, costo `O(n)` y las notas con la justificación de las tres recurrencias.
- **Entrega:** `d46.cpp` y `d46_notas.md`.

### Día 47 · jueves 17 de diciembre · Recorrido de Euler: consultas sobre subárboles

**Teoría desde cero.** Numera los vértices en el orden en que un DFS los **entra** (`tin`) y anota el momento en que **termina** de visitar su subárbol (`tout`). Entonces **el subárbol de `v` son exactamente los vértices con `tin` en `[tin[v], tout[v])`**: un subárbol es un tramo contiguo del arreglo. Esto convierte consultas sobre subárboles en consultas sobre rangos (prefijos, y más adelante BIT y árboles de segmentos).

```cpp
vector<int> tin(n + 1), tout(n + 1), sig(n + 1, 0), pila = {1};
int t = 0; tin[1] = t++;
while (!pila.empty()) {
    int u = pila.back();
    if (sig[u] < (int)g[u].size()) {
        int v = g[u][sig[u]++];                       // siguiente vecino por mirar
        if (v == padre[u]) continue;
        padre[v] = u; prof[v] = prof[u] + 1;
        tin[v] = t++; pila.push_back(v);
    } else {
        tout[u] = t; pila.pop_back();                 // [tin, tout) es el subárbol
    }
}
// u es ancestro de v  <=>  tin[u] <= tin[v] && tin[v] < tout[u]
```

**Matemática del día.** *Familia laminar:* dos intervalos `[tin, tout)` de vértices distintos son **disjuntos o uno contiene al otro** (un DFS termina un subárbol antes de salir a un vecino); por eso "tener el intervalo contenido" es lo mismo que "ser descendiente". Además `tout[v] − tin[v] = tam[v]`. Para contar vértices de profundidad `d` dentro del subárbol de `v`, guarda para cada profundidad la lista **ordenada** de sus `tin` y cuenta con dos búsquedas binarias.

**Problema 47.1 — ¿Es ancestro?** · nivel 4

- **Entrada:** `n q`; `n − 1` aristas (raíz 1); `q` consultas `u v`. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** `SI` si `u` es ancestro de `v` (un vértice es ancestro de sí mismo), `NO` si no.
- **Ejemplo:** `5 3 / 1 2 / 1 3 / 3 4 / 3 5 / 1 4 / 3 5 / 2 4` → `SI / SI / NO`.
- **Matemática:** demuestra la caracterización `tin[u] ≤ tin[v] < tout[u]` usando la propiedad laminar.

**Problema 47.2 — Sumas de subárbol y de camino** · nivel 5

- **Entrada:** `n q`; `n` valores `a_i`; `n − 1` aristas (raíz 1); `q` consultas `t v`. Si `t = 1`: la suma de los valores del subárbol de `v`; si `t = 2`: la suma de los valores en el camino de la raíz a `v`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i| ≤ 10^9`.
- **Salida:** una respuesta por consulta.
- **Ejemplo:** `5 3 / 1 2 3 4 5 / 1 2 / 1 3 / 3 4 / 3 5 / 1 3 / 2 4 / 1 1` → `12 / 8 / 15`.
- **Matemática:** con el valor de cada vértice colocado en la posición `tin`, la suma del subárbol es una suma de rango (prefijos); la suma raíz-a-`v` se acumula con `suma[v] = suma[padre] + a[v]`.

**Problema 47.3 — Contar a profundidad exacta** · nivel 6

- **Entrada:** `n q`; `n − 1` aristas (raíz 1); `q` consultas `v d`. Límites: `1 ≤ n, q ≤ 2·10^5`, `0 ≤ d < n`.
- **Salida:** cuántos vértices del subárbol de `v` tienen profundidad (absoluta) exactamente `d`.
- **Ejemplo:** `5 3 / 1 2 / 1 3 / 3 4 / 3 5 / 1 1 / 3 2 / 2 2` → `2 / 2 / 0`.
- **Matemática:** justifica que los vértices de profundidad `d` del subárbol de `v` son los de la lista de profundidad `d` con `tin` en `[tin[v], tout[v])`, y cuenta con `lower_bound`. Costo `O((n + q) log n)`.

**Proyecto del día — Consultor de jerarquías**

- **Entrada:** `n q`, `n − 1` aristas (raíz 1) y `q` comandos: `ancestro u v` (`SI`/`NO`), `desc v` (cantidad de descendientes **sin contar** a `v`), `nivel v` (profundidad), `contar v d` (como en el Problema 47.3) y `hojas_en v` (cuántas hojas tiene el subárbol de `v`). Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Ejemplo:** `5 5 / 1 2 / 1 3 / 3 4 / 3 5 / ancestro 1 4 / desc 3 / nivel 5 / contar 1 2 / hojas_en 3` → `SI / 2 / 2 / 2 / 2`.
- **Qué reviso:** un solo recorrido iterativo que produce `tin`, `tout`, profundidad y prefijos de hojas; cada comando en `O(log n)` o `O(1)`.
- **Entrega:** `d47.cpp` y `d47_notas.md`.

### Día 48 · viernes 18 de diciembre · Ancestro común más bajo (LCA) con saltos binarios

**Teoría desde cero.** El **ancestro común más bajo** `lca(u, v)` es el vértice más profundo que es ancestro de ambos. Para hallarlo rápido se precalcula, para cada vértice, su ancestro a distancia `2^0, 2^1, 2^2, …` (**saltos binarios**), en `O(n log n)`.

```cpp
const int LOG = 18;                                   // 2^18 > 2·10^5
vector<array<int, LOG>> up(n + 1);                    // up[v][k] = ancestro 2^k de v (0 si no existe)
for (int v : orden) {                                 // padres antes que hijos
    up[v][0] = padre[v];
    for (int k = 1; k < LOG; k++) up[v][k] = up[up[v][k - 1]][k - 1];   // up[0][*] = 0
}
int kesimo(int v, int k) {                            // k-ésimo ancestro, o 0 si no existe
    for (int i = 0; i < LOG; i++) if (k >> i & 1) v = up[v][i];
    return v;
}
int lca(int a, int b) {
    if (prof[a] < prof[b]) swap(a, b);
    a = kesimo(a, prof[a] - prof[b]);                 // sube a al nivel de b
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)                // sube a ambos mientras difieran
        if (up[a][i] != up[b][i]) { a = up[a][i]; b = up[b][i]; }
    return up[a][0];
}
// distancia(u, v) = prof[u] + prof[v] - 2 * prof[lca(u, v)]
```

**Matemática del día.** *Por qué se puede subir `k` niveles con saltos de `2^i`:* todo `k` se escribe en binario como suma de potencias de 2. *Por qué el segundo ciclo termina en el hijo del LCA:* si dos vértices están a la misma profundidad y no son iguales, subir `2^i` los lleva al mismo ancestro cuando `2^i` es lo bastante grande; el ciclo, de mayor a menor, sube mientras los ancestros difieran y acaba justo debajo del LCA, de modo que `up[a][0]` es el LCA. *Costo:* `O(log n)` por consulta.

**Problema 48.1 — k-ésimo ancestro** · nivel 5

- **Entrada:** `n q`; `n − 1` aristas (raíz 1); `q` consultas `v k`. Límites: `1 ≤ n, q ≤ 2·10^5`, `0 ≤ k ≤ n`.
- **Salida:** el ancestro `k`-ésimo de `v` (`k = 0` es `v`), o `-1` si no existe.
- **Ejemplo:** `5 3 / 1 2 / 1 3 / 3 4 / 4 5 / 5 2 / 5 3 / 2 5` → `3 / 1 / -1`.
- **Matemática:** demuestra la descomposición binaria de `k` y calcula las celdas de la tabla (`n · 18`).

**Problema 48.2 — LCA** · nivel 5

- **Entrada:** `n q`; `n − 1` aristas (raíz 1); `q` consultas `u v`. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** `lca(u, v)` por consulta.
- **Ejemplo:** `5 3 / 1 2 / 1 3 / 3 4 / 4 5 / 2 5 / 4 5 / 5 5` → `1 / 4 / 5`.
- **Matemática:** demuestra la corrección del segundo ciclo (el invariante: `a` y `b` siguen siendo descendientes distintos y propios del LCA).

**Problema 48.3 — Nodo número k del camino** · nivel 6

- **Entrada:** `n q`; `n − 1` aristas (raíz 1); `q` consultas `u v k`. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** el vértice en la posición `k` (desde 0) del camino de `u` a `v`, o `-1` si el camino tiene menos de `k + 1` vértices.
- **Ejemplo:** `5 4 / 1 2 / 1 3 / 3 4 / 4 5 / 2 5 3 / 5 2 1 / 2 2 0 / 2 5 9` → `4 / 4 / 2 / -1`.
- **Matemática:** sea `l = lca(u, v)`. Si `k ≤ prof[u] − prof[l]`, la respuesta es el `k`-ésimo ancestro de `u`; si no, es el ancestro de `v` a distancia `dist(u, v) − k`.

**Proyecto del día — Biblioteca de árboles**

Una `struct Arbol` con: constructor (recibe las aristas y la raíz), `lca`, `dist`, `kesimo`, `camino(u, v)` y `en_camino(a, u, v)` (¿está `a` en el camino de `u` a `v`?). Un `main` lee `n q`, las aristas y `q` comandos `lca u v`, `dist u v`, `kth u k`, `camino u v` y `en_camino a u v`, y escribe una respuesta por comando.

- **Autoprueba:** antes de leer comandos, ejecuta 2000 árboles aleatorios con `n ≤ 30` y compara tu `lca`, `dist` y `kesimo` contra versiones ingenuas (subir paso a paso); imprime `AUTOTEST OK` **por `cerr`** (para no mezclarlo con la salida estándar).
- **Pista:** `a` está en el camino de `u` a `v` si y solo si `dist(u, a) + dist(a, v) = dist(u, v)`.
- **Qué reviso:** la autoprueba, el diseño de la estructura y los límites del `kesimo` (que no se salga de la tabla).
- **Entrega:** `d48.cpp` y `d48_notas.md`.

### Día 49 · sábado 19 de diciembre · Repaso de la semana 7: mini-simulacro de grafos y árboles

**Teoría: estrategia de mini-simulacro.** Tienes 3 problemas con subtareas, como en la IOI. Procede igual que en el Día 35: lee todo, asegura la primera subtarea de cada uno con una fuerza bruta, mejora subtarea por subtarea y compara cada solución rápida contra la fuerza bruta antes de darla por buena. Tiempo sugerido: 3 horas.

**Problema 49.1 — Estaciones de bomberos** · nivel 5

Una ciudad tiene `n` cruces, `m` calles con longitud y `k` estaciones de bomberos. Para cada cruce, ¿cuál es la estación más cercana y a qué distancia?

- **Entrada:** `n m k`; los `k` cruces con estación; luego `m` calles `u v w` (no dirigidas). Límites: `1 ≤ k ≤ n ≤ 2·10^5`, `1 ≤ m ≤ 2·10^5`, `1 ≤ w ≤ 10^9`.
- **Salida:** `n` líneas `distancia estación`; en empate de distancia, la estación de menor número; si no hay ninguna alcanzable, `-1 -1`.
- **Subtareas:** (20 puntos) `n ≤ 100`; (30 puntos) `n ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 5 2 / 1 5 / 1 2 3 / 2 3 4 / 3 4 1 / 4 5 2 / 2 4 6` → `0 1 / 3 1 / 3 5 / 2 5 / 0 5`.
- **Matemática:** demuestra que un Dijkstra con todas las estaciones como fuentes a la vez y etiquetas `(distancia, estación)` ordenadas lexicográficamente da el resultado pedido (la suma de una arista preserva el orden de las etiquetas).

**Problema 49.2 — Punto de reunión** · nivel 6

Tres amigos viven en los cruces `a`, `b` y `c` de una ciudad con forma de árbol. ¿Cuál es la menor suma de distancias de un cruce `x` a los tres?

- **Entrada:** `n q`; `n − 1` calles `u v`; `q` consultas `a b c`. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** el mínimo sobre `x` de `d(x, a) + d(x, b) + d(x, c)`, una línea por consulta.
- **Subtareas:** (20 puntos) `n, q ≤ 100`; (30 puntos) `n, q ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 1 / 1 2 / 1 3 / 3 4 / 4 5 / 2 5 3` → `4`.
- **Matemática:** demuestra que el mínimo vale `(d(a, b) + d(b, c) + d(c, a)) / 2`: los tres caminos se encuentran en un único vértice `x` (la "mediana"), y sus tres tramos `x–a`, `x–b`, `x–c` suman exactamente la mitad de la suma de los lados. ¿Por qué la suma es siempre par?

**Problema 49.3 — Camino de suma máxima** · nivel 7

- **Entrada:** `n`; `n` valores `a_i`; `n − 1` aristas. Límites: `1 ≤ n ≤ 2·10^5`, `|a_i| ≤ 10^9`.
- **Salida:** la mayor suma de los valores de los vértices de un camino (puede tener un solo vértice).
- **Subtareas:** (20 puntos) `n ≤ 20`; (30 puntos) `n ≤ 2000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 / 2 -1 3 -4 5 / 1 2 / 1 3 / 3 4 / 3 5` → `10` (vértices 5, 3 y 1).
- **Matemática:** sea `bajar[v]` la mejor suma de un camino que empieza en `v` y baja por un solo hijo (`a_v + max(0, mejor hijo)`). La mejor suma que tiene a `v` como vértice más alto es `a_v` más el mayor `bajar` de un hijo (si es positivo) más el segundo mayor (si es positivo). Justifica que cada camino tiene un único vértice más alto.

**Proyecto del día — Informe de mini-simulacro y pruebas de estrés**

1. Resuelve los tres problemas con el tiempo sugerido y anota cuánto te tomó cada uno.
2. Entrega la mejor solución completa de cada uno (indica qué lograste dentro del tiempo y qué después).
3. Para cada problema, un test de estrés dentro del mismo archivo contra la fuerza bruta de su primera subtarea (3000 casos aleatorios pequeños; para el 49.1 compara además tu Dijkstra con Bellman–Ford).
4. En las notas, una tabla: subtareas logradas en el tiempo, puntaje estimado por problema y una acción concreta de mejora.

- **Qué califico:** que cada solución completa cumpla los límites de la última subtarea, la independencia de los tests de estrés y la calidad del análisis.
- **Entrega:** `d49_p1.cpp`, `d49_p2.cpp`, `d49_p3.cpp` y `d49_notas.md`.

---

## Semana 8 · 20–26 dic · Estructuras de datos para consultas de rango

**Objetivo:** responder consultas sobre rangos con actualizaciones usando árboles de Fenwick y de segmentos (con propagación perezosa), tablas dispersas, barridos y descomposición en bloques.

### Día 50 · domingo 20 de diciembre · Árbol de Fenwick (BIT)

**Teoría desde cero.** Los prefijos del Día 15 no sirven si el arreglo **cambia**: cada actualización obligaría a recalcular todo. El **árbol de Fenwick** (o BIT, *binary indexed tree*) permite *actualizar un elemento* y *sumar un prefijo* en `O(log n)` con muy poco código.

```cpp
struct BIT {
    int n; vector<long long> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void add(int i, long long v) { for (; i <= n; i += i & -i) t[i] += v; }       // a[i] += v
    long long sum(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }   // a[1..i]
    long long sum(int l, int r) { return sum(r) - sum(l - 1); }                     // a[l..r]
};
```

La celda `t[i]` guarda la suma de las `lowbit(i)` posiciones que terminan en `i`, es decir, del rango `(i − lowbit(i), i]` (con `lowbit(i) = i & −i`). Índices **desde 1**.

**Contar elementos y buscar el `k`-ésimo.** Si cada posición `v` del BIT cuenta cuántas veces aparece el valor `v`, `sum(v)` dice cuántos elementos son `≤ v`. El `k`-ésimo menor se halla **bajando por el árbol** en `O(log n)`:

```cpp
int kesimo(long long k) {              // menor v con sum(v) >= k
    int pos = 0, pw = 1;
    while (pw * 2 <= n) pw *= 2;
    for (; pw > 0; pw >>= 1)
        if (pos + pw <= n && t[pos + pw] < k) { pos += pw; k -= t[pos]; }
    return pos + 1;
}
```

**Contar inversiones.** Con los valores comprimidos a `1..m` (Día 54: ordena, quita repetidos y usa `lower_bound`), recorre el arreglo y suma `i − sum(id[i])` (los anteriores que son mayores), insertando luego `id[i]`.

**Matemática del día.** *Por qué `O(log n)`:* `add` pasa de `i` a `i + lowbit(i)`, y `lowbit` al menos se duplica; `sum` pasa de `i` a `i − lowbit(i)`, que apaga un bit. Ambos hacen a lo más `log2(n) + 1` pasos. *Por qué `sum(i)` es correcta:* el prefijo `[1, i]` se parte en los rangos `(i − lowbit(i), i]`, `(i' − lowbit(i'), i']`, … que son disjuntos y lo cubren. *Cota de inversiones:* a lo más `n(n − 1)/2 ≈ 2·10^10`.

**Problema 50.1 — Actualizaciones y sumas** · nivel 4

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 i v` (suma `v` a `a_i`) o `2 l r` (consulta la suma de `a[l..r]`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v| ≤ 10^9`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `5 5 / 1 2 3 4 5 / 2 1 5 / 1 3 10 / 2 1 3 / 2 3 5 / 1 1 -1` → `15 / 16 / 22`.
- **Matemática:** demuestra que `sum` descompone `[1, i]` en rangos disjuntos y calcula los pasos máximos para `n = 2·10^5`.

**Problema 50.2 — Inversiones** · nivel 5

- **Entrada:** `n` y `n` enteros, con `1 ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** cuántas parejas `i < j` cumplen `a_i > a_j`.
- **Ejemplo:** `5 / 3 1 2 5 4` → `3`; `4 / 4 3 2 1` → `6`.
- **Matemática:** demuestra que la compresión conserva el orden relativo (y por tanto las inversiones) y acota la respuesta.

**Problema 50.3 — `k`-ésimo menor dinámico** · nivel 6

- **Entrada:** `q` y `q` operaciones: `+ x` (inserta `x`), `- x` (elimina una copia de `x`, que existe) o `? k` (imprime el `k`-ésimo menor del conjunto actual, que tiene al menos `k` elementos). Límites: `1 ≤ q ≤ 2·10^5`, `1 ≤ x ≤ 10^6`.
- **Salida:** la respuesta de cada `?`.
- **Ejemplo:** `6 / + 5 / + 3 / + 8 / ? 2 / - 3 / ? 2` → `5 / 8`.
- **Matemática:** justifica el descenso por el árbol: en cada nivel, si `t[pos + pw] < k` el `k`-ésimo está a la derecha y se resta lo que queda a la izquierda.

**Proyecto del día — Ranking dinámico**

- **Entrada:** `n q` y `q` comandos sobre `n` jugadores con puntaje inicial 0: `sumar p v` (suma `v > 0` al puntaje del jugador `p`), `rango p` (1 más la cantidad de jugadores con puntaje **estrictamente mayor** que el de `p`) y `mejores k` (el `k`-ésimo mayor puntaje entre todos los jugadores). Límites: `1 ≤ n, q ≤ 2·10^5`; ningún puntaje supera `10^6`.
- **Salida:** la respuesta de cada `rango` y `mejores`.
- **Ejemplo:** `3 7 / sumar 1 10 / sumar 2 5 / rango 2 / mejores 1 / sumar 2 7 / rango 1 / mejores 2` → `2 / 10 / 2 / 10`.
- **Qué reviso:** un BIT de conteos indexado por puntaje (al sumar, quitas el puntaje viejo y pones el nuevo), `O(log 10^6)` por comando y el uso correcto del `k`-ésimo mayor como `(n − k + 1)`-ésimo menor.
- **Entrega:** `d50.cpp` y `d50_notas.md`.

### Día 51 · lunes 21 de diciembre · Árbol de segmentos

**Teoría desde cero.** Un **árbol de segmentos** guarda, en cada nodo, un resumen (suma, mínimo, máximo, …) de un tramo del arreglo. La raíz resume `[0, n−1]`; cada nodo parte su tramo en dos mitades. Permite *cambiar un elemento* y *consultar cualquier rango* en `O(log n)`, y sirve para cualquier operación **asociativa** (no necesita ser invertible, a diferencia de los prefijos y el BIT).

```cpp
struct Nodo { long long suma, pref, suf, mejor; };          // ejemplo: subarreglo máximo
Nodo hoja(long long v) { return {v, v, v, v}; }
Nodo combinar(const Nodo &a, const Nodo &b) {                // a es el tramo izquierdo
    return { a.suma + b.suma,
             max(a.pref, a.suma + b.pref),
             max(b.suf, b.suma + a.suf),
             max({a.mejor, b.mejor, a.suf + b.pref}) };
}

vector<Nodo> t;                                              // tamaño 4n; el nodo x tiene hijos 2x y 2x+1
void construir(int x, int l, int r) {
    if (l == r) { t[x] = hoja(a[l]); return; }
    int m = (l + r) / 2;
    construir(2 * x, l, m); construir(2 * x + 1, m + 1, r);
    t[x] = combinar(t[2 * x], t[2 * x + 1]);
}
void poner(int x, int l, int r, int pos, long long v) {
    if (l == r) { t[x] = hoja(v); return; }
    int m = (l + r) / 2;
    if (pos <= m) poner(2 * x, l, m, pos, v); else poner(2 * x + 1, m + 1, r, pos, v);
    t[x] = combinar(t[2 * x], t[2 * x + 1]);
}
Nodo consultar(int x, int l, int r, int ql, int qr) {         // requiere ql <= qr dentro de [l, r]
    if (ql <= l && r <= qr) return t[x];
    int m = (l + r) / 2;
    if (qr <= m) return consultar(2 * x, l, m, ql, qr);
    if (ql > m) return consultar(2 * x + 1, m + 1, r, ql, qr);
    return combinar(consultar(2 * x, l, m, ql, qr), consultar(2 * x + 1, m + 1, r, ql, qr));
}
```

Para una suma o un mínimo basta cambiar `Nodo` por un número y `combinar` por `+` o `min`. Al combinar, **el orden importa** si la operación no es conmutativa: izquierda primero.

**Descenso por el árbol.** Con un árbol de máximos, la primera posición con valor `≥ v` se encuentra sin consultar rangos: si el máximo de la raíz es `< v`, no existe; si no, baja por el hijo izquierdo cuando su máximo es `≥ v` y, si no, por el derecho.

**Matemática del día.** *Costo de una consulta:* en cada nivel hay a lo sumo dos nodos que cubren el rango parcialmente; los demás se descartan o quedan totalmente dentro, así que se visitan `O(log n)` nodos. *Tamaño:* un árbol de altura `ceil(log2 n) + 1` cabe en `4n` posiciones. *Por qué `combinar` es asociativa* en el ejemplo: el subarreglo máximo de un tramo es el mejor de la izquierda, el mejor de la derecha o uno que cruza la mitad (`sufijo izquierdo + prefijo derecho`).

**Problema 51.1 — Mínimo en rango con actualizaciones** · nivel 5

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 i v` (asigna `a_i = v`) o `2 l r` (mínimo de `a[l..r]`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v| ≤ 10^9`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `5 4 / 5 2 7 1 6 / 2 1 3 / 1 4 9 / 2 3 5 / 2 4 4` → `2 / 6 / 9`.
- **Matemática:** demuestra que a lo sumo dos nodos por nivel quedan parcialmente cubiertos.

**Problema 51.2 — Primera posición con valor al menos x** · nivel 6

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 i v` (asigna `a_i = v`) o `2 x` (primera posición `p` con `a_p ≥ x`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v|, |x| ≤ 10^9`.
- **Salida:** `p` (desde 1) o `-1`, por cada consulta de tipo 2.
- **Ejemplo:** `5 4 / 3 1 4 1 5 / 2 4 / 1 1 9 / 2 8 / 2 10` → `3 / 1 / -1`.
- **Matemática:** demuestra que el descenso es correcto (si el máximo del hijo izquierdo es `≥ x`, la primera posición está allí; si no, en el derecho) y que cuesta `O(log n)`.

**Problema 51.3 — Subarreglo máximo con actualizaciones** · nivel 7

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 i v` (asigna `a_i = v`) o `2 l r` (la mayor suma de un subarreglo **no vacío** dentro de `a[l..r]`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v| ≤ 10^9`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `5 4 / -2 1 -3 4 -1 / 2 1 5 / 1 3 5 / 2 1 5 / 2 2 3` → `4 / 10 / 6`.
- **Matemática:** demuestra que `combinar` es asociativa y que representa bien el tramo concatenado; explica por qué las sumas caben en `long long`.

**Proyecto del día — Biblioteca de árbol de segmentos**

Una plantilla `SegTree<Nodo, Combinar>` que reciba el tipo del nodo y la función de combinación (y la función `hoja`) con `construir`, `poner`, `consultar` y un descenso genérico. Con ella, resuelve los tres problemas de hoy. El `main` lee primero `1`, `2` o `3` (el problema) y luego la entrada de ese problema.

- **Prueba:** una función de autoprueba (resultado por `cerr`) que compare la plantilla contra fuerza bruta en 3000 casos aleatorios por problema.
- **Qué reviso:** que la plantilla sea realmente genérica, el orden izquierda-derecha al combinar y los límites (`n = 1`, consultas de un solo elemento).
- **Entrega:** `d51.cpp` y `d51_notas.md`.

### Día 52 · martes 22 de diciembre · Propagación perezosa (lazy)

**Teoría desde cero.** ¿Y si las actualizaciones también son de **rango** ("suma `v` a todo `a[l..r]`")? Actualizar elemento por elemento cuesta `O(n)`. La **propagación perezosa** deja una *etiqueta* en los nodos que cubren completamente el rango y **pospone** el trabajo hacia los hijos hasta que haga falta.

```cpp
struct SegLazy {
    int n; vector<long long> sum, lz;
    SegLazy(int n) : n(n), sum(4 * n, 0), lz(4 * n, 0) {}
    void aplicar(int x, int len, long long v) { sum[x] += v * len; lz[x] += v; }
    void empujar(int x, int l, int r) {                    // pasa la etiqueta a los hijos
        if (lz[x] == 0) return;
        int m = (l + r) / 2;
        aplicar(2 * x, m - l + 1, lz[x]);
        aplicar(2 * x + 1, r - m, lz[x]);
        lz[x] = 0;
    }
    void sumar(int x, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { aplicar(x, r - l + 1, v); return; }
        empujar(x, l, r);
        int m = (l + r) / 2;
        sumar(2 * x, l, m, ql, qr, v); sumar(2 * x + 1, m + 1, r, ql, qr, v);
        sum[x] = sum[2 * x] + sum[2 * x + 1];
    }
    long long consultar(int x, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return sum[x];
        empujar(x, l, r);
        int m = (l + r) / 2;
        return consultar(2 * x, l, m, ql, qr) + consultar(2 * x + 1, m + 1, r, ql, qr);
    }
};
```

**Reglas para otros tipos de etiqueta.**

- *Asignar `v`:* la etiqueta nueva **reemplaza** a la anterior.
- *Sumar `d` sobre una etiqueta ya existente:* si había una asignación `v`, se vuelve asignación `v + d`; si había una suma `e`, se vuelve suma `e + d`.
- *Invertir (0↔1):* dos inversiones se cancelan (la etiqueta es un booleano que se niega); un nodo con `on` unos y longitud `len` pasa a tener `len − on`.

**Matemática del día.** *Invariante:* para cada nodo, `sum[x]` ya incluye todas las actualizaciones aplicadas a él o a sus ancestros hasta el último `empujar`, y `lz[x]` es lo que falta aplicar a sus hijos. *Por qué componer etiquetas funciona:* las etiquetas son transformaciones de los valores del tramo y su composición debe ser asociativa; en cada caso de arriba la composición de dos etiquetas es otra etiqueta del mismo tipo. *Costo:* `O(log n)` por operación, porque solo se visitan los nodos parcialmente cubiertos (como en el Día 51) y se empuja en cada uno.

**Problema 52.1 — Suma en rango y consulta de suma** · nivel 6

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 l r v` (suma `v` a `a[l..r]`) o `2 l r` (suma de `a[l..r]`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v| ≤ 10^9`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `5 4 / 1 2 3 4 5 / 1 2 4 10 / 2 1 5 / 2 3 3 / 1 1 5 -1` → `45 / 13`.
- **Matemática:** acota el mayor valor posible (`10^9 + 2·10^5·10^9`) y por qué `v * len` cabe en `long long`.

**Problema 52.2 — Asignar, sumar y consultar** · nivel 7

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 l r v` (asigna `v` a todo `a[l..r]`), `2 l r v` (suma `v` a todo `a[l..r]`) o `3 l r` (suma de `a[l..r]`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |v| ≤ 10^9`.
- **Salida:** la respuesta de cada consulta de tipo 3.
- **Ejemplo:** `5 6 / 1 2 3 4 5 / 1 2 4 7 / 3 1 5 / 2 3 5 1 / 3 1 5 / 1 1 5 2 / 3 2 3` → `27 / 30 / 4`.
- **Matemática:** deduce la regla de composición de etiquetas "asignar" y "sumar" y demuestra que es asociativa (los 4 casos de aplicar una etiqueta sobre otra).

**Problema 52.3 — Interruptores** · nivel 7

- **Entrada:** `n q` y `q` líneas: `1 l r` (invierte cada lámpara de `l..r`) o `2 l r` (cuántas lámparas están encendidas en `l..r`). Al inicio todas están apagadas. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `5 5 / 1 1 3 / 2 1 5 / 1 2 4 / 2 1 5 / 2 4 5` → `3 / 2 / 1`.
- **Matemática:** demuestra que invertir un tramo transforma `on` en `len − on` y que dos inversiones seguidas se cancelan.

**Proyecto del día — Hoja de cálculo simplificada**

Una columna de `n` números con las operaciones `sumar l r v`, `asignar l r v`, `suma l r`, `min l r` y `max l r`. Cada nodo guarda `suma`, `min`, `max` y su longitud, con una etiqueta de tipo *asignar* o *sumar*.

- **Entrada:** `n q`; `n` enteros; `q` comandos. Límites: `1 ≤ n, q ≤ 2·10^5`, `|valores| ≤ 10^9`.
- **Salida:** la respuesta de `suma`, `min` y `max` (los otros comandos no escriben).
- **Ejemplo:** `5 6 / 5 3 8 1 9 / suma 1 5 / asignar 2 3 4 / min 1 5 / sumar 4 5 10 / max 1 5 / suma 2 4` → `26 / 1 / 19 / 19`.
- **Qué reviso:** la composición de etiquetas (tabla de los 4 casos en las notas), `empujar` antes de bajar y pruebas contra fuerza bruta.
- **Entrega:** `d52.cpp` y `d52_notas.md`.

### Día 53 · miércoles 23 de diciembre · Tabla dispersa (sparse table) y consultas de mínimo

**Teoría desde cero.** Si el arreglo **no cambia** y solo hay consultas de mínimo (o máximo, `gcd`, …), la **tabla dispersa** responde cada una en `O(1)` tras preparar `O(n log n)`. Guarda `st[k][i]` = mínimo del tramo de longitud `2^k` que empieza en `i`.

```cpp
int K = __lg(n) + 1;                           // __lg(x) = floor(log2(x))
vector<vector<int>> st(K, vector<int>(n));
st[0] = a;
for (int k = 1; k < K; k++)
    for (int i = 0; i + (1 << k) <= n; i++)
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);

auto consulta = [&](int l, int r) {            // mínimo de a[l..r], 0-indexado
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);   // dos tramos que se solapan
};
```

Solo sirve para operaciones **idempotentes** (`f(x, x) = x`), porque los dos tramos de la consulta se solapan: vale con mínimo, máximo, `gcd`, `AND`, `OR`; no con sumas. Con muchas consultas (`10^6`) usa lectura rápida (`ios::sync_with_stdio(false); cin.tie(nullptr);`).

**Matemática del día.** *Por qué los dos tramos cubren `[l, r]`:* si `k = floor(log2(len))`, entonces `2^k ≤ len < 2^(k+1)`, así que dos tramos de longitud `2^k`, uno pegado a `l` y otro pegado a `r`, cubren todo el rango y su unión es exactamente `[l, r]`. *Memoria:* `n·log2(n) ≈ 3,6·10^6` celdas para `n = 2·10^5`. *Comparación:* tabla dispersa `O(n log n)` / `O(1)` solo estática; árbol de segmentos `O(n)` / `O(log n)` con actualizaciones.

**Problema 53.1 — Mínimo en rango estático** · nivel 4

- **Entrada:** `n q`; `n` enteros; `q` consultas `l r`. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ q ≤ 10^6`, `|a_i| ≤ 10^9`.
- **Salida:** el mínimo de `a[l..r]` por consulta.
- **Ejemplo:** `6 3 / 5 2 7 1 6 3 / 1 3 / 3 6 / 2 2` → `2 / 1 / 2`.
- **Matemática:** demuestra que los dos tramos solapados cubren exactamente `[l, r]` y calcula el tamaño de la tabla.

**Problema 53.2 — Amplitud en rango** · nivel 5

- **Entrada:** igual que el 53.1.
- **Salida:** `max − min` de `a[l..r]` por consulta.
- **Ejemplo:** `6 3 / 5 2 7 1 6 3 / 1 3 / 3 6 / 2 2` → `5 / 6 / 0`.
- **Matemática:** explica por qué una tabla dispersa de máximos y otra de mínimos bastan, y por qué la amplitud es no decreciente al agrandar el rango.

**Problema 53.3 — Ventana más larga con amplitud acotada** · nivel 6

- **Entrada:** `n K` y `n` enteros, con `1 ≤ n ≤ 2·10^5`, `0 ≤ K ≤ 10^9` y `|a_i| ≤ 10^9`.
- **Salida:** la mayor longitud de un subarreglo contiguo con `max − min ≤ K`.
- **Ejemplo:** `7 3 / 4 6 5 9 8 7 10` → `4` (los elementos `9 8 7 10`).
- **Matemática:** si `[l, r]` cumple la condición, también toda subventana; por eso, con dos punteros, el menor `l` válido para cada `r` no decrece. Cada paso consulta la amplitud en `O(1)`.

**Proyecto del día — Comparativa de estructuras de rango**

Programa que resuelve consultas de mínimo en rango con **tres** métodos: fuerza bruta `O(n)` por consulta, árbol de segmentos y tabla dispersa, y los compara.

- **Procedimiento:** con `n = 2·10^5` valores aleatorios y `q = 2·10^5` consultas aleatorias (`mt19937_64` con semilla fija), mide con `chrono` el tiempo de **preparación** y el de **consultas** de cada método y verifica que los tres den las mismas respuestas.
- **Salida:** una tabla `metodo preparacion_ms consultas_ms memoria_aprox_MB` y `RESPUESTAS IGUALES` o la primera discrepancia.
- **Notas:** explica los tiempos observados con las complejidades (`O(n)`, `O(log n)`, `O(1)` por consulta) y cuándo elegirías cada método.
- **Entrega:** `d53.cpp` y `d53_notas.md`.

### Día 54 · jueves 24 de diciembre · Compresión de coordenadas y barrido (sweep line)

**Teoría desde cero.** Cuando los valores son enormes (`10^9`) pero solo importan **sus posiciones relativas**, se **comprimen**: se ordenan los valores distintos y cada uno se reemplaza por su posición en esa lista.

```cpp
vector<int> vals = a;
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());
auto id = [&](int x) { return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()); };   // 0..m-1
```

Un **barrido** (*sweep line*) recorre los eventos ordenados por una coordenada (por ejemplo `x`) y mantiene una estructura sobre la otra (por ejemplo un BIT sobre `y`). Reglas prácticas: define el orden exacto de los empates (¿un final antes que un inicio?), procesa en bloque los eventos que comparten coordenada y comprime la otra coordenada para poder indexar.

**Matemática del día.** *Compresión:* la función que envía cada valor a su posición es creciente, así que preserva `<`, `=`, `>`; por eso sirve para contar inversiones o dominancias. *Unión de intervalos:* al ordenar por inicio, un intervalo se fusiona con el actual si su inicio es `≤` al final actual; el largo cubierto es la suma de `fin − inicio` de los grupos fusionados. *Dominancia:* para contar los puntos `(x', y')` con `x' < x` e `y' < y`, recorre por `x` creciente, consulta el BIT con el prefijo `y − 1` **antes** de insertar los puntos del mismo `x`.

**Problema 54.1 — Longitud cubierta** · nivel 4

- **Entrada:** `n` y `n` segmentos `l r`, con `1 ≤ n ≤ 2·10^5` y `0 ≤ l < r ≤ 10^9`.
- **Salida:** la longitud total de la unión de los segmentos (suma de `r − l` de los trozos fusionados).
- **Ejemplo:** `4 / 1 5 / 3 8 / 10 12 / 11 15` → `12`.
- **Matemática:** demuestra que, ordenados por inicio, basta comparar cada segmento con el último grupo fusionado.

**Problema 54.2 — Puntos dominados** · nivel 6

- **Entrada:** `n` y `n` puntos `x y`, con `1 ≤ n ≤ 2·10^5` y `1 ≤ x, y ≤ 10^9` (puede haber coordenadas repetidas, pero no puntos idénticos).
- **Salida:** para cada punto (en el orden de entrada), cuántos puntos tienen `x'` **y** `y'` estrictamente menores.
- **Ejemplo:** `5 / 1 1 / 2 3 / 3 2 / 4 5 / 5 4` → `0 1 1 3 3`.
- **Matemática:** justifica el orden de procesamiento con empates en `x` (consultas del grupo antes de insertarlo) y el uso de `y` comprimida.

**Problema 54.3 — Horizonte** · nivel 6

Cada edificio ocupa `[l, r)` en el eje `x` y tiene altura `h`. El **horizonte** es la altura máxima visible en cada `x`.

- **Entrada:** `n` y `n` líneas `l r h`, con `1 ≤ n ≤ 10^5`, `0 ≤ l < r ≤ 10^9` y `1 ≤ h ≤ 10^9`.
- **Salida:** primero `k`, la cantidad de puntos clave, y luego `k` líneas `x h`: cada `x` donde la altura máxima cambia y la nueva altura (0 si no hay edificio). El horizonte empieza en altura 0.
- **Ejemplo:** `3 / 1 5 3 / 2 4 5 / 6 8 2` → `6 / 1 3 / 2 5 / 4 3 / 5 0 / 6 2 / 8 0`.
- **Matemática:** mantén un `multiset` de alturas activas; en cada coordenada procesa **todos** los eventos antes de comparar el máximo con el anterior. Justifica por qué no hay que mirar nada entre dos coordenadas consecutivas de eventos.

**Proyecto del día — Calendario inteligente**

Varias personas tienen reuniones ocupadas en un día `[0, T)`. Encuentra los huecos en los que **nadie** está ocupado y la primera hora para una reunión de duración `d`.

- **Entrada:** `n T d` y `n` intervalos `l r` (ocupado en `[l, r)`; pueden solaparse), con `1 ≤ n ≤ 2·10^5`, `1 ≤ T ≤ 10^9`, `1 ≤ d ≤ T` y `0 ≤ l < r ≤ T`.
- **Salida:** la cantidad `k` de huecos libres; `k` líneas `inicio fin`; la longitud del mayor hueco (0 si no hay); y el menor inicio de un hueco de longitud `≥ d` (o `-1`).
- **Ejemplo:** `3 100 15 / 10 30 / 20 40 / 60 70` → `3 / 0 10 / 40 60 / 70 100 / 30 / 40`.
- **Qué reviso:** ordenar y fusionar, los bordes (`0` y `T`) y el costo `O(n log n)`.
- **Entrega:** `d54.cpp` y `d54_notas.md`.

### Día 55 · viernes 25 de diciembre · Descomposición en bloques y algoritmo de Mo

**Teoría desde cero.**

**Descomposición en raíz cuadrada.** Divide el arreglo en bloques de tamaño `B ≈ √n` y guarda un resumen por bloque. Una consulta mira a mano los elementos de los bloques parciales de los extremos y usa el resumen de los bloques completos: `O(√n)`. Es más fácil de escribir que un árbol de segmentos y resuelve problemas donde el resumen del bloque es complicado (por ejemplo, el bloque guardado **ordenado** para contar elementos `≥ x` con una búsqueda binaria).

**Algoritmo de Mo.** Para consultas **offline** sobre rangos `[l, r]` donde sabes **agregar o quitar** un elemento de una ventana: ordena las consultas por `(l / B, r)` y mueve una ventana de un lado a otro agregando y quitando elementos.

```cpp
int B = max(1, (int)sqrt(n));
sort(qs.begin(), qs.end(), [&](const Q &x, const Q &y) {
    int bx = x.l / B, by = y.l / B;
    if (bx != by) return bx < by;
    return (bx & 1) ? x.r > y.r : x.r < y.r;            // zigzag: menos movimiento del puntero r
});
int L = 0, R = -1;                                      // ventana [L, R] vacía
for (auto &q : qs) {
    while (L > q.l) agregar(--L);
    while (R < q.r) agregar(++R);
    while (L < q.l) quitar(L++);
    while (R > q.r) quitar(R--);
    ans[q.id] = valor_actual;
}
```

Orden de los `while`: primero se agranda la ventana y después se achica, para que nunca se quite un elemento que no estaba.

**Matemática del día.** *Costo de Mo:* dentro de un bloque de `l`, el puntero `L` se mueve a lo sumo `B` veces por consulta (`q·B` en total) y `R` solo avanza en un sentido, a lo sumo `n` por bloque (`(n/B)·n` en total). Total `q·B + n²/B`, que se minimiza con `B = n/√q`, y vale `O(n√q)`. *Distintos en rango:* mantén `cnt[v]` y un contador `distintos`; al agregar `v`, si `cnt[v]` pasa de 0 a 1, `distintos++`; al quitar, si pasa de 1 a 0, `distintos--`. *Frecuencia máxima:* mantén `cnt[v]`, `cc[c]` (cuántos valores tienen frecuencia `c`) y `mx`; al quitar un valor con frecuencia `mx` y `cc[mx] = 1`, `mx` baja en 1.

**Problema 55.1 — Contar mayores con actualizaciones** · nivel 5

- **Entrada:** `n q`; `n` enteros; `q` líneas: `1 i v` (asigna `a_i = v`) o `2 l r x` (cuántos elementos de `a[l..r]` son `≥ x`). Límites: `1 ≤ n, q ≤ 5·10^4`, valores y `x` hasta `10^9`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `5 4 / 5 2 7 1 6 / 2 1 5 4 / 1 2 9 / 2 1 3 8 / 2 2 5 6` → `3 / 1 / 3`.
- **Matemática:** guarda cada bloque **ordenado**: una actualización reordena un bloque en `O(B log B)` (o `O(B)` desplazando) y una consulta cuesta `O((n/B)·log B + B)`. Elige `B` y calcula el costo total.

**Problema 55.2 — Valores distintos en rango (Mo)** · nivel 7

- **Entrada:** `n q`; `n` enteros; `q` consultas `l r`. Límites: `1 ≤ n, q ≤ 2·10^5`, `1 ≤ a_i ≤ 10^9` (comprime).
- **Salida:** la cantidad de valores distintos en `a[l..r]` por consulta.
- **Ejemplo:** `6 3 / 1 2 1 3 2 1 / 1 3 / 2 5 / 1 6` → `2 / 3 / 3`.
- **Matemática:** demuestra el costo `O(n√q)` de Mo y por qué ese orden de consultas lo logra.

**Problema 55.3 — Frecuencia máxima en rango (Mo)** · nivel 7

- **Entrada:** igual que el 55.2.
- **Salida:** la mayor cantidad de veces que aparece un mismo valor dentro de `a[l..r]`, por consulta.
- **Ejemplo:** `6 3 / 1 2 1 3 2 1 / 1 3 / 2 5 / 1 6` → `2 / 2 / 3`.
- **Matemática:** justifica con `cc[c]` que `quitar` puede bajar `mx` como máximo en 1 y por qué **no** basta guardar solo `mx` (quitar no se puede deshacer sin información extra).

**Proyecto del día — Biblioteca de Mo y el mejor tamaño de bloque**

Una plantilla `Mo` genérica con funciones `agregar`, `quitar` y `valor` (recibidas como lambdas), usada para resolver los Problemas 55.2 y 55.3, y un experimento.

- **Experimento:** con `n = q = 2·10^5` aleatorios, mide el tiempo para `B` en `{n/√q / 4, n/√q / 2, n/√q, 2·n/√q, 4·n/√q}` y para los dos órdenes (con y sin zigzag). Imprime una tabla `B zigzag tiempo_ms`.
- **Pruebas:** autoprueba contra fuerza bruta (3000 casos aleatorios pequeños) con resultado por `cerr`.
- **Qué reviso:** la corrección de la plantilla, el orden de los `while` y la tabla del experimento.
- **Notas:** compara el tiempo observado con `n√q` y explica cuál `B` fue mejor y por qué.
- **Entrega:** `d55.cpp` y `d55_notas.md`.

### Día 56 · sábado 26 de diciembre · Repaso de la semana 8 y pruebas de estrés

**Teoría: ¿qué estructura uso?**

- **Sumas en rangos sin cambios:** prefijos (Día 15).
- **Actualizaciones de rango y lectura final:** diferencias (Día 17).
- **Actualizar un elemento y sumar prefijos/rangos, contar elementos, `k`-ésimo:** BIT.
- **Cualquier operación asociativa con actualizaciones puntuales:** árbol de segmentos.
- **Actualizaciones de rango con consultas de rango:** árbol de segmentos con propagación perezosa.
- **Mínimo/máximo/gcd estático:** tabla dispersa.
- **Consultas offline difíciles (distintos, frecuencias):** Mo. **Offline con orden:** ordena consultas y elementos y usa un BIT.

**Problema 56.1 — Suma de mínimos de todos los subarreglos** · nivel 5

- **Entrada:** `n` y `n` enteros, con `1 ≤ n ≤ 2·10^5` y `1 ≤ a_i ≤ 10^9`.
- **Salida:** la suma, módulo `10^9 + 7`, del mínimo de cada subarreglo contiguo.
- **Ejemplo:** `4 / 3 1 2 4` → `17`.
- **Matemática:** atribuye cada subarreglo a su mínimo **más a la izquierda**. Para `i`, sea `izq` la cantidad de elementos consecutivos a su izquierda **estrictamente mayores** y `der` la de consecutivos a la derecha **mayores o iguales**; el aporte de `i` es `a_i · (izq + 1) · (der + 1)`. Calcúlalos con una pila monótona (Día 22) y justifica por qué no se cuenta ningún subarreglo dos veces.

**Problema 56.2 — Menores en un rango (offline)** · nivel 6

- **Entrada:** `n q`; `n` enteros; `q` consultas `l r x`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |x| ≤ 10^9`.
- **Salida:** cuántos elementos de `a[l..r]` son estrictamente menores que `x`, por consulta.
- **Ejemplo:** `5 3 / 5 2 7 1 6 / 1 5 6 / 2 4 3 / 3 5 10` → `3 / 2 / 3`.
- **Matemática:** ordena las consultas por `x` y los elementos por valor; antes de responder una consulta, inserta en un BIT (por posición) todos los elementos `< x`. La respuesta es `sum(r) − sum(l − 1)`. Justifica por qué ordenar no cambia la respuesta de cada consulta.

**Problema 56.3 — Subarreglos con suma en un intervalo** · nivel 7

- **Entrada:** `n L R` y `n` enteros, con `1 ≤ n ≤ 2·10^5`, `|a_i| ≤ 10^9` y `|L| ≤ |R| ≤ 10^15` (`L ≤ R`).
- **Salida:** cuántos subarreglos contiguos tienen suma entre `L` y `R` (ambos incluidos).
- **Ejemplo:** `5 2 4 / 1 -2 3 1 2` → `8`; `3 3 3 / 1 2 3` → `2`.
- **Matemática:** con prefijos `p`, el subarreglo `(i, j]` cumple `L ≤ p_j − p_i ≤ R`, es decir, `p_j − R ≤ p_i ≤ p_j − L`. Para cada `j`, cuenta con un BIT sobre los prefijos comprimidos cuántos `p_i` previos caen en ese intervalo (dos `lower_bound`/`upper_bound` sobre los valores comprimidos).

**Proyecto del día — Pruebas de estrés de la semana**

Un único programa con cinco comparaciones contra fuerza bruta (semilla fija, 2000 pruebas cada una); escribe `OK` o el primer contraejemplo:

1. BIT: actualizaciones puntuales y sumas de rango.
2. Árbol de segmentos: mínimo en rango con asignaciones.
3. Propagación perezosa: sumar/asignar en rango y sumas de rango.
4. Tabla dispersa: mínimo y máximo en rango.
5. Mo: valores distintos en rango.

- **Qué reviso:** generadores que cubran bordes (`n = 1`, rangos de un elemento), fuerzas brutas independientes y mensajes claros.
- **Notas:** una tabla con una fila por estructura: operaciones, complejidad y el error que más te costó.
- **Entrega:** `d56.cpp` y `d56_notas.md`.

---

## Semana 9 · 27 dic–2 ene · Cadenas, teoría de números avanzada y probabilidad

**Objetivo:** comparar y buscar en cadenas en tiempo lineal (hashing, KMP, Z, tries), manejar la función φ de Euler y la inclusión–exclusión, y calcular esperanzas módulo un primo. Termina con el segundo simulacro.

### Día 57 · domingo 27 de diciembre · Hashing de cadenas

**Teoría desde cero.** Comparar dos subcadenas carácter por carácter cuesta `O(longitud)`. Un **hash polinomial** resume una cadena en un número, de modo que comparar subcadenas cuesta `O(1)` después de preparar los **hashes de prefijos**. La idea: leer la cadena como un número en base `B` módulo `M`.

```cpp
using u64 = unsigned long long;
const u64 MOD = (1ULL << 61) - 1;                          // primo de Mersenne: módulo grande
u64 mulmod(u64 a, u64 b) {
    __uint128_t t = (__uint128_t)a * b;
    u64 r = (u64)(t & MOD) + (u64)(t >> 61);
    return r >= MOD ? r - MOD : r;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const u64 BASE = rng() % (MOD - 1000) + 500;                // base aleatoria

vector<u64> H(n + 1, 0), P(n + 1, 1);
for (int i = 0; i < n; i++) {
    H[i + 1] = (mulmod(H[i], BASE) + (unsigned char)s[i]) % MOD;
    P[i + 1] = mulmod(P[i], BASE);
}
// hash de s[l..r) (r exclusivo) en O(1):
auto sub = [&](int l, int r) { return (H[r] + MOD - mulmod(H[l], P[r - l])) % MOD; };
```

**Colisiones.** Dos cadenas distintas pueden tener el mismo hash. Con un módulo de unos `10^9` y `10^5` cadenas, hay muchas probabilidades de colisión (paradoja del cumpleaños); por eso se usa un módulo de 61 bits o dos módulos, y una **base aleatoria** (una base fija puede ser atacada por casos de prueba hechos a propósito).

**Matemática del día.** *Por qué `sub` es correcta:* `H[r] = H[l]·B^(r−l) + (hash de s[l..r))`, de donde se despeja el hash del tramo. *Probabilidad de error:* el hash de una cadena de largo `n` es un polinomio de grado `< n` en `B`. Dos cadenas distintas producen polinomios distintos; su diferencia es un polinomio no nulo de grado `< n`, que tiene como mucho `n − 1` raíces módulo `M`. Con `B` elegida al azar, la probabilidad de colisión de una comparación es `≤ (n − 1)/M`. *Paradoja del cumpleaños:* con `k` valores aleatorios en `M` posibles, la probabilidad de alguna coincidencia es `≈ k²/(2M)`; para `k = 10^5` y `M = 10^9` es mayor que 1.

**Problema 57.1 — Comparar subcadenas** · nivel 5

- **Entrada:** una cadena `s` de minúsculas; luego `q` y `q` líneas `l1 r1 l2 r2`. Límites: `1 ≤ |s|, q ≤ 2·10^5`, `1 ≤ l ≤ r ≤ |s|`.
- **Salida:** `SI` si `s[l1..r1] = s[l2..r2]` (comparando los textos); si no, `NO` (también `NO` si sus longitudes difieren).
- **Ejemplo:** `abcabc / 3 / 1 3 4 6 / 1 2 2 3 / 2 3 5 6` → `SI / NO / SI`.
- **Matemática:** demuestra la fórmula de `sub` y acota la probabilidad de que alguna de las `q` respuestas sea incorrecta (`q · n / M`).

**Problema 57.2 — Subcadenas distintas** · nivel 5

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 3000`.
- **Salida:** cuántas subcadenas **distintas** tiene.
- **Ejemplo:** `abab` → `7` (a, b, ab, ba, aba, bab, abab); `aaa` → `3`.
- **Matemática:** hay `n(n + 1)/2` subcadenas por posición; para cada largo `L`, ordena los `n − L + 1` hashes y cuenta los distintos. Calcula el costo total y la probabilidad de error.

**Problema 57.3 — Subcadena repetida más larga** · nivel 6

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 2·10^5`.
- **Salida:** la mayor longitud de una subcadena que aparece **al menos dos veces** (las apariciones pueden solaparse), o `0`.
- **Ejemplo:** `banana` → `3` (`ana`); `abcd` → `0`.
- **Matemática:** si existe una subcadena repetida de largo `L`, también existe una de largo `L − 1` (quita el último carácter de ambas copias): el predicado es monótono y se puede hacer búsqueda binaria sobre `L`, comprobando cada `L` con un conjunto de hashes en `O(n)`. Costo `O(n log n)`.

**Proyecto del día — Detector de plagio**

- **Entrada:** `k` y dos líneas con textos (palabras de minúsculas separadas por espacios, hasta `10^5` caracteres cada una).
- **Salida:** dos líneas: `jaccard: X.XX%`, donde `X` es `100 · |A ∩ B| / |A ∪ B|` y `A`, `B` son los **conjuntos de `k`-gramas de palabras** (`k` palabras consecutivas) de cada texto; y `comun: L`, la longitud (en caracteres, espacios incluidos) de la **subcadena común más larga** de ambos textos.
- **Ejemplo:** `2 / a b c d / b c d e` → `jaccard: 50.00% / comun: 5`.
- **Qué reviso:** hashing de `k`-gramas (cada palabra puede mapearse a un hash y combinarse), la subcadena común más larga con búsqueda binaria y hashes (Problema 57.3 adaptado) y el manejo de textos con menos de `k` palabras (`jaccard: 0.00%`, si ambos conjuntos son vacíos).
- **Entrega:** `d57.cpp` y `d57_notas.md`.

### Día 58 · lunes 28 de diciembre · KMP y función Z

**Teoría desde cero.** Un **borde** de una cadena es un prefijo propio que también es sufijo (en `abacaba`, `a` y `aba`). La **función prefijo** `pi[i]` es la longitud del borde más largo de `s[0..i]`. Se calcula en `O(n)`:

```cpp
vector<int> pi(n, 0);
for (int i = 1; i < n; i++) {
    int k = pi[i - 1];
    while (k > 0 && s[i] != s[k]) k = pi[k - 1];     // acorta el borde hasta que se pueda extender
    if (s[i] == s[k]) k++;
    pi[i] = k;
}
```

**Buscar un patrón `p` en un texto `t` (KMP):** calcula `pi` de `p + '#' + t` (con un carácter que no esté en el alfabeto); `p` aparece terminando en una posición cuando `pi` vale `|p|`.

**Función Z.** `z[i]` es la longitud del prefijo común más largo entre `s` y `s[i..]`:

```cpp
vector<int> z(n, 0);
for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > r) { l = i; r = i + z[i]; }
}
```

**Matemática del día.** *Costo lineal:* `k` aumenta como mucho una unidad por posición y cada vuelta del `while` lo disminuye, así que el total de vueltas es `≤ n`. *Período:* si `p = n − pi[n−1]` divide a `n`, la cadena es la repetición `n/p` veces de su prefijo de largo `p` y ese es el período mínimo; si no, el período mínimo es `n` (no se repite). *Todos los bordes:* siguiendo `n → pi[n−1] → pi[pi[n−1]−1] → …` obtienes todos los bordes.

**Problema 58.1 — Ocurrencias de un patrón** · nivel 4

- **Entrada:** dos líneas: el texto `t` y el patrón `p` (minúsculas), con `1 ≤ |p| ≤ |t| ≤ 10^6`.
- **Salida:** la cantidad de ocurrencias; si hay al menos una, en la línea siguiente las posiciones iniciales (desde 1) en orden creciente.
- **Ejemplo:** `ababa / aba` → `2 / 1 3`.
- **Matemática:** demuestra la corrección de `pi` y calcula el costo `O(|t| + |p|)`.

**Problema 58.2 — Período mínimo** · nivel 5

- **Entrada:** una cadena `s` de minúsculas, con `1 ≤ |s| ≤ 10^6`.
- **Salida:** `largo veces`: el menor `p` tal que `s` es la repetición de su prefijo de largo `p` exactamente `veces` veces (`p` divide a `n`), y `veces = n/p`.
- **Ejemplo:** `abcabcabc` → `3 3`; `abcab` → `5 1`.
- **Matemática:** demuestra que `n − pi[n−1]` es el menor período (no necesariamente divisor) y que la cadena es una repetición exacta si y solo si ese valor divide a `n`.

**Problema 58.3 — Cuántas veces aparece cada prefijo** · nivel 6

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 10^6`.
- **Salida:** `n` enteros: para cada `L` de 1 a `n`, cuántas veces aparece el prefijo de longitud `L` como subcadena de `s` (las apariciones pueden solaparse).
- **Ejemplo:** `aaa` → `3 2 1`; `abab` → `2 2 1 1`.
- **Matemática:** cada posición `i` aporta una aparición a su borde `pi[i]` y, por el encadenamiento de bordes, a todos los bordes de ese borde. Cuenta `cnt[pi[i]]++` y propaga de mayor a menor: `cnt[pi[L−1]] += cnt[L]`; luego suma 1 a cada `L` (la aparición como prefijo).

**Proyecto del día — Buscador de texto**

Un programa que cuenta las ocurrencias de un patrón con **tres métodos** y los compara.

- **Entrada:** `m`, luego el texto (una línea, hasta `10^6` caracteres) y `m` patrones (una línea cada uno, hasta 1000 caracteres).
- **Salida:** una línea por patrón con las ocurrencias halladas por KMP, y una tabla final de tiempos de: búsqueda ingenua `O(n·m)`, KMP y hashing, con `RESULTADOS IGUALES` si los tres coinciden.
- **Pruebas:** incluye en las notas la medida con el caso difícil para el método ingenuo (texto `aaaa…a` de `10^6` caracteres y patrón `aaa…ab` de 1000) y explica la diferencia.
- **Qué reviso:** KMP correcto, manejo de patrones más largos que el texto y la comparación de tiempos con `chrono`.
- **Entrega:** `d58.cpp` y `d58_notas.md`.

### Día 59 · martes 29 de diciembre · Trie y XOR máximo

**Teoría desde cero.** Un **trie** (árbol de prefijos) guarda un conjunto de cadenas en un árbol donde cada arista es una letra; las cadenas con un mismo prefijo comparten el camino. Insertar y buscar cuestan `O(longitud)`, y se puede guardar en cada nodo cuántas palabras pasan por él.

```cpp
struct Trie {
    vector<array<int, 26>> ch;
    vector<int> pasan, fin;                       // palabras que pasan por el nodo / que terminan en él
    Trie() { nuevo(); }
    int nuevo() { ch.push_back({}); fill(ch.back().begin(), ch.back().end(), -1); pasan.push_back(0); fin.push_back(0); return ch.size() - 1; }
    void insertar(const string &w) {
        int u = 0;
        for (char c : w) {
            int x = c - 'a';
            if (ch[u][x] == -1) { int v = nuevo(); ch[u][x] = v; }
            u = ch[u][x]; pasan[u]++;
        }
        fin[u]++;
    }
};
```

**Trie binario para XOR máximo.** Cada número se escribe con 30 bits (del más alto al más bajo) y se inserta como una palabra sobre `{0, 1}`. Para maximizar `x ^ y` con `y` en el conjunto, en cada bit se prefiere bajar por la rama con el bit **contrario** al de `x`:

```cpp
int max_xor(int x) {
    int u = 0, res = 0;
    for (int b = 29; b >= 0; b--) {
        int c = (x >> b & 1) ^ 1;                 // el bit opuesto
        if (ch[u][c] != -1) { res |= 1 << b; u = ch[u][c]; }
        else u = ch[u][c ^ 1];
    }
    return res;
}
```

**Matemática del día.** *Por qué el voraz del XOR es correcto:* el bit `b` pesa `2^b`, más que la suma de todos los bits menores (`2^b − 1`); así, conseguir un 1 en un bit alto siempre supera cualquier ganancia en bits bajos. *Tamaño:* a lo más `1 + 30·n` nodos. *XOR de subarreglo:* con `p_i = a_1 ^ … ^ a_i` (y `p_0 = 0`), el XOR de `a[i+1..j]` es `p_i ^ p_j`, porque los elementos repetidos se cancelan.

**Problema 59.1 — Trie de palabras** · nivel 5

- **Entrada:** `q` y `q` comandos: `ins w` (inserta la palabra `w`), `cnt p` (cuántas palabras insertadas tienen el prefijo `p`) o `has w` (`SI` si `w` fue insertada como palabra completa; si no, `NO`). Límites: `1 ≤ q ≤ 2·10^5`, longitud total `≤ 10^6`, minúsculas.
- **Salida:** la respuesta de cada `cnt` y `has`.
- **Ejemplo:** `6 / ins casa / ins casco / ins cosa / cnt ca / cnt c / has cas` → `2 / 3 / NO`.
- **Matemática:** demuestra que `pasan[u]` (contado al insertar) es exactamente el número de palabras con el prefijo que lleva a `u`. Acota la memoria (`26` enteros por nodo × `10^6` nodos).

**Problema 59.2 — Mayor XOR de una pareja** · nivel 6

- **Entrada:** `n` y `n` enteros, con `2 ≤ n ≤ 2·10^5` y `0 ≤ a_i < 2^30`.
- **Salida:** el mayor `a_i ^ a_j` con `i < j`.
- **Ejemplo:** `5 / 7 12 3 9 20` → `29` (`9 ^ 20`).
- **Matemática:** justifica el voraz bit a bit. Costo `O(30·n)`.

**Problema 59.3 — XOR máximo de un subarreglo** · nivel 6

- **Entrada:** `n` y `n` enteros, con `1 ≤ n ≤ 2·10^5` y `0 ≤ a_i < 2^30`.
- **Salida:** el mayor XOR de los elementos de un subarreglo contiguo **no vacío**.
- **Ejemplo:** `4 / 8 1 2 12` → `15` (`1 ^ 2 ^ 12`).
- **Matemática:** con prefijos `p_0, …, p_n`, el XOR de un subarreglo es `p_i ^ p_j` con `i < j`. Inserta `p_0`, y para cada `j` consulta `max_xor(p_j)` **antes** de insertar `p_j`.

**Proyecto del día — Autocompletado con frecuencias**

- **Entrada:** `n q`; `n` líneas `palabra frecuencia`; `q` prefijos. Límites: `1 ≤ n, q ≤ 10^5`, longitud total `≤ 10^6`, frecuencias hasta `10^9`, palabras distintas de minúsculas.
- **Salida:** por cada prefijo, hasta tres palabras que lo tengan, ordenadas por frecuencia **descendente** y, en empate, alfabéticamente, separadas por espacios; o `-` si no hay.
- **Ejemplo:** palabras `casa 5, casco 3, cosa 7, casas 5, caso 1`; consultas `ca`, `co`, `z` → `casa casas casco / cosa / -`.
- **Idea:** en cada nodo guarda las tres mejores palabras que pasan por él; al insertar, actualiza esa lista (`O(3)` por nodo del camino).
- **Qué reviso:** la lista de tres por nodo, el desempate y que cada consulta cueste `O(|prefijo|)`.
- **Entrega:** `d59.cpp` y `d59_notas.md`.

### Día 60 · miércoles 30 de diciembre · Función φ de Euler y exponentes enormes

**Teoría desde cero.** La **función φ de Euler**, `φ(n)`, cuenta cuántos enteros de `1` a `n` son coprimos con `n`. Por ejemplo, `φ(12) = 4` (1, 5, 7, 11) y, para un primo `p`, `φ(p) = p − 1`.

**Fórmula.** Si `n = p1^e1 · … · pk^ek`, entonces `φ(n) = n · Π (1 − 1/p_i)`. Es **multiplicativa**: `φ(a·b) = φ(a)·φ(b)` si `gcd(a, b) = 1`. Y `Σ_{d | n} φ(d) = n`.

```cpp
// φ(n) por factorización, O(sqrt n)
long long phi(long long n) {
    long long r = n;
    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0) {
            while (n % d == 0) n /= d;
            r -= r / d;                        // r *= (1 - 1/d)
        }
    if (n > 1) r -= r / n;
    return r;
}

// φ de todos los números hasta N, en O(N log log N)
vector<int> phis(N + 1);
iota(phis.begin(), phis.end(), 0);
for (int i = 2; i <= N; i++)
    if (phis[i] == i)                          // nadie lo tocó: es primo
        for (int j = i; j <= N; j += i) phis[j] -= phis[j] / i;
```

**Teorema de Euler.** Si `gcd(a, m) = 1`, entonces `a^φ(m) ≡ 1 (mod m)`. Consecuencia para exponentes gigantes: `a^e ≡ a^(e mod φ(m)) (mod m)` cuando `gcd(a, m) = 1`. Con `m` primo, `φ(m) = m − 1` (es el pequeño teorema de Fermat del Día 26).

**Matemática del día.**

- *Fórmula de φ:* los enteros de `1` a `n` no divisibles por ningún `p_i` son, por inclusión–exclusión, `n − Σ n/p_i + Σ n/(p_i p_j) − … = n·Π(1 − 1/p_i)`.
- *Euler:* los residuos coprimos con `m` son `φ(m)` y, al multiplicarlos por `a`, solo se permutan (como en Fermat); el producto queda igual y se cancela.
- *Parejas coprimas:* la cantidad de parejas `a < b ≤ n` con `gcd(a, b) = 1` es `Σ_{b=2}^{n} φ(b)`, porque para cada `b` hay `φ(b)` valores `a < b` coprimos con `b`.

**Problema 60.1 — φ(n)** · nivel 5

- **Entrada:** `T` y `T` valores `n`, con `1 ≤ T ≤ 100` y `1 ≤ n ≤ 10^12`.
- **Salida:** `φ(n)` por cada `n`.
- **Ejemplo:** `3 / 1 12 97` → `1 4 96`.
- **Matemática:** demuestra la fórmula con inclusión–exclusión y por qué `r -= r / d` evita la división inexacta (`r` siempre es múltiplo de `d` en ese punto).

**Problema 60.2 — Parejas coprimas hasta n** · nivel 5

- **Entrada:** `n`, con `1 ≤ n ≤ 5·10^6`.
- **Salida:** cuántas parejas `1 ≤ a < b ≤ n` cumplen `gcd(a, b) = 1`.
- **Ejemplo:** `5` → `9`.
- **Matemática:** demuestra `Σ_{b=2}^{n} φ(b)` y acota el resultado (`≈ 3n²/π²` ≈ `7,6·10^12`).

**Problema 60.3 — Torre de potencias** · nivel 6

Calcula `a^(b^c)` módulo `p = 10^9 + 7`.

- **Entrada:** `a b c`, con `1 ≤ a, b, c ≤ 10^18`.
- **Salida:** `a^(b^c) mod p`.
- **Ejemplo:** `2 2 5` → `294967268` (`2^32`); `3 2 3` → `6561`.
- **Matemática:** si `p` no divide a `a`, por Fermat basta el exponente `b^c mod (p − 1)`; si `p` divide a `a`, la respuesta es `0` (el exponente es `≥ 1`). Explica por qué reducir el exponente módulo `p` (en lugar de módulo `p − 1`) sería un error.

**Proyecto del día — Biblioteca de teoría de números**

Un conjunto de funciones reutilizables: criba de primos, menor factor primo, `φ` (por criba y por factorización), `potencia`, inverso modular (Euclides extendido), `crt` de dos congruencias y factorización. Un `main` que lee comandos:

- `phi n`, `fact n` (factorización `p^e * …`), `inv a m` (`-1` si no existe) y `pow a b m`.
- **Autoprueba** (resultado por `cerr`): `φ` por criba contra `φ` por conteo con `gcd` para `n ≤ 2000`; `Σ_{d | n} φ(d) = n` para `n ≤ 10^5`; el teorema de Euler con 1000 pares aleatorios; y que `inv` produzca un inverso verdadero.
- **Ejemplo:** `phi 12` → `4`; `inv 3 7` → `5`; `pow 2 10 1000` → `24`; `fact 360` → `2^3 * 3^2 * 5`.
- **Qué reviso:** reutilización sin duplicar código, la autoprueba y los casos borde (`n = 1`, `m = 1`).
- **Entrega:** `d60.cpp` y `d60_notas.md`.

### Día 61 · jueves 31 de diciembre · Inclusión–exclusión

**Teoría desde cero.** Para contar la **unión** de conjuntos sin repetir:

`|A1 ∪ … ∪ Ak| = Σ|Ai| − Σ|Ai ∩ Aj| + Σ|Ai ∩ Aj ∩ Al| − …`

Se programa con una máscara sobre los `2^k` subconjuntos de conjuntos, con signo `(−1)^(|S|+1)`. Aplicaciones típicas:

- *Números hasta `n` no divisibles por ninguno de unos primos dados:* `Σ_S (−1)^|S| · floor(n / producto(S))`.
- *Desarreglos* (permutaciones sin puntos fijos): `D(n) = (n − 1)·(D(n − 1) + D(n − 2))`, con `D(0) = 1`, `D(1) = 0`.
- *Funciones sobreyectivas:* cadenas de largo `n` sobre un alfabeto de `m` letras que usan **todas** las letras: `Σ_{j=0}^{m} (−1)^j · C(m, j) · (m − j)^n`.

```cpp
long long sin_divisores(long long n, const vector<long long> &p) {    // p: primos distintos, k <= 15
    int k = p.size(); long long res = 0;
    for (int m = 0; m < (1 << k); m++) {
        long long prod = 1; bool cero = false;
        for (int i = 0; i < k; i++) if (m >> i & 1) {
            if (prod > n / p[i]) { cero = true; break; }              // el producto ya pasa de n
            prod *= p[i];
        }
        if (cero) continue;
        res += (__builtin_popcount(m) % 2 ? -1 : 1) * (n / prod);
    }
    return res;
}
```

**Matemática del día.** *Demostración:* si un elemento pertenece a exactamente `t ≥ 1` de los conjuntos, el lado derecho lo cuenta `Σ_{j=1}^{t} (−1)^(j+1)·C(t, j) = 1` veces (por el teorema del binomio, `Σ_{j=0}^{t} (−1)^j·C(t, j) = 0`). *Desarreglos:* por inclusión–exclusión, `D(n) = Σ_{k=0}^{n} (−1)^k · n!/k!`; la recurrencia sale de decidir dónde queda el elemento 1 y si el elemento que lo ocupa vuelve al lugar 1 o no.

**Problema 61.1 — Sin divisores dados** · nivel 5

- **Entrada:** `n k` y `k` primos distintos, con `1 ≤ n ≤ 10^18`, `1 ≤ k ≤ 15` y primos menores que 100.
- **Salida:** cuántos enteros de `1` a `n` no son divisibles por ninguno de esos primos.
- **Ejemplo:** `30 3 / 2 3 5` → `8`; `100 2 / 2 5` → `40`.
- **Matemática:** aplica la fórmula con signos y comprueba el segundo ejemplo a mano (`100 − 50 − 20 + 10`). ¿Por qué se puede cortar cuando el producto supera `n`?

**Problema 61.2 — Desarreglos** · nivel 6

- **Entrada:** `n`, con `1 ≤ n ≤ 10^6`.
- **Salida:** `D(n)` módulo `10^9 + 7`.
- **Ejemplo:** `4` → `9`; `5` → `44`; `1` → `0`.
- **Matemática:** demuestra `D(n) = (n − 1)·(D(n−1) + D(n−2))` clasificando según dónde queda el elemento 1 (en la posición `j`) y si el elemento `j` queda en la posición 1 (caso `D(n−2)`) o no (caso `D(n−1)`).

**Problema 61.3 — Cadenas que usan todas las letras** · nivel 7

- **Entrada:** `n m`, con `1 ≤ n ≤ 10^9` y `1 ≤ m ≤ 10^6`.
- **Salida:** cuántas cadenas de largo `n` sobre un alfabeto de `m` letras usan cada letra al menos una vez, módulo `10^9 + 7`.
- **Ejemplo:** `3 2` → `6`; `4 3` → `36`.
- **Matemática:** sea `A_i` el conjunto de cadenas que **no** usan la letra `i`; cuenta el complemento de la unión con inclusión–exclusión: `Σ_j (−1)^j C(m, j) (m − j)^n`. Calcula los `C(m, j)` con factoriales (Día 26) y las potencias con `potencia`. Costo `O(m log n)`.

**Proyecto del día — Contador combinatorio verificado**

Implementa las tres funciones de hoy y una **verificación por fuerza bruta**.

- **Comandos** (hasta el fin de la entrada): `sindiv n p1 p2 …`, `desarreglos n` y `sobre n m`, con el mismo formato de respuestas que los problemas.
- **Autoprueba** (por `cerr`): `desarreglos` contra el conteo de todas las permutaciones sin puntos fijos para `n ≤ 9`; `sobre` contra la enumeración de las `m^n` cadenas para `n ≤ 7` y `m ≤ 4`; y `sindiv` contra un recorrido de `1..n` para `n ≤ 10^5`.
- **Qué reviso:** la fuerza bruta es genuinamente independiente, los casos `n < m` (la respuesta de `sobre` es 0) y los módulos.
- **Entrega:** `d61.cpp` y `d61_notas.md`.

### Día 62 · viernes 1 de enero · Probabilidad y esperanza

**Teoría desde cero.** La **probabilidad** de un suceso en un espacio de resultados igualmente probables es `favorables / totales`. La **esperanza** (valor esperado) de una variable aleatoria `X` es `E[X] = Σ x · P(X = x)`: el promedio a largo plazo.

**Linealidad de la esperanza:** `E[X + Y] = E[X] + E[Y]` **siempre**, aunque `X` e `Y` dependan una de la otra. Es la herramienta más poderosa: para contar "cuántos objetos cumplen algo", escribe la cantidad como suma de **indicadores** `I_i` (1 si el objeto `i` lo cumple, 0 si no) y suma sus probabilidades, `E[Σ I_i] = Σ P(I_i = 1)`.

**Esperanza módulo `p`.** Las respuestas son fracciones `a/b`; se entregan como `a · b^(−1) mod p` (inverso modular del Día 26).

```cpp
// inversos de 1..N en O(N): inv[i] = -(p / i) * inv[p mod i]
vector<long long> inv(N + 1, 1);
for (int i = 2; i <= N; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
```

**Matemática del día.**

- *Inversiones esperadas:* en una permutación aleatoria, cada pareja `i < j` está invertida con probabilidad `1/2` (por simetría, `a_i > a_j` y `a_i < a_j` son igual de probables). Hay `C(n, 2)` parejas: `E = n(n − 1)/4`.
- *Máximos de prefijo:* el elemento en la posición `i` es el mayor de los primeros `i` con probabilidad `1/i`, así que el número esperado de récords es `H_n = 1 + 1/2 + … + 1/n`.
- *Coleccionista de cupones:* con `k` tipos ya reunidos de `n`, el tiempo de espera para uno nuevo tiene distribución geométrica con éxito `(n − k)/n` y esperanza `n/(n − k)`; sumando, `E = n·H_n`.
- *Caras seguidas:* sea `E_k` la espera esperada para obtener `k` caras consecutivas con una moneda justa. Tras reunir `k − 1` caras seguidas (esperanza `E_{k−1}`), tiras otra vez: con probabilidad `1/2` terminas, con `1/2` empiezas de cero; así `E_k = E_{k−1} + 1 + E_k/2`, y por tanto `E_k = 2·E_{k−1} + 2`, con `E_0 = 0`.

**Problema 62.1 — Suma esperada de dados** · nivel 5

- **Entrada:** `k m`, con `1 ≤ k, m ≤ 10^18`: se lanzan `k` dados justos de `m` caras (numeradas de `1` a `m`).
- **Salida:** la esperanza de la suma, como `a · b^(−1) mod 10^9 + 7`.
- **Ejemplo:** `2 6` → `7`; `1 2` → `500000005` (la esperanza es `3/2`).
- **Matemática:** demuestra `E = k·(m + 1)/2` con linealidad y calcula el valor módulo `p` reduciendo `k` y `m + 1` antes de multiplicar.

**Problema 62.2 — Inversiones y récords esperados** · nivel 6

- **Entrada:** `n`, con `1 ≤ n ≤ 10^6`.
- **Salida:** dos números, módulo `10^9 + 7`: el número esperado de inversiones y el número esperado de máximos de prefijo (récords) de una permutación aleatoria de `n` elementos.
- **Ejemplo:** `3` → `500000005 833333341` (`3/2` y `11/6`).
- **Matemática:** deduce ambas fórmulas con indicadores (`n(n − 1)/4` y `H_n`) y calcula `H_n` con la tabla de inversos en `O(n)`.

**Problema 62.3 — Caras seguidas** · nivel 6

- **Entrada:** `k`, con `1 ≤ k ≤ 10^18`.
- **Salida:** el número esperado de lanzamientos de una moneda justa hasta obtener `k` caras seguidas, módulo `10^9 + 7`.
- **Ejemplo:** `3` → `14`.
- **Matemática:** demuestra `E_k = 2^(k+1) − 2` resolviendo la recurrencia `E_k = 2E_{k−1} + 2` por inducción y calcula `2^(k+1)` con `potencia`.

**Proyecto del día — Monte Carlo contra exacto**

Un programa que compara **tres esperanzas** calculadas exactamente con la simulación de muchos experimentos.

- **Experimentos** (`10^6` repeticiones cada uno, `mt19937_64` con semilla fija): (1) número de récords de una permutación aleatoria de tamaño 10 (exacto `H_10 = 2,928968…`); (2) número de lanzamientos para ver los 10 tipos de un coleccionista de cupones (exacto `10·H_10 = 29,289682…`); (3) lanzamientos hasta 5 caras seguidas (exacto `62`).
- **Salida:** una tabla `experimento exacto simulado error_relativo` con 4 decimales.
- **Qué reviso:** simulaciones correctas (una permutación uniforme con `shuffle`), cálculo exacto independiente (con fracciones o `double`) y el análisis en las notas: el error relativo esperado de un promedio de `N` repeticiones es del orden de `σ / (μ·√N)`; compara con tus resultados.
- **Entrega:** `d62.cpp` y `d62_notas.md`.

### Día 63 · sábado 2 de enero · Simulacro 2 estilo IOI

**Teoría: una herramienta más, la función de Möbius.** Para el tercer problema de hoy necesitas `μ(d)`: vale `0` si `d` tiene un factor primo repetido y `(−1)^k` si `d` es producto de `k` primos distintos (`μ(1) = 1`). Propiedad clave: `Σ_{d | g} μ(d) = 1` si `g = 1` y `0` si `g > 1` (es inclusión–exclusión sobre los primos de `g`).

```cpp
vector<int> mu(N + 1, 1); vector<bool> comp(N + 1, false);
for (int i = 2; i <= N; i++) if (!comp[i]) {                  // i es primo
    for (int j = i; j <= N; j += i) { if (j > i) comp[j] = true; mu[j] = -mu[j]; }
    for (long long j = (long long)i * i; j <= N; j += (long long)i * i) mu[j] = 0;
}
```

Estrategia de simulacro: la misma de los Días 35 y 49. Tiempo sugerido: 3 horas.

**Problema 63.1 — Bordes** · nivel 6

Un **borde** de una cadena `s` es una longitud `L` (con `1 ≤ L < |s|`) tal que el prefijo de largo `L` es igual al sufijo de largo `L`.

- **Entrada:** una cadena `s` de minúsculas, con `1 ≤ |s| ≤ 10^6`.
- **Salida:** una línea con `k L1 L2 … Lk`: la cantidad de bordes y sus longitudes en orden creciente (si no hay, escribe solo `0`).
- **Subtareas:** (20 puntos) `|s| ≤ 100`; (30 puntos) `|s| ≤ 5000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `abacaba` → `2 1 3`.
- **Matemática:** demuestra que los bordes de `s` son `pi[n−1]`, `pi[pi[n−1]−1]`, … hasta 0 (los bordes de un borde son bordes de la cadena).

**Problema 63.2 — Rebajas** · nivel 6

Una tienda ofrece `n` artículos en fila, con precios `a_i ≥ 0`. Un cliente compra siempre **desde el primero**, en orden, mientras el total no pase su presupuesto `x`. Los precios pueden cambiar.

- **Entrada:** `n q`; los `n` precios; luego `q` operaciones: `1 i v` (el precio del artículo `i` pasa a `v`) o `2 x` (cuántos artículos compra un cliente con presupuesto `x`). Límites: `1 ≤ n, q ≤ 2·10^5`, `0 ≤ a_i, v ≤ 10^9`, `0 ≤ x ≤ 10^15`.
- **Salida:** la respuesta de cada operación de tipo 2.
- **Subtareas:** (20 puntos) `n, q ≤ 100`; (30 puntos) `n, q ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 4 / 3 1 4 1 5 / 2 8 / 1 3 10 / 2 8 / 2 2` → `3 / 2 / 0`.
- **Matemática:** como los precios no son negativos, la suma prefija es no decreciente y la respuesta es el mayor `p` con `suma(1..p) ≤ x`. Un BIT con descenso (Día 50) la halla en `O(log n)`. Explica por qué falla si hubiera precios negativos.

**Problema 63.3 — Parejas coprimas** · nivel 7

- **Entrada:** `n` y `n` enteros, con `1 ≤ n ≤ 10^5` y `1 ≤ a_i ≤ 10^6`.
- **Salida:** cuántas parejas `i < j` cumplen `gcd(a_i, a_j) = 1`.
- **Subtareas:** (20 puntos) `n ≤ 100`; (30 puntos) `n ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `4 / 2 3 4 9` → `4`.
- **Matemática:** con `Σ_{d | g} μ(d) = [g = 1]`, el número de parejas coprimas es `Σ_d μ(d) · C(c_d, 2)`, donde `c_d` es la cantidad de elementos divisibles por `d`. Calcula `c_d` recorriendo los múltiplos de `d` en la tabla de frecuencias (costo `Σ M/d ≈ M ln M`). Justifica la identidad.

**Proyecto del día — Informe del simulacro 2**

1. Resuelve los tres problemas con el tiempo sugerido y anota cuánto te tomó cada uno.
2. Entrega la mejor solución completa de cada uno (indica qué lograste dentro del tiempo y qué después).
3. Para cada problema, un test de estrés contra la fuerza bruta de su primera subtarea (3000 casos aleatorios pequeños).
4. En las notas, una tabla con las subtareas logradas, el puntaje estimado, la causa de cada subtarea perdida y una acción concreta de mejora. Compara con tus informes de los Días 35 y 49: ¿qué mejoró?

- **Qué califico:** que cada solución completa cumpla los límites de la última subtarea, la independencia de los tests de estrés y la calidad del análisis.
- **Entrega:** `d63_p1.cpp`, `d63_p2.cpp`, `d63_p3.cpp` y `d63_notas.md`.

---

## Semana 10 · 3–9 ene · Programación dinámica avanzada

**Objetivo:** dominar las familias de DP que aparecen en problemas de nivel IOI: sobre subconjuntos (máscaras), sobre dígitos, con transiciones optimizadas, sobre intervalos, con optimización convexa y con exponenciación de matrices.

### Día 64 · domingo 3 de enero · DP con máscaras de bits

**Teoría desde cero.** Cuando `n ≤ 20`, el **estado** puede ser un **subconjunto** de los `n` elementos, guardado como una máscara de `n` bits (Día 25). La DP recorre las máscaras de menor a mayor: `dp[mask]` resume "qué se hizo con los elementos de `mask`".

**Asignación óptima.** `n` trabajadores y `n` tareas con costo `c[i][j]`. Los trabajadores se asignan en orden; el trabajador `i` es el que corresponde a la cantidad de bits de la máscara:

```cpp
vector<long long> dp(1 << n, INF);
dp[0] = 0;
for (int m = 0; m < (1 << n); m++) {
    if (dp[m] == INF) continue;
    int i = __builtin_popcount(m);                      // trabajador que recibe la siguiente tarea
    if (i == n) continue;
    for (int j = 0; j < n; j++) if (!(m >> j & 1))
        dp[m | 1 << j] = min(dp[m | 1 << j], dp[m] + c[i][j]);
}
// respuesta: dp[(1 << n) - 1]
```

**Viajante (TSP).** `dp[mask][u]` = menor costo de un camino que sale de la ciudad 0, visita exactamente las ciudades de `mask` y termina en `u`. Transición: ir de `u` a una ciudad `v` fuera de `mask`. Costo `O(2^n · n²)`: con `n = 16`, unos `1,7·10^7`.

**Subconjuntos de un subconjunto.** Para recorrer todos los `s ⊆ m` (no vacíos): `for (int s = m; s > 0; s = (s - 1) & m)`. Recorrer así las submáscaras de todas las máscaras cuesta `O(3^n)`.

**Matemática del día.** *Cantidad de estados y transiciones:* hay `2^n` máscaras; cada una prueba `n` bits (asignación) o `n²` parejas (TSP). *Costo de las submáscaras:* cada elemento está, en cada pareja `(s, m)` con `s ⊆ m`, en uno de tres estados (fuera de `m`, en `m` pero no en `s`, en ambos), así que hay `3^n` parejas. *Por qué la DP es correcta:* el trabajador `i` (o la ciudad actual) solo depende de qué elementos ya se usaron, no del orden en que se usaron.

**Problema 64.1 — Asignación** · nivel 6

- **Entrada:** `n` y una matriz `n × n` de costos, con `1 ≤ n ≤ 20` y `0 ≤ c ≤ 10^6`.
- **Salida:** el costo mínimo de asignar cada trabajador a una tarea distinta.
- **Ejemplo:** `3 / 9 2 7 / 6 4 3 / 5 8 1` → `9`.
- **Matemática:** justifica por qué basta una máscara de tareas usadas (el trabajador es `popcount(m)`) y calcula las operaciones para `n = 20` (`2^20 · 20 ≈ 2·10^7`).

**Problema 64.2 — Viajante** · nivel 6

- **Entrada:** `n` y la matriz de distancias `n × n` (no necesariamente simétrica), con `2 ≤ n ≤ 16` y `1 ≤ d ≤ 10^6` fuera de la diagonal.
- **Salida:** el costo mínimo de un ciclo que sale de la ciudad 1, visita todas exactamente una vez y regresa.
- **Ejemplo:** `4 / 0 2 9 10 / 1 0 6 4 / 15 7 0 8 / 6 3 12 0` → `21` (ruta `1 3 4 2 1`).
- **Matemática:** define `dp[mask][u]`, demuestra la recurrencia y cuenta memoria: `2^16 · 16` valores de 8 bytes son 8 MB.

**Problema 64.3 — Empacar en bolsas** · nivel 7

- **Entrada:** `n C` y `n` pesos, con `1 ≤ n ≤ 16`, `1 ≤ C ≤ 10^9` y `1 ≤ w_i ≤ C`.
- **Salida:** la menor cantidad de bolsas de capacidad `C` para guardar todos los objetos.
- **Ejemplo:** `4 10 / 6 5 4 5` → `2`; `5 10 / 6 6 6 3 3` → `3`.
- **Matemática:** el estado es la máscara de objetos ya guardados y el valor es el par `(bolsas usadas, carga de la última bolsa)` mínimo en orden lexicográfico. Demuestra que minimizar ese par es suficiente: para el mismo número de bolsas, conviene que la última esté lo más vacía posible. Costo `O(2^n · n)`.

**Proyecto del día — Planificador de reparto**

Programa que resuelve el viajante y **muestra la ruta**.

- **Entrada:** como en el Problema 64.2.
- **Salida:** la línea con el costo mínimo y, en la siguiente, la ruta `1 … 1` que lo alcanza, eligiendo, entre las rutas óptimas, la **lexicográficamente menor**. Para lograrlo, calcula la DP "hacia atrás" (`dp[mask][u]` = menor costo de terminar el recorrido desde `u` habiendo visitado `mask`) y reconstruye eligiendo en cada paso la menor ciudad que mantenga el óptimo.
- **Ejemplo:** `4 / 0 2 9 10 / 1 0 6 4 / 15 7 0 8 / 6 3 12 0` → `21 / 1 3 4 2 1`.
- **Qué reviso:** la reconstrucción, el uso de `INF` sin desbordar y una prueba contra fuerza bruta (todas las permutaciones) para `n ≤ 8`.
- **Entrega:** `d64.cpp` y `d64_notas.md`.

### Día 65 · lunes 4 de enero · DP de dígitos

**Teoría desde cero.** Para contar cuántos números de `[0, N]` cumplen una propiedad que depende de sus **dígitos** (suma, repeticiones, divisibilidad), con `N` hasta `10^18`, se construye el número dígito a dígito de izquierda a derecha. El estado es `(posición, información acumulada, tope)`, donde `tope` indica si los dígitos puestos hasta ahora son **iguales al prefijo de `N`** (si es así, el siguiente dígito no puede pasar del de `N`).

```cpp
string s;                                         // dígitos de N, por ejemplo "1234"
long long memo[20][7][2];
long long f(int pos, int rem, bool tope) {        // ¿cuántos completan un múltiplo de 7?
    if (pos == (int)s.size()) return rem == 0;
    long long &m = memo[pos][rem][tope];
    if (m != -1) return m;
    long long r = 0;
    int lim = tope ? s[pos] - '0' : 9;
    for (int d = 0; d <= lim; d++)
        r += f(pos + 1, (rem * 10 + d) % 7, tope && d == lim);
    return m = r;
}
// para cada N nuevo: memset(memo, -1, sizeof memo); respuesta f(0, 0, true)
```

- **Intervalo `[L, R]`:** `contar(R) − contar(L − 1)`.
- **Ceros a la izquierda:** si la propiedad depende de los dígitos "reales" (por ejemplo, que no haya dos iguales juntos), agrega al estado si el número ya **empezó** (si ya se puso un dígito distinto de 0).
- **Costo:** estados × 10 transiciones. Con `20 · 7 · 2` estados, es instantáneo.

**Matemática del día.** *Por qué funciona `tope`:* el conjunto de números `≤ N` con una longitud fija se parte según el primer dígito donde se separan de `N`; antes de ese dígito son iguales a `N` (`tope` activo) y después son libres (`tope` inactivo). *Cantidad de estados:* longitud × valores de la información × 2. Para la suma de dígitos de un número de 18 cifras, la suma va de 0 a 162.

**Problema 65.1 — Suma de dígitos** · nivel 6

- **Entrada:** `N S`, con `0 ≤ N ≤ 10^18` y `0 ≤ S ≤ 162`.
- **Salida:** cuántos enteros de `[0, N]` tienen suma de dígitos exactamente `S`.
- **Ejemplo:** `100 5` → `6` (5, 14, 23, 32, 41, 50).
- **Matemática:** cuenta estados (`19 · 163 · 2`) y justifica el límite `S ≤ 162` (`18 · 9`).

**Problema 65.2 — Sin dígitos iguales adyacentes** · nivel 6

- **Entrada:** `L R`, con `1 ≤ L ≤ R ≤ 10^18`.
- **Salida:** cuántos enteros de `[L, R]` no tienen dos dígitos iguales consecutivos (en su escritura decimal sin ceros a la izquierda).
- **Ejemplo:** `1 100` → `90`.
- **Matemática:** explica el estado `empezó` (los ceros a la izquierda no cuentan como dígitos) y el uso de `contar(R) − contar(L − 1)`; comprueba el ejemplo: `100 − 9 (11, 22, …, 99) − 1 (100) = 90`.

**Problema 65.3 — Múltiplos con suma de dígitos múltiplo** · nivel 7

- **Entrada:** `N K`, con `1 ≤ N ≤ 10^18` y `1 ≤ K ≤ 50`.
- **Salida:** cuántos enteros de `[1, N]` son divisibles entre `K` y tienen una suma de dígitos divisible entre `K`.
- **Ejemplo:** `100 3` → `33`; `1000 5` → `39`.
- **Matemática:** el estado es `(posición, resto del número módulo K, resto de la suma módulo K, tope)`; cuenta estados (`19 · 50 · 50 · 2`) y justifica por qué la respuesta para `K = 3` es la cantidad de múltiplos de 3 (los criterios de divisibilidad entre 3 y la suma de dígitos coinciden).

**Proyecto del día — Marco de DP de dígitos**

Una plantilla reutilizable de DP de dígitos y tres comandos:

- `suma N S`, `sinrep L R`, `div N K`, con el mismo significado que los problemas de hoy.
- **Autoprueba** (por `cerr`): cada comando contra una enumeración directa para `N ≤ 10^5`.
- **Qué reviso:** la plantilla (separar el cálculo de `contar(N)` de la propiedad concreta), el manejo de `L = 1` (`contar(0)`) y los casos `N = 0`.
- **Ejemplo:** `suma 100 5` → `6`; `sinrep 1 100` → `90`; `div 100 3` → `33`.
- **Entrega:** `d65.cpp` y `d65_notas.md`.

### Día 66 · martes 5 de enero · DP con transiciones optimizadas

**Teoría desde cero.** A veces el estado es fácil pero la **transición** es lenta: `dp[i]` depende de **todos** los `dp[j]` en una ventana, o de todos los `j` que cumplen una condición. Tres herramientas la aceleran:

- **Sumas prefijas:** si `dp[i] = Σ_{j=i−K}^{i−1} dp[j]`, escribe la suma como `P[i−1] − P[i−K−1]`.
- **Deque monótono:** si `dp[i] = c[i] + min_{j ∈ [i−K, i−1]} dp[j]`, mantén un deque de índices con `dp` creciente (Día 23):

```cpp
deque<int> dq;                                       // índices; dp[dq.front()] es el mínimo de la ventana
dp[0] = 0; dq.push_back(0);
for (int i = 1; i < n; i++) {
    while (!dq.empty() && dq.front() < i - K) dq.pop_front();   // salió de la ventana
    dp[i] = dp[dq.front()] + c[i];
    while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
    dq.push_back(i);
}
```

- **Estructura de datos sobre los valores:** si `dp[i] = w_i + max{dp[j] : j < i, a_j < a_i}`, un BIT de máximos indexado por `a` (comprimido) responde "el máximo de los `dp[j]` con `a_j < a_i`" en `O(log n)`.

**Matemática del día.** *Del costo `O(n·K)` a `O(n)`:* cada índice entra y sale del deque una sola vez. *Corrección:* el deque conserva solo los candidatos que pueden ser el mínimo mientras permanezcan en la ventana: si `j < j'` y `dp[j] ≥ dp[j']`, `j` nunca será mejor que `j'` (sale antes y vale más). *Prefijos de máximo:* con un BIT de máximo, las actualizaciones solo **aumentan** valores, que es lo que permite usar el prefijo.

**Problema 66.1 — Saltos con alcance** · nivel 6

- **Entrada:** `n K` y `n` costos `c_i`, con `1 ≤ K ≤ n ≤ 10^6` y `0 ≤ c_i ≤ 10^9`. Empiezas en la piedra 1 (sin pagar su costo) y en cada salto avanzas entre 1 y `K` piedras, pagando el costo de la piedra donde caes.
- **Salida:** el costo mínimo para llegar a la piedra `n`.
- **Ejemplo:** `5 2 / 0 4 1 7 2` → `3` (piedras `1 → 3 → 5`).
- **Matemática:** demuestra que el deque conserva siempre el mínimo de la ventana y que cada índice entra y sale una vez.

**Problema 66.2 — Subsecuencia con saltos acotados** · nivel 7

- **Entrada:** `n K` y `n` enteros `a_i`, con `1 ≤ K ≤ n ≤ 10^6` y `|a_i| ≤ 10^9`.
- **Salida:** la mayor suma de una subsecuencia **no vacía** de índices `i_1 < i_2 < …` donde cada par consecutivo cumple `i_{t+1} − i_t ≤ K`.
- **Ejemplo:** `6 2 / 3 -5 4 -1 -2 6` → `12` (índices 1, 3, 4, 6).
- **Matemática:** `dp[i] = a_i + max(0, max_{j ∈ [i−K, i−1]} dp[j])` (el `0` permite empezar en `i`). La respuesta es `max dp[i]`. Justifica el término `max(0, …)` y usa un deque de máximos.

**Problema 66.3 — LIS ponderada** · nivel 7

- **Entrada:** `n`, luego `n` valores `a_i` y luego `n` pesos `w_i`, con `1 ≤ n ≤ 2·10^5`, `|a_i| ≤ 10^9` y `1 ≤ w_i ≤ 10^9`.
- **Salida:** el mayor peso total de una subsecuencia **estrictamente creciente** en `a`.
- **Ejemplo:** `5 / 3 1 4 2 5 / 10 1 5 8 2` → `17` (valores 3, 4, 5).
- **Matemática:** `dp[i] = w_i + max{dp[j] : j < i, a_j < a_i}`; usa un BIT de máximo sobre `a` comprimido. Explica por qué se consulta **antes** de insertar `dp[i]` (para no usar a `i` dos veces y para exigir `<` estricto).

**Proyecto del día — Saltos: fuerza bruta contra optimizado**

- **Programa:** implementa el Problema 66.1 de dos formas: `O(n·K)` directa y `O(n)` con deque.
- **Pruebas:** compara ambas con 3000 casos aleatorios pequeños y mide el tiempo para `n = 10^6` y `K = 10^3` (por `cerr` o en una tabla).
- **Qué reviso:** que la fuerza bruta no use el deque, que el deque se vacíe correctamente de índices fuera de la ventana y que el programa lea la entrada del Problema 66.1.
- **Notas:** explica la diferencia de tiempos con las complejidades.
- **Entrega:** `d66.cpp` y `d66_notas.md`.

### Día 67 · miércoles 6 de enero · DP de intervalos

**Teoría desde cero.** En una **DP de intervalos**, el estado es un tramo `[l, r]` de una secuencia y la respuesta se obtiene **partiendo** el tramo en dos (o eligiendo qué elemento se trata *último*). Se calcula por **longitud creciente**.

```cpp
for (int len = 2; len <= n; len++)
    for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        dp[l][r] = INF;
        for (int k = l; k < r; k++)                       // punto de corte
            dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + costo(l, k, r));
    }
```

Costo típico `O(n³)` (`n²` estados × `n` cortes): sirve hasta `n ≈ 400`.

**Matemática del día.** *Subestructura óptima:* una solución óptima para `[l, r]` tiene un "último paso" (el último corte, el último globo, la última multiplicación) y lo que ocurre a cada lado es una solución óptima de un tramo más corto e **independiente** del otro lado. *Cantidad de formas de colocar paréntesis:* para multiplicar `n` matrices hay `C_{n−1}` formas, con `C_m` el `m`-ésimo número de Catalan (Día 28): crece exponencialmente, de ahí la importancia de la DP en vez de probar todas.

**Problema 67.1 — Cortes en palíndromos** · nivel 6

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 2000`.
- **Salida:** el mínimo de cortes para partir `s` en piezas que sean todas palíndromos.
- **Ejemplo:** `aab` → `1`; `abcba` → `0`; `abc` → `2`.
- **Matemática:** calcula `pal[l][r]` en `O(n²)` (`pal[l][r] = (s[l] = s[r]) y pal[l+1][r−1]`) y luego `dp[i] = min_j dp[j] + 1` sobre los `j` con `s[j..i−1]` palíndromo. Justifica ambas recurrencias.

**Problema 67.2 — Multiplicación de matrices en cadena** · nivel 6

- **Entrada:** `n` y `n + 1` enteros `p_0, …, p_n` (la matriz `i` tiene dimensiones `p_{i−1} × p_i`), con `1 ≤ n ≤ 400` y `1 ≤ p ≤ 100`.
- **Salida:** el mínimo de multiplicaciones escalares para calcular el producto completo.
- **Ejemplo:** `3 / 10 30 5 60` → `4500` (`(A1·A2)·A3`).
- **Matemática:** multiplicar una matriz `a × b` por una `b × c` cuesta `a·b·c`. Define `dp[l][r]` y su recurrencia con el corte `k`, y calcula el costo `O(n³)`.

**Problema 67.3 — Estallar globos** · nivel 7

Tienes `n` globos con valores `a_i`. Al estallar el globo `i` ganas `a_izquierda · a_i · a_derecha`, donde izquierda y derecha son sus vecinos **actuales** (un vecino fuera de la fila vale 1). Maximiza el total al estallarlos todos.

- **Entrada:** `n` y `n` valores, con `1 ≤ n ≤ 300` y `0 ≤ a_i ≤ 100`.
- **Salida:** la ganancia máxima.
- **Ejemplo:** `4 / 3 1 5 8` → `167`.
- **Matemática:** piensa en el globo que estalla **último** en `(l, r)`: sus vecinos son los bordes `l` y `r`, y los dos lados quedan independientes. Esto da `dp[l][r] = max_k dp[l][k] + dp[k][r] + a_l·a_k·a_r` (con `1` agregado en ambos extremos). Explica por qué pensar en el **primero** que estalla no funciona.

**Proyecto del día — Optimizador de multiplicación con paréntesis**

- **Entrada:** como en el Problema 67.2.
- **Salida:** el costo mínimo y, en la línea siguiente, una expresión con los paréntesis óptimos (`A1`, `A2`, …); entre varios cortes óptimos, usa el **menor** `k`.
- **Ejemplo:** `3 / 10 30 5 60` → `4500 / ((A1 A2) A3)`.
- **Qué reviso:** una tabla de cortes `corte[l][r]`, la reconstrucción recursiva, y una prueba contra la enumeración de todas las formas de poner paréntesis para `n ≤ 8`.
- **Notas:** muestra el número de formas de colocar paréntesis para `n = 1..10` (Catalan).
- **Entrega:** `d67.cpp` y `d67_notas.md`.

### Día 68 · jueves 7 de enero · Optimización convexa: rectas (CHT) y divide y vencerás

**Teoría desde cero.** Algunas DP tienen la forma `dp[i] = min_j (dp[j] + b_j·x_i + c_i)`: para cada `j` hay una **recta** `y = m_j·x + k_j`, y `dp[i]` es el mínimo de esas rectas evaluado en `x_i`. El **truco de la envolvente convexa** (*convex hull trick*, CHT) mantiene solo las rectas que alguna vez son el mínimo.

**Caso monótono** (pendientes decrecientes, consultas `x` crecientes), con un deque:

```cpp
struct Recta { long long m, b; long long en(long long x) const { return m * x + b; } };
deque<Recta> dq;
bool sobra(const Recta &l1, const Recta &l2, const Recta &l3) {      // ¿l2 nunca es mínima?
    return (__int128)(l3.b - l1.b) * (l1.m - l2.m) <= (__int128)(l2.b - l1.b) * (l1.m - l3.m);
}
void agregar(Recta r) {
    while (dq.size() >= 2 && sobra(dq[dq.size() - 2], dq.back(), r)) dq.pop_back();
    dq.push_back(r);
}
long long consultar(long long x) {                                    // x no decreciente
    while (dq.size() >= 2 && dq[0].en(x) >= dq[1].en(x)) dq.pop_front();
    return dq[0].en(x);
}
```

**Caso general: árbol de Li Chao.** Cada nodo (un tramo de abscisas) guarda **una** recta; al insertar una nueva, la peor de las dos en el punto medio solo puede ganar en una mitad y baja allí. Sirve con rectas y consultas en cualquier orden, en `O(log n)` cada una:

```cpp
struct LiChao {
    vector<long long> xs;                                // abscisas de consulta, ordenadas y distintas
    vector<Recta> t;
    LiChao(vector<long long> v) : xs(v), t(4 * v.size(), {0, (long long)4e18}) {}
    void agregar(int x, int l, int r, Recta nueva) {
        int m = (l + r) / 2;
        bool izq = nueva.en(xs[l]) < t[x].en(xs[l]);
        bool med = nueva.en(xs[m]) < t[x].en(xs[m]);
        if (med) swap(t[x], nueva);                      // en el medio queda la mejor
        if (l == r) return;
        if (izq != med) agregar(2 * x, l, m, nueva);     // la perdedora puede ganar a la izquierda
        else agregar(2 * x + 1, m + 1, r, nueva);
    }
    long long consultar(int x, int l, int r, int i) {    // mínimo en xs[i]
        long long res = t[x].en(xs[i]);
        if (l == r) return res;
        int m = (l + r) / 2;
        return min(res, i <= m ? consultar(2 * x, l, m, i) : consultar(2 * x + 1, m + 1, r, i));
    }
};
```

**Divide y vencerás para DP.** Si `dp[g][i] = min_{k < i} dp[g−1][k] + C(k + 1, i)` y el punto óptimo `opt(i)` es **no decreciente** en `i`, se calcula una capa entera en `O(n log n)`: resuelve el punto medio probando solo `opt ∈ [optl, optr]` y reparte el rango (`ant` es la capa anterior, `act` la que se está llenando):

```cpp
void calc(int l, int r, int optl, int optr) {            // llena cur[l..r]
    if (l > r) return;
    int m = (l + r) / 2, mejor = optl; long long val = INF;
    for (int k = optl; k <= min(m - 1, optr); k++) {
        long long c = ant[k] + costo(k + 1, m);
        if (c < val) { val = c; mejor = k; }
    }
    act[m] = val;
    calc(l, m - 1, optl, mejor);
    calc(m + 1, r, mejor, optr);
}
```

**Matemática del día.** *Por qué un deque sirve:* con pendientes decrecientes y `x` crecientes, la recta mínima solo "avanza" hacia las de pendiente menor; las que quedan atrás no vuelven. *Condición de `sobra`:* `l2` es innecesaria cuando `l1` y `l3` se cortan en una abscisa `≤` donde se cortan `l1` y `l2`; eso es la desigualdad de productos cruzados (con `__int128` para no desbordar). *Divide y vencerás:* la monotonía de `opt` se cumple cuando el costo cumple la **desigualdad del cuadrilátero**: `C(a, c) + C(b, d) ≤ C(a, d) + C(b, c)` para `a ≤ b ≤ c ≤ d`; para `C(l, r) = (suma[l..r])²` con valores no negativos, se cumple.

**Problema 68.1 — Mínimo de rectas** · nivel 7

- **Entrada:** `n q`; `n` líneas `m b` (la recta `y = m·x + b`); luego `q` valores `x`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|m|, |b|, |x| ≤ 10^9`.
- **Salida:** `min_i (m_i·x + b_i)` para cada `x`.
- **Ejemplo:** `3 3 / 1 0 / -1 5 / 0 2 / 0 2 6` → `0 / 2 / -1`.
- **Matemática:** demuestra que en cada nodo de Li Chao la recta que pierde en el punto medio solo puede ganar en una mitad (dos rectas se cruzan a lo más una vez). Acota los valores (`|m·x + b| ≤ 10^18 + 10^9`).

**Problema 68.2 — Dividir en k grupos** · nivel 8

- **Entrada:** `n k` y `n` enteros, con `1 ≤ k ≤ n ≤ 5000`, `k ≤ 100` y `1 ≤ a_i ≤ 100`.
- **Salida:** la menor suma de `(suma del grupo)²` al partir el arreglo en exactamente `k` grupos contiguos no vacíos.
- **Ejemplo:** `5 2 / 1 2 3 4 5` → `117` (grupos `1 2 3` y `4 5`: `36 + 81`).
- **Matemática:** plantea `dp[g][i]` y la optimización de divide y vencerás con el costo `C(l, r) = (S[r] − S[l−1])²`; comprueba la desigualdad del cuadrilátero y calcula `k · n · log n`.

**Problema 68.3 — Fábrica de lotes** · nivel 8

Divide el arreglo en cualquier cantidad de grupos contiguos; cada grupo cuesta `(suma)² + C`. Minimiza el costo total.

- **Entrada:** `n C` y `n` enteros, con `1 ≤ n ≤ 2·10^5`, `0 ≤ C ≤ 10^9` y `1 ≤ a_i ≤ 1000`.
- **Salida:** el costo mínimo.
- **Ejemplo:** `5 10 / 1 2 3 4 5` → `99`.
- **Matemática:** con sumas prefijas `S`, `dp[i] = min_j dp[j] + (S_i − S_j)² + C`. Expándelo: `dp[j] + S_j² − 2·S_i·S_j + S_i² + C`; para cada `j` es una recta de pendiente `−2·S_j` y término independiente `dp[j] + S_j²`, evaluada en `x = S_i`. Las pendientes decrecen y las consultas crecen: usa el deque.

**Proyecto del día — Biblioteca de optimización convexa**

Una biblioteca con (1) CHT monótona con deque, (2) árbol de Li Chao y (3) la plantilla de divide y vencerás para DP por capas. Con ella, resuelve los tres problemas de hoy (el `main` lee primero `1`, `2` o `3` y luego la entrada de ese problema).

- **Autoprueba** (por `cerr`): cada problema contra su DP ingenua `O(n²)` o `O(k·n²)` en 3000 casos aleatorios pequeños.
- **Qué reviso:** la corrección de `sobra` sin desbordar, que la plantilla sea reutilizable y los casos borde (`n = 1`, una sola recta).
- **Entrega:** `d68.cpp` y `d68_notas.md`.

### Día 69 · viernes 8 de enero · Exponenciación de matrices y recurrencias lineales

**Teoría desde cero.** Una **recurrencia lineal** como `F(n) = F(n−1) + F(n−2)` se puede escribir como una multiplicación de una **matriz** por un vector de estado:

`[F(n+1); F(n)] = [[1, 1], [1, 0]] · [F(n); F(n−1)]`

Aplicarla `n` veces equivale a elevar la matriz a la `n`-ésima potencia, y **la potencia de una matriz se calcula por cuadrados** igual que la de un número: `O(d³ · log n)` para una matriz `d × d`.

```cpp
using Mat = vector<vector<long long>>;
Mat mul(const Mat &A, const Mat &B) {
    int n = A.size(); Mat C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) if (A[i][k])
            for (int j = 0; j < n; j++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
Mat potencia(Mat A, long long e) {
    int n = A.size(); Mat R(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) R[i][i] = 1;               // identidad
    for (; e > 0; e >>= 1) { if (e & 1) R = mul(R, A); A = mul(A, A); }
    return R;
}
```

**Aplicaciones.** (1) Recurrencias de orden `d` con matriz **compañera** (la primera fila son los coeficientes; debajo, una diagonal de unos desplazada). (2) **Caminos en un grafo:** si `A` es la matriz de adyacencia, `A^k[i][j]` es el número de caminos (con repeticiones de vértices) de longitud exactamente `k` de `i` a `j`.

**Matemática del día.** *Asociatividad:* `(AB)C = A(BC)` permite agrupar potencias como `A^8 = ((A²)²)²`. *Caminos:* por inducción sobre `k`, `A^{k+1}[i][j] = Σ_t A^k[i][t]·A[t][j]` cuenta los caminos de longitud `k` de `i` a `t` seguidos de una arista `t → j`. *Matriz compañera:* para `a_n = c_1·a_{n−1} + … + c_d·a_{n−d}`, el estado `(a_n, …, a_{n−d+1})` se transforma en `(a_{n+1}, …, a_{n−d+2})` con la matriz cuya primera fila es `(c_1, …, c_d)` y cuyas filas siguientes son filas de la identidad desplazadas. *Identidad de Fibonacci:* `gcd(F(m), F(n)) = F(gcd(m, n))`.

**Problema 69.1 — Fibonacci enorme** · nivel 6

- **Entrada:** `n`, con `0 ≤ n ≤ 10^18`.
- **Salida:** `F(n) mod 10^9 + 7`, con `F(0) = 0` y `F(1) = 1`.
- **Ejemplo:** `10` → `55`; `100` → `687995182`.
- **Matemática:** demuestra que `[[1,1],[1,0]]^n = [[F(n+1), F(n)], [F(n), F(n−1)]]` por inducción.

**Problema 69.2 — Caminos de longitud exacta** · nivel 7

- **Entrada:** `n m k` y `m` aristas dirigidas `u v`, con `1 ≤ n ≤ 50`, `0 ≤ m ≤ n²`, `1 ≤ k ≤ 10^18` (puede haber lazos `u u`).
- **Salida:** la cantidad de caminos de longitud exactamente `k` de `1` a `n`, módulo `10^9 + 7`.
- **Ejemplo:** `3 4 2 / 1 2 / 2 3 / 1 3 / 3 3` → `2`.
- **Matemática:** demuestra `A^k[i][j] = número de caminos de longitud k` por inducción y calcula el costo `n³ log k` (`50³ · 60 ≈ 7,5·10^6`).

**Problema 69.3 — Recurrencia lineal general** · nivel 7

- **Entrada:** `d n`; luego `c_1 … c_d`; luego `a_0 … a_{d−1}`. Límites: `1 ≤ d ≤ 30`, `0 ≤ n ≤ 10^18`, `0 ≤ c_i, a_i < 10^9 + 7`.
- **Salida:** `a_n` módulo `10^9 + 7`, con `a_k = c_1·a_{k−1} + … + c_d·a_{k−d}` para `k ≥ d`.
- **Ejemplo:** `3 10 / 1 1 1 / 0 0 1` → `81` (tribonacci: 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81).
- **Matemática:** construye la matriz compañera y justifica cómo extraer `a_n` de `M^(n − d + 1)` aplicada al vector inicial (`n < d` se responde directamente).

**Proyecto del día — Biblioteca de matrices**

Una `struct Matriz` con multiplicación, potencia y producto matriz-vector, usada para los tres problemas (el `main` lee `1`, `2` o `3` y luego la entrada).

- **Autoprueba** (por `cerr`): (1) las recurrencias contra la DP iterativa para `n ≤ 1000`; (2) los caminos contra una DP por pasos para `k ≤ 30` en grafos aleatorios; (3) la identidad `gcd(F(m), F(n)) = F(gcd(m, n))` para `1 ≤ m, n ≤ 90` (con `F` exacta en `long long`).
- **Notas:** demuestra la identidad de Fibonacci con `gcd` o, al menos, explica por qué `F(m)` divide a `F(k·m)`.
- **Qué reviso:** la identidad de la potencia (`A^0 = I`), el módulo en cada paso y la comparación contra la DP.
- **Entrega:** `d69.cpp` y `d69_notas.md`.

### Día 70 · sábado 9 de enero · Repaso de la semana 10 y pruebas de estrés de DP

**Teoría: lista de comprobación para plantear una DP.**

1. Escribe en una frase qué significa el estado y comprueba que **resume todo** lo que el futuro necesita saber del pasado.
2. Enumera **todas** las opciones del último (o primer) paso; ninguna debe quedar fuera ni contarse dos veces.
3. Casos base, orden de evaluación y qué estado es la respuesta.
4. Cuenta estados × transiciones: si no cabe en el tiempo, busca prefijos, deque, estructura de datos, CHT o divide y vencerás.
5. Si piden la solución (no solo el valor), guarda cómo llegaste a cada estado o reconstruye comparando.

**Problema 70.1 — Asignaciones perfectas** · nivel 6

- **Entrada:** `n` y una matriz `n × n` de 0 y 1 (`1` = esa persona puede hacer esa tarea), con `1 ≤ n ≤ 16`.
- **Salida:** de cuántas maneras se puede asignar a cada persona una tarea distinta permitida, módulo `10^9 + 7`.
- **Ejemplo:** `3 / 1 1 0 / 0 1 1 / 1 0 1` → `2`.
- **Matemática:** `dp[mask]` cuenta las asignaciones de las primeras `popcount(mask)` personas a las tareas de `mask`. Justifica que cada asignación se cuenta una sola vez.

**Problema 70.2 — Insertar para formar un palíndromo** · nivel 6

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 2000`.
- **Salida:** el mínimo de caracteres que hay que **insertar** (en cualquier posición) para que `s` sea palíndromo.
- **Ejemplo:** `abcd` → `3`; `aab` → `1`; `race` → `3`.
- **Matemática:** `dp[l][r] = dp[l+1][r−1]` si `s[l] = s[r]`; si no, `1 + min(dp[l+1][r], dp[l][r−1])`. Demuestra que la respuesta es `|s|` menos la longitud de la subsecuencia palindrómica más larga.

**Problema 70.3 — Cadenas sin tres unos seguidos** · nivel 7

- **Entrada:** `n`, con `1 ≤ n ≤ 10^18`.
- **Salida:** cuántas cadenas binarias de largo `n` no contienen `111`, módulo `10^9 + 7`.
- **Ejemplo:** `3` → `7`; `4` → `13`; `1` → `2`.
- **Matemática:** con `a_n` la respuesta, `a_n = a_{n−1} + a_{n−2} + a_{n−3}` (según cuántos unos terminan la cadena: 0, 1 o 2). Plantea la matriz `3 × 3` y los valores iniciales `a_1 = 2`, `a_2 = 4`, `a_3 = 7`.

**Proyecto del día — Pruebas de estrés de la semana**

Un único programa con cinco comparaciones (semilla fija, 2000 pruebas cada una; `OK` o primer contraejemplo):

1. TSP con máscaras contra todas las permutaciones (`n ≤ 8`).
2. DP de dígitos (`sinrep`) contra enumeración (`N ≤ 10^5`).
3. DP de intervalos (globos) contra la recursión exhaustiva (`n ≤ 8`).
4. CHT con deque contra la DP `O(n²)` del Problema 68.3 (`n ≤ 60`).
5. Matriz de la recurrencia sin `111` contra enumeración de cadenas (`n ≤ 20`).

- **Qué reviso:** generadores correctos, fuerzas brutas independientes y mensajes claros.
- **Notas:** una tabla con una fila por familia de DP: estado, transición y complejidad.
- **Entrega:** `d70.cpp` y `d70_notas.md`.

---

## Semana 11 · 10–16 ene · Grafos avanzados

**Objetivo:** descomponer grafos dirigidos (componentes fuertemente conexas), encontrar puntos críticos, modelar con 2-SAT y flujos, y dominar las dos descomposiciones de árboles más usadas en concursos: pesada-ligera y por centroides.

### Día 71 · domingo 10 de enero · Componentes fuertemente conexas (SCC)

**Teoría desde cero.** En un grafo **dirigido**, dos vértices `u` y `v` están en la misma **componente fuertemente conexa** (SCC) si existe un camino de `u` a `v` **y** otro de `v` a `u`. Las SCC parten los vértices en grupos disjuntos. Si cada SCC se contrae a un solo vértice, se obtiene el **grafo de condensación**, que es siempre un **DAG** (si hubiera un ciclo entre SCC, se fusionarían en una).

**Algoritmo de Kosaraju** (`O(n + m)`):

1. Haz un DFS sobre el grafo y anota los vértices en el **orden en que terminan** de visitarse.
2. Invierte todas las aristas (grafo transpuesto).
3. Recorre los vértices en **orden inverso de finalización**; cada DFS no visitado sobre el grafo transpuesto recoge exactamente una SCC.

```cpp
vector<int> orden, comp(n + 1, -1);
vector<bool> vis(n + 1, false);
for (int s = 1; s <= n; s++) if (!vis[s]) {            // 1) orden de finalización (DFS iterativo)
    vector<pair<int,int>> pila = {{s, 0}};
    vis[s] = true;
    while (!pila.empty()) {
        int u = pila.back().first;
        int i = pila.back().second++;
        if (i < (int)g[u].size()) {
            int v = g[u][i];
            if (!vis[v]) { vis[v] = true; pila.push_back({v, 0}); }
        } else { orden.push_back(u); pila.pop_back(); }
    }
}
int nc = 0;
for (int idx = n - 1; idx >= 0; idx--) {               // 3) sobre el grafo transpuesto gt
    int s = orden[idx];
    if (comp[s] != -1) continue;
    vector<int> pila = {s}; comp[s] = nc;
    while (!pila.empty()) {
        int u = pila.back(); pila.pop_back();
        for (int v : gt[u]) if (comp[v] == -1) { comp[v] = nc; pila.push_back(v); }
    }
    nc++;
}
// Las SCC quedan numeradas en orden topológico del grafo de condensación:
// toda arista entre SCC distintas va de un número menor a uno mayor.
```

**Matemática del día.** *Por qué Kosaraju es correcto:* el vértice que termina último en el paso 1 pertenece a una SCC "fuente" del grafo de condensación (sin aristas entrantes de otras SCC). En el grafo transpuesto esa SCC es "sumidero", así que el DFS que empieza allí no escapa y recoge justo esa SCC; al retirarla se repite el argumento. *Condensación acíclica:* si dos SCC `A` y `B` tuvieran caminos `A → B` y `B → A`, todos sus vértices serían mutuamente alcanzables y serían una sola SCC. *Fuente y sumidero:* una SCC de la condensación es **fuente** si no recibe aristas de otras SCC y **sumidero** si no envía.

**Problema 71.1 — Componentes fuertes** · nivel 6

- **Entrada:** `n m` y `m` aristas dirigidas `u v`, con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `cantidad_de_SCC tamaño_de_la_mayor`.
- **Ejemplo:** `6 7 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 4 / 5 6` → `3 3` (`{1,2,3}`, `{4,5}`, `{6}`).
- **Matemática:** demuestra que la relación "se alcanzan mutuamente" es de equivalencia (reflexiva, simétrica y transitiva), de modo que las SCC son sus clases.

**Problema 71.2 — Aristas para hacer fuertemente conexo** · nivel 7

- **Entrada:** igual que el 71.1.
- **Salida:** la menor cantidad de aristas que hay que **agregar** para que todo el grafo sea una sola SCC.
- **Ejemplo:** el grafo anterior → `1` (agregar `6 → 1`); `4 2 / 1 2 / 3 4` → `2`.
- **Matemática:** si la condensación tiene una sola SCC, la respuesta es 0; si no, es `max(fuentes, sumideros)`. Cota inferior: cada fuente necesita una arista entrante y cada sumidero una saliente, y cada arista nueva sirve a lo sumo a una fuente y a un sumidero. Construcción: se pueden emparejar fuentes con sumideros de modo que, al agregar las aristas, todo quede conectado (esboza el argumento). Cuida el caso de una SCC aislada, que es a la vez fuente y sumidero.

**Problema 71.3 — Camino de mayor peso** · nivel 7

- **Entrada:** `n m`; `n` pesos `w_i`; `m` aristas dirigidas. Límites: `1 ≤ n, m ≤ 2·10^5`, `0 ≤ w_i ≤ 10^9`.
- **Salida:** la mayor suma de pesos de los vértices que se pueden recoger en un recorrido (caminata) que puede repetir vértices, contando cada vértice una sola vez.
- **Ejemplo:** `6 7 / 2 1 3 4 5 6 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 4 / 5 6` → `21` (todas las SCC: `6 + 9 + 6`).
- **Matemática:** en una caminata se puede recorrer **toda** una SCC antes de salir de ella, así que el peso de una SCC es la suma de sus vértices; el problema se reduce al camino de mayor peso en el DAG de la condensación (DP en orden topológico; con la numeración de Kosaraju, basta recorrer las SCC en orden creciente o decreciente de número).

**Proyecto del día — Dependencias circulares entre módulos**

Un proyecto tiene `n` módulos; la arista `u → v` significa "`u` debe construirse antes que `v`".

- **Entrada:** `n m` y `m` aristas `u v`, con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `grupos: k` (la cantidad de SCC con **al menos dos módulos**, o con un lazo `u → u`), luego `k` líneas, cada una con los módulos de un grupo en orden creciente (los grupos, ordenados por su menor módulo), y por último `orden: …`, un orden de construcción de las SCC: cada SCC se representa por su menor módulo y el orden es el topológico de la condensación, eligiendo en los empates el representante menor.
- **Ejemplo:** `6 7 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 4 / 5 6` → `grupos: 2 / 1 2 3 / 4 5 / orden: 1 4 6`.
- **Qué reviso:** Kosaraju iterativo, construcción de la condensación sin aristas repetidas, Kahn con un `priority_queue` y la salida exacta.
- **Entrega:** `d71.cpp` y `d71_notas.md`.

### Día 72 · lunes 11 de enero · Puentes y puntos de articulación

**Teoría desde cero.** En un grafo **no dirigido**, un **puente** es una arista cuya eliminación aumenta el número de componentes; un **punto de articulación** es un vértice con esa misma propiedad. Son los "puntos débiles" de una red.

Se encuentran con **una sola pasada de DFS** y dos números por vértice: `tin[u]` (el orden de llegada) y `low[u]` (el menor `tin` alcanzable desde el subárbol de `u` usando a lo sumo **una** arista de retroceso).

```cpp
vector<int> tin(n + 1, 0), low(n + 1, 0); int reloj = 0;
vector<bool> es_puente(m, false);
function<void(int, int)> dfs = [&](int u, int arista_padre) {
    tin[u] = low[u] = ++reloj;
    for (auto [v, id] : g[u]) {                         // g[u]: (vecino, identificador de la arista)
        if (id == arista_padre) continue;                // no regreses por la arista que usaste
        if (tin[v]) low[u] = min(low[u], tin[v]);        // arista de retroceso
        else {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) es_puente[id] = true;   // el subárbol de v no puede "saltar" por encima de u
        }
    }
};
```

**Puntos de articulación.** Un vértice `u` que no es la raíz del DFS es de articulación si tiene un hijo `v` con `low[v] ≥ tin[u]`. La raíz lo es si tiene **dos o más hijos** en el árbol del DFS.

Con `n = 2·10^5`, un grafo en forma de camino produce una recursión demasiado profunda: la versión de producción debe ser **iterativa** (misma lógica con una pila explícita, como en el Día 71).

**Matemática del día.** *Por qué `low[v] > tin[u]` identifica puentes:* la arista de árbol `(u, v)` es la única conexión entre el subárbol de `v` y el resto si y solo si ninguna arista de retroceso del subárbol de `v` llega a `u` ni a un ancestro de `u`, es decir, `low[v] > tin[u]`. *Por qué se identifica la arista por su `id` y no por el vecino:* con aristas paralelas, la segunda copia sí es una arista de retroceso válida. *Componentes 2-aristas-conexas:* al eliminar todos los puentes quedan componentes en las que cualquier par de vértices sigue conectado tras quitar cualquier arista.

**Problema 72.1 — Puentes** · nivel 6

- **Entrada:** `n m` y `m` aristas `u v`, con `1 ≤ n, m ≤ 2·10^5` (grafo simple).
- **Salida:** la cantidad `k` de puentes y, en la línea siguiente (si `k > 0`), sus números de arista (desde 1) en orden creciente.
- **Ejemplo:** `6 7 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 6 / 6 4` → `1 / 4`.
- **Matemática:** demuestra la caracterización con `low` y `tin`.

**Problema 72.2 — Puntos de articulación** · nivel 6

- **Entrada:** igual que el 72.1.
- **Salida:** la cantidad de puntos de articulación y, en la línea siguiente (si hay), los vértices en orden creciente.
- **Ejemplo:** el mismo grafo → `2 / 3 4`.
- **Matemática:** justifica por qué la raíz requiere un tratamiento aparte (con un solo hijo, quitarla no desconecta nada).

**Problema 72.3 — Daño de cada puente** · nivel 7

- **Entrada:** igual que el 72.1.
- **Salida:** `k` y luego `k` líneas `índice pares`: para cada puente, en orden creciente de índice, cuántas parejas de vértices `{x, y}` **dejan de estar conectadas** si se elimina.
- **Ejemplo:** `7 5 / 1 2 / 2 3 / 3 4 / 5 6 / 6 7` → `5 / 1 3 / 2 4 / 3 3 / 4 2 / 5 2`.
- **Matemática:** si el puente `(u, v)` tiene a `v` como hijo en el árbol del DFS y el subárbol de `v` tiene `s` vértices, y su componente tiene `C` vértices, se desconectan `s · (C − s)` parejas. Justifica por qué el subárbol de `v` queda aislado del resto de su componente y calcula `s` con tamaños de subárbol.

**Proyecto del día — Auditor de red**

- **Entrada:** `n m` y `m` aristas `u v` (grafo simple), con `1 ≤ n, m ≤ 2·10^5`.
- **Salida (cuatro líneas):** `componentes: C`; `puentes: k i1 i2 …` (cantidad y números de arista); `articulaciones: k v1 v2 …`; `dos_conexas: D`, la cantidad de componentes que quedan al eliminar todos los puentes.
- **Ejemplo:** `6 7 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 6 / 6 4` → `componentes: 1 / puentes: 1 4 / articulaciones: 2 3 4 / dos_conexas: 2`.
- **Qué reviso:** DFS **iterativo**, un solo recorrido para puentes y articulaciones, y el cálculo de `D` con DSU o un segundo recorrido.
- **Entrega:** `d72.cpp` y `d72_notas.md`.

### Día 73 · martes 12 de enero · 2-SAT

**Teoría desde cero.** Un problema **2-SAT** pregunta: dadas `n` variables booleanas y una lista de **cláusulas** de la forma `(a ∨ b)` (donde cada `a` y `b` es una variable o su negación), ¿existe una asignación que las haga todas verdaderas? Con tres literales por cláusula (3-SAT) es difícil; con dos se resuelve en `O(n + m)` con SCC.

**Grafo de implicaciones.** La cláusula `(a ∨ b)` equivale a dos implicaciones: `¬a → b` y `¬b → a`. Cada variable `x_i` genera dos vértices (el literal verdadero y el falso).

```cpp
// variable i (0..n-1): literal verdadero = 2*i, literal falso = 2*i + 1; negar: l ^ 1
void clausula(int a, int b) {              // (a OR b)
    g[a ^ 1].push_back(b);                 // si a es falso, b debe ser verdadero
    g[b ^ 1].push_back(a);
}
// Se calculan las SCC (Kosaraju) del grafo de 2n vértices.
// Es satisfacible  <=>  comp[2*i] != comp[2*i + 1] para toda variable i.
// Una asignación: x_i = verdadero si comp[2*i] > comp[2*i + 1]
// (con las SCC numeradas en orden topológico, como las entrega Kosaraju).
```

(Una cláusula de un solo literal `(a)` se escribe como `(a ∨ a)`.)

**Matemática del día.** *Insatisfacible si `x` y `¬x` están en la misma SCC:* entonces `x ⇒ ¬x` y `¬x ⇒ x`, y ninguna asignación lo cumple. *Satisfacible en caso contrario:* se asigna verdadero al literal que aparece **más tarde** en el orden topológico; como las implicaciones solo van "hacia adelante", nunca un verdadero implica un falso. *Simetría:* el grafo es simétrico (`a → b` existe junto con `¬b → ¬a`), por eso `comp[x]` y `comp[¬x]` se comportan como espejos.

**Problema 73.1 — ¿Es satisfacible?** · nivel 7

- **Entrada:** `n m` y `m` líneas `a b`: cada una es la cláusula `(a ∨ b)`, donde un entero positivo `i` es la variable `x_i` y uno negativo `−i` es `¬x_i`. Límites: `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `SI` o `NO`.
- **Ejemplo:** `3 3 / 1 2 / -1 3 / -2 -3` → `SI`; `2 4 / 1 2 / 1 -2 / -1 2 / -1 -2` → `NO`.
- **Matemática:** demuestra el criterio de las SCC en las dos direcciones.

**Problema 73.2 — Una asignación** · nivel 7

- **Entrada:** igual que el 73.1.
- **Salida:** `NO` o `SI` y, en la línea siguiente, `n` valores `0`/`1` con una asignación que satisfaga todas las cláusulas (cualquiera sirve; la verifico).
- **Ejemplo:** `3 3 / 1 2 / -1 3 / -2 -3` → `SI / 1 0 1` (u otra asignación válida).
- **Matemática:** demuestra que la regla "verdadero si `comp[x] > comp[¬x]`" produce siempre una asignación válida.

**Problema 73.3 — Comité** · nivel 8

Hay `2n` candidatos agrupados en `n` parejas: la pareja `i` es `(2i − 1, 2i)`. El comité debe tener **exactamente un** miembro de cada pareja. Hay `m` conflictos `u v`: `u` y `v` no pueden estar ambos en el comité.

- **Entrada:** `n m` y `m` conflictos `u v`, con `1 ≤ n ≤ 10^5`, `0 ≤ m ≤ 2·10^5` y `1 ≤ u, v ≤ 2n`.
- **Salida:** `NO` o `SI` y, en la línea siguiente, los `n` candidatos elegidos, uno por pareja y en el orden de las parejas (cualquier comité válido; lo verifico).
- **Ejemplo:** `2 1 / 1 3` → `SI / 2 3` (u otro comité válido).
- **Matemática:** usa una variable `x_i` por pareja (verdadera = se elige `2i − 1`). Expresa cada conflicto como `(¬u ∨ ¬v)`, escribiendo los literales de `u` y `v` en función de `x_i`. Justifica que "exactamente uno" ya está garantizado por usar una sola variable por pareja.

**Proyecto del día — Resolutor 2-SAT con generador de pruebas**

- **Programa:** una biblioteca 2-SAT (grafo de implicaciones + Kosaraju) con una función que devuelva satisfacibilidad y una asignación.
- **Pruebas** (por `cerr`): 3000 casos aleatorios con `n ≤ 10` y hasta 30 cláusulas, comparando la satisfacibilidad con una fuerza bruta de `2^n` asignaciones y comprobando que la asignación devuelta cumpla **todas** las cláusulas. Genera también casos con alta probabilidad de ser insatisfacibles.
- **Qué reviso:** el mapeo de literales, el manejo de cláusulas repetidas y unitarias, y que el programa también resuelva el Problema 73.2.
- **Entrega:** `d73.cpp` y `d73_notas.md`.

### Día 74 · miércoles 13 de enero · Flujo máximo y emparejamientos

**Teoría desde cero.** Una **red de flujo** es un grafo dirigido con una **capacidad** en cada arista, una fuente `s` y un sumidero `t`. Un **flujo** asigna a cada arista una cantidad no mayor que su capacidad, con la regla de que, en cada vértice distinto de `s` y `t`, **entra tanto como sale**. El **flujo máximo** es la mayor cantidad que se puede enviar de `s` a `t`.

**Algoritmo de Dinic.** Repite: (1) una BFS desde `s` asigna **niveles**; (2) una DFS envía flujo solo por aristas que suben un nivel y tienen capacidad restante; se actualizan también las **aristas inversas** (de capacidad 0 al inicio), que permiten "deshacer" decisiones. Termina cuando `t` ya no es alcanzable.

```cpp
struct Dinic {
    struct Arista { int a; long long cap; };
    vector<Arista> E; vector<vector<int>> g; vector<int> nivel, ptr;
    Dinic(int n) : g(n), nivel(n), ptr(n) {}
    void agregar(int u, int v, long long c) {
        g[u].push_back(E.size()); E.push_back({v, c});
        g[v].push_back(E.size()); E.push_back({u, 0});               // arista inversa
    }
    bool bfs(int s, int t) {
        fill(nivel.begin(), nivel.end(), -1); nivel[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int id : g[u]) if (E[id].cap > 0 && nivel[E[id].a] == -1) {
                nivel[E[id].a] = nivel[u] + 1; q.push(E[id].a);
            }
        }
        return nivel[t] != -1;
    }
    long long dfs(int u, int t, long long f) {
        if (u == t || f == 0) return f;
        for (int &i = ptr[u]; i < (int)g[u].size(); i++) {
            int id = g[u][i], v = E[id].a;
            if (E[id].cap > 0 && nivel[v] == nivel[u] + 1) {
                long long d = dfs(v, t, min(f, E[id].cap));
                if (d > 0) { E[id].cap -= d; E[id ^ 1].cap += d; return d; }
            }
        }
        return 0;
    }
    long long flujo(int s, int t) {
        long long total = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long f = dfs(s, t, LLONG_MAX)) total += f;
        }
        return total;
    }
};
```

**Emparejamiento máximo en grafos bipartitos.** Crea una fuente unida con capacidad 1 a cada vértice de la izquierda, aristas de capacidad 1 de izquierda a derecha según los pares permitidos y cada vértice de la derecha unido con capacidad 1 al sumidero. El flujo máximo es el tamaño del emparejamiento máximo. (En redes de capacidades unitarias, Dinic cuesta `O(m√n)`.)

**Matemática del día.**

- *Teorema del flujo máximo y el corte mínimo:* el valor del flujo máximo es igual a la capacidad del **corte mínimo** (el menor total de capacidades de aristas que separan `s` de `t`). Si tras el último paso `S` es el conjunto de vértices alcanzables desde `s` en la red residual, las aristas de `S` a su complemento están saturadas y forman un corte mínimo.
- *Teorema de König:* en un grafo bipartito, el emparejamiento máximo es igual al tamaño del cubrimiento de vértices mínimo, y el mayor conjunto independiente tiene `|L| + |R| − (emparejamiento máximo)` vértices.
- *Selección de proyectos con corte mínimo:* conecta `s → proyecto` con capacidad = ganancia, `proyecto → herramienta` con capacidad infinita y `herramienta → t` con capacidad = costo; la ganancia máxima es `Σ ganancias − corte mínimo`.

**Problema 74.1 — Flujo máximo** · nivel 7

- **Entrada:** `n m` y `m` aristas dirigidas `u v c`, con `2 ≤ n ≤ 500`, `1 ≤ m ≤ 5000` y `1 ≤ c ≤ 10^9`. Fuente 1 y sumidero `n`.
- **Salida:** el flujo máximo.
- **Ejemplo:** `4 5 / 1 2 3 / 1 3 2 / 2 3 1 / 2 4 2 / 3 4 3` → `5`.
- **Matemática:** acota el flujo (`≤ 5000·10^9`) y justifica la necesidad de las aristas inversas con un ejemplo donde un camino de aumento "malo" bloquee el óptimo sin ellas.

**Problema 74.2 — Emparejamiento máximo** · nivel 7

- **Entrada:** `a b m` y `m` pares `l r` (la persona `l` de la izquierda puede ocupar la plaza `r` de la derecha). Límites: `1 ≤ a, b ≤ 10^5`, `1 ≤ m ≤ 2·10^5`.
- **Salida:** el tamaño del mayor emparejamiento.
- **Ejemplo:** `3 3 4 / 1 1 / 1 2 / 2 2 / 3 3` → `3`.
- **Matemática:** demuestra que el flujo máximo en la red de capacidades unitarias es el tamaño del emparejamiento (la integridad del flujo: con capacidades enteras existe un flujo máximo entero).

**Problema 74.3 — Selección de proyectos** · nivel 8

- **Entrada:** `P T D`; `P` ganancias; `T` costos; `D` pares `i j` ("el proyecto `i` necesita la herramienta `j`"). Límites: `1 ≤ P, T ≤ 1000`, `0 ≤ D ≤ 5000`, valores hasta `10^6`. Puedes elegir cualquier conjunto de proyectos y debes pagar **una vez** cada herramienta necesaria.
- **Salida:** la mayor ganancia neta posible (al menos 0, eligiendo ningún proyecto).
- **Ejemplo:** `3 2 4 / 10 8 5 / 6 7 / 1 1 / 2 1 / 2 2 / 3 2` → `10`.
- **Matemática:** demuestra que un corte `(S, T)` con capacidad finita corresponde a elegir los proyectos del lado de `s` junto con todas sus herramientas (por la capacidad infinita), y que su capacidad es `ganancias de proyectos no elegidos + costos de herramientas usadas`.

**Proyecto del día — Asignador de turnos**

- **Entrada:** `a b m` y `m` pares `l r`, con `1 ≤ a, b ≤ 10^4`, `1 ≤ m ≤ 5·10^4` (trabajadores y turnos).
- **Salida:** el tamaño `k` del emparejamiento máximo y `k` líneas `l r` con un emparejamiento que lo logre (cualquiera sirve; lo verifico contra los pares permitidos).
- **Ejemplo:** `3 3 4 / 1 1 / 1 2 / 2 2 / 3 3` → `3 / 1 1 / 2 2 / 3 3` (u otro).
- **Qué reviso:** Dinic (o Hopcroft–Karp) correcto, la reconstrucción del emparejamiento a partir de las aristas saturadas y el costo.
- **Notas:** a partir del emparejamiento máximo, indica un conjunto independiente máximo y un cubrimiento mínimo (teorema de König).
- **Entrega:** `d74.cpp` y `d74_notas.md`.

### Día 75 · jueves 14 de enero · Descomposición pesada-ligera (HLD)

**Teoría desde cero.** Para consultas y actualizaciones sobre **caminos** de un árbol, el recorrido de Euler no alcanza (un camino no es un tramo contiguo). La **descomposición pesada-ligera** parte el árbol en **cadenas**: cada vértice elige como **hijo pesado** al hijo con el subárbol más grande, y las aristas hacia hijos pesados forman cadenas verticales. Si numeras los vértices recorriendo primero la cadena pesada, **cada cadena es un tramo contiguo** de `pos[]`. Un camino cualquiera cruza `O(log n)` cadenas.

```cpp
vector<int> padre, prof, tam, pesado, cabeza, pos; int tiempo = 0;
void dfs1(int u, int p) {                              // tamaños y el hijo pesado
    padre[u] = p; tam[u] = 1; pesado[u] = -1;
    for (int v : g[u]) if (v != p) {
        prof[v] = prof[u] + 1; dfs1(v, u); tam[u] += tam[v];
        if (pesado[u] == -1 || tam[v] > tam[pesado[u]]) pesado[u] = v;
    }
}
void dfs2(int u, int h) {                              // cabeza de la cadena y posición
    cabeza[u] = h; pos[u] = tiempo++;
    if (pesado[u] != -1) dfs2(pesado[u], h);           // la cadena sigue por el hijo pesado
    for (int v : g[u]) if (v != padre[u] && v != pesado[u]) dfs2(v, v);   // cadenas nuevas
}
// una estructura de rangos (BIT o árbol de segmentos) sobre pos[] responde por cadena:
long long consulta_camino(int u, int v) {
    long long res = 0;
    while (cabeza[u] != cabeza[v]) {
        if (prof[cabeza[u]] < prof[cabeza[v]]) swap(u, v);
        res += st.consultar(pos[cabeza[u]], pos[u]);   // tramo de la cadena de u
        u = padre[cabeza[u]];                          // salta a la cadena del padre
    }
    if (prof[u] > prof[v]) swap(u, v);
    res += st.consultar(pos[u], pos[v]);               // ya están en la misma cadena
    return res;
}
```

(Con `n` grande, escribe `dfs1` y `dfs2` de forma iterativa, igual que en días anteriores.)

**Pesos en aristas.** Guarda el peso de la arista `(padre, v)` en la posición de `v`. En la consulta del camino, el último tramo (misma cadena) empieza en `pos[u] + 1` (se excluye el ancestro común más bajo).

**Matemática del día.** *Por qué hay `O(log n)` cadenas:* una arista a un hijo **ligero** `c` cumple `tam[c] ≤ tam[padre]/2` (si no, `c` sería más pesado que otro hijo, pues los hijos suman menos que el padre). Subir por una arista ligera duplica al menos el tamaño del subárbol, y eso puede pasar a lo sumo `log2 n` veces en un camino de la raíz. *Costo total:* `O(log n)` cadenas × `O(log n)` por consulta de rango = `O(log² n)`.

**Problema 75.1 — Suma en un camino con actualizaciones** · nivel 8

- **Entrada:** `n q`; `n` valores; `n − 1` aristas; `q` operaciones: `1 v x` (el valor del vértice `v` pasa a `x`) o `2 u v` (la suma de los valores de los vértices del camino de `u` a `v`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|valor| ≤ 10^9`.
- **Salida:** la respuesta de cada operación de tipo 2.
- **Ejemplo:** `5 4 / 1 2 3 4 5 / 1 2 / 1 3 / 3 4 / 3 5 / 2 2 4 / 1 3 10 / 2 2 4 / 2 4 5` → `10 / 17 / 19`.
- **Matemática:** justifica el costo `O(log² n)` por operación.

**Problema 75.2 — Sumar a un camino, consultar un vértice** · nivel 8

- **Entrada:** `n q`; `n − 1` aristas; `q` operaciones: `1 u v x` (suma `x` a todos los vértices del camino de `u` a `v`) o `2 v` (el valor actual del vértice `v`). Todos los valores empiezan en 0. Límites: `1 ≤ n, q ≤ 2·10^5`, `|x| ≤ 10^9`.
- **Salida:** la respuesta de cada operación de tipo 2.
- **Ejemplo:** `5 4 / 1 2 / 1 3 / 3 4 / 3 5 / 1 2 4 5 / 2 3 / 1 4 5 2 / 2 4` → `5 / 7`.
- **Matemática:** el camino se parte en tramos contiguos de `pos[]`; la suma sobre un tramo y la consulta puntual se resuelven con un BIT de diferencias (Día 17 y Día 50).

**Problema 75.3 — Arista más pesada de un camino** · nivel 8

- **Entrada:** `n q`; `n − 1` aristas `u v w`; `q` consultas `u v`. Límites: `1 ≤ n, q ≤ 2·10^5`, `1 ≤ w ≤ 10^9`.
- **Salida:** el mayor peso entre las aristas del camino de `u` a `v` (0 si `u = v`).
- **Ejemplo:** `5 3 / 1 2 4 / 1 3 7 / 3 4 2 / 3 5 9 / 2 4 / 4 5 / 2 2` → `7 / 9 / 0`.
- **Matemática:** coloca el peso de cada arista en el vértice más profundo de sus extremos y justifica por qué en el último tramo hay que excluir al ancestro común más bajo. Usa un árbol de segmentos de máximos o una tabla dispersa (el árbol es estático).

**Proyecto del día — Biblioteca HLD**

Una `struct HLD` con la descomposición (`dfs1`/`dfs2` iterativos), consulta y actualización de camino, y consulta/actualización de subárbol (usando `pos[v]` y `pos[v] + tam[v] − 1`), con una estructura de rangos genérica debajo.

- **Autoprueba** (por `cerr`): 3000 árboles aleatorios con `n ≤ 30` y operaciones aleatorias contra una implementación ingenua que sube por los padres.
- **Qué reviso:** la reutilización para los tres problemas, el manejo de aristas con peso, y los árboles con forma de camino y de estrella.
- **Entrega:** `d75.cpp` y `d75_notas.md`.

### Día 76 · viernes 15 de enero · Descomposición por centroides

**Teoría desde cero.** El **centroide** de un árbol con `n` vértices es un vértice que, al quitarlo, deja componentes de tamaño `≤ n/2`. **Siempre existe.** La **descomposición por centroides** quita el centroide, y repite en cada componente. El resultado es un árbol de centroides de **altura `O(log n)`**: cada vértice pertenece a `O(log n)` componentes.

```cpp
int calcular_tam(int u, int p) {
    tam[u] = 1;
    for (int v : g[u]) if (v != p && !borrado[v]) tam[u] += calcular_tam(v, u);
    return tam[u];
}
int centroide(int u, int p, int total) {
    for (int v : g[u]) if (v != p && !borrado[v] && tam[v] * 2 > total) return centroide(v, u, total);
    return u;
}
void descomponer(int u) {
    int total = calcular_tam(u, -1);
    int c = centroide(u, -1, total);
    borrado[c] = true;
    // aquí: procesa todos los caminos que pasan por c en esta componente
    for (int v : g[c]) if (!borrado[v]) descomponer(v);
}
```

**Idea típica: caminos que pasan por el centroide.** Cada camino entre dos vértices de una componente o pasa por el centroide `c`, o está completamente en una de las componentes más pequeñas (donde se contará más adelante). Para los que pasan por `c`, calcula la distancia de cada vértice a `c` y combina los vértices de **subárboles distintos** de `c`: `dist(u, v) = d_c(u) + d_c(v)`. Ejemplo: contar los pares a distancia exactamente `K` con un arreglo `cnt[d]` de cuántos vértices ya vistos tienen profundidad `d`.

**Matemática del día.** *Existencia:* parte de cualquier vértice y muévete hacia un hijo con subárbol `> n/2` mientras exista; el movimiento no puede volver atrás (el lado de atrás tiene `< n/2`) y termina en un vértice cuyos hijos tienen `≤ n/2`. *Altura `O(log n)`:* cada componente que se procesa tiene a lo sumo la mitad de vértices que la anterior. *Costo:* en cada nivel de la descomposición se visitan en total `O(n)` vértices, y hay `O(log n)` niveles: `O(n log n)`.

**Problema 76.1 — Centroide** · nivel 6

- **Entrada:** `n` y `n − 1` aristas, con `1 ≤ n ≤ 2·10^5`.
- **Salida:** el centroide de menor número y el tamaño de la mayor componente que queda al quitarlo.
- **Ejemplo:** `5 / 1 2 / 2 3 / 3 4 / 3 5` → `3 2`.
- **Matemática:** demuestra que un árbol tiene uno o dos centroides (y si son dos, están unidos por una arista y `n` es par).

**Problema 76.2 — Caminos de longitud K** · nivel 8

- **Entrada:** `n K` y `n − 1` aristas, con `1 ≤ n ≤ 2·10^5` y `1 ≤ K ≤ n`.
- **Salida:** cuántas parejas no ordenadas `{u, v}` están a distancia exactamente `K`.
- **Ejemplo:** `5 2 / 1 2 / 2 3 / 3 4 / 4 5` → `3`.
- **Matemática:** en cada centroide, recorre sus subárboles uno por uno: para cada vértice de profundidad `d` suma `cnt[K − d]` (los ya vistos de subárboles anteriores, incluyendo al centroide con profundidad 0) y después agrega los de ese subárbol al arreglo. Justifica por qué no cuentas parejas del mismo subárbol y calcula el costo `O(n log n)`.

**Problema 76.3 — Vértice marcado más cercano** · nivel 9

- **Entrada:** `n q`; `n − 1` aristas; `q` operaciones: `1 v` (marca el vértice `v`) o `2 v` (la distancia de `v` al vértice marcado más cercano). Al inicio solo el vértice 1 está marcado. Límites: `1 ≤ n, q ≤ 2·10^5`.
- **Salida:** la respuesta de cada operación de tipo 2.
- **Ejemplo:** `5 5 / 1 2 / 2 3 / 3 4 / 3 5 / 2 4 / 1 5 / 2 4 / 2 1 / 2 5` → `3 / 2 / 0 / 0`.
- **Matemática:** para cada centroide `c` guarda `mejor[c]`, la menor distancia a `c` de un vértice marcado de su componente. Marcar `v` actualiza `mejor[c] = min(mejor[c], dist(v, c))` en los `O(log n)` ancestros de `v` en el árbol de centroides; la consulta de `v` es `min_c (dist(v, c) + mejor[c])`. Guarda, para cada vértice, su distancia a cada centroide ancestro (`O(n log n)` valores). Justifica que ningún camino óptimo se pierde: el camino de `v` al marcado más cercano `m` pasa por el centroide ancestro común más alto de ambos.

**Proyecto del día — Biblioteca de centroides**

- **Programa:** la descomposición (con un cálculo de tamaños iterativo o con una recursión de profundidad acotada), los ancestros en el árbol de centroides con sus distancias, y las operaciones de los Problemas 76.2 y 76.3.
- **Autoprueba** (por `cerr`): 3000 árboles aleatorios con `n ≤ 30` contra BFS desde cada vértice (conteo de caminos de longitud `K` y marcado más cercano).
- **Qué reviso:** la altura del árbol de centroides (compruébala imprimiéndola por `cerr` para un camino de `n = 2·10^5`), la separación de las operaciones y los casos `K = 1` y árboles en forma de estrella.
- **Entrega:** `d76.cpp` y `d76_notas.md`.

### Día 77 · sábado 16 de enero · Repaso de la semana 11 y pruebas de estrés de grafos

**Teoría: ¿qué técnica de grafos uso?**

- **Alcanzabilidad mutua, condensar ciclos:** SCC. **Puntos y aristas críticos, 2-conexidad:** `tin`/`low`.
- **Cláusulas con dos literales:** 2-SAT. **Asignar con capacidades, cortes, emparejar:** flujo.
- **Consultas sobre caminos de un árbol con actualizaciones:** HLD. **Contar o minimizar sobre todos los caminos de un árbol:** centroides.
- **Orden de dependencias:** topológico. **Distancias:** BFS, Dijkstra, Bellman–Ford, Floyd.

**Problema 77.1 — El que llega a todos** · nivel 7

- **Entrada:** `n m` y `m` aristas dirigidas, con `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** cuántos vértices tienen un camino hacia **todos** los demás vértices.
- **Ejemplo:** `6 7 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 4 / 5 6` → `3`.
- **Matemática:** un vértice llega a todos si y solo si su SCC es la **única fuente** de la condensación; en ese caso la respuesta es el tamaño de esa SCC y, si hay varias fuentes, es 0. Demuéstralo.

**Problema 77.2 — 2-aristas-conexidad** · nivel 8

- **Entrada:** `n m q`; `m` aristas no dirigidas; `q` consultas `u v`. Límites: `1 ≤ n, m, q ≤ 2·10^5`.
- **Salida:** `SI` si `u` y `v` siguen conectados después de eliminar **cualquier** arista (es decir, están en la misma componente 2-arista-conexa); si no, `NO`.
- **Ejemplo:** `6 7 3 / 1 2 / 2 3 / 3 1 / 3 4 / 4 5 / 5 6 / 6 4 / 1 3 / 1 4 / 5 6` → `SI / NO / SI`.
- **Matemática:** demuestra que "estar en la misma componente tras quitar los puentes" equivale a la propiedad pedida (si hay un puente en medio, quitarlo desconecta; si no, hay dos caminos sin aristas comunes).

**Problema 77.3 — Mayor conjunto sin aristas** · nivel 8

- **Entrada:** `a b m` y `m` pares `l r` de un grafo bipartito, con `1 ≤ a, b ≤ 10^5` y `1 ≤ m ≤ 2·10^5`.
- **Salida:** el mayor número de vértices que se pueden elegir sin que haya una arista entre dos de los elegidos.
- **Ejemplo:** `3 3 4 / 1 1 / 1 2 / 2 2 / 3 3` → `3`.
- **Matemática:** por el teorema de König, la respuesta es `a + b − (emparejamiento máximo)`. Demuestra que el complemento de un conjunto independiente es un cubrimiento de vértices.

**Proyecto del día — Pruebas de estrés de la semana**

Un único programa con seis comparaciones (semilla fija, 2000 pruebas cada una; `OK` o el primer contraejemplo):

1. SCC (Kosaraju) contra alcanzabilidad por Floyd–Warshall.
2. Puentes y articulaciones contra "quitar y contar componentes".
3. 2-SAT contra la enumeración de las `2^n` asignaciones.
4. Flujo máximo (Dinic) contra Edmonds–Karp (BFS simple) en redes pequeñas.
5. HLD contra el ascenso ingenuo por padres.
6. Centroides (caminos de longitud `K`) contra BFS desde cada vértice.

- **Qué reviso:** generadores correctos (por ejemplo, redes conexas y árboles), fuerzas brutas independientes y mensajes claros.
- **Notas:** una tabla con una fila por algoritmo de la semana: problema que resuelve, complejidad y el error más frecuente al implementarlo.
- **Entrega:** `d77.cpp` y `d77_notas.md`.

---

## Semana 12 · 17–23 ene · Geometría, juegos y técnicas de competencia

**Objetivo:** razonar con geometría de enteros, analizar juegos, usar "meet in the middle" y bitsets, entender los formatos con grader e interactivos de la IOI, y practicar problemas constructivos.

### Día 78 · domingo 17 de enero · Geometría computacional con enteros

**Teoría desde cero.** Un punto es un par `(x, y)`. Para evitar errores de redondeo, **trabaja con enteros** siempre que puedas. La herramienta central es el **producto cruzado** de dos vectores `a` y `b`:

`cruz(a, b) = a.x · b.y − a.y · b.x`

Vale `|a|·|b|·sen θ`: el **área con signo** del paralelogramo que forman. Positivo si `b` está a la izquierda de `a` (giro antihorario), negativo si está a la derecha, cero si son paralelos.

```cpp
using ll = long long;
struct P { ll x, y; };
P operator-(P a, P b) { return {a.x - b.x, a.y - b.y}; }
ll cruz(P a, P b) { return a.x * b.y - a.y * b.x; }
int signo(ll v) { return (v > 0) - (v < 0); }
int orientacion(P p, P q, P r) { return signo(cruz(q - p, r - p)); }   // 1 antihorario, -1 horario, 0 colineales
bool en_caja(P a, P b, P p) {                                            // p dentro de la caja de a y b
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}
bool se_cortan(P a, P b, P c, P d) {                                     // segmentos ab y cd (tocarse cuenta)
    int o1 = orientacion(a, b, c), o2 = orientacion(a, b, d);
    int o3 = orientacion(c, d, a), o4 = orientacion(c, d, b);
    if (o1 != o2 && o3 != o4) return true;                               // caso general
    if (o1 == 0 && en_caja(a, b, c)) return true;                        // casos con colineales
    if (o2 == 0 && en_caja(a, b, d)) return true;
    if (o3 == 0 && en_caja(c, d, a)) return true;
    if (o4 == 0 && en_caja(c, d, b)) return true;
    return false;
}
```

Con coordenadas hasta `10^9`, las diferencias llegan a `2·10^9` y cada producto a `4·10^18`: el cruce completo cabe justo en `long long`; si dudas, usa `__int128`.

**Área de un polígono (fórmula del topógrafo).** Para un polígono simple con vértices `p_0, …, p_{n−1}` en orden, `2·área = |Σ cruz(p_i, p_{i+1})|` (índices cíclicos). El doble del área es **entero**.

**Teorema de Pick.** Para un polígono simple con vértices enteros: `área = I + B/2 − 1`, donde `I` es la cantidad de puntos de coordenadas enteras en su interior y `B` la de puntos enteros sobre su borde (`B = Σ gcd(|dx|, |dy|)` sobre las aristas).

**Punto en polígono (rayo).** Cuenta cuántas aristas cruza un rayo horizontal hacia la derecha: impar = dentro. Cuida los vértices sobre el rayo con la regla `(a.y > p.y) != (b.y > p.y)` y los puntos sobre el borde, que se detectan aparte.

**Matemática del día.** *Por qué la fórmula del topógrafo funciona:* `cruz(p_i, p_{i+1})` es el doble del área con signo del triángulo `(origen, p_i, p_{i+1})`; al sumar alrededor del polígono, las regiones fuera del polígono se cancelan. *Pick:* es verdadero para triángulos "primitivos" (área `1/2`, sin otros puntos enteros) y se conserva al pegar polígonos; deduce la fórmula de `I` como `(2A − B + 2)/2`.

**Problema 78.1 — Orientación** · nivel 4

- **Entrada:** `T` y `T` líneas con seis enteros `x1 y1 x2 y2 x3 y3`, con `1 ≤ T ≤ 10^5` y `|coordenadas| ≤ 10^9`.
- **Salida:** `ANTIHORARIO`, `HORARIO` o `COLINEALES` según el giro `p1 → p2 → p3`.
- **Ejemplo:** `3 / 0 0 1 0 0 1 / 0 0 0 1 1 0 / 0 0 1 1 2 2` → `ANTIHORARIO / HORARIO / COLINEALES`.
- **Matemática:** demuestra que el signo de `cruz(p2 − p1, p3 − p1)` da el sentido del giro y acota el valor máximo del producto para decidir si basta `long long`.

**Problema 78.2 — Área y puntos de la red** · nivel 5

- **Entrada:** `n` y los `n` vértices de un polígono simple en orden (horario o antihorario), con `3 ≤ n ≤ 10^5` y `|coordenadas| ≤ 10^6`.
- **Salida:** `doble_del_area puntos_interiores`.
- **Ejemplo:** `4 / 0 0 / 4 0 / 4 4 / 0 4` → `32 9`; `3 / 0 0 / 4 0 / 0 3` → `12 3`.
- **Matemática:** usa Pick: `I = (2A − B + 2)/2` con `B = Σ gcd(|dx|, |dy|)`. Comprueba ambos ejemplos a mano.

**Problema 78.3 — Intersección de segmentos** · nivel 6

- **Entrada:** `T` y `T` líneas con ocho enteros `ax ay bx by cx cy dx dy`, con `1 ≤ T ≤ 10^5` y `|coordenadas| ≤ 10^9`. Los segmentos son `ab` y `cd` (pueden degenerar en un punto).
- **Salida:** `SI` si los segmentos tienen algún punto en común (tocarse cuenta); si no, `NO`.
- **Ejemplo:** `3 / 0 0 4 4 0 4 4 0 / 0 0 1 1 2 2 3 3 / 0 0 2 0 2 0 2 2` → `SI / NO / SI`.
- **Matemática:** justifica los dos casos de `se_cortan`: si las orientaciones son opuestas en ambos pares, hay un cruce propio; si alguna orientación es 0, el punto colineal debe caer dentro de la caja del otro segmento. Explica por qué el caso "cuatro puntos colineales" queda cubierto.

**Proyecto del día — Caja de herramientas geométrica**

- **Programa:** funciones `orientacion`, `se_cortan`, `doble_area` y `clasificar(poligono, punto)` (devuelve `DENTRO`, `FUERA` o `BORDE`), usando solo enteros.
- **Entrada:** `n` vértices de un polígono simple, `q` y `q` consultas `x y`, con `3 ≤ n ≤ 10^5` y `q ≤ 10^5`.
- **Salida:** la clasificación de cada punto.
- **Ejemplo:** `4 / 0 0 / 4 0 / 4 4 / 0 4 / 4 / 2 2 / 5 5 / 4 2 / 0 0` → `DENTRO / FUERA / BORDE / BORDE`.
- **Qué reviso:** el rayo con la regla de los vértices, los puntos sobre el borde y vértices, y una autoprueba (por `cerr`) del punto en polígono contra un conteo por cuadrícula para polígonos pequeños con coordenadas en `[0, 10]`.
- **Entrega:** `d78.cpp` y `d78_notas.md`.

### Día 79 · lunes 18 de enero · Envolvente convexa

**Teoría desde cero.** La **envolvente convexa** de un conjunto de puntos es el menor polígono convexo que los contiene (como una banda elástica alrededor de clavos). Se calcula en `O(n log n)` con la **cadena monótona de Andrew**: ordena los puntos por `(x, y)`, construye la cadena inferior de izquierda a derecha manteniendo siempre **giros antihorarios**, y luego la superior de derecha a izquierda.

```cpp
vector<P> envolvente(vector<P> pts) {                    // puntos distintos
    sort(pts.begin(), pts.end(), [](const P &a, const P &b) {
        return a.x != b.x ? a.x < b.x : a.y < b.y; });
    int n = pts.size();
    if (n <= 2) return pts;
    vector<P> h(2 * n); int k = 0;
    for (int i = 0; i < n; i++) {                        // cadena inferior
        while (k >= 2 && cruz(h[k-1] - h[k-2], pts[i] - h[k-2]) <= 0) k--;
        h[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {        // cadena superior
        while (k >= t && cruz(h[k-1] - h[k-2], pts[i] - h[k-2]) <= 0) k--;
        h[k++] = pts[i];
    }
    h.resize(k - 1);
    return h;                                            // antihorario; el `<= 0` descarta colineales
}
```

**Par más lejano (diámetro).** Está entre dos vértices de la envolvente. Con la técnica de las **pinzas rotantes**, para cada vértice `i` el más lejano `j` avanza de forma monótona al recorrer la envolvente: `O(h)` tras construirla.

**Punto en un polígono convexo en `O(log n)`.** Con los vértices `v_0, v_1, …` en orden antihorario, las semirrectas desde `v_0` hacia `v_1, …, v_{n−1}` ordenan el polígono en abanico: una búsqueda binaria encuentra el triángulo `(v_0, v_i, v_{i+1})` donde cae el punto, y se comprueba ese triángulo.

**Matemática del día.** *Por qué funciona la cadena monótona:* un vértice de la envolvente nunca queda "dentro" de un giro a la derecha; al quitar el último punto mientras el giro no sea estrictamente antihorario, se mantiene una cadena convexa, y la cadena inferior más la superior es la envolvente. *Costo:* la ordenación es `O(n log n)` y cada punto entra y sale de la cadena una vez (`O(n)`). *Calipers:* si `j` es el más lejano de `i`, el más lejano de `i + 1` está en `j` o después, porque la distancia es unimodal sobre un polígono convexo.

**Problema 79.1 — Tamaño y área de la envolvente** · nivel 6

- **Entrada:** `n` y `n` puntos distintos, con `1 ≤ n ≤ 10^5` y `|coordenadas| ≤ 10^9`.
- **Salida:** `vértices doble_del_area`: la cantidad de vértices de la envolvente (**sin** contar puntos colineales sobre los lados) y el doble de su área.
- **Ejemplo:** `5 / 0 0 / 4 0 / 4 4 / 0 4 / 2 2` → `4 32`.
- **Matemática:** justifica el `<= 0` (descarta colineales) y acota el doble del área (`≤ 8·10^18`, usa `__int128` si lo necesitas).

**Problema 79.2 — Par más lejano** · nivel 7

- **Entrada:** igual que el 79.1.
- **Salida:** el mayor cuadrado de distancia euclidiana entre dos puntos.
- **Ejemplo:** `5 / 0 0 / 4 0 / 4 4 / 0 4 / 2 2` → `32`.
- **Matemática:** demuestra que el par más lejano son dos vértices de la envolvente (la distancia a un punto fijo es una función convexa) y justifica el avance monótono de las pinzas.

**Problema 79.3 — Punto en polígono convexo** · nivel 7

- **Entrada:** `n q`; `n` vértices de un polígono **convexo** en orden antihorario (sin tres colineales consecutivos); `q` consultas `x y`. Límites: `3 ≤ n ≤ 10^5`, `1 ≤ q ≤ 10^5`, `|coordenadas| ≤ 10^9`.
- **Salida:** `DENTRO`, `FUERA` o `BORDE` por consulta.
- **Ejemplo:** `4 4 / 0 0 / 4 0 / 4 4 / 0 4 / 2 2 / 5 5 / 4 2 / 0 0` → `DENTRO / FUERA / BORDE / BORDE`.
- **Matemática:** describe el abanico desde `v_0` y la búsqueda binaria; explica los casos de borde (el punto sobre las aristas `v_0 v_1` y `v_0 v_{n−1}`) y el costo `O(log n)`.

**Proyecto del día — Cercado de la finca**

- **Entrada:** `n` y `n` puntos (árboles) distintos, con `1 ≤ n ≤ 10^5` y `|coordenadas| ≤ 10^6`.
- **Salida:** `perimetro: P` (con 2 decimales), `area: A` (con 1 decimal), `vertices: K` y `K` líneas `x y` con los vértices de la envolvente en orden antihorario, empezando por el menor `(x, y)`.
- **Ejemplo:** `5 / 0 0 / 4 0 / 4 4 / 0 4 / 2 2` → `perimetro: 16.00 / area: 16.0 / vertices: 4 / 0 0 / 4 0 / 4 4 / 0 4`.
- **Qué reviso:** casos degenerados (`n = 1`, `n = 2`, todos colineales: perímetro del segmento ida y vuelta y área 0) y puntos repetidos en la envolvente.
- **Entrega:** `d79.cpp` y `d79_notas.md`.

### Día 80 · martes 19 de enero · Teoría de juegos

**Teoría desde cero.** Estudiamos juegos de **dos jugadores** que se alternan, sin azar, con información completa, donde **pierde quien no puede mover** (juego imparcial con regla normal). Cada situación es una **posición**:

- **Posición perdedora (P):** quien debe mover pierde con juego óptimo (todos sus movimientos van a posiciones ganadoras).
- **Posición ganadora (N):** existe al menos un movimiento hacia una posición perdedora.

Se calculan con DP desde las posiciones finales, que son perdedoras.

**Nim.** Hay varios montones de piedras; en cada turno se elige un montón y se quitan una o más piedras. **Teorema de Bouton:** si `X = a_1 ^ a_2 ^ … ^ a_n` (XOR de los tamaños), la posición es perdedora si y solo si `X = 0`. Si `X ≠ 0`, la jugada ganadora es elegir un montón `a_i` con `a_i ^ X < a_i` y reducirlo a `a_i ^ X`.

**Sprague–Grundy.** A cada posición de un juego imparcial se le asigna un número, el **valor de Grundy**: `g(pos) = mex { g(siguiente) }`, donde `mex` es el menor entero no negativo que **no** está en el conjunto. Una posición es perdedora si y solo si `g = 0`. Para una **suma de juegos independientes**, `g(suma) = XOR de los g de cada juego`: así, un montón en un juego de restas vale como un montón de Nim con tamaño `g`.

```cpp
// valor de Grundy de un montón de n piedras si en cada turno se quitan k piedras, k en M
vector<int> g(N + 1, 0);
for (int n = 1; n <= N; n++) {
    set<int> alcanzables;
    for (int k : M) if (k <= n) alcanzables.insert(g[n - k]);
    int x = 0; while (alcanzables.count(x)) x++;                 // mex
    g[n] = x;
}
```

**Matemática del día.** *Demostración de Bouton:* (1) Si `X = 0`, cualquier movimiento cambia exactamente un montón, por lo que `X` pasa a ser distinto de 0. (2) Si `X ≠ 0`, sea `b` el bit más alto de `X`; algún montón `a_i` tiene el bit `b` encendido; entonces `a_i ^ X < a_i` y reducirlo a `a_i ^ X` deja `X = 0`. Como el juego termina (las piedras disminuyen), el jugador que deja `X = 0` gana. *Suma de juegos:* se demuestra igual, notando que cada juego equivale a un montón de Nim de tamaño `g`.

**Problema 80.1 — Nim** · nivel 5

- **Entrada:** `n` y `n` tamaños de montones, con `1 ≤ n ≤ 10^5` y `0 ≤ a_i ≤ 10^18`.
- **Salida:** `SEGUNDO` si pierde quien mueve primero; si no, `PRIMERO i nuevo`: el menor índice `i` (desde 1) tal que `a_i ^ X < a_i` y el nuevo tamaño `a_i ^ X` al que se reduce ese montón.
- **Ejemplo:** `3 / 3 4 5` → `PRIMERO 1 1`; `2 / 7 7` → `SEGUNDO`.
- **Matemática:** demuestra el teorema de Bouton y comprueba el primer ejemplo: `3 ^ 4 ^ 5 = 2`.

**Problema 80.2 — Valor de Grundy** · nivel 6

- **Entrada:** `k n` y `k` movimientos permitidos `m_1 … m_k` (se pueden quitar exactamente `m_i` piedras), con `1 ≤ k ≤ 10`, `1 ≤ m_i ≤ 100` y `0 ≤ n ≤ 10^6`.
- **Salida:** el valor de Grundy de un montón de `n` piedras.
- **Ejemplo:** `3 5 / 1 3 4` → `3`; `3 7 / 1 3 4` → `0`.
- **Matemática:** calcula a mano la tabla `g(0..7) = 0 1 0 1 2 3 2 0` y comprueba que `g(7) = 0` coincide con "el jugador que mueve pierde" por fuerza bruta (minimax).

**Problema 80.3 — Varios montones** · nivel 7

- **Entrada:** `k t`; los `k` movimientos permitidos; `t` tamaños de montones. Límites: `1 ≤ k ≤ 10`, `1 ≤ t ≤ 10^5`, tamaños hasta `10^6`.
- **Salida:** `PRIMERO` o `SEGUNDO` según quién gana con juego óptimo (el que mueve primero es `PRIMERO`).
- **Ejemplo:** `3 3 / 1 3 4 / 7 2 5` → `PRIMERO`; `3 3 / 1 3 4 / 7 3 1` → `SEGUNDO`.
- **Matemática:** justifica que el valor de Grundy de la suma es el XOR y calcula los dos ejemplos (`0 ^ 0 ^ 3 = 3` y `0 ^ 1 ^ 1 = 0`).

**Proyecto del día — Tabla de Grundy y periodo**

Los valores de Grundy de un juego de restas son, a la larga, **periódicos**.

- **Entrada:** `k` y `k` movimientos permitidos, con `1 ≤ k ≤ 10` y `1 ≤ m_i ≤ 50`.
- **Salida:** `p s`: el menor periodo `p` y el menor `s` tales que `g(n) = g(n + p)` para todo `n ≥ s`, comprobados hasta `N = 10^6`.
- **Ejemplo:** `2 / 1 2` → `3 0`; `3 / 1 3 4` → `7 0`.
- **Autoprueba** (por `cerr`): para 1000 conjuntos de movimientos aleatorios y `n ≤ 30`, compara que `g(n) ≠ 0` si y solo si el jugador que mueve gana según una búsqueda minimax con memoria.
- **Qué reviso:** la definición del periodo (menor `p`, luego menor `s`), el costo `O(N·k)` y la autoprueba.
- **Entrega:** `d80.cpp` y `d80_notas.md`.

### Día 81 · miércoles 20 de enero · Meet in the middle y bitsets

**Teoría desde cero.**

**Meet in the middle.** Si `n ≤ 40`, recorrer todos los `2^n` subconjuntos es imposible (`10^12`), pero `2 · 2^(n/2) = 2·10^6` sí. Parte los elementos en **dos mitades**, enumera los subconjuntos de cada una y **combina** las dos listas con ordenación y búsqueda binaria o dos punteros.

```cpp
vector<long long> subsumas(const vector<long long> &v) {          // las 2^|v| sumas de subconjuntos
    vector<long long> s = {0};
    for (long long x : v) {
        int m = s.size();
        for (int i = 0; i < m; i++) s.push_back(s[i] + x);
    }
    return s;
}
// A = subsumas(primera mitad); B = subsumas(segunda mitad); sort(B);
// para cada a en A, busca en B una suma igual a (S - a) con binary_search o lower_bound
```

**Bitset.** `bitset<N>` guarda `N` bits y sus operaciones (`|`, `&`, `<<`) actúan sobre **64 bits a la vez**. Para la **alcanzabilidad de sumas**: `dp[s]` indica si algún subconjunto suma `s`. Agregar un valor `a` equivale a `dp |= dp << a`.

```cpp
bitset<100001> dp;
dp[0] = 1;
for (int a : valores) dp |= dp << a;          // cada paso cuesta O(N/64)
cout << dp.count() << "\n";                    // cuántas sumas distintas se alcanzan (con 0)
```

**Matemática del día.** *Costo de MITM:* `2^(n/2)` por mitad más la combinación `O(2^(n/2) · log)`: con `n = 40`, unos `10^6 · 20`. *Contar subconjuntos con suma `≤ S`:* ordena `B` y, para cada suma `a` de `A`, la cantidad de sumas `b` de `B` con `b ≤ S − a` es un `upper_bound`; el total es la suma de esas cantidades. *Ganancia del bitset:* el DP clásico de subconjuntos cuesta `n·N`; con bitset, `n·N/64`.

**Problema 81.1 — Sumas alcanzables** · nivel 6

- **Entrada:** `n` y `n` enteros, con `1 ≤ n ≤ 1000` y `1 ≤ a_i ≤ 100`.
- **Salida:** cuántos valores distintos pueden obtenerse como suma de un subconjunto (incluyendo la suma `0` del conjunto vacío).
- **Ejemplo:** `3 / 1 2 4` → `8`; `3 / 2 2 2` → `4`.
- **Matemática:** acota la suma máxima (`10^5`) para dimensionar el bitset y calcula el costo `n · 10^5 / 64`.

**Problema 81.2 — ¿Existe un subconjunto con suma S?** · nivel 6

- **Entrada:** `n S` y `n` enteros, con `1 ≤ n ≤ 40`, `1 ≤ a_i ≤ 10^9` y `1 ≤ S ≤ 4·10^10`.
- **Salida:** `SI` o `NO`.
- **Ejemplo:** `5 17 / 3 34 4 12 5` → `SI`; `3 10 / 6 7 8` → `NO`.
- **Matemática:** demuestra que existe un subconjunto de suma `S` si y solo si hay `a ∈ A` y `b ∈ B` con `a + b = S`, donde `A` y `B` son las sumas de las dos mitades. Calcula el costo.

**Problema 81.3 — Contar subconjuntos con suma a lo sumo S** · nivel 7

- **Entrada:** `n S` y `n` enteros, con `1 ≤ n ≤ 40`, `1 ≤ a_i ≤ 10^9` y `1 ≤ S ≤ 4·10^10`.
- **Salida:** cuántos subconjuntos de **posiciones** (incluyendo el vacío) tienen suma `≤ S`.
- **Ejemplo:** `4 5 / 1 2 3 4` → `9`.
- **Matemática:** con `B` ordenado, el número de `b ≤ S − a` es `upper_bound(S − a)`. Acota la respuesta (`2^40`) y explica por qué cabe en `long long`.

**Proyecto del día — Mochila grande**

- **Entrada:** `n W` y `n` líneas `peso valor`, con `1 ≤ n ≤ 40`, `1 ≤ W ≤ 10^10` y pesos y valores hasta `10^9`.
- **Salida:** el mayor valor total con peso total `≤ W`.
- **Ejemplo:** `4 10 / 5 10 / 4 40 / 6 30 / 3 50` → `90`.
- **Idea:** enumera los `(peso, valor)` de cada mitad; ordena la segunda por peso y deja, para cada peso, el **mayor valor de un prefijo** (máximo acumulado); para cada subconjunto de la primera, busca por binary search el mayor peso permitido.
- **Qué reviso:** el máximo acumulado (sin él, la búsqueda por peso no basta), la comparación con una fuerza bruta para `n ≤ 15` y los límites.
- **Entrega:** `d81.cpp` y `d81_notas.md`.

### Día 82 · jueves 21 de enero · Problemas con grader e interactivos

**Teoría desde cero.** En la IOI, no todos los problemas son "lee de la entrada estándar y escribe". Los formatos más comunes:

- **Con grader (funciones):** el sistema oficial tiene su propio `main` y llama a una o más funciones que **tú** implementas (por ejemplo `int adivina(int n)`). **No escribes `main`.** Si usas variables globales, recuerda que el grader puede llamar a tus funciones varias veces.
- **Interactivo:** tu programa **conversa** con un programa del jurado: escribes una consulta, esperas su respuesta y decides la siguiente. Hay que **vaciar el búfer** después de cada consulta (`cout << … << endl;` lo hace; con `"\n"` no).
- **Solo salida (*output-only*):** te dan los archivos de entrada y envías los archivos de salida; el puntaje depende de la calidad.
- **Comunicación:** dos programas que se envían mensajes limitados.

En estos problemas se mide también **cuántas consultas** haces: la complejidad "de consultas" importa tanto como el tiempo.

Para practicar sin jurado, usa un **grader local**: un archivo que contiene tu solución, las funciones de consulta (con contador) y un `main` que prueba.

```cpp
// ---------- grader local de "Adivina el número" ----------
static int SECRETO, USADAS = 0;
int consulta(int x) {                          // 0 si x == SECRETO; 1 si x es mayor; -1 si x es menor
    USADAS++;
    return (x > SECRETO) - (x < SECRETO);
}
// ---------- tu solución ----------
int adivina(int n) { /* usa consulta(); devuelve el secreto */ return 1; }
// ---------- main del grader ----------
int main() {
    int n; cin >> n >> SECRETO;
    int r = adivina(n);
    cout << (r == SECRETO ? "OK" : "MAL") << " consultas=" << USADAS << "\n";
}
```

**Matemática del día.** *Cota inferior por árbol de decisión:* con `k` preguntas de respuesta binaria se distinguen a lo sumo `2^k` casos; para `n` posibilidades hacen falta al menos `⌈log2 n⌉` preguntas. Con respuestas de **tres** resultados (menor, igual, mayor; o una balanza), se distinguen `3^k` casos y bastan `⌈log3 n⌉`. *Comparaciones para máximo y mínimo:* tomar los elementos de dos en dos permite encontrar ambos con `⌈3n/2⌉ − 2` comparaciones, menos que las `2n − 3` de buscar cada uno por separado.

**Problema 82.1 — Adivina el número** · nivel 5

- **Función:** `int adivina(int n)`: el secreto está en `[1, n]`, con `1 ≤ n ≤ 10^9`. Llama a `consulta(x)` como máximo `⌊log2 n⌋ + 1` veces y devuelve el secreto.
- **Ejemplo (grader local):** `1000 777` → `OK consultas=…` (a lo más 10).
- **Matemática:** demuestra que la búsqueda binaria usa a lo más `⌊log2 n⌋ + 1` consultas y que no se puede con menos en el peor caso.

**Problema 82.2 — Máximo y mínimo** · nivel 6

- **Función:** `pair<int,int> maxmin(int n)`: hay `n` valores distintos `a_1 … a_n` ocultos (`2 ≤ n ≤ 10^5`); puedes llamar a `bool menor(int i, int j)` (¿`a_i < a_j`?). Devuelve los índices `(del máximo, del mínimo)` usando a lo sumo `⌈3n/2⌉ − 2` llamadas.
- **Ejemplo:** `n = 5`, valores `3 9 2 7 5` → `(2, 3)` con a lo más 6 llamadas.
- **Matemática:** compara los elementos por parejas (`⌊n/2⌋` comparaciones), el máximo está entre los ganadores y el mínimo entre los perdedores. Cuenta las comparaciones totales para `n` par e impar.

**Problema 82.3 — Moneda falsa** · nivel 7

- **Función:** `int falsa(int n)`: hay `n` monedas numeradas `1..n` (`1 ≤ n ≤ 3^10`), todas iguales salvo una **más liviana**. Puedes llamar a `int pesar(vector<int> A, vector<int> B)` con dos conjuntos disjuntos de igual tamaño; devuelve `-1` si `A` pesa menos, `0` si pesan igual y `1` si `A` pesa más. Encuentra la falsa con a lo más `⌈log3 n⌉` pesadas.
- **Ejemplo (grader local):** `n = 9`, falsa `5` → `5` con 2 pesadas.
- **Matemática:** divide las monedas en tres grupos de tamaños `⌈n/3⌉`, `⌈n/3⌉` y el resto (`≤ ⌈n/3⌉`); pesa los dos grupos iguales. Demuestra que la moneda falsa queda en un grupo de a lo sumo `⌈n/3⌉` monedas y que después de `⌈log3 n⌉` pasos queda una.

**Proyecto del día — Grader local**

Escribe un grader local propio para los tres problemas, con:

1. Contadores de consultas y **validación de argumentos** (en `pesar`, que los conjuntos sean disjuntos, del mismo tamaño y con monedas válidas; si no, el grader debe terminar con `ARGUMENTO INVALIDO`).
2. Una prueba exhaustiva: 82.1 para todo `n ≤ 300` y todos los secretos; 82.2 con 2000 arreglos aleatorios para cada `n ≤ 60`; 82.3 con todas las posiciones de la falsa para cada `n ≤ 100`.
3. Una tabla final `problema máximo_de_consultas_usadas límite_teórico`.

- **Qué reviso:** que el grader detecte soluciones que se pasan del límite, la validación de argumentos y la tabla.
- **Notas:** para 82.3, demuestra la cota inferior `⌈log3 n⌉`.
- **Entrega:** `d82.cpp` y `d82_notas.md`.

### Día 83 · viernes 22 de enero · Problemas constructivos e invariantes

**Teoría desde cero.** En un problema **constructivo** te piden **construir** un objeto que cumpla ciertas condiciones (cualquiera que sirva) o decidir que no existe. No hay un algoritmo estándar, pero sí un método:

1. Resuelve a mano o por fuerza bruta los casos pequeños y **busca un patrón**.
2. Intenta una construcción general y **demuéstrala por inducción** o por casos.
3. Para probar que algo es **imposible**, busca un **invariante**: una cantidad que no cambia (paridad, color de un tablero, residuo módulo `m`) y que debería cambiar.
4. Escribe un **verificador** (*checker*) que compruebe tu salida, y pruébalo con la fuerza bruta.

**Matemática del día.** *Coloración de tableros:* en un tablero de ajedrez, cada dominó cubre exactamente una casilla de cada color; si al quitar celdas quedan cantidades distintas de casillas blancas y negras, es imposible cubrir con dominós. *Emparejamientos:* la condición de colores iguales es **necesaria**, pero no siempre suficiente; la existencia real del recubrimiento es un emparejamiento perfecto en el grafo bipartito de casillas adyacentes (Día 74). *Permutaciones:* intercambiar dos elementos cambia el número de ciclos en 1 (los separa o los une).

**Problema 83.1 — Diferencias distintas** · nivel 6

- **Entrada:** `n`, con `1 ≤ n ≤ 10^5`.
- **Salida:** una permutación de `1..n` en la que las `n − 1` diferencias absolutas `|p_i − p_{i+1}|` sean todas distintas (cualquiera sirve; la verifico).
- **Ejemplo:** `5` → `1 5 2 4 3` (diferencias `4 3 2 1`).
- **Matemática:** demuestra que alternar el menor y el mayor restantes (`1, n, 2, n − 1, …`) produce las diferencias `n − 1, n − 2, …, 1`, todas distintas.

**Problema 83.2 — Dominós con casillas prohibidas** · nivel 7

- **Entrada:** `n m k` y `k` casillas `f c` removidas, con `1 ≤ n, m ≤ 40` y `0 ≤ k ≤ nm`.
- **Salida:** `SI` si el resto del tablero se puede cubrir **exactamente** con dominós (de `1 × 2` o `2 × 1`, sin solapes); si no, `NO`.
- **Ejemplo:** `2 2 0` → `SI`; `3 3 0` → `NO`; `4 4 2 / 1 1 / 4 4` → `NO`; `4 4 2 / 1 1 / 1 2` → `SI`.
- **Matemática:** colorea por la paridad de `f + c`. Una cobertura es un emparejamiento perfecto del grafo bipartito (claras contra oscuras, adyacentes). Usa el flujo del Día 74 (Dinic o Hopcroft–Karp) y explica por qué la igualdad de colores es necesaria pero no suficiente.

**Problema 83.3 — Intercambios mínimos** · nivel 7

- **Entrada:** `n` y una permutación `p_1 … p_n` de `1..n`, con `1 ≤ n ≤ 10^5`.
- **Salida:** `k`, el mínimo de intercambios (de dos posiciones cualesquiera) para ordenar la permutación, y `k` líneas `i j` con una secuencia válida de intercambios (cualquiera; la verifico).
- **Ejemplo:** `5 / 3 1 2 5 4` → `3 / 1 3 / 1 2 / 4 5`.
- **Matemática:** `k = n − (cantidad de ciclos)`. Cota inferior: un intercambio cambia el número de ciclos en `+1` o `−1`, y la permutación ordenada tiene `n` ciclos. Construcción: mientras `p_i ≠ i`, intercambia las posiciones `i` y `p_i`.

**Proyecto del día — Verificador y generador**

- **Programa:** un *checker* que lea el archivo de entrada y la salida de una solución y escriba `OK` o `MAL` con el motivo, para los Problemas 83.1 y 83.3; y un generador aleatorio de entradas.
- **Procedimiento:** ejecuta tus soluciones sobre 2000 entradas aleatorias con `n ≤ 200` (incluyendo `n = 1, 2`) y pasa cada salida por el verificador. Incluye al menos tres soluciones **incorrectas** a propósito (por ejemplo, una permutación con diferencias repetidas) para comprobar que el verificador las atrapa.
- **Qué reviso:** que el verificador compruebe **todas** las condiciones (formato, rango, permutación válida, minimalidad de `k` en 83.3) y que atrape los errores sembrados.
- **Entrega:** `d83.cpp` y `d83_notas.md`.

### Día 84 · sábado 23 de enero · Repaso de la semana 12 y mini-simulacro 3

**Teoría: estrategia ante un problema desconocido.**

1. Lee los límites y deduce la complejidad objetivo (Día 8).
2. Resuelve a mano el ejemplo y casos pequeños propios; escribe la fuerza bruta (asegura la primera subtarea).
3. Busca estructura: ¿monotonía (búsqueda binaria)? ¿orden (voraz)? ¿subproblemas que se repiten (DP)? ¿grafo escondido? ¿invariante?
4. Piensa en el caso extremo: `n = 1`, valores iguales, límites máximos (desbordamiento).
5. Compara siempre tu solución rápida con la fuerza bruta antes de darla por buena.

Tiempo sugerido: 3 horas.

**Problema 84.1 — Piedras con límite** · nivel 6

En cada turno, un jugador elige un montón y quita entre `1` y `k` piedras; pierde quien no puede mover.

- **Entrada:** `t k` y `t` tamaños de montón, con `1 ≤ t ≤ 10^5`, `1 ≤ k ≤ 10^18` y `0 ≤ a_i ≤ 10^18`.
- **Salida:** `PRIMERO` o `SEGUNDO` (gana con juego óptimo el que mueve primero o el segundo).
- **Subtareas:** (20 puntos) `t ≤ 3`, `a_i ≤ 20`; (30 puntos) `t ≤ 100`, `a_i, k ≤ 1000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `3 3 / 5 6 7` → `SEGUNDO`; `2 3 / 5 4` → `PRIMERO`.
- **Matemática:** demuestra por inducción que `g(n) = n mod (k + 1)`: desde `n` se alcanzan `n − 1, …, n − k` (los que sean `≥ 0`) y sus residuos cubren todos los valores `0..k` salvo `n mod (k + 1)`.

**Problema 84.2 — Cruces de segmentos horizontales y verticales** · nivel 7

- **Entrada:** `n m`; `n` segmentos horizontales `x1 x2 y` (desde `(x1, y)` hasta `(x2, y)`, con `x1 ≤ x2`); `m` segmentos verticales `x y1 y2` (con `y1 ≤ y2`). Límites: `1 ≤ n, m ≤ 10^5`, `|coordenadas| ≤ 10^9`.
- **Salida:** cuántas parejas (horizontal, vertical) se cortan (tocarse en un extremo cuenta).
- **Subtareas:** (20 puntos) `n, m ≤ 100`; (30 puntos) `n, m ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `2 2 / 0 5 2 / 1 6 4 / 2 0 5 / 5 3 6` → `3`.
- **Matemática:** barre por `x` con eventos (inicio de horizontal: insertar `y` en un BIT; vertical: consultar cuántas `y` activas están en `[y1, y2]`; fin de horizontal: quitar `y`). En una misma `x`, procesa primero los inicios, luego las verticales y por último los finales. Justifica ese orden y la compresión de `y`.

**Problema 84.3 — Equipo equilibrado** · nivel 8

- **Entrada:** `n` par y `n` habilidades `a_i`, con `2 ≤ n ≤ 40` y `1 ≤ a_i ≤ 10^9`. Se elige un equipo de **exactamente `n/2`** personas.
- **Salida:** el menor valor posible de `|2·(suma del equipo) − (suma total)|`.
- **Subtareas:** (20 puntos) `n ≤ 16`; (30 puntos) `n ≤ 24`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `4 / 1 2 3 5` → `1`.
- **Matemática:** parte en dos mitades y, para cada cantidad `c` de elegidos en la primera, necesitas `n/2 − c` en la segunda; guarda las sumas de cada mitad **por cantidad de elementos**, ordénalas y busca con binary search la suma más cercana a `total/2`. Calcula el costo `O(2^(n/2) · n)`.

**Proyecto del día — Informe de mini-simulacro 3**

1. Resuelve los tres problemas con el tiempo sugerido y anota cuánto te tomó cada uno.
2. Entrega la mejor solución completa de cada uno (indica qué lograste dentro del tiempo y qué después).
3. Para cada problema, un test de estrés contra la fuerza bruta de su primera subtarea (3000 casos aleatorios pequeños).
4. En las notas: una tabla con las subtareas logradas, puntaje estimado, causa de cada subtarea perdida y una acción concreta de mejora; compara con los Días 35, 49 y 63.

- **Qué califico:** que cada solución completa cumpla los límites de la última subtarea, la independencia de los tests de estrés y la calidad del análisis.
- **Entrega:** `d84_p1.cpp`, `d84_p2.cpp`, `d84_p3.cpp` y `d84_notas.md`.

---

## Semana 13 · 24–30 ene · Integración: técnicas de nivel IOI

**Objetivo:** dominar estructuras y técnicas que combinan varias ideas (persistencia, fusión pequeño-a-grande, arreglos de sufijos, búsqueda binaria paralela, DP con estructuras) y practicar problemas que mezclan herramientas de todo el plan.

### Día 85 · domingo 24 de enero · Árbol de segmentos persistente

**Teoría desde cero.** Una estructura **persistente** conserva todas sus versiones anteriores: tras una actualización puedes seguir consultando cualquier versión pasada. En un árbol de segmentos, una actualización solo cambia los `O(log n)` nodos del camino de la hoja a la raíz; en vez de modificarlos, se **crean copias** de ese camino y se **comparten** los demás nodos con la versión anterior. Cada versión es una raíz distinta.

Aplicación clásica: el **`k`-ésimo menor de un rango** `a[l..r]`. Recorre `a` de izquierda a derecha; la versión `i` es un árbol de segmentos sobre los **valores** (comprimidos) que cuenta cuántos de `a[1..i]` caen en cada tramo. Para `a[l..r]` se resta la versión `l − 1` de la versión `r` y se baja por el árbol:

```cpp
struct Nodo { int izq, der, cnt; };
vector<Nodo> t(1);                                         // nodo 0 = árbol vacío (hijos 0, cnt 0)
int insertar(int prev, int l, int r, int pos) {            // devuelve la raíz de la nueva versión
    int cur = t.size(); t.push_back(t[prev]);              // copia del nodo anterior
    t[cur].cnt++;
    if (l < r) {
        int m = (l + r) / 2;
        if (pos <= m) { int h = insertar(t[prev].izq, l, m, pos); t[cur].izq = h; }
        else          { int h = insertar(t[prev].der, m + 1, r, pos); t[cur].der = h; }
    }
    return cur;
}
int kesimo(int a, int b, int l, int r, int k) {            // k-ésimo menor de (versión b) - (versión a)
    if (l == r) return l;
    int m = (l + r) / 2;
    int izq = t[t[b].izq].cnt - t[t[a].izq].cnt;           // cuántos caen a la izquierda
    if (k <= izq) return kesimo(t[a].izq, t[b].izq, l, m, k);
    return kesimo(t[a].der, t[b].der, m + 1, r, k - izq);
}
```

La raíz de la versión `i` es `raiz[i] = insertar(raiz[i-1], 0, m-1, id[a[i]])`, con `raiz[0] = 0`.

**Matemática del día.** *Memoria:* cada inserción crea `⌈log2 m⌉ + 1` nodos, así que `n` inserciones usan `≈ 18·n` nodos; para `n = 2·10^5` son `3,6·10^6` nodos de 12 bytes (43 MB). *Corrección de la resta de versiones:* el conteo en un tramo para `a[l..r]` es el de la versión `r` menos el de la versión `l − 1`, porque cada nodo guarda un contador **acumulado** (como las sumas prefijas del Día 15, pero para cada tramo de valores).

**Problema 85.1 — `k`-ésimo menor en un rango** · nivel 8

- **Entrada:** `n q`; `n` enteros; `q` consultas `l r k`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i| ≤ 10^9`, `1 ≤ k ≤ r − l + 1`.
- **Salida:** el `k`-ésimo menor de `a[l..r]`, por consulta.
- **Ejemplo:** `5 3 / 5 2 7 1 6 / 1 5 2 / 2 4 1 / 3 5 3` → `2 / 1 / 7`.
- **Matemática:** demuestra que la resta de contadores de dos versiones da el conteo del rango y que el descenso es `O(log n)`.

**Problema 85.2 — Historial de versiones** · nivel 8

- **Entrada:** `n q`; `n` enteros (versión 0); `q` operaciones: `1 v i x` (crea la **siguiente versión** numerada `1, 2, …` copiando la versión `v` y poniendo `a_i = x`) o `2 v i` (el valor de `a_i` en la versión `v`). Límites: `1 ≤ n, q ≤ 2·10^5`, `|valores| ≤ 10^9`.
- **Salida:** la respuesta de cada consulta de tipo 2.
- **Ejemplo:** `4 6 / 1 2 3 4 / 2 0 3 / 1 0 3 10 / 2 1 3 / 1 1 1 7 / 2 2 1 / 2 0 1` → `3 / 10 / 7 / 1`.
- **Matemática:** una versión es solo una raíz; justifica por qué no se modifica ningún nodo existente (así las versiones antiguas siguen intactas) y calcula la memoria total.

**Problema 85.3 — Contar valores en un intervalo** · nivel 8

- **Entrada:** `n q`; `n` enteros; `q` consultas `l r x y`. Límites: `1 ≤ n, q ≤ 2·10^5`, `|a_i|, |x|, |y| ≤ 10^9`, `x ≤ y`.
- **Salida:** cuántos elementos de `a[l..r]` tienen valor en `[x, y]`.
- **Ejemplo:** `5 3 / 5 2 7 1 6 / 1 5 2 6 / 2 4 3 8 / 3 5 7 7` → `3 / 1 / 1`.
- **Matemática:** con los valores comprimidos, `[x, y]` se traduce a un rango de índices `[lo, hi]` con `lower_bound` y `upper_bound`; la respuesta es `consulta(raiz[r], lo, hi) − consulta(raiz[l−1], lo, hi)`.

**Proyecto del día — Biblioteca persistente**

Una `struct ArbolPersistente` con inserción, consulta de rango de valores y `k`-ésimo, y los tres problemas resueltos con ella (el `main` lee `1`, `2` o `3` y luego la entrada).

- **Autoprueba** (por `cerr`): 3000 casos aleatorios contra fuerza bruta por problema.
- **Qué reviso:** la reserva de memoria (`reserve`), que ninguna operación modifique nodos existentes y los casos `n = 1`.
- **Entrega:** `d85.cpp` y `d85_notas.md`.

### Día 86 · lunes 25 de enero · Fusión pequeño a grande (*small-to-large*)

**Teoría desde cero.** Hay que mantener un **conjunto** (o diccionario) por cada vértice de un árbol, y el conjunto de un vértice es la **unión** de los conjuntos de sus hijos más algún elemento propio. Fusionar todo "ingenuamente" es `O(n²)`. La técnica **pequeño a grande**: al unir dos conjuntos, **mueve los elementos del más pequeño al más grande**.

```cpp
// id[v] = índice del conjunto de v (se reutiliza el del hijo con el conjunto mayor)
vector<set<int>> S;
void dfs(int u, int p) {
    int mayor = -1;
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
        if (mayor == -1 || S[id[v]].size() > S[id[mayor]].size()) mayor = v;
    }
    if (mayor == -1) { id[u] = S.size(); S.push_back({}); }
    else id[u] = id[mayor];                                    // el del hijo mayor pasa a u sin copiarse
    for (int v : g[u]) if (v != p && v != mayor)
        for (int x : S[id[v]]) S[id[u]].insert(x);             // los más pequeños se vuelcan
    S[id[u]].insert(color[u]);
    respuesta[u] = S[id[u]].size();
}
```

(Con `n` grande, hazlo iterativo o aumenta la pila.)

**Matemática del día.** *Cada elemento se mueve `O(log n)` veces:* cuando un elemento se mueve, su conjunto pasa a otro de tamaño **al menos el doble** (se mueve al más grande y este es mayor o igual), y el tamaño nunca supera `n`; así se mueve a lo sumo `log2 n` veces. *Costo total:* `O(n log n)` inserciones, cada una `O(log n)` en un `set` (`O(n log² n)`) o `O(1)` en un diccionario hash. La misma idea sirve en un DSU con listas de elementos y para mantener conteos por color.

**Problema 86.1 — Colores distintos en cada subárbol** · nivel 7

- **Entrada:** `n`; `n` colores `c_i`; `n − 1` aristas. Raíz 1. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ c_i ≤ 10^9`.
- **Salida:** para cada vértice, cuántos colores distintos hay en su subárbol.
- **Ejemplo:** `5 / 1 2 1 2 3 / 1 2 / 1 3 / 3 4 / 3 5` → `3 1 3 1 1`.
- **Matemática:** demuestra que cada color se mueve a lo sumo `log2 n` veces entre conjuntos.

**Problema 86.2 — Color dominante** · nivel 8

- **Entrada:** igual que el 86.1, con `1 ≤ c_i ≤ n` y `1 ≤ n ≤ 10^5`.
- **Salida:** para cada vértice, la **suma** de los colores que más veces aparecen en su subárbol (si hay empate en la frecuencia máxima, se suman todos los empatados).
- **Ejemplo:** `5 / 1 2 1 2 3 / 1 2 / 1 3 / 3 4 / 3 5` → `3 2 6 2 3`.
- **Matemática:** mantén `cnt[color]`, la frecuencia máxima `mx` y la suma `s` de colores con frecuencia `mx`. Al sumar un elemento, actualiza esos tres valores en `O(1)`; justifica que, si fusionas pequeño a grande y **solo se agregan** elementos, `mx` nunca disminuye.

**Problema 86.3 — Profundidad dominante** · nivel 8

- **Entrada:** `n` y `n − 1` aristas, raíz 1, con `1 ≤ n ≤ 2·10^5`.
- **Salida:** para cada vértice `v`, la profundidad **relativa** (0 es `v`) con más vértices en su subárbol; si hay empate, la menor.
- **Ejemplo:** `5 / 1 2 / 1 3 / 3 4 / 3 5` → `1 0 1 0 0`.
- **Matemática:** para el vértice `v`, el diccionario `profundidad → cantidad` del hijo mayor se reutiliza con las profundidades desplazadas en 1 (guarda profundidades absolutas para no recorrerlas). Justifica por qué no hace falta actualizar al desplazar y cómo se obtiene la respuesta.

**Proyecto del día — Biblioteca de fusión de conjuntos**

Un conjunto de utilidades: fusión de `set`/`map` de pequeño a grande, un DSU que mantiene el conjunto de colores de cada componente, y los tres problemas de hoy.

- **Medición:** cuenta cuántas veces se mueve cada elemento y confirma, para árboles aleatorios y para un camino de `n = 2·10^5`, que el máximo de movimientos de un elemento es `≤ log2 n`. Imprime la tabla por `cerr`.
- **Autoprueba:** 3000 árboles aleatorios con `n ≤ 12` contra la solución que recorre cada subárbol.
- **Qué reviso:** el uso del conjunto mayor sin copiarlo, la medición y los casos de árbol-camino y estrella.
- **Entrega:** `d86.cpp` y `d86_notas.md`.

### Día 87 · martes 26 de enero · Arreglo de sufijos

**Teoría desde cero.** El **arreglo de sufijos** `sa` lista los índices de inicio de **todos los sufijos** de una cadena en orden alfabético. Junto con el arreglo `lcp` (longitud del prefijo común más largo entre sufijos vecinos en `sa`), responde muchas preguntas sobre subcadenas.

```cpp
vector<int> sufijos(const string &s) {                     // O(n log^2 n), por duplicación
    int n = s.size();
    vector<int> sa(n), rango(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++) rango[i] = s[i];
    for (int k = 1; ; k <<= 1) {
        auto cmp = [&](int a, int b) {                      // compara por (rango[a], rango[a + k])
            if (rango[a] != rango[b]) return rango[a] < rango[b];
            int ra = a + k < n ? rango[a + k] : -1, rb = b + k < n ? rango[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        rango = tmp;
        if (rango[sa[n - 1]] == n - 1) break;               // todos los rangos distintos
    }
    return sa;
}
vector<int> lcp_kasai(const string &s, const vector<int> &sa) {    // lcp[i] = lcp(sa[i], sa[i+1])
    int n = s.size(), h = 0;
    vector<int> rk(n), lcp(max(0, n - 1));
    for (int i = 0; i < n; i++) rk[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (rk[i] + 1 < n) {
            int j = sa[rk[i] + 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rk[i]] = h;
            if (h > 0) h--;
        } else h = 0;
    }
    return lcp;
}
```

**Usos típicos.**

- *Subcadenas distintas:* `n(n + 1)/2 − Σ lcp`.
- *Subcadena repetida más larga:* `max lcp`.
- *Subcadena común de dos cadenas `s` y `t`:* concatena `s + '#' + t` y busca el mayor `lcp` entre sufijos vecinos que provienen de cadenas distintas.
- *Contar apariciones de un patrón:* las apariciones son un **bloque contiguo** en `sa`; se halla con dos búsquedas binarias comparando el patrón con los sufijos.

**Matemática del día.** *Por qué `Σ lcp` descuenta repeticiones:* cada sufijo `s[i..]` aporta `n − i` prefijos (subcadenas); en el orden de `sa`, los primeros `lcp[j−1]` prefijos del sufijo `sa[j]` ya fueron contados por el sufijo anterior (comparten ese prefijo), así que aporta `n − sa[j] − lcp[j−1]` subcadenas nuevas. *Kasai en `O(n)`:* si el sufijo `i` tiene un vecino con prefijo común `h`, el sufijo `i + 1` tiene uno con prefijo común `≥ h − 1`, así que `h` solo baja de a uno y el total de incrementos es `O(n)`.

**Problema 87.1 — Subcadenas distintas** · nivel 8

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 10^5`.
- **Salida:** la cantidad de subcadenas distintas.
- **Ejemplo:** `abab` → `7`.
- **Matemática:** demuestra la fórmula `n(n + 1)/2 − Σ lcp` y acota el resultado (`≈ 5·10^9`).

**Problema 87.2 — Subcadena común más larga** · nivel 8

- **Entrada:** dos líneas con cadenas `s` y `t` de minúsculas, con `1 ≤ |s|, |t| ≤ 10^5`.
- **Salida:** la longitud de la subcadena común más larga.
- **Ejemplo:** `abcdxyz / xyzabcd` → `4` (`abcd`).
- **Matemática:** al concatenar con un separador, el mayor `lcp` entre dos sufijos vecinos de **cadenas distintas** es la respuesta. Justifica por qué basta mirar vecinos (el `lcp` entre sufijos no vecinos es el mínimo de los `lcp` intermedios) y por qué el separador no debe aparecer en las cadenas.

**Problema 87.3 — Buscar patrones** · nivel 8

- **Entrada:** el texto `s` (una línea); `q`; `q` patrones (una línea cada uno). Límites: `1 ≤ |s| ≤ 10^5`, `1 ≤ q ≤ 10^5`, longitud total de los patrones `≤ 10^6`.
- **Salida:** para cada patrón, cuántas veces aparece en `s` (las apariciones pueden solaparse).
- **Ejemplo:** `banana / 3 / ana / na / x` → `2 / 2 / 0`.
- **Matemática:** justifica que las apariciones forman un bloque contiguo de `sa` y calcula el costo `O(|p| log n)` por patrón.

**Proyecto del día — Biblioteca de sufijos**

Una `struct Sufijos` con `sa`, `lcp` y las tres consultas, usada para los tres problemas.

- **Autoprueba** (por `cerr`): 3000 cadenas aleatorias de longitud `≤ 12` sobre un alfabeto de 2 o 3 letras; compara `sa` y `lcp` con la ordenación directa de los sufijos y las tres respuestas con la fuerza bruta.
- **Qué reviso:** el manejo de `n = 1`, cadenas con una sola letra repetida, el separador y la autoprueba.
- **Entrega:** `d87.cpp` y `d87_notas.md`.

### Día 88 · miércoles 27 de enero · Búsqueda binaria avanzada: sobre la respuesta y paralela

**Teoría desde cero.** Ya conoces la búsqueda binaria sobre la respuesta (Día 19). Aquí se combina con otras ideas.

**Contar para decidir.** Para el "`k`-ésimo valor de algo" (`k`-ésima suma de pares, `k`-ésima distancia), busca binariamente el valor `X` y cuenta **cuántos objetos son `≤ X`**; el `k`-ésimo es el menor `X` con cuenta `≥ k`.

**Truco de la mediana.** Para decidir si un subarreglo tiene mediana `≥ X`, transforma cada elemento en `+1` (si es `≥ X`) o `−1` (si no) y mira si la suma es `≥ 0`. Con sumas prefijas se prueban todos los subarreglos de longitud `≥ L` con un mínimo corrido.

**Búsqueda binaria paralela.** Hay muchas consultas `i` y cada una tiene una respuesta monótona en el tiempo (por ejemplo, "primer instante en que `u` y `v` quedan conectados"), pero comprobar una pregunta requiere simular una estructura que cambia con el tiempo. Hacer una búsqueda binaria por consulta cuesta demasiado. La solución: todas las consultas hacen su búsqueda binaria **a la vez**, por rondas. En cada ronda, cada consulta tiene un punto medio `mid`; se **reproduce la línea de tiempo una sola vez** y, al pasar por el instante `mid` de una consulta, se responde si su predicado es verdadero.

```cpp
// lo[i], hi[i]: la respuesta de la consulta i está en [lo, hi]; hi = m + 1 significa "nunca"
for (int ronda = 0; ronda < 20; ronda++) {
    vector<vector<int>> por_mid(m + 1);
    for (int i = 0; i < q; i++) if (lo[i] < hi[i]) por_mid[(lo[i] + hi[i]) / 2].push_back(i);
    DSU d(n);                                              // la estructura se reinicia en cada ronda
    for (int t = 1; t <= m; t++) {
        d.unite(eu[t], ev[t]);                             // aplica el evento t
        for (int i : por_mid[t])
            if (d.find(U[i]) == d.find(V[i])) hi[i] = t; else lo[i] = t + 1;
    }
}
```

**Matemática del día.** *Costo:* `⌈log2 (m+1)⌉` rondas, cada una `O((m + q) · α(n))`: total `O((m + q) log m)`. *Desigualdad de la mediana:* con `b_i = ±1`, la mediana superior (el elemento en la posición `⌊len/2⌋` del subarreglo ordenado) es `≥ X` si y solo si a lo sumo `⌊len/2⌋` elementos son `< X`, es decir, `len − 2c ≥ 0` con `c` la cantidad de elementos `< X`, que es la suma de los `b`.

**Problema 88.1 — `k`-ésima suma de pares** · nivel 7

- **Entrada:** `n m k`; `n` enteros `a_i`; `m` enteros `b_j`. Límites: `1 ≤ n, m ≤ 2·10^5`, `|a_i|, |b_j| ≤ 10^9`, `1 ≤ k ≤ n·m`.
- **Salida:** el `k`-ésimo menor valor entre las `n·m` sumas `a_i + b_j` (contando cada pareja `(i, j)` por separado).
- **Ejemplo:** `3 3 4 / 1 4 7 / 2 3 6` → `7`.
- **Matemática:** `cuenta(X)` = parejas con suma `≤ X`, calculada con dos punteros sobre los arreglos ordenados en `O(n + m)`. Demuestra que `cuenta` es no decreciente y busca el menor `X` con `cuenta(X) ≥ k` en `[−2·10^9, 2·10^9]`.

**Problema 88.2 — Mediana máxima** · nivel 8

- **Entrada:** `n L` y `n` enteros, con `1 ≤ L ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** la mayor mediana superior (el elemento en la posición `⌊len/2⌋`, contando desde 0, del subarreglo ordenado) entre los subarreglos de longitud **al menos `L`**.
- **Ejemplo:** `5 2 / 1 3 2 5 4` → `5`; `5 3 / 1 3 2 5 4` → `4`.
- **Matemática:** busca binariamente el mayor `X` (entre los valores del arreglo) tal que exista un subarreglo de longitud `≥ L` con suma de `b` `≥ 0`; la comprobación usa prefijos y el mínimo de `p[i]` para `i ≤ j − L`. Justifica la monotonía en `X`.

**Problema 88.3 — Primer momento de conexión** · nivel 8

- **Entrada:** `n m q`; `m` aristas `u v` (la arista `t` aparece en el instante `t`); `q` consultas `u v`. Límites: `1 ≤ n, m, q ≤ 2·10^5`.
- **Salida:** para cada consulta, el menor `t` tal que `u` y `v` están conectados usando las aristas `1..t` (0 si `u = v`, `-1` si nunca).
- **Ejemplo:** `4 3 3 / 1 2 / 2 3 / 3 4 / 1 3 / 1 4 / 2 2` → `2 / 3 / 0`.
- **Matemática:** el predicado "conectados con las primeras `t` aristas" es monótono en `t`. Usa búsqueda binaria paralela con un DSU y demuestra el costo `O((m + q) log m · α(n))`.

**Proyecto del día — Plantilla de búsqueda binaria paralela**

Una plantilla genérica (con funciones `reiniciar`, `aplicar(t)` y `verificar(consulta)` recibidas como lambdas) y el Problema 88.3 resuelto con ella.

- **Autoprueba** (por `cerr`): 3000 casos aleatorios pequeños contra una solución ingenua (DSU nuevo por consulta, aplicando aristas hasta conectar).
- **Qué reviso:** la plantilla (separación de la lógica de rondas y de la estructura), el manejo de "nunca" (`hi = m + 1`) y de consultas con `u = v`.
- **Entrega:** `d88.cpp` y `d88_notas.md`.

### Día 89 · jueves 28 de enero · DP con estructuras de datos

**Teoría desde cero.** Muchas DP tienen la forma `dp[i] = (algo) + mejor{dp[j] : j < i y j cumple una condición sobre un atributo}`. Si los `dp[j]` ya calculados se guardan en una estructura **indexada por ese atributo**, la mejor opción se obtiene con una consulta de rango en `O(log n)`:

- *Condición `a_j < a_i`:* BIT o árbol de segmentos indexado por `a` (comprimido), consulta de prefijo.
- *Condición `|a_j − a_i| ≤ K`:* árbol de segmentos de máximos sobre los valores, consulta del rango `[a_i − K, a_i + K]`.
- *Condición `fin_j ≤ inicio_i`:* ordena y usa búsqueda binaria o un arreglo prefijo.

```cpp
// cantidad de subsecuencias estrictamente crecientes: formas[i] = 1 + Σ formas[j] con j < i y a_j < a_i
for (int i = 0; i < n; i++) {
    long long f = (1 + bit.sum(id[i] - 1)) % MOD;         // consulta ANTES de insertar
    bit.add(id[i], f);
    total = (total + f) % MOD;
}
```

**Matemática del día.** *Consultar antes de insertar:* garantiza que solo se usen índices `j < i` y, al pedir el prefijo `id[i] − 1`, valores **estrictamente** menores. *Intervalos disjuntos con ganancia:* ordena por fin; `dp[i] = max(dp[i − 1], ganancia_i + dp[p(i)])`, con `p(i)` el último intervalo (en el orden) cuyo fin es `≤ inicio_i`, hallado con búsqueda binaria. *Por qué es válido el rango de valores:* un `dp[j]` relevante para `i` es el de un `j` con valor en el rango pedido, y esos son exactamente los que están en esas posiciones de la estructura.

**Problema 89.1 — Subsecuencias crecientes** · nivel 7

- **Entrada:** `n` y `n` enteros, con `1 ≤ n ≤ 2·10^5` y `|a_i| ≤ 10^9`.
- **Salida:** cuántas subsecuencias **no vacías** estrictamente crecientes hay (como conjuntos de posiciones), módulo `10^9 + 7`.
- **Ejemplo:** `4 / 1 3 2 4` → `11`.
- **Matemática:** demuestra la recurrencia `formas[i] = 1 + Σ formas[j]` (la subsecuencia que termina en `i` es solo `i` o una que termina en `j` con `a_j < a_i`, seguida de `i`).

**Problema 89.2 — Intervalos con ganancia** · nivel 7

- **Entrada:** `n` y `n` líneas `s e g`: el intervalo `[s, e)` con ganancia `g`. Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ s < e ≤ 10^9`, `1 ≤ g ≤ 10^9`.
- **Salida:** la mayor ganancia total de un conjunto de intervalos que no se solapen (pueden tocarse: `e_1 ≤ s_2`).
- **Ejemplo:** `4 / 1 3 5 / 2 5 6 / 4 6 5 / 6 8 4` → `14` (intervalos `[1,3)`, `[4,6)` y `[6,8)`).
- **Matemática:** ordena por fin y define `dp[i]` como la mejor ganancia usando los primeros `i`; justifica `dp[i] = max(dp[i−1], g_i + dp[p(i)])`. Acota la respuesta (`≤ 2·10^14`).

**Problema 89.3 — Subsecuencia con saltos de valor acotados** · nivel 8

- **Entrada:** `n K` y `n` enteros, con `1 ≤ n ≤ 2·10^5`, `0 ≤ K ≤ 10^9` y `|a_i| ≤ 10^9`.
- **Salida:** la mayor longitud de una subsecuencia (índices crecientes) donde cada par consecutivo cumple `|a_i − a_j| ≤ K`.
- **Ejemplo:** `6 2 / 4 2 5 7 6 3` → `4`; `5 1 / 1 10 2 11 3` → `3`.
- **Matemática:** `dp[i] = 1 + max{dp[j] : j < i, |a_j − a_i| ≤ K}`. Guarda `dp` en un árbol de segmentos de máximos sobre los valores comprimidos y consulta el rango `[a_i − K, a_i + K]` (traducido con `lower_bound` y `upper_bound`).

**Proyecto del día — Biblioteca de DP con estructuras**

Una biblioteca con (1) BIT de suma y de máximo, (2) árbol de segmentos de máximo sobre valores comprimidos, y los tres problemas de hoy.

- **Autoprueba** (por `cerr`): cada problema contra su DP ingenua `O(n²)` en 3000 casos aleatorios pequeños (incluye valores repetidos y `K = 0`).
- **Qué reviso:** la consulta antes de la inserción, los rangos de valores comprimidos y los módulos.
- **Entrega:** `d89.cpp` y `d89_notas.md`.

### Día 90 · viernes 29 de enero · Conjunto integrador difícil

**Teoría: cómo reconocer las piezas.** Un problema difícil suele ser **dos o tres técnicas conocidas** pegadas. Antes de programar, escribe la lista:

1. ¿Qué estructura es la base? (grafo, árbol, arreglo, cadena, geometría)
2. ¿Hay un parámetro oculto que amplía el estado? (cupones usados, paridad, nivel)
3. ¿Hay muchas consultas? Entonces, ¿offline u online? ¿Cuál es la estructura de datos que responde cada una en `O(log n)`?
4. ¿Hay "contar pares"? Piensa en centroides, en el truco de la contribución o en ordenar y dos punteros.

**Problema 90.1 — Rutas con varios cupones** · nivel 7

Tienes hasta `k` cupones; cada uno reduce el peso de **una** arista del camino a `floor(w/2)`; no se puede usar más de un cupón en la misma arista.

- **Entrada:** `n m k` y `m` aristas dirigidas `u v w`. Límites: `2 ≤ n ≤ 10^5`, `1 ≤ m ≤ 2·10^5`, `0 ≤ k ≤ 10`, `1 ≤ w ≤ 10^9`.
- **Salida:** el costo mínimo de ir de 1 a `n` (o `-1`).
- **Ejemplo:** `4 4 2 / 1 2 3 / 2 4 8 / 1 3 10 / 3 4 2` → `5`.
- **Matemática:** el estado es `(vértice, cupones usados)`: `n·(k+1)` vértices en el grafo ampliado. Explica por qué los pesos siguen siendo no negativos y calcula el costo `O((m·(k+1)) log n)`.

**Problema 90.2 — Sumar a un camino, sumar un subárbol** · nivel 8

- **Entrada:** `n q`; `n − 1` aristas; `q` operaciones: `1 u v x` (suma `x` a cada vértice del camino de `u` a `v`) o `2 w` (la suma de los valores de todos los vértices del subárbol de `w`, con raíz 1). Los valores empiezan en 0. Límites: `1 ≤ n, q ≤ 10^5`, `|x| ≤ 10^4`.
- **Salida:** la respuesta de cada operación de tipo 2.
- **Ejemplo:** `5 5 / 1 2 / 1 3 / 3 4 / 3 5 / 1 2 4 5 / 2 3 / 1 4 5 2 / 2 1 / 2 3` → `10 / 26 / 16`.
- **Matemática:** con HLD (Día 75), el camino se parte en `O(log n)` tramos contiguos de `pos[]` y el subárbol de `w` es el tramo `[pos[w], pos[w] + tam[w] − 1]`. Necesitas *suma de rango con actualización de rango*: usa dos BIT o un árbol de segmentos con propagación perezosa.

**Problema 90.3 — Parejas a distancia acotada** · nivel 9

- **Entrada:** `n D` y `n − 1` aristas, con `1 ≤ n ≤ 10^5` y `0 ≤ D ≤ n`.
- **Salida:** cuántas parejas no ordenadas de vértices `{u, v}` (con `u ≠ v`) están a distancia `≤ D`.
- **Ejemplo:** `5 2 / 1 2 / 2 3 / 3 4 / 4 5` → `7`.
- **Matemática:** con centroides (Día 76): para cada centroide `c`, ordena las profundidades de **todos** los vértices de la componente (incluido `c` con 0) y cuenta con dos punteros las parejas con suma `≤ D`; **resta** las parejas que quedan dentro del mismo subárbol hijo (con las mismas profundidades medidas desde `c`), pues no pasan por `c`. Costo `O(n log² n)`.

**Proyecto del día — Informe del conjunto integrador**

1. Resuelve los tres problemas y entrega la mejor solución completa de cada uno.
2. Para cada problema, un test de estrés contra una fuerza bruta (3000 casos aleatorios pequeños).
3. En las notas, para cada problema, una lista de **piezas** (qué técnicas usaste y de qué día), la complejidad y la parte que más te costó depurar.

- **Qué califico:** corrección y eficiencia, la independencia de los tests y la claridad del análisis.
- **Entrega:** `d90_p1.cpp`, `d90_p2.cpp`, `d90_p3.cpp` y `d90_notas.md`.

### Día 91 · sábado 30 de enero · Repaso de la semana 13 y biblioteca personal

**Teoría: lista de comprobación antes de entregar cualquier solución.**

- ¿Cumple los **límites** con el peor caso (`n` máximo, valores máximos, grafo en forma de camino o de estrella)?
- ¿Hay **desbordamientos**? (`int` contra `long long`, productos intermedios, módulos)
- ¿Están inicializados los arreglos y se reinician entre casos de prueba?
- ¿Los **bordes**? (`n = 1`, rangos de un elemento, valores repetidos, ceros, negativos)
- ¿La recursión puede ser demasiado profunda? ¿Necesitas una versión iterativa?
- ¿Probaste contra una fuerza bruta con casos aleatorios pequeños?
- ¿El formato de salida es exacto (saltos de línea, mayúsculas, espacios finales)?

**Problema 91.1 — Subarreglos con mediana al menos X** · nivel 8

- **Entrada:** `n X` y `n` enteros, con `1 ≤ n ≤ 2·10^5` y `|a_i|, |X| ≤ 10^9`.
- **Salida:** cuántos subarreglos tienen mediana superior (el elemento en la posición `⌊len/2⌋` del subarreglo ordenado) `≥ X`.
- **Ejemplo:** `5 3 / 1 3 2 5 4` → `12`.
- **Matemática:** con `b_i = +1` si `a_i ≥ X` y `−1` si no, y prefijos `p`, un subarreglo `(i, j]` cumple la condición si y solo si `p_j − p_i ≥ 0`. Cuenta las parejas `i < j` con `p_i ≤ p_j` con un BIT sobre los valores de `p` (que van de `−n` a `n`).

**Problema 91.2 — `k`-ésima subcadena distinta** · nivel 8

- **Entrada:** una línea con la cadena `s` (minúsculas) y una segunda línea con `k`. Límites: `1 ≤ |s| ≤ 10^5` y `1 ≤ k ≤` la cantidad de subcadenas distintas.
- **Salida:** la `k`-ésima subcadena distinta en orden lexicográfico.
- **Ejemplo:** `abab / 3` → `aba`; `banana / 5` → `anana`.
- **Matemática:** en el orden de `sa`, el sufijo `sa[j]` aporta `n − sa[j] − lcp[j−1]` subcadenas nuevas, que son sus prefijos de longitud `lcp[j−1] + 1, …, n − sa[j]`, y aparecen en ese orden lexicográfico. Acumula hasta encontrar el sufijo que contiene la posición `k` y calcula la longitud.

**Problema 91.3 — Cubrir con costo mínimo** · nivel 9

- **Entrada:** `n M` y `n` líneas `l r c` (el intervalo `[l, r]` de enteros cuesta `c`). Límites: `1 ≤ n ≤ 2·10^5`, `1 ≤ M ≤ 10^9`, `1 ≤ l ≤ r ≤ 10^9`, `1 ≤ c ≤ 10^9`.
- **Salida:** el menor costo total de un conjunto de intervalos cuya unión contenga **todos** los enteros de `1` a `M`, o `-1`.
- **Ejemplo:** `5 10 / 1 4 3 / 3 7 4 / 6 10 5 / 1 10 13 / 5 10 6` → `9` (`[1,4]` y `[5,10]`).
- **Matemática:** sea `g[r]` el menor costo de un conjunto cuya cobertura llega **exactamente** hasta `r` (empezando en 1, sin huecos), con `g[0] = 0`. Procesa los intervalos por `r` creciente: `g[r] = min(g[r], c + min{g[t] : l − 1 ≤ t ≤ r − 1})`. Comprime los extremos y usa un árbol de segmentos de mínimos con actualización puntual y consulta de rango. La respuesta es `min g[t]` para `t ≥ M`. Justifica por qué un conjunto óptimo puede reordenarse de modo que cada intervalo extienda la cobertura.

**Proyecto del día — Tu biblioteca personal**

Reúne en **un solo archivo** `biblioteca.hpp` las herramientas que construiste durante el plan, cada una con un comentario de una línea (qué hace, complejidad y límites) y una pequeña prueba:

- Aritmética: criba, `gcd`/`egcd`, `potencia`, inverso, factoriales y `C(n, k)`, `φ`.
- Estructuras: DSU, BIT, árbol de segmentos (genérico y perezoso), tabla dispersa, Fenwick de máximos.
- Grafos: BFS, Dijkstra, Floyd–Warshall, orden topológico, SCC, puentes, LCA, Dinic, HLD, centroides.
- Cadenas: hashing, KMP/Z, trie, arreglo de sufijos con LCP.
- DP y geometría: matrices, CHT/Li Chao, cruz y envolvente convexa.

Un archivo `prueba.cpp` incluye `biblioteca.hpp`, ejecuta al menos una verificación por herramienta y escribe `TODO OK`.

- **Qué reviso:** que compile sin avisos con `-Wall -Wextra`, que no haya código duplicado, la prueba de cada herramienta y la documentación. (La biblioteca sirve para repasar y practicar: en la competencia solo cuenta lo que sepas escribir de memoria.)
- **Entrega:** `biblioteca.hpp`, `prueba.cpp` y `d91_notas.md`.

---

## Semana 14 · 31 ene–1 feb · Simulacros finales de la IOI

**Objetivo:** ensayar las dos jornadas de una competencia: tres problemas por día con subtareas, administración del tiempo y análisis posterior. Los problemas combinan herramientas de todo el plan.

**Reglas de los dos simulacros** (hazlos como si fueran la IOI):

- Tiempo sugerido: **5 horas** por jornada (es la duración de cada jornada de la IOI real). Sin consultar este documento ni a nadie.
- Lee los tres problemas primero (15 minutos). Planifica: asegura las primeras subtareas de **los tres** antes de intentar las completas.
- Después de cada subtarea que creas lograda, pruébala contra una fuerza bruta con casos pequeños aleatorios antes de pasar a la siguiente.
- Reserva 30 minutos finales para revisar desbordamientos, casos borde y formato.
- Al terminar, completa el informe del proyecto (tiempos, puntajes, causas de errores).

### Día 92 · domingo 31 de enero · Simulacro IOI, Jornada 1

**Teoría: cómo repartir las 5 horas.** Una distribución razonable: 15 minutos para leer los tres problemas; 45 minutos para asegurar las subtareas fáciles de los tres; 2 horas para las subtareas intermedias; 1 hora y 15 minutos para la solución completa del problema que mejor entiendas; 45 minutos para pruebas, casos borde y revisión final. Si llevas 45 minutos atascado en una subtarea sin avances, pasa a otra: un puntaje parcial seguro vale más que una idea incierta.

**Problema 92.1 — Estaciones de carga** · nivel 7

Un auto recorre una carretera recta desde el kilómetro `0` hasta el `D`. Tiene un tanque de capacidad `T` unidades de energía, consume 1 unidad por kilómetro y sale con el tanque vacío. En el camino hay `n` estaciones: la estación `i` está en el kilómetro `p_i` y vende cada unidad a precio `c_i` (puedes comprar cualquier cantidad entera sin pasar de `T`). Minimiza el costo total para llegar al kilómetro `D`.

- **Entrada:** `D T n` y `n` líneas `p c`. Límites: `1 ≤ D ≤ 10^9`, `1 ≤ T ≤ 10^9`, `1 ≤ n ≤ 2·10^5`, `0 ≤ p_i ≤ D`, `1 ≤ c_i ≤ 10^6`. Puede haber varias estaciones en el mismo kilómetro.
- **Salida:** el costo mínimo, o `-1` si es imposible llegar.
- **Subtareas:** (20 puntos) `D ≤ 20`, `n ≤ 10`; (30 puntos) `D, T ≤ 2000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `10 4 3 / 0 3 / 3 1 / 6 2` → `19`; `10 4 2 / 0 3 / 5 1` → `-1`; `8 4 2 / 0 2 / 4 1` → `12`.
- **Matemática:** en cada estación conviene comprar solo lo necesario para llegar a la **próxima estación más barata** (o llenar el tanque si no hay ninguna al alcance); demuéstralo con un argumento de intercambio. Esa próxima estación más barata se halla con una pila monótona (Día 22). Cuida que el costo total puede llegar a `10^9 · 10^6 = 10^15`.

**Problema 92.2 — Ciudades que desaparecen** · nivel 8

Una red tiene `n` ciudades y `m` carreteras. Las ciudades se eliminan una por una en un orden dado (una ciudad eliminada se lleva sus carreteras). Después de cada eliminación, ¿en cuántos grupos conexos queda dividido lo que sobrevive?

- **Entrada:** `n m`; `m` aristas `u v`; una permutación de `1..n` con el orden de eliminación. Límites: `1 ≤ n, m ≤ 2·10^5`.
- **Salida:** `n` valores: tras eliminar la primera ciudad, tras las dos primeras, etc. (después de eliminarlas todas, 0).
- **Subtareas:** (20 puntos) `n, m ≤ 100`; (30 puntos) `n, m ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 5 / 1 2 / 2 3 / 3 4 / 4 5 / 2 4 / 3 2 4 1 5` → `1 2 2 1 0`.
- **Matemática:** invierte el tiempo: **agrega** las ciudades en el orden contrario y une con un DSU cada ciudad con sus vecinas ya presentes; el número de componentes tras cada adición es la respuesta de la eliminación correspondiente. Justifica la inversión y el costo `O((n + m) α(n))`.

**Problema 92.3 — Subcadenas repetidas** · nivel 9

- **Entrada:** una cadena `s` de minúsculas con `1 ≤ |s| ≤ 10^5`.
- **Salida:** cuántas subcadenas **distintas** aparecen al menos dos veces en `s` (las apariciones pueden solaparse).
- **Subtareas:** (20 puntos) `|s| ≤ 100`; (30 puntos) `|s| ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `banana` → `5` (`a`, `an`, `ana`, `n`, `na`); `abab` → `3`; `aaaa` → `3`.
- **Matemática:** con el arreglo de sufijos y `lcp` (Día 87), una subcadena aparece al menos dos veces si y solo si es prefijo de dos sufijos vecinos en `sa`, es decir, si su longitud es `≤ lcp[j]` para algún `j`. En el orden de `sa`, el sufijo `j + 1` aporta nuevas subcadenas repetidas con longitudes en `(lcp[j−1], lcp[j]]`: la respuesta es `Σ max(0, lcp[j] − lcp[j−1])` (con `lcp[−1] = 0` y un `lcp` final de 0). Demuéstralo.

**Proyecto del día — Informe de la Jornada 1**

1. Entrega, para cada problema, la **mejor solución completa** que logres (indica qué subtareas lograste dentro de las 5 horas y cuáles después).
2. Para cada problema, un test de estrés contra una fuerza bruta (3000 casos aleatorios pequeños).
3. En las notas: una tabla con el **cronograma** (a qué hora empezaste y terminaste cada subtarea), el puntaje estimado por problema, la causa de cada punto perdido (idea, error de implementación, desbordamiento, tiempo) y tres acciones concretas de mejora.

- **Qué califico:** que cada solución completa cumpla los límites de la última subtarea, la independencia de los tests de estrés, la administración del tiempo y la calidad del análisis.
- **Entrega:** `d92_p1.cpp`, `d92_p2.cpp`, `d92_p3.cpp` y `d92_notas.md`.

### Día 93 · lunes 1 de febrero · Simulacro IOI, Jornada 2 y cierre del plan

**Teoría: el análisis posterior (*upsolving*).** Después de un simulacro, lo que más enseña es el análisis. Para cada subtarea perdida, clasifica la causa: (1) no vi la idea; (2) vi la idea pero la implementé mal; (3) error de desbordamiento o de borde; (4) se me acabó el tiempo por mala administración. Cada causa tiene una cura distinta: estudiar la técnica, escribir pruebas de estrés, repasar la lista de comprobación del Día 91 o practicar con cronómetro. Terminar el problema después del simulacro (*upsolving*) y anotar qué idea faltaba es tan importante como el puntaje.

**Problema 93.1 — Suma de sumas de divisores** · nivel 7

Sea `σ(k)` la suma de los divisores de `k`.

- **Entrada:** `n`, con `1 ≤ n ≤ 10^12`.
- **Salida:** `σ(1) + σ(2) + … + σ(n)` módulo `10^9 + 7`.
- **Subtareas:** (20 puntos) `n ≤ 1000`; (30 puntos) `n ≤ 10^6`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5` → `21`; `10` → `87`.
- **Matemática:** cada `d` es divisor de `floor(n/d)` números entre 1 y `n`, así que la suma vale `Σ_{d=1}^{n} d · floor(n/d)`. El valor `floor(n/d)` toma solo `O(√n)` valores distintos: agrupa los `d` consecutivos con el mismo cociente `q`, que van de `d` a `e = floor(n/q)`, y suma `q · (d + e)(e − d + 1)/2` (calcula esa suma de una progresión aritmética con cuidado: reduce los factores módulo `p` y usa el inverso de 2, o divide primero el factor par). Justifica por qué hay a lo sumo `2√n` grupos.

**Problema 93.2 — Cupos de cursos** · nivel 8

- **Entrada:** `n m`; los `m` cupos `c_1 … c_m`; luego, para cada uno de los `n` estudiantes, una línea `k j_1 … j_k` con los cursos que acepta. Límites: `1 ≤ n ≤ 20000`, `1 ≤ m ≤ 1000`, la suma de los `k` es `≤ 10^5`, `0 ≤ c_j ≤ 10^4`. Cada estudiante puede inscribirse en **un solo** curso de su lista y cada curso admite a lo sumo su cupo.
- **Salida:** la mayor cantidad de estudiantes que se pueden inscribir.
- **Subtareas:** (20 puntos) `n ≤ 10`, `m ≤ 5`; (30 puntos) `n ≤ 100`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `3 2 / 1 2 / 1 1 / 2 1 2 / 1 2` → `3`; `3 2 / 1 1 / 1 1 / 1 1 / 2 1 2` → `2`.
- **Matemática:** modela como un flujo: fuente → estudiante (capacidad 1), estudiante → curso (capacidad 1), curso → sumidero (capacidad = cupo). Justifica por qué el flujo máximo entero es la respuesta y calcula el costo con Dinic (el grafo tiene capacidades unitarias en un lado).

**Problema 93.3 — `k`-ésimo valor en un camino** · nivel 10

- **Entrada:** `n q`; `n` valores `a_i`; `n − 1` aristas; `q` consultas `u v k`. Límites: `1 ≤ n, q ≤ 10^5`, `|a_i| ≤ 10^9`, `1 ≤ k ≤` la cantidad de vértices del camino de `u` a `v`.
- **Salida:** el `k`-ésimo menor valor entre los vértices del camino de `u` a `v`, por consulta.
- **Subtareas:** (20 puntos) `n, q ≤ 100`; (30 puntos) `n, q ≤ 3000`; (50 puntos) sin restricciones adicionales.
- **Ejemplo:** `5 3 / 5 2 7 1 6 / 1 2 / 1 3 / 3 4 / 3 5 / 2 4 2 / 4 5 3 / 2 2 1` → `2 / 7 / 2`.
- **Matemática:** construye un árbol de segmentos persistente (Día 85) donde la versión de cada vértice `v` es la de su padre más el valor de `v`. Para el camino `u–v` con `l = lca(u, v)`, los conteos son `cnt[u] + cnt[v] − cnt[l] − cnt[padre(l)]`; baja por las cuatro versiones a la vez. Justifica la fórmula por inclusión–exclusión y calcula el costo `O((n + q) log n)`.

**Proyecto del día — Informe de la Jornada 2 y plan de continuación**

1. Entrega la mejor solución completa de cada problema, los tests de estrés y la tabla de cronograma y puntajes, como el Día 92.
2. **Informe final del plan** (en las notas, máximo dos páginas):
   - Una **autoevaluación por tema** (1 a 5): aritmética y teoría de números, ordenamiento y búsqueda, voraz, DP, grafos, árboles, estructuras de datos, cadenas, geometría, juegos, construcción y verificación.
   - Los **cinco errores** que más cometiste a lo largo de los 93 días y cómo los previenes (usa tus bitácoras de los repasos).
   - La comparación de tus cuatro simulacros (Días 35, 63, 92 y 93): puntajes y tendencias.
   - Un **plan de las siguientes cuatro semanas** con metas medibles (por ejemplo, "resolver 3 problemas de nivel 8 por semana de un juez en línea, con upsolving").
3. Menciona la herramienta o recurso externo que usarás para seguir practicando (la sección de recursos del apéndice).

- **Qué califico:** corrección y eficiencia, la honestidad y concreción del análisis, y la calidad del plan.
- **Entrega:** `d93_p1.cpp`, `d93_p2.cpp`, `d93_p3.cpp` y `d93_notas.md`.

---

## Apéndice A · Referencia rápida de la biblioteca estándar de C++

| Estructura | Operaciones principales | Costo |
|---|---|---|
| `vector<T>` | `v[i]`, `push_back`, `pop_back`, `back`, `size`, `clear`, `resize` | acceso `O(1)`; `push_back` `O(1)` amortizado; insertar/borrar en medio `O(n)` |
| `string` | `s[i]`, `size`, `substr`, `find`, `+=`, `==`, `<` | `find` y comparaciones `O(n)` |
| `pair<A,B>` / `tuple` | `.first`, `.second`, comparación lexicográfica | `O(1)` |
| `stack`, `queue`, `deque` | `push`, `pop`, `top`/`front`/`back` (deque: por ambos extremos) | `O(1)` |
| `priority_queue` | `push`, `pop`, `top` | `push`/`pop` `O(log n)`; `top` `O(1)` |
| `set`, `multiset`, `map` | `insert`, `erase`, `find`, `count`, `lower_bound`, `upper_bound` | `O(log n)` |
| `unordered_set`, `unordered_map` | `insert`, `find`, `erase` | `O(1)` en promedio (peor caso `O(n)`) |
| `bitset<N>` | `&`, `\|`, `^`, `<<`, `>>`, `count`, `[i]` | `O(N/64)` por operación |

**Funciones de `<algorithm>` y `<numeric>` que más usarás.**

| Función | Qué hace |
|---|---|
| `sort(a, b)`, `sort(a, b, comp)` | ordena `[a, b)` en `O(n log n)` |
| `lower_bound(a, b, x)`, `upper_bound(a, b, x)` | primera posición `≥ x` / `> x` en un rango ordenado |
| `binary_search(a, b, x)` | ¿está `x` en el rango ordenado? |
| `reverse(a, b)`, `unique(a, b)` | invierte; quita repetidos **consecutivos** (se usa tras ordenar) |
| `next_permutation(a, b)` | siguiente permutación lexicográfica (`false` si era la última) |
| `min_element`, `max_element` | iterador al menor / mayor |
| `accumulate(a, b, 0LL)` | suma de un rango (con `0LL` para sumar en `long long`) |
| `iota(a, b, x)` | rellena con `x, x+1, x+2, …` |
| `gcd(a, b)`, `lcm(a, b)` | máximo común divisor y mínimo común múltiplo |
| `fill(a, b, x)` | rellena con `x` |
| `__builtin_popcountll(x)`, `__lg(x)` | bits encendidos; `floor(log2(x))` |

**Plantillas útiles.**

```cpp
// recorrer todas las permutaciones de v
sort(v.begin(), v.end());
do { /* usa v */ } while (next_permutation(v.begin(), v.end()));

// ordenar y quitar repetidos
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// comparador para ordenar pares por segundo elemento descendente
sort(p.begin(), p.end(), [](const auto &x, const auto &y) { return x.second > y.second; });

// generador aleatorio con semilla fija
mt19937_64 rng(12345);
long long x = uniform_int_distribution<long long>(1, 100)(rng);
```

---

## Apéndice B · Fórmulas y hechos clave

**Sumas.**

- `1 + 2 + … + n = n(n + 1)/2`
- `1² + 2² + … + n² = n(n + 1)(2n + 1)/6`
- `1³ + 2³ + … + n³ = (n(n + 1)/2)²`
- Progresión geométrica: `1 + r + … + r^n = (r^(n+1) − 1)/(r − 1)` (`r ≠ 1`)
- Número armónico: `H_n = 1 + 1/2 + … + 1/n ≈ ln n + 0,577`

**Combinatoria.**

- `C(n, k) = n! / (k!(n − k)!)`; Pascal: `C(n, k) = C(n−1, k−1) + C(n−1, k)`; `Σ_k C(n, k) = 2^n`
- Estrellas y barras: las soluciones enteras no negativas de `x_1 + … + x_k = n` son `C(n + k − 1, k − 1)`
- Catalan: `C_n = C(2n, n) − C(2n, n + 1)`; `1, 1, 2, 5, 14, 42, 132, …`
- Desarreglos: `D(n) = (n − 1)(D(n − 1) + D(n − 2))`; funciones sobreyectivas: `Σ_j (−1)^j C(m, j)(m − j)^n`
- Inclusión–exclusión: `|∪ A_i| = Σ |A_i| − Σ |A_i ∩ A_j| + …`

**Teoría de números.**

- `gcd(a, b) = gcd(b, a mod b)`; `gcd · lcm = a · b`; Bézout: `a·x + b·y = gcd(a, b)`
- Fermat: `a^(p−1) ≡ 1 (mod p)` si `p` es primo y no divide a `a`; inverso `a^(p−2)`
- Euler: `a^φ(m) ≡ 1 (mod m)` si `gcd(a, m) = 1`; `φ(n) = n · Π (1 − 1/p)`
- Divisores: `τ(n) = Π (e_i + 1)`; `σ(n) = Π (p^(e+1) − 1)/(p − 1)`
- Legendre: el exponente de `p` en `n!` es `Σ floor(n / p^k)`
- Teorema chino del resto: sistemas `x ≡ a_i (mod m_i)` con módulos coprimos tienen solución única módulo `Π m_i`

**Probabilidad.** `E[X + Y] = E[X] + E[Y]`; esperanza de una suma de indicadores = suma de probabilidades; coleccionista de cupones `n · H_n`; inversiones esperadas `n(n − 1)/4`.

**Grafos y árboles.** `Σ grado = 2m`; un árbol tiene `n − 1` aristas; el número ciclomático es `m − n + c`; flujo máximo = corte mínimo; en un grafo bipartito, emparejamiento máximo = cubrimiento mínimo (König).

**Geometría.** `cruz(a, b) = a.x·b.y − a.y·b.x`; `2 · área = |Σ cruz(p_i, p_{i+1})|`; Pick: `A = I + B/2 − 1`.

**Complejidades típicas (1 segundo).**

| `n` | Complejidad |
|---|---|
| hasta 10 | `O(n!)` |
| hasta 20 | `O(2^n · n)` |
| hasta 500 | `O(n^3)` |
| hasta 5 000 | `O(n^2)` |
| hasta 200 000 | `O(n log n)` |
| hasta 10 000 000 | `O(n)` |
| hasta 10^18 | `O(log n)` o `O(1)` |

---

## Apéndice C · Lista de errores frecuentes

1. **Desbordamiento:** usar `int` donde el resultado necesita `long long`; multiplicar antes de reducir módulo; `1 << 40` en lugar de `1LL << 40`.
2. **Uno de más o de menos:** índices desde 0 o desde 1, rangos cerrados o semiabiertos, `mid` en la búsqueda binaria.
3. **Resto negativo:** `(-7) % 3` es `-1` en C++; usa `((a % m) + m) % m`.
4. **Sin inicializar:** variables locales, arreglos que no se reinician entre casos de prueba, `INF` mal elegido (que se desborda al sumar).
5. **Comparadores inválidos:** `<=` en lugar de `<`, o un orden que no es transitivo; provocan fallos de `sort`.
6. **Recursión demasiado profunda:** grafos en forma de camino con `n = 2·10^5`; pasa a una versión iterativa.
7. **Acceso fuera de rango:** `v[n]`, `v[-1]`; compila con `-fsanitize=address,undefined` para detectarlo.
8. **Leer mal la entrada:** mezclar `cin >> x` con `getline` sin descartar el salto de línea; no manejar fin de archivo.
9. **Salida lenta:** `endl` en ciclos largos; usa `"\n"` y `ios::sync_with_stdio(false)`.
10. **Casos borde olvidados:** `n = 1`, entrada vacía, todos los valores iguales, el valor máximo permitido.
11. **Un voraz sin demostración:** si no sabes por qué funciona, busca un contraejemplo con una fuerza bruta antes de confiar en él.
12. **No comparar con una fuerza bruta:** la prueba de estrés encuentra en segundos errores que no verías en horas.

---

## Apéndice D · Dónde seguir practicando

Estos sitios sirven para seguir entrenando cuando termines el plan (verifica en cada uno las reglas y la disponibilidad actual):

- **CSES Problem Set** (`cses.fi`): una colección de problemas clásicos organizados por tema (ordenar y buscar, DP, grafos, consultas de rango, árboles, matemáticas, cadenas, geometría). Muy buena para practicar cada técnica de este plan en orden.
- **USACO Guide** (`usaco.guide`): una guía de estudio con lecciones y problemas por nivel.
- **cp-algorithms** (`cp-algorithms.com`): explicaciones y códigos de algoritmos y estructuras de datos.
- **Codeforces** (`codeforces.com`) y **AtCoder** (`atcoder.jp`): concursos periódicos para practicar bajo presión de tiempo.
- **Sitio oficial de la IOI** (`ioinformatics.org`): busca ahí los enunciados de ediciones anteriores para practicar el formato con subtareas.

**Cómo practicar bien.** Resuelve primero sin ayuda; si te atascas más de 45 minutos, lee solo una pista; escribe siempre un resumen de la idea clave y vuelve a resolver el problema una semana después sin mirar tu solución (*upsolving* y repaso espaciado).

---

*Fin del documento.* Cuando termines cada día, envíame los archivos del proyecto con "Entrega Día N" para calificarlos.
