#include "CMyVector.h"

double f(CMyVector vectorF) {
    if (vectorF.getDimension() != 2) {
        return 0;
    }

    double x = vectorF.getValue(0);
    double y = vectorF.getValue(1);

    double f = sin(x * y) + sin(x) + cos(y);

    return f;
}

double g(CMyVector vectorG) {
    if (vectorG.getDimension() != 3) {
        return 0;
    }

    double x1 = vectorG.getValue(0);
    double x2 = vectorG.getValue(1);
    double x3 = vectorG.getValue(2);

    double g = -(2 * pow(x1, 2) - 2 * x1 * x2 + pow(x2, 2) + pow(x3, 2) - 2 * x1 - 4 * x3);

    return g;
}

CMyVector gradient(CMyVector x, double (*funktion)(CMyVector x)) {
    std::vector<double> v;
    double h = pow(10, -8);

    for(int index = 0; index < x.getDimension(); index++) {
        CMyVector temp = x;
        x.setValue(x.getValue(index) + h, index);
        v.at(index) = (funktion(x) - funktion(temp)) / h;
    }

    CMyVector vector(x.getDimension(), v);
    return vector;
}

int main() {
    std::vector<double> v;
    v.push_back(2);
    v.push_back(3);

    CMyVector vector1(2, v);

    CMyVector vector2(2, v);
    vector2.setValue(4, 0);
    vector2.setValue(5, 1);

    CMyVector vector3(2, v);

    CMyVector res = vector1 + vector2;

    std::cout << res.getDimension() << " " << res.getLength() << std::endl;

    for(int index = 0; index < res.getDimension(); index++) {
        std::cout << res.getValue(index) << std::endl;
    }

    CMyVector res2(2, v);

    std::cout << res2.getDimension();
    res2 = gradient(vector3, f);

    std::cout << res2.getValue(0) << " " << res2.getValue(1) << std:: endl;

    return 0;
}