#include <iostream>
#include <math.h>
#include "machin.h"

int main(int argc, char* argv[]) {
  if(argc != 1) return 1;
  double expectedValue = 4*(4*(1.0/5-1.0/375+1.0/15625)-(1.0/239-1.0/40955757+1.0/3899056325995));
  double computedValue = Machin::pi_approximation(3);
  std::cout << "Serial unit test for Machin formula ";
  if(expectedValue == computedValue){
    std::cout << "passed, expected and computed value after 3 iterations: " << computedValue << std::endl;
  }else{
    std::cout << "failed, difference between expected and computed value: " << fabs(expectedValue - computedValue) << std::endl;
  }
  return 0;
}
