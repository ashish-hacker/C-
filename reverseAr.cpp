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

void reverse(vector<int>& a){
    int n = a.size();
    int l = 0, r = n-1, temp;
    for(int i = 0; i < n/2 + 1 && l <= r; i++){
        temp = a[r];
        a[r] = a[l];
        a[l] = temp;
        r--;
        l++;
    }
    for(auto x: a) cout<<x<<" ";

}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    vi a = {11, 3, 100, 78, 0, 0};
    reverse(a);

    //cout<<n;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
