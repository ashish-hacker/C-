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

int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int prev = nums[0];
        int last = nums[nums.size()-1];
        //cout<<last;
        int i = 1;
        while(i < nums.size()){
            
            //cout<<prev<<" ";
            if(nums[i] == last && last != nums[0]){
                nums.erase(nums.begin()+i+1, nums.end());
                break;
            }
            if(prev == nums[i]){
                nums.erase(nums.begin()+i);
                //cout<<prev;
                //i--;
                if(i < nums.size()-1) prev = nums[i-1];
                //cout<<prev<<" ";
                continue;
            }
            
            
            prev = nums[i];
            i++;
        }
        return nums.size();
    }


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    vi nums = {1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6};

    int n = removeDuplicates(nums);
    cout<<n<<"\n";
    for(auto x: nums) cout<<x<<" ";
    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
