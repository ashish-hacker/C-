#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
//string s;
//getline(cin, s);
bitset<30> d1, d2, col;

void search1(int row, int n, int &ans) {
    if(row == n){
        ans++;
        return;
    }
    REP(column, 0, n-1){
        if(!col[column] && !d1[row - column + n - 1] && !d2[row + column]){
            col[column] = d1[row - column + n - 1] = d2[row + column] = 1;
            search1(row + 1, n, ans);
            col[column] = d1[row - column + n - 1] = d2[row + column] = 0;
        }
    }
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 16;
    //cin>>n;
    int ans = 0;
    //cout<<col<<"\n"<<d1<<"\n"<<d2;
    search1(0, n, ans);
    cout<<ans;

    return 0;
}
