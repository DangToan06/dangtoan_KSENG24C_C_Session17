#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void menu();

void inputString();

void outputString();

void countAlpha();

void countNumber();

void countSpecialChar();

int main(){
    int number;
    char *string = (char*)malloc(1000*sizeof(char));
    do{
        menu();
        scanf("%d", &number);
        fflush(stdin);
        switch (number){
        case 1:
            inputString(string);
            break;
        case 2:
            outputString(string);
            break;
        case 3:
            countAlpha(string);
            break;
        case 4:
            countNumber(string);
            break;
        case 5:
            countSpecialChar(string);
        default:
            break;
        }
    }while(number != 6);
    return 0;
}

void menu(){
    printf("\n\tMENU\n");
    printf("1.Nhap vao mot chuoi\n");
    printf("2.In ra chuoi\n");
    printf("3.Dem so luong chu cai trong chuoi va in ra\n");
    printf("4.Dem so luong chu so trong chuoi va in ra\n");
    printf("5.Dem so luong ky tu dac biet trong chuoi va in ra\n");
    printf("6.Thoat\n");
    printf("\nNhap lua chon cua ban: ");
}

void inputString(char *string){
    printf("Nhap vao mot chuoi:\n");
    fgets(string, 1000, stdin);
    size_t length = strlen(string);
    if(length > 0 && string[length - 1] == '\n'){
        string[length -1] = '\0';
    }
}

void outputString(char *string){
    printf("Chuoi vua nhap la:\n");
    fputs(string, stdout);
}

void countAlpha(char *string){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(isalpha(string[i])){
            count++;
        }
    }
    printf("So luong chu cai la: %d", count);
}

void countNumber(char *string){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            count++;
        }
    }
    printf("So luong chu so la: %d", count);
}

void countSpecialChar(char *string){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        if(!isalnum(string[i])){
            count++;
        }
    }
    printf("So luong ky tu dac biet la: %d", count);
}

