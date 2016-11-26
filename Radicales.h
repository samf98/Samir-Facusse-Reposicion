#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Radicales
{
	private:
		int numerador;
		int denominador;

	public:
		Radicales(int,int);
		~Radicales();
		void setNumerador(int);
		int getNumerador();
		void setDenominador(int);
		int getDenominador();
		void imprimirFraccion();
		void SimplificarFraccion();
		int encontrarDivisorComun();
};