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
        x = xStart + counter * h;
        y = y + h * ableitungen(y, x);

        yStrich = ableitungen(y, x);

        if(this->isSimple) {
            std::cout << "Schritt " << counter + 1 << ": " << std::endl;
            std::cout << "x = " << x << std::endl;
            std::cout << "y = ( ";

            for(int i = 0; i < y.getDimension(); i++)
                std::cout << y[i] << " ";

            std::cout << " )" << std::endl;
            std::cout << "y' = ( ";

            for(int i = 0; i < y.getDimension(); i++)
                std::cout << yStrich[i] << " ";

            std::cout << ")" << std::endl << std::endl;
        }

        counter++;
    }

    std::cout << "Ende bei: " << std::endl;
    std::cout << "x = " << x + h << std::endl;

    for(int i = 0; i < y.getDimension(); i++)
        std::cout << "y = " << y[i] << std::endl;

    if(!this->isSimple)
        std::cout << "Abweichung: " << 0.5 - y[0] << std::endl;

    return yStrich;
}

CMyVector C_DGLSolver::heun(double xStart, double xEnd, int steps, CMyVector yStart) {
    double h = (xEnd - xStart) / steps;
    std::cout << "h = " << h << std::endl;

    int counter = 0;
    double x = 0;
    double xTmp = 0;

    std::vector<double> v;

    CMyVector y = yStart;
    CMyVector yStrich(yStart.getDimension(), v);

    while(counter < steps) {
        x = xStart + counter * h;
        xTmp = x + h;
        yStrich = ableitungen(y, x);
        CMyVector yTest = y + h * ableitungen(y, x);
        CMyVector yMittel = 0.5 * (ableitungen(y, x) + ableitungen(yTest, xTmp));

        y = y + h * yMittel;

        if(this->isSimple) {
            std::cout << "Schritt " << counter << ": " << std::endl;
            std::cout << "x = " << x << std::endl;

            std::cout << "yTest = ( ";

            for(int i = 0; i < y.getDimension(); i++)
                std::cout << yTest[i] << " ";

            std::cout << ")" << std::endl;

            std::cout << "yMittel = ( ";

            for(int i = 0; i < y.getDimension(); i++)
                std::cout << yMittel[i] << " ";

            std::cout << ")" << std::endl;
            std::cout << "y(" << x << ") = ( ";

            for(int i = 0; i < y.getDimension(); i++)
                std::cout << y[i] << " ";

            std::cout << ")" << std::endl;
            std::cout << "y'(" << x << ") = ( ";

            for(int i = 0; i < y.getDimension(); i++)
                std::cout << yStrich[i] << " ";

            std::cout << ")" << std::endl << std::endl;
        }

        counter++;
    }

    std::cout << "Ende bei: " << std::endl;
    std::cout << "x = " << x + h << std::endl;

    for(int i = 0; i < y.getDimension(); i++)
        std::cout << "y = " << y[i] << std::endl;

    if(!this->isSimple)
        std::cout << "Abweichung: " << 0.5 - y[0] << std::endl;

    return yStart;
}
