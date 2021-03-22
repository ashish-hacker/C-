#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution{
    public:
    string remove(string s){
        // remove duplicate elements
        int tail = 1;
        // iterate through the string and append the unique characters
        for(int i = 1;i<s.length();i++){
            int j;
            for(j = 0; j<tail;j++){
                    if(s[i] == s[j]) break;   
            }
            if(j == tail)
                s[tail++] = s[i];
        }
        s[tail] = 0;
        return s;
    }

};

string removeDups(string s){
    int curr, last;
    curr = 0;
    last = 0;
    sort(s.begin(), s.end());
    for(int i = 0; i < s.size();i++){
        if(s[i] != s[last]){
            last++;
            s[last] = s[i];
        }
    }

    return s.substr(0,last+1);
}
int main(){
    string st = "aabcbbddefeefg";
    //cin>>st;
    //auto s  = Solution();
    //string result = s.remove(st);
    //cout<<result<<"\n";
    string s2 = removeDups(st);
    cout<<s2;
    //sort(st, st + st.length());
return 0;
}