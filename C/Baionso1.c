#include<stdio.h>

float calc(int , int);

int main(){
	int m, h;
	printf("Hay nhap so tien/gio: ");
	scanf("%d",&m);
	printf("Hay nhap so gio lam viec: ");
	scanf("%d",&h);
	float result = calc(m, h);
	printf("%.2f", result);
}

float calc(int m, int h){
	if(h<=40){
		return m*h;
	}
	else if(h<=45){
		return m*40 + m*1.8*(h-40);
	}
	else if(h<=50){
		return m*40 + 5*m*1.8 + (h-45)*2.5*m;
	}
	else{
		return m*40 + 5*m*1.8 + 5*m*2.5 + (h-50)*2.6*m;
	}
}