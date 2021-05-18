#include<bits/stdc++.h>

using namespace std;

int n(vector<int> a, int start, int end, int target){
    if(a[start] == target || a[end] == target){
        return 1;
    }
    return 1 + min(n(a, start+1, end, target-a[start]), n(a, start, end-1, target-a[end]));
}
int n1(vector<int> a, int target){
    int start = 0, end = 0;
    int curr_sum = 0;
    int sum = 0;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
    }
    if(sum == target) return a.size();

    while(end < a.size() && start <= end && curr_sum != (sum - target)){
        if(curr_sum < (sum - target)){
            curr_sum += a[end];
            end++;
        }
        else if(curr_sum > (sum - target)){
            curr_sum -= a[start];
            start++;
        }
    }

    return a.size() - (end - start);
}

int main(){
    vector<int> prices = {2, 1, 1, 1};
    int target = 4;
    int res = n1(prices, target);
    cout<<res<<endl;

    return 0;
}