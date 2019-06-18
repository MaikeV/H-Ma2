#include <iostream>
#include <unistd.h>
#include <iomanip>
#include "CZufall.h"
#include "CLotto.h"

void printVector(std::vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << std::setw(7) <<vector[i] << ",";
    }

    std::cout << std::endl;
}

double monteCarlo(int n, std::vector<int> sheet, char choice) {
    int counter = 0;
    CLotto lotto(time(NULL));
    lotto.setSheet(sheet);

    for(int i = 0; i < n; i++) {
        if(choice == 'a') {
            if (3 == lotto.simpleLotto()) {
                counter++;
            }
        } else if(choice == 'b') {
            if (3 == lotto.doubleLotto()) {
                counter++;
            }
        }
    }

    double monteCarlo = (double)counter / n;

    return monteCarlo * 100;
}

int main() {
    char choice = '0';

    while(choice != '4') {
        std::cout << "1) Basistests" << std::endl << "2) Lotto" << std::endl << "3) MonteCarlo" << std::endl << "4) Beenden" << std::endl;
        std::cin >> choice;

        CZufall z;
        std::vector<int> v;
        std::vector<int> sheet;


        switch(choice) {
            case '1':
                std::cout << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "test() mit immer gleichem Wert fuer n: " << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "   0   ,   1   ,   2   ,   3   ,   4   ,   5   ,   6   ,   7   ,   8   ,   9   ," << std::endl;

                for (int i = 0; i < 10; i++) {
                    z.initialize(1);
                    v = z.test(3, 7, 10000);
                    printVector(v);
                }

                std::cout << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "test() mit immer verschiedenen Werten fuer n: " << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "   0   ,   1   ,   2   ,   3   ,   4   ,   5   ,   6   ,   7   ,   8   ,   9   ," << std::endl;

                for (int i = 0; i < 10; i++) {
                    z.initialize(i);
                    v = z.test(3, 7, 10000);
                    printVector(v);
                }

                std::cout << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "test() mit n = time(NULL): " << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "   0   ,   1   ,   2   ,   3   ,   4   ,   5   ,   6   ,   7   ,   8   ,   9   ," << std::endl;

                for (int i = 0; i < 10; i++) {
                    z.initialize(time(NULL));
                    v = z.test(3, 7, 10000);
                    printVector(v);
                }

                std::cout << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "testFalse() mit n = time(NULL): " << std::endl;
                std::cout << "=============================================" << std::endl;
                std::cout << "   0   ,   1   ,   2   ,   3   ,   4   ,   5   ,   6   ,   7   ,   8   ,   9   ," << std::endl;

                for (int i = 0; i < 10; i++) {
                    v = z.test_false(3, 7, 10000);
                    printVector(v);
                }

                std::cout << std::endl;
                break;
            case '3':
                int select;
                double percentage;
                std::cout << "1) Einfache Ziehung, 100.000 mal" << std::endl << "2) Einfache Ziehung 1.000.000 mal" << std::endl << "3) Doppelte Ziehung, 100.000 mal" << std::endl << "4) Doppelte Ziehung, 1.000.000 mal" << std::endl;
                std::cin >> select;

                sheet.resize(6, 0);

                for(int i = 0; i < 6; i++) {
                    sheet[i] = z.wert(1, 50);
                }

                if (select == 1)
                    percentage = monteCarlo(100000, sheet, 'a');
                else if (select == 2)
                    percentage = monteCarlo(1000000, sheet, 'a');
                else if(select == 3)
                    percentage = monteCarlo(100000, sheet, 'b');
                else if(select == 4)
                    percentage = monteCarlo(1000000, sheet, 'b');
                else
                    percentage = 0;

                std::cout << percentage << " %" << std::endl << std::endl;
                break;
            case '2':
                int ini, game, num;
                std::cout << "Bitte Initializer eingeben: ";
                std::cin >> ini;

                CLotto lotto(ini);

                std::cout << "Bitte 6 Zahlen tippen: ";

                for (int i = 0; i < 6; i++) {
                    std::cin >> num;

                    if (num < 1 || num > 49) {
                        i--;
                        std::cout << "Ungueltige Eingabe, bitte Zahlen zwischen 1 und 49 eingeben." << std::endl;
                    } else {
                        sheet.push_back(num);
                        lotto.setSheet(sheet);
                    }
                }

                std::cout << "1) Einfache Ziehung " << std::endl << "2) Doppelte Ziehung ";
                std::cin >> game;

                int result;

                if(game == 1)
                    result = lotto.simpleLotto();
                else if(game == 2)
                    result = lotto.doubleLotto();

                std::cout << "Gesamt: " << result << " Richtige." << std::endl << std::endl;
                break;
//            default:
//                std::cout << "Ungueltige Eingabe.";
//                break;
        }
    }

    std::cout << std::endl;

    return 0;
}