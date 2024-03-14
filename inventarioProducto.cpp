#include <iostream>
#include <malloc.h>
#include <locale.h>
using namespace std;

struct Producto {
    int id;
    char nombre[50];
    int cantidad;
    double precio;
    Producto * sig;
    };
    Producto *cab = NULL, *aux = NULL, *aux2 = NULL; 

int registrar() {
    aux = (struct Producto *)malloc(sizeof(struct Producto));
    aux->sig = NULL;
    cout << "Ingrese un codigo del producto: ";
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
    int valorTotal =0;

    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "Ingreso " << i << ":" << endl;
        cout << "Codigo: " << aux->id << endl;
        cout << "Producto: " << aux->nombre << endl;
        cout << "Cantidad: " << aux->cantidad << endl;
        cout << "Precio: " << aux ->precio<<endl;
       
        int valorProducto = aux->cantidad * aux->precio;
        cout << "Valor total del producto: " << valorProducto << endl;
        valorTotal += valorProducto;
        i++;
    }
        cout << "Valor total del inventario: " << valorTotal << endl;
       return 0;
    }

int buscarPorId(int id) {
    Producto* encontrado = NULL;
    for (aux = cab; aux != NULL; aux = aux->sig) {
        if (aux->id == id) {
            encontrado = aux;
            break;
        }
    }
    if (encontrado != NULL) {
        cout << "Producto encontrado:" << endl;
         cout << "codigo: " << encontrado->id << endl;
        cout << "producto: " << encontrado->nombre << endl;
        cout << "Cantidad: " << aux->cantidad << endl;
        cout << "Precio: " << aux ->precio<<endl;
    } else {
        cout << "Paciente no encontrado." << endl;
    }
    return 0;
}

int eliminarPorId(int id) {

    Producto* anterior = NULL;
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
    }
    else {
        cout << "Producto no encontrado. No se puede eliminar." << endl;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL,""); 
    int opcion = 0;
    do {
        // Menú de opciones <3
        cout << "***************************************  TIENDA EL TEMACH  *********************************************" << endl;
        cout << "1. Registrar Producto" << endl;
        cout << "2. Mostrar Inventario" << endl;
        cout << "3. Buscar Producto por ID" << endl;
        cout << "4. Eliminar Producto" << endl;
        cout << "5. Calcular Valor Total del Inventario" << endl;
        cout << "6. Calcular Promedio de Precios" << endl;
        cout << "7. Vender Productos" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese la opción deseada: ";
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
                buscarPorId(idBuscar);
                break;
            }
            case 4:
               int idEliminar;
               cout << "Ingrese el ID del producto a eliminar: ";
               cin >> idEliminar;
               eliminarPorId(idEliminar);
               break;
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                cout <<"Gracias por usar nuestro sistema <3"<<endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                break;
        }
    } while (opcion != 8);

    Producto* temp;
    while (cab != NULL) {
        temp = cab;
        cab = cab->sig;
        free(temp);
    }

    return 0;
}