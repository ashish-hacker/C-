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
    int mat[s1.length()+1][s2.length()+1];
    for(int i = 0; i < s1.size()+1;i++){
        for(int j = 0; j < s2.size()+1;j++){
            if(i == 0 || j == 0) mat[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
            else mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
        }
    }
    string result = "";
    int curvalue = 1;
    REP(i, 0, s1.size()+1){
        REP(j,0,s2.size()+1){
            //if(mat[i][j] == 1) result += s1[i];
            cout<<mat[i][j]<<" ";
            if(mat[i][j] - mat[i-1][j-1] == 1){
                result += s2[j-1];
                curvalue+=1;
                
            }
        }
        cout<<"\n";
    }
    return result;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1 = "abcdfgheddf",s2 = "abcdeooofghekjj";
    string result = lcs(s1, s2);
    cout<<result<<endl;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test