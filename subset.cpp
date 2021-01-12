#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
//string s;
//getline(cin, s);
vi subset;
vector<vector<int>> result;
void search(ll k, ll n){
    
    if(k == n+1){
        //for(auto x: subset) cout<<x<<" ";
        //cout<<"\n";
        result.push_back(subset);
    }
    else{
        subset.push_back(k);
        search(k+1, n);

        subset.pop_back();
        search(k+1, n);
    }
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    vi subset;
    search(1, 4);
    for(auto x: result){
        for(auto i: x) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test