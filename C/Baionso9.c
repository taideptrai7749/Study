#include<stdio.h>
#include<math.h>

int reverse(int);
int isPerfect(int);
int isPrime(int);
int isArmstrong(int);

int main(){
	int n, q=0;
	scanf("%d",&n);
	while(n<=0 && q<5){
		printf("Error, try again: ");
		scanf("%d",&n);
		q++;
	}
	int reverseNum = reverse(n);
	printf("%d is the reversed number\n", reverseNum);
	
	if(isPerfect(n)){
		printf("%d is a perfect number\n", n);
	}
	else{
		printf("%d is not a perfect number\n", n);
	}
	
	if(reverseNum == n){
		printf("%d is a palindrome number\n", n);
	}
	else
	{
		printf("%d is not a palindrome number\n",n);
	}
	
	if(isPrime(n)){
		printf("%d\n",n);
	}
	else{
		for(int i=1; i<n; i++){
			if(isPrime(i))
			printf("%d ", i);
		}
		printf("\n");
	}
	
	if(isArmstrong(n)){
		printf("%d is an Armstrong number\n", n);
	}
	else
		printf("%d is not an Armstrong number\n", n);
}

int reverse(int n){
	int result = 0;
	while(n>0){
		int rem = n%10;
		result = result*10 + rem;
		n = n/10;
	}
	return result;
}

int isPerfect(int n){
	int sum = 0;
	for(int i=1; i<n; i++){
		if(n%i==0){
			sum = sum + i;
		}
	}
	if(sum == n)
	return 1;
	else 
	return 0;
}

int isPrime(int n){
	if(n<2) return 0;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)
		return 0;
	}
	return 1;
}

int isArmstrong(int n){
	int originalNum = n;
	int num = 0;
	while(n>0){
		int rem = n%10;
		num = num + rem*rem*rem;
		n = n/10;
	}
	if(num == originalNum)
	return 1;
	else 
	return 0;
}