#include <cmath>

class Machin{
  public:
    static double arctan_approximation(int i, double x){
      return pow(-1,i-1)*(pow(x,2*i-1)/(2*i-1));
    }
};
