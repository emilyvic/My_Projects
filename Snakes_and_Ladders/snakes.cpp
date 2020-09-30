//Emilia Victoria Jácome Iñiguez
#include <iostream>
#include <string>

using namespace std;

#include "Jugador.h"
#include "Dado.h"

class MyGame {
	public:
		void start();
};

void MyGame::start(){
	//Declaración de variables:
	int turn = 1; //inicializar el primer turno previo
	Dado miDado; //objeto de la clase Dado
	int resultado, casillaActual, winner; //dados // casilla en la que se cae // ganador
	char resp; //opciones del juego
	bool victory = false; //variable para identificar si el jugador ganó

	resultado = miDado.getTiro(); 

  Jugador p1 (turn, 1, resultado, 1); //Se inicializa el objeto jugador 1 (p1)
	p1.setPosicionFinal(resultado); //calcular posición final
	p1.getTipoCasilla(); //buscar tipo casilla
	p1.identificarCasilla();//actualizar casilla a snake o ladder
  	p1.str(); //se imprime la primera vez
	casillaActual = p1.getPosicionFinal(); //cambiar la casilla
	p1.setPosicionInicial(casillaActual); //la casilla nueva inicial se vuelve la casilla final pasada

	cout << "Press C to continue next turn, or E to end the game:" << endl; //Mensaje Inicial
	cin >> resp;
	resp = toupper(resp); //Sin importar mayúsculas o minúsculas
	Jugador p2(turn, 2, resultado, 1); //Se inicializa el objeto jugador 2

while ((resp!= 'E') && (victory == false)){ //miestras no se haya presionado Exit o que ningún jugador haya ganado todavía
		while ((resp != 'C') && (resp != 'E') ){ //mientras que se presione una tecla inválida
			cout << "Invalid Option please press C to continue next turn or E to end the game" << endl; //Mensaje de respuesta inválida.
			cin >> resp;
			resp = toupper(resp); //sin importar mayúsculas o minúsculas
		}	
		if (resp == 'C'){ // continuar el juego
			turn ++;
			resultado = miDado.getTiro(); //tirar el dado
			if (turn%2 == 0){ //determinar el turno del jugador 2
				p2.setTurno(turn); // mandar la info del turno
				p2.setResultadoDado(resultado); //mandar el resultado del dado
				p2.setPosicionFinal(resultado); //mover la ficha a la posicion marcada por los dados
				p2.getTipoCasilla(); // Identificar el tipo de casilla en que se ha caído en el tablero
				p2.identificarCasilla(); // Acciones según el tipo de ficha.
				casillaActual = p2.getPosicionFinal(); // almacenar 
				p2.str();
				p2.setPosicionInicial(casillaActual);
			}
				else{
					p1.setResultadoDado(resultado);
					p1.setTurno(turn);
					p1.setPosicionFinal(resultado);
					p1.getTipoCasilla();
					p1.identificarCasilla();
					casillaActual = p1.getPosicionFinal();
					p1.str();
					p1.setPosicionInicial(casillaActual);
			}
		}
		
		if (casillaActual > 29 ){ //si la casilla final de uno de los jugadores es 30 o mayor
      		victory = true;
			if(turn %2 == 0){ //determinar si el ganador fue el jugador 2
				winner = 2;//gano el p2
			} 
			else if ( turn%2 != 0){//determinar si el ganador fue el jugador 1
				winner = 1;//gano el p1
			}
		} else {
			cin >> resp;
			resp = toupper(resp); 
		}
	}
	cout << "-- GAME OVER -- "<< endl; //mensaje para acabar el juego

	if (victory == true){
		cout << "Player " << winner << " is the winner!!! "; //mensaje para el ganador
	} else{
		cout << "Thanks for playing!!!" << endl; //mensaje para abandonar la partida
	}
}

int main(){
	MyGame g;
	g.start(); //inicializar el juego
return 0;
}
