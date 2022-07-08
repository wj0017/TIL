#include<iostream>
#include<string>
#include<cstring>

using namespace std;

// Brute Force 의 정석

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string board[50];
int WB_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != WB[i][j])
                cnt++;
        }

    }
    return cnt;
}
int BW_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != BW[i][j])
                cnt++;
        }

    }
    return cnt;
}
int main() {
    int size[2];
    int cnt;
    int min_val = 12345;
    pair<int, int> p1;
    cin >> p1.first >> p1.second;
    for(int i = 0; i < p1.first; i++)
        cin >> board[i];
    for(int i = 0; i + 8 <= p1.first; i++)
    {
        for(int j = 0; j + 8 <= p1.second; j++)
        {
            int tmp;
            tmp = min(WB_cnt(i,j),BW_cnt(i,j));
            if(tmp < min_val) {
                min_val = tmp;
            }
        }
    }
    cout << min_val;
    return 0;
}

/*
int M, N;
int cnt = 0;
string board;
string W = "W";
string B = "B";

int main(){
    
    cin >> M >> N;

    for(int i = 0; i < M * N; i++){
        cin >> board[i];
    }

    if(board[0] == W[0]){
        for(int i = 1; i < M * N; i++){

            if((i / 8) % 2 == 0 && board[i] != B[0]){cnt++;}
            else if((i / 8) % 2 == 1 && board[i] == B[0]){cnt++;}

        }
    }
    else{
        for(int i = 1; i < M * N; i++){
            if(i % 2 == 0 && board[i] == W[0]) {cnt++;}
            else if(i % 2 != 0 && board[i] == B[0]) {cnt++;}
        }
    }

    cout << cnt;
}
*/