#include "Producto.h"
Producto::Producto(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    this -> nombre = nombre;
    this ->precio = precio;
    this ->enOferta = enOferta;
    this ->stock = stock;
}
//Producto::~Producto() {}