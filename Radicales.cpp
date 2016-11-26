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

void Radicales:: imprimirFraccion()
{
	cout<<numerador<<endl<<"--------"<<endl<<denominador<<endl;
}