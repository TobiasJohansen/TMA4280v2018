#include <iostream>
#include <math.h>
#include "riemann.h"

int main(int argc, char* argv[]) {
  if(argc != 1) return 1;
  double expectedValue = sqrt(6*(1.0/1+1.0/4+1.0/9));
  double computedValue = Riemann::pi_approximation(3);
  std::cout << "Unit test for Riemann Zeta function ";
  if(expectedValue == computedValue){
    std::cout << "passed, expected and computed value after 3 iterations is " << computedValue << "." << std::endl;
  }else{
    std::cout << "failed, difference between expected and computed value is " << fabs(expectedValue - computedValue) << "." << std::endl;
  }
  return 0;
}
