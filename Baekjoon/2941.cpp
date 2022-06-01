#include <iostream> 
using namespace std; 

int total=0; 
string s; 

int main() { 

    cin >> s;   
    
    for(int i = 0; i < s.size(); i++) { 

        total += ((int)s[i] - 65) / 3 + 3;
        
        if(s[i] == 'S' ||s[i] == 'V' ||s[i] == 'Y' ||s[i] == 'Z' ) total--; 
    } 

    cout << total; 
}

/*
//BOJ 2941 크로아티아 알파벳 d
//c=, c-, dz=, d-, lj, nj, s=, z=
 
#include<iostream>
#include<string>
 
using namespace std;
 
int solution(string& str){
    int count =0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'c'){ //c인경우
            if(str[i+1] == '=' || str[i+1] == '-'){ //뒷글자 확인
                i++;
            }
        }else if(str[i] == 'd'){
 
            if(str[i+1] == '-'){
                i++;
            }else if(str[i+1] == 'z' && str[i+2] == '='){
                i++;
                i++;
            }
 
        }else if(str[i] == 'l'){
 
            if(str[i+1] == 'j'){
                i++;
            }
 
        }else if(str[i] == 'n'){
 
            if(str[i+1] == 'j'){
                i++;
            }
 
        }else if(str[i] == 's'){
 
            if(str[i+1] == '='){
                i++;
            }
 
 
        }else if(str[i] == 'z') {
 
            if (str[i + 1] == '=') {
                i++;
            }
        }
        count++;
    }
    return count;
}
 
 
int main(void){
    string str;
    cin >> str;
 
    int result;
    result = solution(str);
 
    cout << result;
    return 0;
}


*/