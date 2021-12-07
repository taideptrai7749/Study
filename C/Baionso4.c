#include<stdio.h>
#include<math.h>
int main(){
	float a,b,c;
	printf("Nhap do dai cua 3 canh tam giac: ");
	scanf("%f%f%f",&a,&b,&c);
	while(a+b<=c || a+c<=b || b+c<=a){
		printf("Error, ending the program");
		return 0;
	}
	float P , S , p;
	P = a + b + c;
	p = P/2.0;
	S = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("P = %f\n", P);
	printf("S = %f\n", S);
	
	if(a==b && b==c){
		printf("Tam giac deu");
	}
	else if(a!=b && a!=c && b!=c){
		printf("Tam giac thuong");
	}
	else
	printf("Tam giac can");
	return 0;
}