#include<stdio.h>
#include<math.h>

void enterArray(int[],int*);
void printArray(int[],int);
int isPrime(int);
int firstPrime(int[], int);

int main(){
    int arr[1000];
    int n;
    enterArray(arr,&n); 
    printArray(arr,n);
    printf("Prime number example: %d\n", isPrime(3));
    printf("The first prime element is %d (-1 for not found)",firstPrime(arr,n));
}

void enterArray(int arr[], int *n){
    scanf("%d", n);
    int i;
    for(i=0; i<*n; i++){
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n){
    int i;
    for(i= 0; i< n; i++){
        printf ("%d ", arr[i]);
    }
    printf("\n");
}

int isPrime(int n){
    if(n < 2) return 0;
    int i;
    for(i = 2; i<=sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int firstPrime(int arr[], int n){
    int i;
    for(i = 0; i<n; i++){
        if(isPrime(arr[i])){
            return arr[i];
        }
    }
    return -1;
}