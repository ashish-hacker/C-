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
string Reduced_String(int k,string s){
        // Your code goes here
        int size = s.size(),start = 0, end  = 1;
        bool flag = false;
        while(end < size){
            if(end - start == k){
                s.erase(s.begin()+start, s.begin()+end);
                if(s == "") break;
                start--;
                end = start + 1;
            }
            else if(s[end] == s[start]){
                end++;
            }
            else if(s[end] != s[start]){
                start = end;
                end = start + 1;
            }
        }
        return s;
    }

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    string s;
    s = Reduced_String(2, "geegeegeegeegeegs");
    cout<<s;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test