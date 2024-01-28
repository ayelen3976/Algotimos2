#include <iostream>
#include "Gondola.h"
#include "fstream"

Gondola::Gondola() {
this ->capacidad = 5;
this -> cantidad = 0;
this ->productos = new Producto[5];
}
Gondola :: ~Gondola() {
    delete [] productos;
}
void Gondola::redimensionar(int nuevaCapacidad) {
    Producto* nuevoArray = new Producto[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevoArray[i] = productos[i];
    }
    delete[] productos;
    productos = nuevoArray;
    capacidad = nuevaCapacidad;
}

void Gondola ::mostrarProductos() {
    if(this -> cantidad <= 0 ){
        std::cout << "Lo siento no hay productos todavia en la Gondola" << std::endl;
    }
}

void Gondola::agregarProductos(std::string productos_archivo){
    std::ifstream archivo(productos_archivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo " << productos_archivo << std::endl;
        return;
    }
    std::string nombre;
    double precio;
    int enOferta;
    int stock;

    while (archivo >> nombre >> precio >> enOferta >> stock) {
    this->productos = new Producto(nombre, precio, enOferta, stock);
    std::cout<< "se termino la carga de productos" << std::endl;
    }
}