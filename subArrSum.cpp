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

vector<int> subarraySum(int arr[], int n, int s){
        
        // Your code here
        int prefixArr[n];
        vector<int> result;
        int sum= 0;
        prefixArr[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixArr[i] = prefixArr[i-1] + arr[i];
            cout<<prefixArr[i]<<" ";
        }
        int left = 0, right = 0;
        while(right < n && left <= right){
            if(left > 0 && prefixArr[right] - prefixArr[left-1] == s){
                result.push_back(left+1);
                result.push_back(right+1);
                //cout<<"hello";
                break;
            }
            if(left == 0 && prefixArr[right] == s){
                result.push_back(left+1);
                result.push_back(right+1);
                //cout<<"hell";
                break;
            }
            if(left > 0){
                if(prefixArr[right] - prefixArr[left-1] > s) left++;
                else right++;
            }
            if(left == 0 && prefixArr[right] < s){
                right++;
                //cout<<"right"<<"\n";
            }
            else if(left == 0 && prefixArr[right] > s){
                left++;
                //cout<<"left"<<"\n";
            }
            
        }
        return result;
    }



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x[] = {135, 101 ,170 ,125 ,79 ,159 ,163 ,65, 106 ,146, 82 ,28, 162 ,92 ,196 ,143, 28, 37, 192 ,5 ,103 ,154 ,93, 183 ,22, 117 ,119, 96, 48, 127, 172, 139, 70, 113, 68, 100, 36, 95, 104, 12, 123, 134};
    vi t;
    t = subarraySum(x, 42, 468);
    for(auto x:t) cout<<x;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
