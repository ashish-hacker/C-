#include <bits/stdc++.h>
using namespace std;

unsigned long long fib(int n){
    unsigned long long f[n];
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<=n;i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}


int main(){
int n;
cin>>n;
unsigned long long result = fib(n);
cout<<result;
return 0;
}