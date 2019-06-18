//
// Created by mauske on 17.06.19.
//

#include "CZufall.h"


int CZufall::wert(int a, int b) {
    return rand() % (b - a) + a;
}

void CZufall::initialize(int n) {
    srand(n);
}

std::vector<int> CZufall::test(int a, int b, int N) {
    int rand = 0;
    std::vector<int> vec;
    vec.resize(a + b, 0);

    for(int i = 0; i < N; i++) {
        rand = wert(a, b + 1);
        vec[rand] = vec[rand] + 1;
    }

    return vec;
}

std::vector<int> CZufall::test_false(int a, int b, int N) {
    int rand = 0;
    std::vector<int> vec;
    vec.resize(a + b, 0);

    for(int i = 0; i < N; i++) {
        initialize(time(NULL));
        rand = wert(a, b + 1);
        vec[rand] = vec[rand] + 1;
    }

    return vec;
}
