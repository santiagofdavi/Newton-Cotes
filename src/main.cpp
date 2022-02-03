/* NEWTON-COTES IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 2nd, 2022 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "NewtonCotes.hpp"

using namespace std;

int main(){

    double a;
    double b;
    int grau;
    int m;

    cin >> a >> b >> grau >> m;

    newton_cotes(a, b, grau, m);

    return 0;

}