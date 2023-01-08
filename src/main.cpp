#include <iostream>
#include "product.h"


int main (){

    Product p;

    auto c1 = p.computeA(10,20);
    auto c2 = p.computeB(10,20,30);
    std::cout << "c1=" << c1 << " c2=" << c2 << "\n";

}