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

int homogenicSubStr(string s){
    int ptr1 = 0, ptr2 = 0, ptr3 = 0, total = 0, c2 = 0, c3 = 0;
    char last = s[0];

    while(ptr1 < s.size()){
        
        if(s[ptr1] != last){
            if(c2 == 2) {ptr2++; }
            if(c3 == 3) {ptr3++; }
            c2 = 1; c3 = 1;
            last = s[ptr1];
        }
        if(s[ptr1] == last){
            if(c2 == 2) {ptr2++; c2 = 0;}
            if(c3 == 3) {ptr3++; c3 = 0;}
            c2++;
            c3++;
        }
        ptr1++;
       
    }

    return ptr1+ptr2+ptr3;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "xyx";
    int re = homogenicSubStr(s);
    cout<<re;
   
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
