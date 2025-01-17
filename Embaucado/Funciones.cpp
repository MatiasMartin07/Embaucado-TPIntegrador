#include <iostream>
#include <string>
#include "funciones.h"
#include<cstdlib>
#include<ctime>
using namespace std;

void mostrarMenuPrincipal() {
    cout << endl;
    cout << endl;
    cout << "\t\t ======================================" << endl;
    cout << "\t\t=|             EMBAUCADO              |=" << endl;
    cout << "\t\t=|        ---------------------       |=" << endl;
    cout << "\t\t=|             1 - JUGAR              |=" << endl;
    cout << "\t\t=|             2 - ESTADÍSTICAS       |=" << endl;
    cout << "\t\t=|             3 - CRÉDITOS           |=" << endl;
    cout << "\t\t=|        ---------------------       |=" << endl;
    cout << "\t\t=|             0 - SALIR              |=" << endl;
    cout << "\t\t=|                                    |=" << endl;
    cout << "\t\t ======================================" << endl;
    cout << endl;
    cout << "\t\t    Jugadores Ingresen una Opcion: ";
}
void cargarJugadores(string& nombre1, string& nombre2) {

    char opcion;
    int cambioNombre;
    cout << "\t\t ----------------------------------------------   " << endl;
    cout << "\t\t  Antes de comenzar deben registrar sus nombres:  " << endl;
    cout << "\t\t                                                  " << endl;
    cout << "\t\t  Nombre del Jugador 1:";cin >> nombre1;
    cout << "\t\t  Nombre del Jugador 2:";cin >> nombre2;  cout << endl;




    do {
        cout << "\t\t  Confirmar nombres (S/N):";
        cin >> opcion; cout << endl;


        if (opcion == 'N' || opcion == 'n') {
            cout << "\t\tIngrese el numero de Jugador que desea cambiar: ";

            cin >> cambioNombre;
            cout << endl;
            if (cambioNombre == 1) {

                cout << "\t\tNombre del Jugador 1:";
                cin >> nombre1;
            }
            else if (cambioNombre == 2) {
                cout << "\t\t ----------------------------------------------   " << endl;

                cout << "\t\tNombre del Jugador 2:";
                cin >> nombre2;
            }
            cout << endl;
            cout << "\t\t ----------------------------------------------   " << endl;
            cout << "\t\tConfirmar nombres (S/N):";
            cin >> opcion;
        }
        else {

            cout << endl;
            cout << "\t\t ----------------------------------------------   " << endl;
            cout << "\t\t -------INGRESE UNA OPCION VALIDA (S/N):-------   " << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
    } while (opcion != 'S' && opcion != 's');
    system("cls");
}


void crearMazos(string mazoNaipe[], string mazoPalo[]) {
    crearMazoNaipe(mazoNaipe);
    crearMazoPalo(mazoPalo);
}
void crearMazoNaipe(string mazoNaipe[]) {

    int cont = 0;

    string vNaipes[] = { "10","J","Q","K","A" };

    for (int i = 0;i <= 4;i++) {
        for (int j = 0;j <= 3;j++) {
            mazoNaipe[cont] = vNaipes[i];

            cont++;
        }
    }
}
void crearMazoPalo(string mazoPalo[]) {
    int cont = 0;

    string vPalo[] = { "Corazon","Diamante","Pica","Trebol" };

    for (int i = 0;i <= 4;i++) {
        for (int j = 0;j <= 3;j++) {
            mazoPalo[cont] = vPalo[j];
            cont++;
        }
    }
}

void repartirCartasJugador(string mazoNaipe[],
                           string mazoPalo[],
                           string naipesJugador[],
                           string palosJugador[])
{
    int contadorCartas = 0;

    int num1, num2 = 1;

    while (contadorCartas < 5) {


        num1 = 1 + (rand() % (20 - contadorCartas));
        //genera un numero random del 1 al 20 lo almacena en num1 y le resto contadorCartas que se van poniendo en cero

        if (num1 != num2 && (mazoNaipe[num1] != "Cero")) {
            //pregunto si son distintos num1 y num2 Y si lo que hay guardado en mazoNaipe[num1] es distinto de "Cero".
            // si es verdadero almacena el palo y el naipe en su respectivo vector, si es falso no hace nada y genera numero nuevo.
            // num2 lo inicialize en 1 
            num2 = num1;
            //  cout<<num2<<"----2--"<<endl;

            naipesJugador[contadorCartas] = mazoNaipe[num1];
            palosJugador[contadorCartas] = mazoPalo[num1];

            //vJugador1[k]=vMazo[num1];

            contadorCartas++; //incrementa contador para las 5 cartas
        }
        mazoNaipe[num1] = "Cero";
        //En el indice num1 del vector mazoNaipe guardamos el string "Cero", porque esa es una carta que ya se entrego, para que no se repita le ponemos el valor "Cero"
    }

}

//reparte cartas jugador 1

void repartirCartasJugador1(string vJugador1[], int cantCartas, string vMazo[], int TAM) {
    int k = 0;
    int num1, num2 = 1;
    while (k < 5) {


        num1 = 1 + (rand() % (20 - k));//genera un numero random del 1 al 20 lo almacena en num1 y
        // le resto k que se van poniendo en cero

        if (num1 != num2 && vMazo[num1] != "Cero") {//evaluo si son iguales num2 lo inicialize en 1 si son distintos almacena sino no hace nada y genera numero nuevo
            num2 = num1;
            //  cout<<num2<<"----2--"<<endl;
            vJugador1[k] = vMazo[num1];

            k++; //incrementa contador para las 5 cartas
        }
        vMazo[num1] = "Cero";//se reescribe el vector del mazo con las cartas entregadas al jugador 1 para que no le toquen las mismas al jugador2
    }
}

//reparte cartas jugador 2

void repartirCartasJugador2(string vJugador2[], int cantCartas, string vMazo[], int TAM) {
    int num3, num4 = 1;

    int l = 0;
    while (l < 5) {
        num3 = 1 + (rand() % 15);//genera un numero random del 1 al 15 ya que repartio 5 lo almacena en num3

        if (num3 != num4 && vMazo[num3] != "Cero") {//evaluo si son iguales num4 lo inicialize en 1
            //si son distintos almacena sino no hace nada y genera numero nuevo

            num4 = num3;

            vJugador2[l] = vMazo[num3];

            l++; //incrementa contador para las 5 cartas
        }
        vMazo[num3] = "Cero";//se reescribe el vector del mazo con las cartas entregadas al jugador 2 para que no le toquen las mismas
    }

}
//mostrar cartas jugador 1

//mostrar cartas jugador 2

//Genera carta Embaucadora
void generarEmbaucadora(string& cartaEmbaucadora) {

    string vPalo[] = { "Corazon","Diamante","Pica","Trebol" };

    cartaEmbaucadora = vPalo[(rand() % 4)];


}
void cartasjugadores(string vJugador1[], string vJugador2[], int cantCartas, string& nombreJugador1, string& nombreJugador2) {

    int z;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Jugador 1:" << nombreJugador1 << " \t\t  " << "Jugador 2:" << nombreJugador2 << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;

    for (z = 0;z < 5;z++) {

        cout << "\t" << vJugador1[z] << " \t\t\t " << vJugador2[z] << endl;
    }
}
void mostrarNombresJugadores(string nombreJugador1, string nombreJugador2) {
   
    cout << "---------------------------------------------------------------" << endl;
    cout << "Jugador 1:" << nombreJugador1 << " \t\t  " << "Jugador 2:" << nombreJugador2 << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;

}

void mostrarCartasjugadores(string naipesJugador1[], string palosJugador1[], int puntosJugador1[],
                             string naipesJugador2[], string palosJugador2[], int puntosJugador2[] ) {

    for (int i = 0;i < 5;i++) {

        cout << " " << puntosJugador1[i] << "\t " << naipesJugador1[i] << " de " << palosJugador1[i] << "\t\t" << " " << puntosJugador2[i] << "\t" << naipesJugador2[i] << " de " << palosJugador2[i] << endl;
    }
}
void puntosPorJugador(string naipeJugador[], string paloJugador[], int puntosJugador[], int cantCartas, string& cartaEmbaucadora) {

    int x;

    for (x = 0;x < 5;x++) {

        if (paloJugador[x] == cartaEmbaucadora) {

            puntosJugador[x] = 0;

        }
        else if (naipeJugador[x] == "10") {
            puntosJugador[x] = 10;
        }
        else if (naipeJugador[x] == "J") {
            puntosJugador[x] = 11;
        }
        else if (naipeJugador[x] == "Q") {
            puntosJugador[x] = 12;
        }
        else if (naipeJugador[x] == "K") {
            puntosJugador[x] = 15;
        }
        else if (naipeJugador[x] == "A") {
            puntosJugador[x] = 20;
        }
       

    }
    

}

void confirmarEmbaucadora() {

}