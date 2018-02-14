#include <cmath>
#include <iostream>

int iterations = 100000000;
void riemannZetaFunction(){
    double s = 0;
    for(int i = 1; i < iterations; i++){
        s += 1/pow(i,2);
    }
    std::cout << "Sum of Riemann Zeta function: " << s << std::endl;
}
void machinFormula(){
    double s = 0;
    for(int i = 1; i < iterations; i++){
        s += 1/pow(i,2);
    }
    std::cout << "Sum of Machin formula: " << s << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    riemannZetaFunction();
    return 0;
}