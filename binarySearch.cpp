#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
//string s;
//getline(cin, s);

ll BinarySearch(vector<ll>& arr,ll start, ll end, ll target){
    ll result;
    if(start == end && arr[start] != target) return -1;
    result = ( start + end ) / 2;
    if(arr[result] == target) return result;

    if(arr[result] > target){
        result = BinarySearch(arr, start, result, target);
    }
    else{
        result = BinarySearch(arr, result+1, end, target);
    }


    return result;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> nums = {1, 2, 3, 4, 5, 6};
    int result;
    result = BinarySearch(nums, 0, nums.size()-1, 4);
    cout<<result;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test