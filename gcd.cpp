#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    while(b!=0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
int a,b;
cin>>a>>b;
int re = gcd(a,b);
cout<<re;

return 0;
}