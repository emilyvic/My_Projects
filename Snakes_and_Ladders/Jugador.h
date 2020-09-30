#include<iostream>
#include<string>
using namespace std;
#include"Tablero.h"

class Jugador{
	public:
		Jugador(int turno, int idJugador, int resultadoDado, int posicionInicial);
		//Métodos de acceso
		int getTurno();
		int getIdJugador();
		int getPosicionInicial();
		int getResultadoDado();
		char getTipoCasilla();
		int getPosicionFinal();
		//Métodos de modificación
		void setTurno(int turno);
		void setPosicionInicial(int posicionInicial);
		void setPosicionFinal(int resultadoDado);
		void setResultadoDado(int resultadoDado);
		//otros métodos
		void identificarCasilla();// moverse en función del tipo de casilla
    	void str(); //imprimir 
		Tablero tab[50];

	private:
		int turno, idJugador, posicionInicial, resultadoDado, posicionFinal, posicionCasilla;
		char tipoCasilla;
};

Jugador::Jugador(int turno, int idJugador, int resultadoDado, int posicionInicial){ //constructor inicial
		this -> turno = turno;
		this -> idJugador = idJugador;
		this -> resultadoDado = resultadoDado;
		this -> posicionInicial = posicionInicial;
		posicionFinal = posicionInicial + resultadoDado; //determinada por el resultado de los dados
		posicionCasilla = posicionFinal; //se graba la posicion actual de la casilla
}

int Jugador::getTurno(){
	return turno;
}

int Jugador::getIdJugador(){
	return idJugador;
}

int Jugador::getPosicionInicial(){
	return posicionInicial;
}

int Jugador::getResultadoDado(){
	return resultadoDado;
}

int Jugador::getPosicionFinal(){
	return posicionFinal;
}

char Jugador::getTipoCasilla(){
	tipoCasilla = tab[posicionFinal].getCasilla(posicionFinal);
	return tipoCasilla;
}

void Jugador::setPosicionInicial(int posicionInicial){
	this -> posicionInicial = posicionInicial;
}

void Jugador::setPosicionFinal(int resultadoDado){
		posicionFinal = posicionInicial + resultadoDado;
}

void Jugador::setResultadoDado(int resultadoDado){
	this -> resultadoDado = resultadoDado;
}

void Jugador::setTurno(int turno){
	this -> turno = turno;
}

void Jugador::identificarCasilla(){
	posicionCasilla = posicionFinal; //guardar el tipo de casilla intermedia para imprimir en la jugada
	if ( tipoCasilla == 'S' ){ //penalty
		posicionFinal -= 3;
	} else if(tipoCasilla == 'L'){//reward
		posicionFinal += 3;
	}
	else{
		posicionFinal = posicionCasilla;//casilla normal
	}
} 

void Jugador::str(){
	if (posicionFinal > 30){ //si la casilla final sobrepasa de 30
		posicionFinal = 30; //entonces fijar la posicion final de 30
		posicionCasilla = 30; 
	}
    cout << " " << turno << " "<< idJugador << " " << posicionInicial << " " <<  resultadoDado << " " << tab[posicionCasilla].getCasilla(posicionCasilla) << " " <<  posicionFinal << endl;
	cout << "\n"; //salto de línea para separar cada turno.
} 