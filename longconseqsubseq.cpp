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
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  map<int, int> m;
  int count = 0, prev = INT_MAX, max_count = 0;
  for(int i = 0; i < N; i++){
      if(arr[i] < prev) prev = arr[i];
  }
  prev = prev -1;
  for(int i = 0; i < N; i++){
      if(m.count(arr[i])){
          m[arr[i]]++;
      }
      else m[arr[i]] = 1;
  }
  for(auto i: m){
  if(i.second){
          if(i.first == (prev+1)) {count++; prev = i.first; max_count = max(max_count, count);}
          else{
              max_count = max(max_count, count);
              //cout<<max_count;
              count = 0;
          }
      }
  }
  return max_count;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    int arr[] = {8, 8, 8, 9, 3, 4, 4};
    n = findLongestConseqSubseq(arr, 7);
    cout<<n;
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
