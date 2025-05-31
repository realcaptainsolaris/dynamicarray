#define _POSIX_C_SOURCE 200112L

#include "int_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 30
#define HEIGHT 10
#define PARTICLES 15
#define STEPS 100

void sleep_ms(int milliseconds) {
  struct timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds % 1000) * 1000000;
  nanosleep(&ts, NULL);
}

void render(const IntArray *x_pos, const IntArray *y_pos) {
  char grid[HEIGHT][WIDTH + 1];

  // Gitter mit '.' initialisieren
  for (int y = 0; y < HEIGHT; ++y) {
    for (int x = 0; x < WIDTH; ++x)
      grid[y][x] = '.';
    grid[y][WIDTH] = '\0';
  }

  // Partikel einzeichnen
  for (size_t i = 0; i < x_pos->size; ++i) {
    int x = x_pos->data[i];
    int y = y_pos->data[i];
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
      grid[y][x] = '*';
  }

  // Gitter ausgeben
  printf("\033[H\033[J"); // Terminal löschen
  for (int y = 0; y < HEIGHT; ++y)
    puts(grid[y]);
}

int main(void) {
  srand((unsigned)time(NULL));
  IntArray x_pos, y_pos;
  init_array(&x_pos);
  init_array(&y_pos);

  // Startpositionen zufällig setzen
  for (int i = 0; i < PARTICLES; ++i) {
    push_back(&x_pos, rand() % WIDTH);
    push_back(&y_pos, rand() % HEIGHT);
  }

  // Simulation starten
  for (int step = 0; step < STEPS; ++step) {
    render(&x_pos, &y_pos);
    sleep_ms(150);

    for (size_t i = 0; i < x_pos.size; ++i) {
      int dx = (rand() % 3) - 1;
      int dy = (rand() % 3) - 1;

      x_pos.data[i] += dx;
      y_pos.data[i] += dy;

      // Begrenzen
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

  free_array(&x_pos);
  free_array(&y_pos);
  return 0;
}
