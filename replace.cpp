#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string replace(string s){
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ') s[i] = '%20';
    }
    return s;
}

int main(){
    
    string s = "qwe rty qwre";
    cout<<replace(s);
    
return 0;
}