#include<bits/stdc++.h>

using namespace std;

int fn(int n){
    int total = 0;
    int carry = 0;
    while(n > 0){
        if(n > 0 && n < 10){
            total += 9;
            break;
        }
        int curr_ans = 10 - (n % 10 + carry);
        cout<<total<<" "<<n<<endl;
        total = total + curr_ans;
        carry = 1;
        n /= 10;
    }

    return total;
}

int main(){

    int num = 12;
    int result = fn(num);
    cout<<result<<endl;
}