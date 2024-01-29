#include "Producto.h"
Producto::Producto(){}

Producto::Producto(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    this -> nombre = nombre;
    this ->precio = precio;
    this ->enOferta = enOferta;
    this ->stock = stock;
}
Producto::~Producto() {}

void Producto::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Precio: " << precio << std::endl;
    std::cout << "En Oferta: " << (enOferta ? "Sí" : "No") << std::endl;
    std::cout << "Stock: " << stock << std::endl;

}
std::string Producto::buscarNombreProducto(std::string nombre) {
    return this->nombre;
}

double Producto::precioProducto() {
    return this->precio;
}

int Producto::ofertaProducto() {
    return this->enOferta;
}
int Producto::stockProducto() {
    return this->stock;
}
