#include <iostream>
#include "Gondola.h"
#include "Chango.h"
int main() {
Gondola miGondola;

miGondola.agregarProductos("productos.txt");
miGondola.mostrarProductos();
Chango miChango;
miChango.buscarProductoEnGondola(miGondola, "compra.txt");
miChango.mostrarProductosDelCHango();
return 0;
}
