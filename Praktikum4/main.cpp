#include <iostream>
#include <fstream>
#include <vector>
#include "CKomplex.h"

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

std::vector<CKomplex> werte_einlesen(const char *dateiname) {
    int i, N, idx;
    double re, im;
    std::vector<CKomplex> werte;
    // File oeffnen
    std::ifstream fp;
    fp.open(dateiname);
    // Dimension einlesen
    fp >> N;
    // Werte-Vektor anlegen
    werte.resize(N);
    CKomplex null(0,0);
    for (i = 0; i<N; i++)
        werte[i] = null;
    // Eintraege einlesen und im Werte-Vektor ablegen
    while (!fp.eof()) {
        fp >> idx >> re >> im;
        CKomplex a(re,im);
        werte[idx] = a;
    }
    // File schliessen
    fp.close();

    return werte;
}

void werte_ausgeben(const char *dateiname, std::vector<CKomplex> werte, double epsilon = -1.0) {
    int i;
    int N = werte.size();
    // File oeffnen
    std::ofstream fp;
    fp.open(dateiname);
    // Dimension in das File schreiben
    fp << N << std::endl;
    // Eintraege in das File schreiben
    fp.precision(10);
    for (i = 0; i < N; i++)
        if (werte[i].abs() > epsilon)
            fp << i << "\t" << werte[i].getRe() << "\t" << werte[i].getIm() << std::endl;
    // File schliessen
    fp.close();
}

std::vector<CKomplex> fourierTransformation(std::vector<CKomplex> values, int j) {
    std::vector<CKomplex> newVals = std::vector<CKomplex>();
    int N = values.size();

    for(int n = 0; n < N; n++) {
        CKomplex cn = CKomplex(0,0);

        for(int k = 0; k < N; k++) {
            double phi = j * ((2 * M_PIl * k * n) / N);
            CKomplex comp(phi);
            cn = cn + values[k] * comp;
        }

        cn = cn * (1/sqrt(N));
        newVals.push_back(cn);
    }

    return newVals;
}

double calcDifference(std::vector<CKomplex> vectorI, std::vector<CKomplex> vectorO) {
    double max = 0;

    for(int i = 0; i < vectorI.size(); i++) {
        if(vectorI[i].getRe() - vectorO[i].getRe() > max)
            max = vectorI[i].getRe() - vectorO[i].getRe();
    }

    return max;
}

int main() {
    std::vector<CKomplex> vector;
    std::vector<CKomplex> vectorD;
    std::vector<CKomplex> vectorDB;
    std::vector<CKomplex> vector01;
    std::vector<CKomplex> vector01B;
    std::vector<CKomplex> vector10;
    std::vector<CKomplex> vector10B;
    std::vector<CKomplex> orig;

    orig = werte_einlesen("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/Daten_original.txt");
    vector = fourierTransformation(orig, 1);

    werte_ausgeben("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/epsilonDefault.txt", vector);
    werte_ausgeben("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/epsilon01.txt", vector, 0.1);
    werte_ausgeben("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/epsilon10.txt", vector, 1.0);

    vectorD = werte_einlesen("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/epsilonDefault.txt");
    vectorDB = fourierTransformation(vectorD, -1);

    vector01 = werte_einlesen("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/epsilon01.txt");
    vector01B = fourierTransformation(vector01, -1);

    vector10 = werte_einlesen("/home/mauske/Studium/HoeMa2/H-Ma2/Praktikum4/epsilon10.txt");
    vector10B = fourierTransformation(vector10, -1);

    std::cout << "Maximale Abweichungen:" << std::endl;
    std::cout << "Bei Default-Epsilon: " << calcDifference(orig, vectorDB) << std::endl;
    std::cout << "Bei Epsilon = 0.1: " << calcDifference(orig, vector01B) << std::endl;
    std::cout << "Bei Epsilon = 1.0: " << calcDifference(orig, vector10B) << std::endl;

    return 0;
}