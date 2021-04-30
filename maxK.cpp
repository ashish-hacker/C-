#include<bits/stdc++.h>

using namespace std;

string maxk(string s, int k){

    string result = "";
    int n = s.size();
    char ch[n];
    set<int> st;
    for(int i = 0; i < k; i++){
        char temp = s[i];
        for(int j = i; j < n; j++){
            if(st.count(j)){
                continue;
            }
            if(temp < s[j]){
                ch[i] = s[j];
                ch[j] = s[i];
                temp = s[j];
                st.insert(j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        result += ch[i];
    }
    return result;
}

int main(){
    string r = maxk("1234567", 3);
    cout<<r;

    return 0;
}