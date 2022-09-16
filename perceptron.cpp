#include <iostream> 
#include <cstdlib>
using namespace std;
#include <time.h>

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

Perceptron::~Perceptron(){
    delete[] _weights;
}
