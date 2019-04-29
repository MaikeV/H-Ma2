//
// Created by mauske on 25.04.19.
//

#pragma once
#ifndef AUFGABE1_CMYVECTOR_H
#define AUFGABE1_CMYVECTOR_H

#include <iostream>
#include <vector>
#include <cmath>



class CMyVector {
private:
    int dimension;
    std::vector<double> values;

public:
    CMyVector(int dimension, std::vector<double> vector);

    int getDimension() const;
    double getValue(int position) const;
    void setValue(double value, int position);
    double getLength();
};

CMyVector operator+(CMyVector a, CMyVector b);
CMyVector operator*(double lambda, CMyVector a);


#endif //AUFGABE1_CMYVECTOR_H
