#ifndef PERCEPTRON_HPP_
#define PERCEPTRON_HPP_

class Perceptron {
private:
    float *_w;
    int _nb_w;

public:
    Perceptron(int nb_weight);
    ~Perceptron();
    void print();

    //This function should be in a seperate class
    float linear_model(float *x);
    float sigmoid(float z);
    float log_loss(float *y, float *a);
};

#endif