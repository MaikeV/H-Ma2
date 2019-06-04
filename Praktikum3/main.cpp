#include <iostream>
#include "C_DGLSolver.h"

CMyVector f(CMyVector y, double x) {
    std::vector<double> v;
    CMyVector tmp(y.getDimension(), v);

    tmp.setValue(2 * y[1] - x * y[0], 0);
    tmp.setValue(y[0] * y[1] - 2 * pow(x, 3), 1);

    return tmp;
}

double g(CMyVector y, double x) {
    
}

int main() {
    char select = '0';
    char select2 = '0';

    std::vector<double> v;
    CMyVector ySimple(2, v);
    ySimple.setValue(0, 0);
    ySimple.setValue(1, 1);
    C_DGLSolver dgl(f);

    while (select != '3') {
        std::cout << std::endl;
        std::cout << "1) Euler" << std::endl << "2) Heun" << std::endl << "3) Beenden" << std::endl << "?- ";
        std::cin >> select;

        switch(select) {
            case '1':
                std::cout << "1) Einfacher Ordnung" << std::endl << "2) n-ter Ordnung" << std::endl << "?- ";
                std::cin >> select2;

                if (select2 == '1') {
                    dgl.euler(0, 2, 100, ySimple);
                } else if (select2 == '2') {
                    //dgl.euler();
                } else {
                    std::cout << "Falsche Eingabe";
                }

                break;
            case '2':
                std::cout << "1) Einfacher Ordnung" << std::endl << "2) n-ter Ordnung" << std::endl << "?- ";
                std::cin >> select2;

                if (select2 == '1') {
                    dgl.heun(0, 2, 100, ySimple);
                } else if (select2 == '2') {
                    //dgl.heun();
                } else {
                    std::cout << "Falsche Eingabe";
                }

                break;
            case '3':
                break;
            default:
                std::cout << "Falsche Eingabe.";
        }
    }


    return 0;
}