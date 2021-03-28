#include<bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int>& a, int n){
    int index = 1;
    vector<int> result;
    result.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1]) {
            result.push_back(a[i]);
            index++;
            }
        else continue;
    }
    cout<<index<<"\n";
    return result;
}


int main(){
    vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60 };
    vector<int> r;
    r = LIS(a,a.size());
    for(auto x:r) cout<<x<<" ";
    return 0;
}