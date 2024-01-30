#include <iostream>
#include "Gondola.h"
#include "Chango.h"


int main() {
Gondola mi_gondola;

mi_gondola.agregar_productos("productos.txt");
mi_gondola.mostrar_productos();

Chango mi_chango;

mi_chango.abrir_archivo_compra(mi_gondola, "compra.txt");
mi_chango.realizar_compra();
//mi_gondola.guardar_stock_actualizado("productos.txt");

return 0;
}
