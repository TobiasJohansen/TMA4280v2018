#include <cmath>
#include <cstdlib>
#include <iostream>

double machinFormula(int iterations){
  iterations++;
  double s = 0;
  for(int i = 1; i < iterations; i++){
      s += pow(-1,i-1)*(pow(1.0,2*i-1)/(2*i-1));
  }
  return s;
}

int main(int argc, char* argv[]) {
  int iterations;
  if(argc != 2) return 1;
  iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  std::cout << "Sum of Machin formula: " << machinFormula(iterations) << std::endl;
  return 0;
}
