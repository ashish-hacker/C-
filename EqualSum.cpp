
// C++ program for the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to print the two set 
void findAns(int N) 
{ 
    // Base case 
    if (N <= 2) { 
        cout << "-1"; 
        return; 
    } 
  
    // Sum of first numbers upto N 
    int value = (N * (N + 1)) / 2; 
  
    // To store the first set 
    vector<int> v1; 
  
    // To store the second set 
    vector<int> v2; 
  
    // When N is even 
    if (!(N & 1)) { 
  
        int turn = 1; 
        int start = 1; 
        int last = N; 
        while (start < last) { 
  
            if (turn) { 
                v1.push_back(start); 
                v1.push_back(last); 
                turn = 0; 
            } 
            else { 
                v2.push_back(start); 
                v2.push_back(last); 
                turn = 1; 
            } 
  
            // Increment start 
            start++; 
  
            // Decrement last 
            last--; 
        } 
    } 
  
    // When N is odd 
    else { 
  
        // Required sum of the subset 
        int rem = value / 2; 
  
        // Boolean array to keep 
        // track of used elements 
        bool vis[N + 1]; 
  
        for (int i = 1; i <= N; i++) 
            vis[i] = false; 
  
        vis[0] = true; 
  
        // Iterate from N to 1 
        for (int i = N; i >= 1; i--) { 
            if (rem > i) { 
                v1.push_back(i); 
                vis[i] = true; 
                rem -= i; 
            } 
  
            else { 
                v1.push_back(rem); 
                vis[rem] = true; 
                break; 
            } 
        } 
  
        // Assigning the unused 
        // elements to second subset 
        for (int i = 1; i <= N; i++) { 
            if (!vis[i]) 
                v2.push_back(i); 
        } 
    } 
  
    // Print the elements of first set 
    cout << "Size of subset 1 is: "; 
    cout << v1.size() << "\n"; 
    cout << "Elements of the subset are: "; 
    for (auto c : v1) 
        cout << c << " "; 
  
    cout << endl; 
  
    // Print the elements of second set 
    cout << "Size of subset 2 is: "; 
    cout << v2.size() << "\n"; 
    cout << "Elements of the subset are: "; 
    for (auto c : v2) 
        cout << c << " "; 
} 
  
// Driver Code 
int main() 
{ 
    // Given Number 
    int N = 7; 
  
    // Function Call 
    findAns(N); 
    return 0; 
}