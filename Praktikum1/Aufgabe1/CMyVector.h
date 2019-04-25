//
// Created by mauske on 25.04.19.
//

#pragma once
#ifndef AUFGABE1_CMYVECTOR_H
#define AUFGABE1_CMYVECTOR_H

class CMyVector {
private:
    int dimension;
    double values[];

public:
    CMyVector(int dimension, double values[]);
    CMyVector();

    int getDimension() const;

    void setDimension(int dimension);
    virtual ~CMyVector();
};


#endif //AUFGABE1_CMYVECTOR_H
