//Emilia Jacome

#include<iostream>
using namespace std;
#include "Peliculas.h"
#include "Series.h"

int menu(){ //funcion que muestra el Menú y recibe la opción del usuario
    int ans;
    cout << "-- MENU --"
         << "\n 1. Leer peliculas desde Archivo"
         << "\n 2. Registrar Pelicula"
         << "\n 3. Reporte de todas las peliculas"
         << "\n 4. Reporte  de peliculas por Calificacion"
         << "\n 5. Reporte de peliculas por genero"
         << "\n 6. Cambiar Oscares de una pelicula"
         << "\n 7. Leer series desde Archivo"
         << "\n 8. Reporte de todas las series"
         << "\n 9. Reporte de Series por calificacion"
         << "\n 10. Reporte de Series por genero"
         << "\n 11. Calcular calificacion de Series en base a promedio de calificacion de Episodios "
         << "\n 12. Registrar episodio a una serie"
         << "\n 13. Mostrar episodios de una determinada serie"
         << "\n 14. Mostrar episodios de una determinada serie dada una calificacion"
         << "\n 0. Salir" <<endl;
    cin >> ans;
    cout << "\n" <<endl;
    return ans;
}

void registraEpisodio(Episodio &datosEpi){ //funcion que pide al usuario los datos del episodio y los asigna a los atributos del objeto
    int temporada; 
    string title; 
    double grade;

    cout << "Ingresa el titulo: "<<endl;
    cin.ignore();
    getline(cin, title);
    datosEpi.setTitulo(title);
 

    cout << "Ingresa la temporada: "<<endl;
    cin >> temporada;
    datosEpi.setTemporada(temporada);


    cout << "Ingresa Calificacion: "<<endl;
    cin >> grade;
    datosEpi.setRatingEpi(grade);
}

void registraPeli(Pelicula &datosPeli, Peliculas &arrPelis){
    int iD, length, oscars, year; 
    string title, genre, director; 
    double grade;

    cout << "Ingresa el iD: "<<endl;
    cin >> iD;
    cin.ignore();
    datosPeli.setId(iD);


    cout << "Ingresa el Titulo: "<<endl;
    getline(cin, title);
    datosPeli.setNombre(title);

    cout << "Ingresa Duracion (mins): "<<endl;   
    cin >> length;
    cin.ignore(); 
    datosPeli.setDuracion(length);

    cout << "Ingresa Genero: "<<endl;
    getline(cin,  genre);
    datosPeli.setGenero(genre);

    cout << "Ingresa Calificacion: "<<endl;
    cin >> grade;
    cin.ignore(); 
    datosPeli.setRating(grade);

    cout << "Ingresa Oscars: "<<endl;
    cin >> oscars;  
    datosPeli.setOscars(oscars);
    cin.ignore(); 
}

main(){
    Pelicula *ptrPeli, peli; //crear el pointer del objeto Pelicula
    Episodio *ptrEpi, epi; //crar pointer de Episodio y variable episodio.
    Serie *ser; //crear pointer de tipo serie
    Peliculas pelis; // crear objeto Peliculas se manda a llamar al constructor default.
    Series sers; //crear un objeto de tipo series
    double lookRating;
    string lookGenre;
    bool valid = false; // variable para validar si el iD digitado es correcto
    int idSerie, idPeli, oscares, cantTemp; //variables especificas que se utilizan en cada opción
    int opc = menu(); //mandar a llamar a la función Menu()

    while(opc != 0){
        switch (opc){
            case 1:
                pelis.leerArchivo();
                break;
            case 2:
                cout << " *** Ingresa los datos de la Pelicula *** " << endl;
                ptrPeli = new Pelicula();
                registraPeli(*ptrPeli, pelis);
                pelis.setPtrPelicula(ptrPeli);
                pelis.mostrar();
                break;
            case 3:
                pelis.mostrar();
                break;
            case 4:
                cout << "Digite la calificacion que desea buscar:";
                cin >> lookRating;
                pelis.reporteCalificacion(lookRating);
                break;
            case 5:
                cout << "Digite el genero que desea buscar:";
                cin >> lookGenre;
                pelis.reporteGenero(lookGenre);
                break;
            case 6:
                cout << "Digite el id de la Pelicula que desea modificar:";
                valid = false;
                while (valid == false){
                    cin >> idPeli;
                    valid = pelis.validarId(idPeli);
                    if (valid == false){
                        cout << "Id invalido, vuelve a digitar iD" <<endl;
                    }
                }
                cout << "Digite la cantidad de Oscares de un pelicula:";
                cin >> oscares;
                pelis.cambiarOscars(idPeli, oscares);
                break;
            case 7:
                sers.leerArchivo();
                break;
            case 8:
                sers.mostrar();
                break;
            case 9:
                cout << "Digite la calificacion que desea buscar:";
                cin >> lookRating;
                sers.reporteCalificacion(lookRating);
                break;
            case 10:
                cout << "Digite el genero que desea buscar:";
                cin >> lookGenre;
                sers.reporteGenero(lookGenre);
                break;
            case 11:
                cout << "CALCULANDO CALIFICACION PROMEDIO:"<< endl;
                sers.calcularPromedioSeries();
                break;
            case 12:
                cout << "Digite el iD de la serie a la que desea anadir un episodio" <<endl;
                valid = false;
                while (valid == false){
                    cin >> idSerie;
                    valid = sers.validarId(idSerie);
                    if (valid == false){
                        cout << "Id invalido, vuelve a digitar iD" <<endl;
                    }
                }
                cout << " ** Ingresa los datos del episodio **" << endl;
                ptrEpi = new Episodio();
                registraEpisodio(*ptrEpi);
                cout << "REGISTRANDO EL SIGUIENTE EPISODIO..." << " \n" << ptrEpi->mostrar() <<endl;
                sers.anadirEpi(idSerie, ptrEpi);
                sers.lookEpiXidSerie(idSerie);
                break;
            case 13: 
                valid = false;
                cout <<"Digite el id de la serie: ";
                while (valid == false){
                    cin >> idSerie;
                  valid = sers.validarId(idSerie);
                  if (valid == false){
                      cout << "Id invalido, vuelve a digitar iD" <<endl;
                  }
                }
                sers.lookEpiXidSerie(idSerie);//mostrar episodios de una determinada serie.
                break;
            case 14:
                valid = false;
                cout <<"Digite el id de la serie: "<<endl;
                while (valid == false){
                    cin >> idSerie;
                    cin.ignore(); 
                    valid = sers.validarId(idSerie);
                    if (valid == false){
                      cout << "Id invalido, vuelve a digitar iD" <<endl;
                    }
                }
                cout << "Digite la calificacion que desea buscar:";
                cin >> lookRating;
                cin.ignore(); 
                sers.lookEpiXidRating( idSerie, lookRating); 
                break;
            case 0:
                break;
            default: 
                cout << "Digita nuevamente una opcion de respuesta" <<endl;
                break;
        }
        cout << "\n" <<endl;
        opc = menu();
    }
    return 0;
}
