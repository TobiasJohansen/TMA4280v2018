#include <cmath>
#include <cstdlib>
#include <iostream>

double riemannZetaFunction(int iterations){
  iterations++;
  double s = 0;
  for(int i = 1; i < iterations; i++){
    s += 1.0/pow(i,2);
  }
  return s;
}

int main(int argc, char* argv[]) {
  int iterations;
  if(argc != 2) return 1;
  iterations = std::atoi(argv[1]);
  if(iterations == 0) return 1;
  std::cout << "Sum of Riemann Zeta function: " << riemannZetaFunction(iterations) << std::endl;
  return 0;
}
