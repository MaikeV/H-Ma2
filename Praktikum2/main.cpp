#include "CMyVector.h"
#include "CMyMatrix.h"

CMyVector f(CMyVector j) {
    std::vector<double> v;
    CMyVector vector(3, v);

    vector.setValue(j.getValue(0)* j.getValue(1) * exp(j.getValue(2)), 0);
    vector.setValue(j.getValue(1) * j.getValue(2) * j.getValue(3), 1);
    vector.setValue(j.getValue(3), 2);

    return vector;
}

CMyVector gradient(CMyVector x, double (*function)(CMyVector x)) {
    std::vector<double> v;
    CMyVector vector(x.getDimension(), v);
    double h = 1e-8;

    double fktX = function(x);

    for(int index = 0; index < x.getDimension(); index++) {
        double tmp = x[index];
        x.setValue(x[index]+ h, index);
        vector.setValue(((function(x) - fktX) / h), index);
        x.setValue(tmp,index);
    }

    return vector;
}

CMyMatrix jacobi(CMyVector x, CMyVector (*f)(CMyVector x)) {
    std::vector<CMyVector*> vector;
    CMyMatrix jacobi(f(x).getDimension(), x.getDimension(), vector);

    double h = 1e-4;

    CMyVector fkt = f(x);

    for(int m = 0; m < jacobi.getMRows(); m++) { //3 f
        for(int n = 0; n < jacobi.getNColumns(); n++) { //4 x
            double tmp = x[n];
            x.setValue(x[n]+ h, n);
            double y = (f(x).getValue(m) - fkt.getValue(m)) / h;
            x.setValue(tmp,n);

            jacobi.setValue(m, n, y);
        }
    }
    return jacobi;
}


int main() {
    std::vector<double> v;

    CMyVector vector1(2, v);
    vector1.setValue(0.200000, 0);
    vector1.setValue(-2.100000, 1);

    CMyVector vector2(3, v);
    vector2.setValue(0.00000, 0);
    vector2.setValue(0.00000, 1);
    vector2.setValue(0.00000, 2);

    CMyVector vector3(2, v);
    vector3.setValue(1.000000, 0);
    vector3.setValue(2.000000, 1);

    CMyVector vector4(2, v);
    vector4.setValue(3.000000, 0);
    vector4.setValue(4.000000, 1);

    CMyVector vectorJ(4, v);
    vectorJ.setValue(1, 0);
    vectorJ.setValue(2, 1);
    vectorJ.setValue(0, 2);
    vectorJ.setValue(3, 3);

    char menuChoice = '0';

    std::vector<CMyVector*> vector;

    CMyMatrix matrix1(2, 2, vector);
    matrix1.setValue(0, 0, 1);
    matrix1.setValue(0, 1, 2);
    matrix1.setValue(1, 0, 3);
    matrix1.setValue(1, 1, 4);

    CMyMatrix matrix2(2, 2, vector);
    CMyMatrix matrixJ(3, 4, vector);

    CMyVector result(2, v);

    while(menuChoice != '4') {
        std::cout << std::endl;
        std::cout << "1) Basistests" << std::endl << "2) Jacobi-Matrix" << std::endl << "3) Newton-Verfahren" << std::endl << "4) Beenden" << std::endl << "?- ";
        std::cin >> menuChoice;

        switch(menuChoice) {
            case '1':
                std::cout << "Matrix: " << std::endl;
                std::cout << "( " << matrix1.getValue(0, 0) << " " << matrix1.getValue(0, 1) << " )" << std::endl << "( " << matrix1.getValue(1, 0) << " " << matrix1.getValue(1, 1) << " )" << std::endl << std::endl;

                result = matrix1*vector3;

                std::cout << "Matrix * Vector = " << std::endl;
                std::cout << "( " << result.getValue(0) << " " << result.getValue(1) << " )" << std::endl << std::endl;

                std::cout << "Determinante:" << std::endl;
                std::cout << matrix1.calcDet() << std::endl << std::endl;

                matrix2 = matrix1.invers();
                std::cout << "Inverse:" << std::endl;
                std::cout << "( " << matrix2.getValue(0, 0) << " " << matrix2.getValue(0, 1) << " )" << std::endl << "( " << matrix2.getValue(1, 0) << " " << matrix2.getValue(1, 1) << " )" << std::endl << std::endl;
                break;
            case '2':
                matrixJ = jacobi(vectorJ, f);

                std::cout << "( " << matrixJ.getValue(0, 0) << " " << matrixJ.getValue(0, 1) << " " << matrixJ.getValue(0, 2) << " " << matrixJ.getValue(0, 3) << " )" << std::endl;
                std::cout << "( " << matrixJ.getValue(1, 0) << " " << matrixJ.getValue(1, 1) << " " << matrixJ.getValue(1, 2) << " " << matrixJ.getValue(1, 3) << " )" << std::endl;
                std::cout << "( " << matrixJ.getValue(2, 0) << " " << matrixJ.getValue(2, 1) << " " << matrixJ.getValue(2, 2) << " " << matrixJ.getValue(2, 3) << " )" << std::endl << std::endl;
                break;
            case '3':

                break;
            case '4':
                break;
            default:
                std::cout << "Ungueltige Eingabe" << std::endl << std::endl;
                break;
        }
    }

    return 0;
}