#include <bits/stdc++.h>
using namespace std;

int T;
bool ret;
string s;


bool check(string s) {
    stack<char> st;
    for(char c : s) {
        if(c =='(') {
            st.push(c);
        }
        else{
            if(!st.empty()) st.pop();
            else return false;
        }
    }
    return st.empty();
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> s;
        ret = check(s);
        (ret) ? cout << "YES" << '\n' : cout << "NO" << '\n';
        
    }
    
}