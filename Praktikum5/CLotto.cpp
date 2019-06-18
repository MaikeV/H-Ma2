//
// Created by mauske on 17.06.19.
//

#include <iostream>
#include "CLotto.h"

int CLotto::simpleLotto() {
    std::vector<int> gameNums;
    std::vector<int> sheetNums;
    int counter = 0;

    gameNums = play();
    sheetNums = this->getSheet();

    for(int i = 0; i < sheetNums.size(); i++) {
        for(int j = 0; j < gameNums.size(); j++) {
            if(sheetNums[i] == gameNums[j]) {
                counter++;
                break;
            }
        }
    }

    return counter;
}

int CLotto::doubleLotto() {
//    int lotto1 = simpleLotto();
//    std::cout << "Erste Ziehung: " << lotto1 << " Richtige." << std::endl;
//
//    int lotto2 = simpleLotto();
//    std::cout << "Zweite Ziehung: " << lotto1 << " Richtige." << std::endl;

    std::vector<int> gameNums;
    std::vector<int> game2Nums;
    int counter = 0;

    gameNums = play();
    game2Nums = play();

    for(int i = 0; i < game2Nums.size(); i++) {
        for(int j = 0; j < gameNums.size(); j++) {
            if(game2Nums[i] == gameNums[j]) {
                counter++;
                break;
            }
        }
    }

    return counter;
}
