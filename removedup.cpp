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

int main(){
    string st = "aabcbbdd";
    //cin>>st;
    auto s  = Solution();
    string result = s.remove(st);
    cout<<result;
    //sort(st, st + st.length());
return 0;
}