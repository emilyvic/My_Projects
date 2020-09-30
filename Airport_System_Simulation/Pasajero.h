class Pasajero{
public:
    Pasajero();
    Pasajero(int idP, int idV, string nom, string tipo, string seat);

    void setIdPasajero(int idP);
    void setIdVuelo(int idV);
    void setNombre(string nom);
    void setTipoPasajero(string tipo);
    void setAsiento(string seat);
    void setViajeroFrecuente(bool freq);

    int getIdPasajero();
    int getIdVuelo();
    string getNombre();
    string getTipoPasajero();
    string getAsiento();
    //bool getViajeroFrecuente();

private:
    int idPasajero, idVuelo;
    string nombre, tipoPasajero, asiento;
    //bool viajeroFrecuente;
};

//Constructor Default
Pasajero::Pasajero(){
    idPasajero = 0;
    idVuelo = 0;
    nombre = "-";
    tipoPasajero = "-";
    asiento = "-";
    //viajeroFrecuente = false;
}

//Constructor con parámetros
Pasajero::Pasajero(int idP, int idV, string nom, string tipo, string seat){
    idPasajero = idP;
    idVuelo = idV;
    nombre = nom;
    tipoPasajero = tipo;
    asiento = seat;
    //viajeroFrecuente = freq;
}

//Métodos de modificación.
void Pasajero::setIdPasajero(int idP){
    idPasajero = idP;
}
void Pasajero::setIdVuelo(int idV){
    idVuelo = idV;
}
void Pasajero::setNombre(string nom){
    nombre = nom;
}
void Pasajero::setTipoPasajero(string tipo){
    tipoPasajero = tipo;
}
void Pasajero::setAsiento(string seat){
    asiento = seat;
}
//void Pasajero::setViajeroFrecuente(bool freq){
  //  viajeroFrecuente = freq;
//}

//Métodos de acceso:
int Pasajero::getIdPasajero(){
    return idPasajero;
}
int Pasajero::getIdVuelo(){
    return idVuelo;
}
string Pasajero::getNombre(){
    return nombre;
}
string Pasajero::getTipoPasajero(){
    return tipoPasajero;
}
string Pasajero::getAsiento(){
    return asiento;
}
