#include <cmath>
#include <cstdlib>
#include <iostream>

double riemannZetaFunction(int iterations){
  iterations++;
  double s = 0;
  for(int i = 1; i < iterations; i++){
    s += 1.0/pow(i,2);
  }
  return sqrt(6*s);
}

int main(int argc, char* argv[]) {
  if(argc < 2 ) return 1;
  int task = std::atoi(argv[1]);
  if(task == 0) return 1;
  else if(task == 1){
    if(argc != 3) return 1;
    int iterations = std::atoi(argv[2]);
    if(iterations == 0) return 1;
    std::cout << "Approximation of pi using the Riemann Zeta function: " << riemannZetaFunction(iterations) << std::endl;
  }else if(task == 2){
    if(argc != 2) return 1;
    std::cout << "Computed Riemann Zeta: " << riemannZetaFunction(3) << std::endl;
    std::cout << "Expected Riemann Zeta: " << sqrt(6*(1.0/pow(1,2)+1.0/pow(2,2)+1.0/pow(3,2))) << std::endl;
  }
  return 0;
}
