#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solution(ll n){
    vector<ll> ns;
    while(n != 1){
        ns.push_back(n);
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    ns.push_back(1);
    return ns;
}



int main(){
    ll n;
    vector<ll> result;
    cin>>n;
    result = solution(n);
    for(auto x: result) cout<<x<<"->";


    return 0;
}