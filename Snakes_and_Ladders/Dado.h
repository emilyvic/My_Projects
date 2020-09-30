//  Clase Dado
//  Created by Invitado on 5/14/20. Copyright © 2020 Invitado. All rights reserved.  

#include <iostream>
using namespace std;

#include <time.h>
#include <stdlib.h>

class Dado{
public:
    Dado();
    int getTiro();
};

Dado::Dado(){
    srand( time(0));
}


int Dado::getTiro(){
    return  (rand() % 6) + 1;
}