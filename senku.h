#ifndef SENKU_PROYECTO_POO_SENKU_H
#define SENKU_PROYECTO_POO_SENKU_H
#include <iostream>
#include <iomanip>
typedef char tipomatriz;
int menu_inicial(tipomatriz tablero1[][9],tipomatriz tablero2[][11],tipomatriz tablero3[][9],int &nrow,int &ncol);
void crear_tablero1(tipomatriz tablero[][9],size_t filas,size_t columnas);
void crear_tablero2(tipomatriz tablero[][11],size_t filas,size_t columnas);
void crear_tablero3(tipomatriz tablero[][9],size_t filas,size_t columnas);
void imprimir_tablero1(tipomatriz tablero[][9],size_t filas,size_t columnas);
void imprimir_tablero2(tipomatriz tablero[][11],size_t filas,size_t columnas);
void imprimir_tablero3(tipomatriz tablero[][9],size_t filas,size_t columnas);
int comprobar_juego(char **tablero,size_t filas,size_t columnas);
void mover_ficha(char **tablero,int fil, int col);
void crear_juego(char **tablero, int nrow, int ncol,int tab);
void imprimir_tableroC(char **tablero,int nrow,int ncol);
void borrar_tablero(char **tablero,int ncol);
#endif //SENKU_PROYECTO_POO_SENKU_H
