#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solution(string s){
    string result = "";
    for(int i=s.length()-1;i>=0;i--){
        //Append the characters from last to the string variable result
        result = result + s[i];
        //cout<<result;
    }
    return result;
}

int main(){
    string s = "qwerty\0";
    //cin>>s;
    string re = solution(s);
    cout<<re;
    
return 0;
}