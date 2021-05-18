#include<bits/stdc++.h>

using namespace std;

int binaryToDec(string s){
    int dec = 0;
    int k = 0;
    for(int i = s.length()-1; i >= 0; i--){
        int t = s[i];
        dec = dec + (t - 48) * pow(2, k++);
    }
    return dec;
}
int cal(int n, string s){
    int num = binaryToDec(s);
    int count = 0;
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= num; j++){
            if((i + j) == (i ^ j)) count++;
        }
    }
    return count;
}

int main(){
    int d = cal(2, "10");
    cout<<d<<endl;
    return 0;
}