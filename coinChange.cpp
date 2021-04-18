#include<bits/stdc++.h>

using namespace std;



int coinChange(vector<int>& cost, int money, int index, map<string, int>& memo){
    if(money == 0) return 1;

    if(index >= cost.size()) return 0;

    string key = to_string(money) + "-" + to_string(index);
    if(memo.count(key)) return memo[key];

    
    int currAmount = 0;
    int ways = 0;

    while(currAmount <= money){
        int remaining = money -currAmount;
        ways += coinChange(cost, remaining, index + 1, memo);
        currAmount += cost[index];
    }
    memo.insert({key, ways});
    return ways;
}
int coins(vector<int>& cost, int money){
    map<string, int> memo;
    return coinChange(cost, money, 0, memo);
}

int main(){
    vector<int> cost = {1, 2, 5};
    int money = 11;
    int w = coins(cost, money);
    cout<<w;
    return 0;
}