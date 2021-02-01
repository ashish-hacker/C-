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
bool is9in(ll n){
    
    ll r;
    while(n > 0){
        r = n % 10;
        if(r == 9){
            return true;
        }
        n = n / 10;
    }
    return false;
}
int countDigits(ll n){
    int count = 0;
    while(n > 0){
        n = n / 10;
        count++;
    }
    return count;
}
ll nth(ll n){
    ll count = 0;
    ll i = 1;
    while(count <= n){
        if(is9in(i)){
            i++;
            continue;
        }
        count++;
        i++;
        //cout<<i<<" "<<count<<" "<<n<<"\n";
    }
    return i - 1;
}
ll NthNaturalNumber(ll n, ll& result){
    int nines = 0;
    int digits = countDigits(n);
    ll ninesTillLast = 0, add = 0;
    for(int i = 1; i < digits; i++){
        add = pow(10, i-1);
        ninesTillLast = ninesTillLast * 9 + add; 
    }
    result += 

    nines = ninesTillLast;
    return nines;
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n = 10, result;
    result = NthNaturalNumber(n, result);
    cout<<result;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
