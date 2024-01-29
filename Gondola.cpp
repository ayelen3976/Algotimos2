#include <iostream>
#include "Gondola.h"
#include "fstream"

Gondola::Gondola() {
this -> capacidad = 5;
this -> cantidad = 0;
this -> productos = new Producto[5];
}
Gondola :: ~Gondola() {
    delete [] productos;
}

void Gondola::mostrarProductos() {
    std::cout << "Mostrando productos..." << std::endl;
    if (this->cantidad == 0) {
        std::cout << "No hay productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;
    } else {
        std::cout << "Actualmente hay " << this->cantidad << " productos en la gondola. La capacidad de la misma es " << this->capacidad << "." << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++) {
            std::cout << "--------------Producto" << i << "--------------" << std::endl;
            this->productos[i].mostrar();
        }
    }
}

void Gondola::redimensionarCapacidad(unsigned int factor) {
    unsigned int nuevaCapacidad = capacidad * factor;

    if (cantidad <= (capacidad / 2) - 1) { // Reducir la capacidad si la cantidad de productos es menor o igual a la mitad de la capacidad actual
        nuevaCapacidad = capacidad / 2;
    }

    Producto* nuevosProductos = new Producto[nuevaCapacidad];

    for (unsigned int i = 0; i < cantidad; ++i) {
        nuevosProductos[i] = productos[i];
    }

    delete[] productos;
    productos = nuevosProductos;
    capacidad = nuevaCapacidad;
}

void Gondola::agregarProductos(std::string productos_archivo) {
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
        if (cantidad == capacidad) {
            redimensionarCapacidad(2); // Duplica la capacidad si es necesario
        }

        this->productos[cantidad] = Producto(nombre, precio, enOferta, stock);
        std::cout << "Se guardó el producto: " << nombre << std::endl;
        cantidad++;
    }
     /*       while(archivo >> nombre >> precio >> enOferta >> stock) {
                this->productos[cantidad] = Producto(nombre, precio, enOferta, stock);
                std::cout<<" se guardo el prod :" << nombre << std::endl;
                cantidad++;

            if(cantidad == capacidad){
                capacidad = capacidad*2;
                Producto* nuevosProductos = new Producto[capacidad];
                for (int i = 0; i < cantidad; ++i) {
                    nuevosProductos[i] = this->productos[i];
                }
                delete [] this->productos;
                this -> productos = nuevosProductos;
            }
            if(cantidad <= (capacidad/2)-1){
                capacidad =  (capacidad/2);
                Producto* nuevosProductos = new Producto[capacidad];
                for (int i = 0; i < cantidad; ++i) {
                    nuevosProductos[i] = this->productos[i];
                }
                delete [] this->productos;
                this -> productos = nuevosProductos;
            }
        }*/

        archivo.close();

}

int Gondola::buscarProducto(std::string nombre){
    for (int i = 0; i < cantidad; ++i) {
        if(this->productos[i].buscarNombreProducto(nombre) == nombre){
            std::cout << "Esta es la posición de mi producto buscado: " << i << std::endl;
            return i;
        }
    }
    return -1;

}

Producto Gondola::obtenerProducto(unsigned int posicion) {
    return this->productos[posicion];
}