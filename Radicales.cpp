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

/*int Radicales::encontrarMultiploComunMenor(int denominador_operador)
{
	int temp1 = 0;
	int temp2 = 0;
	int multiplo = 1;
	bool multiplo_encontrado = false;
	while(multiplo_encontrado == false)
	{
		temp1 = this->denominador * multiplo;
		temp2 = denominador_operador * multiplo;
		if(temp1 == temp2)
			multiplo_encontrado = true;
		else
			multiplo++;
	}
	return multiplo;
}*/

Radicales Radicales::operator+(Radicales& suma)
{
	int multiplo = 0;
	if(this->denominador == suma.getDenominador())
	{
		this->numerador = this->numerador + suma.getNumerador();
	}
	else
	{
		multiplo = this->denominador;
		this->denominador = this->denominador * suma.getDenominador();
		this->numerador = (this->numerador * suma.getDenominador()) + (suma.getNumerador() * multiplo);
	}
	return Radicales(numerador,this->denominador);
}

Radicales Radicales::operator-(Radicales& resta)
{
	int multiplo = 0;
	if(this->denominador == resta.getDenominador())
	{
		this->numerador = this->numerador - resta.getNumerador();
	}
	else
	{
		multiplo = this->denominador;
		this->denominador = this->denominador * resta.getDenominador();
		this->numerador = (this->numerador * resta.getDenominador()) - (resta.getNumerador() * multiplo);
	}
	return Radicales(numerador,denominador);
}

Radicales Radicales::operator*(Radicales& multiplicacion)
{
	this->numerador = this->numerador * multiplicacion.getNumerador();
	this->denominador = this->denominador * multiplicacion.getDenominador();
	return Radicales(numerador,denominador);
}

Radicales Radicales::operator/(Radicales& division)
{
	this->numerador = this->numerador * division.getDenominador();
	this->denominador = this->denominador * division.getNumerador();
	return Radicales(numerador,denominador);
}

void Radicales:: imprimirFraccion()
{
	cout<<numerador<<endl<<"--------"<<endl<<denominador<<endl;
}