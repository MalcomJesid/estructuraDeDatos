/*
Realizar un programa que permita registrar pacientes, se debe captura el nombre del paciente y el numero de documento.

1. Mostrar los pacientes de tal manera que se muestre 1, 2, 3, etc según el orden de registro (Colas).

2. El proyecto ser subido por cada miembro del grupo en GitHub. 
*/

#include <iostream>
#include <malloc.h>
#include <locale.h>
using namespace std;

struct paciente {  
    char nombre[40]; 
    int id; 
    paciente* sig; 
};

paciente *cab = NULL, *aux = NULL, *aux2 = NULL; 

int registrar() {
    aux = (struct paciente *)malloc(sizeof(struct paciente));
    aux->sig = NULL;
    cout << "Ingrese un nombre: ";
    cin >> aux->nombre;
    cout << "Ingrese un número: ";
    cin >> aux->id;

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
    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "Paciente " << i << ":" << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "ID: " << aux->id << endl;
        i++;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL,""); 
    int opcion = 0;
    do {
        // Menú de opciones
        cout << "Menu:" << endl;
        cout << "1. Registrar un Paciente" << endl;
        cout << "2. Mostrar todos los pacientes" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion : ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                cout <<"Gracias por Usar nuestro sistemas <3"<<endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opcion valida." << endl;
                break;
        }
    } while (opcion != 3);

    paciente* temp;
    while (cab != NULL) {
        temp = cab;
        cab = cab->sig;
        free(temp);
    }

    return 0;
}
