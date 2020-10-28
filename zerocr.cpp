#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int **zero(int **matrix, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(*((matrix+i)+j)==0){cout<<i<<*((matrix+i)+j)<<j;}
        }
    }

    return matrix;
}

int main(){
   int **ar;
   for(int i=0;i<2;i++){
       for(int j=0;j<2;j++) cin>>*(*ar+i);
   }
   int **arr = zero(ar,2,2); 
   for(int i=0;i<9;i++) cout<<ar[i][i+1];
    
 
return 0;
}