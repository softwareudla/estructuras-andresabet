#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_LIBROS 20
#define DISPONIBLE "Disponible"
#define PRESTADO "Prestado"
void registrarLibro(struct Libro libros[], int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("No se pueden registrar más libros. Límite alcanzado.\n");
        return;
    }

    struct Libro nuevoLibro;
    printf("\n--- Registrar Libro ---\n");
    printf("Ingrese ID del libro: ");
    scanf("%d", &nuevoLibro.id);

    // Validar ID único
    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == nuevoLibro.id) {
            printf("Error: El ID ingresado ya existe.\n");
            return;
        }
    }

    printf("Ingrese título del libro: ");
    scanf(" %[^\n]", nuevoLibro.titulo);
    printf("Ingrese autor del libro: ");
    scanf(" %[^\n]", nuevoLibro.autor);
    printf("Ingrese año de publicación: ");
    scanf("%d", &nuevoLibro.anio);
    strcpy(nuevoLibro.estado, DISPONIBLE);

    libros[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado con éxito.\n");
}

void mostrarLibros(struct Libro libros[], int contador) {
    printf("\n--- Lista de Libros ---\n");
    printf("%-5s %-30s %-20s %-10s %-15s\n", "ID", "Título", "Autor", "Anio", "Estado");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%-5d %-30s %-20s %-10d %-15s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibroPorId(struct Libro libros[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) {
            printf("\n--- Información del Libro ---\n");
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}

void buscarLibroPorTitulo(struct Libro libros[], int contador, char titulo[]) {
    for (int i = 0; i < contador; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("\n--- Información del Libro ---\n");
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("Libro con título '%s' no encontrado.\n", titulo);
}

void actualizarEstado(struct Libro libros[], int contador) {
    int id;
    printf("Ingrese el ID del libro para actualizar su estado: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, DISPONIBLE) == 0) {
                strcpy(libros[i].estado, PRESTADO);
            } else {
                strcpy(libros[i].estado, DISPONIBLE);
            }
            printf("Estado del libro actualizado con éxito.\n");
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}

void eliminarLibro(struct Libro libros[], int *contador) {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado con éxito.\n");
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}