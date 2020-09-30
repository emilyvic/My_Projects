#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

string alfaNumerico(int guarismo){
    string alfa;
    switch(guarismo){
        case 10:
            alfa = "A";
        break;
        case 11:
            alfa = "B";
        break;
        case 12:
            alfa = "C";
        break;
        case 13:
            alfa = "D";
        break;
        case 14:
            alfa = "E";
        break;        
        case 15:
            alfa = "F";
        break;
    }
    return alfa;
}

void imprime(vector <string> &vect){
    //cout << "TAMANO: " << vect.size()<<endl;
    for( int cont=( vect.size() - 1); cont>=0; cont--){
        cout << vect.at(cont);
    }
    cout <<endl;
}

void conversion10(int base, int num, vector <string> &vectRes){
    int cociente, mod;
    while(num/base != 0){
        cociente = num/base;
        vectRes.push_back(to_string(num % base));
        num = num/base;
    }
    vectRes.push_back(to_string(num));
    imprime(vectRes);
}

void conversionMayor(int base, int num, vector <string> &vectRes){
    int mod;
    while(num/base != 0){
        mod = num % base;
        //cout <<"MOD: " << mod <<endl;
        if(mod >= 10){
            vectRes.push_back(alfaNumerico(mod));
        }else{
            vectRes.push_back(to_string(mod));
        }
        num = num/base;
    }
    if(num >= 10){
        vectRes.push_back(alfaNumerico(num));
    }else{
        vectRes.push_back(to_string(num));
    }
    imprime(vectRes);
}

int main(){
    double num;
    int base = 0;
    vector <string> result;
    cout<<"Digite el numero que quiere convertir"<<endl;
    cin>>num;
    while( (base>16) || (base<1) ){ //verificar que la base este entre 2 y 16
        cout << "Digite una base" << endl;
        cin>>base;
    }
    if(base <= 10){
        conversion10(base, num, result);
    }else{
        conversionMayor(base, num, result);
    }
return 0;
}
