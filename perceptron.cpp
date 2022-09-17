#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;


#include "perceptron.hpp"

Perceptron::Perceptron(int nb_weights){
    _nb_weights = nb_weights;
    _weights = new float[_nb_weights];

    srand(time(0));

    for (int i = 0; i < _nb_weights; i++) {
        _weights[i] = rand();
    }
}

void Perceptron::print(){

    cout << "weights : " << "[ ";
    for (int i = 0; i < _nb_weights; i++) {
        cout << _weights[i] << " ";
    }
    cout << "]" << endl;
    
}

float Perceptron::linear_model() {
    float z = 1; //init with bias value
    for (int i = 0; i < _nb_weights; i++) z += _weights[i];
    return z;
}

float Perceptron::sigmoid(float z) { return 1 / (1 - exp(-z)); }

float Perceptron::log_loss(float y, float a) {
    // fix the loss function
    // for    // for (int i = 0; i < _nb_weights; i++) {
    //     a = y * log(a);   
    // } (int i = 0; i < _nb_weights; i++) {
    //     a = y * log(a);   
    // }
    return 0;
}


Perceptron::~Perceptron(){
    delete[] _weights;
}
 