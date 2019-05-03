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

void gradientenverfahren(CMyVector x, double (*function)(CMyVector x), double lambda = 1.0) {
    std::vector<double> v;
    CMyVector xNew(x.getDimension(), v);
    CMyVector xTest(x.getDimension(), v);
    CMyVector grad(x.getDimension(), v);
    int i = 0;

    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    while(i < 25 && gradient(x, function).getLength() > 1e-5) {
        xNew = x + lambda * gradient(x, function);

        grad = gradient(x, function);

        std::cout << "Schritt " << i << ": " << std::endl;

        std::cout << "x = ( ";
        for (int j = 0; j < x.getDimension(); j++)
            std::cout << x[j] << " ";
        std::cout << ")" << std::endl;

        std::cout << "lambda = " << lambda << std::endl;
        std::cout << "f(x) = " << function(x) << std::endl;

        std::cout << "grad f(x) = ( ";
        for (int j = 0; j < grad.getDimension(); j++)
            std::cout << grad[j] << " ";
        std::cout << ")" << std::endl;

        std::cout << "||grad f(x)|| = " << grad.getLength() << std::endl << std::endl;

        std::cout << "xNew = ( " ;
        for (int j = 0; j < xNew.getDimension(); j++)
            std::cout << xNew[j] << " ";
        std::cout << ")" << std::endl;

        std::cout << "f(xNew) = " << function(xNew) << std::endl << std::endl;

        if (function(xNew) > function(x)) {
            std::cout << "Test mit doppelter Schrittweite (lambda = " << lambda * 2 << ")" << std::endl;

            xTest = x + 2 * lambda * gradient(x, function);

            std::cout << "xTest = ( ";
            for (int j = 0; j < xTest.getDimension(); j++)
                std::cout << xTest[j] << " ";
            std::cout << ")" << std::endl;

            std::cout << "f(xTest) = " << function(xTest) << std::endl;

            if(function(xTest) > function(xNew)) {
                x = xTest;
                lambda = lambda * 2;

                std::cout << "verdopple Schrittweite!" << std::endl << std::endl;
            } else {
                x = xNew;

                std::cout << "behalte alte Schrittweite!" << std::endl << std::endl;
            }

        } else if (function(xNew) <= function(x)) {
            while(function(xNew) <= function(x)) {
                std::cout << "halbiere Schrittweite (lamda = " << lambda * 0.5 << ")" << std::endl;

                lambda = lambda * 0.5;
                xNew = x + lambda * gradient(x, function);

                std::cout << "xNew = ( ";
                for (int j = 0; j < xNew.getDimension(); j++)
                    std::cout << xNew[j] << " ";
                std::cout << ")" << std::endl;

                std::cout << "f(xNew) = " << function(xNew) << std::endl;
            }

            x = xNew;
        }

        i++;

        std::cout << "-------------------------------------------------" << std::endl;
    }

    grad = gradient(x, function);

    std::cout << "Ende bei: " << std::endl;

    std::cout << "x = ( " ;
    for(int j = 0; j < x.getDimension(); j++)
        std::cout << x[j] << " ";
    std::cout << ")" << std::endl;

    std::cout << "lambda = " << lambda << std::endl;
    std::cout << "f(x) = " << function(x) << std::endl;

    std::cout << "grad f(x) = ( ";
    for (int j = 0; j < x.getDimension(); j++)
        std::cout << grad[j] << " ";
    std::cout << ")" << std::endl;

    std::cout << "||grad f(x)|| = " << grad.getLength() << std::endl << std::endl;
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

    //gradientenverfahren(vector1, f);
    gradientenverfahren(vector2, g, 0.1);

    return 0;
}