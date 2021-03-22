#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
//string s;
//getline(cin, s);

string lcs(string s1, string s2){
    vector<vector<int>> mat;
    for(int i = 0; i < s1.size()+1;i++){
        for(int j = 0; j < s2.size()+1;j++){
            if(i == 0 || j == 0) mat[i].PB(0);
            else if(s1[i-1] == s2[j-1]) mat[i].PB(1);
            else mat[i].PB(0);
        }
    }
    REP(i, 0, s1.size()){
        REP(j,0,s2.size()){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return "";
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1 = "abcd",s2 = "abc";
    string result = lcs(s1, s2);
    
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test