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

int Radicales::encontrarMultiploComunMenor(int denominador_operador)
{
	int multiplo = 1;
	bool multiplo_encontrado = false;
	while(multiplo_encontrado == false)
	{
		if(denominador * multiplo == denominador_operador * multiplo)
			multiplo_encontrado = true;
		else
			multiplo++;
	}
	return multiplo;
}

Radicales* Radicales::operator+(Radicales& suma)
{
	int multiplo = 0;
	if(this->denominador == suma.getDenominador())
	{
		numerador = numerador + suma.getNumerador();
	}
	else
	{
		multiplo = encontrarMultiploComunMenor(suma.getDenominador());
		denominador = denominador * multiplo;
		numerador = (numerador * multiplo) + (suma.getNumerador() * multiplo);
	}
	return new Radicales(numerador,denominador);
}

Radicales* Radicales::operator-(Radicales& resta)
{
	int multiplo = 0;
	if(this->denominador == resta.getDenominador())
	{
		numerador = numerador - resta.getNumerador();
	}
	else
	{
		multiplo = encontrarMultiploComunMenor(resta.getDenominador());
		denominador = denominador * multiplo;
		numerador = (numerador * multiplo) - (resta.getNumerador() * multiplo);
	}
	return new Radicales(numerador,denominador);
}

Radicales* Radicales::operator*(Radicales& multiplicacion)
{
	numerador = numerador * multiplicacion.getNumerador();
	denominador = denominador * multiplicacion.getDenominador();
	return new Radicales(numerador,denominador);
}

Radicales* Radicales::operator/(Radicales& division)
{
	numerador = numerador * division.getDenominador();
	denominador = denominador * division.getNumerador();
	return new Radicales(numerador,denominador);
}

void Radicales:: imprimirFraccion()
{
	cout<<numerador<<endl<<"--------"<<endl<<denominador<<endl;
}