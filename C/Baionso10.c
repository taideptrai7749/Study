#include<stdio.h>

void commonDivisor(int ,int);
int gcd(int, int);
int lcm(int, int);
void amicableNumber(int, int);
int main(){
	int a, b;
	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter b: ");
	scanf("%d",&b);
	
	while(a<=0){
		printf("a is non-positive, try again: ");
		scanf("%d",&a);
	}
	while(b<=0){
		printf("b is non-positive, try again: ");
		scanf("%d",&b);
	}
	commonDivisor(a,b);
	
	printf("Uoc so chung lon nhat la %d\n",gcd(a,b));
	
	printf("Boi so chung nho nhat la %d\n",lcm(a,b));
	
	amicableNumber(a,b);
}

void commonDivisor(int a, int b){
	printf("Uoc so chung cua 2 so: \n");
	for(int i=1; i<=a; i++){
		if(a%i==0 && b%i==0){
			printf("%d ", i);
		}
	}
	printf("\n");
}

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int lcm(int a,int b){
	return (a*b)/(gcd(a,b));
}

void amicableNumber(int a, int b){
	int s1 = 0, s2 = 0;
	for(int i = 1; i < a; i++){
		if(a%i==0){
			s1 = s1 + i;
		}
	}
	for(int i = 1 ;i < b; i++){
		if(b%i==0){
			s2 = s2 + i;
		}
	}
	if(s1 == b && s2==a){
		printf("They are amicable numbers\n");
	}
	else 
	printf("They are not amicable numbers\n");
}