#ifndef FERNANDEZ_109378_TP2_PRODUCTO_H
#define FERNANDEZ_109378_TP2_PRODUCTO_H
#include <iostream>
#include <string>

class Producto {
private:
    std::string nombre;
    double precio;
    unsigned int descuento;
    unsigned int stock;

public:
    //Precondición: Ninguna.
    //Postcondición: Crea un objeto Producto con valores predeterminados para todos sus atributos.
    Producto();

    // Precondición: Ninguna.
    // Postcondición: Crea un objeto Producto con los atributos proporcionados.
    Producto(std::string nombre, double precio, unsigned int enOferta, unsigned int stock);

    // Precondición: Ninguna.
    // Postcondición: Libera los recursos asignados al objeto Producto.
    ~Producto();

    // Precondición: El objeto Producto debe estar correctamente inicializado.
    // Postcondición: Muestra por pantalla los atributos del producto que estan en la góndola.
    void mostrar_producto_gondola();

    // Precondición: El objeto Producto debe estar correctamente inicializado.
    // Postcondición: Muestra por pantalla los atributos del producto que estan dentro del chango.
    void mostrar_producto_chango();

    // Precondición: El objeto Producto debe estar correctamente inicializado.
    // Postcondición: Devuelve el nombre del producto.
    std::string nombre_producto();

    // Precondición: El objeto Producto debe estar correctamente inicializado.
    // Postcondición: Devuelve el precio del producto.
    double precio_producto();

    // Precondición: El objeto Producto debe estar correctamente inicializado.
    // Postcondición: Devuelve el estado de oferta del producto.
    int oferta_producto();

    // Precondición: El objeto Producto debe estar correctamente inicializado.
    // Postcondición: Devuelve el stock disponible del producto.
    int stock_producto();

};


#endif //FERNANDEZ_109378_TP2_PRODUCTO_H
