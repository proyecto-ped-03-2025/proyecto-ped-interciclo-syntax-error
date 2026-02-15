#include <iostream>
#include <stdlib.h>
#include <cstdlib> //random
#include <ctime>   //time()
#include <string>  //nombre de los jugadores

using namespace std;

struct Nodo
{
    string nombre;
    int carnet, numero;

    Nodo *siguiente;
    Nodo *reversa;

} *primero, *ultimo;

void insertarNombres()
{

    Nodo *nuevo = new Nodo();
    cout << "Ingrese el nombre: ";
    cin>> nuevo->nombre;

    cout << "Ingrese el carnet del usuario:";
    cin >> nuevo->carnet;

    if (primero == NULL)
    { // si primer nodo esta vacio
        primero = nuevo;
        primero->siguiente = NULL;
        primero->reversa = NULL;
        ultimo = primero;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->reversa = ultimo;
        ultimo = nuevo;
    }
    cout << "\n Informacion guardada \n" << endl;
};

oid menu()
{
    int opcion;

    do
    {
        cout << "======== MENU ========" << endl;
        cout << "Escoga una opcion " << endl;
        cout << "1.Agregar Jugadores" << endl;
        cout << "2.Jugar" << endl;
        cout << "3.Mostrar Jugadores" << endl;
        cout << "4.Puntaje" << endl;
        cout << "5.Ayuda" << endl;
        cout << "6.opciones de juego" << endl;
        cout << "7.Integrantes del grupo" << endl;
        cout << "8.Salir" << endl;
        cin >> opcion;
        cout<<"\n"<<endl;
    }while (opcion != 8);
};
