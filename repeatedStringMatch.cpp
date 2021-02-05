#include <bits/stdc++.h>
using namespace std;

bool isin(string a, string b){
        int b1=0,a1=0, count = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[a1] == b[b1]){
                count++;
                if(count == b.size()) return true;
                b1++;
            }
            else if(a[a1] != b[b1]) {count = 0; b1=0;}
            a1++;
        }
        return false;
    }
string repeat(string a, string b){
    return a+b;
}
int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        int count = 1, i = 0;
        string s = A;
        if(isin(B, A)){
            return count;
        }
        while(i < A.size()+B.size()){
            if(isin(B,A)){
                return count;
            }
            else{
                A = repeat(A, s); count++;
            }
            i++;
        }
        return -1;
    }

int main(){
    cout<<repeatedStringMatch("abcd", "abcd");
    return 0;
}
