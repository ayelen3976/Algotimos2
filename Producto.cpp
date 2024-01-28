#include "Producto.h"
Producto::Producto(){}

Producto::Producto(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    this -> nombre = nombre;
    this ->precio = precio;
    this ->enOferta = enOferta;
    this ->stock = stock;
}
Producto::~Producto() {}

std::string Producto::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Precio: " << precio << std::endl;
    std::cout << "En Oferta: " << (enOferta ? "Sí" : "No") << std::endl;
    std::cout << "Stock: " << stock << std::endl;

}
