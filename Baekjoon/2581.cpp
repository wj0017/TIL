#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

int M, N;
int sum = 0;
int cnt = 0;
vector<int> ans;


int main()
{
    cin >> M >> N;

    for(int i = 0; i < M - N; i++){

        int getNum = M + i;
        int cn = 0;

        for(int j = 2; j < getNum; j++){
            if(getNum % j == 0) cn++;
        }
        if(cn == 0 && getNum != 1) {
            cnt++;
            ans.push_back(getNum);
        }
    }

    sum = accumulate(ans.begin(), ans.end(), 0);

    if(cnt > 0) cout << sum << "\n" << ans[0];
    else        cout << "-1";
}