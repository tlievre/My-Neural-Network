#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

#include "perceptron.hpp"

Perceptron::Perceptron(int nb_w){
    _nb_w = nb_w;
    _w = new float[_nb_w];

    _w[0] = 1.; // first weight initialize at 1 

    srand(time(0));
    for (int i = 1; i < _nb_w; i++) {
        _w[i] = static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX));
    }
}

Perceptron::~Perceptron() { delete[] _w; }


void Perceptron::print_weights() { display("w", _w, _nb_w); }


float Perceptron::linear_model(float *x) {
    // x and _w should have the same size
    float z = 1; //init with bias value
    for (int i = 0; i < _nb_w; i++) z += _w[i] * x[i];
    return z;
}

// problem with the dimension of the sigmoid activation function.
float Perceptron::sigmoid(float z) { return 0.5 * (1. + tanh( 0.5 * z)); }


void Perceptron::forward_propagation(float *x, float *z, float *a, int nb_subject){

    // compute the sigmoid activation function
    for (int i = 0; i < nb_subject; i++) {
        z[i] = linear_model(x + (i * nb_subject));
        a[i] = sigmoid(z[i]);
    }
}

float Perceptron::log_loss(float *y, float *a, int nb_subject) {
    float sum = 0;
    for (int i = 0; i < nb_subject; i++) {
        sum += y[i] * log(a[i]) + (1. - y[i]) * (log(1. - a[i]));
    }
    return -1 * sum / (float)nb_subject;
}

void Perceptron::back_propagation(float lr, float *y, float *a, int nb_subject){
    for (int i = 0; i < nb_subject; i++) {
        _w[i] = _w[i] - lr * gradient(_w[i], y, a, nb_subject);
    }
}

// utils
float gradient(float w, float *y, float *a, int nb_subject){
    float sum = 0;
    for (int i = 0; i < nb_subject; i++) {
        sum += y[i] - a[i];
    }
    return -1 * w * sum / (float)nb_subject;
}

void display(string name, float *data, int size) {
    cout << name << " : [ ";
    for(int i = 0; i < size; i++) { cout << data[i] << " ";}
    cout << "]" << endl;
}