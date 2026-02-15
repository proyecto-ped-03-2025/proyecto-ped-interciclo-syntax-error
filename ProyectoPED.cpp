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

struct Puntaje
{
    string nombreJugador;
    int puntos;
    Puntaje *siguiente;

} *listaPuntajes;
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
void mostrarJugadores() // muestra los jugadores registrados para jugar.
{
    Nodo *actual = primero;

    if (actual == NULL) // verifica que la lista no este vacia
    {
        cout << "No hay jugadores registrados." << endl;
        return;
    }

    cout << "======| JUGADORES REGISTRADOS|====== " << endl;
    cout << "\n"<< endl;

    while (actual != NULL) // recorre la lista si ve que no esta vacia y muestra a los jugadores agregados.
    {
        cout << "Nombre: " << actual->nombre << endl;
        cout << "Carnet: " << actual->carnet << endl;
        cout << "\n"<<endl;
       actual = actual->siguiente;
    }
};

void Integrantesgrp(){
    cout << "INTEGRANTES DEL GRUPO"<<endl;
    cout << "1. Diana Rebeca Ayala Jandres 00021325"<<endl;
    cout << "2. Daniel Alejandro Lopez Ruano  00156625"<<endl;
    cout << "3. Israel Lemus Sibrián 00200524"<<endl;
};
void mostrarPuntajes()
{
    if (listaPuntajes == NULL)
    {
        cout << "No hay puntajes registrados aún." << endl; // si no hay puntajes muestra el mensaje informando que no hay puntajes registrados.
        return;
    }
    
};

void ayuda()
{
    cout << "]======| Ayuda |======[ " << endl;
    cout << "1. Al seleccionar esta opcion podras agregar los nombres de las personas que quieren jugar. " << endl;
    cout<<"\n"<<endl;
    cout << "2. Al seleccionar esta opcion podras iniciar la partida para jugar." << endl;
    cout<<"\n"<<endl;
    cout << "3. Al seleccionar esta opcion se muestra la lista de jugadores " << endl;
    cout<<"\n"<<endl;
    cout << "4. Al seleccionar esta opcion se mostraran los puntajes totales de los jugadores" << endl;
    cout<<"\n"<<endl;
    cout << "5. Al seleccionar esta opcion se muestra la opcion de ayuda" << endl;
    cout<<"\n"<<endl;
    cout << "6. Al seleccionar esta opcion se mostraran las opciones de juegos, explicandote como funciona" << endl;
    cout<<"\n"<<endl;
    cout << "7. Al seleccionar esta opcion sales del programa." << endl;
    cout<<"\n"<<endl;
};

void opcionesjuego()
{
    cout << "======| OPCIONES DEL JUEGO |======" << endl;
    cout << "1. Piedra: le gana a tijeras y pierde con papel." << endl;
    cout<<"\n"<<endl;
    cout << "2. Papel: le gana a piedra y pierde con tijeras." << endl;
    cout<<"\n"<<endl;
    cout << "3. Tijeras: le gana a papel y pierde con piedra. " << endl;
    cout<<"\n"<<endl;
    
};
void menu()
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

        switch (opcion)
        {
        case 1:
            insertarNombres();
            break;
        case 2:
        break;
        case 3:
            mostrarJugadores();
            break;

        case 4:
        break;
        case 5:
          ayuda();
        break;
        case 6:
        opcionesjuego();
        break;
        case 7:
        Integrantesgrp();
        break;
        case 8:
        cout << "Saliendo..."<<endl;
        break;
        default: 
        cout << "Esa opcion no existe por favor vuelva a escoger otra opcion" << endl;
        break;
        }
    }while (opcion != 8);
};


