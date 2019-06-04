//
// Created by mauske on 30.05.19.
//

#ifndef PRAKTIKUM3_C_DGLSOLVER_H
#define PRAKTIKUM3_C_DGLSOLVER_H


#include "CMyVector.h"

class C_DGLSolver {
private:
    CMyVector (*f_DGL_System)(CMyVector y, double x);
    double (*f_DGL_nterOrdnung)(CMyVector y, double x);
    bool isSimple;

    CMyVector ableitungen(CMyVector y, double x);


public:
    C_DGLSolver(CMyVector (*f_DGL_System)(CMyVector y, double x)){
        this->f_DGL_System = f_DGL_System;
        this->isSimple = true;

    }

    C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVector y, double x)) {
        this->f_DGL_nterOrdnung = f_DGL_nterOrdnung;
        this->isSimple = false;
    }

    CMyVector euler(double xStart, double xEnd, int steps, CMyVector yStart);
    CMyVector heun(double xStart, double xEnd, int steps, CMyVector yStart);
};


#endif //PRAKTIKUM3_C_DGLSOLVER_H
