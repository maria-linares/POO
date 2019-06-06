#include <iostream>
#include"senku.h"
using namespace std;
int main() {
    int nrow=0,ncol=0;
    char**tablero= nullptr;
    int tab;
    int termina=0;
    tipomatriz tablero1[9][9];
    tipomatriz tablero2[11][11];
    tipomatriz tablero3[9][9];
    //juego
    tab=menu_inicial(tablero1,tablero2,tablero3,nrow,ncol);
    cout<<nrow<<endl;
    cout<<tab<<endl;
    //declarar tablero
    tablero=new char*[nrow];
    for (size_t i = 0; i <nrow ; ++i) {
        tablero[i] = new char[nrow];
    }
    crear_juego(tablero, nrow, ncol,tab);
    imprimir_tableroC(tablero,nrow,ncol);
    int mov=0;
    while(termina==0){
        mover_ficha(tablero,nrow,ncol);
        ++mov;
        cout<<"Numero movimientos: "<<mov<<endl;
        imprimir_tableroC(tablero,nrow,ncol);
        termina=comprobar_juego(tablero,nrow,ncol);
    }
    borrar_tablero(tablero,ncol);
    return 0;
}
