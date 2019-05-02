#include "CMyVector.h"

double f(CMyVector vectorF) {
    if (vectorF.getDimension() != 2) {
        return 0;
    }

    double x = vectorF[0];
    double y = vectorF[1];

    return sin(x * y) + sin(x) + cos(y);;
}

double g(CMyVector vectorG) {
    if (vectorG.getDimension() != 3) {
        return 0;
    }

    double x1 = vectorG[0];
    double x2 = vectorG[1];
    double x3 = vectorG[2];

    return -(2 * pow(x1, 2) - 2 * x1 * x2 + pow(x2, 2) + pow(x3, 2) - 2 * x1 - 4 * x3);
}

double t(CMyVector vectorT) {
    if(vectorT.getDimension() != 2) {
        return 0;
    }

    return pow(vectorT[0], 2) + vectorT[1];
}

CMyVector gradient(CMyVector x, double (*funktion)(CMyVector x)) {
    std::vector<double> v;
    CMyVector vector(x.getDimension(), v);
    double h = 1e-8;

    double fktX = funktion(x);

    for(int index = 0; index < x.getDimension(); index++) {
        x.setValue(x[index]+ h, index);
        vector.setValue(((funktion(x) - fktX) / h), index);
    }

    return vector;
}

int main() {
    std::vector<double> v;

    CMyVector vector1(2, v);
    vector1.setValue(1, 0);
    vector1.setValue(2, 1);

    CMyVector vector2(2, v);
    vector2.setValue(4, 0);
    vector2.setValue(5, 1);


    CMyVector vector4(3, v);
    vector4.setValue(2, 0);
    vector4.setValue(5, 1);
    vector4.setValue(3, 2);

    CMyVector res = vector1 + vector2;

    std::cout << "v1 + v2 = (" << vector1[0] << " " << vector1[1] << ") + (" << vector2[0] << " " << vector2[1] << ") = (" << res[0] << " " << res[1] << "). Length: " << res.getLength() << std::endl;

    CMyVector resF = gradient(vector1, f);
    CMyVector resG = gradient(vector4, g);
    CMyVector resT = gradient(vector1, t);

    std::cout << "f(x, y): " << resF[0] << " " << res[1] << std:: endl;
    std::cout << "g(x1, x2, x3): " << resG[0] << " " << resG[1] << std:: endl;
    std::cout << "t(x, y): " << resT[0] << " " << resT[1] << std::endl;

    return 0;
}