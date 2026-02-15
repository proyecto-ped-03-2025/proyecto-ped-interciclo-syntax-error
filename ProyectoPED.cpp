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
};
