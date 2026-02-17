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

// funciones
void enumerarjugadores(Nodo *lista);
int total(Nodo *lista);
Nodo *buscarnumerorandom(Nodo *lista, int num);
void Jugadoresrand(Nodo *lista, Nodo *&jugador1, Nodo *&jugador2);
void actualizarPuntaje(string nombre);

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

void Jugar()
{
    cout << "Iniciando partida..." << endl;

    int totaldejugadores = total(primero);

    if (totaldejugadores < 2)
    {
        cout << "No hay suficientes jugadores para empezar la partida" << endl;
    };

    enumerarjugadores(primero);

    cout << "======| JUGADORES |====== " << endl;
    cout << "\n"<< endl;
    Nodo *jugador1;
    Nodo *jugador2; // mandar a llamar para luego mostrarlo con ayuda de la funcion
    Jugadoresrand(primero, jugador1, jugador2);
    
    // mostrar los jugadores de la partida que salieron con el numero random
    cout << "Jugador 1: " << jugador1->nombre << endl;
    cout << "Jugador 2: " << jugador2->nombre << endl;
    

    string opcionesdejuego[] = {"Piedra", "Papel", "Tijera"};
    string opcion1 = opcionesdejuego[rand() % 3];
    string opcion2 = opcionesdejuego[rand() % 3]; // para generar las opciones piedra, papel y tijera.

    //cout << "\n"<< endl;

    cout << "jugador 1: " << jugador1->nombre << "  saca:   " << opcion1 << endl;
    cout << "jugador 2: " << jugador2->nombre << "  saca:   " << opcion2 << endl;
    cout<<"\n"<<endl;

    if (opcion1 == opcion2)
    {
        cout << "Empate" << endl;
        // si en estos casos gana el jugador 1:
    }
    else if ((opcion1 == "Piedra" && opcion2 == "Tijeras") || (opcion1 == "Papel" && opcion2 == "Piedra") || (opcion1 == "Tijeras" && opcion2 == "Papel"))
    {

        cout << jugador1->nombre << " es el ganador :D!" << endl;
        cout << "\n"<< endl;
        actualizarPuntaje(jugador1->nombre);
    }
    else
    {
        cout << jugador2->nombre << " es el ganador :D!" << endl;
        cout << "\n"<< endl;
        actualizarPuntaje(jugador2->nombre);
    };
};


void enumerarjugadores(Nodo *lista) //funcion para asignar un numero a cada jugador que se vaya agregando
{ // variable que tiene la direccion del primer nodo/elemento

    Nodo *actual = lista; // se guarda la direccion del primer nodo en actual
    int contador = 1;
    while (actual != NULL)
    { // mientras exista un elemento

        actual->numero = contador;  // para acceder al campo numero del nodo y asignar el uno al primer nodo.
        contador++;                 // una vez se ha asignado el primer numero, pasara al siguiente nodo y empezara a enlistarlos
        actual = actual->siguiente; // una vez asignado el numero, el puntero actual guarda la direccion del siguiente nodo y sucesivamente.
    }
};

int total(Nodo *lista)
{
    int contador = 0; // iniciar el contador con cero para que inicie con el primer dato de la lista.

    Nodo *actual = lista;

    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente; // el while ayudara a saber cuantos datos hay en la lista
    }
    return contador; // devolverá el total de datos que tiene la lista
};

// funcion para buscar la direccion donde se encuentran el numero del jugador:

Nodo *buscarnumerorandom(Nodo *lista, int num)
{
    Nodo *actual = lista; // apuntar al primer elemento de la lista
    while (actual != NULL)
    {                              // mientras se encuentre llena la lista se cumplira
        if (actual->numero == num) // si se cumple, devuelve la direccion del random 1
        {
            return actual; // ayudara a llegar a la direccion del numero random 1
        }
        actual = actual->siguiente; // se pasa a buscar la direccion del siguiente numero random , si no esta ahi, sigue al siguiente y sucesivamente.
    }
    return NULL;
};

Nodo *numeroal(Nodo *lista)
{ // esta funcion devolverá una copia de la direccion del nodo aleatorio, se ocupa tipo nodo

    int totaljugadores = total(lista); // ahi se guarda el total de jugadores que se obtuvo de la funcion anterior

    if (totaljugadores == 0)
    {
        return nullptr; // si no hay ningun jugador, no se eligirá
    }

    int numerorandom = rand() % totaljugadores + 1;

    return buscarnumerorandom(lista, numerorandom);
};

void Jugadoresrand(Nodo *lista, Nodo *&jugador1, Nodo *&jugador2)
{ //
    int total = 0;
    Nodo *actual = lista;

    while (actual != NULL)
    {
        total++; // el total aumente mediante el numero de datos que se encuentre en la lista
        actual = actual->siguiente;
    };

    if (total < 2)
    {                               // si hay menos de dos jugadores
        jugador1 = jugador2 = NULL; // si se cumple la condicion, no hay jugadores o solo hay 1
        return;
    }

    int posjugador1= rand() % total; // seleccionara la posicion del jugador random que jugara en la partida
    int posjugador2;

    do
    {
        posjugador2 = rand() % total; // ahora eligira al otro jugador de la ronda

    } while (posjugador2 == posjugador1); // el while se ejecutara siempre y cuando los dos jugadores tengan la misma direccion, si tienen la misma direccion, se ejecutara para generar una diferente

    jugador1 = lista;

    for (int i = 0; i < posjugador1; i++)
    {                                   // buscara la direccion que se generaron con el rand
        jugador1 = jugador1->siguiente; // para moverse al siguiente nodo
    }

    jugador2 = lista;
    for (int i = 0; i < posjugador2; i++)
    {
        jugador2 = jugador2->siguiente;
    };

    cout << "Jugadores a competir: " << jugador1->nombre<< " y " << jugador2->nombre << endl; // muestra los jugadores a jugar en esta ronda
    cout<<"\n"<<endl;
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

void actualizarPuntaje(string nombre)
{
    Puntaje *actual = listaPuntajes;

    // Buscar si el jugador ya tiene puntos registrados
    while (actual != NULL)
    {
        if (actual->nombreJugador == nombre)
        {
            actual->puntos++; // Aumentar puntos si ya existe
            return;
        }
        actual = actual->siguiente;
    }

    // Si no existe crea un  nuevo registro
    Puntaje *nuevo = new Puntaje();
    nuevo->nombreJugador = nombre;
    nuevo->puntos = 1;
    nuevo->siguiente = listaPuntajes;
    listaPuntajes = nuevo;
}


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
    cout << "======| TABLA DE PUNTAJES |======" << endl;
    cout << "\n"<<endl;

    Puntaje *actual = listaPuntajes;
    while (actual != NULL)
    {
        cout << "Jugador: " << actual->nombreJugador << " Puntos: " << actual->puntos << endl;
        actual = actual->siguiente;
    }
    // Encontrar al jugador con más puntos
    actual = listaPuntajes;
    string ganador = "";
    int maxPuntos = 0;

    while (actual != NULL)
    {
        if (actual->puntos > maxPuntos)
        {
            maxPuntos = actual->puntos;
            ganador = actual->nombreJugador;
        }
        actual = actual->siguiente;
    }

    cout << "Ganador de la partida: " << ganador << " con " << maxPuntos << " 5 victorias gana el juego. " << endl;
    //modificacion de victorias
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
        mostrarPuntajes();
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