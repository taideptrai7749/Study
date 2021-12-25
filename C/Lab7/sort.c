#include<stdio.h>

#include<stdio.h>
#include<math.h>

void enterArray(int[],int*);
void printArray(int[],int);
void selectionSort(int[], int);
void bubbleSort(int[], int);

int main(){
    int arr[1000];
    int n;
    enterArray(arr,&n); 
    selectionSort(arr, n);
    printArray(arr,n);
    int size;
    int b[1000];
    enterArray(b, &size);
    bubbleSort(b, size);
    printArray(b, size);
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

void selectionSort(int arr[], int n){
    int i;
    int j;
    int smallestIndex;
    for(i = 0; i<n-1; i++){
        smallestIndex = i;
        for(j = i+1; j<n; j++){
            if(arr[j] < arr[smallestIndex])
            smallestIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

void bubbleSort(int arr[], int n){
    int i;
    int j;
    for(i = n-1; i>0; i--){
        for(j = 0; j< i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}