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
string compress(string s)
    {
        // Your code goes here
        int n = s.size();
        vector<int> v(n);
        for(int i = 1; i<n;i++){
            int j = v[i-1];
            while(j>0 && s[i]!=s[j]){
                j = v[j-1];
            }
            if(s[i]==s[j]) j++;
            v[i] = j;
        }
        string ans ="";
        for(int i = n-1;i>=0;i--){
            if(i%2){
                if(v[i]>=(i+1)/2 && (i+1)%(2 % (i+1-v[i])) == 0){
                    ans+='*';
                    i/=2;i++;
                }
                else ans+=s[i];
                
            }
        }
        reverse(ans.begin(), ans.end());
       
        return ans;
    }
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "ababcababcd";
    s = compress(s);
    cout<<"\n"<<s;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
