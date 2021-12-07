#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n<=0){
		printf("Error, enter again: ");
		scanf("%d",&n);
	}
	float s1 = 0.0;
	for(int i=1; i<=n; i++){
		s1 = s1 + (i+1.0)/(sqrt(i));
	}
	printf("Cau a: %f\n",s1);
	int s2 = 0;
	for(int i= 1; i<=n; i++){
		s2 = s2 + i; 
	}
	printf("Cau b: %d\n",s2);
	float s3 = 0.0;
	for(int i=1; i<=n ;i++){
		s3 = s3+ (1.0/i);
	}
	printf("Cau c: %f\n", s3);
	int s4 = 1;
	for(int i= 1; i<=n; i++){
		s4 = s4 * i; 
	}
	printf("Cau d: %d\n", s4);
	float s5 = 0.0;
	for(int i=1; i<=n ;i++){
		s5 = s5 + pow(-1,i)/i;
	}
	printf("Cau e: %f\n", s5);
}