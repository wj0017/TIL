#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, pair<int, int>>> E;
vector<pair<int, pair<int, int>>> F;

typedef struct{
    int parent;
    int depth;

}nodetype;

void initial(nodetype* U, int n);
void merge(nodetype* U, int p, int q);
int find(nodetype* U, int i);
bool equal(nodetype* U, int x, int y);
int kruskal(int v, int e, vector<pair<int, pair<int, int>>> E, vector<pair<int, pair<int, int>>>& F);


int main()
{
    int v = 5, e = 7;

    int sum = kruskal(v, e, E, F);   
    cout << "Sum :" << sum << endl;
}

/* BOOK_DATA
1 2 1
1 3 3
2 3 3
2 4 6
3 4 4
3 5 2
4 5 5
*/


/* MY_DATA
1 2 1
1 4 2
2 3 3
2 5 1
3 4 3
3 5 4
4 5 2
*/

void initial(nodetype* U, int n){
    for(int i = 1; i <= n; i++){
        U[i].parent = i;
        U[i].depth = 0;
    }
}

void merge(nodetype* U, int p, int q){ 
    if (U[p].depth == U[q].depth){ 
        U[p].depth =+ 1; 
        U[q].parent = p;        
    }
    else if (U[p].depth < U[q].depth){
        U[p].parent = q; 
    }   
    else{
        U[q].parent = p;
    } 
}


int find(nodetype* U, int i){
    int j;
    j = i;
    while (U[j].parent != j){
        j = U[j].parent;
    }
    return j;
}


bool equal(nodetype* U, int x, int y){
    
    x = find(U, x);
    y = find(U, y);

    if (x == y){
        return true;
    }  
    else{
        return false;
    } 
}

int kruskal(int v, int e, vector<pair<int, pair<int, int>>> E, vector<pair<int, pair<int, int>>>& F){
    int i, j;
    nodetype U[v + 1];
    initial(U, v);

    for (int i = 0; i < e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        E.push_back(make_pair(c, make_pair(a, b))); 
    }
    sort(E.begin(), E.end());

    cout << "-------" << endl;
    for (int i = 0; i < e; i++){
        cout << E[i].first << " " << E[i].second.first << " " << E[i].second.second << endl;
    }
    int sum = 0;

    for (int i = 0; i < e; i++){
        if (!equal(U,E[i].second.first,E[i].second.second)){
            merge(U, E[i].second.first, E[i].second.second);
            sum += E[i].first;
            F.push_back({E[i].first, {E[i].second.first, E[i].second.second}});
        }
    }
    cout << "\nF" << endl;
    for (int i = 0; i < v-1; i++){
        cout << F[i].first << " " << F[i].second.first << " " << F[i].second.second << endl;
    }
    
    return sum;
}