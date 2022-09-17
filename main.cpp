#include <iostream>
using namespace std;

#include "perceptron.hpp"

int main() {

    Perceptron p1(10);
    p1.print();
    
    float z = p1.linear_model();
    float a = p1.sigmoid(z);

    cout << "z : " << z << endl;
    cout << "a : " << a << endl;

    return 0;
}