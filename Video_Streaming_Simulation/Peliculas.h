#ifndef PELICULAS_H
#define PELICULAS_H

#include <fstream>
#include "Pelicula.h"

using namespace std;
#include <sstream>

class Peliculas{
    public:
        Peliculas();
        void leerArchivo();
        void mostrar(); //Reporte de todas las películas, muestra calificación promedio de todas las películas
        //double calculaPromedio(double valor);
        void reporteCalificacion(double buscaRating);
        void reporteGenero(string buscaGenero);
        void setPtrPelicula(Pelicula *ptr); //para cuando se ingresa por teclado
        Pelicula getPtrPelicula(int);
        void cambiarOscars(int idPeli, int oscares );
        bool validarId(int idPeli);
    private:
        Pelicula *arrPtrPelis[100]; //arreglo de Pointers de tipo película
        int cant; //cantidad de elementos en el arreglo
};

Peliculas::Peliculas(){
    cant = 0;
    for (int cont =0; cont < 100; cont++){
        arrPtrPelis[cont] = nullptr;//arreglo de apuntadores de tipo película, no utiliza memoria adicional
    } 
}

void Peliculas::leerArchivo(){
    fstream archEnt; //archivo de entrada
    archEnt.open("ArchivoPeliculas.txt"); //abrir archivo de entrada
    string arr[6]; // crear un arreglo de strings para almacenar los reglones que sacas del archivo
    string linea, palabra; // crear el string linea para sustraer la 
    cout <<" *** REGISTRANDO LAS SIGUIENTES PELICULAS... ***" << endl;
    while (getline(archEnt, linea)){ //leer una línea entera u guardarlo en la variable linea.
        cout //<< "Linea #" << cant << " Contiene: " 
        << linea << endl;
        stringstream s(linea); //para separar palabras

        //lee cada columna de datos de un reglón y guardalo en un variable string "palabra" hasta que encuentra una ,
        
        int numCol = 0;

        while(getline (s, palabra, ',')){
            arr[numCol++] = palabra;
        }
        //Crear un objeto del tipo Película - con memoria dinámica-
        arrPtrPelis[cant] = new Pelicula();
        /*Imprimir datos que se van cargando al arreglo
        cout << "iD " << arr[0] << " : \n";
        cout << "Titulo " << arr[1] << " : \n";
        cout << "Duracion " << arr[2] << " : \n";
        cout << "Calificacion " << arr[4] << " : \n";
        cout << "Genero " << arr[3] << " : \n";
        cout << "Oscars " << arr[5] << " : \n";
        */
            //Asignar los datos al objeto con apuntadores 
        arrPtrPelis[cant] -> setId(stoi(arr[0])); //stoi es string to int
        arrPtrPelis[cant] -> setNombre(arr[1]);
        arrPtrPelis[cant] -> setDuracion(stoi(arr[2]));
        arrPtrPelis[cant] -> setRating(stod(arr[4]));
        arrPtrPelis[cant] -> setGenero(arr[3]);
        arrPtrPelis[cant] -> setOscars(stoi(arr[5]));
        cant++;
    }
    archEnt.close();
}

void Peliculas::reporteCalificacion(double buscaRating){
    cout << "\n" <<endl ;
    cout << "*** REPORTE DE PELICULAS POR CALIFICACION " << buscaRating << " ***" << endl;
    cout << " id  Titulo  Duracion  Genero  Calificacion  Oscares" <<endl;
    for (int i=0; i<cant; i++){
        if (arrPtrPelis[i] -> getRating() == buscaRating ){
            cout << arrPtrPelis[i] -> mostrar() <<endl;
        }
    }
}

void Peliculas::reporteGenero(string buscaGenero){
    cout << "\n" <<endl ;
    cout << "*** REPORTE DE PELICULAS POR GENERO: " << buscaGenero << " ***" << endl;
    cout << " id  Titulo  Duracion  Genero  Calificacion  Oscares" <<endl;
    for (int i=0; i<cant; i++){
        if (arrPtrPelis[i] -> getGenero() == buscaGenero ){
            cout << arrPtrPelis[i] -> mostrar()  <<endl;
        }
    }
}

void Peliculas::setPtrPelicula(Pelicula *ptr){
    //cout << ptr<< endl;//saber si se estan cargando
    arrPtrPelis[cant++] = ptr;
}

Pelicula Peliculas::getPtrPelicula(int num){
    //validar que si exista la película
    Pelicula pel;
    if ( (num >= 0) && (num<= cant) ){
        return *arrPtrPelis[num];
    }
    else
        return pel;
}

void Peliculas::mostrar(){
    cout << " *** LISTA DE PELICULAS REGISTRADAS *** " <<endl;
    cout << " \n id  Titulo  Duracion  Genero  Calificacion  Oscares" <<endl;
    for (int i = 0; i < cant; i++){
        cout << arrPtrPelis[i] -> mostrar() << endl;
    }
    cout << "\n" <<endl;
}

void Peliculas::cambiarOscars(int idPeli, int oscares ){
    for (int i = 0; i < cant; i++){ //ciclo para buscar la peli con el id Dado
        if (arrPtrPelis[i]->getId() == idPeli){ //cuando la encuentra, entra en el if
            arrPtrPelis[i]->setOscars(oscares); //Modifica la cantidad de oscares con el método set
            cout << " \n id  Titulo  Duracion  Genero  Calificacion  Oscares" <<endl;
            cout << (arrPtrPelis[i]->mostrar()) << endl; //muestra la info de la peli actualizada
        }
    }
}

bool Peliculas::validarId(int idPeli){
    bool valid = false;
    int cont = 0;
    while ( (valid == false) && (cont < cant) ){
        if ( arrPtrPelis[cont]->getId() == idPeli ){
            valid = true;
        }
        cont++;
    }
    return valid;
}
#endif