#include <bits/stdc++.h>
using namespace std;

int arr[26];
string s;
int main(){
    
    // 1. input
    cin >> s;
    
    // 2. count
    for(char c : s){
        int idx = c - 'a';
        arr[idx]++;
    }
    
    // 3. print
    for(int idx = 0; idx < 26; idx++){
        cout << arr[idx] << " ";
    }
    
    return 0;
}