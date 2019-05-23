#include <iostream>
#include "tester/tester.h"
#include"solver.h"
using namespace std;

int main(int argc, char const *argv[]) {
      //Tester::execute();
      solver solver1("1-2*5/2+1-2^4+1");
      cout << solver1.solve();
      return EXIT_SUCCESS;
}

