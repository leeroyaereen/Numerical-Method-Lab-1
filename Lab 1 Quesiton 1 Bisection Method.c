#include <stdio.h>
#include <math.h>

float function(float x);
float Mid(float Xe, float Xu);
float Iteration(float Xe, float Xu);
float checkError(float Xe, float Xu);

void main(){
	//Declare variables
	float xe=0, xu = 0;
	float res;
	
	//Get input from user
	printf("Enter the input for Xe");
	scanf("%f",&xe);
	
	printf("Enter the input for Xu");
	scanf("%f",&xu);
	
	//find the value that gets negative and positive response
	if(function(xe)>0){
		printf("Re Enter the correct value for Xe");
		return;
	}
	
	if(function(xu)<0){
		printf("Re Enter the correct value for Xe");
		return;
	}
	//Start Iteration
	res = Iteration(xe,xu);
	//Show Result
	printf("\n Root of the function is: %f", res);
}
float function(float x){
	float res = x - exp(-x);
	return res;
}
float Mid(float Xe, float Xu){
	return (Xe + Xu)/2;
}

float checkError(float Xm, float pXm)
{
	float res =(Xm-pXm)/Xm;
	printf("\t error= %f",res);
	return res;
}

float Iteration(float Xe, float Xu){
	float Xm = 0;
	float prevXm = 0;
	
	do{
		prevXm = Xm;
		Xm= Mid(Xe,Xu);
		
		if(function(Xm) < 0){
			Xe = Xm;
		}else{
			Xu = Xm;
		}
		printf("\nXm = %f",Xm);
	}while(checkError(Xm,prevXm)>0.001 || checkError(Xm,prevXm)<-0.001);
	return Xm;
}

