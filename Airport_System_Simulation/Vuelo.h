#include"Tiempo.h"

class Vuelo{
public:
    Vuelo();
    Vuelo(int id, string ori, string aero, string dest, string date, Tiempo heur1, Tiempo heur2);

    void setIdVuelo(int id);
    void setAerolinea(string aero);
    void setOrigen(string ori);
    void setDestino(string dest);
    void setFecha(string date);
    void setHoraSalida(Tiempo heur1);
    void setHoraLlegada(Tiempo heur2);

    int getIdVuelo();
    string getAerolinea();
    string getOrigen();
    string getDestino();
    string getFecha();
    Tiempo getHoraSalida();
    Tiempo getHoraLlegada();

private:
    int idVuelo;
    string origen, aerolinea, destino, fecha;
    Tiempo horaSalida, horaLlegada;
};

//Constructor Default
Vuelo::Vuelo(){
    Tiempo h;
    idVuelo = 0;
    aerolinea = "-";
    origen = "-";
    destino = "-";
    fecha = "-";
    horaSalida = h;
    horaLlegada = h;
}

//Constructor con par�metros
Vuelo::Vuelo(int id, string ori, string aero, string dest, string date, Tiempo heur1, Tiempo heur2){
    idVuelo = id;
    aerolinea = aero;
    origen = ori;
    destino = dest;
    fecha = date;
    horaSalida = heur1;
    horaLlegada = heur2;
}

//M�todos de modificaci�n.
void Vuelo::setIdVuelo(int id){
    idVuelo = id;
}
void Vuelo::setAerolinea(string aero){
    aerolinea = aero;
}
void Vuelo::setOrigen(string ori){
    origen = ori;
}
void Vuelo::setDestino(string dest){
    destino = dest;
}
void Vuelo::setFecha(string date){
    fecha = date;
}
void Vuelo::setHoraSalida(Tiempo heur1){
    horaSalida = heur1;
}
void Vuelo::setHoraLlegada(Tiempo heur2){
    horaLlegada = heur2;
}

//M�todos de acceso:
int Vuelo::getIdVuelo(){
    return  idVuelo;
}
string Vuelo::getAerolinea(){
    return aerolinea;
 }

string Vuelo::getOrigen(){
    return origen;
}
string Vuelo::getDestino(){
    return destino;
}
string Vuelo::getFecha(){
    return fecha;
}
Tiempo Vuelo::getHoraSalida(){
    return horaSalida;
}

Tiempo Vuelo::getHoraLlegada(){
    return horaLlegada;
}
