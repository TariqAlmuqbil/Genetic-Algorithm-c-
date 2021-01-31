#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <algorithm>
#include <iterator>
#include "GAmodule.h"
#include "Object.h"
using std::vector;




int main(){


    GAmodule <GlodenNumber> myModule(200,1000,15);

    myModule.startEvalotion();

    auto result = myModule.getBestResult();

	std::cout << "_____________ Best result : " << "\n";
    result.printThis();

    return 0;
}
