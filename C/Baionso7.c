#include<stdio.h>

int main(){
	int m, n;
	printf("Vui long bo tien vao may: ");
	scanf("%d",&m);
	printf("Vui long chon loai nuoc giai khat: ");
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("Pepsi\n");
			if(m>=6000){
				printf("Ban con du lai %d",m-6000);
			}
			else{
				printf("Ban khong du tien.");
			}
			break;
		case 2:
			printf("Tra xanh\n");
			if(m>=7000){
				printf("Ban con du lai %d",m-7000);
			}
			else{
				printf("Ban khong du tien.");
			}
			break;
		case 3:
			printf("Sting\n");
			if(m>=8000){
				printf("Ban con du lai %d",m-8000);
			}
			else{
				printf("Ban khong du tien.");
			}
			break;
		case 4:
			printf("Sua tuoi\n");
			if(m>=6000){
				printf("Ban con du lai %d",m-6000);
			}
			else{
				printf("Ban khong du tien.");
			}
			break;
		case 5:
			printf("Nuoc suoi\n");
			if(m>=4000){
				printf("Ban con du lai %d",m-4000);
			}
			else{
				printf("Ban khong du tien.");
			}
			break;
	}
	return 0;
}