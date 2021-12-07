#include <stdio.h>

int main()
{
    float initialAmout = 10000000;
    int function;
    int stop = 1;
    do
    {
        printf("1 - Rut tien, 2 - Kiem tra so du, 3 - Chuyen tien: ");
        scanf("%d", &function);
        if (function > 3 || function < 1)
        {
            printf("Nhap lai: \n");
        }
    } while (function > 3 || function < 1);
    float amount;
    while (stop == 1 && initialAmout > 0)
    {
        switch (function)
        {
        case 1:
            printf("Rut so tien nho hon hoac bang 2000000: ");
            do
            {
                scanf("%f", &amount);
                if (amount < 0 || amount > 2000000)
                {
                    printf("Nhap lai: ");
                }
            } while (amount < 0 || amount > 2000000);

            printf("Ban da rut thanh cong, so tien con lai la %f", initialAmout - amount);
            initialAmout = initialAmout - amount;

            printf("Ban co muon tiep tuc ? (1 cho Yes va 0 cho No): ");
            do
            {
                scanf("%d", &stop);
                if (stop != 1 && stop != 0)
                {
                    printf("Nhap lai: ");
                }
            } while (stop != 1 && stop != 0);
            if (stop == 1)
            {
                printf("1 - Rut tien, 2 - Kiem tra so du, 3 - Chuyen tien: ");
                scanf("%d", &function);
            }
            else
            {
                return 0;
            }
            break;

        case 2:
            printf("%f la so tien cua ban\n", initialAmout);
            printf("Ban co muon tiep tuc ? (1 cho Yes va 0 cho No): ");
            do
            {
                scanf("%d", &stop);
                if (stop != 1 && stop != 0)
                {
                    printf("Nhap lai: ");
                }
            } while (stop != 1 && stop != 0);
            if (stop == 1)
            {
                printf("1 - Rut tien, 2 - Kiem tra so du, 3 - Chuyen tien: ");
                scanf("%d", &function);
            }
            else
            {
                return 0;
            }
            break;

        case 3:
            printf("Nhap so tien ban muon chuyen di: ");
            do
            {
                scanf("%f", &amount);
                if (amount <= 0)
                {
                    printf("Nhap sai, hay nhap lai: ");
                }
            } while (amount <= 0);
            printf("Chuyen tien thanh cong, so tien con lai la %f", initialAmout - amount);
            initialAmout = initialAmout - amount;
            printf("Ban co muon tiep tuc ? (1 cho Yes va 0 cho No): ");
            do
            {
                scanf("%d", &stop);
                if (stop != 1 && stop != 0)
                {
                    printf("Nhap lai: ");
                }
            } while (stop != 1 && stop != 0);
            if (stop == 1)
            {
                printf("1 - Rut tien, 2 - Kiem tra so du, 3 - Chuyen tien: ");
                scanf("%d", &function);
            }
            else
            {
                return 0;
            }
            break;
        }
    }
    return 0;
}