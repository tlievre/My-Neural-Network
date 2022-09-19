#include <iostream>
// #include <cstdlib>
using namespace std;

#include "perceptron.hpp"

# define NB_SUBJECTS 10 //subject
# define NB_FEATURES 10 //features

int main() {

    Perceptron p1(10);
    p1.print();
    
    float *x = new float[NB_SUBJECTS*NB_FEATURES]; //10 subjects & 10 features
    for (int i = 0; i < NB_SUBJECTS*NB_FEATURES; i++) { x[i] = rand() % 100; }


    float *y = new float[NB_SUBJECTS];
    for (int i = 0; i < NB_SUBJECTS; i++) { y[i] = rand() % 100; }

    //-------------------------FORWARD PROPAGATION ----------------------------

    float *z = new float[NB_SUBJECTS]; //linear function
    float *a = new float[NB_SUBJECTS]; //activation function
    

    // compute the sigmoid activation function
    for (int i = 0; i < NB_SUBJECTS; i++) {
        z[i] = p1.linear_model(x + (i * NB_SUBJECTS));
        a[i] = p1.sigmoid(z[i]);
    }
    
    // loss functions
    float ll = p1.log_loss(y, a);

    // monitoring
    cout << "z : [";
    for(int i = 0; i < NB_SUBJECTS; i++) { cout << z[i] << " ";}
    cout << "]"<< endl;

    cout << "a : [";
    for(int i = 0; i < NB_SUBJECTS; i++) { cout << a[i] << " ";}
    cout << "]"<< endl;

    cout << "l : " << ll << endl;

    delete[] z;
    delete[] a;
    delete[] x;
    delete[] y;

    return 0;
}