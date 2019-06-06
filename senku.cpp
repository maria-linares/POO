#include"senku.h"

using namespace std;

char O='O',x='+',esp=' ';//Con esto podemos cambiar la forma de las fichas y espacios del tablero
void crear_tablero1(tipomatriz tablero[][9],size_t filas,size_t columnas){
    for(size_t f=0;f<filas;++f){
        for(size_t c=0;c<columnas;c++){
            if(f==0 || f==8 || c==0 ||c==8 ){
                tablero[f][c]=esp;
            }
            else if((f<3 || f>5) && (c<3 ||c>5)){
                tablero[f][c]=esp;

            }else if(f==4 && c==4){
                tablero[f][c]=x;
            }else{
                tablero[f][c]=O;
            }

        }
    }
}
void crear_tablero2(tipomatriz tablero[][11],size_t filas,size_t columnas){
    for(size_t f=0;f<filas;++f){
        for(size_t c=0;c<columnas;c++){
            if(f==0 || f==10 || c==0 ||c==10 ){
                tablero[f][c]=esp;
            }
            else if((f<4 || f>6) && (c<4 ||c>6)){
                tablero[f][c]=esp;

            }else if(f==5 && c==5){
                tablero[f][c]=x;
            }else{
                tablero[f][c]=O;
            }

        }
    }
}
void crear_tablero3(tipomatriz tablero[][9],size_t filas,size_t columnas){
    for(size_t f=0;f<filas;++f){
        for(size_t c=0;c<columnas;c++){
            if(f==0 || f==8 || c==0 ||c==8 ){
                tablero[f][c]=esp;
            }
            else if((f<3 || f>5) && (c==1||c==7)){
                tablero[f][c]=esp;

            }else if((f==1 || f==7) && (c==2 ||c==6)){
                tablero[f][c]=esp;
            }
            else if(f==3 && c==4){
                tablero[f][c]=x;
            }else{
                tablero[f][c]=O;
            }

        }
    }
}
//impimir tableros sin coordenadas
void imprimir_tablero1(tipomatriz tablero[][9],size_t filas,size_t columnas){
    for(size_t f=0;f<filas;++f){
        for(size_t c=0;c<columnas;c++){
            cout<<setw(2)<<tablero[f][c];
        }
        cout<<endl;
    }
}
void imprimir_tablero2(tipomatriz tablero[][11],size_t filas,size_t columnas){
    for(size_t f=0;f<filas;++f){
        for(size_t c=0;c<columnas;c++){
            cout<<setw(2)<<tablero[f][c];
        }
        cout<<endl;
    }
}
void imprimir_tablero3(tipomatriz tablero[][9],size_t filas,size_t columnas){
    for(size_t f=0;f<filas;++f){
        for(size_t c=0;c<columnas;c++){
            cout<<setw(2)<<tablero[f][c];
        }
        cout<<endl;
    }
}
//Esta función imprime el tablero con coordenadas
void imprimir_tableroC(char **tablero,int nrow,int ncol){
    for(size_t f=0;f<nrow;++f){
        if(f>0 && f<nrow-1){
            cout<<f;
        }if(f==0){
            cout<<" ";}
        for(size_t c=1;c<ncol;c++){

            if(f==0 && c<ncol-1){
                cout<<setw(2)<<c;
            }else{
                cout<<setw(2)<<tablero[f][c];
            }

        }
        cout<<endl;
    }
}
int menu_inicial(tipomatriz tablero1[][9],tipomatriz tablero2[][11],tipomatriz tablero3[][9],int &nrow,int &ncol){
    int opcion;
    crear_tablero1(tablero1,9,9);
    crear_tablero2(tablero2,11,11);
    crear_tablero3(tablero3,9,9);
    cout<<"\n Bienvenidos a Senku! Escoge el tablero con el que quieras jugar.\n";
    cout<<" 1. Estilo Ingles.\n";
    imprimir_tablero1(tablero1,9,9);
    cout<<" 2. Estilo Aleman.\n";
    imprimir_tablero2(tablero2,11,11);
    cout<<" 3. Estilo Frances.\n";
    imprimir_tablero3(tablero3,9,9);
    cout<<" 0. Salir del programa\n";
    cout<<"\n Seleccionar la opcion: \n";
    do{
        cin>>opcion;
    }while (opcion>3 || opcion<0);
    if (opcion==1 || opcion==3){
        nrow=9;
        ncol=9;
    }else if(opcion==2){
        nrow=11;
        ncol=11;
    }else if(opcion==0){
        exit(0);
    }
    return opcion;
}
int comprobar_juego(char **tablero,size_t filas,size_t columnas){
    int sigue=0,fin=0;
    for(size_t f=1;f<filas-1;f++){
        for(size_t c=1;c<columnas-1;c++){
            if(tablero[f][c]==O){
                if((tablero[f+1][c]==O) && (tablero[f+2][c]==x)){
                    sigue++;}
                else if((tablero[f-1][c]==O) && (tablero[f-2][c]==x)){
                    sigue++;}
                else if((tablero[f][c+1]==O) && (tablero[f][c+2]==x)){
                    sigue++;}
                else if((tablero[f][c-1]==O) && (tablero[f][c-2]==x)){
                    sigue++;}
                ++fin;
            }
        }
    }
    if(fin==1){
        cout<<"¡Felicitaciones ganaste!";
        return 1;
    }else if(sigue==0){
        cout<<"Has perdido, intentalo de nuevo";
        borrar_tablero(tablero,columnas);
        return -1;
    }else{return 0;}
}
void mover_ficha(char **tablero,int fil, int col) {
    int x1=0, x2=0, y1=0, y2=0;
    int si = 0;
    do {
        cout << "Ingrese la posicion de origen (fila, columna): \n";
        cin >> x1 >> y1;
        if ((x1 > 0 || x1 < fil) && (y1 > 0 || y1 < col) && (tablero[x1][y1] == O)) {
            cout << "Ingrese la posicion de destino (fila, columna): \n";
            cin >> x2 >> y2;
            if ((tablero[x2][y2] == x) && (tablero[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] == O) &&
                (abs(x2 - x1) == 2 || abs(y2 - y1) == 2)) {
                ++si;
            } else {
                cout << "Ingrese un movimiento valido\n";
            }
        }
    } while (si == 0);
    if(si>0){
        tablero[x1][y1]=x;
        tablero[x2][y2]=O;
        tablero[x1+(x2-x1)/2][y1+(y2-y1)/2]=x;
    }
}
void crear_juego(char **tablero, int nrow, int ncol,int tab){
    if(tab==1){
        for(size_t f=0;f<nrow;++f){
            for(size_t c=0;c<ncol;c++){
                if(f==0 || f==8 || c==0 ||c==8 ){
                    tablero[f][c]=esp;
                }
                else if((f<3 || f>5) && (c<3 ||c>5)){
                    tablero[f][c]=esp;

                }else if(f==4 && c==4){
                    tablero[f][c]=x;
                }else{
                    tablero[f][c]=O;
                }

            }
        }
    }else if(tab==2){
        for(size_t f=0;f<nrow;++f){
            for(size_t c=0;c<ncol;c++){
                if(f==0 || f==10 || c==0 ||c==10 ){
                    tablero[f][c]=esp;
                }
                else if((f<4 || f>6) && (c<4 ||c>6)){
                    tablero[f][c]=esp;

                }else if(f==5 && c==5){
                    tablero[f][c]=x;
                }else{
                    tablero[f][c]=O;
                }

            }
        }
    }else if(tab==3){
        for(size_t f=0;f<nrow;++f){
            for(size_t c=0;c<ncol;c++){
                if(f==0 || f==8 || c==0 ||c==8 ){
                    tablero[f][c]=esp;
                }
                else if((f<3 || f>5) && (c==1||c==7)){
                    tablero[f][c]=esp;

                }else if((f==1 || f==7) && (c==2 ||c==6)){
                    tablero[f][c]=esp;
                }
                else if(f==3 && c==4){
                    tablero[f][c]=x;
                }else{
                    tablero[f][c]=O;
                }

            }
        }
    }
}
void borrar_tablero(char **tablero,int ncol){
    for (size_t i = 0; i <ncol ; ++i) {
        delete [] tablero[i];
    }
    delete []tablero;
}
