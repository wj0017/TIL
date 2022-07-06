#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int min,max;
    bool *prime;
    int arr[123456] = {};

    while(1){

        int cnt = 0;
        cin >> min;
        if(min == 0) break;
        max = 2 * min;
        prime = new bool[max+1];
        fill_n(prime, max+1, 1);
        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i <= sqrt(max); i++)
            if(prime[i] == true)
                for(int j = i*2; j <= max; j += i)
                    prime[j] = false;

        for (int i = min + 1; i <= max; i++)
            if(prime[i] == true)
                cnt++;
        
        arr[min] = cnt;
    }

    for(int i = 0; i < sizeof(arr) / sizeof(int); i++){
        if(arr[i] != 0){
            cout << arr[i] << endl;
        }
    }

    return 0;
}

/*
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    vector<int> cases;
    int max = 0;
    int count = 0;
    while (1) {
        int i;
        cin >> i;
        if (i == 0)
            break;
        if (i > max)
            max = i;
        cases.push_back(i);
    }
    bool *prime = new bool[2 * max + 1];
    fill_n(prime, 2 * max + 1, 1);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(2*max); i++)
        if(prime[i] == true)
            for(int j = i*2; j <= (2*max); j += i)
                prime[j] = false;

    for(int j = 0; j < cases.size(); j++)
    {
        for(int k = cases[j]+1; k <= 2*cases[j]; k++)
            if(prime[k] == true)
                count++;
        cout << count << '\n';
        count = 0;
    }
    return 0;
}
*/