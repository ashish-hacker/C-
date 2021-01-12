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

void search(ll n){
    vi permutation;
    REP(i, 1, n+1) permutation.push_back(i);

    do{
        for(auto x: permutation) cout<<x<<" ";
        cout<<"\n";
    }while(next_permutation(permutation.begin(), permutation.end()));
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Print permutaion upto certain numbers
    search(2);

    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
