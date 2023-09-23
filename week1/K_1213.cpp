#include <bits/stdc++.h>
using namespace std;

int len, cnt;
string s;
map<char, int> mp;
string front, tmp, back;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 1. Input string and str to map(char type)
    cin >> s;
    len = s.length();
    for(char c : s) mp[c]++;
    
    // 2. Check If it's impossible to make palindrome
    // 2.1 If size is even number
    if (len % 2 == 0) {
        for (auto it : mp){
            if (it.second % 2 != 0) {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
        }
    }
    // 2.2 If size is odd number
    else {
        for (auto it : mp) {
            if (it.second % 2 != 0 ) {
                tmp += it.first;
                cnt++;
            }
            if (cnt > 1) {
                cout << "I'm Sorry Hansoo";
                exit(0);
            }
        }
    }
    
    // 3. Make palindrome
    for(auto it : mp){
        for(int i = 0; i < it.second / 2; i++) {
            front += it.first;
            back += it.first;
        }
    }
    reverse(back.begin(), back.end());
    cout << front + tmp + back;
}