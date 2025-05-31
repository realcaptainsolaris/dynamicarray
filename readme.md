# Modern C – 2D-Partikelsimulation mit dynamischem Array

Dieses Projekt demonstriert eine einfache 2D-Partikelsimulation in modernem C (C99/C11), umgesetzt mit dynamischen Arrays und ASCII-Grafik im Terminal.

## Features

- Dynamische Speicherung von Partikelpositionen mit `IntArray`
- 2D-Darstellung im Terminal mit `.` und `*`
- Zufällige Bewegung in X- und Y-Richtung
- Verwendung von `nanosleep()` statt `usleep()` für bessere Kompatibilität
- Saubere Trennung von Header (`int_array.h`) und Implementation (`int_array.c`)
- Kompilierbar mit `-Wall -Wextra` unter Linux/macOS

## Beispielausgabe

```

..............................
......*...........*...........
.............*..............*.
.........*....................
..................*.......\*...

````


## Dateien

| Datei         | Zweck                                  |
|---------------|------------------------------------------|
| `main.c`      | Partikelsimulation mit ASCII-Rendering   |
| `int_array.h` | Dynamisches Array (Interface + inline)   |
| `int_array.c` | Implementation des Arrays                |
| `Makefile`    | Build-System mit Debug/Release-Zielen    |

## Kompilierung

```bash
make relase        # Release-Build
make debug  # Debug-Build mit -g und -O0
make clean
````

## Ausführung

```bash
./app
```

## Systemvoraussetzungen

* Linux oder macOS
* GCC oder Clang
* Terminal mit ANSI-Sequenzunterstützung (für "clear"-Effekt)


## Lizenz

MIT


