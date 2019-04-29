#include "CMyVector.h"

int main() {
    std::vector<double> v;
    v.push_back(2);
    v.push_back(3);

    CMyVector vector1(2, v);

    CMyVector vector2(2, v);
    vector2.setValue(4, 0);
    vector2.setValue(5, 1);

    CMyVector res = vector1 + vector2;

    std::cout << res.getDimension() << " " << res.getLength() << std::endl;

    for(int index = 0; index < res.getDimension(); index++) {
        std::cout << res.getValue(index) << std::endl;
    }

    return 0;
}