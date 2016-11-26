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
		cout<<"Salir?[0=No||1=Si]  ";
		cin>>op;
	}while(op==0);
	return 0;
}