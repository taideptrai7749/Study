#include<stdio.h>
#include<math.h>
int main(){
	double x;
	printf("Please enter an x value: ");
	scanf("%lf",&x);
	double result;
	if(x<0){
		result = sin(x)*cos(5*x);
		printf("sin(%f)cos(5%f) = %f",x,x, result);
	}
	else if(x==0){
		result = pow(5,x);
		printf("5^%f = %f", x, result);
	}
	else if(x<5){
		result = exp(x);
		printf("e^%f = %f", x, result);
	}
	else {
		result = pow(5,x)/(x+5);
		printf("%f is the result",result);
	}
}