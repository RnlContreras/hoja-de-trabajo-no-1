#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;

int opcion;
void calculoSalario(ofstream &Sala);
void nuevoEmpleado(ofstream &datos);
void listaEmp(ifstream &Lec);

int main(){
	char cont_2;
	
	do{
	ofstream Esc;
	ifstream Lec;
	ofstream Sala;
	
	system("cls");
	cout<<"---MENU PRINCIPAL---"<<endl;
	cout<<"1.DATOS EMPLEADO"<<endl;
	cout<<"2.DATOS GUARDADOS"<<endl;
	cout<<"3.CALCULO SALARIO"<<endl;
	
	cout<<"SELECCION: |";
	cin>>opcion;
	
	switch(opcion){
		
			case 1:{
			nuevoEmpleado(Esc);
			break;
			}//case 1 switch1
			case 2:{
			listaEmp(Lec);
			break;
			}
			case 3:{
			calculoSalario(Sala);
			break;
			}
			case 4:{
         	
            break;
            default:
               cout<<"NO SE ENCONTRO SELECCION: "<<endl;
      }	
	}
      cout<<"OPRIMA CUALQUIER TECLA PARA VOLVER: |";
      cin>>cont_2;
   }while(cont_2!=1);
   system("PAUSE");
}

void calculoSalario(ofstream &datos){
	double salarioPorhora;
	double horaT;
	double salario1;
	double horaE;
	double salarioExtra;
	double igss;
	double salarioF;
	
	datos.open("baseDatos.txt", ios::out|ios::app);
	
	system("cls");
	cout<<"---CALCULO DE SALARIO---";
	
	cout<<"\nINGRESE EL VALOR SALARIO POR HORA: ";
	cin>>salarioPorhora;
	cout<<"INGRESE HORAS TRABAJADAS: ";
	cin>>horaT;
	horaE = horaT - 40;
	
	salario1 = salarioPorhora*horaT;
		
	cout<<"SALARIO ORDINARIO: Q."<<salario1<<endl;
	
	
	if(horaT > 40){
		cout<<"EL ENPLEADO TIENE: "<<horaE<<" HORAS EXTRAS!"<<endl;
		salarioExtra = (salarioPorhora*0.015)*horaE;
		cout<<"SALARIO EXTRA: Q."<<salarioExtra<<endl;
	}
	
	igss = (salario1 + salarioExtra)*  0.0483;
	cout<<"IGSS: "<<igss<<endl;
	
	salarioF = (salarioExtra + salario1)-igss;
	
	cout<<"TOTAL A PAGAR: Q."<<salarioF<<endl;
	
	datos<<salarioF;
	datos.close();
}


void nuevoEmpleado(ofstream &datos){
	string nombre;
	string nombre1;
	string apellido;
	string apellido1;
	
	
	
	
	int seleccion = 1;
	
	do{
		datos.open("baseDatos.txt", ios::out|ios::app);
		
		system("cls");
		cout<<"---INGRESE DATOS DEL EMPLADO---"<<endl;
		cout<<"PRIMER NOMBRE: ";
		cin>>nombre;
		cout<<"SEGUNDO NOMBRE: ";
		cin>>nombre1;
		cout<<"PRIMER APELLIDO: ";
		cin>>apellido;
		cout<<"SEGUNDO APELLIDO: ";
		cin>>apellido1;	
		
		datos<<nombre<<"\t"<<nombre1<<"\t"<<apellido<<"\t"<<apellido1<<"\n";
		datos.close();	
	
	cout<<"DESEA INGRESAR OTRO DATO: SI(1)NO(0): |";
	cin>>seleccion;	
	}while(seleccion == 1);
	
}
void listaEmp(ifstream &Lec){
	system("cls");
	string nombre;
	string nombre1;
	string apellido;
	string apellido1;
	string salarioF;
	
	Lec.open("baseDatos.txt", ios::in);
	
	Lec>>nombre;
	while(!Lec.eof()){
		Lec>>nombre1;
		Lec>>apellido;
		Lec>>apellido1;
		Lec>>salarioF;
		
		cout<<"NOMBRE DEL EMPLEADO: "<<nombre<<" "<<nombre1<<" "<<apellido<<" "<<apellido1<<"\t"<<salarioF<<endl;
		
		Lec>>nombre;
	}
	Lec.close();
}

