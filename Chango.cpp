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

void Chango::redimensionarCapacidad(unsigned int factor) {
    unsigned int nuevaCapacidad = capacidad * factor;

    if (cantidad <= (capacidad / 2) - 1) {
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

void Chango::cargarProductoEnGondola(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    if (cantidad == capacidad) {
        redimensionarCapacidad(2); // Duplica la capacidad si es necesario
    }

    this->productos[cantidad] = Producto(nombre, precio, enOferta, stock);
    std::cout << "Se guardó el producto en el chango: " << nombre << std::endl;
    cantidad++;
}

void Chango::mostrarProductosDelCHango() {
    if (this->cantidad == 0) {
        //std::cout << "No hay productos en el chango. La capacidad de la misma es " << this->capacidad << "." << std::endl;
    } else {
        std::cout << "Actualmente hay " << this->cantidad << " productos en el changoo. La capacidad de la misma es " << this->capacidad << "." << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++) {
           // std::cout << "--------------Producto chango" << i << "--------------" << std::endl;
            this->productos[i].mostrarProductoChango();
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

            if (cantidad <= stock_producto) {
                // Si hay suficiente stock, cargar el producto en el chango
                std::cout << "Se compraron " << cantidad << " unidades del producto " << nombre << std::endl;
                this->cargarProductoEnGondola(nombre, precio_producto, oferta_producto, cantidad);
                gondola.obtenerProducto(posicion).actualizarStock(stock_producto - cantidad);
            } else {
                std::cout << "Del producto " << nombre << " solo hay " << stock_producto << " unidades disponibles." << std::endl;
                std::cout << "Se compraron " << stock_producto << " unidades del producto " << nombre << std::endl;
                this->cargarProductoEnGondola(nombre, precio_producto, oferta_producto, stock_producto);
                gondola.obtenerProducto(posicion).actualizarStock(0);

            }
        } else {
            std::cout << "El producto " << nombre << " no se encuentra en la góndola." << std::endl;
        }
    }

    archivo.close();


}
void Chango::realizarCompra() {
        double totalCompra = 0.0;

        std::cout << "VAMOS A CERRAR LA COMPRA AHORA" << std::endl;
        std::cout << "Producto\tPrecio\tCantidad\tOferta(S/N)\tPrecio final" << std::endl;

        for (unsigned int i = 0; i < this->cantidad; i++) {
            double precioProducto = this->productos[i].precioProducto();

            // Aplicar descuento del 10% si corresponde
            if (this->productos[i].ofertaProducto() == 1) {
                double descuento = precioProducto * 0.1; // Calcula el 10% del precio
                precioProducto -= descuento; // Aplica el descuento
            }

            // Calcular precio final del producto
            double precioFinal = precioProducto * this->productos[i].stockProducto();

            // Mostrar información del producto
            std::cout << this->productos[i].nombreProducto() << "\t"
                      << precioProducto << "\t"
                      << this->productos[i].stockProducto() << "\t"
                      << (this->productos[i].ofertaProducto() == 1 ? "S" : "N") << "\t"
                      << precioFinal << std::endl;

            // Agregar precio final del producto al total de la compra
            totalCompra += precioFinal;
        }

        // Mostrar total de la compra
        std::cout << "Total: $" << totalCompra << std::endl;
    }


