# My-Neural-Network
Perceptron model from scratch
---

**author** : Thomas Lievre

**email** : lievre.thomas@gmail.com


The aim of this project is to implement by my own the perceptron model. The project actually contain :

- The class *Perceptron* in **Perceptron.cpp/hpp**;
- The main function in **main.cpp**.

## How it works ?

The model take $n*m$ data subject and turn it into the best biclassification prediction. 

## Forward propagation

It take a vector $x_i$ as an input and output a real. This vector is equivalent to features of a subject in statistic :

$$z(x_i) = b + \sum_{i=0}^n{w_ixi}$$

We use an activation function to turn the input of the perceptron into affiliation probabilities of the first class.

$$a(z) = \frac{1}{1+e^{-z}}$$

## back propagation

The log loss function come from the Likelyhood function in Inference Statistic theory. The purpose of this part is, in statistic inference theory, to maximize the likelyhood of the model parameters' so $\hat{\theta} = (X_i)_{1 \leq i \leq n}$  (not sure about that). Our aim in the real world is to mimize error between reality and prediction indeed, reduce de gape between this two value. With this aim in mind We'll use the opposite of the log likelyhood function in order to compute the minimum of this convex problem with a gradient descent.

$$logloss = -\frac{1}{m}\sum_{i=0}^n[y_i\log{y}]$$

## Reference

**Machine learnia :**

https://www.youtube.com/watch?v=XUFLq6dKQok&list=PLO_fdPEVlfKoanjvTJbIbd9V5d9Pzp8Rw
