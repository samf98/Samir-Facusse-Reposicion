#include <iostream>
#include "Radicales.h"

using namespace std;

int main()
{
	Radicales* inicial = NULL;
	int op = 0;
	do
	{
		cout<<"1-Crear fracción"<<endl;
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
					cout<<"Fracción simplificada."<<endl<<endl;
					inicial->SimplificarFraccion();
					inicial->imprimirFraccion();
				}
				else
					cout<<"Denominador inválido, no se creará ninguna fracción."<<endl;
				break;
			}
		}
		cout<<"Salir?[0=No||1=Si]  ";
		cin>>op;
	}while(op==0);

	delete inicial;
	return 0;
}