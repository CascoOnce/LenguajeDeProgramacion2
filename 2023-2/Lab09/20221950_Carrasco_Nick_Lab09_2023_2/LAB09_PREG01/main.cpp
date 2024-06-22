/* 
 * File:   main.cpp
 * Author: Casco
 *
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Flota.h"
using namespace std;

int main(int argc, char** argv) {
    Flota Unidades;
    
    Unidades.cargaflota();
    
    
//    Unidades.cargapedidos();
    Unidades.muestracarga();
    
//    vector<int> vInt(10, 55);
//    cout << vInt.size() << endl;
//    cout << vInt.capacity() << endl;
//    for(int x: vInt){
//        cout << setw(5) << x;
//    }
//    cout << endl;
//    vInt.assign(5, 101);
//    cout << vInt.size() << endl;
//    cout << vInt.capacity() << endl;
//    for(int x: vInt){
//        cout << setw(5) << x;
//    }
    return 0;
}

