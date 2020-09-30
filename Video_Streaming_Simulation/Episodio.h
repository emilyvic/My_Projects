#include <iostream>
#include <string>
using namespace std;

#ifndef EPISODIO_H
#define EPISODIO_H

class Episodio {
    private:
        string titulo;
        int temporada;
        double ratingEpi;
    public:
        Episodio();
        Episodio(string title, int temp, double rating);
        void setTitulo(string title);        
        void setTemporada(int temp);
        void setRatingEpi(double rating);

        string getTitulo();
        int getTemporada();
        double getRatingEpi();

        string mostrar();

        //sobrecarga del operador +
        double operator + (double dPuntuacion){
            return dPuntuacion + ratingEpi;
        }
};

Episodio::Episodio(){
    titulo = "Ingrese Titulo";
    temporada = 0;
    ratingEpi = 0.0;
}

Episodio::Episodio(string title, int temp, double rating){
    titulo = title;
    temporada = temp;
    ratingEpi = rating;
}

void Episodio::setTitulo(string title){
    titulo = title;
}

void Episodio::setTemporada(int temp){
    temporada = temp;
}

void Episodio::setRatingEpi(double rating){
    ratingEpi = rating;
}

string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}

double Episodio::getRatingEpi(){
    return ratingEpi;
}

string Episodio::mostrar(){
    return  ("Titulo: " + titulo + "\n Temporada: " + to_string(temporada) + "\n Calificacion: " + to_string(ratingEpi));
}

#endif