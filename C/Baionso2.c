#include<stdio.h>

int calc(int);

int main(){
	int d;
	printf("Enter the distance you want to travel: ");
	scanf("%d",&d);
	int result = calc(d);
	printf("%d is the amount of money",result);
}

int calc(int d){
	if(d<=1){
		return 18000;
	}
	else if(d<=10){
		return 18000 + (d-1)*8000;
	}
	else if(d<=30){
		return 18000 + 9*8000 + (d-10)*6000;
	}
	else {
		return 18000 + 9*8000 + 20*6000 + (d-30)*4000;
	}
}