#include <stdio.h>
#include <string.h>
#include "funciones.h"


#define MAX_LIBROS 20
#define DISPONIBLE "Disponible"
#define PRESTADO "Prestado"


// Función principal
int main() {
    struct Libro libros[MAX_LIBROS];
    int contador = 0;
    int opc;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibro(libros, &contador);
                break;
            case 2:
                mostrarLibros(libros, contador);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroPorId(libros, contador, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el titulo del libro a buscar: ");
                scanf(" %[^\n]", titulo);
                buscarLibroPorTitulo(libros, contador, titulo);
                break;
            }
            case 5:
                actualizarEstado(libros, contador);
                break;
            case 6:
                eliminarLibro(libros, &contador);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opc != 7);

    return 0;
}

// Implementación de funciones
int menu() {
    int opcion;
    printf("\n--- Menu Biblioteca ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar lista de libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Actualizar estado del libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
