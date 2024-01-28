#include <iostream>
#include "Gondola.h"
int main() {
Gondola miGondola;
miGondola.mostrarProductos();

miGondola.agregarProductos("productos.txt");
miGondola.mostrarProductos();
return 0;
}
