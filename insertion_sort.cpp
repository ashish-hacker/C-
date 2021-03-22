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
int* insertion_sort(int arr[], int n){

    for(int i = 0; i < n; i++){
        int curr = arr[i];

        int j = i-1;
        while(j >= 0 && arr[j] > curr){ // find the right spot for the current element
            arr[j+1] = arr[j];
            arr[j] = curr;
            j--;
        }
        arr[j+1] = curr;
        for(int k = 0; k < n; k++) cout<<arr[k]<<" ";
        cout<<"\n";
    }
    return arr;
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {4,3,1,5,2};
    int* a = insertion_sort(arr, 5);
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
