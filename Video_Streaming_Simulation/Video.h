#include <iostream>
#include <string>
using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video{
    public:
        Video();
        Video(int iD, string nombre, string genero, int duracion, double rating);
        void setId(int);
        void setNombre(string);
        void setGenero(string);
        void setDuracion(int);
        void setRating(double);

        int getId();
        string getNombre();
        string getGenero();
        int getDuracion();
        double getRating();

        string mostrar();
    protected:
        string nombre, genero;
        int iD, duracion;
        double rating;
};

Video::Video(){
    iD = 0;
    nombre = "Digite titulo";
    genero = "Digite genero";
    duracion = 0;
    rating = 0.0;
}

Video::Video(int iD, string nombre, string genero, int duracion, double rating){
    this -> iD = iD;
    this -> nombre = nombre;
    this -> genero = genero;
    this -> duracion = duracion;
    this -> rating = rating;
}

void Video::setId(int iD){
    this -> iD = iD;
}

void Video::setNombre(string nombre){
    this -> nombre = nombre;    
}

void Video::setGenero(string genero){
    this -> genero = genero;
}

void Video::setDuracion(int duracion){
    this -> duracion = duracion;   
}

void Video::setRating(double rating){
    this -> rating = rating;    
}

int Video::getId(){
    return iD;
}

string Video::getNombre(){
    return nombre;
}

string Video::getGenero(){
    return genero;
}

int Video::getDuracion(){
    return duracion;
}

double Video::getRating(){
    return rating;
}

string Video::mostrar(){
    return (to_string(iD) + "\n Titulo: " + nombre + "\n Duracion: " + to_string(duracion) + "\n Genero: " + genero);
}

#endif