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

vector<vector<int>> setZero(vector<vector<int>>& m){
    vi is;
    vi js;
    for(int i = 0; i < m.size();i++){
        for(int j = 0; j < m.size();j++){
            if(m[i][j] == 0) continue;

        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> mat = {{1,2,3},
                               {4,0,6},
                               {7,8,9}};
    mat = setZero(mat);
    REP(i,0,2){
        REP(j,0,2){
            cout<<mat[i][j];
        }
        cout<<"\n";
    }
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test