/**
 * @file main.c
 * @brief 2D-Partikelsimulation mit dynamischen Arrays in modernem C
 *
 * Dieses Programm simuliert eine einfache zweidimensionale Partikelbewegung.
 * Die Partikel bewegen sich zufällig über ein ASCII-Gitter und werden dort
 * als `*` dargestellt. Leere Felder erscheinen als `.`.
 *
 * Für die dynamische Speicherung der X- und Y-Positionen der Partikel
 * wird ein eigenes dynamisches Array (`IntArray`) verwendet, das in
 * int_array.h/.c definiert ist. Dadurch ist die Anzahl der Partikel flexibel
 * und das Projekt demonstriert den praktischen Einsatz von modularer
 * Datenstrukturverwaltung.
 *
 * Technische Besonderheiten:
 * - Positionen der Partikel werden unabhängig in zwei IntArrays gespeichert
 * - Die Bewegung erfolgt zufällig in 8 Richtungen (inkl. Stillstand)
 * - Die Darstellung wird pro Frame aktualisiert
 * - Zeitsteuerung erfolgt über `nanosleep` für ms-genaues Timing
 *
 * Build z. B. mit:
 *   gcc -std=c11 -Wall -Wextra -o app main.c int_array.c
 */

#define _POSIX_C_SOURCE 200112L
#include "int_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int WIDTH = 30;
const int HEIGHT = 10;
const int PARTICLES = 15;
const int STEPS = 100;

/**
 * Schlafe für eine bestimmte Anzahl Millisekunden.
 * Nutzt POSIX nanosleep für Portabilität.
 */
void sleep_ms(int milliseconds) {
  struct timespec ts = {.tv_sec = milliseconds / 1000,
                        .tv_nsec = (milliseconds % 1000) * 1000000};
  nanosleep(&ts, NULL);
}

/**
 * Gibt das aktuelle Partikelfeld als ASCII-Grafik im Terminal aus.
 *
 * @param x_pos  Array der X-Koordinaten aller Partikel
 * @param y_pos  Array der Y-Koordinaten aller Partikel
 */
void render(const IntArray *x_pos, const IntArray *y_pos) {
  char grid[HEIGHT][WIDTH + 1];

  // Gitter initialisieren mit '.'
  for (int y = 0; y < HEIGHT; ++y) {
    for (int x = 0; x < WIDTH; ++x)
      grid[y][x] = '.';
    grid[y][WIDTH] = '\0';
  }

  // Partikel als '*' ins Gitter setzen
  for (size_t i = 0; i < x_pos->size; ++i) {
    int x = x_pos->data[i];
    int y = y_pos->data[i];
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
      grid[y][x] = '*';
  }

  // Terminal löschen (ANSI-Sequenz) und Gitter ausgeben
  printf("\033[H\033[J");
  for (int y = 0; y < HEIGHT; ++y)
    puts(grid[y]);
}

/**
 * Hauptfunktion: Startet die 2D-Partikelsimulation.
 * Initialisiert Positionen und simuliert zufällige Bewegung.
 */
int main(void) {
  srand((unsigned)time(NULL)); // Zufallszahlengenerator initialisieren

  IntArray x_pos, y_pos;
  init_array(&x_pos);
  init_array(&y_pos);

  // Zufällige Startpositionen der Partikel erzeugen
  for (int i = 0; i < PARTICLES; ++i) {
    push_back(&x_pos, rand() % WIDTH);
    push_back(&y_pos, rand() % HEIGHT);
  }

  // Game Loop: Partikel bewegen und rendern
  for (int step = 0; step < STEPS; ++step) {
    render(&x_pos, &y_pos);
    sleep_ms(150); // kleine Pause für Animation

    // Bewegung jedes Partikels: zufällig -1, 0 oder +1 in x/y
    // rand() liefert einen Wert zwischen 0 und RAND_MAX (Makro)
    for (size_t i = 0; i < x_pos.size; ++i) {
      int dx = (rand() % 3) - 1;
      int dy = (rand() % 3) - 1;

      x_pos.data[i] += dx;
      y_pos.data[i] += dy;

      // Begrenzung auf gültige Feldgröße (Reflektion)
      if (x_pos.data[i] < 0)
        x_pos.data[i] = 0;
      if (x_pos.data[i] >= WIDTH)
        x_pos.data[i] = WIDTH - 1;
      if (y_pos.data[i] < 0)
        y_pos.data[i] = 0;
      if (y_pos.data[i] >= HEIGHT)
        y_pos.data[i] = HEIGHT - 1;
    }
  }

  // Speicher freigeben
  free_array(&x_pos);
  free_array(&y_pos);
  return 0;
}
