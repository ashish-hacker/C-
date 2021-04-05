#include<bits/stdc++.h>

using namespace std;

int min(int a, int b, int c){
    return a<=b?(a<=c?a:c):(b<=c?b:c);
}

int calMinCost(vector<vector<int>>& cost,int m, int n){
    if(m == 0 && n == 0) return cost[m][n];
    else if(m < 0 || n < 0) return INT_MAX;

    else{
        return cost[m][n] + min(calMinCost(cost, m-1, n),
                                calMinCost(cost, m, n-1),
                                calMinCost(cost, m-1, n-1));
    }
    
}

int dpSol(vector<vector<int>>& cost, int m, int n){
    vector<vector<int>> table(3, vector<int> (3, 0));
    if(m == 0 && n == 0) return cost[m][n]; // if the starting position is the ending position
    table[0][0] = cost[0][0];
    // fill the values in first row
    for(int i = 1; i <= m; i++){
        table[0][i] = table[0][i-1] + cost[0][i];
    }

    // fill the values in first column
    for(int i = 1; i <= n; i++){
        table[i][0] = table[i-1][0] + cost[i][0];
    }
    // fill other cells
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            table[i][j] = cost[i][j] + min(table[i-1][j-1], table[i][j-1], table[i-1][j]);
        }
    }
    // return table[m][n]
    return table[m][n];
}

int main(){
    vector<vector<int>> cost = {{1, 2, 3},
                                {4, 8, 2},
                                {1, 5, 3}};
    int re = dpSol(cost, 2, 2);
    cout<<re;
    return 0;
}