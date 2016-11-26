#include <iostream>
#include "Radicales.h"

using namespace std;

void calculadora(Radicales*);

int main()
{
	Radicales* inicial = NULL;
	int op = 0;
	do
	{
		cout<<"1-Crear fracción"<<endl<<"2-Usar calculadora"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
			{
				int numerador = 0;
				int denominador = 0;

				cout<<"Ingrese numerador: ";
				cin>>numerador;
				cout<<"Ingrese denominador (recuerde que no puede ser 0): ";
				cin>>denominador;
				if(denominador!=0)
				{
					inicial = new Radicales(numerador,denominador);
					cout<<"Fracción inicial."<<endl<<endl;
					inicial->imprimirFraccion();
					cout<<endl<<endl;
					cout<<"Fracción simplificada."<<endl<<endl;
					inicial->SimplificarFraccion();
					inicial->imprimirFraccion();
					cout<<endl<<endl;
				}
				else
					cout<<"Denominador inválido, no se creará ninguna fracción."<<endl;
				break;
			}
			case 2:
			{
				if(inicial == NULL)
					cout<<"No ha creado una fracción inicial."<<endl;
				else
					calculadora(inicial);
				break;
			}
		}
		cout<<"Salir?[0=No||1=Si]  ";
		cin>>op;
	}while(op==0);

	delete inicial;
	return 0;
}

void calculadora(Radicales* inicial)
{
	Radicales* resultado;
	resultado = inicial;
	Radicales* operador = NULL;
	int op = 0;
	int numerador_segundo=0;
	int denominador_segundo=0;
	cout<<"Crear segunda fracción:"<<endl;
	cout<<"Ingrese numerador: ";
	cin>>numerador_segundo;
	cout<<"Ingrese denomindador: ";
	cin>>denominador_segundo;
	if(denominador_segundo!=0)
	{
		operador = new Radicales(numerador_segundo,denominador_segundo);
		cout<<"Fracción inicial: "<<endl<<endl;
		operador->imprimirFraccion();
		cout<<endl<<endl;
		cout<<"Fracción simplificada: "<<endl<<endl;
		operador->SimplificarFraccion();
		operador->imprimirFraccion();
		cout<<endl<<endl;
		cout<<"1-Suma"<<endl<<"2-Resta"<<endl<<"3-Multiplicación"<<endl<<"4-División"<<endl;
		cin>>op;
		cout<<"Fracción 1: "<<endl<<endl;
		inicial->imprimirFraccion();
		cout<<"Fracción 2: "<<endl<<endl;
		operador->imprimirFraccion();
		cout<<endl<<endl;
		if(op==1){
			*resultado = *inicial + *operador;
		}
		else if(op == 2)
		{
			*resultado = *inicial - *operador;
		}
		else if(op == 3)
		{
			*resultado = *inicial * *operador;
		}
		else if(op == 4)
		{
			*resultado = *inicial / *operador;
		}
		cout<<"Fracción resultante: "<<endl<<endl;
		inicial -> SimplificarFraccion();
		inicial -> imprimirFraccion();
		cout<<endl;<<endl;
	}
	else
		cout<<"Denominador inválido, no se creo una segunda fracción."<<endl;
	delete operador;
}