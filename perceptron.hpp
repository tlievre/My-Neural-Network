#ifndef PERCEPTRON_HPP_
#define PERCEPTRON_HPP_

class Perceptron {
private:
    float *_w; //weights
    int _nb_w; // numbers of weights - 1

    //This function should be in a seperate class
    float linear_model(float *x);
    float sigmoid(float z);

public:
    Perceptron(int nb_weight);
    ~Perceptron();
    void print_weights();

    // forward propagation
    void forward_propagation(float *x, float *z, float *a, int nb_subject); 

    // activation function
    float log_loss(float *y, float *a, int nb_subject);

    // backpropagation or update weights
    void back_propagation(float lr, float *y, float *a, int nb_subject);

};

// utils
float gradient(float w, float *y, float *a, int nb_subject);

void display(string name, float *data, int size);

#endif