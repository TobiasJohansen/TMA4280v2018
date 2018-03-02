#include <cmath>

class Riemann{
  public:
    static double pi_approximation(int from, int to){
      double s = 0;
      for(int i = from; i < to; i++){
        s += 1.0/pow(i,2);
      }
      return s;
    }
};
