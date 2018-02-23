#include <cmath>

class Machin{
  public:
    static double pi_approximation(int iterations){
      iterations++;
      return 4*(4*arctan_approximation(iterations, 1.0/5)-arctan_approximation(iterations, 1.0/239));
    }
  private:
    static double arctan_approximation(int iterations, double x){
      double s = 0;
      for(int i = 1; i < iterations; i++){
          s += pow(-1,i-1)*(pow(x,2*i-1)/(2*i-1));
      }
      return s;
    }
};
