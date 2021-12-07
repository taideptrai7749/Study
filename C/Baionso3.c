#include<stdio.h>
#include<math.h>

void check(float, float, float, float, float);
int main(){
	float xO , yO, r;
	printf("Nhap diem toa do x cua duong tron: ");
	scanf("%f",&xO);
	printf("Nhap diem toa do x cua duong tron: ");
	scanf("%f",&yO);
	printf("Nhap ban kinh r cua duong tron: ");
	scanf("%f",&r);
	float xA, yA;
	printf("Nhap diem toa do x cua diem A: ");
	scanf("%f",&xA);
	printf("Nhap diem toa do y cua diem A: ");
	scanf("%f",&yA);
	check(xO,yO,r,xA,yA);
	return 0;
}

void check(float xO, float yO, float r, float xA, float yA){
	float distance = sqrt((xA-xO)*(xA-xO) + (yA-yO)*(yA-yO));
	if(distance == r){
		printf("A nam tren duong tron");
	}
	else if(distance > r){
		printf("A nam ngoai duong tron");
	}
	else {
		printf("A nam trong duong tron");
	}
}