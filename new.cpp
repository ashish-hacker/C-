#include <bits/stdc++.h>
#include <fstream>
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




int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int ic = 0, fc = 0;
	int count = 0;
	int integer = 0;
	float f = 0.0;
	bool flag = false;
    string line1, line2, line;
	fstream myfile1 ("data41.txt"); // read file "data41.txt" to the buffer
	fstream myfile2 ("data42.txt"); // read file "data42.txt" to the buffer
	fstream newf ("output4.txt"); // open "output4.txt" in write mode

	ifstream test ("data41.txt");
	// count the number of inputs 
	while(getline(test, line)){
		for(int i = 0; i < line.size(); i++){
			if(line[i] == ':') count++; // number of inputs will be equal to number of ':' present
		}
	}
	int integers[count]; // array to store the integer values
	float decimals[count]; // array to store the decimal values

	while(getline(myfile1, line1) && getline(myfile2, line2)){
		int dec = 0, tpow = 0;
		for(int i = 0; i < line1.size(); i++){
			if(line1[i] == ' ') continue; // if space is encountered go to the next index skipping the space index
			if(line1[i] == ':') { // if : is encountered push the value to the vector integers
				integers[ic++] = integer; 
				integer = 0; // reset the value of integer
				}
			else{
				int temp = line1[i] - 48;
				integer = integer * 10 + temp;
			}
		}

		for(int i = 0; i < line2.size(); i++){
			
			if(line2[i] == ' ') continue;
			if(line2[i] == ':'){ // if : is encountered push the value to the vector decimals
				f = integer + dec/pow(10, tpow);
				decimals[fc++] = f;  // push the value into the vector

				// reset all values
				flag = false; 
				integer = 0;
				dec = 0;
				tpow = 0;
				}
			else if(line2[i] == '.'){ // decimal part will start after it
				flag = true;
			}
			else if(!flag){
				int temp = line2[i] - 48; // convert char to int
				integer = integer * 10 + temp; // update the integer value
				
			}
			else{
				dec = dec * 10 + (line2[i] - 48); // update the decimal part after "."
				tpow++;
			}
		}
	}
	for(int i = 0; i < count; i++){
		newf<<integers[i]+decimals[i]<<", ";
	}
	
	// close all files for memory clean up
	myfile1.close();
	myfile2.close();
	newf.close();

    return 0;
}

//g++ -std=c++11 -O2 -Wall test.cpp -o test
