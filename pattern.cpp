#include <bits/stdc++.h>
using namespace std;

// prints the sequence like a pyramid pointing downward 
void printDown(int n){
    for(int j =1;j<=n;j++){
    for(int i = j;i<=n;i++){
        cout<<i<<" ";// printing number separated by spaces
        }
        cout<<"\n";//new line 
    //for printing spaces
    if(j!=n)
    for(int i=0;i<j;i++) cout<<" ";
    }
   
}

// prints the sequence like a pyramid(facing upward) 
void printUp(int n){
    for(int i = 1;i<n;i++){
        //for printing spaces
        for(int j=n-1;j>i;j--) cout<<" ";
        int count = n - i;
        while(count<=n){
            cout<<count<<" ";// printing number separated by spaces
            count++;
        }
    cout<<"\n";//new line
    }
}
int main(){
    // Prints in decrementing string elements
    printDown(7);
    // Prints in incrementing string elements
    printUp(7);
    
    return 0;
}