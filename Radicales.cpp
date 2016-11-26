#include "Radicales.h"

Radicales::Radicales(int pNumerador, int pDenominador)
{
	this->numerador = pNumerador;
	this->denominador = pDenominador;
}

Radicales::~Radicales()
{

}

void Radicales::setNumerador(int pNumerador)
{
	this->numerador = pNumerador;
}

int Radicales::getNumerador()
{
	return this->numerador;
}

void Radicales::setDenominador(int pDenominador)
{
	this->denominador = pDenominador;
}

int Radicales::getDenominador()
{
	return this->denominador;
}

void Radicales::SimplificarFraccion()
{
	bool simplificada = false;
	int divisor = 0;

	while(simplificada==false)
	{
		divisor = encontrarDivisorComun();

		if(divisor != 0)
		{
			numerador = numerador/divisor;
			denominador = denominador/divisor;
		}
		else
		{
			simplificada = true;
		}
	}
}

int Radicales::encontrarDivisorComun()
{
	int divisor = 2;
	bool divisor_encontrado = false;
	while(divisor_encontrado == false)
	{
		if( numerador%divisor==0 && denominador%divisor==0 )
			divisor_encontrado = true;
		else
			divisor++;

		if((divisor == numerador+1 && divisor_encontrado == false) || (divisor == denominador+1 && divisor_encontrado == false))
		{
			divisor = 0;
			divisor_encontrado = true;
		}

	}
	return divisor;

}

void Radicales:: imprimirFraccion()
{
	cout<<numerador<<endl<<"--------"<<endl<<denominador<<endl;
}