//
// Created by mauske on 17.06.19.
//

#ifndef PRAKTIKUM5_CZUFALL_H
#define PRAKTIKUM5_CZUFALL_H

#include <vector>
#include <stdlib.h>
#include <time.h>


class CZufall {
public:
    CZufall(){};

    int wert(int a, int b);
    void initialize(int n);
    std::vector<int> test(int a, int b, int N);
    std::vector<int> test_false(int a, int b, int N);
};


#endif //PRAKTIKUM5_CZUFALL_H
