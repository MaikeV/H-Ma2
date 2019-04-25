#include <iostream>
#include "CMyVector.h"

int main() {
    std::vector<double> v;



    CMyVector vector(2, v);

    vector.setDimension(2);

    int dim = vector.getDimension();

    std::cout << dim;
}