#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string bin(int n){
    
    string binary = bitset<25>(n).to_string(); 
    //cout<<binary<<"\n";

    return binary;
}
int NoD(ll n) 
{  
    int digits = (int)(floor( log(n) /  log(2)) + 1);  
 
    return digits;
} 
vector<string> split(const string &s, char delim) 
{ 
    vector<string> elems; 
    stringstream ss(s); 
    string item; 
    while (getline(ss, item, delim)) 
        elems.push_back(item); 
  
    return elems; 
} 
int countBinEquiv(vector<int>& arr, int n,int dig) 
{ 
    int sum_of_1=0,sum_of_0=0,count=0;
    vector<string> list; 
  
    for (int i = 0; i < (int) pow(2, n); i++) 
    { 
        string subset = ""; 
  
        for (int j = 0; j < n; j++) 
        { 
            if ((i & (1 << j)) != 0) 
                subset += to_string(arr[j]) + "|"; 
        } 
        if (find(list.begin(), list.end(), subset) == list.end()) 
            list.push_back(subset); 
    } 
    
    for (string subset : list) 
    { 
        vector<string> arr = split(subset, '|'); 
        for (string str: arr){
            int x = 0;
            stringstream ashish(str);
            ashish>>x;
            string s = bin(x);
            //cout<<s.erase(0,25-dig)<<endl;
            bitset<25> b(s);
            int k = b.count();
            sum_of_1 += k;
            sum_of_0 += dig - k;
            //cout<<str<<" "; 
        } 
        //cout<<count<<" "<<sum_of_0<<" "<<sum_of_1<<endl;
        if(sum_of_1 == sum_of_0 && sum_of_1 != 0) count++;
        //cout<<endl;
        sum_of_0 = 0;
        sum_of_1 = 0;
        
    } 
    return count;
} 



int main(){
int n,x;
cin>>n;
vector<int> a;
vector<int>::iterator result;
for(int i = 0;i<n;i++){
    cin>>x;
    a.push_back(x);
}

result = max_element(a.begin(),a.end());
//cout<<*result<<endl;
int re = *result;
int dig = NoD(re);
//cout<<dig<<endl;

//string r = bin(re);
//cout<<r.erase(0,15-dig)<<endl;

//bitset<15> b(r);
//cout<<b.count();

int res = countBinEquiv(a,n,dig);
string final = bin(res);
cout<<final.erase(0,25-dig);
return 0;
}

