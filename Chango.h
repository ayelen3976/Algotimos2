
#ifndef FERNANDEZ_109378_TP2_CHANGO_H
#define FERNANDEZ_109378_TP2_CHANGO_H
#include "Producto.h"
#include "Gondola.h"
class Chango {
private:
    Producto *productos;
    unsigned int capacidad;
    unsigned int cantidad;
public:
    Chango();
    ~Chango();

    void cargarProductoEnGondola(std::string nombre, double precio, unsigned int enOferta, unsigned int stock);
    void buscarProductoEnGondola(Gondola& gondola, std::string archivo_compra);
    void mostrarProductosDelCHango();
    void redimensionarCapacidad(unsigned int factor);
    void realizarCompra();

};


#endif //FERNANDEZ_109378_TP2_CHANGO_H
