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

/* 이렇게 하는 게 더 효율 적일 듯
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	string x, y;
	cin >> x >> y;

	string bigger;

	for (int i = 2; i >= 0; i--) {
		if (x[i] > y[i]) {
			bigger = x; break;
		}
		else if (x[i] < y[i]) {
			bigger = y; break;
		}
	}

	cout << bigger[2] << bigger[1] << bigger[0];
	return 0;
}
*/