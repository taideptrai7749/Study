#include<stdio.h>
int main(){
	float x, y;
	printf("Nhap x: ");
	scanf("%f",&x);
	printf("Nhap y: ");
	scanf("%f",&y);
	double S;
	S = (3*x*x*x*y - (x*x)/2 + (x*y)/5) * 6*x*y*y*y;
	printf("Result = %.3f",S);
}