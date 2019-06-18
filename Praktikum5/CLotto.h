//
// Created by mauske on 17.06.19.
//

#ifndef PRAKTIKUM5_CLOTTO_H
#define PRAKTIKUM5_CLOTTO_H


#include "CZufall.h"

class CLotto {
private:
    std::vector<int> sheet;
    CZufall generator;

    std::vector<int> play() {
        CZufall lotto;
        int num = 0;
        bool contains = false;
        std::vector<int> nums;
        nums.resize(6);

        for(int i = 0; i < 6; i++) {
            contains = false;
            num = lotto.wert(1, 50);

            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] == num) {
                    i--;
                    contains = true;
                    break;
                }
            }

            if(!contains)
                nums[i] = num;
        }

        return nums;
    }
public:
    CLotto(int n) {
        if (n < 0)
            this->generator.initialize(time(NULL));
        else
            this->generator.initialize(n);

        this->sheet.resize(6, 0);
    }

    const std::vector<int> &getSheet() const {
        return sheet;
    }

    void setSheet(const std::vector<int> &sheet) {
        CLotto::sheet = sheet;
    }

    int simpleLotto();
    int doubleLotto();
};


#endif //PRAKTIKUM5_CLOTTO_H
