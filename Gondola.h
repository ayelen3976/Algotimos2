
#ifndef FERNANDEZ_109378_TP2_GONDOLA_H
#define FERNANDEZ_109378_TP2_GONDOLA_H
#include "Producto.h"

class Gondola {
private:
    Producto *productos;
    unsigned int capacidad;
    unsigned int cantidad;

public:
    // Precondición: Ninguna.
    // Postcondición: Crea un objeto Gondola vacío.
    Gondola();

    // Precondición: Ninguna.
    // Postcondición: Libera los recursos asignados al objeto Gondola.
    ~Gondola();

    // Precondición: El objeto Gondola debe estar correctamente inicializado.
    // Postcondición: Muestra por pantalla los productos disponibles en la góndola.
    void mostrar_productos();

    // Precondición: El archivo especificado debe existir y contener los productos en el formato adecuado.
    // Postcondición: Agrega los productos del archivo a la góndola.
    void agregar_productos(std::string archivo_productos);

    // Precondición: El objeto Gondola debe estar correctamente inicializado y el factor debe ser mayor que 0.
    // Postcondición: Ajusta la capacidad de la góndola según el factor especificado.
    void redimensionar_capacidad(unsigned int factor);

    // Precondición: El objeto Gondola debe estar correctamente inicializado.
    // Postcondición: Devuelve la posición del producto en la góndola si se encuentra, -1 en caso contrario.
    int buscar_producto(std::string nombre);

    // Precondición: El objeto Gondola debe estar correctamente inicializado y la posición debe ser válida.
    // Postcondición: Devuelve el producto en la posición especificada de la góndola.
    Producto obtener_producto(unsigned int posicion);

    // Precondición: El objeto Gondola debe estar correctamente inicializado y el producto debe existir en la góndola.
    // Postcondición: Actualiza el producto en la góndola con la información proporcionada.
    void actualizar_productos_gondola(Producto* producto);

    // Precondición: El objeto Gondola debe estar correctamente inicializado y el archivo debe ser válido.
    // Postcondición: Guarda el stock actualizado de los productos en el archivo especificado.
    void guardar_stock_actualizado(std::string archivo_productos);

    // Precondición: El objeto Gondola debe estar correctamente inicializado y el producto debe existir en la góndola.
    // Postcondición: Elimina el producto de la góndola con el nombre especificado.
    void eliminar_producto(std::string nombre);
};

#endif //FERNANDEZ_109378_TP2_GONDOLA_H
