#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool isPrime(int n){
	int root = sqrt(n);
	for(int i=3; i<=root; i+=2){
		if(n%i==0)
			return false;
	}
	return true;
}
void gold(int n){
	for(int i=3; i<=n/2; i+=2){
		if(isPrime(i) && isPrime(n-i)){
			printf("%d = %d + %d\n",n,i,n-i);			
			break;
		}
	}
}
int main(void){
	int n;
	while(1){
		scanf("%d", &n);
		if(n==0)
			break;
		else
			gold(n);
	}
}
/*
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

bool prime_num(int input){
	for (int i = 2; i <= sqrt(input); i++) {
		if (input%i == 0)return false;
	}
	return true;
}

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base :: sync_with_stdio(false);
	
	int num;
	int gap = 2;
	int check_1 = 0;
	int check_2 = 0;

	while(1){

		cin >> num;
		if(num != 0){
			while(gap < num / 2 + 1){
				if(prime_num(gap) && prime_num(num - gap)){
					if(2 * gap >= check_2 - check_1){
						check_1 = gap;
						check_2 = num - gap;
					}
				}
				gap++;
			}
			if(check_1 == 0 && check_2 == 0){
				cout << "Goldbach's conjecture is wrong" << "\n";
			}
			else{
				cout << num << " = " << check_1 << " + " << check_2 << "\n";
			}

		}
		else{
			break;
		}

		check_1 = 0;
		check_2 = 0;
		gap = 2;
	}

	return 0;
}
*/