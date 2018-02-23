#include <cmath>

class Riemann{
  public:
    static double pi_approximation(int iterations){
      iterations++;
      double s = 0;
      for(int i = 1; i < iterations; i++){
        s += 1.0/pow(i,2);
      }
      return sqrt(6*s);
    }
};
