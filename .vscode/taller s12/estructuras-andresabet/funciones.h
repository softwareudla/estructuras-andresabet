

struct Libro {
    int id;
    char titulo[100];
    char estado[20];
     char autor[100];
    int anio;
};

int menu();
void registrarLibro(struct Libro libros[], int *contador);
void mostrarLibros(struct Libro libros[], int contador);
void buscarLibroPorId(struct Libro libros[], int contador, int id);
void buscarLibroPorTitulo(struct Libro libros[], int contador, char titulo[]);
void actualizarEstado(struct Libro libros[], int contador);
void eliminarLibro(struct Libro libros[], int *contador);