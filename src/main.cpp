#include <iostream>
#include "permutations.h"

using namespace std;

int main() {
    cout << "Answer: " << permutations::multiply_cycle("(acfg)(bcd)(aed)(fade)(bgfae)");
}
