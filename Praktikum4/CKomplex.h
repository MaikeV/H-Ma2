//
// Created by mauske on 16.06.19.
//

#ifndef PRAKTIKUM4_CKOMPLEX_H
#define PRAKTIKUM4_CKOMPLEX_H


#include <cmath>

class CKomplex {
private:
    double re;
    double im;
public:
    CKomplex(){
        this->re = 0;
        this->im = 0;
    }

    CKomplex(double a, double b) {
        this->re = a;
        this->im = b;
    }

    CKomplex(double phi) {
        this->re = cos(phi);
        this->im = sin(phi);
    }

    double getRe() const {
        return re;
    }

    double getIm() const {
        return im;
    }

    double abs() {
        return sqrt(pow(this->getRe(), 2) + pow(this->getIm(), 2));
    }
};

CKomplex operator+(CKomplex first, CKomplex second) {
    double a = first.getRe() + second.getRe();
    double b = first.getIm() + second.getIm();

    return CKomplex(a, b);
}

CKomplex operator*(CKomplex first, CKomplex second) {
    //(a + bj) * (c + dj)
    // ac + adj + bcj + bd * pow(j, 2)
    // ac + adj + bcj - bd

    double a = (first.getRe() * second.getRe()) - (first.getIm() * second.getIm());
    double b = (first.getRe() * second.getIm()) + (first.getIm() * second.getRe());

    return CKomplex(a, b);
}

CKomplex operator*(double lambda, CKomplex comp) {
    double a = lambda * comp.getRe();
    double b = lambda * comp.getIm();

    return CKomplex(a, b);
}

#endif //PRAKTIKUM4_CKOMPLEX_H
