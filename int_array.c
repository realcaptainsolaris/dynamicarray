#include "int_array.h"
#include <stdio.h>
#include <stdlib.h>

// Anfangskapazität für das dynamische Array
static const size_t INITIAL_CAPACITY = 4;

/**
 * Initialisiert ein IntArray mit Standardkapazität.
 */
void init_array(IntArray *arr) {
  arr->size = 0;
  arr->capacity = INITIAL_CAPACITY;
  arr->data = malloc(arr->capacity * sizeof(int));
}

/**
 * Gibt den Speicher des Arrays wieder frei.
 */
void free_array(IntArray *arr) {
  free(arr->data);
  arr->data = NULL;
}

/**
 * Fügt einen Wert ans Ende des Arrays an.
 * Wenn die Kapazität nicht ausreicht, wird verdoppelt.
 */

void push_back(IntArray *arr, int value) {
  // Prüfen, ob noch Platz im Array ist
  if (arr->size >= arr->capacity) {
    // Kapazität verdoppeln
    arr->capacity *= 2;

    // Speicher neu allokieren mit neuer Kapazität
    int *new_data = realloc(arr->data, arr->capacity * sizeof(int));

    // Fehlerprüfung: Wenn realloc fehlschlägt → abbrechen
    if (!new_data) {
      perror("realloc failed");
      exit(EXIT_FAILURE);
    }

    // Pointer aktualisieren
    arr->data = new_data;
  }

  // Wert ans Ende des Arrays schreiben und size erhöhen
  arr->data[arr->size++] = value;
}

/**
 * Gibt den Inhalt des Arrays auf stdout aus.
 */
void print_array(const IntArray *arr) {
  printf("Array: ");
  for (size_t i = 0; i < arr->size; ++i) {
    printf("%d ", arr->data[i]);
  }
  printf("\n");
}
