#include<iostream>

#define n 4

using namespace std;

int W = 16;
int w[n + 1] = {0, 5, 10, 10, 5};
int p[n + 1] = {0, 10, 20, 30, 40};
int maxprofit = 0;
int numbest = 0;
int bestset[n + 1];
int include[n + 1];

void knapsack(int i, int profit, int weight);
bool promising(int i, int weight, int profit);

int main(){
    knapsack(0, 0, 0);

    for (int i = 1; i <= numbest; i++){
        cout << bestset[i];
    }
}

void knapsack(int i, int profit, int weight){
    if (weight <= W && profit > maxprofit){
        maxprofit = profit;
        numbest = i;
        for(int i = 1; i < n; i++){
            bestset[i] = include[i];
        }
    }
    if(promising(i, weight, profit)){
        include[i+1] = 1;
        knapsack(i+1, profit + p[i+1], weight + w[i+1]);
        include[i+1] = 0;
        knapsack(i+1, profit, weight);
    }
}

bool promising(int i, int weight, int profit){
    int j, k;
    int totweight;
    float bound;
    if(weight >= W) return false;
    else{
        j = i+1;
        bound = profit;
        totweight = weight;
        while((j <= n) && (totweight + w[j] <= W)){
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }
        k = j;
        if(k <= n){
            bound = bound + (W - totweight) * p[k] / w[k];
        }
        return bound > maxprofit;
    }
}