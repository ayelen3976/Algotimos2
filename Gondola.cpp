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
/*void Gondola::redimensionar(int nuevaCapacidad) {
    Producto* nuevoArray = new Producto[nuevaCapacidad];
    for (int i = 0; i < cantidad; ++i) {
        nuevoArray[i] = productos[i];
    }
    delete[] productos;
    productos = nuevoArray;
    capacidad = nuevaCapacidad;
}*/
void Gondola::mostrarProductos() {
    std::cout << "Mostrando productos..." << std::endl;
    if (this->cantidad == 0) {
        std::cout << "No hay productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;
    } else {
        std::cout << "Actualmente hay " << this->cantidad << " productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++) {
            std::cout << "Producto " << i << ": ";
            //this->productos[i].mostrar();  // Asegúrate de que esta línea esté correcta
            std::cout << "Mostrado producto " << i << std::endl;  // Mensaje de depuración
        }
    }
}

void Gondola::agregarProductos(std::string productos_archivo) {
    std::ifstream archivo(productos_archivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo " << productos_archivo << std::endl;
        return;
    }

    std::string linea;
    std::string nombre;
    double precio;
    int enOferta;
    int stock;

        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            if (ss >> nombre >> precio >> enOferta >> stock) {
                this->productos[cantidad] = Producto(nombre, precio, enOferta, stock);
                std::cout<<" se guardo el prod :" << nombre << std::endl;
                cantidad++;
            }
        }

        archivo.close();

/*
        if (ss >> nombre >> precio >> enOferta >> stock) {
            if (cantidad == capacidad) {
                // Asegúrate de tener un método que maneje el redimensionamiento
                redimensionar(capacidad * 2);
            }
            this->productos[cantidad++] = Producto(nombre, precio, enOferta != 0, stock);

            // Impresión de depuración para verificar los datos leídos
            std::cout << "Producto agregado: " << nombre << std::endl;
        }
*/

}