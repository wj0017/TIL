#include<iostream>

// GCD = 최대 공약수
// LCM = 최소 공배수
 
using namespace std;
 
int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}
 
int main()
{
    int t, n;
    long long n_arr[101] = { 0 };
    long long sum[101] = { 0 };
 
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> n_arr[j];
        }
        for (int k = 0; k < n; k++)
        {
            for (int p = k + 1; p < n; p++)
            {
                sum[i] += gcd(n_arr[k], n_arr[p]);
            }
        }
    }
 
    for (int i = 0; i < t; i++)
    {
        cout << sum[i]<<"\n";
    }
}


/*
using namespace std;

int main(){

    cin.tie(NULL);
	cout.tie(NULL);
	ios_base :: sync_with_stdio(false);
	

    int num;
    cin >> num;

    while(num--){
        int num_1, cnt;
        vector<int> arr;
        int sum = 0;

        cin >> cnt;
        
        while(cnt--){
            cin >> num_1;
            arr.push_back(num_1);
        }

        for(int i = 0; i < arr.size(); i++){
            for(int j = i; j < arr.size(); j++){
                if(j == i && j == arr.size()) continue;
                else{
                    if(arr[i] > arr[j]) sum += arr[i] / arr[j];
                    else sum += arr[j] / arr[i];
                }
            }
        }
        cout << sum;
    }
}
*/