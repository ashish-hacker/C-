#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
//string s;
//getline(cin, s);
int i = 0;
int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int totalprofit = 0;
        int buy = 0, sell = 1;
        while(sell < prices.size()){
            if(prices[sell] <= prices[buy]){ // case when there is loss 
                //cout<<buy<<" "<<sell;
                buy = sell;
                sell++;
                //totalprofit += maxprofit;
                maxprofit = 0;
            }
            else if(prices[sell-1] > prices[sell]){ // case where the price decreases ( good time to buy)
                buy = sell;
                sell++;
                //totalprofit += maxprofit;
                maxprofit = 0;
            }
            else if(prices[sell] > prices[buy]){ // case of continuously increasing prices
                int profit = prices[sell] - prices[buy];
                maxprofit = profit > maxprofit ? profit : maxprofit;
                cout<<maxprofit<<" "<<totalprofit<<"\n";
                buy = sell;
                sell++;
                i++;
                cout<<i<<"\n";
                
                totalprofit += maxprofit;
                maxprofit = 0;
                
            }
        }
        
        return totalprofit;
    }



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    vi prices = {2,1,78,9,99};
    int result = maxProfit(prices);
    cout<<"\n"<<result;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
