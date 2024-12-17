#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void menu(){
    printf("\n\tMENU\n");
    printf("1.Nhap vao so phan tu va tung phan tu\n");
    printf("2.Hien thi ca phan tu trong mang\n");
    printf("3.Nhap do dai mang\n");
    printf("4.Tinh tong cac phan tu trong mang\n");
    printf("5.Hien thi phan tu lon nhat\n");
    printf("6.Thoat");
    printf("\nNhap lua chon cua ban: ");
}

void inputArray(int *arr, int n){
    printf("Nhap so luong phan tu:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
}

void outputArray(int *arr, int n){
    printf("Mang vua duoc nhap la:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void sumArray(int *arr, int n, int *sum){
    for(int i = 0; i < n; i++){
        *sum += arr[i];
    }
}

void maxNumber(int *arr, int n, int *max){
    for(int i = 0; i < n; i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
    }
}

int main(){
    int n, number, length, sum = 0;
    int *arr;
    do{
        menu();
        scanf("%d", &number);
        int max = INT_MIN;
        switch(number){
            case 1:
                printf("Nhap so luong phan tu trong mang:\n");
                scanf("%d", &n);
                int *arr = (int*) malloc(n*sizeof(int));
                inputArray(arr, n);
                break;
            case 2:
                outputArray(arr, n);
                break;
            case 3:
                printf("\nDo dai cau mang la: %d", n);
                break;
            case 4:
                sumArray(arr, n, &sum);
                printf("Tong cua mnag la: %d", sum);
                break;
            case 5:
                maxNumber(arr, n, &max);
                printf("Phan tu lan nhat trong mang la: %d", max);
                break;
            case 6:
                break;
        }
    }while(number != 6);
    free(arr);
    return 0;
}