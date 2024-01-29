#ifndef FERNANDEZ_109378_TP2_PRODUCTO_H
#define FERNANDEZ_109378_TP2_PRODUCTO_H
#include <iostream>
#include <string>

class Producto {
private:
    std::string nombre;
    double precio;
    unsigned int enOferta;
    unsigned int stock;

public:
    Producto();
    Producto(std::string nombre, double precio, unsigned int enOferta, unsigned int stock);

    ~Producto();

    void mostrar();
    std::string buscarNombreProducto( std::string nombre);
    double precioProducto();

    int ofertaProducto();

    int stockProducto();
};


#endif //FERNANDEZ_109378_TP2_PRODUCTO_H
