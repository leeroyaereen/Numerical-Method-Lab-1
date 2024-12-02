#include <stdio.h>
#include <math.h>

// prototypes
float g(float x);  // Iteration function g(x)
float checkError(float currentX, float prevX);
float FixedPointIteration(float initialGuess);

void main() {
    float initialGuess, result;

    printf("Enter the initial guess for the root: ");
    scanf("%f", &initialGuess);

    result = FixedPointIteration(initialGuess);

    printf("\nRoot of the function is: %f\n", result);
}

float g(float x) {
    return exp(-x);
}

float checkError(float currentX, float prevX) {
    float error = (currentX - prevX) / currentX;
    printf("\tError = %f", error);
    return error;
}

float FixedPointIteration(float initialGuess) {
    float currentX = initialGuess, prevX;
    do {
        prevX = currentX;
        currentX = g(prevX); 
        printf("\nCurrent X = %f", currentX);
    } while (checkError(currentX, prevX) > 0.001 || checkError(currentX, prevX) < -0.001);

    return currentX;
}

