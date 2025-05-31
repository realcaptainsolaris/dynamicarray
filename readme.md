# Modern C – Dynamisches Array (Header + Source getrennt)

Dieses Projekt zeigt ein **dynamisches Array in modernem C**, aufgeteilt in Header und Implementation. Ziel ist sauberes, sicheres und wartbares C, kompatibel mit C99/C11.

## Features

- Dynamisch wachsendes `IntArray` (mit `malloc`, `realloc`)
- Modularer Aufbau: `.h`/`.c`-Trennung
- `static inline`-Funktion (`square`) im Header
- Fehlerprüfung bei Speicheroperationen
- `const`, `size_t`, `NULL`, `-Wall -Wextra` konform

## Dateien

| Datei         | Beschreibung                          |
|---------------|----------------------------------------|
| `int_array.h` | Interface & Inline-Hilfsfunktion       |
| `int_array.c` | Implementierung des dynamischen Arrays |
| `main.c`      | Beispielnutzung mit `square(i)`        |

## Kompilierung

```bash
gcc -std=c11 -Wall -Wextra -o app main.c int_array.c
````

## Makefile
    make release # Release-Build mit -O2
    make debug   # Debug-Build mit -g und ohne Optimierung
    make clean   # Aufräumen

## Ausführung

```bash
./app
```

### Beispielausgabe:

```
Array: 0 1 4 9 16 25 36 49 64 81
```

## Funktionen

* `init_array(&arr)` – Initialisiert ein neues Array
* `push_back(&arr, value)` – Fügt ein Element hinzu (automatisches Realloc)
* `print_array(&arr)` – Gibt alle Werte aus
* `free_array(&arr)` – Gibt den Speicher frei
* `square(x)` – Inline-Funktion im Header


