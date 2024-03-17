#include <iostream>
#include <malloc.h>
#include <locale.h>
using namespace std;

struct Producto {
    int id;
    char nombre[50];
    int cantidad;
    double precio;
    Producto *sig;
};
Producto *cab = NULL, *aux = NULL, *aux2 = NULL;

    int gananciasTotales = 0;
    int cantidadVendidaTotal = 0;

int registrar() {
    aux = (struct Producto *)malloc(sizeof(struct Producto));
    aux->sig = NULL;
    cout << "Ingrese el codigo del producto: ";
    cin >> aux->id;
    cout << "Ingrese el nombre del producto: ";
    cin >> aux->nombre;
    cout << "Ingrese la cantidad : ";
    cin >> aux->cantidad;
    cout << "Ingrese la precio por unidad : ";
    cin >> aux->precio;

    if (cab == NULL)
        cab = aux;
    else {
        aux2 = cab;
        while (aux2->sig != NULL)
            aux2 = aux2->sig;
        aux2->sig = aux;
    }
    return 0;
}

int mostrar() {
    int i = 1;
    int valorTotal = 0;

    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "Ingreso " << i << ":" << endl;
        cout << "Codigo: " << aux->id << endl;
        cout << "Producto: " << aux->nombre << endl;
        cout << "Cantidad: " << aux->cantidad << endl;
        cout << "Precio: " << aux->precio << endl;

        int valorProducto = aux->cantidad * aux->precio;
        cout << "Valor total del producto: " << valorProducto << endl;
        valorTotal += valorProducto;
        i++;
    }
    cout << "Valor total del inventario: " << valorTotal << endl;
    return 0;
}

Producto *buscarPorId(int id) {
    Producto *encontrado = NULL;
    for (aux = cab; aux != NULL; aux = aux->sig) {
        if (aux->id == id) {
            encontrado = aux;
            break;
        }
    }
    return encontrado;
}

int eliminarPorId(int id) {
    Producto *anterior = NULL;
    aux = cab;

    while (aux != NULL && aux->id != id) {
        anterior = aux;
        aux = aux->sig;
    }

    if (aux != NULL) {
        if (anterior != NULL)
            anterior->sig = aux->sig;
        else
            cab = aux->sig;

        free(aux);
        cout << "Producto eliminado correctamente." << endl;
    } else {
        cout << "Producto no encontrado. No se puede eliminar." << endl;
    }
    return 0;
}

int venderProductos() {
    int idProducto, cantidad;
    char deseaContinuar;

    do {
        cout << "Ingrese el ID del producto a vender: ";
        cin >> idProducto;

        Producto* producto = buscarPorId(idProducto);

        if (producto != NULL) {
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad;

            if (producto->cantidad >= cantidad && cantidad > 0) {
                producto->cantidad -= cantidad;
                cout << "Venta de " << cantidad << " " << producto->nombre << "(s) realizada correctamente." << endl;
                gananciasTotales += (cantidad * producto->precio);
                cantidadVendidaTotal += cantidad;
            } else if (cantidad <= 0) {
                cout << "La cantidad ingresada no es válida." << endl;
            } else {
                cout << "No hay suficiente cantidad en el inventario para completar la venta de " << cantidad << " " << producto->nombre << "(s)." << endl;
            }
        } else {
            cout << "Producto no encontrado." << endl;
        }

        cout << "¿Desea comprar otro producto? (s/n): ";
        cin >> deseaContinuar;
    } while (deseaContinuar == 's' || deseaContinuar == 'S');

    return 0;
}

void mostrarVentasYGanancias() {
    cout << "Total de productos vendidos: " << cantidadVendidaTotal << endl;
    cout << "Ganancias totales: $" << gananciasTotales << endl;
}

int devolverProducto(int id, int cantidad) {
    Producto* producto = buscarPorId(id);
    if (producto != NULL) {
        producto->cantidad += cantidad;
        cout << "Devolución realizada correctamente." << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
    return 0;
}


int main() {
    setlocale(LC_ALL, "");
    int opcion = 0;
    do {
        // Menú de opciones <3
        cout << "***************************************  TIENDA EL TEMACH  *********************************************" << endl;
        cout << "1. Registrar Producto" << endl;
        cout << "2. Mostrar Inventario" << endl;
        cout << "3. Buscar Producto por ID" << endl;
        cout << "4. Eliminar Producto" << endl;
        cout << "5. Vender Productos" << endl;
        cout << "6. Devolucion de producto" << endl;
        cout << "7. Mostrar ventas y ganancias" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3: {
                int idBuscar;
                cout << "Ingrese el ID del producto a buscar: ";
                cin >> idBuscar;
                Producto *productoEncontrado = buscarPorId(idBuscar);
                if (productoEncontrado != NULL) {
                    cout << "Producto encontrado:" << endl;
                    cout << "codigo: " << productoEncontrado->id << endl;
                    cout << "producto: " << productoEncontrado->nombre << endl;
                    cout << "Cantidad: " << productoEncontrado->cantidad << endl;
                    cout << "Precio: " << productoEncontrado->precio << endl;
                } else {
                    cout << "Producto no encontrado." << endl;
                }
                break;
            }
            case 4: {
                int idEliminar;
                cout << "Ingrese el ID del producto a eliminar: ";
                cin >> idEliminar;
                eliminarPorId(idEliminar);
                break;
            }
            case 5:
                venderProductos();
                break;
            case 6:
                 int idDevolucion, cantidadDevolucion;
                 cout << "Ingrese el ID del producto a devolver: ";
                 cin >> idDevolucion;
                 cout << "Ingrese la cantidad a devolver: ";
                 cin >> cantidadDevolucion;
                 devolverProducto(idDevolucion, cantidadDevolucion);

                break;
            case 7:
                 mostrarVentasYGanancias();
                break;
            case 8:
                cout << "Gracias por usar nuestro sistema <3" << endl;
                break;
                
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                break;
        }
    } while (opcion != 8);

    Producto *temp;
    while (cab != NULL) {
        temp = cab;
        cab = cab->sig;
        free(temp);
    }

    return 0;
}
