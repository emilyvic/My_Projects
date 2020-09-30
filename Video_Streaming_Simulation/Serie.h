#include<iostream>
using namespace std;
#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Episodio.h"

class Serie : public Video{ 
    protected:
        Episodio *arrPtrEpisodios[20]; //hasta un máximo de 20 episodios para cada serie. 
        int cant; //cantidad de episodios
    public:
        Serie();//constructor por feaul.
        Serie(int quant, int iD, string nombre, string genero, int duracion , double rating, Episodio *arrPtrEpisodios[]); //con parámetros clase video
        //~Serie(); //destructor

        string mostrar(); //muestra la info de la serie
        void setEpisodio(int num, Episodio *epi); //cambia el episodio num
        Episodio getEpisodio(int num); // muestra info de episodio de una idserie num
        void setCantEpi(int quant); // cambiar la cant de episodios
        int getCantEpi(); //retorna cant de episodios
        void lookEpiXRating(double lookRating);
        double calcularPromedio();//se sobrecarga en base a las calificaciones de los episodios y se calcula el promedio.
};

Serie::Serie(){
    cant = 0;      
    Episodio *epis[cant];
    *arrPtrEpisodios[cant] = *epis[cant];
}

Serie::Serie( int quant, int iD, string nombre, string genero , int duracion, double rating, Episodio *arrPtrEpisodios[]) : Video( iD,  nombre,  genero,  duracion, rating){
    cant = quant;
    for(int cont = 0; cont < cant; cont++){
        arrPtrEpisodios[cont] = nullptr;
    }
}

void Serie::setEpisodio(int num, Episodio *epi){
    arrPtrEpisodios[num] = epi; 
}

Episodio Serie::getEpisodio(int num){
    Episodio epi;
    //if ( (num >= 0) && (num <=cant)){
      //return epi;
        return *arrPtrEpisodios[num];
}

void Serie::setCantEpi(int quant){
    cant = quant;
}

int Serie::getCantEpi(){
    return cant;
}

void Serie::lookEpiXRating(double lookRating){
    cout << "*** EPISODIOS CON CALIFICACION " << lookRating << " *** "<< endl;
    for(int j = 0; j < cant; j++){
        if ( ( arrPtrEpisodios[j] -> getRatingEpi() ) == lookRating){
            //cout << "Si encontre" <<endl;
            cout << arrPtrEpisodios[j]->mostrar() <<endl;
        }
    }
}

double Serie::calcularPromedio(){
    //Inicilizar las variables
    double suma = 0;
    double promedio = 0;

    if (cant > 1){ //si la serie tiene más de un episodio
        for (int i = 0; i < cant; i++){
            suma =  ( *arrPtrEpisodios[i] + suma ); //aplicada la sobrecarga
            // sobrecargado el operador + en la clase Episodio
        }
        promedio = suma/cant;
    }
    else if(cant == 0){ //si la serie no tiene episodios
        cout << "La serie no tiene episodios" <<endl;
        promedio = 0;
    }
    else if(cant == 1){ //si la serie solo tiene un episodio
        promedio = (arrPtrEpisodios[0]->getRatingEpi()); // el promedio sera igual al rating del único episodio
    }
    return promedio;
}


string Serie::mostrar(){
    return to_string(iD) + " " + nombre + " " + to_string(duracion) + " " + genero + " " + to_string(rating) + " " + to_string(cant); 
}

#endif