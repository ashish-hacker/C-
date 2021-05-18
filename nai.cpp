#include<bits/stdc++.h>

using namespace std;

map<vector<int>, int> m;

int calDp(vector<int> k){
    if(m.count(k)){
        return m[k];
    }
    else{
        if(k[1] == 1){
            m[k] = k[2]-k[0]+1;
        }
        else{
            int sum = 0;
            for(int i = k[0]; i <= k[2]; i++){
                sum += calDp({i, k[1]-1, k[2]});
            }
            m[k] = sum;
        }
        return m[k];
    }

}

int nai(vector<int> a, int n){
    int ways = 1;
    int zeroesCount = 0;
    bool flag = false;
    int start, end;
    for(int i = 0; i < n; i++){
        if(a[i] == 0 && i == n-1){
            if(zeroesCount == 0){
                start = a[i-1];
                end = 9;
                ways *= calDp({start, 1, end});
                break;
            }
            zeroesCount++;
            flag = false;
            end = 9;
            ways *= calDp({start, zeroesCount, end});
            zeroesCount = 0;
            
        }
        if(!flag && a[i] == 0) {
            if(i == 0) start = 1;
            else start = a[i-1];
            flag = true; 
            }
        if(flag && a[i] != 0){ 
            flag = false; end = a[i]; 
            ways *= calDp({start, zeroesCount, end}); 
            zeroesCount = 0;
            }
        if(flag){
            zeroesCount++;
        }
    }
    return ways;
}

int main(){
    int result = nai({1, 0, 0, 3, 6}, 5);
    cout<<result<<endl;

    return 0;
}