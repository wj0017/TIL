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

