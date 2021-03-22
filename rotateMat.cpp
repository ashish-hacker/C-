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
vector<vector<int>> rotate(vector<vector<int>> mat, int n){

    // Transpose of the matrix
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    REP(i,0,n-1){
        REP(j,0,n-1){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
        

        // Flip horizontally or you can say reverse each row
        int ptr1 = 0, ptr2 = n-1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/ 2; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[i][n-1-j];
                mat[i][n-1-j] = temp;
            }
        }
    
    return mat;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    mat = rotate(mat, 3);
    REP(i,0,2){
        REP(j,0,2){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
