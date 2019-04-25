//
// Created by mauske on 25.04.19.
//

#include "CMyVector.h"

//CMyVector::CMyVector(int dimension) : dimension(dimension) {}

CMyVector::CMyVector() = default;

CMyVector::CMyVector(int dimension, double values[]) {
    this->dimension = dimension;

    this->values =
}

CMyVector::~CMyVector() = default;

int CMyVector::getDimension() const {
    return dimension;
}

void CMyVector::setDimension(int dimension) {
    CMyVector::dimension = dimension;
}
