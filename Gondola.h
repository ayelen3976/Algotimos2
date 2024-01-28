
#ifndef FERNANDEZ_109378_TP2_GONDOLA_H
#define FERNANDEZ_109378_TP2_GONDOLA_H
#include "Producto.h"

class Gondola {
private:
    Producto *productos;
    unsigned int capacidad;
    unsigned int cantidad;

    void redimensionar(int nuevaCapacidad);

public:
Gondola();
~Gondola();


void agregarProductos(std::string archivo_productos);

void mostrarProductos();


};
#endif //FERNANDEZ_109378_TP2_GONDOLA_H
