#include <iostream>
#include <string>
using namespace std;

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"

class Pelicula : public Video{
    private:
        int oscars;
    public:
        Pelicula();
        Pelicula(int, int, string, string, int, double);
        
        void setOscars(int);
        int getOscars();
        string mostrar();
};

Pelicula::Pelicula(){
    oscars = 0;
}

Pelicula::Pelicula(int oscares, int iD, string nombre, string genero, int duracion, double rating) : Video(iD, nombre, genero, duracion, rating){
    oscars = oscares;
}

void Pelicula::setOscars(int oscares){
    oscars = oscares;
}

int Pelicula::getOscars(){
    return oscars;
}


string Pelicula:: mostrar(){
    return (to_string(iD) + " " + nombre + " " + to_string(duracion) + " " + genero + " " + to_string(rating) + " " + to_string(oscars));
}

#endif