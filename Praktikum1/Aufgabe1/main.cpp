#include "CMyVector.h"

int main() {
    CMyVector vector;
    vector.setDimension(2);


    int dim = vector.getDimension();

    std::cout << dim << " " << vector.getValue(1);
}