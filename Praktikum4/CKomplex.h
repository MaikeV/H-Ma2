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

    CKomplex operator+(CKomplex second) {
        double a = this->getRe() + second.getRe();
        double b = this->getIm() + second.getIm();

        return CKomplex(a, b);
    }

    CKomplex operator*(CKomplex second) {
        //(a + bj) * (c + dj)
        // ac + adj + bcj + bd * pow(j, 2)
        // ac + adj + bcj - bd

        double a = (this->getRe() * second.getRe()) - (this->getIm() * second.getIm());
        double b = (this->getRe() * second.getIm()) + (this->getIm() * second.getRe());

        return CKomplex(a, b);
    }

    CKomplex operator*(double lambda) {
        double a = lambda * this->getRe();
        double b = lambda * this->getIm();

        return CKomplex(a, b);
    }
};

#endif //PRAKTIKUM4_CKOMPLEX_H
