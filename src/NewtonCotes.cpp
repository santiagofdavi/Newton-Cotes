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

double avaliacao_funcao(double &x){

    return pow(M_E,-1*x)+3*x*x+x+1;

}

double denominador(int &grau){

    double d[10] = {2, 6, 8, 90, 288, 840, 17280, 28350, 89600, 598752};
    return d[grau - 1];

}

void coeficientes(int &grau, int vec[]){

    int c[35] = {1, 1, 4, 1, 3, 7, 32,
                 12, 19, 75, 50, 41, 216,
                 27, 272, 751, 3577, 1323,
                 2989, 989, 5888, -928, 10496,
                 -4540, 2857, 15741, 1080, 19344,
                 5778, 16067, 106300, -48525,
                 272400, -260550, 427368};

    int p = floor(grau * (grau + 2) / 4 + grau % 2);
    int n12 = floor((grau + 1) / 2) - 1;

    for(unsigned i = 0; i <= n12; i++){

        vec[i] = c[p + i - 1];
        vec[grau - i] = c[p + i - 1];

    }

    if(grau % 2 == 0){

        vec[grau / 2] = c[p + grau / 2 - 1];

    }

}

void print(unsigned &i, double &x, double &y, int &c){

    cout << setprecision(5) << fixed << "\t" << i << "     " << x << "     " 
         << y << "     " << c << endl;

}

void newton_cotes(double &a, double &b, int &grau, int m){

    cout << "\nIntegracao via Newton-Cotes com polinomio de grau " << grau << endl << endl;
    cout << "\ti\tx(i)\t    y(i)      c(i)" << endl;

    int Info = 0;

    double Integral = 0;

    int cotes[grau + 1];
    
    coeficientes(grau, cotes);

    if(m % grau != 0 || m < 0){

        Info -= 10;
        cout << "Info = " << Info << endl << endl;

        return;

    }

    double h = (b - a) / m;
    int j = -1;

    double x;
    double y;
    int k;

    for(unsigned i = 0; i < m + 1; i++){

        x = a + i * h;
        y = avaliacao_funcao(x);
        j++;
        k = cotes[j];

        if(i % grau == 0 && i != 0 && i != m){

            k += k;
            j = 0;

        }

        Integral += y * k;

        print(i, x, y, k);

    }

    Integral *= grau * h / denominador(grau);

    cout << endl << "Integral = " << Integral << endl;
    cout << "Info = " << Info << endl << endl;

}