#include<bits/stdc++.h>

using namespace std;

int cutrod(int ar[], int n){
   int maximum = INT_MIN;
   if(n <= 0) return 0;
   map<int, int> memo;

   for(int i = 0; i < n; i++){
       if(memo.count(n-i-1)){
           maximum = max(maximum, ar[i] + memo[n-i-1]);
       }
       else{
           int m = cutrod(ar, n-i-1);
           maximum = max(maximum, ar[i] + m);
       }
   }
   return maximum;
}

int main(){
    int price[8] = {3, 5, 8, 9, 10, 17, 17, 20};
    int result = cutrod(price, 8);

    cout<<result;

    return 0;
}