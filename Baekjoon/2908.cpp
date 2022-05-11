#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string a, b;

    cin >> a;
    cin >> b;

    for(int i = 2; i > 0; i--){

        if(a[i] - 48 > b[i] - 48){
            cout << a[2] << a[1] << a[0];
            break; 
        }
        else if(b[i] - 48 > a[i] - 48){
            cout << b[2] << b[1] << b[0];
            break;
        }
        else{
            continue;
        }
    }

    return 0;
}