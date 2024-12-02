
#include <stdio.h>
#include <math.h>

float function(float x);
float derivative(float x);
float Iteration(float initialGuess);
float checkError(float Xe, float Xu);

void main(){
	float initialGuess;
    float result;

    // Get initial guess from the user
    printf("Enter the initial guess for the root: ");
    scanf("%f", &initialGuess);

    // Start Newton-Raphson iteration
    result = Iteration(initialGuess);

    // Show result
    printf("\nRoot of the function is: %f", result);
}
float function(float x){
	float res = x - exp(-x);
	return res;
}

float derivative(float x) {
    return 1 + exp(-x); 
}

float checkError(float currentX, float prevX) {
    float error = (currentX - prevX) / currentX;
    printf("\tError = %f", error);
    return error;
}
float Iteration(float initialGuess){
	float currentX = initialGuess;
    float prevX;
    do {
        prevX = currentX;
        currentX = prevX - function(prevX) / derivative(prevX); 
        printf("\nCurrent X = %f", currentX);
        
        
    } while (checkError(currentX, prevX) > 0.001 || checkError(currentX, prevX) < -0.001);
    return currentX;

}
