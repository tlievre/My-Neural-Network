#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

#include "perceptron.hpp"

Perceptron::Perceptron(int nb_w){
    _nb_w = nb_w;
    _w = new float[_nb_w];

    srand(time(0));

    for (int i = 0; i < _nb_w; i++) {
        _w[i] = static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX));
    }
}

void Perceptron::print(){

    cout << "w : " << "[ ";
    for (int i = 0; i < _nb_w; i++) {
        cout << _w[i] << " ";
    }
    cout << "]" << endl;
    
}

float Perceptron::linear_model(float *x) {
    // x and _w should have the same size
    float z = 1; //init with bias value
    for (int i = 0; i < _nb_w; i++) z += _w[i] * x[i];
    return z;
}

// problem with the dimension of the sigmoid activation function.
float Perceptron::sigmoid(float z) { return 0.5 * (1. + tanh( 0.5 * z)); }


float Perceptron::log_loss(float *y, float *a) {

    float sum = 0;
    //fix the loss functionlog_loss
    for (int i = 0; i < _nb_w; i++) {
        sum += y[i] * log(a[i]) + (1. - y[i]) * (log(1. - a[i]));
        
    }
    return -1 * sum / (float)_nb_w;
}

Perceptron::~Perceptron(){
    delete[] _w;
}
 