#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Radical
{
	private:
		int numerador;
		int denominador;

	public:
		Radical(int,int);
		~Radical();
		void setNumerador(int);
		int getNumerador();
		void setDenominador();
		int getDenominador();
		void imprimirFraccion();
}