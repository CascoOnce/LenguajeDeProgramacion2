/* 
 * File:   main.cpp
 * Author: AdiosCasco 20221950
 *
 * Created on 24 de mayo de 2024, 05:07 AM
 */

#include <iostream>

using namespace std;
#include "Cliente.h"

int main(int argc, char** argv) {
    int i;
    class Cliente arrCliente[200];
    ifstream file ("Clientes.csv", ios::in);
    for (i = 0; file >> arrCliente[i]; i++);
    cout << i;
    return 0;
}

