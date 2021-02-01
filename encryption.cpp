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

string encrypt(string s){
    int L = s.size();
    //cout<<L<<"\n";
    // Delete spaces in the string
    REP(i, 0, L){
        if(s[i] == ' '){
            s.erase(s.begin()+i);
            i--;
            L--;
        }
    }
    
    // Get ceil and floor of sqrt(L)
    int row, col,temp;
    row = sqrt(L);
    col = row;
    REP(i, 1, L){
        if(row > col) col++;
        if(row * col < L) {if(col == row)col++; else row++;}
        else break;
    }
    //cout<<row<<" "<<col<<"\n";
    // Make the Grid
    vector<string> grid;
    for(int i = 0; i < L; i += col){
        grid.push_back(s.substr(i, col));
    }
    //for(auto x: grid) cout<<x<<"\n";
    REP(i, 0, grid.size()){
        if(grid[i].size() < col){
            REP(j, grid[i].size(), col){
                grid[i] += " ";
            }
        }
    }

    string result = "";
    // Encode the message
    for(int i = 0; i < col; i++){
        //cout<<i<<" ";
        for(int j = 0;j < grid.size();j++){
            //cout<<j<<" "<<grid[j][i]<<" ";
            if(grid[j][i] != ' ')
            result += grid[j][i];
        }
        result += " ";
        //cout<<"\n";
    }
    return result;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = encrypt("chillout");
    cout<<s;
    
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
