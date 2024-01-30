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

void Gondola::mostrar_productos(){
    if (this->cantidad == 0) {
        std::cout << "No hay productos en la gondola." << std::endl;
    } else {
        std::cout << "Actualmente hay " << this->cantidad << " productos en la gondola. La capacidad es de " << this->capacidad << "." << std::endl;
        std::cout << "///////PRODUCTOS////////" << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++) {
            this->productos[i].mostrar_producto_gondola();
        }
        std::cout << "///////////////////////" << std::endl;

    }
}

void Gondola::agregar_productos(std::string productos_archivo){
    std::ifstream archivo(productos_archivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo " << productos_archivo << std::endl;
        return;
    }

    std::string nombre;
    double precio;
    int descuento;
    int stock;
    while(archivo >> nombre >> precio >> descuento >> stock) {
        this->productos[cantidad] = Producto(nombre, precio, descuento, stock);
        cantidad++;
        if(cantidad == capacidad){
            capacidad = capacidad*2;
            redimensionar_capacidad(capacidad);
        }
    }
    if(cantidad <= (capacidad/2)-1){
        capacidad =  (capacidad/2);
        redimensionar_capacidad(capacidad);
    }
    archivo.close();
}

void Gondola::redimensionar_capacidad(unsigned int factor){
    Producto* nuevosProductos = new Producto[factor];
    for (int i = 0; i < cantidad; ++i) {
        nuevosProductos[i] = this->productos[i];
    }
    delete [] this->productos;
    this -> productos = nuevosProductos;
}



int Gondola::buscar_producto(std::string nombre){
    for (int i = 0; i < cantidad; ++i) {
        if(this->productos[i].nombre_producto() == nombre){
            return i;
        }
    }
    return -1;
}

Producto Gondola::obtener_producto(unsigned int posicion) {
    return this->productos[posicion];
}

void Gondola::actualizar_productos_gondola(Producto* producto) {
    for (int i = 0; i < cantidad; ++i) {
        if(this->productos[i].nombre_producto() == producto->nombre_producto()){
            this->productos[i] = *producto;
        }
    }
}
void Gondola::guardar_stock_actualizado(std::string archivo_productos) {
    std::cout << "vamos a guardar el stock actualizado en el archivo !!!!" << std::endl;
    {
        std::ofstream arProductosActualizados(archivo_productos);

        for (unsigned int i = 0; i < this->cantidad; i++)
        {
            arProductosActualizados << this->productos[i].nombre_producto() << "\t"
                                    << this->productos[i].precio_producto() << "\t"
                                    << this->productos[i].oferta_producto() << "\t"
                                    << this->productos[i].stock_producto()<< std::endl;
        }

        arProductosActualizados.close();
    }

}

void Gondola::eliminar_producto(std::string nombreProducto) {
    for (int i = 0; i < cantidad; ++i) {
        if (this->productos[i].nombre_producto() == nombreProducto) {
            for (int j = i; j < cantidad - 1; ++j) {
                this->productos[j] = this->productos[j + 1];
            }
            cantidad--;
            this->productos[cantidad] = Producto();
            break;
        }
    }
}