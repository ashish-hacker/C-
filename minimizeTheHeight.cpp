//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
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
int getMinDiff(int arr[], int n, int k) {
        // code here
        //sort(arr, arr+n);
        for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        for(int i = 0; i < n; i++){
            if(arr[i]>= n - k + 1) arr[i] -= k;
            else arr[i] += k;
        }
        
        for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
        cout<<"\n";
        sort(arr, arr+n);
        return arr[n-1] - arr[0];
    }



int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0,num = 10,k = 5;
    int a[] = {5 ,5 ,8 ,6 ,4 ,10 ,3 ,8 ,9 ,10};
    n = getMinDiff(a, num, k);
    cout<<n;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test