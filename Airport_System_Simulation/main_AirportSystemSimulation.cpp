#include <iostream>
#include<string>
#include <fstream>
using namespace std;
#include"Pasajero.h"
#include"Vuelo.h"

//Funci�n que verifica si el vuelo que digit� el usuario existe.
bool buscaIdVuelo(int idABuscar, Vuelo arrVuelos[], int cantVuelos){
    for (int cont = 0; cont<cantVuelos; cont++){
        if (arrVuelos[cont].getIdVuelo() == idABuscar){
            return true;
        }
    }
    return false; //si recorri� todo el arreglo y no lo encontr�.
}

//Funci�n que muestra todos los pasajeros de un vuelo.
void consultaPasajeros(Vuelo arrVuelos[], int cantVuelos, Pasajero arrPasajeros[], int cantPasajeros){
    int numConsulta;
    Tiempo tempTiempo;

    cout << "Digite el numero de vuelo que desea buscar:" << endl;
    cin >> numConsulta;

    if (!buscaIdVuelo(numConsulta, arrVuelos, cantVuelos)){
    // si el usuario digit� un n�mero de vuelo inexistente imprime lo siguiente.
        cout<<"El vuelo que busca no existe";
    }
    else
        for (int cont = 0; cont < cantVuelos; cont++ ){
            if (arrVuelos[cont].getIdVuelo() == numConsulta){
                cout << "Los pasajeros registrados para el vuelo: " << endl;

                cout << arrVuelos[cont].getIdVuelo() << " de ";
                cout << arrVuelos[cont].getAerolinea() <<" desde ";
                cout << arrVuelos[cont].getOrigen() << " con destino a ";
                cout << arrVuelos[cont].getDestino() << " en la fecha ";
                cout << arrVuelos[cont].getFecha() << " que sale a las ";
                tempTiempo = arrVuelos[cont].getHoraSalida();
                cout << tempTiempo.getHoras()<< ":" << tempTiempo.getMinutos()<< " y llega a ";
                tempTiempo = arrVuelos[cont].getHoraLlegada();
                cout << tempTiempo.getHoras()<< ":" << tempTiempo.getMinutos()<< " son: " << endl;
                cout << " " << endl;
                cout << "    ID:" << "  " << "# VUELO:" << "  " << "NOMBRE:" << "  " << "TIPO:" << "  " << "ASIENTO:" << endl;
                cout << " " <<endl;
                for (int cont = 0; cont < cantPasajeros; cont++ ){
                    if (arrPasajeros[cont].getIdVuelo() == numConsulta){
                    cout << arrPasajeros[cont].getIdPasajero() << " ";
                    cout << arrPasajeros[cont].getIdVuelo() << " ";
                    cout << arrPasajeros[cont].getNombre() << " ";
                    cout << arrPasajeros[cont].getTipoPasajero() << " ";
                    cout << arrPasajeros[cont].getAsiento() << endl;
                }
            }
        }
    }
}

//Funci�n que agrega un nuevo elemento al arreglo de pasajeros.
void registrarNuevoPasajero(Pasajero arrPasajeros[], int &cantPasajeros){

    Pasajero newPassenger;
    int idP, idV;
    string nom, tipo, seat;

    cout << "Digite numero de pasajero (no. de pasaporte): " << endl;
    cin >> idP;
    cout << "Digite el nombre: " << endl;
    cin >> nom;
    cout << "Digite el n�mero de vuelo: " << endl;
    cin >> idV;
    cout << "Digite el tipo de pasajero: " << endl;
    cin >> tipo;
    cout << "Digite el n�mero de asiento: " << endl;
    cin >> seat;

    arrPasajeros[cantPasajeros].setIdPasajero(idP);
    arrPasajeros[cantPasajeros].setNombre(nom);
    arrPasajeros[cantPasajeros].setIdVuelo(idV);
    arrPasajeros[cantPasajeros].setTipoPasajero(tipo);
    arrPasajeros[cantPasajeros].setAsiento(seat);

    cantPasajeros++;
}

//Funci�n que agrega un nuevo elemento al arreglo de vuelos.
void registrarNuevoVuelo(Vuelo arrVuelos[], int &cantVuelos){
    Vuelo newFlight;
    Tiempo tempTiempo;
    int id, hour1, mins1, hour2, mins2;
    string aero, ori, dest, date;

    cout << "Digite numero de vuelo: " << endl;
    cin >> id;
    cout << "Digite aerol�nea: " << endl;
    cin >> aero;
    cout << "Digite ciudad de origen: " << endl;
    cin >> ori;
    cout << "Digite ciudad de destino: " << endl;
    cin >> dest;
    cout << "Digite la fecha: " << endl;
    cin >> date;
    cout << "Digite la hora de salida: " << endl;
    cin >> hour1 >> mins1;
    cout << "Digite la hora de llegada: " << endl;
    cin >> hour2 >> mins2;

    tempTiempo.setHoras(hour1);
    tempTiempo.setMinutos(mins1);
    tempTiempo.setHoras(hour2);
    tempTiempo.setMinutos(mins2);

    arrVuelos[cantVuelos].setIdVuelo(id);
    arrVuelos[cantVuelos].setAerolinea(aero);
    arrVuelos[cantVuelos].setOrigen(ori);
    arrVuelos[cantVuelos].setDestino(dest);
    arrVuelos[cantVuelos].setFecha(date);
    arrVuelos[cantVuelos].setHoraSalida(tempTiempo);
    arrVuelos[cantVuelos].setHoraLlegada(tempTiempo);

    cantVuelos++;
}

//Funci�n para cargar los datos de un archivo de texto (BaseDeDatosVuelos) a un arreglo.
void cargaDatosArrVuelos(Vuelo arrVuelos[], int &cantVuelos){
    Tiempo tempTiempo1, tempTiempo2;
    ifstream archVuelos;
    int id;
    string aero, ori, dest, date;
    int hours1, mins1, hours2, mins2;

    archVuelos.open("BaseDatosVuelos.txt"); //Igual al nombre del archivo .txt.
    cantVuelos = 0;

    while (archVuelos >> id >> aero >> ori >> dest >> date >> hours1 >> mins1 >> hours2 >> mins2 ) {
        tempTiempo1.setHoras(hours1);
        tempTiempo1.setMinutos(mins1);
        tempTiempo2.setHoras(hours2);
        tempTiempo2.setMinutos(mins2);

        arrVuelos[cantVuelos].setIdVuelo(id);
        arrVuelos[cantVuelos].setAerolinea(aero);
        arrVuelos[cantVuelos].setOrigen(ori);
        arrVuelos[cantVuelos].setDestino(dest);
        arrVuelos[cantVuelos].setFecha(date);
        arrVuelos[cantVuelos].setHoraSalida(tempTiempo1);
        arrVuelos[cantVuelos].setHoraLlegada(tempTiempo2);
        cantVuelos++;
    }
    archVuelos.close();
}

//Funci�n que muestra los datos del arreglo de Vuelos.
void muestraDatosVuelos (Vuelo arrVuelos[], int cantVuelos){
       Tiempo tempTiempo1, tempTiempo2;

    cout << "# VUELO:" << "  " << "AEROLINEA:" << "  " << "ORIGEN:" << "  " << "DESTINO:" << "  " << "FECHA:" << "  " << "HORA SALIDA:" << "  " << "HORA LLEGADA:"<< "  " << "DURACI�N:" << endl;
    cout << " " <<endl;

    for (int cont = 0; cont < cantVuelos; cont++){
        cout << arrVuelos[cont].getIdVuelo() << " ";
        cout << arrVuelos[cont].getAerolinea() << " ";
        cout << arrVuelos[cont].getOrigen() << " ";
        cout << arrVuelos[cont].getDestino() << " ";
        cout << arrVuelos[cont].getFecha() << " ";
        tempTiempo1 = arrVuelos[cont].getHoraSalida();
        cout << tempTiempo1.getHoras()<< ":" << tempTiempo1.getMinutos()<< " - ";
        tempTiempo2 = arrVuelos[cont].getHoraLlegada();
        cout << tempTiempo2.getHoras()<< ":" << tempTiempo2.getMinutos()<< " ";
        cout << tempTiempo1.diferencia(tempTiempo2)<<" mins. " << endl;
    }
}

//Funci�n para cargar los datos de un archivo de texto (BaseDeDatosPasajeros) a un arreglo.
void cargaDatosArrPasajeros(Pasajero arrPasajeros[], int &cantPasajeros){
    ifstream archPasajeros;
    int idP, idV;
    string nom, tipo, seat;

    archPasajeros.open("BaseDatosPasajeros.txt"); //Igual al nombre del archivo .txt.
    cantPasajeros = 0;

    while (archPasajeros >> idP >> nom  >> idV >> tipo >> seat){
        arrPasajeros[cantPasajeros].setIdPasajero(idP);
        arrPasajeros[cantPasajeros].setNombre(nom);
        arrPasajeros[cantPasajeros].setIdVuelo(idV);
        arrPasajeros[cantPasajeros].setTipoPasajero(tipo);
        arrPasajeros[cantPasajeros].setAsiento(seat);
        cantPasajeros++;
    }
    archPasajeros.close();
}

//Funci�n que muestra los datos del arreglo de Pasajeros.
void muestraDatosPasajeros (Pasajero arrPasajeros[], int cantPasajeros){
cout << "    ID:" << "  " << "# VUELO:" << "  " << "NOMBRE:" << "  " << "TIPO:" << "  " << "ASIENTO:" << endl;
cout << " " <<endl;

    for (int cont = 0; cont < cantPasajeros; cont++){
        cout << arrPasajeros[cont].getIdPasajero() << " ";
        cout << arrPasajeros[cont].getIdVuelo() << " ";
        cout << arrPasajeros[cont].getNombre() << " ";
        cout << arrPasajeros[cont].getTipoPasajero() << " ";
        cout << arrPasajeros[cont].getAsiento() << endl;
    }
}

int main(){
    char opcion;

    Vuelo arrVuelos[20];
    int cantVuelos;

    Pasajero arrPasajeros[20];
    int cantPasajeros;

    cargaDatosArrVuelos(arrVuelos, cantVuelos);
    cargaDatosArrPasajeros(arrPasajeros, cantPasajeros);
    do{
        cout << " " << endl;
        cout << "Seleccione una de las siguientes opciones:" << endl;
        cout << " " << endl;
        cout << " A) Consultar lista de vuelos" << endl;
        cout << " B) Consultar lista de Pasajeros" <<endl;
        cout << " C) Registrar un nuevo vuelo" <<endl;
        cout << " D) Registrar un nuevo pasajero" <<endl;
        cout << " E) Consulta pasajeros de un vuelo determinado" <<endl;
        cout << " F) Exit" <<endl;
        cout << " " << endl;

        cin >> opcion;

        switch(opcion){
            case 'A':{
                cout << " " << endl ;
                cout << " Vuelos Disponibles hasta el momento: " << endl ;
                cout << " " << endl ;
                muestraDatosVuelos (arrVuelos, cantVuelos);
                break; }

            case 'B':{
                cout << " " << endl ;
                cout << " Pasajeros Registrados hasta el momento: " << endl ;
                cout << " " << endl ;
                muestraDatosPasajeros (arrPasajeros, cantPasajeros);
                break;}

            case 'C':{
                registrarNuevoVuelo(arrVuelos, cantVuelos);
                muestraDatosVuelos (arrVuelos, cantVuelos);
                break;}

            case 'D':{
                registrarNuevoPasajero(arrPasajeros, cantPasajeros);
                muestraDatosPasajeros (arrPasajeros, cantPasajeros);
                break;}

            case 'E':{
                consultaPasajeros(arrVuelos, cantVuelos, arrPasajeros,  cantPasajeros);
                break;}
        }
    }while(opcion != 'F');
    return 0;
}
