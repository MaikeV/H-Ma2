//
// Created by mauske on 30.05.19.
//

#include "C_DGLSolver.h"


CMyVector C_DGLSolver::ableitungen(CMyVector y, double x) {
    if (this->isSimple) {
        return this->f_DGL_System(y, x);
    } else if (!this->isSimple){
        std::vector<double> v;
        CMyVector tmp(y.getDimension(), v);

        tmp.setValue(this->f_DGL_nterOrdnung(y, x), y.getDimension() - 1);

        for(int i = 0; i < y.getDimension() - 1; i++)
            tmp.setValue(y[i + 1], i);

        return tmp;
    }
}

CMyVector C_DGLSolver::euler(double xStart, double xEnd, int steps, CMyVector yStart) {
    double h = (xEnd - xStart) / steps;
    std::cout << "h = " << h << std::endl;

    int counter = 0;
    double x = 0;

    std::vector<double> v;

    CMyVector y = yStart;
    CMyVector yStrich(yStart.getDimension(), v);

    while(counter < steps) {
        yStrich = ableitungen(yStart, xStart);

        x = xStart + counter * h;
        y = y + h * ableitungen(y, x);

        std::cout << "Schritt " << counter << ": " << std::endl;
        std::cout << "x = " << x << std::endl;
        std::cout << "y(" << x << ") = ( ";

        for(int i = 0; i < y.getDimension(); i++)
             std::cout << y[i] << " ";

        std::cout << " )" << std::endl;
        std::cout << "y'(" << x << ") = ( ";

        for(int i = 0; i < y.getDimension(); i++)
            std::cout << yStrich[i] << " ";

        std::cout << ")" << std::endl << std::endl;
        counter++;
    }

    std::cout << "Ende bei Schritt " << counter << ": " << std::endl;
    std::cout << "x = " << x + h << std::endl;

    for(int i = 0; i < y.getDimension(); i++)
        std::cout << "y = " << y[i] << std::endl;

    return yStrich;
}

CMyVector C_DGLSolver::heun(double xStart, double xEnd, int steps, CMyVector yStart) {
    double h = (xEnd - xStart) / steps;
    std::cout << "h = " << h << std::endl;

    int counter = 0;
    int x = 0;

    while(counter < steps) {
        x = xStart + counter * h;
        CMyVector yTest = yStart + h * ableitungen(yStart, x);
        CMyVector yMittel = 0.5 * (ableitungen(yStart, x) + ableitungen(yTest, x));

        yStart = yStart + h * yMittel;

        counter++;
    }

    return yStart;
}
