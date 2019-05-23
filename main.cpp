#include <iostream>
#include "tester/tester.h"
#include"solver.h"
using namespace std;

int main(int argc, char const *argv[]) {
      //Tester::execute();
      solver solver1("4+5*3^2");
      cout << solver1.solve();
      return EXIT_SUCCESS;
}

