
/*
** 에라토스테네스의 체 **

2부터 소수를 구하고자 하는 구간의 모든 수를 나열한다. 그림에서 회색 사각형으로 두른 수들이 여기에 해당한다.
2는 소수이므로 오른쪽에 2를 쓴다. (빨간색)
자기 자신을 제외한 2의 배수를 모두 지운다.
남아있는 수 가운데 3은 소수이므로 오른쪽에 3을 쓴다. (초록색)
자기 자신을 제외한 3의 배수를 모두 지운다.
남아있는 수 가운데 5는 소수이므로 오른쪽에 5를 쓴다. (파란색)
자기 자신을 제외한 5의 배수를 모두 지운다.
남아있는 수 가운데 7은 소수이므로 오른쪽에 7을 쓴다. (노란색)
자기 자신을 제외한 7의 배수를 모두 지운다.
위의 과정을 반복하면 구하는 구간의 모든 소수가 남는다.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int min,max;
    bool *prime;
    cin >> min;
    cin >> max;
    prime = new bool[max+1];
    fill_n(prime, max+1, 1);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(max); i++)
        if(prime[i] == true)
            for(int j = i*2; j <= max; j += i)
                prime[j] = false;

    for (int i = min; i <= max; i++)
        if(prime[i] == true)
            cout << i << "\n";
   return 0;
}