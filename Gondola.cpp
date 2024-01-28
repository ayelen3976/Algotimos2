#include <iostream>
#include "Gondola.h"
#include "fstream"
#include <sstream>

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
    {
        if (this->cantidad == 0)
        {
            std::cout << "No hay productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;
        }
        else
        {
            std::cout << "Actualmente hay " << this->cantidad << " productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;

                this-> productos->mostrar();

        }
    }
}

void Gondola::agregarProductos(std::string productos_archivo){
    std::ifstream archivo(productos_archivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo " << productos_archivo << std::endl;
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string nombre;
        double precio;
        int enOferta;
        int stock;


        while (ss >> nombre >> precio >> enOferta >> stock) {
            this -> productos[cantidad] = Producto(nombre, precio, enOferta, stock);
            std::cout<< "se termino la carga de productos" << std::endl;

        cantidad ++;
    }}
}