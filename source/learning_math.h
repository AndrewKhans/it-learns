
/*
    MSE is:
    Loss = 1/n * sum((y_pred - y_true)^2)
*/
float meanSquaredError(float* y_pred, float* y_true, size_t n);


float gradient()

/*
    for (epoch = 0; epoch < N; epoch++) {
        forward();
        loss();
        backward();
        update();
    }
*/
void train(unsigned int epochs,);

/* activation functions */
static inline float relu(float val) { return (val > 0) ? val : 0 }
float tanh(float val);