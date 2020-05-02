/*
Ejercicio # 1 - 3 puntos.
Una empresa tiene diez almacenes y necesita crear un programa que lea las ventas mensuales de los diez almacenes,
calcular la media de ventas y obtener un listado de los almacenes cuyas ventas mensuales son superiores a la media
*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

struct almacen{
  int codigo;
  int mes;
  float montoVendido;
}almacen[10];

void inicial();

main(){
	
	inicial();
}

void inicial(){
int i,n;
int media = 0;
	
	cout<<"CUANTOS DATOS DESEA INGRESAR?: ";
	cin>>n;
	system("cls");
	for(i=0;i<n;i++){
		cout<<"*****************************************"<<endl;
		cout<<"*BIENVENIDO A ALMACENES DE GUATEMALA S.A*"<<endl;
		cout<<"*************INGRESE DATOS***************"<<endl;
		fflush(stdin);
		cout<<"CODIGO: ";
		cin>>almacen[i].codigo;
		cout<<"MES: ";
		cin>>almacen[i].mes;
		cout<<"MONTO TOTAL: Q";
		cin>>almacen[i].montoVendido;
		system("cls");
	
		media = almacen[i].montoVendido/2;
	}
	
	
	
	//Imprimiendo
	system("cls");
	cout<<"*****************************************"<<endl;
	cout<<"*BIENVENIDO A ALMACENES DE GUATEMALA S.A*"<<endl;
	cout<<"*****************************************"<<endl;
	cout<<"ALMACENES: "<<endl;
	for(i=0;i<n;i++){
		cout<<"ALMACEN: "<<almacen[i].codigo<<endl;
		cout<<"MES: "<<almacen[i].mes<<endl;
		cout<<"MONTO TOTAL: Q"<<almacen[i].montoVendido<<endl;
		cout<<"-------------------------------------"<<endl;
		if(almacen[i].montoVendido >= media){
		cout<<"***SUPERA LA MEDIA EN VENTAS***"<<endl;
	}
	}
	
}


