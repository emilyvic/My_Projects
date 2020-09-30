#include<cmath>
class Tiempo{
public:
    Tiempo();
    Tiempo(int mins, int hours);

    void setMinutos(int mins);
    void setHoras(int hours);


    int getMinutos();
    int getHoras();
    int diferencia(Tiempo tiempo2);
private:
    int minutos, horas;
};

//Constructor Default
Tiempo::Tiempo(){
    minutos = 0;
    horas = 0;
}

//Constructor con parámetros
Tiempo::Tiempo(int mins, int hours){
    minutos = mins;
    horas = hours;
}

//Métodos de modificación.
void Tiempo::setMinutos(int mins){
    minutos = mins;
}

void Tiempo::setHoras(int hours){
    horas = hours;
}

//Métodos de acceso:
int Tiempo::getMinutos(){
    return minutos;
}

int Tiempo::getHoras(){
    return horas;
}

//Otros métodos de la clase
int Tiempo::diferencia(Tiempo tiempo2){
    return tiempo2.horas*60 + tiempo2.minutos - horas*60 + minutos;
}
