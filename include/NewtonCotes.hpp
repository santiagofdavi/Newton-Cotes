/* NEWTON-COTES IN C++

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 2nd, 2022 */

#ifndef NEWTONCOTES_H
#define NEWTONCOTES_H

double avaliacao_funcao(double &x);

double denominador(int &grau);

void coeficientes(int &grau, int vec[]);

void print(unsigned &i, double &x, double &y, double &c);

void newton_cotes(double &a, double &b, int &grau, int m);

#endif