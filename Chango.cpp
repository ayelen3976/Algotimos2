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
    unsigned int cantidad_chango;
    while(archivo >> nombre >> cantidad_chango) {
        buscar_comprar_producto(nombre, cantidad_chango, gondola);
        if(this->cantidad == capacidad){
            capacidad = capacidad*2;
            redimensionar_capacidad(capacidad);
        }
    }
    if(this->cantidad <= (capacidad/2)-1){
        capacidad =  (capacidad/2);
        redimensionar_capacidad(capacidad);
    }
    archivo.close();
}

void Chango::buscar_comprar_producto(const std::string& nombre, unsigned int cantidad_chango, Gondola& gondola) {
    int posicion = gondola.buscar_producto(nombre);
    if (posicion != -1) {
        double precio_producto = gondola.obtener_producto(posicion).precio_producto();
        unsigned int oferta_producto = gondola.obtener_producto(posicion).oferta_producto();
        unsigned int stock_producto = gondola.obtener_producto(posicion).stock_producto();
        if (cantidad_chango <= stock_producto) {
            this->productos[cantidad] = Producto(nombre, precio_producto, oferta_producto, cantidad_chango);
            Producto producto_actualizado(nombre, precio_producto, oferta_producto, (stock_producto - cantidad_chango));
            gondola.actualizar_productos_gondola(&producto_actualizado);
            this->cantidad++;
        } else {
            this->productos[cantidad] = Producto(nombre, precio_producto, oferta_producto, stock_producto);
            Producto producto1(nombre, precio_producto, oferta_producto, 0);
            gondola.eliminar_producto(nombre);
            std::cout << "SOBREAVISO : El producto " << nombre << " solo nos quedan: " << stock_producto
                      << ", igualmente se lo agregaremos :)" << std::endl;
            this->cantidad++;
        }
    } else {
        std::cout << " AVISO : El producto " << nombre << " de su lista de compras no se encuentra en la góndola." << std::endl;
    }
}


void Chango::redimensionar_capacidad(unsigned int factor){
    Producto* nuevosProductos = new Producto[factor];
    for (int i = 0; i < cantidad; ++i) {
        nuevosProductos[i] = this->productos[i];
    }
    delete [] this->productos;
    this -> productos = nuevosProductos;
}

void Chango::mostrar_productos_del_chango() {
    if (this->cantidad == 0) {
        std::cout << "No hay productos en el chango." << std::endl;
    } else {
        std::cout <<"-----------------------------------------------------------" << std::endl;
        std::cout <<"------------------ SU LISTA DE COMPRAS --------------------" << std::endl;
        std::cout <<"-----------------------------------------------------------" << std::endl;

        for (unsigned int i = 0; i < this->cantidad; i++) {
            this->productos[i].mostrar_producto_chango();
        }
        std::cout <<"-----------------------------------------------------------" << std::endl;
        std::cout <<"-----------------------------------------------------------" << std::endl;
        std::cout <<"-----------------------------------------------------------" << std::endl;

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


