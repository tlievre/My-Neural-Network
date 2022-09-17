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

    //This function should be in a seperate class
    float linear_model();
    float sigmoid(float z);
    float log_loss(float z, float a);
};

#endif