#include "Producto.h"
Producto::Producto(){}

Producto::Producto(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    this -> nombre = nombre;
    this ->precio = precio;
    this ->enOferta = enOferta;
    this ->stock = stock;
}
Producto::~Producto() {}

void Producto::mostrarProductoGondola(){
    std::cout << " Nombre: " << nombre << " |";
    std::cout << " Precio: " << precio << " |";
    std::cout << " En Oferta: " << (enOferta ? "Sí" : "No") << " |";
    std::cout << " Stock: " << stock << std::endl;
}
void Producto::mostrarProductoChango(){
std::cout << " Nombre: " << nombre << " |";
std::cout << " Precio: " << precio << " |";
std::cout << " En Oferta: " << (enOferta ? "Sí" : "No") << " |";
std::cout << " cantidad:" << stock << std::endl;
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
void Producto::actualizarStock(unsigned int nuevostock) {
    this ->stock = nuevostock;
}
