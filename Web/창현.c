#include <stdio.h>
#include <string.h>

void Palindrome(char s1[]);

int main(void) {

	char s[100];

    while(1){
        printf("문자열을 입력하세요(종료 : 0)=>");
        scanf("%s", s);

        if(s[0]== '0'){
            break;
        }
        Palindrome(s);
    }

	return 0;
}

void Palindrome(char s1[]){

    int i;
    int j = 0;
    int len = strlen(s1);

    for(i = 0; i < len / 2; i++){
        if(s1[i] != s1[len-1-i]){
            j = 1;
        }
    }

    if(j == 0){
        printf("Palindrome yes!\n");
    }
    else{
        printf("Palindrome no!\n");
    }
}
/* 3번

int main(){

    int arr[5];
    int sum = 0;
    int len =sizeof(arr)/4;

    for(int i = 0; i < 5; i++){
        scanf("%d",&arr[i]);
        printf("%d", arr[i]);
        sum += arr[i];

        if(i == len - 1){
            printf(" = ");
        }
        else{
            printf(" + ");
        }
    }  
    printf("%d", sum);

    return 0; 
}

*/

