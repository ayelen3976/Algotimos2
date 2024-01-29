
#ifndef FERNANDEZ_109378_TP2_GONDOLA_H
#define FERNANDEZ_109378_TP2_GONDOLA_H
#include "Producto.h"

class Gondola {
private:
    Producto *productos;
    unsigned int capacidad;
    unsigned int cantidad;

public:
Gondola();
~Gondola();

void mostrarProductos();

void agregarProductos(std::string archivo_productos);

int buscarProducto(std::string nombre);

Producto obtenerProducto(unsigned int posicion);

void redimensionarCapacidad(unsigned int factor); // Declaración de la función
};
#endif //FERNANDEZ_109378_TP2_GONDOLA_H
