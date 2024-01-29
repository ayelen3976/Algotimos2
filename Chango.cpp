#include "Chango.h"
#include "fstream"

Chango::Chango() {
    this -> capacidad = 5;
    this -> cantidad = 0;
    this -> productos = new Producto[5];
}
Chango::~Chango() {
    delete [] productos;
}


void Chango::cargarProductoEnGondola(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    this->productos[cantidad] = Producto(nombre, precio, enOferta, stock);
    std::cout<<" se guardo el prod en el chango ! :" << nombre << std::endl;
    cantidad++;
}

void Chango::mostrarProductosDelCHango() {
    std::cout << "Mostrando productos del changoo..." << std::endl;
    if (this->cantidad == 0) {
        std::cout << "No hay productos en el chango. La capacidad de la misma es " << this->capacidad << "." << std::endl;
    } else {
        std::cout << "Actualmente hay " << this->cantidad << " productos en el changoo. La capacidad de la misma es " << this->capacidad << "." << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++) {
            std::cout << "--------------Producto chango" << i << "--------------" << std::endl;
            this->productos[i].mostrar();
        }
    }
}

void Chango::buscarProductoEnGondola(Gondola &gondola, std::string archivo_productos) {
    std::ifstream archivo(archivo_productos);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo " << archivo_productos << std::endl;
        return;
    }
    std::string nombre;
    unsigned int cantidad;
    int posicion;

    while (archivo >> nombre >> cantidad) {
    posicion = gondola.buscarProducto(nombre);
        if (posicion != -1) {
            double precio_producto = gondola.obtenerProducto(posicion).precioProducto();
            unsigned int oferta_producto= gondola.obtenerProducto(posicion).ofertaProducto();
            unsigned int stock_producto =  gondola.obtenerProducto(posicion).stockProducto();

       this ->cargarProductoEnGondola(nombre, precio_producto, oferta_producto, stock_producto );
        } else {
            std::cout << "El producto " << nombre << " no se encuentra en la góndola." << std::endl;
        }
    }

    archivo.close();


}
