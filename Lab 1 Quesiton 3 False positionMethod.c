#include <stdio.h>
#include <math.h>

float function(float x);
float FalsePosition(float Xe, float Xu);
float checkError(float Xm, float prevXm);

void main(){
	float xe, xu, result;

    // Get inputs 
    printf("Enter the initial value for Xe: ");
    scanf("%f", &xe);
    printf("Enter the initial value for Xu: ");
    scanf("%f", &xu);

    // Ensure the function values at boundaries have opposite signs
    if (function(xe) * function(xu) > 0) {
        printf("Invalid inputs! Function values at Xe and Xu must have opposite signs.\n");
        return;
    }

    result = FalsePosition(xe, xu);

    // Display 
    printf("\nRoot of the function is: %f\n", result);
}

float function(float x) {
    return x - exp(-x); 
}

// Function to calculate the relative error
float checkError(float Xm, float prevXm) {
    float error = (Xm - prevXm) / Xm;
    printf("\tError = %f", error);
    return error;
}

// False Position Method implementation
float FalsePosition(float Xe, float Xu) {
    float Xm = 0, prevXm = 0;

    do {
        prevXm = Xm;

        Xm = Xu - (function(Xu) * (Xe - Xu)) / (function(Xe) - function(Xu));

        if (function(Xm) < 0) {
            Xe = Xm;
        } else {
            Xu = Xm;
        }

        printf("\nXm = %f", Xm);
    } while (checkError(Xm, prevXm) > 0.001 || checkError(Xm, prevXm) < -0.001);

    return Xm;
}
