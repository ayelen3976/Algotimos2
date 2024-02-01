#include "Producto.h"
Producto::Producto(){}

Producto::Producto(std::string nombre, double precio, unsigned int descuento, unsigned int stock) {
    this -> nombre = nombre;
    this ->precio = precio;
    this ->descuento = descuento;
    this ->stock = stock;
}
Producto::~Producto() {}

void Producto::mostrar_producto_gondola(){
    std::cout << nombre<<"\t "<<precio<<"\t"<<descuento<<"\t"<<stock<<"\t " << std::endl;
}
void Producto::mostrar_producto_chango(){
std::cout << " cantidad: " << stock << "\t\t";
std::cout << " Nombre: " << nombre << "\t\t"<<std::endl;
}

std::string Producto::nombre_producto() {
    return this->nombre;
}

double Producto::precio_producto() {
    return this->precio;
}

int Producto::oferta_producto() {
    return this->descuento;
}
int Producto::stock_producto() {
    return this->stock;
}


