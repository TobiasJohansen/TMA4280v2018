#include <cmath>
#include <cstdlib>
#include <iostream>

double arctan(int iterations, double x){
  double s = 0;
  for(int i = 1; i < iterations; i++){
      s += pow(-1,i-1)*(pow(x,2*i-1)/(2*i-1));
  }
  return s;
}

double machinFormula(int iterations){
  iterations++;
  return 4*(4*arctan(iterations, 1.0/5)-arctan(iterations, 1.0/239));
}

int main(int argc, char* argv[]) {
  if(argc < 2 ) return 1;
  int task = std::atoi(argv[1]);
  if(task == 0) return 1;
  else if(task == 1){
    if(argc != 3) return 1;
    int iterations = std::atoi(argv[2]);
    if(iterations == 0) return 1;
    std::cout << "Approximation of pi using the Machin formula: " << machinFormula(iterations) << std::endl;
  }else if(task == 2){
    if(argc != 2) return 1;
    std::cout << "Computed Machin: TODO" << std::endl;
    std::cout << "Expected Machin: TODO" << std::endl;
  }
}
