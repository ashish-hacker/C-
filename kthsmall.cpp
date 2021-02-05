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
int kthsmall(vi& a, int l, int r, int k){
    int ksmall = INT_MAX;
    for(int i = 0; i <= r; i++){
        if(ksmall > a[i] && l < k){
            l++;
            ksmall = a[i];
        }
        else if(ksmall > a[i] && l == k){
            
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    vi a = {1, 30, 2, 4};
    n = kthsmallnlarge(a, 0, 3, 2);
    cout<<n;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
