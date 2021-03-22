#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool anagram(string s1, string s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1 == s2;
}
bool isAnagram(string s1, string s2){
    // define two pointers

    // check if they have the equal length if not return false

    // Two pointers pointing to the starting 
}

int main(){
    string s1="dcba", s2="abdce";
    //cin>>s1>>s2;
    if(anagram(s1,s2)) cout<<"Strings are anagrams";
    else cout<<"They are not anagrams.";
    
 
return 0;
}