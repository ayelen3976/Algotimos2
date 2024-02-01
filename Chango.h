
#ifndef FERNANDEZ_109378_TP2_CHANGO_H
#define FERNANDEZ_109378_TP2_CHANGO_H
#include "Producto.h"
#include "Gondola.h"
class Chango {
private:
    Producto *productos;
    unsigned int capacidad;
    unsigned int cantidad;
public:
    // Precondición: Ninguna.
    // Postcondición: Crea un objeto Chango vacío.
    Chango();

    // Precondición: Ninguna.
    // Postcondición: Libera los recursos asignados al objeto Chango.
    ~Chango();

    // Precondición: El objeto Chango y la góndola deben estar correctamente inicializados, y el archivo de compra debe existir y contener los productos en el formato adecuado.
    // Postcondición: Realiza la compra de los productos encontrados en la góndola según la lista de compra especificada en el archivo.
    void abrir_archivo_compra(Gondola& gondola, std::string archivo_compra);

    // Precondición: El objeto Chango y la góndola deben estar correctamente inicializados, y el producto debe estar disponible en la góndola.
    // Postcondición: Realiza la compra del producto especificado en la góndola con la cantidad especificada.
    void buscar_comprar_producto(const std::string& nombre, unsigned int cantidad, Gondola& gondola);

    // Precondición: El objeto Chango debe estar correctamente inicializado y el factor debe ser mayor que 0.
    // Postcondición: Ajusta la capacidad del chango según el factor especificado.
    void redimensionar_capacidad(unsigned int factor);

    // Precondición: El objeto Chango debe estar correctamente inicializado.
    // Postcondición: Muestra por pantalla los productos que se encuentran en el chango.
    void mostrar_productos_del_chango();

    // Precondición: El objeto Chango debe estar correctamente inicializado.
    // Postcondición: Finaliza la compra de los productos en el chango, mostrando un resumen de la compra realizada.
    void realizar_compra();

};


#endif //FERNANDEZ_109378_TP2_CHANGO_H
