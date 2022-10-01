#include <iostream>
// #include <cstdlib>
using namespace std;

#include "perceptron.hpp"

# define NB_SUBJECTS 10 //subject
# define NB_FEATURES 10 //features
# define EPOCHS 100

void test_tab(float *x, int size = 10) {
    for (int i = 0; i < size; i++) x[i] += 1;
}

int main() {

    Perceptron p1(10);
    p1.print_weights();
    
    float *x = new float[NB_SUBJECTS*NB_FEATURES]; //10 subjects & 10 features

    for (int i = 0; i < NB_SUBJECTS*NB_FEATURES; i++) {
        x[i] = static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX));
    }


    float *y = new float[NB_SUBJECTS];
    for (int i = 0; i < NB_SUBJECTS; i++) {
        y[i] = static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX));
    }

    float *z = new float[NB_SUBJECTS]; //linear function
    float *a = new float[NB_SUBJECTS]; //activation function
    float ll;
    
    
//-------------------------LEARNING PHASE -------------------------------------
    for (int epoch = 0; epoch < EPOCHS; epoch++) {


//-------------------------FORWARD PROPAGATION --------------------------------
        p1.forward_propagation(x, z, a, NB_SUBJECTS);
    
        // loss functions
        ll = p1.log_loss(y, a, NB_SUBJECTS);

        // forward monitoring
        cout << "EPOCH " << epoch << " FORWARD" << endl;
        p1.print_weights();
        display("z", z, NB_SUBJECTS);
        display("a", a, NB_SUBJECTS);
        cout << "l : " << ll << endl;

//-------------------------BACKWARD PROPAGATION --------------------------------
        p1.back_propagation(0.05, y, a, NB_SUBJECTS);

        // forward monitoring
        cout << "EPOCH " << epoch << " BACKWARD" << endl;
        p1.print_weights();
        cout << endl;
    }

    delete[] z;
    delete[] a;
    delete[] x;
    delete[] y;

    return 0;
}