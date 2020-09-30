#include<iostream>
#include<string>
using namespace std;

class Tablero{
private:
	char tab[50]; //tablero como arreglo de chars (tipos de casilla)

public:
 	Tablero();
 	char getCasilla(int casillaFinal); //método para obtener el tipo de casilla según el número de casilla (índice)
};

Tablero::Tablero(){
	tab[0] = '-';
	for (int num = 1; num <= 30; num ++){ //Tamaño del tablero = 30 casillas.
		tab[num] = 'N'; //Inicializar todas las casillas de tipo N
	}
	//Determinar las casillas de tipo snake
	tab[9] = 'S';
	tab[19] = 'S';
	tab[29] = 'S';
	//Determinar las casillas de tipo Ladder
	tab[12] = 'L';
	tab[23] = 'L';
	tab[26] = 'L';
}

char Tablero::getCasilla(int casillaFinal){
	return tab[casillaFinal]; //Dame el tipo de casilla de mi casilla final
}