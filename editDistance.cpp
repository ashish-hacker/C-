#include <bits/stdc++.h>

using namespace std;

int mini(int a, int b, int c = 0){

    return a <= b? (a <= c? a : c) : (b <= c? b: c);
}
int editDist(string s1, string s2, int m, int n){ // using recursion O(3^n)

    // if s1 is empty we have to remove all characters from s2
    if(m == 0) return n;

    // if s2 is empty we have to remove all characters from s1
    if(n == 0) return m;

    // else we go from last character of both the strings to the first recursively

    // if the last characters are same , we ignore the last character of both the strings and recurse through m-1 and n-1 index
    if(s1[m-1] == s2[n-1]) return editDist(s1, s2, m-1, n-1);

    // if the last characters are not same , three cases can arise here
    else{
        return 1 + mini(editDist(s1, s2, m, n-1), // INSERT operation could be the case
                       editDist(s1, s2, m-1, n),// or DELETE
                       editDist(s1, s2, m-1, n-1));// or REPLACE
    }
}
int dp(string s1, string s2, int m, int n){ // using dynamic programming O(n^2)

    int table[m+1][n+1];
    if(m == 0) return n;
    if(n == 0) return m;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0) table[i][j] = j;
            else if(j == 0) table[i][j] = i;
            else if(s1[i-1] == s2[j-1]) table[i][j] = table[i-1][j-1];
            else{
                table[i][j] = 1 + mini(table[i][j-1],
                                        table[i-1][j],
                                        table[i-1][j-1]);
            }
        }
    }
    return table[m][n];
}

int main(){
    string s1 = "ce", s2 = "de";
    int r = dp(s1, s2, s1.length(), s2.length());
    cout<<r<<endl;
    return 0;
}