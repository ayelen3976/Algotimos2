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

void Chango::abrir_archivo_compra(Gondola &gondola, std::string archivo_productos) {
    std::ifstream archivo(archivo_productos);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo " << archivo_productos << std::endl;
        return;
    }
    std::string nombre;
    unsigned int cantidad;
    while (archivo >> nombre >> cantidad) {
        buscar_comprar_producto(nombre, cantidad, gondola);
    }
    if(cantidad <= (capacidad/2)-1){
        capacidad =  (capacidad/2);
        redimensionar_capacidad(capacidad);
    }
    archivo.close();
}
void Chango::buscar_comprar_producto(const std::string& nombre, unsigned int cantidad, Gondola& gondola) {
    int posicion = gondola.buscar_producto(nombre);
    if (posicion != -1) {
        double precio_producto = gondola.obtener_producto(posicion).precio_producto();
        unsigned int oferta_producto = gondola.obtener_producto(posicion).oferta_producto();
        unsigned int stock_producto = gondola.obtener_producto(posicion).stock_producto();

        if (cantidad <= stock_producto) {
            comprar_producto(nombre, precio_producto, oferta_producto, cantidad);
            Producto producto_actualizado(nombre, precio_producto, oferta_producto, (stock_producto-cantidad));
            gondola.actualizar_productos_gondola(&producto_actualizado);
        } else {
            comprar_producto(nombre, precio_producto, oferta_producto, stock_producto);
            Producto producto1(nombre, precio_producto, oferta_producto, 0);
            gondola.eliminar_producto(nombre);
            std::cout << "SOBREAVISO : El producto " << nombre <<" solo nos quedan: " << stock_producto<< " ,igualmente se lo agregaremos :)"<<std::endl;
        }
    } else {
        std::cout << " AVISO : El producto " << nombre << " de su lista de compras no se encuentra en la góndola." << std::endl;
    }
}

void Chango::comprar_producto(const std::string& nombre, double precio, unsigned int oferta, unsigned int cantidad) {
    cargar_producto_en_chango(nombre, precio, oferta, cantidad);
}


void Chango::cargar_producto_en_chango(std::string nombre, double precio, unsigned int enOferta, unsigned int stock) {
    if (cantidad == capacidad) {
        redimensionar_capacidad(2);
    }
    this->productos[cantidad] = Producto(nombre, precio, enOferta, stock);
    cantidad++;
}


void Chango::redimensionar_capacidad(unsigned int factor) {
    unsigned int nuevaCapacidad = capacidad * factor;

    if (cantidad <= (capacidad / 2) - 1) {
        nuevaCapacidad = capacidad / 2;
    }
    Producto *nuevosProductos = new Producto[nuevaCapacidad];

    for (unsigned int i = 0; i < cantidad; ++i) {
        nuevosProductos[i] = productos[i];
    }
    delete[] productos;
    productos = nuevosProductos;
    capacidad = nuevaCapacidad;
}




void Chango::mostrar_productos_del_chango() {
    if (this->cantidad == 0) {
        std::cout << "No hay productos en el chango."<< "." << std::endl;
    } else {
        for (unsigned int i = 0; i < this->cantidad; i++) {
            this->productos[i].mostrar_producto_chango();
        }
    }
}

void Chango::realizar_compra() {
        double totalCompra = 0.0;
    std::cout << "///////////////////~VAMOS A CERRAR LA COMPRA~//////////////////" << std::endl;

    std::cout << "Producto\tPrecioU\t\tCantidad\tOferta(S/N)\t\tPrecioI" << std::endl;
        for (unsigned int i = 0; i < this->cantidad; i++) {
            double precioProducto = this->productos[i].precio_producto();

            if (this->productos[i].oferta_producto() == 1) {
                double descuento = precioProducto * 0.1;
                precioProducto -= descuento;
            }
            double precioFinal = precioProducto * this->productos[i].stock_producto();
            std::cout << this->productos[i].nombre_producto() <<"\t\t"
                      << this->productos[i].precio_producto()<<"\t\t\t"
                      << this->productos[i].stock_producto() <<"\t\t\t"
                      << (this->productos[i].oferta_producto() == 1 ? "S" : "N") << "\t\t\t\t"
                      << precioFinal << std::endl;

            totalCompra += precioFinal;
        }
        std::cout << "Total: $" << totalCompra << std::endl;
    std::cout << "//////////////////////////////////////////////////////////////" << std::endl;

    }


