#include<stdio.h>

int main(){

    // 5 개의 숫자를 임의로 입력 받아서 입력 받은
    // 값 중에서 짝수를 출력하고 짝수의 합을 구
    // 하시오

    int num;
    int total = 0; // 합?

    printf("입력: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &num);
        
        if(num % 2 == 0){ // 짝수 판별 조건문
            printf("%d " ,num);
            total += num; // total = num + total
        }
    }
}