#ifndef PERCEPTRON_HPP_
#define PERCEPTRON_HPP_

class Perceptron {
private:
    float *_weights;
    int _nb_weights;
    
public:
    Perceptron(int nb_weight);
    ~Perceptron();
    void print();
};

#endif