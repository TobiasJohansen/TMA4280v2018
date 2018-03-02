#include <cmath>

class Machin{
  public:
    static double pi_approximation(int from, int to){
      return 4*(4*arctan_approximation(from, to, 1.0/5)-arctan_approximation(from, to, 1.0/239));
    }
  private:
    static double arctan_approximation(int from, int to, double x){
      double s = 0;
      for(int i = from; i < to; i++){
          s += pow(-1,i-1)*(pow(x,2*i-1)/(2*i-1));
      }
      return s;
    }
};
