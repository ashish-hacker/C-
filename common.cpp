#include <bits/stdc++.h>
using namespace std;
vector<int> subset;
vector<vector<int>> s;
int n =3;
void search(int k) {
if (k == n) {
    return;
} else {
search(k+1);
subset.push_back(k);
search(k+1);
subset.pop_back();

}
}
void sets(int k){
    vector<int> ts;
    
}



int main(){
    
   
    return 0;
}