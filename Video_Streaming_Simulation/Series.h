#include<iostream>
#ifndef SERIES_H
#define SERIES_H

using namespace std;
#include <fstream>
#include "Serie.h"
#include"Episodio.h"
#include <sstream>

class Series{
    private:
        Serie *arrPtrSeries[150]; //arreglo de apuntadores de series.
        int cantSeries; //cant de series registradas
    public:
        //constructor default
        Series();
        void leerArchivo(); //funcion para leer series de un archivo y cargarlas en arrPtrSeries
        void mostrar(); //Muestra el reporte de todas las series registradas con su promedio.
        void reporteCalificacion(double buscaRating); //muestra todas las series con una calificación es específico
        void reporteGenero(string buscaGenero); //muestra todas las series de un género determinado
        void lookEpiXidSerie(int idSerie); //desplegar todos los espisodios de una serie dado su iD
        void lookEpiXidRating(int idSerie, double buscaRating); //desplegar todos los espisodios de una serie dado su iD y una calificacion
        void setPtrSeries(Serie *ptr); 
        Serie getPtrSeries(int numt);
        void anadirEpi(int idSerie, Episodio *epi);
        bool validarId(int idSerie);
        void calcularPromedioSeries();
};

Series::Series(){
    cantSeries = 0;
    for (int cont = 0; cont<200; cont++){
        arrPtrSeries[cont] = nullptr;
    }
}

void Series::leerArchivo(){
    fstream archEnt;
    int contLineasEpisodio = 0; //contador de episodios;
    int arrIdSerie[150];//variable para almacenar el id de la serie de cada episodio
    Episodio *arrPtrEpisodio[150]; //arreglo de apuntadores de los episodios de todas las series
    Episodio *arrPtrEpi[100]; //arreglo de apuntadores de la serie registrada una por una 
    archEnt.open("ArchivoEpisodios.csv");
    string arr[6];
	string arr2[6];
    string linea, palabra;
    
    cout <<" *** CARGANDO LOS SIGUIENTES EPISODIOS... ***" << endl;
    cout << "\n" <<endl ;
    while(getline(archEnt, linea)){
        cout //<< "Linea #" 
        << contLineasEpisodio //<< " contiene: " 
        << " " << linea <<endl; //mostrar cada reglón leído
        stringstream s(linea); //para separar palabras

        int cont = 0; //incializar el contador

        while(getline (s, palabra, ',')){ //almacenar palabra por palabra
            arr[cont++] = palabra;
        }

        //crear nueva instancia de la clase Episodio a registrar para cada episodio que se va leyendo desde el archivo
        arrPtrEpisodio[contLineasEpisodio] = new Episodio();
        /*
        //Solo para verificar que si se hayan cargado los datos al arreglo
        cout << "Id de la Serie: " << arr[0] << "\n";
        cout << "Titulo: " << arr[1] <<  "\n";
        cout << "Temporada: " << arr[2] <<  "\n";
        cout << "Calificacion: " << arr[3] <<  "\n";
        cout << "\n" <<endl ;
       */
       //guardar el id de todas las series que se cargan en el arreglo de idSerie
        arrIdSerie[contLineasEpisodio] = stoi(arr[0]);

        //asignar los atributos del episodio al objeto temporal que cree
        arrPtrEpisodio[contLineasEpisodio] -> setTitulo(arr[1]);
        arrPtrEpisodio[contLineasEpisodio] -> setTemporada(stoi(arr[2]));
        arrPtrEpisodio[contLineasEpisodio] -> setRatingEpi(stod(arr[3]));

        //verificar que se haya actualizado el objeto correctamente
        //cout << "Info de Episodio #" << to_string(contLineasEpisodio) << " \n" << arrPtrEpisodio[contLineasEpisodio] -> mostrar() <<endl;
        //cout << "\n" <<endl ;

        //aumentar el contador de episodios
        contLineasEpisodio++;
    } //hasta que ya no hayan más líneas de info que leer en el archivo
    archEnt.close();

    //Solo para mostrar todos los episodios cargados en una lista
    cout << "\n" <<endl ;
    cout << "*** SERIES CARGADAS EN EL ARREGLO ***" <<endl;
    //Imprimir direcciones de memoria
   /* for (int i = 0; i < contEpisodio; i++){
        cout << arrPtrEpisodio[i] <<endl;
    }*/
    
    //REPORTE DE SERIES

    archEnt.open("ArchivoSeries.csv");
    cantSeries = 0; //inicilizar la cantidad de series en 0
    cout <<" *** REGISTRANDO LAS SIGUIENTES SERIES... ***" << endl;
    while(getline(archEnt, linea)){
        cout //<< "La linea #" 
        << cantSeries  //<< " contiene:  " 
        << " " << linea <<endl;

        stringstream s(linea);
        int contParametros = 0, cantEpisodios;
        while(getline(s, palabra, ',')){
            arr2[contParametros++] = palabra;
        }
        /*Imprimir datos de cada serie mientras se va cargando
        cout << "iD: " << arr2[0] << "\n";
        cout << "Titulo: " << arr2[1] << "\n";
        cout << "Duracion: " << arr2[2] << "\n";
        cout << "Calificacion: " << arr2[4] << "\n";
        cout << "Genero: " << arr2[3] << "\n";
        cout << "Cantidad de Episodios: " << arr2[5] << "\n";
        */
        //inicializar arreglo de episodios de la serie
        for(int i=0; i<20; i++){
            arrPtrEpi[i] = nullptr;
        }
        //crear un nuevo objeto Serie en la memoria dinámica e inicializarlo con los parámetros
        arrPtrSeries[cantSeries] = new Serie(stoi(arr2[5]),stoi(arr2[0]), arr2[1], arr2[3], stoi(arr2[2]), stod(arr2[4]), arrPtrEpi);
        //en vez de esto:
        /*
        arrPtrSeries[cant] -> setId(stoi(arr[0])); //stoi es string to int
        arrPtrSeries[cant] -> setNombre(arr[1]);
        arrPtrSeries[cant] -> setDuracion(stoi(arr[2]));
        arrPtrSeries[cant] -> setRating(stod(arr[4]));
        arrPtrSeries[cant] -> setGenero(arr[3]);
        arrPtrSeries[cant] -> setCantEpi(stoi(arr[5]));
        cant++;
        */

       //buscar episodios pertenecientes a una serie en particular
        //cout << " *** EPISODIOS QUE SE CARGAN A LA SERIE *** " << endl;
       int numEpiSerie = 0; //inicializar contador de episodios de una serie en particular
       for (int i = 0; (i < contLineasEpisodio) && (numEpiSerie < (stoi(arr2[5]))); i++ ){
           if(arrIdSerie[i] == (stoi(arr2[0])) ){ //si el id del episodio es igual al id de la serie
                arrPtrSeries[cantSeries]->setEpisodio(numEpiSerie, arrPtrEpisodio[i]); //entonces asigna ese episodio dentro del objeto serie
				//cout << arrPtrEpisodio[i] -> mostrar() << endl;
                numEpiSerie++; //incrementar la cantidad de episodios de esa serie 
           }
           //asignar el episodio a la serie correspondiente
       }
        //cout << "\n" <<endl ;
        cantSeries++;
    } //hasta que ya no hayan más lineas que leer en el archivo
    archEnt.close();
}

void Series::reporteCalificacion(double buscaRating){
    cout << "\n" <<endl ;
    cout << "*** REPORTE DE SERIES POR CALIFICACION " << buscaRating << " ***" << endl;
    cout << " id  Titulo  Duracion  Genero  Calificacion  Cant Episodios" <<endl;
    for (int i=0; i<cantSeries; i++){
        if (arrPtrSeries[i] -> getRating() == buscaRating ){
            cout << arrPtrSeries[i] -> mostrar() <<endl;
        }
    }
    cout << "\n" <<endl ;
}

void Series::reporteGenero(string buscaGenero){
    cout << "\n" <<endl ;
    cout << "*** REPORTE DE PELICULAS POR GENERO " << buscaGenero << " ***" << endl;
    cout << " id  Titulo  Duracion  Genero  Calificacion  Cant. Episodios" <<endl;
    for (int i=0; i<cantSeries; i++){
        if (arrPtrSeries[i] -> getGenero() == buscaGenero ){
            cout << arrPtrSeries[i] -> mostrar() << endl;
        }
   }
    cout << "\n" <<endl ;
}

void Series::setPtrSeries(Serie *ptr){
    cout <<ptr<< endl; //saber si se estan cargando
    arrPtrSeries[cantSeries++] = ptr;
    cantSeries++;
}

Serie Series::getPtrSeries(int num){
    Serie ser;
    if ( (num >= 0) && (num<= cantSeries)){
        return *arrPtrSeries[num];
    }
    else
    {
        return ser;
    }
}

void Series::lookEpiXidSerie(int idSerie){
    Episodio epik;
    int cantEpi;
    cout <<"*** LISTA DE EPISODIOS PARA SERIE #" << idSerie << " *** " << endl;
    cout <<"Nombre de la serie: ";

    for (int i = 0; i < cantSeries; i++){ //un ciclo for para recorrer el arreglo de series
        if ( arrPtrSeries[i]->getId() == idSerie ){ //buscar la serie en base al iD
            cout << ((arrPtrSeries[i] -> getNombre())) << endl; //Imprimir el nombre de la serie
            cantEpi = arrPtrSeries[i] -> getCantEpi(); //obtener la cantidad de episodios de la serie
            if (cantEpi != 0){
                for(int j = 0; j<cantEpi; j++ ){ //buscar los episodios de acuerdo a la cantidad de episodios particular de cada serie
                    epik = arrPtrSeries[i]->getEpisodio(j); //pedir los episodios
                    cout << epik.mostrar()<<endl; //mostrar los episodios
                }
            }
            else{
                cout << "La serie " <<  ((arrPtrSeries[i] -> getNombre())) << " no tiene episodios registrados" <<endl;
            }
        }
    }
}

void Series::lookEpiXidRating(int idSerie, double buscaRating){
    Episodio epik;
    int cantEpi;
    cout << "\n" <<endl;
    cout <<"*** LISTA DE EPISODIOS PARA SERIE #" << idSerie << " *** " << endl;
    cout << "\n" <<endl;
    cout <<"Nombre de la serie: ";

    for (int i = 0; i < cantSeries; i++){ //un ciclo for para recorrer el arreglo de series
        if ( arrPtrSeries[i]->getId() == idSerie ){ //buscar la serie en base al iD
            cout << ((arrPtrSeries[i] -> getNombre())) << endl; //Imprimir el nombre de la serie
            cantEpi = arrPtrSeries[i] -> getCantEpi(); //obtener la cantidad de episodios de la serie
            if (cantEpi != 0){ //verificar que la serie tiene episodios
                arrPtrSeries[i]->lookEpiXRating(buscaRating);
            }
            else{
                cout << "La serie " <<  ((arrPtrSeries[i] -> getNombre())) << "no tiene episodios registrados" <<endl;
            }
        }
    }
}

void Series::mostrar(){
    cout <<"*** LISTA DE SERIES REGISTRADAS *** " <<endl;
    cout << " \n id  Titulo  Duracion  Genero  Calificacion  Cant De Episodios" <<endl;
    for (int cont = 0; cont <cantSeries; cont++){
        cout << arrPtrSeries[cont] -> mostrar() <<endl;
    }
}

bool Series::validarId(int idSerie){
    bool valid = false;
    int cont = 0;
    while ( (valid == false) && (cont < cantSeries) ){
        if ( arrPtrSeries[cont]->getId() == idSerie ){
            valid = true;
        }
        cont++;
    }
    return valid;
}

void Series::anadirEpi(int idSerie, Episodio *epi){
    int cantEpi; //variable para almacenar cant de episodios de la serie
    for (int i = 0; i < cantSeries; i++){ //un ciclo for para recorrer el arreglo de series
        if ( arrPtrSeries[i]->getId() == idSerie ){ //buscar la serie en base al iD
            cantEpi = (arrPtrSeries[i]->getCantEpi()); //extraer la cantidad de episodios de la serie.
            arrPtrSeries[i] -> setEpisodio(cantEpi, epi); //añadir el episodio nuevo a la serie en la siguiente posicion
            arrPtrSeries[i] -> setCantEpi(cantEpi+1); //actualizar e incrementar la cantidad de episodios en la serie 
        }
    }
}

//Calcular la calificacion de cada serie en base a sus episodios
void Series::calcularPromedioSeries(){
    cout <<"*** MOSTRANDO SERIES CON CALIFICACIONES PROMEDIO ***" <<endl;
    cout << " \n id  Titulo  Duracion  Genero  Calificacion  Cant De Episodios" <<endl;

    for (int i = 0; i < cantSeries; i++){ //recorrer todas y cada una de las series del arreglo cargado
        arrPtrSeries[i]->setRating( arrPtrSeries[i]->calcularPromedio() ); //calcular su promedio y reasignar el rating
        cout << arrPtrSeries[i]->mostrar() <<endl; //mostrar toda la lista de series con el nuevo rating
    }
}

#endif