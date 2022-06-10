#include <iostream> 
#include<cstdlib>

using namespace std; 

int main(){

    string word;

    int num;
    cin >> num;
    int cnt = num;
    
    for(int i = 0; i < num; i++){

        cin >> word;
        int check = 0;
        int cnt2 = 0; // 판명을 위한 숫자

        for(int j = 0; j < word.length(); j++){

            // if word = aabc
            // 이러면 a 부터 시작해서 체크 두번째 a를 만나고 check = 1
            // 그다음 b를 만나고 c만나고 끝

            // if word = aaba
            // 이러면 a 부터 시작해서 두번째 만나고 세번째 a를 만남
            // 이때 a가 0,1 이다가 3으로 튀기 때문에 그룹단어가 아니라 판명, cnt - 1

            check = j; // 어떤 자리를 판명하는지 알아야 하니까

            for(int k = j; k < word.length(); k++){
                if(word[j] == word[k]){
                    if(k - check != 1){
                        cnt2++;
                    }
                    else{
                        check = k;
                    }
                }
            }
        }

        if(cnt2 > 0){
            cnt -= 1;
        }
        
        // 바뀌고 나서 다시 그 문자가 나오는 걸 판단
        // word[0]을 기준으로 처음부터 끝까지 같은 문자를 찾기
        // 그 이후에 같은 문자가 연속한지 판별
        // 연속하면 그 문자를 기준으로 삼음 (check 이용)
    }
    
    cout << cnt;
    
}