#include <iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;
#include <algorithm>

template <class T>
void cambia(int a, int b, vector <T> &vect){ //pos a, pos b, y vector
    T aux;
    aux = vect[a];
    vect[a] = vect[b];
    vect[b] = aux;  
}

void imprimirPos(int &pos){
    if (pos != -1){
        cout << "El elemento buscado esta en la posicion " << pos <<endl;
    }else{
        cout << "El elemento buscado no existe dentro del arreglo " << pos <<endl;
    }
    pos = 0;
}

template<class T>
void imprime(int cant, vector <T> &vect){
    cout <<"\n";
    for (auto i = vect.cbegin(); i != vect.cend(); i++){
        cout << *i << " ";
    }
    cout <<endl;
}

void imprimeDatos(int c, int i, string complex){
    cout<<"Comparaciones: " << c 
        <<"     Intercambios: " << i  
        <<"     Complejidad: "<< complex
        <<endl;
}

template<class T>
void intercambio (int cant, vector<T> &vect){
    int compas = 0 , inter = 0;
    string complex = "O(n^2)";
    for (int j=0; j<cant-1; j++){
        for(int i =j+1; i<cant; i++){
            compas++;//contador de Comparaciones realizadas en la función
            if (vect[j] > vect[i]){
                cambia(j, i, vect);
                //imprime(cant, vect);
                inter ++; // contador de Intercambios realizados en la función
            }
        }
    }
    imprimeDatos(compas, inter, complex);
}

template<class T>
void Inserccion(int cant, vector<T> &vect){
    int compas = 0 , inter = 0;
    string complex = "O(n^2)";
    for (int i = 1; i <cant; i++){
        compas++;
        if (vect[i] < vect[i-1]){ //comparar con el elemento anterior de al lado
            cambia(i, i-1, vect);
            //imprime(cant, vect);
            inter ++;
            //imprime(cant, vect);
            if (i!=1){ //en la primera instancia no se puede comparar con elementos anteriores
                for (int j = i-1; j>0; j--){
                    compas++;
                    if (vect[j] < vect[j-1]){ //comparacion con elementos anteriores
                        cambia(j, (j-1), vect);
                        //imprime(cant, vect);
                        inter++;
                        //imprime(cant, vect);
                    }
                }
            }
        }
    }
    imprimeDatos(compas, inter, complex);
}

template<class T>
void merge(vector<T> &vect, int inicio, int mitad, int fin){
    vector<T> Izq; //lista de la izquierda
    vector<T> Der; //lista de la derecha
    int pos, cant1, cant2, i, j; //variables auxiliares
    pos =inicio; //posicion del arreglo original al que se va a arreglar
    cant1 = mitad-inicio + 1; //cant de elementos lista izq
    cant2 = fin - mitad; //cant de elementos lista der
    for (i=0; i<cant1; i++){
        Izq.push_back(vect[inicio+i]);//actualizar la lista Izq
    }

    for (j=0; j<cant2; j++){
        Der.push_back(vect[mitad+1+j]);//Actualizar la lista Der
    }

    i =0;
    j = 0;
    while( (i<cant1) && (j<cant2)){ //mientras el contador sea menor a la cantidad de elementos de Izq y j menor a cant2
        if(Izq[i] <= Der[j] ){
            vect[pos] = Izq[i];
            i++;
        }else{
            vect[pos] = Der[j];
            j++;
        }
        pos++;
    }
    //ayudan a vaciar los elementos pendientes despues de que se acabaron los elementos para comparar
    while(i<cant1){
        vect[pos] = Izq[i];
        i++;
        pos++;
    }
    while(j<cant2){
        vect[pos] = Der[j];
        j++;
        pos++;
    }
}

template<class T>
void mergeSort(vector<T> &vect, int beg, int fin, int &comp){
    comp++;
    if (beg < fin){ // beg = indice de izquierda  fin = indice de derecha
        int mitad = (beg+fin)/2; //medio para separar en 2 la lista (izquierda y derecha) Promedio entre inicio y fin
        //Para encontrar las primeras mitades
        mergeSort(vect, beg, mitad, comp);//primera lista: de inicio a medio
        mergeSort (vect, mitad+1, fin, comp); // segunda lista: de medio hasta fin
        merge (vect, beg, mitad, fin); // metodo para unir ambas listas: beg = 0, mitad = 0, fin = 1
    }
}

template<class T>
void dividir(vector<T> &vect, int inicio, int fin, int &pivot, int &comp){
    T pivVal = vect[inicio]; //el elemento pivote es el primer elemento
    int j = inicio; // posición de inicio

    for(int i=inicio+1; i<=fin; i++ ){ //recorrer el subvector de inicio a fin
        comp++;
        if(vect[i] < pivVal){ //si el elemento es menor al pivote
            j++;
            cambia(i,j,vect);//entonces ponerlo Antes del pivote
        }//de lo contrario dejarlo donde esta ()
    }
    pivot = j; //posicion de pivote
    cambia(inicio, pivot,vect); //inicializar el pivote con el elemento del inicio
}

template<class T>
void quickSort(vector<T> &vect, int inicio, int fin, int &comp){
    int pivot;
    if(inicio<fin){ // si hay más de un elemento por comparar
        dividir(vect, inicio, fin, pivot, comp);
        quickSort(vect, inicio, pivot-1, comp);
        quickSort(vect, pivot+1, fin, comp);
    }
}

template<class T>
void burbuja (int cant, vector<T> &vect){
    int compas = 0 , inter = 0;
    string complex = "O(n^2)";
    for(int i = cant; i>0; i--){
        for(int ele = 1; ele<i; ele++){
            compas++;//contador de Comparaciones realizadas en la función
            if (vect [ele] < vect [ele-1] ){
                cambia(ele, (ele-1), vect);
                //imprime(cant, vect);
                inter ++;// contador de Intercambios realizados en la función
            }
        }
    }
    imprimeDatos(compas, inter, complex);
}

template<class T>
void seleccionDirecta(int cant, vector<T> &vect){
    int compas = 0 , inter = 0; 
    string complex = "O(n^2)";
    int min;
    for (int i=0; i<cant; i++){
        min = i;
        for (int j =i+1 ; j<cant; j++){ // for para encontrar la posición del minimo elemento de todo el vector 
            compas++;//contador de Comparaciones realizadas en la función
            if ( vect[min] > vect[j]){
                min = j;
            }
        }
        cambia(min, i, vect);
        //imprime(cant, vect);
        inter++;// contador de Intercambios realizados en la función
    }
    imprimeDatos(compas, inter, complex);
}

template<class T>
int busqIter(int cant, vector<T> &vect){
    T ele; //Elemento que digite el usuario
    cout << "Digite el elemento a buscar"<<endl;
    cin >> ele;
    int i=0;
    int pos = -2;
    bool found = false;
    while( (found == false) && (i<cant)){
        if(vect[i] == ele){
            pos = i;
            found = true;
        }
        i++;
    }
    cout <<"Complejidad: O(n)"<<endl;
    return pos+1;
}

template<class T>
int busqBin(int cant, vector<T> vect){
    sort(vect.begin(), vect.end());//ordenar localmente (en este scope) los elementos del vector
    cout << "vector ordenado: ";
    imprime(cant, vect);
    T ele; //Elemento que digite el usuario
    cout << "Digite el elemento a buscar"<<endl;
    cin >> ele;  
    int low, high, mid;
    int result = -2;
    low = 0; // El primer elemento del vector 
    high = cant-1; // El ultimo elemento del vector

    while( (low <= high)){ //mientras no se haya encontrado el elemento o se llegue al final de las particiones de búsqueda
        mid = (high + low)/2; //la posicion de la mitad sera el promedio entre el menor y el mayor
        
        if (ele == vect[mid]){ //si el elemento de la mitad coincida
            result = mid; // retornar el elemento de la mitad
            break; //se ha encontrado elemento, entonces se puede salir
        }else if (ele > vect[mid]){// si el elemento que se busca es mayor a la mitad
                low = mid +1; // el elemento siguiente de la mitad será el nuevo menor
        }else{ //si el elemento que se busca es menor al de la mitad, 
                high = mid -1;//entonces el anterior al de la mitad será el nuevo mayor                
        }
    }
    cout<<"Complejidad: O(log(n))"<<endl;
    return result+1; //retorna el resultado
}

template<class T>
void crearVectorNum (int cant, vector<T> &vect){
    srand(time(NULL));
    for (int i=0; i <cant; i++){
        vect.push_back(rand () % 100);
    }
    cout << "Vector Registrado: ";
    imprime(cant, vect);
}

void crearVectorChar (int cant, vector<char> &vect){
    char c, c1;
    int r;
    srand(time(NULL));
    for (int i=0; i <cant; i++){
        r = rand () % 26;
        c = 'a' + r;
        vect.push_back(c);
    }
    cout << "Vector Registrado: ";
    imprime(cant, vect);
}

void crearVectorStr (int cant, vector<string> &vect){
    cout << "Digite sus elementos strings" <<endl;
    string ele;
    for (int i=0; i <cant; i++){
        cin >> ele;
        cout << "Nuevo Elemento: " << ele <<endl;
        vect.push_back(ele);
    }
    cout << "Vector Registrado: ";
    imprime(cant, vect);
}

int pideTipoDato(int &cant){
    int ans;
    ans = 0;
    cout<< "Digita la cantidad de elementos" <<endl;
    cin >> cant;

    while ((ans <1) || (ans>4) ){
        cout <<"Seleccione tipo de dato"
        << "\n 1. int"
        << "\n 2. Double"
        << "\n 3. String"
        << "\n 4. Char" 
        <<endl;
        cin >> ans;
    }
    return ans;
}

char menu(){ //Funcion que muestra el menu de acciones
    char ans;
    cout << "\n *** MENU *** " 
        << "\n a) Cambiar tipo de dato"
        << "\n b) Orden por Burbuja" 
        << "\n c) Orden por Seleccion"
        << "\n d) Orden por Intercambio" 
        << "\n e) Orden por Insercion"
        << "\n f) Búsquedas Iterativa"
        << "\n g) Busqueda Binaria"
        << "\n h) Orden por MergeSort"
        << "\n i) Orden por QuickSort"
        << "\n z) Salir"
        << endl;
    cin >> ans;
    cout << "\n" <<endl;
    return ans;
}

template<class T>
char metodoOrd(int cant,vector<T> &vect ){ //PROBAR
    unsigned t0, t1;
    bool salir = false;
    char opc;
    double time;
    int comp=0;
    vector<T> vect1, vect2;
    char ans = menu();//Pedir tipo de dato
    vect2 = vect;
    while( salir == false){
        vect1 = vect;
        switch (ans){
            case 'a'://cambiar tipo de dato
                vect.clear();
                vect1.clear();
                opc = 'n';
                salir = true;
                break;
            case 'd'://Metodo Intercambio
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                intercambio(cant,vect1);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl
                << "VECTOR RESULTADO: ";
                imprime (cant,vect1);
                break;
            case 'b': //Metodo burbuja
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                burbuja(cant,vect1);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl
                << "VECTOR RESULTADO: ";
                imprime (cant,vect1);
                break;
            case 'c'://Metodo Seleccion Directa
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                seleccionDirecta(cant, vect1);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl
                << "VECTOR RESULTADO: ";
                imprime (cant, vect1);
                break;
            case 'e'://Metodo por Inserccion
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                Inserccion(cant, vect1);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl
                << "VECTOR RESULTADO: ";
                imprime (cant, vect1);
                break;
            case 'f': //Metodo de busqueda iterativa
                int pos; 
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                pos = busqIter(cant, vect2);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl;
                imprimirPos(pos);
                break;
            case 'g': //Metodo de busqueda binaria
                t0 = clock();
                pos = busqBin(cant, vect);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout <<"Tiempo de Ejecucion: " << time << " segundos" <<endl
                << "VECTOR RESULTADO: ";
                imprimirPos(pos);
                break;
            case 'h'://Método Merge-Sort
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                mergeSort(vect1, 0, (cant-1), comp);
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout << "Comparaciones: " <<comp
                <<"     Tiempo de Ejecucion: " << time << " segundos" << "      Complejidad: O(nlog(n))"<<endl
                << "VECTOR RESULTADO: ";
                imprime(cant, vect1);
                break;
            case 'i'://método Quick-Sort
                int inicio;
                int fin;
                inicio = 0;
                fin = cant-1;
                cout << "VECTOR ORIGINAL: ";
                imprime(cant, vect); //imprimir vector original
                t0 = clock();
                quickSort(vect1, inicio, fin, comp);//Método Quick-Sort
                t1 = clock();
                time = (double (t1-t0)/CLOCKS_PER_SEC);
                cout << "Comparaciones: " <<comp
                <<"     Tiempo de Ejecucion: " << time << " segundos" <<"     Complejidad: O(nlog(n))"<<endl
                << "VECTOR RESULTADO: ";
                imprime(cant, vect1);
                break;
            case 'z':
                salir =true;
                opc = 's';
                break;
            default: //En el caso de que digite mal
                cout << "Digita nuevamente una opcion de respuesta" <<endl;
                break;
        }
        vect2 = vect1;
        vect1.clear();
        if(salir == false){
            ans = menu();
        }
    }
    return opc;
}

int main(){
    //Declarar los vectores
    srand(time(NULL));// Para evitar numeros repetidos
    vector <int> vectI;
    vector <double> vectD;
    vector <string> vectS;
    vector <char> vectC;

    int n; //Variable Cantidad de elementos del vector
    char ans; //Variable de respuesta
    ans = pideTipoDato(n); //Llamar a función para cambiar de dato
    char exit = 'n'; // variable para salir

    while(exit == 'n'){
        switch(ans){
            case 1: // Tipo: Int
                crearVectorNum(n, vectI);
                exit = metodoOrd(n, vectI);
            break;
            case 2:// Tipo: Double
                crearVectorNum(n, vectD);
                exit = metodoOrd(n, vectD);
            break;
            case 3:// Tipo: String
                crearVectorStr(n, vectS);
                exit = metodoOrd(n, vectS);
            break;
            case 4:// Tipo: Char
                crearVectorChar(n, vectC);
                exit = metodoOrd(n, vectC);
            break;
        }
        if(exit == 'n'){
            ans = pideTipoDato(n);
        }
    }
    cout <<"programa terminado con Exito" <<endl;
    return 0;
}
