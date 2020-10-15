#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Creating a vector of strings of the length of the substring to be compared
vector<string> substrings(string s,int n){
    vector<string> sub;
    int count = 0;
    for(int i=2;i<n;i++){
        count = i-2;
        string b = "";
        while(count<=i){
            b += s[count];
            count++;
        }
    sub.push_back(b);  
    }
    return sub;
}

// Compares each and every string of the vector and prints the index and the substring , returns number of matches found.
int matchString(string s, vector<string>& arr){
    sort(s.begin(),s.end());
    int count =0;
    for(int i=0;i<arr.size();i++){
        string x = arr[i];
        sort(x.begin(),x.end());
        if(s == x) {count++; cout<<arr[i]<<" present in index: "<<i<<"\n";
        }
    }
    return count;
}
int main(){
    //Given a main string
    string s = "XYYZXZYZXXYZ"; 
    // And a substring
    string sub = "XYZ";
    vector<string> substring = substrings(s, s.size());
    int x = matchString(sub, substring);
    cout<<"Total matches found:"<<x;
    
    
    
    return 0;
}