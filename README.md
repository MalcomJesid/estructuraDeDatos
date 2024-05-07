/*Realizar un
sistema que permita el registro de estudiantes con el uso de árboles binarios,
el sistema debe permitir realizar la indexación (orden de inserción) a través
del código del estudiante (cada estudiante ya tiene un código asignado por
tanto se le debe preguntar) y también por la fecha de nacimiento.

El sistema debe
permitir recorrer la solución planteada con el uso de los métodos de Inorden,
Preorden y Postorden.


Puede darse el
caso de que dos estudiantes proporcionen la misma fecha de nacimiento en cuyo
caso deberá ubicarse al nuevo nodo a la derecha de su igual


El sistema debe
permitir eliminar el registro del estudiante. 


Del alumno se
deben solicitar: código, nombres, apellidos y fecha de nacimiento (año, mes y día)*/



//MALCOM JESID RIASCOS FIGUEROA COD.12000373
//FAIBER PACHECO SILVA
#include <iostream>
using namespace std;


//Primer Arbol por Fecha del estudiante.
struct Student {
    int id;
    char nombre[40];
    char apellido[40];
    int anio;
    int mes;
    int dia;
    Student *iza, *der;
};
 Student*raiz= NULL,*aux, *aux2;
 
int posicionar() {
    while (true) {
        if (aux->id < aux2->id) {
            if (aux2->iza != NULL) {
                aux2 = aux2->iza;
            } else {
                aux2->iza = aux;
                break;
            }
        } else if (aux->id > aux2->id) {
            if (aux2->der != NULL) {
                aux2 = aux2->der;
            } else {
                aux2->der = aux;
                break;
            }
        } 
    }
    return 0;
}

int RegistrarEstudiante() {
    int i = 0;
    cout << "Bienvenido al área de registro" << endl;
    cout << "\n";

    do {
        aux = (struct Student *)malloc(sizeof(struct Student));
        cout << "Ingresa el nombre del estudiante: " << endl;
        cin >> aux->nombre;
        cout << "\n";

        cout << "Ingresa el apellido del estudiante: " << endl;
        cin >> aux->apellido;
        cout << "\n";

        cout << "Fecha de nacimiento del estudiante (ingresa solo números):" << endl;
        system("pause");
        cout << "\n";

        cout << "Día:" << endl;
        cin >> aux->dia;
        cout << "\n";
        cout << "Mes:" << endl;
        cin >> aux->mes;
        cout << "\n";
        cout << "Año:" << endl;
        cin >> aux->anio;
        cout << "\n";

        cout << "Ingresa el código del estudiante:" << endl;
        cin >> aux->id;
        cout << "\n";

        aux->iza = aux->der = NULL;

        if (raiz == NULL) {
            raiz = aux;
            aux = NULL;
            free(aux);
        } else { 
            aux2 = raiz;
            posicionar();
        }
        cout << "\n";
        cout << "Estudiante Registrado." << endl;
        system("pause");
        cout << "¿Desea registrar otro estudiante? (1.SI/2.NO)";
        cin >> i;
        cout << "\n";
    } while (i != 2);
    return 0;
}

int eliminarEstudiante(int id) {
    Student *padre1 = NULL;
    Student *aux = raiz;

   
    while (aux != NULL && aux->id != id) {
        padre1 = aux;
        if (id < aux->id) {
            aux = aux->iza;
        } else {
            aux = aux->der;
        }
    }

    
    if (aux == NULL) {
        cout << "No se encontró ningún estudiante con el ID proporcionado." << endl;
        return 0;
    }


    if (aux->iza == NULL && aux->der == NULL) {
        if (padre1 == NULL) {
            raiz = NULL;
        } else if (padre1->iza == aux) {
            padre1->iza = NULL;
        } else {
            padre1->der = NULL;
        }
        delete aux;
    }
    
    else if (aux->iza == NULL || aux->der == NULL) {
        Student *temp;
        if (aux->iza != NULL) {
            temp = aux->iza;
        } else {
            temp = aux->der;
        }
        if (padre1 == NULL) {
            raiz = temp;
        } else if (padre1->iza == aux) {
            padre1->iza = temp;
        } else {
            padre1->der = temp;
        }
        delete aux;
    }
   
    else {
        Student *sucesor = aux->der;
        while (sucesor->iza != NULL) {
            sucesor = sucesor->iza;
        }
        int tempID = sucesor->id;
        eliminarEstudiante(sucesor->id);
        aux->id = tempID;
    }

    cout << "Estudiante eliminado exitosamente." << endl;
    return 0;
}

int preorden (Student*recursive) {
 cout << "ID: " << aux->id << ", Nombre: " << aux->nombre << " " << aux->apellido 
             << ", Fecha de nacimiento: " << aux->dia << "/" << aux->mes << "/" << aux->anio << endl;
    cout<<"\n";
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\n";
if(recursive -> iza != NULL)
preorden (recursive->iza);
if(recursive -> der != NULL)
preorden (recursive -> der);
return 0;}

int inorden(Student*recursive) {
if (recursive-> iza != NULL) 
inorden(aux->iza); 
        cout << "ID: " << aux->id << ", Nombre: " << aux->nombre << " " << aux->apellido 
        << ", Fecha de nacimiento: " << aux->dia << "/" << aux->mes << "/" << aux->anio << endl;
        cout<<"\n";
        cout <<"***********************************************************************************"<< endl;
        cout<<"\n";
if(recursive->der!=NULL){ inorden(recursive->der);}
return 0;
}

int postorden(Student*recursive) {
if (recursive-> iza != NULL)
postorden(aux->iza); 
postorden(aux->der); 
cout << "ID: " << aux->id << ", Nombre: " << aux->nombre << " " << aux->apellido 
             << ", Fecha de nacimiento: " << aux->dia << "/" << aux->mes << "/" << aux->anio << endl;
        cout <<"***********************************************************************************"<< endl;
        cout<<"\n"<< endl; 
        cout<<"\n";
return 0;
}

int recorrer(){
	  int iu = 0;
    	aux = raiz;
       if(aux!=NULL){
            cout << "***************************************  Institucion Educativa *********************************************" << endl;
            cout << "************************************          El Macho           ****************************************" << endl;
            cout<<"***********************************          Recorrer arbol           **************************************"<<endl;
		  cout<<"\n";
		  do{
			  cout<<"Elige el recorrido:"<<endl;
		      cout<<"1. InOrden"<<endl;
	          cout<<"2. PreOrden"<<endl;
	          cout<<"3. PostOrden"<<endl;
	          cout<<"4. salir"<<endl;
		      cin>>iu;
	          switch (iu)
	           {
	             case 1: 
					aux = raiz;
					inorden(aux);
					system("pause"); 
					break;
	             case 2: 
					aux = raiz;
					preorden(aux);
					system("pause");
					break;
	             case 3: 
	            	aux = raiz;
					postorden(aux);
					system("pause");
	            	break;
	             case 4: cout<<"Adios"; break;
	             default:cout<<"Opcion Invalida."; break;
	            }
		    }while(iu!=4);
        }else{
         cout<<"Vacio..."<<endl;
         cout<<"No se ha registrado estudiantes"<<endl;
         system("pause");
	    }
	 return 0;
    }

//Segundo Arbol por Fecha del estudiante.
struct Student2 {
    int id2;
    char nombre2[40];
    char apellido2[40];
    int anio2;
    int mes2;
    int dia2;
    Student2 *iza2, *der2;
};
 Student2*raizB= NULL,*auxB, *aux2B;

int posicionarB(){
    while (true) {
            if (aux->anio < aux2->anio || 
                   (aux->anio == aux2->anio && aux->mes < aux2->mes) ||
                   (aux->anio == aux2->anio && aux->mes == aux2->mes && aux->dia < aux2->dia)) {
            if (aux2->iza != NULL) {
                aux2 = aux2->iza;
            } else {
                aux2->iza = aux;
                break;
            }
        }     else {
            if (aux2->der != NULL) {
                aux2 = aux2->der;
            } else {
                aux2->der = aux;
                break;
            }
        }  
}return 0;}

int RegistrarEstudiante2() {
    int i2 = 0;
    cout << "Bienvenido al área de registro" << endl;
    cout << "\n";

    do {
        auxB = (struct Student2 *)malloc(sizeof(struct Student2));
        cout << "Ingresa el nombre del estudiante: " << endl;
        cin >> auxB->nombre2;
        cout << "\n";

        cout << "Ingresa el apellido del estudiante: " << endl;
        cin >> auxB->apellido2;
        cout << "\n";

        cout << "Fecha de nacimiento del estudiante (ingresa solo números):" << endl;
        system("pause");
        cout << "\n";

        cout << "Día:" << endl;
        cin >> auxB->dia2;
        cout << "\n";
        cout << "Mes:" << endl;
        cin >> auxB->mes2;
        cout << "\n";
        cout << "Año:" << endl;
        cin >> auxB->anio2;
        cout << "\n";

        cout << "Ingresa el código del estudiante:" << endl;
        cin >> auxB->id2;
        cout << "\n";

        auxB->iza2 = auxB->der2 = NULL;

        if (raizB == NULL) {
            raizB = auxB;
            auxB = NULL;
            free(aux);
        } else { 
            aux2B = raizB;
            posicionarB();
        }
        cout << "\n";
        cout << "Estudiante Registrado." << endl;
        system("pause");
        cout << "¿Desea registrar otro estudiante? (1.SI/2.NO)";
        cin >> i2;
        cout << "\n";
    } while (i2 != 2);
    return 0;
}

int preordenF (Student2*recursive) {
 cout << "ID: " << auxB->id2 << ", Nombre: " << auxB->nombre2 << " " << auxB->apellido2 
             << ", Fecha de nacimiento: " << auxB->dia2 << "/" << auxB->mes2 << "/" << auxB->anio2 << endl;
    cout<<"\n";
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\n";
if(recursive -> iza2 != NULL)
preordenF (recursive->iza2);
if(recursive -> der2 != NULL)
preordenF (recursive -> der2);
return 0;}

int inordenF(Student2*recursive) {
if (recursive-> iza2 != NULL) 
inordenF(auxB->iza2); 
        cout << "ID: " << auxB->id2 << ", Nombre: " << auxB->nombre2 << " " << auxB->apellido2 
        << ", Fecha de nacimiento: " << auxB->dia2 << "/" << auxB->mes2 << "/" << auxB->anio2 << endl;
        cout<<"\n";
        cout <<"***********************************************************************************"<< endl;
        cout<<"\n";
if(recursive->der2!=NULL){ inordenF(recursive->der2);}
return 0;
}

int postordenF(Student2*recursive) {
if (recursive-> iza2 != NULL)
postordenF(auxB->iza2); 
postordenF(auxB->der2); 
cout << "ID: " << auxB->id2 << ", Nombre: " << auxB->nombre2 << " " << auxB->apellido2 
             << ", Fecha de nacimiento: " << auxB->dia2 << "/" << auxB->mes2 << "/" << auxB->anio2 << endl;
        cout <<"***********************************************************************************"<< endl;
        cout<<"\n"<< endl; 
        cout<<"\n";
return 0;
}

int recorrer2(){
	  int iu2 = 0;
    	auxB = raizB;
       if(auxB!=NULL){
            cout << "***************************************  Institucion Educativa *********************************************" << endl;
            cout << "************************************          El Macho           ****************************************" << endl;
            cout<<"***********************************          Recorrer arbol           **************************************"<<endl;
		  cout<<"\n";
		  do{
			  cout<<"Elige el recorrido:"<<endl;
		      cout<<"1. InOrden"<<endl;
	          cout<<"2. PreOrden"<<endl;
	          cout<<"3. PostOrden"<<endl;
	          cout<<"4. salir"<<endl;
		      cin>>iu2;
	          switch (iu2)
	           {
	             case 1: 
					auxB = raizB;
					inordenF(auxB);
					system("pause"); 
					break;
	             case 2: 
					auxB = raizB;
					preordenF(auxB);
					system("pause");
					break;
	             case 3: 
	            	auxB = raizB;
					postordenF(auxB);
					system("pause");
	            	break;
	             case 4: cout<<"Adios"; break;
	             default:cout<<"Opcion Invalida."; break;
	            }
		    }while(iu2!=4);
        }else{
         cout<<"Vacio..."<<endl;
         cout<<"No se ha registrado estudiantes"<<endl;
         system("pause");
	    }
	 return 0;
    }

int eliminarEstudiante2(int id2) {
    Student2 *padre = NULL;
    Student2 *aux2 = raizB;

    
    while (aux2 != NULL && aux2->id2 != id2) {
        padre = aux2;
        if (id2 < aux2->id2) {
            aux2 = aux2->iza2;
        } else {
            aux2 = aux2->der2;
        }
    }


    if (aux2 == NULL) {
        cout << "No se encontró ningún estudiante con el ID proporcionado." << endl;
        return 0;
    }

    
    if (aux2->iza2 == NULL && aux2->der2 == NULL) {
        if (padre == NULL) {
            raizB = NULL;
        } else if (padre->iza2 == aux2) {
            padre->iza2 = NULL;
        } else {
            padre->der2 = NULL;
        }
        delete aux;
    }
    
    else if (aux2->iza2 == NULL || aux2->der2 == NULL) {
        Student2 *temp;
        if (aux2->iza2 != NULL) {
            temp = aux2->iza2;
        } else {
            temp = aux2->der2;
        }
        if (padre == NULL) {
            raizB = temp;
        } else if (padre->iza2 == aux2) {
            padre->iza2 = temp;
        } else {
            padre->der2 = temp;
        }
        delete aux2;
    }

    else {
        Student2 *sucesor = aux2->der2;
        while (sucesor->iza2 != NULL) {
            sucesor = sucesor->iza2;
        }
        int tempID = sucesor->id2;
        eliminarEstudiante2(sucesor->id2);
        aux2->id2 = tempID;
    }

    cout << "Estudiante eliminado exitosamente." << endl;
    return 0;
}

int main() {
    setlocale(LC_ALL, "");
    int opcion = 0;
    do {
        // Menú de opciones <3
        cout << "***************************************  Institucion Educativa *********************************************" << endl;
        cout << "*************************************          El Macho        *******************************************" << endl;
        cout << "1. Registrar Estudiante" << endl; //Completado.
        cout << "2. Recorrido por ID" << endl;    //Completado.
         cout <<"3. Eliminar Estudiante " << endl;    //Completado.
        cout << "3. Registro Estudiante Fecha" << endl;//Completado.
        cout << "4. Recorrido por Fecha" << endl;//Completado.
        cout << "5. Eliminar Estudiante Arbol dos" << endl;
        cout << "6. Salir" << endl; 
        cout << "Ingrese la opción deseada: ";
        cin >> opcion; 
        switch (opcion) {
            case 1: RegistrarEstudiante(); break;
            case 2: recorrer(); break;
            case 3:  int id;
                cout << "Ingrese el ID del estudiante que desea eliminar: ";
                cin >> id;
                eliminarEstudiante(id); break;
            case 4: RegistrarEstudiante2(); break;
            case 5: recorrer2(); break;     
            case 6:  int id2;
                cout << "Ingrese el ID del estudiante que desea eliminar: ";
                cin >> id2;
                        eliminarEstudiante(id2); break;      
            case 7:cout << "Gracias por usar nuestro sistema <3" << endl; break;
            default: cout << "Opcion no válida. Por favor, elija una opcion valida." << endl; break;
        
 } }while (opcion != 7);
 return 0;
 }


//MALCOM JESID RIASCOS FIGUEROA COD.12000373
//Faiber Pacheco Silva
